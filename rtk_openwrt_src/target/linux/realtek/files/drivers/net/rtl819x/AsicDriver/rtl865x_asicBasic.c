/*
* Copyright c                  Realtek Semiconductor Corporation, 2009  
* All rights reserved.
* 
* Program : Switch table basic operation driver
* Abstract :
* Author : hyking (hyking_liu@realsil.com.cn)  
*/

#include <net/rtl/rtl_types.h>
//#include "types.h"
#include "asicRegs.h"
#include "asicTabs.h"
//#include "rtl_glue.h"
#include "rtl865x_hwPatch.h"
#include "rtl865x_asicBasic.h"

/*
 *  According to ghhuang's suggest,
 *    we DO NOT need to access 8 ASIC entries at once.
 *  We just need to access several entries as we need.
 */

#define RTL865X_FAST_ASIC_ACCESS

/*
 *  For RTL865xC Access protection mechanism
 *
 *	We define 2 different MACROs for ASIC table
 *	read/write protection correspondingly
 *
 */
//#define		RTL865XC_ASIC_READ_PROTECTION				/* Enable/Disable ASIC read protection */
#define		RTL865XC_ASIC_WRITE_PROTECTION				/* Enable/Disable ASIC write protection */

//#undef		RTL865X_READ_MULTIPLECHECK
#define 		RTL865X_READ_MULTIPLECHECK
#define		RTL865X_READ_MULTIPLECHECK_CNT		2
#define		RTL865X_READ_MULTIPLECHECK_MAX_RETRY	10
#define 	SIG_REG	(BSP_REVR+0x0C)
#define		ID_REG	(BSP_REVR+0x00)


int8 RtkHomeGatewayChipName[16];
int32 RtkHomeGatewayChipRevisionID;
int32 RtkHomeGatewayChipNameID;


static void prom_putchar(char c)
{
#define UART0_THR		(UART0_BASE + 0x000)
#define UART0_FCR		(UART0_BASE + 0x008)
#define UART0_LSR       (UART0_BASE + 0x014)
#define TXRST			0x04
#define CHAR_TRIGGER_14	0xC0
#define LSR_THRE		0x20
#define TxCHAR_AVAIL	0x00
#define TxCHAR_EMPTY	0x20
unsigned int busy_cnt = 0;

	do
	{
		/* Prevent Hanging */
		if (busy_cnt++ >= 30000)
		{
		 /* Reset Tx FIFO */
		 REG8(UART0_FCR) = TXRST | CHAR_TRIGGER_14;
		 return;
		}
	} while ((REG8(UART0_LSR) & LSR_THRE) == TxCHAR_AVAIL);

	/* Send Character */
	REG8(UART0_THR) = c;
}

static void early_console_write(const char *s, unsigned n)
{
	while (n-- && *s) {
		if (*s == '\n')
			prom_putchar('\r');
		prom_putchar(*s);
		s++;
	}
}

#ifdef RTL865X_FAST_ASIC_ACCESS
static uint32 _rtl8651_asicTableSize[] =
{
        2 /*TYPE_L2_SWITCH_TABLE*/,
        1 /*TYPE_ARP_TABLE*/,
#if defined(CONFIG_RTL_8198C)
	 3 /*TYPE_L3_ROUTING_TABLE*/,
#else
	 2 /*TYPE_L3_ROUTING_TABLE*/,
#endif
        3 /*TYPE_MULTICAST_TABLE*/,
        5 /*TYPE_NETIF_TABLE*/,
        3 /*TYPE_EXT_INT_IP_TABLE*/,
        3 /*TYPE_VLAN_TABLE*/,
        3 /*TYPE_VLAN1_TABLE*/,          
    4 /*TYPE_SERVER_PORT_TABLE*/,
    3 /*TYPE_L4_TCP_UDP_TABLE*/,
    3 /*TYPE_L4_ICMP_TABLE*/,
    1 /*TYPE_PPPOE_TABLE*/,
#if defined(CONFIG_RTL_8198C)
    11 /*TYPE_ACL_RULE_TABLE*/,
#else
    8 /*TYPE_ACL_RULE_TABLE*/,
#endif
    1 /*TYPE_NEXT_HOP_TABLE*/,
    3 /*TYPE_RATE_LIMIT_TABLE*/,
    1 /*TYPE_ALG_TABLE*/,
#if defined(CONFIG_RTL_8198C)   
   9 /*TYPE_DS_LITE_TABLE*/,	
   6 /*TYPE_6RD_TABLE*/,
   6 /*TYPE_L3_V6_ROUTING_TABLE*/,
   1 /*TYPE_NEXT_HOP_V6_TABLE*/,
   3 /*TYPE_ARP_V6_TABLE*/,
   9 /*TYPE_MULTICAST_V6_TABLE*/,
#endif
};
#endif


#define SIG_8196C 	0xF
#define SIG_8196CS 	0x3
#define SIG_8196CT	0x7
#define SIG_8197	0xB
#define SIG_8197B	0xA
#define SIG_8198	0x8
#define SIG_8198T	0x9
#define SIG_8196D	0xF
#define SIG_8196DT 	0xE
#define SIG_8196DS	0xD
#define SIG_8197D	0x8
#define SIG_8197DN	0xB
#define SIG_8197DT	0x9
#define SIG_8197DU	0xC
#define SIG_819XD	0x8
#define SIG_819XDT	0xB
#define SIG_89XXD 	0
// voip
#define SIG_VOIP(x)	(((x) & 0x8) == 0)

__DRAM_FWD static unsigned int fun_enable=0;

#ifdef CONFIG_RTL_819XD
#include "../common/smi.h"

int check_8367r_connected(void)
{
	uint32 data, saved_pin_mux = REG32(PIN_MUX_SEL);
	int ret = 0;
	
	// set to GPIO mode
	REG32(PIN_MUX_SEL) |= (0x00000018);

	// MDC: F5, MDIO: F6
	WRITE_MEM32(PEFGH_CNR, READ_MEM32(PEFGH_CNR) & (~(0x00006000)));	//set GPIO pin, F5 and F6
	WRITE_MEM32(PEFGH_DIR, READ_MEM32(PEFGH_DIR) | ((0x00006000))); //output pin

	smi_init(5, 5, 6);	// GPIO_PORT_F = 5
	
	if((smi_write(0x13C2, 0x0249)) == 0)
		if((smi_read(0x1300, &data)) == 0)
			if (data == 0x6000)
				ret = 1;
	
	REG32(PIN_MUX_SEL) = saved_pin_mux;

	return ret;
}
#endif

int32 rtl865x_initAsicFun(uint32 *enable)
{
	uint32 idReg, icReg;
	
	*enable = 0;

	idReg = REG32(ID_REG) & 0xffff0000;
	icReg =	REG32(SIG_REG) & 0x0f;

	if (idReg == 0xC0000000) // 8198 series
	{
		if ((icReg == SIG_8198T) ||	SIG_VOIP(icReg))
			*enable |= (ALL_NAT | HW_NAT | HW_MCST | HW_QOS);
		else if (icReg == SIG_8198)
			*enable |= (HW_NAT | HW_QOS | HW_MCST);
		else if ((icReg == SIG_8197) || (icReg == SIG_8197B))
			*enable |= (HW_MCST | HW_QOS);
		else
			*enable |= (HW_NAT | HW_QOS | HW_MCST);
	}
	else if (idReg == 0x80000000) // 8196c series
	{
		if (icReg == SIG_8196CT){
#if defined(CONFIG_POCKET_ROUTER_SUPPORT)
			*enable |= (DUMP_SWITCH | HW_MCST);
#else
			*enable |= (ALL_NAT | HW_NAT | HW_MCST | HW_QOS);
#endif	
		}else if (icReg == SIG_8196C)
			*enable |= ( HW_NAT | HW_MCST | HW_QOS);
		else if (icReg == SIG_8196CS)
			*enable |= ( HW_NAT | HW_MCST | HW_QOS);
		else
			*enable |= ( HW_NAT | HW_MCST | HW_QOS);

	}

#ifdef CONFIG_RTL_819XD
	else if (idReg == 0x81970000) // 8196D/8197D series
	{
		if (check_8367r_connected())
			*enable |= (HW_NAT | HW_QOS | HW_MCST);
		else
		{
		if((icReg == SIG_8196D) || (icReg == SIG_8197D) || (icReg == SIG_8197DN))
			*enable |= (DUMP_SWITCH | HW_MCST);
		else if ((icReg == SIG_8196DT) || (icReg == SIG_8197DT) || SIG_VOIP(icReg))
			*enable |= (ALL_NAT | HW_NAT | HW_QOS | HW_MCST);
		else
			*enable |= (DUMP_SWITCH | HW_MCST);
		}
	}
	else if ((idReg == 0x88810000)) // 8196D/8197D series
	{
		*enable |= (HW_NAT | HW_QOS | HW_MCST);
	}
#endif

#ifdef CONFIG_RTL_8196E
	else if (idReg == 0x81960000)
	{
		*enable |= (HW_NAT | HW_QOS | HW_MCST);
	}
#endif

#ifdef CONFIG_RTL_8198C
	// 0xb8000000 = 0x8198C000
	else if (idReg == 0x81980000)
	{
		*enable |= (HW_NAT | HW_QOS | HW_MCST);
	}
#endif

	if (*enable)
		return SUCCESS;
	else
		return FAILED;
}

int32 rtl865x_getAsicFun(uint32 *enable)
{
	*enable = fun_enable; 
	if (fun_enable)
		return SUCCESS;
	else
	{	
		rtl865x_initAsicFun(&fun_enable);
		*enable = fun_enable; 
		return SUCCESS;
	}
}

int32 bsp_swcore_init(uint32 type)
{
	int ret;
	uint32 i;
	uint32 idReg, icReg;

	ret = SUCCESS;	
	idReg = REG32(ID_REG) & 0xffff0000;
	icReg =	REG32(SIG_REG) & 0x0f;

#ifdef CONFIG_RTL_8198C
	{
	extern void ado_refine(void);
	ado_refine();
	}
#endif

	i=rtl865x_initAsicFun(&fun_enable);

	if(i == FAILED)
		goto error;	

	if (idReg == 0xC0000000) // 8198 series
	{
		if((type == SIG_8198T) && (icReg != SIG_8198T) && !SIG_VOIP(icReg))
		{
			early_console_write("init switch core failed!!!\n", 27);
			ret = FAILED;
		}
		else
			ret = SUCCESS;

	}
	else if (idReg == 0x80000000) // 8196c series
	{
		if((type == SIG_8196CT) && (icReg != SIG_8196CT))
		{
			early_console_write("init switch core failed!!!\n", 27);
			ret = FAILED;
		}
		else if((type == SIG_8196C) && (icReg != SIG_8196C) && (icReg != SIG_8196CT)&& (icReg != 0x3) && (icReg != 0xB))
		{
			early_console_write("init switch core failed!!!\n", 27);
			ret = FAILED;
		}
		else if((type == SIG_8196CS) && (icReg != SIG_8196CS) && (icReg != 0x7))
		{
			early_console_write("init switch core failed!!!\n", 27);
			ret = FAILED;
		}
		else 
			ret = SUCCESS;
	}

#ifdef CONFIG_RTL_819XD
	else if (idReg == 0x81970000) // 8196D/8197D series
	{
		if((type == SIG_819XD) && (icReg != SIG_8196D) && (icReg != SIG_8197DN) && (icReg != SIG_8197D) && (icReg != SIG_8196DT) && (icReg != SIG_8197DT) && (icReg != SIG_89XXD))
		{
			early_console_write("init switch core failed!!!\n", 27);
			ret = FAILED;
		}
		else if((type == SIG_819XDT) && (icReg != SIG_8196DT) && (icReg != SIG_8197DT) && (icReg != SIG_89XXD))
		{
			early_console_write("init switch core failed!!!\n", 27);
			ret = FAILED;
		}
		else
			ret = SUCCESS;
	}
#endif
#ifdef CONFIG_RTL_8881A
	else if (idReg == 0x88810000) // 8196D/8197D series
    {
        ret = SUCCESS;
    }
#endif

#ifdef CONFIG_RTL_8196E
	else if (idReg == 0x81960000)
	{
		ret = SUCCESS;
	}
#endif

#ifdef CONFIG_RTL_8198C
	else if (idReg == 0x81980000)
	{
		ret = SUCCESS;
	}
#endif

	return ret;
	
error:
	return FAILED;
}

int32 rtl865x_accessAsicTable(uint32 tableType, uint32 *access)
{
	uint32 enable;

	rtl865x_getAsicFun(&enable);
	
	switch(tableType)
	{
		case TYPE_RATE_LIMIT_TABLE:
			if(enable&ALL_NAT)
				*access = 1;
			else
				*access =0;
			break;
		case TYPE_EXT_INT_IP_TABLE:
		case TYPE_ARP_TABLE:
		case TYPE_L4_TCP_UDP_TABLE:
		case TYPE_L4_ICMP_TABLE:
		case TYPE_PPPOE_TABLE:
			if(enable&HW_NAT)
				*access = 1;
			else
				*access = 0;
			break;
		case TYPE_MULTICAST_TABLE:
			if( enable&HW_MCST)
				*access = 1;
			else
				*access = 0;
			break;
		default:
			*access = 1;	
			break;
	}

	return SUCCESS;
}

static void _rtl8651_asicTableAccessForward(uint32 tableType, uint32 eidx, void *entryContent_P) 
{
	ASSERT_CSP(entryContent_P);

	while ( (READ_MEM32(SWTACR) & ACTION_MASK) != ACTION_DONE );//Wait for command done

#ifdef RTL865X_FAST_ASIC_ACCESS

	{
		register uint32 index;

		for( index = 0; index < _rtl8651_asicTableSize[tableType]; index++ )
		{
			WRITE_MEM32(TCR0+(index<<2), *((uint32 *)entryContent_P + index));
		}

	}
#else
	WRITE_MEM32(TCR0, *((uint32 *)entryContent_P + 0));
	WRITE_MEM32(TCR1, *((uint32 *)entryContent_P + 1));
	WRITE_MEM32(TCR2, *((uint32 *)entryContent_P + 2));
	WRITE_MEM32(TCR3, *((uint32 *)entryContent_P + 3));
	WRITE_MEM32(TCR4, *((uint32 *)entryContent_P + 4));
	WRITE_MEM32(TCR5, *((uint32 *)entryContent_P + 5));
	WRITE_MEM32(TCR6, *((uint32 *)entryContent_P + 6));
	WRITE_MEM32(TCR7, *((uint32 *)entryContent_P + 7));

#if defined(CONFIG_RTL_8198C)
	if( _rtl8651_asicTableSize[tableType]>8)
	{	
		WRITE_MEM32(TCR8, *((uint32 *)entryContent_P + 8));
		WRITE_MEM32(TCR9, *((uint32 *)entryContent_P + 9));
		WRITE_MEM32(TCR10, *((uint32 *)entryContent_P + 10));
	}
#endif

#endif	
	WRITE_MEM32(SWTAA, ((uint32) rtl8651_asicTableAccessAddrBase(tableType) + eidx * RTL8651_ASICTABLE_ENTRY_LENGTH));//Fill address
}

int32 _rtl8651_addAsicEntry(uint32 tableType, uint32 eidx, void *entryContent_P) 
{
	uint32 access;

	rtl865x_accessAsicTable(tableType, &access);
	if(!access)
		return FAILED;

	_rtl8651_asicTableAccessForward(tableType, eidx, entryContent_P);

	#ifdef RTL865XC_ASIC_WRITE_PROTECTION
	if (RTL865X_TLU_BUG_FIXED)	/* No need to stop HW table lookup process */
	{
      		WRITE_MEM32(SWTCR0,EN_STOP_TLU|READ_MEM32(SWTCR0));
		while ( (READ_MEM32(SWTCR0) & STOP_TLU_READY)==0);
	}
	#endif

	WRITE_MEM32(SWTACR, ACTION_START | CMD_ADD );//Activate add command

	while ( (READ_MEM32(SWTACR) & ACTION_MASK) != ACTION_DONE );//Wait for command done
    
	if ( (READ_MEM32(SWTASR) & TABSTS_MASK) != TABSTS_SUCCESS )//Check status
	{
		#ifdef RTL865XC_ASIC_WRITE_PROTECTION
		if(RTL865X_TLU_BUG_FIXED)	/* No need to stop HW table lookup process */
		{
			WRITE_MEM32(SWTCR0,~EN_STOP_TLU&READ_MEM32(SWTCR0));
		}
		#endif

		return FAILED;
	}

	#ifdef RTL865XC_ASIC_WRITE_PROTECTION
	if (RTL865X_TLU_BUG_FIXED)	/* No need to stop HW table lookup process */
	{
		WRITE_MEM32(SWTCR0,~EN_STOP_TLU&READ_MEM32(SWTCR0));
	}
	#endif

	return SUCCESS;
}
static unsigned int mcastForceAddOpCnt=0;
#if defined(CONFIG_RTL_8198C)
static unsigned int mcastForceAddOpCnt6=0;
#endif
unsigned int _rtl865x_getForceAddMcastOpCnt(void)
{
	return mcastForceAddOpCnt;
}
#if defined(CONFIG_RTL_8198C)
unsigned int _rtl8198C_getForceAddMcastv6OpCnt(void)
{
	return mcastForceAddOpCnt6;
}
#endif
int32 _rtl8651_forceAddAsicEntry(uint32 tableType, uint32 eidx, void *entryContent_P) 
{
	uint32 access;

	rtl865x_accessAsicTable(tableType, &access);
	if(!access)
		return FAILED;
	
	if(tableType==TYPE_MULTICAST_TABLE)
	{
		mcastForceAddOpCnt++;
	}
#if defined(CONFIG_RTL_8198C)
	if(tableType==TYPE_MULTICAST_V6_TABLE)
	{
		mcastForceAddOpCnt6++;
	}
#endif
	#ifdef RTL865XC_ASIC_WRITE_PROTECTION
	if (RTL865X_TLU_BUG_FIXED)	/* No need to stop HW table lookup process */
	{	/* No need to stop HW table lookup process */
		WRITE_MEM32(SWTCR0,EN_STOP_TLU|READ_MEM32(SWTCR0));
		while ( (READ_MEM32(SWTCR0) & STOP_TLU_READY)==0);
	}
	#endif

	_rtl8651_asicTableAccessForward(tableType, eidx, entryContent_P);

 	WRITE_MEM32(SWTACR, ACTION_START | CMD_FORCE);//Activate add command
	while ( (READ_MEM32(SWTACR) & ACTION_MASK) != ACTION_DONE );//Wait for command done

	#ifdef RTL865XC_ASIC_WRITE_PROTECTION
	if (RTL865X_TLU_BUG_FIXED)	/* No need to stop HW table lookup process */
	{
		WRITE_MEM32(SWTCR0,~EN_STOP_TLU&READ_MEM32(SWTCR0));
	}
	#endif

	return SUCCESS;
}

#if defined(CONFIG_RTL_8198C)
#define MAX_ENTRY_CONTENT_SIZE	11
#else
#define MAX_ENTRY_CONTENT_SIZE	8
#endif

int32 _rtl8651_readAsicEntry(uint32 tableType, uint32 eidx, void *entryContent_P) 
{
	uint32 *entryAddr;
	uint32 tmp;/* dummy variable, don't remove it */
	uint32 access;

	#ifdef RTL865X_READ_MULTIPLECHECK
	uint32 entryContent[RTL865X_READ_MULTIPLECHECK_CNT][MAX_ENTRY_CONTENT_SIZE];	// CONFIG_RTL_8198C
	uint32 entryContentIdx;
	uint32 entryContent_new = RTL865X_READ_MULTIPLECHECK_CNT;/* to indicate which content is newer */
	uint32 entryCompare_max_count = RTL865X_READ_MULTIPLECHECK_MAX_RETRY;
	uint32 needRetry;
	#endif
#if defined(CONFIG_RTL_8198C)
	int i;
#endif

	rtl865x_accessAsicTable(tableType, &access);
	if(!access)
		return FAILED;

	
	#ifdef RTL865XC_ASIC_READ_PROTECTION
	if (RTL865X_TLU_BUG_FIXED)	/* No need to stop HW table lookup process */
	{	/* No need to stop HW table lookup process */
		WRITE_MEM32(SWTCR0,EN_STOP_TLU|READ_MEM32(SWTCR0));
		while ( (READ_MEM32(SWTCR0) & STOP_TLU_READY)==0);
	}
	#endif

	ASSERT_CSP(entryContent_P);
	entryAddr = (uint32 *) (
		(uint32) rtl8651_asicTableAccessAddrBase(tableType) + (eidx<<5 /*RTL8651_ASICTABLE_ENTRY_LENGTH*/) ) ;
		/*(uint32) rtl8651_asicTableAccessAddrBase(tableType) + eidx * RTL8651_ASICTABLE_ENTRY_LENGTH);*/

	while ( (READ_MEM32(SWTACR) & ACTION_MASK) != ACTION_DONE );//Wait for command ready
    
#ifdef RTL865X_READ_MULTIPLECHECK
		do
		{
			for (	entryContentIdx = 0 ;
				entryContentIdx < RTL865X_READ_MULTIPLECHECK_CNT ;
			   	entryContentIdx ++ )
			{
				entryContent[entryContentIdx][0] = *(entryAddr + 0);
				entryContent[entryContentIdx][1] = *(entryAddr + 1);
				entryContent[entryContentIdx][2] = *(entryAddr + 2);
				entryContent[entryContentIdx][3] = *(entryAddr + 3);
				entryContent[entryContentIdx][4] = *(entryAddr + 4);
				entryContent[entryContentIdx][5] = *(entryAddr + 5);
				entryContent[entryContentIdx][6] = *(entryAddr + 6);
				entryContent[entryContentIdx][7] = *(entryAddr + 7);
#if defined(CONFIG_RTL_8198C)
				if(_rtl8651_asicTableSize[tableType]>8)
				{
				/*
				   The LSB 256bits is defined as before, but bit 335 to bit256 is moved to add addr[15].
				   for example: 
					ACL rule 0 Virtual Address : bit [255:0]  : 0xbb0c_0000 ~ 0xbb0c_001c
						                                  bit [335:256] : 0xbb0c_8000 ~ 0xbb0c_8008
				   
					entryContent[entryContentIdx][8] = *(entryAddr + 0 + (BIT(15) / 4));
					entryContent[entryContentIdx][9] = *(entryAddr + 1 + (BIT(15) / 4));
					entryContent[entryContentIdx][10] = *(entryAddr + 2 + (BIT(15) / 4));
				 */	
				entryContent[entryContentIdx][8] = *(entryAddr + 8192);
				entryContent[entryContentIdx][9] = *(entryAddr + 8193);
				entryContent[entryContentIdx][10] = *(entryAddr + 8194);
				}
#endif

			}
			entryContent_new = RTL865X_READ_MULTIPLECHECK_CNT-1;

			needRetry = FALSE;

			for (	entryContentIdx = 1 ;
				entryContentIdx < RTL865X_READ_MULTIPLECHECK_CNT ;
			   	entryContentIdx ++ )
			{
				int32 idx;

				for ( idx = 0 ; idx < MAX_ENTRY_CONTENT_SIZE ; idx ++ )	// CONFIG_RTL_8198C
				{
					if (	entryContent[entryContentIdx][idx] !=
						entryContent[0][idx]	)
					{
						needRetry = TRUE;
						goto retry;
					}
				}
			}
retry:
		entryCompare_max_count --;
		} while (	( needRetry == TRUE ) &&
		      		( entryCompare_max_count > 0 ) );
	
	/* Update entryAddr for newer one */
	entryAddr = &( entryContent[ entryContent_new ][0] );
#endif

#if defined(RTL865X_READ_MULTIPLECHECK) && defined(CONFIG_RTL_8198C)
	#ifdef RTL865X_FAST_ASIC_ACCESS
	for( i = 0; i < _rtl8651_asicTableSize[tableType]; i++ )
	{
		*((uint32 *)entryContent_P + i) = entryContent[ entryContent_new ][i];
	}
	#else
	for( i = 0; i < MAX_ENTRY_CONTENT_SIZE; i++ )
	{
		*((uint32 *)entryContent_P + i) = entryContent[ entryContent_new ][i];
	}
	#endif

#else
#ifdef RTL865X_FAST_ASIC_ACCESS
	{
		register uint32 index;

		for( index = 0; index < _rtl8651_asicTableSize[tableType]; index++ )
		{
			#if defined(CONFIG_RTL_8198C)
			if(index<8)
				*((uint32 *)entryContent_P + index) = READ_MEM32((uint32)(entryAddr + index));
			else
				*((uint32 *)entryContent_P + index) = READ_MEM32((uint32)(entryAddr + index-8+8192));
			#else
			*((uint32 *)entryContent_P + index) = READ_MEM32((uint32)(entryAddr + index));
			#endif
		}
	}
#else
	*((uint32 *)entryContent_P + 0) = *(entryAddr + 0);
	*((uint32 *)entryContent_P + 1) = *(entryAddr + 1);
	*((uint32 *)entryContent_P + 2) = *(entryAddr + 2);
	*((uint32 *)entryContent_P + 3) = *(entryAddr + 3);
	*((uint32 *)entryContent_P + 4) = *(entryAddr + 4);
	*((uint32 *)entryContent_P + 5) = *(entryAddr + 5);
	*((uint32 *)entryContent_P + 6) = *(entryAddr + 6);
	*((uint32 *)entryContent_P + 7) = *(entryAddr + 7);
    
#if defined(CONFIG_RTL_8198C)
	if(_rtl8651_asicTableSize[tableType]>8)
	{
		*((uint32 *)entryContent_P + 8) = *(entryAddr + 8192);
		*((uint32 *)entryContent_P + 9) = *(entryAddr + 8193);
		*((uint32 *)entryContent_P + 10) = *(entryAddr+ 8194);
	}
#endif
#endif
#endif

	/* Dummy read. Must read an un-used table entry to refresh asic latch */
	tmp = *(uint32 *)((uint32) rtl8651_asicTableAccessAddrBase(TYPE_ACL_RULE_TABLE) + 1024 * RTL8651_ASICTABLE_ENTRY_LENGTH);
	#ifdef RTL865XC_ASIC_READ_PROTECTION
	if (RTL865X_TLU_BUG_FIXED)	/* No need to stop HW table lookup process */
	{
		WRITE_MEM32(SWTCR0,~EN_STOP_TLU&READ_MEM32(SWTCR0));
	}
	#endif

	return 0;
}

int32 _rtl8651_readAsicEntryStopTLU(uint32 tableType, uint32 eidx, void *entryContent_P) 
{
	uint32 *entryAddr;
	uint32 tmp;/* dummy variable, don't remove it */
	uint32 access;

	rtl865x_accessAsicTable(tableType, &access);
	if(!access)
		return FAILED;

	ASSERT_CSP(entryContent_P);
	entryAddr = (uint32 *) (
		(uint32) rtl8651_asicTableAccessAddrBase(tableType) + (eidx<<5 /*RTL8651_ASICTABLE_ENTRY_LENGTH*/) ) ;
		/*(uint32) rtl8651_asicTableAccessAddrBase(tableType) + eidx * RTL8651_ASICTABLE_ENTRY_LENGTH);*/
#if 0
	while ( (READ_MEM32(SWTACR) & ACTION_MASK) != ACTION_DONE );//Wait for command ready
#endif	

	if (RTL865X_TLU_BUG_FIXED)	/* No need to stop HW table lookup process */
	{	/* No need to stop HW table lookup process */
		WRITE_MEM32(SWTCR0,EN_STOP_TLU|READ_MEM32(SWTCR0));
		#if 0
		//while ( (READ_MEM32(SWTCR0) & STOP_TLU_READY)==0);
		#endif	
	}

#ifdef RTL865X_FAST_ASIC_ACCESS
	{
		register uint32 index;

		for( index = 0; index < _rtl8651_asicTableSize[tableType]; index++ )
		{
            #if defined(CONFIG_RTL_8198C)
            if(index<8)
                *((uint32 *)entryContent_P + index) = READ_MEM32((uint32)(entryAddr + index));
            else
                *((uint32 *)entryContent_P + index) = READ_MEM32((uint32)(entryAddr + index-8+8192));
            #else
			*((uint32 *)entryContent_P + index) = READ_MEM32((uint32)(entryAddr + index));
            #endif
		}
	}
#else
	*((uint32 *)entryContent_P + 0) = *(entryAddr + 0);
	*((uint32 *)entryContent_P + 1) = *(entryAddr + 1);
	*((uint32 *)entryContent_P + 2) = *(entryAddr + 2);
	*((uint32 *)entryContent_P + 3) = *(entryAddr + 3);
	*((uint32 *)entryContent_P + 4) = *(entryAddr + 4);
	*((uint32 *)entryContent_P + 5) = *(entryAddr + 5);
	*((uint32 *)entryContent_P + 6) = *(entryAddr + 6);
	*((uint32 *)entryContent_P + 7) = *(entryAddr + 7);

#if defined(CONFIG_RTL_8198C)
    if(_rtl8651_asicTableSize[tableType]>8)
    {
        *((uint32 *)entryContent_P + 8) = *(entryAddr + 8192);
        *((uint32 *)entryContent_P + 9) = *(entryAddr + 8193);
        *((uint32 *)entryContent_P + 10) = *(entryAddr + 8194);
    }
#endif

#endif


	if (RTL865X_TLU_BUG_FIXED)	/* No need to stop HW table lookup process */
	{
		WRITE_MEM32(SWTCR0,~EN_STOP_TLU&READ_MEM32(SWTCR0));
	}

	/* Dummy read. Must read an un-used table entry to refresh asic latch */
	tmp = *(uint32 *)((uint32) rtl8651_asicTableAccessAddrBase(TYPE_ACL_RULE_TABLE) + 1024 * RTL8651_ASICTABLE_ENTRY_LENGTH);

	return 0;
}

int32 _rtl8651_delAsicEntry(uint32 tableType, uint32 startEidx, uint32 endEidx) 
{
	uint32 eidx = startEidx;

	while ( (READ_MEM32(SWTACR) & ACTION_MASK) != ACTION_DONE );//Wait for command done

#ifdef RTL865X_FAST_ASIC_ACCESS
	{
		register uint32 index;

		for( index = 0; index < _rtl8651_asicTableSize[tableType]; index++ )
		{
			WRITE_MEM32(TCR0+(index<<2), 0);
		}
	}
#else
	WRITE_MEM32(TCR0, 0);
	WRITE_MEM32(TCR1, 0);
	WRITE_MEM32(TCR2, 0);
	WRITE_MEM32(TCR3, 0);
	WRITE_MEM32(TCR4, 0);
	WRITE_MEM32(TCR5, 0);
	WRITE_MEM32(TCR6, 0);
	WRITE_MEM32(TCR7, 0);

#if defined(CONFIG_RTL_8198C)
    if(_rtl8651_asicTableSize[tableType]>8)
    {
    	WRITE_MEM32(TCR8, 0);
    	WRITE_MEM32(TCR9, 0);
    	WRITE_MEM32(TCR10, 0);
    }
#endif

#endif	
	
	while (eidx <= endEidx) {
		WRITE_MEM32(SWTAA, (uint32) rtl8651_asicTableAccessAddrBase(tableType) + eidx * RTL8651_ASICTABLE_ENTRY_LENGTH);//Fill address
        
		WRITE_MEM32(SWTACR, ACTION_START | CMD_FORCE);//Activate add command

		while ( (READ_MEM32(SWTACR) & ACTION_MASK) != ACTION_DONE );//Wait for command done
    
		if ( (READ_MEM32(SWTASR) & TABSTS_MASK) != TABSTS_SUCCESS )//Check status
			return FAILED;
		
		++eidx;
	}
	return SUCCESS;
}

extern void machine_restart(char *command);
static unsigned int rtl819x_lastTxDesc=0;
static unsigned int rtl819x_lastRxDesc=0;
static unsigned int rtl819x_swHangCnt=0;
static unsigned int rtl819x_checkSwCoreTimer=0;
void rtl819x_poll_sw(void)
{
	unsigned int port6Queue0Cgst= (READ_MEM32(0xbb80610c) & (1<<16));
	unsigned int curRing0RxDesc=READ_MEM32(0xb8010004)&0xFFFFFFFC;
	unsigned int curRing0TxDesc=READ_MEM32(0xb8010020)&0xFFFFFFFC;

	if (((rtl819x_checkSwCoreTimer++) % 20)==0) 
	{
		
		//unsigned int sysDescRunOut= (READ_MEM32(0xbb806100) & (1<<27));
		if(port6Queue0Cgst==0) 
		{
			rtl819x_swHangCnt=0;
		}
		else
		{
		
			if((rtl819x_lastTxDesc==0) || (rtl819x_lastRxDesc==0))
			{
				rtl819x_lastRxDesc=curRing0RxDesc;
				rtl819x_lastTxDesc=curRing0TxDesc;
				rtl819x_swHangCnt=0;
			}
			else
			{
				if((rtl819x_lastRxDesc==curRing0RxDesc) && (rtl819x_lastTxDesc==curRing0TxDesc))
				{
					rtl819x_swHangCnt++;
				}
				else
				{
					rtl819x_swHangCnt=0;
				}
			}

		
		}
		
		
		rtl819x_lastRxDesc=curRing0RxDesc;
		rtl819x_lastTxDesc=curRing0TxDesc;

		if(rtl819x_swHangCnt>2)
		{
			rtl819x_swHangCnt=0;
			#ifndef CONFIG_OPENWRT_SDK
			panic_printk(".........................................\n");
			#else
			printk(".........................................\n");
			#endif
			machine_restart(NULL);
		}
		
	}

	return;
}

#ifdef CONFIG_RTL_8881A
#include <linux/reboot.h>

int Lx1_check(void)
{
	if (REG32(GISR2) & LX1_BTRDY_IP)  {	
		extern unsigned int get_uptime_by_sec(void);
		#if defined(CONFIG_TR181_ETH)
		panic_printk("\nLexra bus 1 master timeout, GISR2= 0x%08x, uptime= %d seconds.\n\n", REG32(GISR2), get_uptime_by_sec());
		#endif
		machine_restart(NULL);
	}
	return 0;
}
#endif



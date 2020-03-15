/****************************************************************************** 
* 
* Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved. 
* 
* This program is free software; you can redistribute it and/or modify it 
* under the terms of version 2 of the GNU General Public License as 
* published by the Free Software Foundation. 
* 
* This program is distributed in the hope that it will be useful, but WITHOUT 
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
* more details. 
* 
* You should have received a copy of the GNU General Public License along with 
* this program; if not, write to the Free Software Foundation, Inc., 
* 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA 
* 
* 
******************************************************************************/

#if !defined(__ECOS) && !defined(CPTCFG_CFG80211_MODULE)
#include "mp_precomp.h"
#else
#include "../mp_precomp.h"
#endif
#include "../phydm_precomp.h"

#if (RTL8821B_SUPPORT == 1)
static BOOLEAN
CheckPositive(
    IN  PDM_ODM_T     pDM_Odm,
    IN  const u4Byte  Condition1,
    IN  const u4Byte  Condition2
    )
{
     u1Byte    _GLNA        = (pDM_Odm->BoardType & BIT4) >> 4;
     u1Byte    _GPA         = (pDM_Odm->BoardType & BIT3) >> 3;
     u1Byte    _ALNA        = (pDM_Odm->BoardType & BIT7) >> 7;
     u1Byte    _APA         = (pDM_Odm->BoardType & BIT6) >> 6;
     
     u1Byte     cBoard      = (u1Byte)((Condition1 &  bMaskByte0)               >>  0);
     u1Byte     cInterface  = (u1Byte)((Condition1 & (BIT11|BIT10|BIT9|BIT8))   >>  8);
     u1Byte     cPackage    = (u1Byte)((Condition1 & (BIT15|BIT14|BIT13|BIT12)) >> 12);
     u1Byte     cPlatform   = (u1Byte)((Condition1 & (BIT19|BIT18|BIT17|BIT16)) >> 16);
     u1Byte     cCut        = (u1Byte)((Condition1 & (BIT27|BIT26|BIT25|BIT24)) >> 24);
     u1Byte     cGLNA       = (cBoard & BIT0) >> 0;
     u1Byte     cGPA        = (cBoard & BIT1) >> 1;
     u1Byte     cALNA       = (cBoard & BIT2) >> 2;
     u1Byte     cAPA        = (cBoard & BIT3) >> 3;
     u1Byte     cTypeGLNA   = (u1Byte)((Condition2 & bMaskByte0) >>  0);
     u1Byte     cTypeGPA    = (u1Byte)((Condition2 & bMaskByte1) >>  8);
     u1Byte     cTypeALNA   = (u1Byte)((Condition2 & bMaskByte2) >> 16);
     u1Byte     cTypeAPA    = (u1Byte)((Condition2 & bMaskByte3) >> 24);
     
     ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, 
                 ("===> [8812A] CheckPositive(0x%X 0x%X)\n", Condition1, Condition2));
     ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, 
                 ("	(Platform, Interface) = (0x%X, 0x%X)", pDM_Odm->SupportPlatform, pDM_Odm->SupportInterface));
     ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, 
                 ("	(Board, Package) = (0x%X, 0x%X\n", pDM_Odm->BoardType, pDM_Odm->PackageType));
     
     if ((cPlatform  != pDM_Odm->SupportPlatform  && cPlatform  != 0) || 
         (cInterface != pDM_Odm->SupportInterface && cInterface != 0) || 
         (cCut       != pDM_Odm->CutVersion       && cCut       != 0))
         return FALSE;
     
     if (cPackage != pDM_Odm->PackageType && cPackage != 0)
         return FALSE;
     
     if (((_GLNA != 0) && (_GLNA == cGLNA) && (cTypeGLNA == pDM_Odm->TypeGLNA)) ||
         ((_GPA  != 0) && (_GPA  == cGPA ) && (cTypeGPA  == pDM_Odm->TypeGPA )) ||
         ((_ALNA != 0) && (_ALNA == cALNA) && (cTypeALNA == pDM_Odm->TypeALNA)) ||
         ((_APA  != 0) && (_APA  == cAPA ) && (cTypeAPA  == pDM_Odm->TypeAPA )))
         return TRUE;
     else 
     	return FALSE;
}

static BOOLEAN
CheckNegative(
    IN  PDM_ODM_T     pDM_Odm,
    IN  const u4Byte  Condition1,
    IN  const u4Byte  Condition2
    )
{
    return TRUE;
}

/******************************************************************************
*                           RadioA.TXT
******************************************************************************/

u4Byte Array_TC_8821B_RadioA[] = { 
		0x018, 0x00010124,
		0x018, 0x00018124,
		0x018, 0x00010124,
		0x01B, 0x00003240,
		0x085, 0x00080000,
		0x089, 0x00000007,
		0x08A, 0x000F7A02,
		0x08B, 0x0007FFFC,
		0x08C, 0x00014A27,
		0x08D, 0x000D0000,
		0x08E, 0x00064540,
		0x0EF, 0x00010000,
		0x033, 0x00000007,
		0x03E, 0x00000000,
		0x03F, 0x00003801,
		0x033, 0x00000006,
		0x03E, 0x00000000,
		0x03F, 0x0002B801,
		0x033, 0x00000005,
		0x03E, 0x00000000,
		0x03F, 0x0006B801,
		0x033, 0x00000004,
		0x03E, 0x00000001,
		0x03F, 0x000EB801,
		0x033, 0x00000003,
		0x03E, 0x00000035,
		0x03F, 0x0006B801,
		0x033, 0x00000002,
		0x03E, 0x00000070,
		0x03F, 0x0004B801,
		0x033, 0x00000001,
		0x03E, 0x00000071,
		0x03F, 0x0007B801,
		0x033, 0x00000000,
		0x03E, 0x00000071,
		0x03F, 0x000FB801,
		0x033, 0x0000000F,
		0x03E, 0x00000000,
		0x03F, 0x00003801,
		0x033, 0x0000000E,
		0x03E, 0x00000000,
		0x03F, 0x0002B801,
		0x033, 0x0000000D,
		0x03E, 0x00000000,
		0x03F, 0x0006B801,
		0x033, 0x0000000C,
		0x03E, 0x00000001,
		0x03F, 0x000EB801,
		0x033, 0x0000000B,
		0x03E, 0x00000035,
		0x03F, 0x0006B801,
		0x033, 0x0000000A,
		0x03E, 0x00000070,
		0x03F, 0x0004B801,
		0x033, 0x00000009,
		0x03E, 0x00000071,
		0x03F, 0x0007B801,
		0x033, 0x00000008,
		0x03E, 0x00000071,
		0x03F, 0x000FB801,
		0x033, 0x00000017,
		0x03E, 0x00000000,
		0x03F, 0x00003801,
		0x033, 0x00000016,
		0x03E, 0x00000000,
		0x03F, 0x0002B801,
		0x033, 0x00000015,
		0x03E, 0x00000000,
		0x03F, 0x0006B801,
		0x033, 0x00000014,
		0x03E, 0x00000001,
		0x03F, 0x000EB801,
		0x033, 0x00000013,
		0x03E, 0x00000035,
		0x03F, 0x0006B801,
		0x033, 0x00000012,
		0x03E, 0x00000070,
		0x03F, 0x0004B801,
		0x033, 0x00000011,
		0x03E, 0x00000071,
		0x03F, 0x0007B801,
		0x033, 0x00000010,
		0x03E, 0x00000071,
		0x03F, 0x000FB801,
		0x0EF, 0x00000000,
		0x0EF, 0x00004000,
		0x033, 0x00000000,
		0x03F, 0x0000000B,
		0x033, 0x00000001,
		0x03F, 0x00000006,
		0x033, 0x00000002,
		0x03F, 0x00000004,
		0x0EF, 0x00000000,
		0x084, 0x00000005,
		0x087, 0x00050000,
		0x088, 0x00040400,
		0x018, 0x00000001,
		0x0EF, 0x00008000,
		0x033, 0x0000000F,
		0x03F, 0x0000003C,
		0x033, 0x0000000E,
		0x03F, 0x00000031,
		0x033, 0x0000000D,
		0x03F, 0x0000002D,
		0x033, 0x0000000C,
		0x03F, 0x00000021,
		0x033, 0x0000000B,
		0x03F, 0x0000001D,
		0x033, 0x0000000A,
		0x03F, 0x00000011,
		0x033, 0x00000009,
		0x03F, 0x00000001,
		0x033, 0x00000007,
		0x03F, 0x0000003D,
		0x033, 0x00000006,
		0x03F, 0x00000031,
		0x033, 0x00000005,
		0x03F, 0x0000002D,
		0x033, 0x00000004,
		0x03F, 0x00000021,
		0x033, 0x00000003,
		0x03F, 0x0000001D,
		0x033, 0x00000002,
		0x03F, 0x00000011,
		0x033, 0x00000001,
		0x03F, 0x00000001,
		0x0EF, 0x00000000,
		0x0DF, 0x0002000D,
		0x0CA, 0x000A0100,
		0x0CF, 0x00000005,
		0x0B0, 0x000FFF63,
		0x0B1, 0x0006DB60,
		0x0B2, 0x00028709,
		0x0B3, 0x000FFC6F,
		0x0B4, 0x0005C152,
		0x0B5, 0x00012080,
		0x0B6, 0x000203FF,
		0x0B7, 0x00030018,
		0x0B8, 0x00081000,
		0x0B9, 0x00023840,
		0x0B4, 0x0005C152,
		0x018, 0x00018124,
		0x018, 0x00010124,
		0x001, 0x00000020,
		0x001, 0x00000028,

};

void
ODM_ReadAndConfig_TC_8821B_RadioA(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
    #define READ_NEXT_PAIR(v1, v2, i) do { if (i+2 >= ArrayLen) break; i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)
    #define COND_ELSE  2
    #define COND_ENDIF 3
    u4Byte     i         = 0;
    u4Byte     ArrayLen    = sizeof(Array_TC_8821B_RadioA)/sizeof(u4Byte);
    pu4Byte    Array       = Array_TC_8821B_RadioA;
	
    ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD, ("===> ODM_ReadAndConfig_TC_8821B_RadioA\n"));

    for (i = 0; i < ArrayLen; i += 2 )
    {
        u4Byte v1 = Array[i];
        u4Byte v2 = Array[i+1];
    
        // This (offset, data) pair doesn't care the condition.
        if ( v1 < 0x40000000 )
        {
           odm_ConfigRF_RadioA_8821B(pDM_Odm, v1, v2);
           continue;
        }
        else
        {   // This line is the beginning of branch.
            BOOLEAN bMatched = TRUE;
            u1Byte  cCond  = (u1Byte)((v1 & (BIT29|BIT28)) >> 28);

            if (cCond == COND_ELSE) { // ELSE, ENDIF
                bMatched = TRUE;
                READ_NEXT_PAIR(v1, v2, i);
            } else if ( ! CheckPositive(pDM_Odm, v1, v2) ) { 
                bMatched = FALSE;
                READ_NEXT_PAIR(v1, v2, i);
                READ_NEXT_PAIR(v1, v2, i);
            } else {
                READ_NEXT_PAIR(v1, v2, i);
                if ( ! CheckNegative(pDM_Odm, v1, v2) )
                    bMatched = FALSE;
                else
                    bMatched = TRUE;
                READ_NEXT_PAIR(v1, v2, i);
            }

            if ( bMatched == FALSE )
            {   // Condition isn't matched. Discard the following (offset, data) pairs.
                while (v1 < 0x40000000 && i < ArrayLen -2)
                    READ_NEXT_PAIR(v1, v2, i);

                i -= 2; // prevent from for-loop += 2
            }
            else // Configure matched pairs and skip to end of if-else.
            {
                while (v1 < 0x40000000 && i < ArrayLen-2) {
                    odm_ConfigRF_RadioA_8821B(pDM_Odm, v1, v2);
                    READ_NEXT_PAIR(v1, v2, i);
                }

                // Keeps reading until ENDIF.
                cCond = (u1Byte)((v1 & (BIT29|BIT28)) >> 28);
                while (cCond != COND_ENDIF && i < ArrayLen-2) {
                    READ_NEXT_PAIR(v1, v2, i);
                    cCond = (u1Byte)((v1 & (BIT29|BIT28)) >> 28);
                }
            }
        } 
    }
}

u4Byte
ODM_GetVersion_TC_8821B_RadioA(
)
{
	   return 14;
}

/******************************************************************************
*                           TxPowerTrack.TXT
******************************************************************************/

u1Byte gDeltaSwingTableIdx_TC_5GB_N_TxPowerTrack_8821B[][DELTA_SWINGIDX_SIZE] = {
	{0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16},
	{0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16},
	{0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16},
};
u1Byte gDeltaSwingTableIdx_TC_5GB_P_TxPowerTrack_8821B[][DELTA_SWINGIDX_SIZE] = {
	{0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16},
	{0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16},
	{0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16},
};
u1Byte gDeltaSwingTableIdx_TC_5GA_N_TxPowerTrack_8821B[][DELTA_SWINGIDX_SIZE] = {
	{0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16},
	{0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16},
	{0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16},
};
u1Byte gDeltaSwingTableIdx_TC_5GA_P_TxPowerTrack_8821B[][DELTA_SWINGIDX_SIZE] = {
	{0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16},
	{0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16},
	{0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16},
};
u1Byte gDeltaSwingTableIdx_TC_2GB_N_TxPowerTrack_8821B[]    = {0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10};
u1Byte gDeltaSwingTableIdx_TC_2GB_P_TxPowerTrack_8821B[]    = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 12, 12, 12, 12};
u1Byte gDeltaSwingTableIdx_TC_2GA_N_TxPowerTrack_8821B[]    = {0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10};
u1Byte gDeltaSwingTableIdx_TC_2GA_P_TxPowerTrack_8821B[]    = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 12, 12, 12, 12};
u1Byte gDeltaSwingTableIdx_TC_2GCCKB_N_TxPowerTrack_8821B[] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10};
u1Byte gDeltaSwingTableIdx_TC_2GCCKB_P_TxPowerTrack_8821B[] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 12, 12, 12, 12};
u1Byte gDeltaSwingTableIdx_TC_2GCCKA_N_TxPowerTrack_8821B[] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10};
u1Byte gDeltaSwingTableIdx_TC_2GCCKA_P_TxPowerTrack_8821B[] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 12, 12, 12, 12};

void
ODM_ReadAndConfig_TC_8821B_TxPowerTrack(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	PODM_RF_CAL_T  pRFCalibrateInfo = &(pDM_Odm->RFCalibrateInfo);

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD, ("===> ODM_ReadAndConfig_MP_TC_8821B\n"));


	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GA_P, gDeltaSwingTableIdx_TC_2GA_P_TxPowerTrack_8821B, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GA_N, gDeltaSwingTableIdx_TC_2GA_N_TxPowerTrack_8821B, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GB_P, gDeltaSwingTableIdx_TC_2GB_P_TxPowerTrack_8821B, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GB_N, gDeltaSwingTableIdx_TC_2GB_N_TxPowerTrack_8821B, DELTA_SWINGIDX_SIZE);

	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_P, gDeltaSwingTableIdx_TC_2GCCKA_P_TxPowerTrack_8821B, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_N, gDeltaSwingTableIdx_TC_2GCCKA_N_TxPowerTrack_8821B, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_P, gDeltaSwingTableIdx_TC_2GCCKB_P_TxPowerTrack_8821B, DELTA_SWINGIDX_SIZE);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_N, gDeltaSwingTableIdx_TC_2GCCKB_N_TxPowerTrack_8821B, DELTA_SWINGIDX_SIZE);

	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GA_P, gDeltaSwingTableIdx_TC_5GA_P_TxPowerTrack_8821B, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GA_N, gDeltaSwingTableIdx_TC_5GA_N_TxPowerTrack_8821B, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GB_P, gDeltaSwingTableIdx_TC_5GB_P_TxPowerTrack_8821B, DELTA_SWINGIDX_SIZE*3);
	ODM_MoveMemory(pDM_Odm, pRFCalibrateInfo->DeltaSwingTableIdx_5GB_N, gDeltaSwingTableIdx_TC_5GB_N_TxPowerTrack_8821B, DELTA_SWINGIDX_SIZE*3);
}

/******************************************************************************
*                           TXPWR_LMT.TXT
******************************************************************************/

const char * Array_TC_8821B_TXPWR_LMT[] = { 
	"FCC", "2.4G", "20M", "CCK", "1T", "01", "32", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "01", "32", 
	"MKK", "2.4G", "20M", "CCK", "1T", "01", "32",
	"FCC", "2.4G", "20M", "CCK", "1T", "02", "32", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "02", "32", 
	"MKK", "2.4G", "20M", "CCK", "1T", "02", "32",
	"FCC", "2.4G", "20M", "CCK", "1T", "03", "36", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "03", "32", 
	"MKK", "2.4G", "20M", "CCK", "1T", "03", "32",
	"FCC", "2.4G", "20M", "CCK", "1T", "04", "36", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "04", "32", 
	"MKK", "2.4G", "20M", "CCK", "1T", "04", "32",
	"FCC", "2.4G", "20M", "CCK", "1T", "05", "36", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "05", "32", 
	"MKK", "2.4G", "20M", "CCK", "1T", "05", "32",
	"FCC", "2.4G", "20M", "CCK", "1T", "06", "36", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "06", "32", 
	"MKK", "2.4G", "20M", "CCK", "1T", "06", "32",
	"FCC", "2.4G", "20M", "CCK", "1T", "07", "36", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "07", "32", 
	"MKK", "2.4G", "20M", "CCK", "1T", "07", "32",
	"FCC", "2.4G", "20M", "CCK", "1T", "08", "36", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "08", "32", 
	"MKK", "2.4G", "20M", "CCK", "1T", "08", "32",
	"FCC", "2.4G", "20M", "CCK", "1T", "09", "32", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "09", "32", 
	"MKK", "2.4G", "20M", "CCK", "1T", "09", "32",
	"FCC", "2.4G", "20M", "CCK", "1T", "10", "32", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "10", "32", 
	"MKK", "2.4G", "20M", "CCK", "1T", "10", "32",
	"FCC", "2.4G", "20M", "CCK", "1T", "11", "32", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "11", "32", 
	"MKK", "2.4G", "20M", "CCK", "1T", "11", "32",
	"FCC", "2.4G", "20M", "CCK", "1T", "12", "63", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "12", "32", 
	"MKK", "2.4G", "20M", "CCK", "1T", "12", "32",
	"FCC", "2.4G", "20M", "CCK", "1T", "13", "63", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "13", "32", 
	"MKK", "2.4G", "20M", "CCK", "1T", "13", "32",
	"FCC", "2.4G", "20M", "CCK", "1T", "14", "63", 
	"ETSI", "2.4G", "20M", "CCK", "1T", "14", "63", 
	"MKK", "2.4G", "20M", "CCK", "1T", "14", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "01", "30", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "01", "32", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "01", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "02", "30", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "02", "32", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "02", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "03", "32", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "03", "32", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "03", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "04", "32", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "04", "32", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "04", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "05", "32", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "05", "32", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "05", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "06", "32", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "06", "32", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "06", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "07", "32", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "07", "32", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "07", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "08", "32", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "08", "32", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "08", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "09", "30", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "09", "32", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "09", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "10", "30", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "10", "32", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "10", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "11", "30", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "11", "32", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "11", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "12", "63", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "12", "32", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "12", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "13", "63", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "13", "32", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "13", "32",
	"FCC", "2.4G", "20M", "OFDM", "1T", "14", "63", 
	"ETSI", "2.4G", "20M", "OFDM", "1T", "14", "63", 
	"MKK", "2.4G", "20M", "OFDM", "1T", "14", "63",
	"FCC", "2.4G", "20M", "HT", "1T", "01", "26", 
	"ETSI", "2.4G", "20M", "HT", "1T", "01", "32", 
	"MKK", "2.4G", "20M", "HT", "1T", "01", "32",
	"FCC", "2.4G", "20M", "HT", "1T", "02", "26", 
	"ETSI", "2.4G", "20M", "HT", "1T", "02", "32", 
	"MKK", "2.4G", "20M", "HT", "1T", "02", "32",
	"FCC", "2.4G", "20M", "HT", "1T", "03", "32", 
	"ETSI", "2.4G", "20M", "HT", "1T", "03", "32", 
	"MKK", "2.4G", "20M", "HT", "1T", "03", "32",
	"FCC", "2.4G", "20M", "HT", "1T", "04", "32", 
	"ETSI", "2.4G", "20M", "HT", "1T", "04", "32", 
	"MKK", "2.4G", "20M", "HT", "1T", "04", "32",
	"FCC", "2.4G", "20M", "HT", "1T", "05", "32", 
	"ETSI", "2.4G", "20M", "HT", "1T", "05", "32", 
	"MKK", "2.4G", "20M", "HT", "1T", "05", "32",
	"FCC", "2.4G", "20M", "HT", "1T", "06", "32", 
	"ETSI", "2.4G", "20M", "HT", "1T", "06", "32", 
	"MKK", "2.4G", "20M", "HT", "1T", "06", "32",
	"FCC", "2.4G", "20M", "HT", "1T", "07", "32", 
	"ETSI", "2.4G", "20M", "HT", "1T", "07", "32", 
	"MKK", "2.4G", "20M", "HT", "1T", "07", "32",
	"FCC", "2.4G", "20M", "HT", "1T", "08", "32", 
	"ETSI", "2.4G", "20M", "HT", "1T", "08", "32", 
	"MKK", "2.4G", "20M", "HT", "1T", "08", "32",
	"FCC", "2.4G", "20M", "HT", "1T", "09", "26", 
	"ETSI", "2.4G", "20M", "HT", "1T", "09", "32", 
	"MKK", "2.4G", "20M", "HT", "1T", "09", "32",
	"FCC", "2.4G", "20M", "HT", "1T", "10", "26", 
	"ETSI", "2.4G", "20M", "HT", "1T", "10", "32", 
	"MKK", "2.4G", "20M", "HT", "1T", "10", "32",
	"FCC", "2.4G", "20M", "HT", "1T", "11", "26", 
	"ETSI", "2.4G", "20M", "HT", "1T", "11", "32", 
	"MKK", "2.4G", "20M", "HT", "1T", "11", "32",
	"FCC", "2.4G", "20M", "HT", "1T", "12", "63", 
	"ETSI", "2.4G", "20M", "HT", "1T", "12", "32", 
	"MKK", "2.4G", "20M", "HT", "1T", "12", "32",
	"FCC", "2.4G", "20M", "HT", "1T", "13", "63", 
	"ETSI", "2.4G", "20M", "HT", "1T", "13", "32", 
	"MKK", "2.4G", "20M", "HT", "1T", "13", "32",
	"FCC", "2.4G", "20M", "HT", "1T", "14", "63", 
	"ETSI", "2.4G", "20M", "HT", "1T", "14", "63", 
	"MKK", "2.4G", "20M", "HT", "1T", "14", "63",
	"FCC", "2.4G", "20M", "HT", "2T", "01", "30", 
	"ETSI", "2.4G", "20M", "HT", "2T", "01", "32", 
	"MKK", "2.4G", "20M", "HT", "2T", "01", "32",
	"FCC", "2.4G", "20M", "HT", "2T", "02", "32", 
	"ETSI", "2.4G", "20M", "HT", "2T", "02", "32", 
	"MKK", "2.4G", "20M", "HT", "2T", "02", "32",
	"FCC", "2.4G", "20M", "HT", "2T", "03", "32", 
	"ETSI", "2.4G", "20M", "HT", "2T", "03", "32", 
	"MKK", "2.4G", "20M", "HT", "2T", "03", "32",
	"FCC", "2.4G", "20M", "HT", "2T", "04", "32", 
	"ETSI", "2.4G", "20M", "HT", "2T", "04", "32", 
	"MKK", "2.4G", "20M", "HT", "2T", "04", "32",
	"FCC", "2.4G", "20M", "HT", "2T", "05", "32", 
	"ETSI", "2.4G", "20M", "HT", "2T", "05", "32", 
	"MKK", "2.4G", "20M", "HT", "2T", "05", "32",
	"FCC", "2.4G", "20M", "HT", "2T", "06", "32", 
	"ETSI", "2.4G", "20M", "HT", "2T", "06", "32", 
	"MKK", "2.4G", "20M", "HT", "2T", "06", "32",
	"FCC", "2.4G", "20M", "HT", "2T", "07", "32", 
	"ETSI", "2.4G", "20M", "HT", "2T", "07", "32", 
	"MKK", "2.4G", "20M", "HT", "2T", "07", "32",
	"FCC", "2.4G", "20M", "HT", "2T", "08", "32", 
	"ETSI", "2.4G", "20M", "HT", "2T", "08", "32", 
	"MKK", "2.4G", "20M", "HT", "2T", "08", "32",
	"FCC", "2.4G", "20M", "HT", "2T", "09", "32", 
	"ETSI", "2.4G", "20M", "HT", "2T", "09", "32", 
	"MKK", "2.4G", "20M", "HT", "2T", "09", "32",
	"FCC", "2.4G", "20M", "HT", "2T", "10", "32", 
	"ETSI", "2.4G", "20M", "HT", "2T", "10", "32", 
	"MKK", "2.4G", "20M", "HT", "2T", "10", "32",
	"FCC", "2.4G", "20M", "HT", "2T", "11", "30", 
	"ETSI", "2.4G", "20M", "HT", "2T", "11", "32", 
	"MKK", "2.4G", "20M", "HT", "2T", "11", "32",
	"FCC", "2.4G", "20M", "HT", "2T", "12", "63", 
	"ETSI", "2.4G", "20M", "HT", "2T", "12", "32", 
	"MKK", "2.4G", "20M", "HT", "2T", "12", "32",
	"FCC", "2.4G", "20M", "HT", "2T", "13", "63", 
	"ETSI", "2.4G", "20M", "HT", "2T", "13", "32", 
	"MKK", "2.4G", "20M", "HT", "2T", "13", "32",
	"FCC", "2.4G", "20M", "HT", "2T", "14", "63", 
	"ETSI", "2.4G", "20M", "HT", "2T", "14", "63", 
	"MKK", "2.4G", "20M", "HT", "2T", "14", "63",
	"FCC", "2.4G", "40M", "HT", "1T", "01", "63", 
	"ETSI", "2.4G", "40M", "HT", "1T", "01", "63", 
	"MKK", "2.4G", "40M", "HT", "1T", "01", "63",
	"FCC", "2.4G", "40M", "HT", "1T", "02", "63", 
	"ETSI", "2.4G", "40M", "HT", "1T", "02", "63", 
	"MKK", "2.4G", "40M", "HT", "1T", "02", "63",
	"FCC", "2.4G", "40M", "HT", "1T", "03", "26", 
	"ETSI", "2.4G", "40M", "HT", "1T", "03", "32", 
	"MKK", "2.4G", "40M", "HT", "1T", "03", "32",
	"FCC", "2.4G", "40M", "HT", "1T", "04", "26", 
	"ETSI", "2.4G", "40M", "HT", "1T", "04", "32", 
	"MKK", "2.4G", "40M", "HT", "1T", "04", "32",
	"FCC", "2.4G", "40M", "HT", "1T", "05", "26", 
	"ETSI", "2.4G", "40M", "HT", "1T", "05", "32", 
	"MKK", "2.4G", "40M", "HT", "1T", "05", "32",
	"FCC", "2.4G", "40M", "HT", "1T", "06", "32", 
	"ETSI", "2.4G", "40M", "HT", "1T", "06", "32", 
	"MKK", "2.4G", "40M", "HT", "1T", "06", "32",
	"FCC", "2.4G", "40M", "HT", "1T", "07", "32", 
	"ETSI", "2.4G", "40M", "HT", "1T", "07", "32", 
	"MKK", "2.4G", "40M", "HT", "1T", "07", "32",
	"FCC", "2.4G", "40M", "HT", "1T", "08", "32", 
	"ETSI", "2.4G", "40M", "HT", "1T", "08", "32", 
	"MKK", "2.4G", "40M", "HT", "1T", "08", "32",
	"FCC", "2.4G", "40M", "HT", "1T", "09", "26", 
	"ETSI", "2.4G", "40M", "HT", "1T", "09", "32", 
	"MKK", "2.4G", "40M", "HT", "1T", "09", "32",
	"FCC", "2.4G", "40M", "HT", "1T", "10", "26", 
	"ETSI", "2.4G", "40M", "HT", "1T", "10", "32", 
	"MKK", "2.4G", "40M", "HT", "1T", "10", "32",
	"FCC", "2.4G", "40M", "HT", "1T", "11", "26", 
	"ETSI", "2.4G", "40M", "HT", "1T", "11", "32", 
	"MKK", "2.4G", "40M", "HT", "1T", "11", "32",
	"FCC", "2.4G", "40M", "HT", "1T", "12", "63", 
	"ETSI", "2.4G", "40M", "HT", "1T", "12", "32", 
	"MKK", "2.4G", "40M", "HT", "1T", "12", "32",
	"FCC", "2.4G", "40M", "HT", "1T", "13", "63", 
	"ETSI", "2.4G", "40M", "HT", "1T", "13", "32", 
	"MKK", "2.4G", "40M", "HT", "1T", "13", "32",
	"FCC", "2.4G", "40M", "HT", "1T", "14", "63", 
	"ETSI", "2.4G", "40M", "HT", "1T", "14", "63", 
	"MKK", "2.4G", "40M", "HT", "1T", "14", "63",
	"FCC", "2.4G", "40M", "HT", "2T", "01", "63", 
	"ETSI", "2.4G", "40M", "HT", "2T", "01", "63", 
	"MKK", "2.4G", "40M", "HT", "2T", "01", "63",
	"FCC", "2.4G", "40M", "HT", "2T", "02", "63", 
	"ETSI", "2.4G", "40M", "HT", "2T", "02", "63", 
	"MKK", "2.4G", "40M", "HT", "2T", "02", "63",
	"FCC", "2.4G", "40M", "HT", "2T", "03", "30", 
	"ETSI", "2.4G", "40M", "HT", "2T", "03", "30", 
	"MKK", "2.4G", "40M", "HT", "2T", "03", "30",
	"FCC", "2.4G", "40M", "HT", "2T", "04", "32", 
	"ETSI", "2.4G", "40M", "HT", "2T", "04", "30", 
	"MKK", "2.4G", "40M", "HT", "2T", "04", "30",
	"FCC", "2.4G", "40M", "HT", "2T", "05", "32", 
	"ETSI", "2.4G", "40M", "HT", "2T", "05", "30", 
	"MKK", "2.4G", "40M", "HT", "2T", "05", "30",
	"FCC", "2.4G", "40M", "HT", "2T", "06", "32", 
	"ETSI", "2.4G", "40M", "HT", "2T", "06", "30", 
	"MKK", "2.4G", "40M", "HT", "2T", "06", "30",
	"FCC", "2.4G", "40M", "HT", "2T", "07", "32", 
	"ETSI", "2.4G", "40M", "HT", "2T", "07", "30", 
	"MKK", "2.4G", "40M", "HT", "2T", "07", "30",
	"FCC", "2.4G", "40M", "HT", "2T", "08", "32", 
	"ETSI", "2.4G", "40M", "HT", "2T", "08", "30", 
	"MKK", "2.4G", "40M", "HT", "2T", "08", "30",
	"FCC", "2.4G", "40M", "HT", "2T", "09", "32", 
	"ETSI", "2.4G", "40M", "HT", "2T", "09", "30", 
	"MKK", "2.4G", "40M", "HT", "2T", "09", "30",
	"FCC", "2.4G", "40M", "HT", "2T", "10", "32", 
	"ETSI", "2.4G", "40M", "HT", "2T", "10", "30", 
	"MKK", "2.4G", "40M", "HT", "2T", "10", "30",
	"FCC", "2.4G", "40M", "HT", "2T", "11", "30", 
	"ETSI", "2.4G", "40M", "HT", "2T", "11", "30", 
	"MKK", "2.4G", "40M", "HT", "2T", "11", "30",
	"FCC", "2.4G", "40M", "HT", "2T", "12", "63", 
	"ETSI", "2.4G", "40M", "HT", "2T", "12", "32", 
	"MKK", "2.4G", "40M", "HT", "2T", "12", "32",
	"FCC", "2.4G", "40M", "HT", "2T", "13", "63", 
	"ETSI", "2.4G", "40M", "HT", "2T", "13", "32", 
	"MKK", "2.4G", "40M", "HT", "2T", "13", "32",
	"FCC", "2.4G", "40M", "HT", "2T", "14", "63", 
	"ETSI", "2.4G", "40M", "HT", "2T", "14", "63", 
	"MKK", "2.4G", "40M", "HT", "2T", "14", "63",
	"FCC", "5G", "20M", "OFDM", "1T", "36", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "36", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "36", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "40", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "40", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "40", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "44", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "44", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "44", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "48", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "48", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "48", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "52", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "52", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "52", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "56", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "56", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "56", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "60", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "60", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "60", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "64", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "64", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "64", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "100", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "100", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "100", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "114", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "114", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "114", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "108", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "108", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "108", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "112", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "112", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "112", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "116", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "116", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "116", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "120", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "120", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "120", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "124", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "124", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "124", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "128", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "128", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "128", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "132", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "132", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "132", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "136", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "136", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "136", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "140", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "140", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "140", "30",
	"FCC", "5G", "20M", "OFDM", "1T", "149", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "149", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "149", "63",
	"FCC", "5G", "20M", "OFDM", "1T", "153", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "153", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "153", "63",
	"FCC", "5G", "20M", "OFDM", "1T", "157", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "157", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "157", "63",
	"FCC", "5G", "20M", "OFDM", "1T", "161", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "161", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "161", "63",
	"FCC", "5G", "20M", "OFDM", "1T", "165", "32", 
	"ETSI", "5G", "20M", "OFDM", "1T", "165", "30", 
	"MKK", "5G", "20M", "OFDM", "1T", "165", "63",
	"FCC", "5G", "20M", "HT", "1T", "36", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "36", "30", 
	"MKK", "5G", "20M", "HT", "1T", "36", "30",
	"FCC", "5G", "20M", "HT", "1T", "40", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "40", "30", 
	"MKK", "5G", "20M", "HT", "1T", "40", "30",
	"FCC", "5G", "20M", "HT", "1T", "44", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "44", "30", 
	"MKK", "5G", "20M", "HT", "1T", "44", "30",
	"FCC", "5G", "20M", "HT", "1T", "48", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "48", "30", 
	"MKK", "5G", "20M", "HT", "1T", "48", "30",
	"FCC", "5G", "20M", "HT", "1T", "52", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "52", "30", 
	"MKK", "5G", "20M", "HT", "1T", "52", "30",
	"FCC", "5G", "20M", "HT", "1T", "56", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "56", "30", 
	"MKK", "5G", "20M", "HT", "1T", "56", "30",
	"FCC", "5G", "20M", "HT", "1T", "60", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "60", "30", 
	"MKK", "5G", "20M", "HT", "1T", "60", "30",
	"FCC", "5G", "20M", "HT", "1T", "64", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "64", "30", 
	"MKK", "5G", "20M", "HT", "1T", "64", "30",
	"FCC", "5G", "20M", "HT", "1T", "100", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "100", "30", 
	"MKK", "5G", "20M", "HT", "1T", "100", "30",
	"FCC", "5G", "20M", "HT", "1T", "114", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "114", "30", 
	"MKK", "5G", "20M", "HT", "1T", "114", "30",
	"FCC", "5G", "20M", "HT", "1T", "108", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "108", "30", 
	"MKK", "5G", "20M", "HT", "1T", "108", "30",
	"FCC", "5G", "20M", "HT", "1T", "112", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "112", "30", 
	"MKK", "5G", "20M", "HT", "1T", "112", "30",
	"FCC", "5G", "20M", "HT", "1T", "116", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "116", "30", 
	"MKK", "5G", "20M", "HT", "1T", "116", "30",
	"FCC", "5G", "20M", "HT", "1T", "120", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "120", "30", 
	"MKK", "5G", "20M", "HT", "1T", "120", "30",
	"FCC", "5G", "20M", "HT", "1T", "124", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "124", "30", 
	"MKK", "5G", "20M", "HT", "1T", "124", "30",
	"FCC", "5G", "20M", "HT", "1T", "128", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "128", "30", 
	"MKK", "5G", "20M", "HT", "1T", "128", "30",
	"FCC", "5G", "20M", "HT", "1T", "132", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "132", "30", 
	"MKK", "5G", "20M", "HT", "1T", "132", "30",
	"FCC", "5G", "20M", "HT", "1T", "136", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "136", "30", 
	"MKK", "5G", "20M", "HT", "1T", "136", "30",
	"FCC", "5G", "20M", "HT", "1T", "140", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "140", "30", 
	"MKK", "5G", "20M", "HT", "1T", "140", "30",
	"FCC", "5G", "20M", "HT", "1T", "149", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "149", "30", 
	"MKK", "5G", "20M", "HT", "1T", "149", "63",
	"FCC", "5G", "20M", "HT", "1T", "153", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "153", "30", 
	"MKK", "5G", "20M", "HT", "1T", "153", "63",
	"FCC", "5G", "20M", "HT", "1T", "157", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "157", "30", 
	"MKK", "5G", "20M", "HT", "1T", "157", "63",
	"FCC", "5G", "20M", "HT", "1T", "161", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "161", "30", 
	"MKK", "5G", "20M", "HT", "1T", "161", "63",
	"FCC", "5G", "20M", "HT", "1T", "165", "32", 
	"ETSI", "5G", "20M", "HT", "1T", "165", "30", 
	"MKK", "5G", "20M", "HT", "1T", "165", "63",
	"FCC", "5G", "20M", "HT", "2T", "36", "28", 
	"ETSI", "5G", "20M", "HT", "2T", "36", "30", 
	"MKK", "5G", "20M", "HT", "2T", "36", "30",
	"FCC", "5G", "20M", "HT", "2T", "40", "28", 
	"ETSI", "5G", "20M", "HT", "2T", "40", "30", 
	"MKK", "5G", "20M", "HT", "2T", "40", "30",
	"FCC", "5G", "20M", "HT", "2T", "44", "28", 
	"ETSI", "5G", "20M", "HT", "2T", "44", "30", 
	"MKK", "5G", "20M", "HT", "2T", "44", "30",
	"FCC", "5G", "20M", "HT", "2T", "48", "28", 
	"ETSI", "5G", "20M", "HT", "2T", "48", "30", 
	"MKK", "5G", "20M", "HT", "2T", "48", "30",
	"FCC", "5G", "20M", "HT", "2T", "52", "34", 
	"ETSI", "5G", "20M", "HT", "2T", "52", "30", 
	"MKK", "5G", "20M", "HT", "2T", "52", "30",
	"FCC", "5G", "20M", "HT", "2T", "56", "32", 
	"ETSI", "5G", "20M", "HT", "2T", "56", "30", 
	"MKK", "5G", "20M", "HT", "2T", "56", "30",
	"FCC", "5G", "20M", "HT", "2T", "60", "30", 
	"ETSI", "5G", "20M", "HT", "2T", "60", "30", 
	"MKK", "5G", "20M", "HT", "2T", "60", "30",
	"FCC", "5G", "20M", "HT", "2T", "64", "26", 
	"ETSI", "5G", "20M", "HT", "2T", "64", "30", 
	"MKK", "5G", "20M", "HT", "2T", "64", "30",
	"FCC", "5G", "20M", "HT", "2T", "100", "28", 
	"ETSI", "5G", "20M", "HT", "2T", "100", "30", 
	"MKK", "5G", "20M", "HT", "2T", "100", "30",
	"FCC", "5G", "20M", "HT", "2T", "114", "28", 
	"ETSI", "5G", "20M", "HT", "2T", "114", "30", 
	"MKK", "5G", "20M", "HT", "2T", "114", "30",
	"FCC", "5G", "20M", "HT", "2T", "108", "30", 
	"ETSI", "5G", "20M", "HT", "2T", "108", "30", 
	"MKK", "5G", "20M", "HT", "2T", "108", "30",
	"FCC", "5G", "20M", "HT", "2T", "112", "32", 
	"ETSI", "5G", "20M", "HT", "2T", "112", "30", 
	"MKK", "5G", "20M", "HT", "2T", "112", "30",
	"FCC", "5G", "20M", "HT", "2T", "116", "32", 
	"ETSI", "5G", "20M", "HT", "2T", "116", "30", 
	"MKK", "5G", "20M", "HT", "2T", "116", "30",
	"FCC", "5G", "20M", "HT", "2T", "120", "34", 
	"ETSI", "5G", "20M", "HT", "2T", "120", "30", 
	"MKK", "5G", "20M", "HT", "2T", "120", "30",
	"FCC", "5G", "20M", "HT", "2T", "124", "32", 
	"ETSI", "5G", "20M", "HT", "2T", "124", "30", 
	"MKK", "5G", "20M", "HT", "2T", "124", "30",
	"FCC", "5G", "20M", "HT", "2T", "128", "30", 
	"ETSI", "5G", "20M", "HT", "2T", "128", "30", 
	"MKK", "5G", "20M", "HT", "2T", "128", "30",
	"FCC", "5G", "20M", "HT", "2T", "132", "28", 
	"ETSI", "5G", "20M", "HT", "2T", "132", "30", 
	"MKK", "5G", "20M", "HT", "2T", "132", "30",
	"FCC", "5G", "20M", "HT", "2T", "136", "28", 
	"ETSI", "5G", "20M", "HT", "2T", "136", "30", 
	"MKK", "5G", "20M", "HT", "2T", "136", "30",
	"FCC", "5G", "20M", "HT", "2T", "140", "26", 
	"ETSI", "5G", "20M", "HT", "2T", "140", "30", 
	"MKK", "5G", "20M", "HT", "2T", "140", "30",
	"FCC", "5G", "20M", "HT", "2T", "149", "34", 
	"ETSI", "5G", "20M", "HT", "2T", "149", "30", 
	"MKK", "5G", "20M", "HT", "2T", "149", "63",
	"FCC", "5G", "20M", "HT", "2T", "153", "34", 
	"ETSI", "5G", "20M", "HT", "2T", "153", "30", 
	"MKK", "5G", "20M", "HT", "2T", "153", "63",
	"FCC", "5G", "20M", "HT", "2T", "157", "34", 
	"ETSI", "5G", "20M", "HT", "2T", "157", "30", 
	"MKK", "5G", "20M", "HT", "2T", "157", "63",
	"FCC", "5G", "20M", "HT", "2T", "161", "34", 
	"ETSI", "5G", "20M", "HT", "2T", "161", "30", 
	"MKK", "5G", "20M", "HT", "2T", "161", "63",
	"FCC", "5G", "20M", "HT", "2T", "165", "34", 
	"ETSI", "5G", "20M", "HT", "2T", "165", "30", 
	"MKK", "5G", "20M", "HT", "2T", "165", "63",
	"FCC", "5G", "40M", "HT", "1T", "38", "26", 
	"ETSI", "5G", "40M", "HT", "1T", "38", "30", 
	"MKK", "5G", "40M", "HT", "1T", "38", "30",
	"FCC", "5G", "40M", "HT", "1T", "46", "32", 
	"ETSI", "5G", "40M", "HT", "1T", "46", "30", 
	"MKK", "5G", "40M", "HT", "1T", "46", "30",
	"FCC", "5G", "40M", "HT", "1T", "54", "32", 
	"ETSI", "5G", "40M", "HT", "1T", "54", "30", 
	"MKK", "5G", "40M", "HT", "1T", "54", "30",
	"FCC", "5G", "40M", "HT", "1T", "62", "24", 
	"ETSI", "5G", "40M", "HT", "1T", "62", "30", 
	"MKK", "5G", "40M", "HT", "1T", "62", "30",
	"FCC", "5G", "40M", "HT", "1T", "102", "24", 
	"ETSI", "5G", "40M", "HT", "1T", "102", "30", 
	"MKK", "5G", "40M", "HT", "1T", "102", "30",
	"FCC", "5G", "40M", "HT", "1T", "110", "32", 
	"ETSI", "5G", "40M", "HT", "1T", "110", "30", 
	"MKK", "5G", "40M", "HT", "1T", "110", "30",
	"FCC", "5G", "40M", "HT", "1T", "118", "32", 
	"ETSI", "5G", "40M", "HT", "1T", "118", "30", 
	"MKK", "5G", "40M", "HT", "1T", "118", "30",
	"FCC", "5G", "40M", "HT", "1T", "126", "32", 
	"ETSI", "5G", "40M", "HT", "1T", "126", "30", 
	"MKK", "5G", "40M", "HT", "1T", "126", "30",
	"FCC", "5G", "40M", "HT", "1T", "134", "32", 
	"ETSI", "5G", "40M", "HT", "1T", "134", "30", 
	"MKK", "5G", "40M", "HT", "1T", "134", "30",
	"FCC", "5G", "40M", "HT", "1T", "151", "30", 
	"ETSI", "5G", "40M", "HT", "1T", "151", "30", 
	"MKK", "5G", "40M", "HT", "1T", "151", "63",
	"FCC", "5G", "40M", "HT", "1T", "159", "32", 
	"ETSI", "5G", "40M", "HT", "1T", "159", "30", 
	"MKK", "5G", "40M", "HT", "1T", "159", "63",
	"FCC", "5G", "40M", "HT", "2T", "38", "28", 
	"ETSI", "5G", "40M", "HT", "2T", "38", "30", 
	"MKK", "5G", "40M", "HT", "2T", "38", "30",
	"FCC", "5G", "40M", "HT", "2T", "46", "28", 
	"ETSI", "5G", "40M", "HT", "2T", "46", "30", 
	"MKK", "5G", "40M", "HT", "2T", "46", "30",
	"FCC", "5G", "40M", "HT", "2T", "54", "30", 
	"ETSI", "5G", "40M", "HT", "2T", "54", "30", 
	"MKK", "5G", "40M", "HT", "2T", "54", "30",
	"FCC", "5G", "40M", "HT", "2T", "62", "30", 
	"ETSI", "5G", "40M", "HT", "2T", "62", "30", 
	"MKK", "5G", "40M", "HT", "2T", "62", "30",
	"FCC", "5G", "40M", "HT", "2T", "102", "26", 
	"ETSI", "5G", "40M", "HT", "2T", "102", "30", 
	"MKK", "5G", "40M", "HT", "2T", "102", "30",
	"FCC", "5G", "40M", "HT", "2T", "110", "30", 
	"ETSI", "5G", "40M", "HT", "2T", "110", "30", 
	"MKK", "5G", "40M", "HT", "2T", "110", "30",
	"FCC", "5G", "40M", "HT", "2T", "118", "34", 
	"ETSI", "5G", "40M", "HT", "2T", "118", "30", 
	"MKK", "5G", "40M", "HT", "2T", "118", "30",
	"FCC", "5G", "40M", "HT", "2T", "126", "32", 
	"ETSI", "5G", "40M", "HT", "2T", "126", "30", 
	"MKK", "5G", "40M", "HT", "2T", "126", "30",
	"FCC", "5G", "40M", "HT", "2T", "134", "30", 
	"ETSI", "5G", "40M", "HT", "2T", "134", "30", 
	"MKK", "5G", "40M", "HT", "2T", "134", "30",
	"FCC", "5G", "40M", "HT", "2T", "151", "34", 
	"ETSI", "5G", "40M", "HT", "2T", "151", "30", 
	"MKK", "5G", "40M", "HT", "2T", "151", "63",
	"FCC", "5G", "40M", "HT", "2T", "159", "34", 
	"ETSI", "5G", "40M", "HT", "2T", "159", "30", 
	"MKK", "5G", "40M", "HT", "2T", "159", "63",
	"FCC", "5G", "80M", "VHT", "1T", "42", "22", 
	"ETSI", "5G", "80M", "VHT", "1T", "42", "30", 
	"MKK", "5G", "80M", "VHT", "1T", "42", "30",
	"FCC", "5G", "80M", "VHT", "1T", "58", "20", 
	"ETSI", "5G", "80M", "VHT", "1T", "58", "30", 
	"MKK", "5G", "80M", "VHT", "1T", "58", "30",
	"FCC", "5G", "80M", "VHT", "1T", "106", "20", 
	"ETSI", "5G", "80M", "VHT", "1T", "106", "30", 
	"MKK", "5G", "80M", "VHT", "1T", "106", "30",
	"FCC", "5G", "80M", "VHT", "1T", "122", "20", 
	"ETSI", "5G", "80M", "VHT", "1T", "122", "30", 
	"MKK", "5G", "80M", "VHT", "1T", "122", "30",
	"FCC", "5G", "80M", "VHT", "1T", "155", "28", 
	"ETSI", "5G", "80M", "VHT", "1T", "155", "30", 
	"MKK", "5G", "80M", "VHT", "1T", "155", "63",
	"FCC", "5G", "80M", "VHT", "2T", "42", "28", 
	"ETSI", "5G", "80M", "VHT", "2T", "42", "30", 
	"MKK", "5G", "80M", "VHT", "2T", "42", "30",
	"FCC", "5G", "80M", "VHT", "2T", "58", "26", 
	"ETSI", "5G", "80M", "VHT", "2T", "58", "30", 
	"MKK", "5G", "80M", "VHT", "2T", "58", "30",
	"FCC", "5G", "80M", "VHT", "2T", "106", "28", 
	"ETSI", "5G", "80M", "VHT", "2T", "106", "30", 
	"MKK", "5G", "80M", "VHT", "2T", "106", "30",
	"FCC", "5G", "80M", "VHT", "2T", "122", "32", 
	"ETSI", "5G", "80M", "VHT", "2T", "122", "30", 
	"MKK", "5G", "80M", "VHT", "2T", "122", "30",
	"FCC", "5G", "80M", "VHT", "2T", "155", "34", 
	"ETSI", "5G", "80M", "VHT", "2T", "155", "30", 
	"MKK", "5G", "80M", "VHT", "2T", "155", "63"
};

void
ODM_ReadAndConfig_TC_8821B_TXPWR_LMT(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	u4Byte     i           = 0;
	u4Byte     ArrayLen    = sizeof(Array_TC_8821B_TXPWR_LMT)/sizeof(pu1Byte);
	pu1Byte    *Array      = (pu1Byte*)Array_TC_8821B_TXPWR_LMT;

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD, ("===> ODM_ReadAndConfig_TC_8821B_TXPWR_LMT\n"));

	for (i = 0; i < ArrayLen; i += 7 )
	{
	    pu1Byte regulation = Array[i];
	    pu1Byte band = Array[i+1];
	    pu1Byte bandwidth = Array[i+2];
	    pu1Byte rate = Array[i+3];
	    pu1Byte rfPath = Array[i+4];
	    pu1Byte chnl = Array[i+5];
	    pu1Byte val = Array[i+6];
	
	 	 odm_ConfigBB_TXPWR_LMT_8821B(pDM_Odm, regulation, band, bandwidth, rate, rfPath, chnl, val);
	}

}

#endif // end of HWIMG_SUPPORT


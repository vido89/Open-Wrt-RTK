#include "8192cd.h"
#include "8192cd_cfg.h"
#include "8192cd_util.h"
#include "8192cd_headers.h"
#include "Beamforming.h"
#include "8812_reg.h"
#include "8812_vht_gen.h"



#ifdef BEAMFORMING_SUPPORT


VOID
Beamforming_SetBeamFormLeave(
	struct rtl8192cd_priv *priv,
	u1Byte				Idx
	)
{

#ifdef CONFIG_RTL_8812_SUPPORT
		if(GET_CHIP_VER(priv) == VERSION_8812E)
			SetBeamformLeave8812(priv, Idx);	
#endif

#ifdef CONFIG_WLAN_HAL_8192EE
		if(GET_CHIP_VER(priv) == VERSION_8192E)
			SetBeamformLeave92E(priv,Idx);
#endif

#ifdef CONFIG_WLAN_HAL_8814AE
		if(GET_CHIP_VER(priv) == VERSION_8814A)
			SetBeamformLeave8814A(priv,Idx);
#endif

}

VOID
Beamforming_SetBeamFormStatus(
	struct rtl8192cd_priv *priv,
	u1Byte				Idx
	)
{

#ifdef CONFIG_WLAN_HAL_8192EE
		if(GET_CHIP_VER(priv)== VERSION_8192E)
			SetBeamformStatus92E(priv, Idx);		
#endif
#ifdef CONFIG_RTL_8812_SUPPORT
		if(GET_CHIP_VER(priv)== VERSION_8812E)
			SetBeamformStatus8812(priv, Idx);
#endif

#ifdef CONFIG_WLAN_HAL_8814AE
		if(GET_CHIP_VER(priv) == VERSION_8814A)
			SetBeamformStatus8814A(priv,Idx);
#endif

}

VOID
Beamforming_SetBeamFormEnter(
	struct rtl8192cd_priv *priv,
	u1Byte				Idx
	)
{

#ifdef CONFIG_WLAN_HAL_8192EE
		if (GET_CHIP_VER(priv)== VERSION_8192E)	
			SetBeamformEnter92E(priv, Idx);
#endif
#ifdef CONFIG_RTL_8812_SUPPORT
		if (GET_CHIP_VER(priv)== VERSION_8812E)	
			SetBeamformEnter8812(priv, Idx);
#endif
#ifdef CONFIG_WLAN_HAL_8814AE
		if(GET_CHIP_VER(priv) == VERSION_8814A)
			SetBeamformEnter8814A(priv,Idx);
#endif

}


VOID
Beamforming_NDPARate(
	struct rtl8192cd_priv *priv,
	BOOLEAN		Mode,
	u1Byte		BW,
	u1Byte		Rate
	)
{
#ifdef CONFIG_WLAN_HAL_8192EE
	if(GET_CHIP_VER(priv)== VERSION_8192E){
		Beamforming_NDPARate_92E(priv, Mode, BW, Rate);
	}		
#endif
#ifdef CONFIG_RTL_8812_SUPPORT
	if(GET_CHIP_VER(priv)== VERSION_8812E) {
		Beamforming_NDPARate_8812(priv, Mode, BW, Rate);  //
	}
#endif
#ifdef CONFIG_WLAN_HAL_8814AE
	if(GET_CHIP_VER(priv)== VERSION_8814A){
		Beamforming_NDPARate_8814A(priv, Mode, BW, Rate);
	}		
#endif

}

VOID
Beamforming_SetHWTimer(
	struct rtl8192cd_priv *priv,
	u2Byte	t
	)
{
#ifdef CONFIG_WLAN_HAL_8192EE
		if(GET_CHIP_VER(priv)== VERSION_8192E)
		{			
			HW_VAR_HW_REG_TIMER_STOP_92E(priv);
			HW_VAR_HW_REG_TIMER_INIT_92E(priv, t);
			HW_VAR_HW_REG_TIMER_START_92E(priv);
		}
#endif
#ifdef CONFIG_RTL_8812_SUPPORT
		if(GET_CHIP_VER(priv)== VERSION_8812E)
		{
			HW_VAR_HW_REG_TIMER_STOP_8812(priv);
			HW_VAR_HW_REG_TIMER_INIT_8812(priv, t);
			HW_VAR_HW_REG_TIMER_START_8812(priv);
		}
#endif
#ifdef CONFIG_WLAN_HAL_8814AE
		if(GET_CHIP_VER(priv)== VERSION_8814A)
		{			
			HW_VAR_HW_REG_TIMER_STOP_8814A(priv);
			HW_VAR_HW_REG_TIMER_INIT_8814A(priv, t);
			HW_VAR_HW_REG_TIMER_START_8814A(priv);
		}
#endif
}

VOID
Beamforming_StopHWTimer(
	struct rtl8192cd_priv *priv
	)
{
#ifdef CONFIG_WLAN_HAL_8192EE
		if(GET_CHIP_VER(priv)== VERSION_8192E)
		{			
			HW_VAR_HW_REG_TIMER_STOP_92E(priv);
		}
#endif
#ifdef CONFIG_RTL_8812_SUPPORT
		if(GET_CHIP_VER(priv)== VERSION_8812E)
		{
			HW_VAR_HW_REG_TIMER_STOP_8812(priv);
		}
#endif
#ifdef CONFIG_WLAN_HAL_8814AE
		if(GET_CHIP_VER(priv)== VERSION_8814A)
		{			
			HW_VAR_HW_REG_TIMER_STOP_8814A(priv);
		}
#endif
}

u1Byte
Beamforming_GetHTNDPTxRate(
	struct rtl8192cd_priv *priv,
	u1Byte	CompSteeringNumofBFer
)
{
	u1Byte Nr_index = 0;
	u1Byte NDPTxRate;

#ifdef CONFIG_WLAN_HAL_8814AE
	if(GET_CHIP_VER(priv)== VERSION_8814A)
		Nr_index = TxBF_Nr(halTxbf8814A_GetNtx(priv), CompSteeringNumofBFer);		/*find Nr*/
	else
#endif
		Nr_index = TxBF_Nr(1, CompSteeringNumofBFer);		/*find Nr*/
	switch(Nr_index)
	{
		case 1:
		NDPTxRate = _MCS8_RATE_;
		break;

		case 2:
		NDPTxRate = _MCS16_RATE_;
		break;

		case 3:
		NDPTxRate = _MCS24_RATE_;
		break;
			
		default:
		NDPTxRate = _MCS8_RATE_;
		break;
	
	}

return NDPTxRate;

}

u1Byte
Beamforming_GetVHTNDPTxRate(
	struct rtl8192cd_priv *priv,
	u1Byte	CompSteeringNumofBFer
)
{
	u1Byte Nr_index = 0;
	u1Byte NDPTxRate;

#ifdef CONFIG_WLAN_HAL_8814AE
	if(GET_CHIP_VER(priv)== VERSION_8814A)
		Nr_index = TxBF_Nr(halTxbf8814A_GetNtx(priv), CompSteeringNumofBFer);		/*find Nr*/
	else
#endif
		Nr_index = TxBF_Nr(1, CompSteeringNumofBFer);		/*find Nr*/
	
	switch(Nr_index)
	{
		case 1:
		NDPTxRate = _NSS2_MCS0_RATE_;
		break;

		case 2:
		NDPTxRate = _NSS3_MCS0_RATE_;
		break;

		case 3:
		NDPTxRate = _NSS4_MCS0_RATE_;
		break;
			
		default:
		NDPTxRate = _NSS2_MCS0_RATE_;
		break;
	
	}

return NDPTxRate;

}


VOID
PacketAppendData(
	IN	POCTET_STRING	packet,
	IN	OCTET_STRING	data
	)
{
	pu1Byte buf = packet->Octet + packet->Length;
	memcpy( buf, data.Octet, data.Length);
	packet->Length = packet->Length + data.Length;
}

VOID
Beamforming_GidPAid(
	struct rtl8192cd_priv *priv,
	struct stat_info	*pstat)
{

	if (OPMODE & WIFI_AP_STATE)
	{
		u2Byte	AID = (u2Byte) ((pstat->aid) & 0x1ff); 		//AID[0:8]
		u2Byte	bssid = 0;	

		pstat->g_id = 63;
		
		bssid = ((BSSID[5] & 0xf0) >> 4) ^ (BSSID[5] & 0xf);	// BSSID[44:47] xor BSSID[40:43]
		pstat->p_aid = (AID + bssid * 32) & 0x1ff;		// (dec(A) + dec(B)*32) mod 512		

	}
	else if (OPMODE & WIFI_ADHOC_STATE)
	{
		pstat->p_aid = REMAP_AID(pstat);
		pstat->g_id = 63;

	}
	else if (OPMODE & WIFI_STATION_STATE)
	{
		pstat->g_id = 0;		
		pstat->p_aid = ((int)(pstat->hwaddr[5])<<1) | (pstat->hwaddr[4]>>7);
	}	
}

BEAMFORMING_CAP
Beamforming_GetEntryBeamCapByMacId(
	struct rtl8192cd_priv *priv,
	IN	u1Byte		MacId
	)
{
	u1Byte	i = 0;
	PRT_BEAMFORMING_INFO	pBeamformingInfo = &(priv->pshare->BeamformingInfo);
	BEAMFORMING_CAP			BeamformEntryCap = BEAMFORMING_CAP_NONE;
	
	for(i = 0; i < BEAMFORMEE_ENTRY_NUM; i++)
	{
		if(pBeamformingInfo->BeamformeeEntry[i].bUsed &&
			(MacId == pBeamformingInfo->BeamformeeEntry[i].MacId))
		{
			BeamformEntryCap =  pBeamformingInfo->BeamformeeEntry[i].BeamformEntryCap;
			i = BEAMFORMEE_ENTRY_NUM;
		}
	}

	return BeamformEntryCap;
}


PRT_BEAMFORMING_ENTRY
Beamforming_GetBFeeEntryByAddr(
	struct rtl8192cd_priv *priv,
	IN	pu1Byte		RA,
	OUT	pu1Byte		Idx
	)
{
	u1Byte	i = 0;
	PRT_BEAMFORMING_INFO pBeamformingInfo = &(priv->pshare->BeamformingInfo);
	
	for(i = 0; i < BEAMFORMEE_ENTRY_NUM; i++)
	{
		if((pBeamformingInfo->BeamformeeEntry[i].bUsed) && 
			((memcmp(RA, pBeamformingInfo->BeamformeeEntry[i].MacAddr, MACADDRLEN)) == 0))
		{
			*Idx = i;
			return &(pBeamformingInfo->BeamformeeEntry[i]);
		}
	}
	return NULL;
}

PRT_BEAMFORMER_ENTRY
Beamforming_GetBFerEntryByAddr(
	struct rtl8192cd_priv *priv,
	IN	pu1Byte		RA,
	OUT	pu1Byte		Idx
	)
{
	u1Byte	i = 0;
	PRT_BEAMFORMING_INFO pBeamformingInfo = &(priv->pshare->BeamformingInfo);
	
	for(i = 0; i < BEAMFORMER_ENTRY_NUM; i++)
	{
		if((pBeamformingInfo->BeamformerEntry[i].bUsed) && 
			((memcmp(RA, pBeamformingInfo->BeamformerEntry[i].MacAddr, MACADDRLEN)) == 0))
		{
			*Idx = i;
			return &(pBeamformingInfo->BeamformerEntry[i]);
		}
	}
	return NULL;
}


PRT_BEAMFORMING_ENTRY
Beamforming_GetEntryByMacId(
	struct rtl8192cd_priv *priv,
	u1Byte		MacId,
	pu1Byte		Idx
	)
{
	u1Byte	i = 0;
	PRT_BEAMFORMING_INFO pBeamformingInfo = &(priv->pshare->BeamformingInfo);
	
	for(i = 0; i < BEAMFORMEE_ENTRY_NUM; i++)
	{
		if(pBeamformingInfo->BeamformeeEntry[i].bUsed && 
			(MacId == pBeamformingInfo->BeamformeeEntry[i].MacId))
		{
			*Idx = i;
			return &(pBeamformingInfo->BeamformeeEntry[i]);
		}
	}

	return NULL;

}

PRT_BEAMFORMING_ENTRY
Beamforming_GetFreeBFeeEntry(
	struct rtl8192cd_priv *priv,
    OUT	pu1Byte		Idx,
    pu1Byte             RA
	)
{
	u1Byte	i = 0;
	PRT_BEAMFORMING_INFO pBeamformingInfo = &(priv->pshare->BeamformingInfo);
	
    ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]%s Start!\n", __FUNCTION__));

    ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]%s, RA= 0x %x%x%x%x%x%x\n",
        __FUNCTION__,
        RA[0],RA[1],RA[2],RA[3],RA[4],RA[5]));

    ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]%s, BFeeEntry_Idx0= 0x %x%x%x%x%x%x\n",
    __FUNCTION__,
    pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[0],
    pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[1],
    pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[2],
    pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[3],
    pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[4],
    pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[5]));


    if( !(memcmp(RA, pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0, MACADDRLEN)) ){
        ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@%s, (memcmp(RA, pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0, MACADDRLEN)) == 1, return NULL!!\n", __FUNCTION__));
        return NULL;
    }
    else if(!(memcmp(RA, pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx1, MACADDRLEN))){
        ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@%s, (memcmp(RA, pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx1, MACADDRLEN)) == 1, return NULL!!\n", __FUNCTION__));
        return NULL;
    }

	for(i = 0; i < BEAMFORMEE_ENTRY_NUM; i++)
	{
		if(pBeamformingInfo->BeamformeeEntry[i].bUsed == FALSE)
		{
			*Idx = i;
			return &(pBeamformingInfo->BeamformeeEntry[i]);
		}	
	}
	return NULL;
}

PRT_BEAMFORMER_ENTRY
Beamforming_GetFreeBFerEntry(
	struct rtl8192cd_priv *priv,
	OUT	pu1Byte		Idx,
	pu1Byte             RA
	)
{
	u1Byte	i = 0;
	PRT_BEAMFORMING_INFO pBeamformingInfo = &(priv->pshare->BeamformingInfo);
	
    ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]%s Start!\n", __FUNCTION__));
    
    if(!(memcmp(RA, pBeamformingInfo->DelEntryListByMACAddr.BFerEntry_Idx0, MACADDRLEN))){
        ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@s, (memcmp(RA, pBeamformingInfo->DelEntryListByMACAddr.BFerEntry_Idx0, MACADDRLEN)) == 1, return NULL!!\n", __FUNCTION__));
        return NULL;
    }
    else if(!(memcmp(RA, pBeamformingInfo->DelEntryListByMACAddr.BFerEntry_Idx1, MACADDRLEN))){
        ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@s, (memcmp(RA, pBeamformingInfo->DelEntryListByMACAddr.BFerEntry_Idx1, MACADDRLEN)) == 1, return NULL!!\n", __FUNCTION__));
        return NULL;
    }
    
	for(i = 0; i < BEAMFORMER_ENTRY_NUM; i++)
	{
		if(pBeamformingInfo->BeamformerEntry[i].bUsed == FALSE)
		{
			*Idx = i;
			return &(pBeamformingInfo->BeamformerEntry[i]);
		}	
	}
	return NULL;
}

PRT_BEAMFORMING_ENTRY
Beamforming_AddBFeeEntry(
	struct rtl8192cd_priv *priv,
	struct stat_info	*pSTA,
		pu1Byte				RA,
		u2Byte				AID,
		u2Byte				MacID,
		u1Byte				BW,
		BEAMFORMING_CAP		BeamformCap,
		pu1Byte				Idx,
		u2Byte				CompSteeringNumofBFer
	)
{
	PRT_BEAMFORMING_ENTRY	pEntry;
	pEntry = Beamforming_GetFreeBFeeEntry(priv, Idx,RA);

    // Check if this MAC address is in DelEntryList
    

	if(pEntry != NULL)
	{	
		pEntry->bUsed = TRUE;
		pEntry->AID = AID;
		pEntry->MacId = MacID;
		pEntry->BW = BW;

		// AID -> P_AID
		if (OPMODE & WIFI_AP_STATE)
		{
			u2Byte bssid = ((GET_MY_HWADDR[5]>> 4) & 0x0f ) ^ 
							(GET_MY_HWADDR[5] & 0xf);				// BSSID[44:47] xor BSSID[40:43]
			pEntry->P_AID = (AID + (bssid <<5)) & 0x1ff;				// (dec(A) + dec(B)*32) mod 512	

		}
		else if (OPMODE & WIFI_ADHOC_STATE)
		{
//			pEntry->P_AID = AID;
			pEntry->P_AID = 0;
	
		}
		else if (OPMODE & WIFI_STATION_STATE) {
			pEntry->P_AID =  RA[5];						// BSSID[39:47]
			pEntry->P_AID = (pEntry->P_AID << 1) | (RA[4] >> 7 );
		}
		//
			
		memcpy(pEntry->MacAddr, RA, MACADDRLEN);
		pEntry->bTxBF = FALSE;
		pEntry->bSound = FALSE;
		
		pEntry->BeamformEntryCap = BeamformCap;	
		pEntry->BeamformEntryState = BEAMFORMING_ENTRY_STATE_UNINITIALIZE;
		pEntry->LogStatusFailCnt = 0;

		pEntry->CompSteeringNumofBFer = CompSteeringNumofBFer;
		pEntry->pSTA = pSTA;

#ifdef MBSSID
		if(GET_CHIP_VER(priv) == VERSION_8812E)
			if (GET_MIB(GET_ROOT(priv))->miscEntry.vap_enable)
				rtl8192cd_set_mbssid(priv, RA, *Idx);
#endif
		return pEntry;
	}
	else
		return NULL;
}

PRT_BEAMFORMER_ENTRY
Beamforming_AddBFerEntry(
		struct rtl8192cd_priv *priv,
		pu1Byte				RA,
		u2Byte				AID,
		BEAMFORMING_CAP	BeamformCap,
		pu1Byte				Idx,
		u2Byte				NumofSoundingDim
	)
{
	PRT_BEAMFORMER_ENTRY	pEntry;
    
    ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]%s Start!\n", __FUNCTION__));

    pEntry = Beamforming_GetFreeBFerEntry(priv, Idx, RA);

	if(pEntry != NULL)
	{	
		pEntry->bUsed = TRUE;			

		// AID -> P_AID
		if (OPMODE & WIFI_AP_STATE)
		{
                u2Byte bssid = ((GET_MY_HWADDR[5]>> 4) & 0x0f ) ^ (GET_MY_HWADDR[5] & 0xf);     // BSSID[44:47] xor BSSID[40:43]
			pEntry->P_AID = (AID + (bssid <<5)) & 0x1ff;				// (dec(A) + dec(B)*32) mod 512	

		}
		else if (OPMODE & WIFI_ADHOC_STATE)
		{
			pEntry->P_AID = 0;
		}
		else if (OPMODE & WIFI_STATION_STATE) {
			pEntry->P_AID =  RA[5];						// BSSID[39:47]
			pEntry->P_AID = (pEntry->P_AID << 1) | (RA[4] >> 7 );
		}

		memcpy(pEntry->MacAddr, RA, MACADDRLEN);
		pEntry->BeamformEntryCap = BeamformCap;	
		pEntry->NumofSoundingDim = NumofSoundingDim;
		
            pEntry->ClockResetTimes = 0;
            pEntry->NDPAPreLogSeq = 0;
            pEntry->NDPALogSeq = 0;
            pEntry->NDPALogRetryCnt = 0;
            pEntry->NDPALogSuccess = 0;
//            pEntry->LogStatusFailCnt = 0;
            ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@%s, BFer Entry!=NULL\n", __FUNCTION__));

		return pEntry;
	}
	else
		return NULL;
}


BOOLEAN
Beamforming_RemoveEntry(
	struct rtl8192cd_priv *priv,
	IN	pu1Byte		RA,
	OUT	pu1Byte		Idx
	)
{
	PRT_BEAMFORMER_ENTRY	pBFerEntry = Beamforming_GetBFerEntryByAddr(priv, RA, Idx);
    PRT_BEAMFORMING_ENTRY   pBFeeEntry = Beamforming_GetBFeeEntryByAddr(priv, RA, Idx);
    PRT_BEAMFORMING_INFO    pBeamformingInfo = &(priv->pshare->BeamformingInfo);

    u1Byte  i;
    // CurDelBFerBFeeEntrySel had been decided by the function who calls Beamforming_DeInitEntry
    DEL_ENTRY_TYPE_SEL  CurDelBFerBFeeEntrySel=pBeamformingInfo->CurDelBFerBFeeEntrySel;
    
	BOOLEAN ret = FALSE;

//    if( (CurDelBFerBFeeEntrySel== BFerEntry)||(CurDelBFerBFeeEntrySel == BFerBFeeEntry) )
/*
    if( CurDelBFerBFeeEntrySel == BFerEntry)
    {
        if (pBFerEntry != NULL)
        {
		pBFerEntry->bUsed = FALSE;
		pBFerEntry->BeamformEntryCap = BEAMFORMING_CAP_NONE;

            if(*Idx==0)
                memcpy(&pBeamformingInfo->DelEntryListByMACAddr.BFerEntry_Idx0[0], RA, 6);                
            else
                memcpy(&pBeamformingInfo->DelEntryListByMACAddr.BFerEntry_Idx1[0], RA, 6);
            
		ret = TRUE;
            ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@%s, Remove BFerEntry idx=%d\n", __FUNCTION__, *Idx));
        }
    }
*/
    if (pBFerEntry != NULL)
    {
        pBFerEntry->bUsed = FALSE;
        pBFerEntry->BeamformEntryCap = BEAMFORMING_CAP_NONE;

        if(CurDelBFerBFeeEntrySel == BFerEntry)
        {
            if(*Idx==0)
                memcpy(pBeamformingInfo->DelEntryListByMACAddr.BFerEntry_Idx0, RA, 6);                
            else
                memcpy(pBeamformingInfo->DelEntryListByMACAddr.BFerEntry_Idx1, RA, 6);
	}
	
		ret = TRUE;
	}

    if (pBFeeEntry != NULL) 
    {
        pBFeeEntry->bUsed = FALSE;
        pBFeeEntry->BeamformEntryCap = BEAMFORMING_CAP_NONE;

        if(CurDelBFerBFeeEntrySel == BFeeEntry)
        {
            if(*Idx==0)
                memcpy(&pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[0], RA, 6);            
            else
                memcpy(&pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx1[0], RA, 6);
        }
        
        ret = TRUE;    
    }
    
/*
    if( (CurDelBFerBFeeEntrySel == BFeeEntry)||(CurDelBFerBFeeEntrySel == BFerBFeeEntry) )
    {
        if (pBFeeEntry != NULL) 
        {
            pBFeeEntry->bUsed = FALSE;
            pBFeeEntry->BeamformEntryCap = BEAMFORMING_CAP_NONE;

            if(*Idx==0)
                memcpy(&pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[0], RA, 6);            
            else
                memcpy(&pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx1[0], RA, 6);

            ret = TRUE;
        
            ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@%s, Remove BFeeEntry idx=%d\n", __FUNCTION__, *Idx));
            ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@%s, RA=0x%x%x%x%x%x%x\n",
                __FUNCTION__,
                RA[0],RA[1],RA[2],RA[3],RA[4],RA[5]));

            ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@%s, BFeeEntry_Idx0=0x%x%x%x%x%x%x, BFeeEntry_Idx1=0x%x%x%x%x%x%x\n",
            __FUNCTION__,
            pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[0],
            pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[1],
            pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[2],
            pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[3],
            pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[4],
            pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx0[5],
            pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx1[0],
            pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx1[1],
            pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx1[2],
            pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx1[3],
            pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx1[4],
            pBeamformingInfo->DelEntryListByMACAddr.BFeeEntry_Idx1[5]
            ));

        }
            
    }
*/
	return ret;
}

BOOLEAN
Beamforming_InitEntry(
	struct rtl8192cd_priv	*priv,
	struct stat_info		*pSTA,
	pu1Byte				BFerBFeeIdx	
	)
{

	PRT_BEAMFORMING_ENTRY	pBeamformEntry = NULL;
	PRT_BEAMFORMER_ENTRY	pBeamformerEntry = NULL;
	pu1Byte					RA; 
	u2Byte					AID, MacID;
	u1Byte					WirelessMode;
	u1Byte					BW = HT_CHANNEL_WIDTH_20;
	BEAMFORMING_CAP		BeamformCap = BEAMFORMING_CAP_NONE;	
	u1Byte					BFerIdx = 0xF, BFeeIdx = 0xF;
	u2Byte					CompSteeringNumofBFer = 0, NumofSoundingDim = 0;

	// The current setting does not support Beaforming
	if (priv->pmib->dot11RFEntry.txbf == 0)
	{
		return FALSE;
	}

	// IBSS, AP mode
	if(pSTA != NULL)
	{
		AID = pSTA->aid;
		RA  = pSTA->hwaddr;
		MacID = pSTA->aid;

		WirelessMode = pSTA->WirelessMode;
		BW = pSTA->tx_bw;
	}
	else	// Client mode
	{
		return FALSE;
	}

	if( WirelessMode < WIRELESS_MODE_N_24G)
		return FALSE;

	else 
	{

// BIT 4 implies capable of sending NDPA (BFER),
// BIT 3 implies capable of receiving NDPA (BFEE),

	if(pSTA->ht_cap_len && (cpu_to_le32(pSTA->ht_cap_buf.txbf_cap) & 0x8)&& (priv->pmib->dot11RFEntry.txbfer == 1))	//bfer
	{
		BeamformCap |=BEAMFORMER_CAP_HT_EXPLICIT;
		CompSteeringNumofBFer = (u1Byte)((cpu_to_le32(pSTA->ht_cap_buf.txbf_cap) & (BIT(23)|BIT(24)))>>23);
//		panic_printk("[%d] BeamformCap = BEAMFORMER_CAP_HT_EXPLICIT \n",__LINE__);
	}
	if (pSTA->ht_cap_len && (cpu_to_le32(pSTA->ht_cap_buf.txbf_cap) & 0x10)&& (priv->pmib->dot11RFEntry.txbfee == 1))	//bfee
	{
		BeamformCap |=BEAMFORMEE_CAP_HT_EXPLICIT;
		NumofSoundingDim = (u1Byte)((cpu_to_le32(pSTA->ht_cap_buf.txbf_cap) & (BIT(27)|BIT(28)))>>27);
//		panic_printk("[%d] BeamformCap = BEAMFORMEE_CAP_HT_EXPLICIT \n",__LINE__);
	}

#ifdef RTK_AC_SUPPORT			
		if(WirelessMode == WIRELESS_MODE_AC_5G)
		{
			if(pSTA->vht_cap_len && (cpu_to_le32(pSTA->vht_cap_buf.vht_cap_info) & BIT(SU_BFEE_S)) && (priv->pmib->dot11RFEntry.txbfer == 1))  // ACÁÙ¨S¨Ì¾Úbfer or bfee¾×
			{
			BeamformCap |=BEAMFORMER_CAP_VHT_SU;
			CompSteeringNumofBFer = (u1Byte)((cpu_to_le32(pSTA->vht_cap_buf.vht_cap_info) & (BIT(MAX_ANT_SUPP_S)|BIT(MAX_ANT_SUPP_S+1)|BIT(MAX_ANT_SUPP_E)))>>MAX_ANT_SUPP_S);
			}
			if(pSTA->vht_cap_len && (cpu_to_le32(pSTA->vht_cap_buf.vht_cap_info) & BIT(SU_BFER_S)) && (priv->pmib->dot11RFEntry.txbfee == 1))
			{
			BeamformCap |=BEAMFORMEE_CAP_VHT_SU;
			NumofSoundingDim = (u1Byte)((cpu_to_le32(pSTA->vht_cap_buf.vht_cap_info) & (BIT(SOUNDING_DIMENSIONS_S)|BIT(SOUNDING_DIMENSIONS_S+1)|BIT(SOUNDING_DIMENSIONS_E)))>>SOUNDING_DIMENSIONS_S);
			}
		}
#endif		
	}

	if(BeamformCap == BEAMFORMING_CAP_NONE)
		return FALSE;

	ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, CompSteeringNumofBFer = %d, NumofSoundingDim = %d\n", __FUNCTION__, CompSteeringNumofBFer, NumofSoundingDim));
// bfme
	if((BeamformCap & BEAMFORMEE_CAP_HT_EXPLICIT) || (BeamformCap & BEAMFORMEE_CAP_VHT_SU))
	{
		pBeamformerEntry = Beamforming_GetBFerEntryByAddr(priv, RA, &BFerIdx);

		if(pBeamformerEntry == NULL)
		{
			pBeamformerEntry = Beamforming_AddBFerEntry(priv, RA, AID, BeamformCap, &BFerIdx, NumofSoundingDim);
			
			if(pBeamformerEntry == NULL)
				ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, Not enough BFer entry!\n", __FUNCTION__));
		}
	}

// bfer
	if((BeamformCap & BEAMFORMER_CAP_HT_EXPLICIT) || (BeamformCap & BEAMFORMER_CAP_VHT_SU))
	{
		pBeamformEntry = Beamforming_GetBFeeEntryByAddr(priv, RA, &BFeeIdx);
		
		if(pBeamformEntry == NULL)
		{
			pBeamformEntry = Beamforming_AddBFeeEntry(priv, pSTA, RA, AID, MacID, BW, BeamformCap, &BFeeIdx, CompSteeringNumofBFer);

			if(pBeamformEntry == NULL)
			{
				return NULL;
			}
			else
				pBeamformEntry->BeamformEntryState = BEAMFORMING_ENTRY_STATE_INITIALIZEING;
		}	
		else
		{
			// Entry has been created. If entry is initialing or progressing then errors occur.
			if(	pBeamformEntry->BeamformEntryState != BEAMFORMING_ENTRY_STATE_INITIALIZED && 
				pBeamformEntry->BeamformEntryState != BEAMFORMING_ENTRY_STATE_PROGRESSED)
			{
				ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, Error State of Beamforming\n", __FUNCTION__));
				return FALSE;
			}	
			else
				pBeamformEntry->BeamformEntryState = BEAMFORMING_ENTRY_STATE_INITIALIZEING;
		}

		pBeamformEntry->BeamformEntryState = BEAMFORMING_ENTRY_STATE_INITIALIZED;
		Beamforming_AutoTest(priv, BFeeIdx, pBeamformEntry);
	}

	*BFerBFeeIdx = (BFerIdx<<4) | BFeeIdx;
	ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s,  BFerIdx=%d, BFeeIdx=%d, BFerBFeeIdx=%d \n", __FUNCTION__, BFerIdx, BFeeIdx, *BFerBFeeIdx));

	return TRUE;
}

BOOLEAN
Beamforming_DeInitEntry(
	struct rtl8192cd_priv *priv,
	pu1Byte			RA
	)
{
	u1Byte					Idx = 0;

    ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]%s Start!!!\n", __FUNCTION__));
	
	if(Beamforming_RemoveEntry(priv, RA, &Idx) == TRUE)
	{
		Beamforming_SetBeamFormLeave(priv, Idx);

#ifdef CONFIG_RTL_8812_SUPPORT				// 8812 only??
#ifdef MBSSID
		if (GET_MIB(GET_ROOT(priv))->miscEntry.vap_enable)
			rtl8192cd_clear_mbssid(priv, Idx);
#endif
#endif
		
		return TRUE;
	}
	else
	{
		// For AP debug, because when STA disconnect AP, release_stainfo will be triggered many times
		return FALSE;
	}

}

VOID
BeamformingReset(
	struct rtl8192cd_priv *priv
	)
{
	u1Byte		Idx = 0;
	PRT_BEAMFORMING_INFO pBeamformingInfo = &(priv->pshare->BeamformingInfo);

	for(Idx = 0; Idx < BEAMFORMEE_ENTRY_NUM; Idx++)
	{
		if(pBeamformingInfo->BeamformeeEntry[Idx].bUsed == TRUE)
		{
			ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, Reset entry idx=%d\n", __FUNCTION__, Idx));
			pBeamformingInfo->BeamformeeEntry[Idx].bUsed = FALSE;
			pBeamformingInfo->BeamformeeEntry[Idx].BeamformEntryCap = BEAMFORMING_CAP_NONE;
			//pBeamformingInfo->BeamformeeEntry[Idx].BeamformEntryState = BEAMFORMING_ENTRY_STATE_UNINITIALIZE;
			pBeamformingInfo->BeamformeeEntry[Idx].bBeamformingInProgress = FALSE;

			Beamforming_SetBeamFormLeave(priv, Idx);		
		}
	}

	for(Idx = 0; Idx < BEAMFORMER_ENTRY_NUM; Idx++)
	{
		pBeamformingInfo->BeamformerEntry[Idx].bUsed = FALSE;
	}

}



#define FillOctetString(_os,_octet,_len)		\
	(_os).Octet=(pu1Byte)(_octet);			\
	(_os).Length=(_len);

VOID
ConstructHTNDPAPacket(
	struct rtl8192cd_priv *priv,
	pu1Byte				RA,
	pu1Byte				Buffer,
	pu4Byte				pLength,
	u1Byte			 	BW
	)
{
	u2Byte					Duration= 0;
	OCTET_STRING			pNDPAFrame, ActionContent;
	u1Byte					ActionHdr[4] = {ACT_CAT_VENDOR, 0x00, 0xe0, 0x4c};
	int aSifsTime = ((priv->pmib->dot11BssType.net_work_type & WIRELESS_11N) && (priv->pshare->ht_sta_num)) ? 0x10 : 10;


	SET_80211_HDR_FRAME_CONTROL(Buffer,0);
	SET_80211_HDR_ORDER(Buffer, 1);
	SET_80211_HDR_TYPE_AND_SUBTYPE(Buffer,Type_Action_No_Ack);

	memcpy((void *)GetAddr1Ptr(Buffer), RA, MACADDRLEN);
	memcpy((void *)GetAddr2Ptr(Buffer), GET_MY_HWADDR, MACADDRLEN);
	memcpy((void *)GetAddr3Ptr(Buffer), BSSID, MACADDRLEN);

	Duration = 2*aSifsTime + 40;
	
	if(BW== HT_CHANNEL_WIDTH_20_40)
		Duration+= 87;
	else	
		Duration+= 180;

	SET_80211_HDR_DURATION(Buffer, Duration);

	//HT control field
	SET_HT_CTRL_CSI_STEERING(Buffer+sMacHdrLng, 3);
	SET_HT_CTRL_NDP_ANNOUNCEMENT(Buffer+sMacHdrLng, 1);
	
	FillOctetString(pNDPAFrame, Buffer, sMacHdrLng+sHTCLng);

	FillOctetString(ActionContent, ActionHdr, 4);
	PacketAppendData(&pNDPAFrame, ActionContent);	

	*pLength = 32;
}


BOOLEAN
SendHTNDPAPacket(
	struct rtl8192cd_priv *priv,
		pu1Byte				RA,
		u1Byte 				BW,
		u1Byte		NDPTxRate
	)
{
	BOOLEAN					ret = TRUE;
	unsigned char *pbuf 		= get_wlanllchdr_from_poll(priv);
	u4Byte PacketLength;
	DECLARE_TXINSN(txinsn);	

	if(pbuf) 
	{
		memset(pbuf, 0, sizeof(struct wlan_hdr));
		ConstructHTNDPAPacket(
				priv, 
				RA,
				pbuf,
				&PacketLength,
				BW
				);
		
		txinsn.q_num = MGNT_QUEUE;	
		txinsn.fr_type = _PRE_ALLOCLLCHDR_;				

		txinsn.phdr = pbuf;
		txinsn.hdr_len = PacketLength;
		txinsn.fr_len = 0;
		txinsn.tx_rate = NDPTxRate; //_MCS8_RATE_;, According to Nr
		txinsn.fixed_rate = 1;	
		txinsn.ndpa = 1;

		if (rtl8192cd_wlantx(priv, &txinsn) == CONGESTED) {		
			netif_stop_queue(priv->dev);		
			priv->ext_stats.tx_drops++; 	
//			panic_printk("TX DROP: Congested!\n");
			if (txinsn.phdr)
				release_wlanhdr_to_poll(priv, txinsn.phdr); 			
			if (txinsn.pframe)
				release_mgtbuf_to_poll(priv, txinsn.pframe);			
			return 0;	
		}
	}
	else
		ret = FALSE;

	return ret;
}




VOID
ConstructVHTNDPAPacket(
	struct rtl8192cd_priv *priv,
	pu1Byte			RA,
	u2Byte			AID,
	pu1Byte			Buffer,
	pu4Byte			pLength,
	u1Byte 			BW
	)
{
	u2Byte					Duration= 0;
	u1Byte					Sequence = 0;
	pu1Byte					pNDPAFrame = Buffer;
	u2Byte					tmp16;
	
	RT_NDPA_STA_INFO		STAInfo;
	int aSifsTime = ((priv->pmib->dot11BssType.net_work_type & WIRELESS_11N) && (priv->pshare->ht_sta_num)) ? 0x10 : 10;

	// Frame control.
	SET_80211_HDR_FRAME_CONTROL(pNDPAFrame, 0);
	SET_80211_HDR_TYPE_AND_SUBTYPE(pNDPAFrame, Type_NDPA);

	memcpy((void *)GetAddr1Ptr(pNDPAFrame), RA, MACADDRLEN);
	memcpy((void *)GetAddr2Ptr(pNDPAFrame), GET_MY_HWADDR, MACADDRLEN);

	Duration = 2*aSifsTime + 44;
	
	if(BW == HT_CHANNEL_WIDTH_80)
		Duration += 40;
	else if(BW == HT_CHANNEL_WIDTH_20_40)
		Duration+= 87;
	else	
		Duration+= 180;

	SetDuration(pNDPAFrame, Duration);
	Sequence = GET_HW(priv)->sounding_seq<<2;
	GET_HW(priv)->sounding_seq =  (GET_HW(priv)->sounding_seq+1) & 0xfff;
	 
	memcpy(pNDPAFrame+16, &Sequence,1);

	if (OPMODE & WIFI_ADHOC_STATE)
		AID = 0;

	STAInfo.AID = AID;

	STAInfo.FeedbackType = 0;
	STAInfo.NcIndex = 0;
	
	memcpy(&tmp16, (pu1Byte)&STAInfo, 2);
	tmp16 = cpu_to_le16(tmp16);

	memcpy(pNDPAFrame+17, &tmp16, 2);

	*pLength = 19;
}


BOOLEAN
SendVHTNDPAPacket(
	struct rtl8192cd_priv *priv,
	IN	pu1Byte			RA,
	IN	u2Byte			AID,
	u1Byte 				BW,
	u1Byte		NDPTxRate
	)
{
	BOOLEAN					ret = TRUE;
	u4Byte 					PacketLength;
	unsigned char *pbuf 	= get_wlanllchdr_from_poll(priv);
	DECLARE_TXINSN(txinsn);	

	if(pbuf)
	{
		memset(pbuf, 0, sizeof(struct wlan_hdr));

		ConstructVHTNDPAPacket	(
			priv, 
			RA,
			AID,
			pbuf,
			&PacketLength,
			BW
			);

		txinsn.q_num = MANAGE_QUE_NUM;
		txinsn.fr_type = _PRE_ALLOCLLCHDR_;		
		txinsn.phdr = pbuf;
		txinsn.hdr_len = PacketLength;
		txinsn.fr_len = 0;
		txinsn.fixed_rate = 1;	
		txinsn.tx_rate = NDPTxRate;	// According to Nr	
		txinsn.ndpa = 1;

		if (rtl8192cd_wlantx(priv, &txinsn) == CONGESTED) {		
			netif_stop_queue(priv->dev);		
			priv->ext_stats.tx_drops++; 	
//			panic_printk("TX DROP: Congested!\n");
			if (txinsn.phdr)
				release_wlanhdr_to_poll(priv, txinsn.phdr); 			
			if (txinsn.pframe)
				release_mgtbuf_to_poll(priv, txinsn.pframe);
			return 0;	
		}
	}
	else
		ret = FALSE;

	return ret;
}



u1Byte
beamforming_SoundingIdx(
	PRT_BEAMFORMING_INFO 			pBeamInfo
	)
{
	u1Byte							Idx = 0;
	PRT_BEAMFORMING_PERIOD_INFO	pBeamPeriodInfo = &(pBeamInfo->BeamformingPeriodInfo);

	if(	pBeamPeriodInfo->Mode == SOUNDING_SW_VHT_TIMER ||pBeamPeriodInfo->Mode == SOUNDING_SW_HT_TIMER ||
		pBeamPeriodInfo->Mode == SOUNDING_HW_VHT_TIMER ||pBeamPeriodInfo->Mode == SOUNDING_HW_HT_TIMER)
		Idx = pBeamPeriodInfo->Idx;
	else
		Idx = 0;

	return Idx;
}


BEAMFORMING_NOTIFY_STATE
beamfomring_bSounding(
	PRT_BEAMFORMING_INFO 	pBeamInfo,
	pu1Byte					Idx
	)
{
	BEAMFORMING_NOTIFY_STATE		bSounding = BEAMFORMING_NOTIFY_NONE;
	//RT_BEAMFORMING_ENTRY			Entry = pBeamInfo->BeamformeeEntry[*Idx];
	RT_BEAMFORMING_PERIOD_INFO		BeamPeriodInfo = pBeamInfo->BeamformingPeriodInfo;

	if(BeamPeriodInfo.Mode == SOUNDING_STOP_All_TIMER)
		bSounding = BEAMFORMING_NOTIFY_RESET;
//	else if(BeamPeriodInfo.Mode == SOUNDING_STOP_OID_TIMER && Entry.bTxBF == FALSE)
//		bSounding = BEAMFORMING_NOTIFY_RESET;
	else
	{
		u1Byte i;

		for(i=0;i<BEAMFORMEE_ENTRY_NUM;i++)
		{
			//panic_printk("[David]@%s: BFee Entry %d bUsed=%d, bSound=%d \n", __FUNCTION__, i, pBeamInfo->BeamformeeEntry[i].bUsed, pBeamInfo->BeamformeeEntry[i].bSound);
			if(pBeamInfo->BeamformeeEntry[i].bUsed && (!pBeamInfo->BeamformeeEntry[i].bSound))
			{
				*Idx = i;
				bSounding = BEAMFORMING_NOTIFY_ADD;
			}

			if((!pBeamInfo->BeamformeeEntry[i].bUsed) && pBeamInfo->BeamformeeEntry[i].bSound)
			{
				*Idx = i;
				bSounding = BEAMFORMING_NOTIFY_DELETE;
			}
		}
	}

	return bSounding;
}


SOUNDING_MODE
beamforming_SoundingMode(
	PRT_BEAMFORMING_INFO 	pBeamInfo,
	u1Byte					Idx
	)
{
	RT_BEAMFORMING_PERIOD_INFO		BeamPeriodInfo = pBeamInfo->BeamformingPeriodInfo;	
	SOUNDING_MODE					Mode = BeamPeriodInfo.Mode;
	RT_BEAMFORMING_ENTRY			Entry = pBeamInfo->BeamformeeEntry[Idx];

	if(	BeamPeriodInfo.Mode == SOUNDING_SW_VHT_TIMER || BeamPeriodInfo.Mode == SOUNDING_SW_HT_TIMER ||
		BeamPeriodInfo.Mode == SOUNDING_HW_VHT_TIMER || BeamPeriodInfo.Mode == SOUNDING_HW_HT_TIMER )
		Mode = BeamPeriodInfo.Mode;
	else	if(Entry.BeamformEntryCap & BEAMFORMER_CAP_VHT_SU)
		Mode = SOUNDING_AUTO_VHT_TIMER;
	else	if(Entry.BeamformEntryCap & BEAMFORMER_CAP_HT_EXPLICIT)
		Mode = SOUNDING_AUTO_HT_TIMER;

	return Mode;
}


u2Byte
beamforming_SoundingTime(
	PRT_BEAMFORMING_INFO 	pBeamInfo,
	SOUNDING_MODE			Mode
	)
{
	u2Byte							SoundingTime = 0xffff;
	RT_BEAMFORMING_PERIOD_INFO		BeamPeriodInfo = pBeamInfo->BeamformingPeriodInfo;

	if(Mode == SOUNDING_HW_HT_TIMER || Mode == SOUNDING_HW_VHT_TIMER)
		SoundingTime = BeamPeriodInfo.BeamPeriod * 32;
	else	if(Mode == SOUNDING_SW_HT_TIMER || Mode == SOUNDING_SW_VHT_TIMER)
		SoundingTime = BeamPeriodInfo.BeamPeriod ;
	else
		SoundingTime = 20*32;

	return SoundingTime;
}


u1Byte
beamforming_SoundingBW(
	PRT_BEAMFORMING_INFO 	pBeamInfo,
	SOUNDING_MODE			Mode,
	u1Byte					Idx
	)
{
	u1Byte							SoundingBW = HT_CHANNEL_WIDTH_20;
	RT_BEAMFORMING_ENTRY			Entry = pBeamInfo->BeamformeeEntry[Idx];
	RT_BEAMFORMING_PERIOD_INFO		BeamPeriodInfo = pBeamInfo->BeamformingPeriodInfo;

	if(Mode == SOUNDING_HW_HT_TIMER || Mode == SOUNDING_HW_VHT_TIMER)
		SoundingBW = BeamPeriodInfo.BW;
	else	if(Mode == SOUNDING_SW_HT_TIMER || Mode == SOUNDING_SW_VHT_TIMER)
		SoundingBW = BeamPeriodInfo.BW;
	else 
		SoundingBW = Entry.BW;

	return SoundingBW;
}


VOID
beamforming_StartPeriod(
	struct rtl8192cd_priv *priv,
	u1Byte				Idx
	)
{

	PRT_BEAMFORMING_INFO 		pBeamInfo = &(priv->pshare->BeamformingInfo);
	PRT_BEAMFORMING_TIMER_INFO	pBeamTimerInfo = &(pBeamInfo->BeamformingTimerInfo[Idx]);	


//	pBeamTimerInfo->Idx = Idx;
	pBeamTimerInfo->Mode = beamforming_SoundingMode(pBeamInfo, Idx);
	pBeamTimerInfo->BW = beamforming_SoundingBW(pBeamInfo, pBeamTimerInfo->Mode, Idx);
	pBeamTimerInfo->BeamPeriod = beamforming_SoundingTime(pBeamInfo, pBeamTimerInfo->Mode);

	if(pBeamTimerInfo->Mode == SOUNDING_SW_VHT_TIMER || pBeamTimerInfo->Mode == SOUNDING_SW_HT_TIMER) 
	{
		ODM_SetTimer(ODMPTR, &pBeamInfo->BeamformingTimer, pBeamTimerInfo->BeamPeriod);
	} 
	else
	{
		Beamforming_SetHWTimer(priv, pBeamTimerInfo->BeamPeriod);
	}	

//	panic_printk ("%s Idx %d Mode %d BW %d Period %d\n", __FUNCTION__, 
//			Idx, pBeamTimerInfo->Mode, pBeamTimerInfo->BW, pBeamTimerInfo->BeamPeriod);
}


VOID
beamforming_EndPeriod_SW(
		struct rtl8192cd_priv *priv,
		u1Byte		Idx
	)
{
//	u1Byte						Idx = 0;
	PRT_BEAMFORMING_ENTRY		pBeamformEntry;
	PRT_BEAMFORMING_INFO 		pBeamInfo = &(priv->pshare->BeamformingInfo);
	PRT_BEAMFORMING_TIMER_INFO	pBeamTimerInfo = &(pBeamInfo->BeamformingTimerInfo[Idx]);

	if(pBeamTimerInfo->Mode == SOUNDING_SW_VHT_TIMER || pBeamTimerInfo->Mode == SOUNDING_SW_HT_TIMER) 
	{
		ODM_CancelTimer(ODMPTR, &pBeamInfo->BeamformingTimer);
	}
	else
	{
		Beamforming_StopHWTimer(priv);
	}

}

VOID
beamforming_EndPeriod_FW(
		struct rtl8192cd_priv 	*priv,
		u1Byte				Idx
	)
{
	return;
}

VOID
beamforming_ClearEntry_SW(
		struct rtl8192cd_priv 	*priv,
		BOOLEAN				IsDelete,
		u1Byte				DeleteIdx
	)
{
	u1Byte						Idx = 0;
	PRT_BEAMFORMING_ENTRY		pBeamformEntry;
	PRT_BEAMFORMING_INFO 		pBeamInfo = &(priv->pshare->BeamformingInfo);

	if(IsDelete)
	{
		if(DeleteIdx<BEAMFORMEE_ENTRY_NUM)
		{
			pBeamformEntry = pBeamInfo->BeamformeeEntry + DeleteIdx;

			if(!((!pBeamformEntry->bUsed) && pBeamformEntry->bSound))
			{
				ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, SW DeleteIdx is wrong!\n", __FUNCTION__)); 
				return;
			}
		}

		if(pBeamformEntry->BeamformEntryState == BEAMFORMING_ENTRY_STATE_PROGRESSING)
		{
			pBeamformEntry->bBeamformingInProgress = FALSE;
			pBeamformEntry->BeamformEntryState = BEAMFORMING_ENTRY_STATE_UNINITIALIZE;
		}
		else if(pBeamformEntry->BeamformEntryState == BEAMFORMING_ENTRY_STATE_PROGRESSED)
		{
			pBeamformEntry->BeamformEntryState  = BEAMFORMING_ENTRY_STATE_UNINITIALIZE;
			Beamforming_SetBeamFormStatus(priv, DeleteIdx);
		}	
		pBeamformEntry->bSound=FALSE;
		
	}
	else
	{
		for(Idx = 0; Idx < BEAMFORMEE_ENTRY_NUM; Idx++)
		{
			pBeamformEntry = pBeamInfo->BeamformeeEntry+Idx;

			if(pBeamformEntry->bSound)
			{
				ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, SW Reset entry %d\n", __FUNCTION__, Idx)); 

				/*	
				*	If End procedure is 
				*	1. Between (Send NDPA, C2H packet return), reset state to initialized.
				*	After C2H packet return , status bit will be set to zero. 
				*r
				*	2. After C2H packet, then reset state to initialized and clear status bit.
				*/ 
				if(pBeamformEntry->BeamformEntryState == BEAMFORMING_ENTRY_STATE_PROGRESSING)
					{
					Beamforming_End(priv, 0);
					}	
				else if(pBeamformEntry->BeamformEntryState == BEAMFORMING_ENTRY_STATE_PROGRESSED)
				{
					pBeamformEntry->BeamformEntryState  = BEAMFORMING_ENTRY_STATE_INITIALIZED;
					Beamforming_SetBeamFormStatus(priv, Idx);
				}	
				
				pBeamformEntry->bSound=FALSE;
			}
		}			
	}

}

VOID
beamforming_ClearEntry_FW(
		struct rtl8192cd_priv 	*priv,
		BOOLEAN				IsDelete,
		u1Byte				DeleteIdx
	)
{
	return;
}

struct rtl8192cd_priv* 
getBeamEntryDev(struct rtl8192cd_priv *priv, PRT_BEAMFORMING_ENTRY pEntry)
{
	struct stat_info *pstat;
	struct rtl8192cd_priv *vxd_priv;	
	int j;

	pstat = get_stainfo(priv, pEntry->MacAddr);
	if(pstat)
		return priv;
	
#ifdef MBSSID
	  if ((OPMODE & WIFI_AP_STATE) && priv->pmib->miscEntry.vap_enable) 
	  {
		for (j=0; j<RTL8192CD_NUM_VWLAN; j++) 
		{
			if ((priv->pvap_priv[j]->assoc_num > 0) && IS_DRV_OPEN(priv->pvap_priv[j]))
			{
				pstat = get_stainfo(priv->pvap_priv[j], pEntry->MacAddr);
				if(pstat)
					return priv->pvap_priv[j];

			}
		}
	}
#endif			
#ifdef UNIVERSAL_REPEATER
	vxd_priv = GET_VXD_PRIV(priv);
	priv = vxd_priv;
	if((OPMODE & WIFI_STATION_STATE) && (vxd_priv->assoc_num > 0) && IS_DRV_OPEN(vxd_priv)	) 
	{ 	
		pstat = get_stainfo(vxd_priv, pEntry->MacAddr);
		if(pstat)
			return vxd_priv;
	}
#endif
	return NULL;

}


BOOLEAN
BeamformingStart_V2(
	struct rtl8192cd_priv *priv,
	u1Byte			Idx,
	u1Byte			Mode, 
	u1Byte			BW
	)
{
	pu1Byte					RA = NULL;
	PRT_BEAMFORMING_ENTRY	pEntry;
	BOOLEAN					ret = TRUE;
	PRT_BEAMFORMING_INFO 	pBeamformingInfo = &(priv->pshare->BeamformingInfo);
	u1Byte					NDPTxRate;
	pEntry = &(pBeamformingInfo->BeamformeeEntry[Idx]);

	priv = getBeamEntryDev(priv, pEntry);
	if( !priv)
		return FALSE;
 
	if(pEntry->bUsed == FALSE)
	{
		pEntry->bBeamformingInProgress = FALSE;
		return FALSE;
	}
	else
	{
		if(pEntry->bBeamformingInProgress)
			return FALSE;
		pEntry->bBeamformingInProgress = TRUE;			
	
		RA = pEntry->MacAddr;
		
		if(Mode == SOUNDING_SW_HT_TIMER || Mode == SOUNDING_HW_HT_TIMER || Mode == SOUNDING_AUTO_HT_TIMER)
		{	
			if(!(pEntry->BeamformEntryCap & BEAMFORMER_CAP_HT_EXPLICIT))
			{
//				pBeamformingInfo->bBeamformingInProgress = FALSE;
				pEntry->bBeamformingInProgress = FALSE; 
				return FALSE;
			}
		}
		else if(Mode == SOUNDING_SW_VHT_TIMER || Mode == SOUNDING_HW_VHT_TIMER || Mode == SOUNDING_AUTO_VHT_TIMER)
		{
			if(!(pEntry->BeamformEntryCap & BEAMFORMER_CAP_VHT_SU))
			{
//				pBeamformingInfo->bBeamformingInProgress = FALSE;
				pEntry->bBeamformingInProgress = FALSE; 
				return FALSE;
			}
		}
		
		if(pEntry->BeamformEntryState != BEAMFORMING_ENTRY_STATE_INITIALIZED && pEntry->BeamformEntryState != BEAMFORMING_ENTRY_STATE_PROGRESSED)
		{
//			pBeamformingInfo->bBeamformingInProgress = FALSE;
			pEntry->bBeamformingInProgress = FALSE; 
			return FALSE;
		}	
		else
		{
			pEntry->BeamformEntryState = BEAMFORMING_ENTRY_STATE_PROGRESSING; 
			pEntry->bSound = TRUE;
		}
	}

	pEntry->BW = BW;
	pBeamformingInfo->BeamformeeCurIdx = Idx;
	
	Beamforming_SetBeamFormStatus(priv, (pBeamformingInfo->BeamformeeCurIdx));
	Beamforming_NDPARate(priv, Mode, BW, 0);	// soundingpreiod only for debug, use 0 for all case

//  debug
	if(!priv->pshare->rf_ft_var.soundingEnable)
		return TRUE;

#ifdef CONFIG_WLAN_HAL_8192EE
	if ((OPMODE & WIFI_AP_STATE) && (priv->pshare->soundingLock))
		return TRUE;
#endif	
//	
	if(Mode == SOUNDING_SW_HT_TIMER || Mode == SOUNDING_HW_HT_TIMER || Mode == SOUNDING_AUTO_HT_TIMER)
	{
		NDPTxRate = Beamforming_GetHTNDPTxRate(priv, pEntry->CompSteeringNumofBFer);
		ret = SendHTNDPAPacket(priv,RA, BW, NDPTxRate);
		ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, HT NDP Rate = %d\n", __FUNCTION__, NDPTxRate));  
	}
	else
	{
		NDPTxRate = Beamforming_GetVHTNDPTxRate(priv, pEntry->CompSteeringNumofBFer);

#ifdef CONFIG_WLAN_HAL_8814AE		
		if(((pEntry->pSTA->current_tx_rate >=_NSS3_MCS7_RATE_) && (pEntry->pSTA->current_tx_rate <=_NSS3_MCS9_RATE_)) &&
			priv->pshare->rf_ft_var.Nsnding3SS &&(GET_CHIP_VER(priv)== VERSION_8814A) )
		{
			ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, VHT3SS 7,8,9, not sounding!!\n", __FUNCTION__));
		}
		else
#endif

#ifdef CONFIG_RTL_8812_SUPPORT
		if(((pEntry->pSTA->current_tx_rate >=_NSS2_MCS0_RATE_) && (pEntry->pSTA->current_tx_rate <=_NSS2_MCS9_RATE_)) &&
			priv->pshare->rf_ft_var.Nsnding3SS && (GET_CHIP_VER(priv)== VERSION_8812E) )
		{
			ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, VHT2SS 0-9 Not sounding!!\n", __FUNCTION__));
		}
		else
#endif

/*
#ifdef CONFIG_WLAN_HAL_8192EE
		if(((pEntry->pSTA->current_tx_rate >=_MCS8_RATE_) && (pEntry->pSTA->current_tx_rate <=_MCS15_RATE_)) &&
			priv->pshare->rf_ft_var.Nsnding3SS && (GET_CHIP_VER(priv)== VERSION_8192E) )
		{
			ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, HT MCS 8-15 Not sounding!!\n", __FUNCTION__));
		}
		else

#endif
*/
		{
			if(priv->pshare->rf_ft_var.ndpaaid != 0xff)
				ret = SendVHTNDPAPacket(priv,RA, priv->pshare->rf_ft_var.ndpaaid, BW, NDPTxRate);
			else
				ret = SendVHTNDPAPacket(priv,RA, pEntry->AID, BW, NDPTxRate);
		}
		ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, VHT NDP Rate = %d\n", __FUNCTION__, NDPTxRate));  
	}

	if(ret == FALSE)
	{
		ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, Beamforming_RemoveEntry because of failure sending NDPA for addr =\n", __FUNCTION__));  
//		Beamforming_RemoveEntry(priv, RA, &Idx);
		Beamforming_Leave(priv, RA);
//		pBeamformingInfo->bBeamformingInProgress = FALSE;
		pEntry->bBeamformingInProgress = FALSE;
		return FALSE;
	}

	return TRUE;
}


VOID
Beamforming_Notify(
	struct rtl8192cd_priv *priv
	)
{
	u1Byte						Idx=BEAMFORMEE_ENTRY_NUM;
	BEAMFORMING_NOTIFY_STATE	bSounding = BEAMFORMING_NOTIFY_NONE;
	PRT_BEAMFORMING_INFO 		pBeamInfo = &(priv->pshare->BeamformingInfo);
	PRT_BEAMFORMING_TIMER_INFO	pBeamTimerInfo = NULL;	

	bSounding = beamfomring_bSounding(pBeamInfo, &Idx);

	if(Idx<BEAMFORMEE_ENTRY_NUM)
		pBeamTimerInfo = &(pBeamInfo->BeamformingTimerInfo[Idx]);	
	else if(bSounding == BEAMFORMING_NOTIFY_RESET)
		pBeamTimerInfo = &(pBeamInfo->BeamformingTimerInfo[0]);	

	if(pBeamInfo->BeamformState == BEAMFORMING_STATE_END)
	{
		if(bSounding==BEAMFORMING_NOTIFY_ADD)
		{			
			beamforming_StartPeriod(priv, Idx);
			pBeamInfo->BeamformState = BEAMFORMING_STATE_START_1BFee;
		}
	}
	else if(pBeamInfo->BeamformState == BEAMFORMING_STATE_START_1BFee)
	{
		if(bSounding==BEAMFORMING_NOTIFY_ADD)
		{
			beamforming_StartPeriod(priv, Idx);
			pBeamInfo->BeamformState = BEAMFORMING_STATE_START_2BFee;
		}
		else if(bSounding == BEAMFORMING_NOTIFY_DELETE)
		{
			if(pBeamTimerInfo->Mode == SOUNDING_FW_HT_TIMER || pBeamTimerInfo->Mode == SOUNDING_FW_VHT_TIMER)
			{
				beamforming_EndPeriod_FW(priv, Idx);
				beamforming_ClearEntry_FW(priv, TRUE, Idx);
			}
			else
			{
				beamforming_EndPeriod_SW(priv, Idx);
				beamforming_ClearEntry_SW(priv, TRUE, Idx);
			}
			
			pBeamInfo->BeamformState = BEAMFORMING_STATE_END;
		}
		else if(bSounding == BEAMFORMING_NOTIFY_RESET)
		{
			if(pBeamTimerInfo->Mode == SOUNDING_FW_HT_TIMER || pBeamTimerInfo->Mode == SOUNDING_FW_VHT_TIMER)
			{
				beamforming_EndPeriod_FW(priv, Idx);
				beamforming_ClearEntry_FW(priv, FALSE, Idx);
			}
			else
			{
				beamforming_EndPeriod_SW(priv, Idx);
				beamforming_ClearEntry_SW(priv, FALSE, Idx);
			}
			
			pBeamInfo->BeamformState = BEAMFORMING_STATE_END;
		}
	}
	else if(pBeamInfo->BeamformState == BEAMFORMING_STATE_START_2BFee)
	{
		if(bSounding == BEAMFORMING_NOTIFY_ADD)
		{
			ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, should be block\n", __FUNCTION__));  

		}
		else if(bSounding == BEAMFORMING_NOTIFY_DELETE)
		{
			if(pBeamTimerInfo->Mode == SOUNDING_FW_HT_TIMER || pBeamTimerInfo->Mode == SOUNDING_FW_VHT_TIMER)
			{
				beamforming_EndPeriod_FW(priv, Idx);
				beamforming_ClearEntry_FW(priv, TRUE, Idx);
			}
			else
			{
				// For 2->1 entry, we should not cancel SW timer
				beamforming_ClearEntry_SW(priv, TRUE, Idx);
			}
		
			pBeamInfo->BeamformState = BEAMFORMING_STATE_START_1BFee;
		}
		else if(bSounding == BEAMFORMING_NOTIFY_RESET)
		{
			if(pBeamTimerInfo->Mode == SOUNDING_FW_HT_TIMER || pBeamTimerInfo->Mode == SOUNDING_FW_VHT_TIMER)
			{
				beamforming_EndPeriod_FW(priv, Idx);
				beamforming_ClearEntry_FW(priv, FALSE, Idx);
			}
			else
			{
				beamforming_EndPeriod_SW(priv, Idx);
				beamforming_ClearEntry_SW(priv, FALSE, Idx);
			}
			
			pBeamInfo->BeamformState = BEAMFORMING_STATE_END;
		}
	}

}


VOID
Beamforming_AutoTest(
	struct rtl8192cd_priv *priv,
	u1Byte					Idx, 
	PRT_BEAMFORMING_ENTRY	pBeamformEntry
	)
{
	SOUNDING_MODE					Mode;

	BEAMFORMING_CAP				BeamformCap = pBeamformEntry->BeamformEntryCap;
	PRT_BEAMFORMING_INFO 		pBeamInfo = &(priv->pshare->BeamformingInfo);	
	PRT_BEAMFORMING_PERIOD_INFO pBeamPeriodInfo = &(pBeamInfo->BeamformingPeriodInfo);

	if(BeamformCap & BEAMFORMER_CAP_VHT_SU)
		Mode = SOUNDING_SW_VHT_TIMER;
	else if(BeamformCap & BEAMFORMER_CAP_HT_EXPLICIT)
	{
	Mode = SOUNDING_SW_HT_TIMER;		// use sw timer for all IC
	
/*#ifdef CONFIG_WLAN_HAL_8192EE
		if(GET_CHIP_VER(priv)== VERSION_8192E)
			Mode = SOUNDING_SW_HT_TIMER;
#endif
#ifdef CONFIG_RTL_8812_SUPPORT
		if(GET_CHIP_VER(priv)== VERSION_8812E)
			Mode = SOUNDING_HW_HT_TIMER;
#endif
#ifdef CONFIG_WLAN_HAL_8814AE
		if(GET_CHIP_VER(priv)== VERSION_8814A)
			Mode = SOUNDING_HW_HT_TIMER;
#endif*/
	}
	else 
		return;

	pBeamPeriodInfo->Idx = Idx;
	pBeamPeriodInfo->Mode = Mode;
	pBeamPeriodInfo->BW = pBeamformEntry->BW;

	pBeamPeriodInfo->BeamPeriod = priv->pshare->rf_ft_var.soundingPeriod;


}


VOID
Beamforming_End(
	struct rtl8192cd_priv *priv,
	BOOLEAN			Status	
	)
{

	PRT_BEAMFORMING_INFO pBeamformingInfo = &(priv->pshare->BeamformingInfo);
    PRT_BEAMFORMING_ENTRY	pBFeeEntry = &(pBeamformingInfo->BeamformeeEntry[pBeamformingInfo->BeamformeeCurIdx]);

    ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@%s, BeamformEntryState=%d, pBFeeEntry->bUsed=%d\n",
        __FUNCTION__,
        pBFeeEntry->BeamformEntryState,
        pBFeeEntry->bUsed
        ));

    if((pBFeeEntry->BeamformEntryState != BEAMFORMING_ENTRY_STATE_PROGRESSING)||(pBFeeEntry->bUsed==0))
	{
		return;
	}

    // Because in this case 8814A STOP sounding @BeamformingStart_V2 , so NOT apply V-matrix here.
    if(((pBFeeEntry->pSTA->current_tx_rate >=_NSS3_MCS7_RATE_) && (pBFeeEntry->pSTA->current_tx_rate <=_NSS3_MCS9_RATE_)) &&
		priv->pshare->rf_ft_var.Nsnding3SS)
	{
		ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, VHT3SS 7,8,9, do not apply V matrix.\n", __FUNCTION__));
        pBFeeEntry->BeamformEntryState = BEAMFORMING_ENTRY_STATE_INITIALIZED;
		Beamforming_SetBeamFormStatus(priv, (pBeamformingInfo->BeamformeeCurIdx));
	}
    else if(Status == 1)        // Receive CSI successful
	{
        pBFeeEntry->LogStatusFailCnt = 0;
        pBFeeEntry->BeamformEntryState = BEAMFORMING_ENTRY_STATE_PROGRESSED;
		Beamforming_SetBeamFormStatus(priv, (pBeamformingInfo->BeamformeeCurIdx));
	}
    else        // Receive CSI failure
	{
        pBFeeEntry->BeamformEntryState = BEAMFORMING_ENTRY_STATE_INITIALIZED;
        pBFeeEntry->LogStatusFailCnt++;
	}

    pBFeeEntry->bBeamformingInProgress = FALSE;
    ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, pEntry->LogStatusFailCnt : %d\n", __FUNCTION__, pBFeeEntry->LogStatusFailCnt));  

    // Receive CSI failure
    if(pBFeeEntry->LogStatusFailCnt > 50)
	{
        ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@%s, LogStatusFailCnt > 50\n", __FUNCTION__));
        
        pBeamformingInfo->CurDelBFerBFeeEntrySel = BFeeEntry;
        if(Beamforming_DeInitEntry(priv, pBFeeEntry->MacAddr))
			Beamforming_Notify(priv);
	}

}	

int shortenSoundingPeriod(struct rtl8192cd_priv *priv)
{
	PRT_BEAMFORMING_INFO 		pBeamformingInfo = &(priv->pshare->BeamformingInfo);
	PRT_BEAMFORMING_ENTRY		pEntry = &(pBeamformingInfo->BeamformeeEntry[0]);
	struct stat_info 			*pstat;
	struct rtl8192cd_priv 		*vxd_priv;	
	u4Byte idx, j, ret=0;
	pBeamformingInfo->BeamformingPeriodState = 0;     //

	for(idx=0 ; idx<BEAMFORMEE_ENTRY_NUM; idx++)
	{
		pEntry = &(pBeamformingInfo->BeamformeeEntry[idx]);
		if( pEntry->bUsed)  
		{
			pstat = get_stainfo(priv, pEntry->MacAddr);
			if(pstat) 
			{
				if(pstat->tx_avarage > (1<<16))//0.5Mbps
				{
					++ret;
					if(idx == 0)                                                                        //
						pBeamformingInfo->BeamformingPeriodState+=1;        // entry 0 only = 1
					else                                                                                  // entry 1 only = 2
						pBeamformingInfo->BeamformingPeriodState+=2;        // entry 0 and 1 = 3
				}
			}

#ifdef MBSSID
		  if ((OPMODE & WIFI_AP_STATE) && priv->pmib->miscEntry.vap_enable)
		  {
			for (j=0; j<RTL8192CD_NUM_VWLAN; j++)
			{
				if ((priv->pvap_priv[j]->assoc_num > 0) && IS_DRV_OPEN(priv->pvap_priv[j]))
				{
					pstat = get_stainfo(priv->pvap_priv[j], pEntry->MacAddr);
					if(pstat)
					{
						if(pstat->tx_avarage > (1<<16))  // 0.5Mbps
							++ret;
					}
				}
			}
		}
#endif		
#ifdef UNIVERSAL_REPEATER
			vxd_priv = GET_VXD_PRIV(priv);
			if((OPMODE_VXD & WIFI_STATION_STATE) && (vxd_priv->assoc_num > 0) && IS_DRV_OPEN(vxd_priv) 	)
			{		
				pstat = get_stainfo(vxd_priv, pEntry->MacAddr);
				if(pstat)
				{
					if(pstat->tx_avarage >  (1<<16))  // 0.5Mbps
						++ret;
				}
			}
#endif
			
		}
	}
	//panic_printk("BeamformPeriodState = %d\n", pBeamformingInfo->BeamformingPeriodState);
	return ret;
}

u1Byte
getBFeeStaNum(
	struct rtl8192cd_priv *priv
	)
{
	PRT_BEAMFORMING_INFO 		pBeamformingInfo = &(priv->pshare->BeamformingInfo);
	int idx;
	u1Byte BFee_STA_Num = 0;
	for(idx=0 ; idx<BEAMFORMEE_ENTRY_NUM; idx++)
	{
		if(pBeamformingInfo->BeamformeeEntry[idx].bUsed)
			BFee_STA_Num++;
	}
	return BFee_STA_Num;	
}


VOID
Beamforming_TimerCallback(
	struct rtl8192cd_priv *priv
	)
{
	BOOLEAN						ret = FALSE;//, timer_set=FALSE;
	PRT_BEAMFORMING_INFO 		pBeamformingInfo = &(priv->pshare->BeamformingInfo);
	int 							idx = pBeamformingInfo->BeamformeeCurIdx;		
	PRT_BEAMFORMING_ENTRY		pEntry = &(pBeamformingInfo->BeamformeeEntry[idx]);
	PRT_BEAMFORMING_TIMER_INFO	pBeamformingTimerInfo = &(pBeamformingInfo->BeamformingTimerInfo[idx]);	
	u1Byte						BFee_STA_Num = 0;
	u1Byte						index = 0;

	BFee_STA_Num = getBFeeStaNum(priv);
	
	if (!(priv->drv_state & DRV_STATE_OPEN))
		return;

#if 0
	for(idx=0 ; idx<BEAMFORMEE_ENTRY_NUM; idx++)  
	{
#else
	{		

		if(BFee_STA_Num == 2)
		{
			if(pBeamformingInfo->BeamformingPeriodState == 0 || pBeamformingInfo->BeamformingPeriodState == 3)
			{
				if(pBeamformingInfo->BeamformeeEntry[idx^1].bUsed)
					idx ^=1;
			}
			else if(pBeamformingInfo->BeamformingPeriodState == 2)
			{
				idx = 1;
			}
			else
				idx = 0;
		}	
		else
		{  
			if(pBeamformingInfo->BeamformeeEntry[0].bUsed)
				idx = 0;
			else if(pBeamformingInfo->BeamformeeEntry[1].bUsed)
				idx = 1;
		}
		
		pBeamformingInfo->BeamformeeCurIdx = idx;
#endif
		pEntry = &(pBeamformingInfo->BeamformeeEntry[idx]);
		pBeamformingTimerInfo = &(pBeamformingInfo->BeamformingTimerInfo[idx]);
		
		if(pEntry->bBeamformingInProgress)
		{
			Beamforming_End(priv, 0);
		}
		if( pEntry->bUsed) 
		{
			ret = BeamformingStart_V2( priv, idx, pBeamformingTimerInfo->Mode, pEntry->BW);

		}

//		if(ret && !timer_set)
//		if(ret)
		if(pBeamformingInfo->BeamformeeEntry[0].bUsed || pBeamformingInfo->BeamformeeEntry[1].bUsed)
		{		
			if(pBeamformingInfo->BeamformState >= BEAMFORMING_STATE_START_1BFee)
			{
				if(pBeamformingTimerInfo->Mode == SOUNDING_SW_VHT_TIMER || pBeamformingTimerInfo->Mode == SOUNDING_SW_HT_TIMER)  
				{
					if(shortenSoundingPeriod(priv)){
						if(pBeamformingInfo->BeamformingPeriodState == 1 || pBeamformingInfo->BeamformingPeriodState == 2)
						{
							ODM_SetTimer(ODMPTR, &pBeamformingInfo->BeamformingTimer, pBeamformingTimerInfo->BeamPeriod/100);
						}
						else   // pBeamformingInfo->BeamformingPeriodState == 3
						{
							ODM_SetTimer(ODMPTR, &pBeamformingInfo->BeamformingTimer, pBeamformingTimerInfo->BeamPeriod/200);
						}
					}
					else  
					{
						ODM_SetTimer(ODMPTR, &pBeamformingInfo->BeamformingTimer, pBeamformingTimerInfo->BeamPeriod);
					}
				}
				else
				{
					int BeamPeriod = priv->pshare->rf_ft_var.soundingPeriod;

					if(pBeamformingTimerInfo->Mode == SOUNDING_HW_VHT_TIMER || pBeamformingTimerInfo->Mode == SOUNDING_HW_HT_TIMER)
						BeamPeriod *=32;	//HW timer, clock = 32K
	
					if(shortenSoundingPeriod(priv))
					{
						if(pBeamformingInfo->BeamformingPeriodState == 1 || pBeamformingInfo->BeamformingPeriodState == 2) //only one entry is in used
							BeamPeriod /= 100;
						else //two entries are in used
							BeamPeriod /= 200;
					}

					if(pBeamformingTimerInfo->BeamPeriod != BeamPeriod)
					{
						pBeamformingTimerInfo->BeamPeriod = BeamPeriod;
					}
					Beamforming_SetHWTimer(priv, pBeamformingTimerInfo->BeamPeriod);
				}
//				timer_set = 1;
			}
		}	

	
	}

}

VOID Beamforming_SWTimerCallback(unsigned long task_priv)
{
	struct rtl8192cd_priv *priv = (struct rtl8192cd_priv *)task_priv;
	Beamforming_TimerCallback(priv);
//	mod_timer(&priv->txbf_swtimer, jiffies + priv->pshare->rf_ft_var.soundingPeriod);
}

VOID
Beamforming_Init(
	struct rtl8192cd_priv *priv
	)
{
	PRT_BEAMFORMING_INFO pBeamInfo = &(priv->pshare->BeamformingInfo);
	PRT_BEAMFORMING_PERIOD_INFO	pBeamPeriodInfo = &(pBeamInfo->BeamformingPeriodInfo);

	pBeamInfo->BeamformingPeriodState = 0;
	pBeamPeriodInfo->Mode = SOUNDING_STOP_OID_TIMER;

	init_timer(&pBeamInfo->BeamformingTimer);
	pBeamInfo->BeamformingTimer.function = Beamforming_SWTimerCallback;
	pBeamInfo->BeamformingTimer.data = (unsigned long)priv;
}

VOID
Beamforming_Release(
	struct rtl8192cd_priv *priv
	)
{
	PRT_BEAMFORMING_INFO pBeamformingInfo = &(priv->pshare->BeamformingInfo);
	ODM_CancelTimer(ODMPTR, &pBeamformingInfo->BeamformingTimer);
}		



VOID
Beamforming_Enter(
	struct rtl8192cd_priv *priv,
	struct stat_info	*pstat
)
{
	u1Byte	BFerBFeeIdx = 0xff;
	if(Beamforming_InitEntry(priv, pstat, &BFerBFeeIdx))
	{
		Beamforming_SetBeamFormEnter(priv, BFerBFeeIdx);
	}	
}


VOID
Beamforming_Leave(
	struct rtl8192cd_priv *priv,
	pu1Byte			RA
	)
{
	u1Byte		Idx = 0;
	PRT_BEAMFORMING_INFO 	pBeamformingInfo = &(priv->pshare->BeamformingInfo);
	Beamforming_GetBFeeEntryByAddr(priv, RA, &Idx);

	if(RA == NULL)
	{
		BeamformingReset(priv);
		ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, Reset entry\n", __FUNCTION__));  
	}
	else
	{
        pBeamformingInfo->CurDelBFerBFeeEntrySel = BFerBFeeEntry;
		Beamforming_DeInitEntry(priv, RA);
		ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("%s, DeInit entry %d\n", __FUNCTION__, Idx));  
	}

	Beamforming_Notify(priv);

}


VOID
Beamforming_SetTxBFen(
	struct rtl8192cd_priv *priv,
	u1Byte			MacId,
	BOOLEAN			bTxBF
	)
{
	u1Byte					Idx = 0;
//	PRT_BEAMFORMING_INFO 	pBeamformingInfo = &(priv->pshare->BeamformingInfo);
	PRT_BEAMFORMING_ENTRY	pEntry;

	pEntry = Beamforming_GetEntryByMacId(priv, MacId, &Idx);

	if(pEntry == NULL)
		return;
	else
		pEntry->bTxBF = bTxBF;

	Beamforming_Notify(priv);
}

BEAMFORMING_CAP
Beamforming_GetBeamCap(
	IN PRT_BEAMFORMING_INFO 	pBeamInfo
	)
{
	u1Byte					i;
	BOOLEAN 				bSelfBeamformer = FALSE;
	BOOLEAN 				bSelfBeamformee = FALSE;
	RT_BEAMFORMING_ENTRY	BeamformeeEntry;
	RT_BEAMFORMER_ENTRY	BeamformerEntry;
	BEAMFORMING_CAP 		BeamformCap = BEAMFORMING_CAP_NONE;

	/*
	for(i = 0; i < BEAMFORMEE_ENTRY_NUM; i++)
	{
		BeamformEntry = pBeamInfo->BeamformeeEntry[i];

		if(BeamformEntry.bUsed)
		{
			if( (BeamformEntry.BeamformEntryCap & BEAMFORMEE_CAP_VHT_SU) ||
				(BeamformEntry.BeamformEntryCap & BEAMFORMEE_CAP_HT_EXPLICIT))
				bSelfBeamformee = TRUE;
			if( (BeamformEntry.BeamformEntryCap & BEAMFORMER_CAP_VHT_SU) ||
				(BeamformEntry.BeamformEntryCap & BEAMFORMER_CAP_HT_EXPLICIT))
				bSelfBeamformer = TRUE;
		}

		if(bSelfBeamformer && bSelfBeamformee)
			i = BEAMFORMEE_ENTRY_NUM;
	}
	*/

	for(i = 0; i < BEAMFORMEE_ENTRY_NUM; i++)
	{
		BeamformeeEntry = pBeamInfo->BeamformeeEntry[i];

		if(BeamformeeEntry.bUsed)
		{
			bSelfBeamformer = TRUE;
			//panic_printk("[Beamform]%s, BFee entry %d bUsed=TRUE\n", __FUNCTION__, i);  
		}
	}

	for(i = 0; i < BEAMFORMER_ENTRY_NUM; i++)
	{
		BeamformerEntry = pBeamInfo->BeamformerEntry[i];

		if(BeamformerEntry.bUsed)
		{
			bSelfBeamformee = TRUE;
			//panic_printk"[Beamform]%s, BFer entry %d bUsed=TRUE\n", __FUNCTION__, i);  
		}
	}

	if(bSelfBeamformer)
		BeamformCap |= BEAMFORMER_CAP;
	if(bSelfBeamformee)
		BeamformCap |= BEAMFORMEE_CAP;

	return BeamformCap;
}

VOID
Beamforming_GetNDPAFrame(
	struct rtl8192cd_priv *priv,
	pu1Byte 					pNDPAFrame
	)
{
	pu1Byte						TA ;
	u1Byte						Idx, Sequence;
	PRT_BEAMFORMER_ENTRY		pBeamformerEntry = NULL;
    PRT_BEAMFORMING_INFO    pBeamformingInfo = &(priv->pshare->BeamformingInfo);

	if (GET_CHIP_VER(priv) != VERSION_8812E)
		return;
	if(IsCtrlNDPA(pNDPAFrame) == FALSE)
		return;

	TA = GetAddr2Ptr(pNDPAFrame);
	// Remove signaling TA. 
	TA[0] = TA[0] & 0xFE; 

        pBeamformerEntry = Beamforming_GetBFerEntryByAddr(priv, TA, &Idx);

        if(pBeamformerEntry == NULL)
		return;
        else if(!(pBeamformerEntry->BeamformEntryCap & BEAMFORMEE_CAP_VHT_SU))
		return;
        
        // NDPALogSuccess: As long as 8812A receive NDPA and feedback CSI succeed once, clock reset is NO LONGER needed !2015-04-10, Jeffery
        // ClockResetTimes: While BFer entry always doesn't receive our CSI, clock will reset again and again.So ClockResetTimes is limited to 5 times.2015-04-13, Jeffery
        else if( pBeamformerEntry->NDPALogSuccess==1 )
        {
        
            ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@%s ,ClockResetTimes=%d, NDPALogSuccess=%d, clock reset is no longer needed!!\n",
            __FUNCTION__,
            pBeamformerEntry->ClockResetTimes,
            pBeamformerEntry->NDPALogSuccess));
            
            return;
        }
        else if( pBeamformerEntry->ClockResetTimes==3 )
        {
             ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@%s ,ClockResetTimes=%d, DeInit BFer Entry !!\n",
            __FUNCTION__,
            pBeamformerEntry->ClockResetTimes,
            pBeamformerEntry->NDPALogSuccess));
            pBeamformingInfo->CurDelBFerBFeeEntrySel = BFerEntry ;
            Beamforming_DeInitEntry(priv, pBeamformerEntry->MacAddr);
		return;
        }

	Sequence = (pNDPAFrame[16]) >> 2;

        ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@%s Start, Sequence=%d, NDPALogSeq=%d, NDPAPreLogSeq=%d, NDPALogRetryCnt=%d, ClockResetTimes=%d, NDPALogSuccess=%d\n",
        __FUNCTION__,
        Sequence,
        pBeamformerEntry->NDPALogSeq,
        pBeamformerEntry->NDPAPreLogSeq,
        pBeamformerEntry->NDPALogRetryCnt,
        pBeamformerEntry->ClockResetTimes,
        pBeamformerEntry->NDPALogSuccess));

        if ((pBeamformerEntry->NDPALogSeq != 0) && (pBeamformerEntry->NDPAPreLogSeq != 0))
	{
            //2 Success Condition
            if( (pBeamformerEntry->NDPALogSeq!=Sequence)&&(pBeamformerEntry->NDPALogSeq!=pBeamformerEntry->NDPAPreLogSeq) )
	{
                /* break option for clcok reset, 2015-03-30, Jeffery */
                pBeamformerEntry->NDPALogRetryCnt = 0;

                /*As long as 8812A receive NDPA and feedback CSI succeed once, clock reset is no longer needed.*/
                /*That is, NDPALogSuccess is NOT needed to be reset to zero, 2015-04-13, Jeffery*/
                pBeamformerEntry->NDPALogSuccess=1;
	}

            //2 Fail Condition
	else
	{
                
                if (pBeamformerEntry->NDPALogRetryCnt == 5)
                {
                
                    pBeamformerEntry->ClockResetTimes++;
                    pBeamformerEntry->NDPALogRetryCnt = 0;

                    watchdog_kick();
                    ODM_RT_TRACE(ODMPTR, BEAMFORMING_DEBUG, ODM_DBG_LOUD, ("[Beamforming]@%s ,Clock Reset!!! ClockResetTimes=%d\n",
                    __FUNCTION__, 
                    pBeamformerEntry->ClockResetTimes));  

#ifdef CONFIG_RTL_8812_SUPPORT	
			_Beamforming_CLK(priv);
#endif		
	}
                else
                    pBeamformerEntry->NDPALogRetryCnt++;
            }
        }

        pBeamformerEntry->NDPAPreLogSeq = pBeamformerEntry->NDPALogSeq;
        pBeamformerEntry->NDPALogSeq = Sequence;

}

#endif


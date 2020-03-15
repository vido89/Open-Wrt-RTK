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

#ifndef __HAL_PHY_RF_8821B_H__
#define __HAL_PHY_RF_8821B_H__

/*--------------------------Define Parameters-------------------------------*/
#define	IQK_DELAY_TIME_8821B		10		//ms
#define	index_mapping_NUM_8821B	15
#define AVG_THERMAL_NUM_8821B	4
#define RF_T_METER_8821B 		0x42


void ConfigureTxpowerTrack_8821B(
	PTXPWRTRACK_CFG	pConfig
	);

void DoIQK_8821B(
	PVOID		pDM_VOID,
	u1Byte 		DeltaThermalIndex,
	u1Byte		ThermalValue,	
	u1Byte 		Threshold
	);

VOID
ODM_TxPwrTrackSetPwr8821B(
	PDM_ODM_T			pDM_Odm,
	PWRTRACK_METHOD 	Method,
	u1Byte 				RFPath,
	u1Byte 				ChannelMappedIndex
	);

VOID	                                                 
PHY_DPCalibrate_8821B(                                   
	IN 	PDM_ODM_T	pDM_Odm                             
	);


VOID PHY_SetRFPathSwitch_8821B(
#if (DM_ODM_SUPPORT_TYPE & ODM_AP)
	IN PDM_ODM_T		pDM_Odm,
#else
	IN	PADAPTER	pAdapter,
#endif
	IN	BOOLEAN		bMain
	);

BOOLEAN PHY_QueryRFPathSwitch_8821B(	
	IN	PADAPTER	pAdapter
	);


//1 7.	IQK

void	
PHY_IQCalibrate_8821B(	
	IN	PADAPTER	pAdapter,	
	IN	BOOLEAN 	bReCovery
);

VOID
PHY_LCCalibrate_8821B(
	IN PDM_ODM_T		pDM_Odm
);

VOID
GetDeltaSwingTable_8821B(
	IN 	PDM_ODM_T			pDM_Odm,
	OUT pu1Byte 			*TemperatureUP_A,
	OUT pu1Byte 			*TemperatureDOWN_A,
	OUT pu1Byte 			*TemperatureUP_B,
	OUT pu1Byte 			*TemperatureDOWN_B	
);
#endif	// #ifndef __HAL_PHY_RF_8821B_H__								


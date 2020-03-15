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
#if (RTL8822B_SUPPORT == 1)
#ifndef	__ODM_RTL8822B_H__
#define __ODM_RTL8822B_H__

BOOLEAN
phydm_write_txagc_1byte_8822b(
	IN	PDM_ODM_T				pDM_Odm,
	IN	u4Byte					PowerIndex,
	IN	ODM_RF_RADIO_PATH_E		Path,	
	IN	u1Byte					HwRate
	);

BOOLEAN
phydm_rfe_8822b(
	IN	PDM_ODM_T				pDM_Odm,
	IN	u1Byte					channel
	);

VOID
phydm_CcaParByBw_8822b(
	IN	PDM_ODM_T				pDM_Odm,
	IN	ODM_BW_E				bandwidth
	);

VOID
phydm_CcaParByRxPath_8822b(
	IN	PDM_ODM_T				pDM_Odm
	);


#endif	/* #define __ODM_RTL8822B_H__ */
#endif


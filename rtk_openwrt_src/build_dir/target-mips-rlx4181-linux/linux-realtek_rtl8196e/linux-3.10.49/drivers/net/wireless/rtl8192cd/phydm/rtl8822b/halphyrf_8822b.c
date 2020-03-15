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

#if (RTL8822B_SUPPORT == 1)

VOID PHY_SetRFPathSwitch_8822B(
#if (DM_ODM_SUPPORT_TYPE & ODM_AP)
	IN PDM_ODM_T		pDM_Odm,
#else
	IN	PADAPTER	pAdapter,
#endif
	IN	BOOLEAN		bMain
	)
{
}

BOOLEAN 
phy_QueryRFPathSwitch_8822B(
	IN	PADAPTER	pAdapter
	)
{
	return TRUE;
}


BOOLEAN PHY_QueryRFPathSwitch_8822B(	
	IN	PADAPTER	pAdapter
	)
{

#if DISABLE_BB_RF
	return TRUE;
#endif

	return phy_QueryRFPathSwitch_8822B(pAdapter);
}


#endif	/* (RTL8822B_SUPPORT == 0)*/

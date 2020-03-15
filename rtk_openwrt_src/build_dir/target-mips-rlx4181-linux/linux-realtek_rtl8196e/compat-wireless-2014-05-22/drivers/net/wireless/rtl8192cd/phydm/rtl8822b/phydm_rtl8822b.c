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

/*============================================================
// include files
============================================================*/

#include "mp_precomp.h"
#include "../phydm_precomp.h"

#if (RTL8822B_SUPPORT == 1)

BOOLEAN
phydm_write_txagc_1byte_8822b(
	IN	PDM_ODM_T				pDM_Odm,
	IN	u4Byte					PowerIndex,
	IN	ODM_RF_RADIO_PATH_E		Path,	
	IN	u1Byte					HwRate
	)
{
	u4Byte	offset_txagc[2] = {0x1d00, 0x1d80};
	u1Byte	rate_idx = (HwRate & 0xfc), i;
	u1Byte	rate_offset = (HwRate & 0x3);
	u4Byte	rate_mask = (0xff << (rate_offset << 3));
	u4Byte	txagc_content = 0x0;

	/* For debug command only!!!! */

	/* Error handling  */
	if ((Path > ODM_RF_PATH_B) || (HwRate > 0x53)) {
		ODM_RT_TRACE(pDM_Odm, ODM_PHY_CONFIG, ODM_DBG_TRACE, ("phydm_write_txagc_1byte_8822b(): unsupported path (%d)\n", Path));
		return FALSE;
	}

#if 1
	/* For HW limitation, We can't write TXAGC once a byte. */
	for (i = 0; i < 4; i++) {
		if (i != rate_offset)
			txagc_content = txagc_content|(config_phydm_read_txagc_8822b(pDM_Odm, Path, rate_idx + i) << (i << 3));
		else
			txagc_content = txagc_content|((PowerIndex & 0x3f) << (i << 3));
	}
	ODM_SetBBReg(pDM_Odm, (offset_txagc[Path] + rate_idx), bMaskDWord, txagc_content);
#else
	ODM_Write1Byte(pDM_Odm, (offset_txagc[Path] + HwRate), (PowerIndex & 0x3f));
#endif

	ODM_RT_TRACE(pDM_Odm, ODM_PHY_CONFIG, ODM_DBG_TRACE, ("phydm_write_txagc_1byte_8822b(): Path-%d Rate index 0x%x (0x%x) = 0x%x\n", 
		Path, HwRate, (offset_txagc[Path] + HwRate), PowerIndex));
	return TRUE;
}

BOOLEAN
phydm_rfe_8822b(
	IN	PDM_ODM_T				pDM_Odm,
	IN	u1Byte					channel
	)
{
	/* Efuse is not wrote now */
	/* Need to check RFE type finally */
	if (channel <= 14) {
		/* if (pDM_Odm->RFEType == 1) */
		{
			ODM_SetBBReg(pDM_Odm, 0x64, BIT29|BIT28, 0x3);
			ODM_SetBBReg(pDM_Odm, 0x4c, BIT26|BIT25, 0x0);
			ODM_SetBBReg(pDM_Odm, 0x40, BIT2, 0x1);
			ODM_SetBBReg(pDM_Odm, 0x1990, 0xfff, 0xc30);
			ODM_SetBBReg(pDM_Odm, 0x974, 0xfff, 0xfff);
			ODM_SetBBReg(pDM_Odm, 0xcb0, bMaskDWord, 0x77700070);
			ODM_SetBBReg(pDM_Odm, 0xeb0, bMaskDWord, 0x77700070);
			ODM_SetBBReg(pDM_Odm, 0xcb4, bMaskLWord, 0x0077);
			ODM_SetBBReg(pDM_Odm, 0xeb4, bMaskLWord, 0x0077);
			ODM_SetBBReg(pDM_Odm, 0xcbc, 0xfff, 0x404);
			ODM_SetBBReg(pDM_Odm, 0xebc, 0xfff, 0x404);
		}
	} else if (channel > 35) {
		/* if (pDM_Odm->RFEType == 1) */
		{
			ODM_SetBBReg(pDM_Odm, 0x64, BIT29|BIT28, 0x3);
			ODM_SetBBReg(pDM_Odm, 0x4c, BIT26|BIT25, 0x0);
			ODM_SetBBReg(pDM_Odm, 0x40, BIT2, 0x1);
			ODM_SetBBReg(pDM_Odm, 0x1990, 0xfff, 0xc30);
			ODM_SetBBReg(pDM_Odm, 0x974, 0xfff, 0xfff);
			ODM_SetBBReg(pDM_Odm, 0xcb0, bMaskDWord, 0x77171117);
			ODM_SetBBReg(pDM_Odm, 0xeb0, bMaskDWord, 0x77171117);
			ODM_SetBBReg(pDM_Odm, 0xcb4, bMaskLWord, 0x1177);
			ODM_SetBBReg(pDM_Odm, 0xeb4, bMaskLWord, 0x1177);
			ODM_SetBBReg(pDM_Odm, 0xcbc, 0xfff, 0x404);
			ODM_SetBBReg(pDM_Odm, 0xebc, 0xfff, 0x404);
		}
	} else
		return FALSE;

	return TRUE;
}

VOID
phydm_CcaParByBw_8822b(
	IN	PDM_ODM_T				pDM_Odm,
	IN	ODM_BW_E				bandwidth
	)
{
	u4Byte		reg82c;
	
	reg82c = ODM_GetBBReg(pDM_Odm, 0x82c, bMaskDWord);
	
	if (bandwidth == ODM_BW20M) {
		/* 82c[15:12] = 4 */
		/* 82c[27:24] = 6 */
		
		reg82c &= (~(0x0f00f000));
		reg82c |= ((0x4) << 12);
		reg82c |= ((0x6) << 24);
	} else if (bandwidth == ODM_BW40M) {
		/* 82c[19:16] = 9 */
		/* 82c[27:24] = 6 */
	
		reg82c &= (~(0x0f0f0000));
		reg82c |= ((0x9) << 16);
		reg82c |= ((0x6) << 24);
	} else if (bandwidth == ODM_BW80M) {
		/* 82c[15:12] 7 */
		/* 82c[19:16] b */
		/* 82c[23:20] d */
		/* 82c[27:24] 3 */
	
		reg82c &= (~(0x0ffff000));
		reg82c |= ((0xdb7) << 12);
		reg82c |= ((0x3) << 24);
	}

	ODM_SetBBReg(pDM_Odm, 0x82c, bMaskDWord, reg82c);
}

VOID
phydm_CcaParByRxPath_8822b(
	IN	PDM_ODM_T				pDM_Odm
	)
{
	if ((pDM_Odm->RXAntStatus == ODM_RF_A) || (pDM_Odm->RXAntStatus == ODM_RF_B)) {
		/* Preamble parameters for ch-D */
		/*ODM_SetBBReg(pDM_Odm, 0x834, 0x70000, 0x4);*/

		/* 838[7:4] = 8 */
		/* 838[11:8] = 7 */
		/* 838[15:12] = 6 */
		/* 838[19:16] = 7 */
		/* 838[23:20] = 7 */
		/* 838[27:24] = 7 */
		ODM_SetBBReg(pDM_Odm, 0x838, 0x0ffffff0, 0x777678);
	} else {
		/* Preamble parameters for ch-D */
		/*ODM_SetBBReg(pDM_Odm, 0x834, 0x70000, 0x6);*/

		/* 838[7:4] = 3 */
		/* 838[11:8] = 3 */
		/* 838[15:12] = 6 */
		/* 838[19:16] = 6 */
		/* 838[23:20] = 7 */
		/* 838[27:24] = 7 */
		ODM_SetBBReg(pDM_Odm, 0x838, 0x0ffffff0, 0x776633);
	}

}


#endif	/* RTL8822B_SUPPORT == 1 */


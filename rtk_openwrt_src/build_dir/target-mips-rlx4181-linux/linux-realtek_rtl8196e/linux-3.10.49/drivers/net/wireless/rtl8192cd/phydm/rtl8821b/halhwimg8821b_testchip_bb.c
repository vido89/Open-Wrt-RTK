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
*                           AGC_TAB.TXT
******************************************************************************/

u4Byte Array_TC_8821B_AGC_TAB[] = { 
		0x81C, 0xFE000001,
		0x81C, 0xFD020001,
		0x81C, 0xFC040001,
		0x81C, 0xFB060001,
		0x81C, 0xFA080001,
		0x81C, 0xF90A0001,
		0x81C, 0xF80C0001,
		0x81C, 0xF70E0001,
		0x81C, 0xF6100001,
		0x81C, 0xF5120001,
		0x81C, 0xF4140001,
		0x81C, 0xF3160001,
		0x81C, 0xF2180001,
		0x81C, 0xF11A0001,
		0x81C, 0xF01C0001,
		0x81C, 0xEF1E0001,
		0x81C, 0xEE200001,
		0x81C, 0xED220001,
		0x81C, 0xEC240001,
		0x81C, 0xEB260001,
		0x81C, 0xEA280001,
		0x81C, 0xE92A0001,
		0x81C, 0xE82C0001,
		0x81C, 0xE72E0001,
		0x81C, 0xE6300001,
		0x81C, 0xE5320001,
		0x81C, 0xE4340001,
		0x81C, 0xE3360001,
		0x81C, 0xE2380001,
		0x81C, 0xCB3A0001,
		0x81C, 0xCA3C0001,
		0x81C, 0xC93E0001,
		0x81C, 0xC8400001,
		0x81C, 0xC7420001,
		0x81C, 0xC6440001,
		0x81C, 0xC5460001,
		0x81C, 0xC4480001,
		0x81C, 0xC34A0001,
		0x81C, 0xC24C0001,
		0x81C, 0xA74E0001,
		0x81C, 0xA6500001,
		0x81C, 0xA5520001,
		0x81C, 0xA4540001,
		0x81C, 0xA3560001,
		0x81C, 0xA2580001,
		0x81C, 0x885A0001,
		0x81C, 0x875C0001,
		0x81C, 0x865E0001,
		0x81C, 0x85600001,
		0x81C, 0x84620001,
		0x81C, 0x83640001,
		0x81C, 0x82660001,
		0x81C, 0x48680001,
		0x81C, 0x476A0001,
		0x81C, 0x466C0001,
		0x81C, 0x456E0001,
		0x81C, 0x44700001,
		0x81C, 0x43720001,
		0x81C, 0x42740001,
		0x81C, 0x41760001,
		0x81C, 0x41780001,
		0x81C, 0x417A0001,
		0x81C, 0x417C0001,
		0x81C, 0x417E0001,
		0x81C, 0xFD000101,
		0x81C, 0xFC020101,
		0x81C, 0xFB040101,
		0x81C, 0xFA060101,
		0x81C, 0xF9080101,
		0x81C, 0xF80A0101,
		0x81C, 0xF70C0101,
		0x81C, 0xF60E0101,
		0x81C, 0xF5100101,
		0x81C, 0xF4120101,
		0x81C, 0xF3140101,
		0x81C, 0xF2160101,
		0x81C, 0xF1180101,
		0x81C, 0xF01A0101,
		0x81C, 0xEF1C0101,
		0x81C, 0xEE1E0101,
		0x81C, 0xED200101,
		0x81C, 0xEC220101,
		0x81C, 0xEB240101,
		0x81C, 0xEA260101,
		0x81C, 0xE9280101,
		0x81C, 0xE82A0101,
		0x81C, 0xE72C0101,
		0x81C, 0xE62E0101,
		0x81C, 0xE5300101,
		0x81C, 0xE4320101,
		0x81C, 0xE3340101,
		0x81C, 0xE2360101,
		0x81C, 0xC6380101,
		0x81C, 0xC53A0101,
		0x81C, 0xC43C0101,
		0x81C, 0xC33E0101,
		0x81C, 0xC2400101,
		0x81C, 0x88420101,
		0x81C, 0x87440101,
		0x81C, 0x86460101,
		0x81C, 0x85480101,
		0x81C, 0x844A0101,
		0x81C, 0x834C0101,
		0x81C, 0x824E0101,
		0x81C, 0x65500101,
		0x81C, 0x64520101,
		0x81C, 0x63540101,
		0x81C, 0x62560101,
		0x81C, 0x44580101,
		0x81C, 0x435A0101,
		0x81C, 0x425C0101,
		0x81C, 0x075E0101,
		0x81C, 0x06600101,
		0x81C, 0x05620101,
		0x81C, 0x04640101,
		0x81C, 0x03660101,
		0x81C, 0x02680101,
		0x81C, 0x016A0101,
		0x81C, 0x016C0101,
		0x81C, 0x016E0101,
		0x81C, 0x01700101,
		0x81C, 0x01720101,
		0x81C, 0x01740101,
		0x81C, 0x01760101,
		0x81C, 0x01780101,
		0x81C, 0x017A0101,
		0x81C, 0x017C0101,
		0x81C, 0x017E0101,
		0xC50, 0x00000022,
		0xC50, 0x00000020,

};

void
ODM_ReadAndConfig_TC_8821B_AGC_TAB(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
    #define READ_NEXT_PAIR(v1, v2, i) do { if (i+2 >= ArrayLen) break; i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)
    #define COND_ELSE  2
    #define COND_ENDIF 3
    u4Byte     i         = 0;
    u4Byte     ArrayLen    = sizeof(Array_TC_8821B_AGC_TAB)/sizeof(u4Byte);
    pu4Byte    Array       = Array_TC_8821B_AGC_TAB;
	
    ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD, ("===> ODM_ReadAndConfig_TC_8821B_AGC_TAB\n"));

    for (i = 0; i < ArrayLen; i += 2 )
    {
        u4Byte v1 = Array[i];
        u4Byte v2 = Array[i+1];
    
        // This (offset, data) pair doesn't care the condition.
        if ( v1 < 0x40000000 )
        {
           odm_ConfigBB_AGC_8821B(pDM_Odm, v1, bMaskDWord, v2);
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
                    odm_ConfigBB_AGC_8821B(pDM_Odm, v1, bMaskDWord, v2);
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
ODM_GetVersion_TC_8821B_AGC_TAB(
)
{
	   return 14;
}

/******************************************************************************
*                           PHY_REG.TXT
******************************************************************************/

u4Byte Array_TC_8821B_PHY_REG[] = { 
		0x800, 0x9020D010,
		0x804, 0x080112E0,
		0x808, 0x0E028211,
		0x80C, 0x00000011,
		0x810, 0x20101263,
		0x814, 0x020C3D10,
		0x818, 0x03A00385,
		0x820, 0x00000000,
		0x824, 0x00030FE0,
		0x828, 0x00000000,
		0x82C, 0x58757178,
		0x830, 0xBB9CEA0E,
		0x834, 0x0400C486,
		0x838, 0x87AA4330,
		0x83C, 0x47974779,
		0x840, 0x037750E0,
		0x844, 0x45BCFCDE,
		0x848, 0x5CD07F8B,
		0x84C, 0x6CFDFFB5,
		0x850, 0x28876706,
		0x854, 0x00015204,
		0x858, 0x4060C000,
		0x85C, 0x74210368,
		0x860, 0x6929C321,
		0x864, 0x79727432,
		0x868, 0x8CA7A314,
		0x86C, 0x438C2878,
		0x870, 0x44444444,
		0x874, 0x31612C2E,
		0x878, 0x00003152,
		0x87C, 0x000FC000,
		0x8A0, 0x00000013,
		0x8A4, 0x7F7F7F7F,
		0x8A8, 0xA202033E,
		0x8AC, 0x87F87E04,
		0x8B0, 0x00000600,
		0x8B4, 0x000FC0C0,
		0x8B8, 0xEC0057FF,
		0x8BC, 0x0CA520C3,
		0x8C0, 0x3FF00020,
		0x8C4, 0x04C00000,
		0x8C8, 0x00024969,
		0x8CC, 0x08248492,
		0x8D0, 0x0000B800,
		0x8D4, 0x940008A0,
		0x8D8, 0x290B5612,
		0x8DC, 0x00000000,
		0x8E0, 0x32316400,
		0x8E4, 0x4A092925,
		0x8E8, 0xFFFFC42C,
		0x8EC, 0x99999999,
		0x8F0, 0x00009999,
		0x8F4, 0x00F80FA1,
		0x8F8, 0x400082C0,
		0x8FC, 0x00000000,
		0x8B4, 0x000FC080,
		0x900, 0x00000700,
		0x90C, 0x00000000,
		0x910, 0x0000FC00,
		0x914, 0x00000404,
		0x918, 0x1C1028C0,
		0x91C, 0x64B11A1C,
		0x920, 0xE0767233,
		0x924, 0x055AA500,
		0x928, 0x4A0000E4,
		0x92C, 0xFFFE0000,
		0x930, 0xFFFFFFFE,
		0x934, 0x001FFFFF,
		0x938, 0x00008400,
		0x93C, 0x001C0642,
		0x940, 0x02470430,
		0x950, 0x02010080,
		0x954, 0x07FD0080,
		0x960, 0x00000000,
		0x964, 0x00000000,
		0x968, 0x00000000,
		0x96C, 0x00000000,
		0x970, 0x801FFFFF,
		0x978, 0x00000000,
		0x97C, 0x00000000,
		0x980, 0x00000000,
		0x984, 0x00000000,
		0x988, 0x00000000,
		0x990, 0x27100000,
		0x994, 0xFFFF0100,
		0x998, 0xFFFFFF5C,
		0x99C, 0xFFFFFFFF,
		0x9A0, 0x000000FF,
		0x9A4, 0x00080080,
		0x9A8, 0x00000000,
		0x9AC, 0x00000000,
		0x9B0, 0x81081008,
		0x9B4, 0x00000000,
		0x9B8, 0x01081008,
		0x9BC, 0x01081008,
		0x9D0, 0x00000000,
		0x9D4, 0x00000000,
		0x9D8, 0x00000000,
		0x9DC, 0x00000000,
		0x9E4, 0x00000002,
		0x9E8, 0x000002D5,
		0xB00, 0xE3100000,
		0xB04, 0x0000B000,
		0xB5C, 0x41CFFFFF,
		0xC00, 0x00000007,
		0xC04, 0x00042020,
		0xC08, 0x80410231,
		0xC0C, 0x00000000,
		0xC10, 0x00000100,
		0xC14, 0x01000000,
		0xC1C, 0x40000043,
		0xC20, 0x12121212,
		0xC24, 0x12121212,
		0xC28, 0x12121212,
		0xC2C, 0x12121212,
		0xC30, 0x12121212,
		0xC34, 0x12121212,
		0xC38, 0x12121212,
		0xC3C, 0x12121212,
		0xC40, 0x12121212,
		0xC44, 0x12121212,
		0xC48, 0x12121212,
		0xC4C, 0x12121212,
		0xC50, 0x00000020,
		0xC54, 0x00000000,
		0xC58, 0xD8001402,
		0xC5C, 0x00000120,
		0xC60, 0x34347473,
		0xC64, 0x07003333,
		0xC68, 0x00418041,
		0xC6C, 0x00414041,
		0xC70, 0x80414041,
		0xC74, 0x80414041,
		0xC78, 0x80418041,
		0xC7C, 0x00418041,
		0xC80, 0x00410041,
		0xC84, 0x00410041,
		0xC94, 0x010000DC,
		0xC98, 0x00088000,
		0xCA0, 0x00002929,
		0xCA4, 0x08040201,
		0xCA8, 0x80402010,
		0xCAC, 0x00000000,
		0xCB0, 0x54775477,
		0xCB4, 0x54775477,
		0xCB8, 0x00500000,
		0xCBC, 0x07700000,
		0xCC0, 0x00000010,
		0xCC8, 0x00000010,
		0xCD8, 0x12121212,
		0xCDC, 0x12121212,
		0xCE0, 0x12121212,
		0xCE4, 0x12121212,
		0xCE8, 0x12121212,
		0x198C, 0x00000007,
		0x1990, 0xFFAA5500,
		0x1994, 0x00000077,
		0x19D4, 0x88888888,
		0x19D8, 0x00000888,
		0xA00, 0x00D047C8,
		0xA04, 0x81FF800C,
		0xA08, 0x8C838300,
		0xA0C, 0x2E7F000F,
		0xA10, 0x9500BB78,
		0xA14, 0x11145028,
		0xA18, 0x00881117,
		0xA1C, 0x89140F00,
		0xA20, 0x1A1B0000,
		0xA24, 0x090E1317,
		0xA28, 0x00000204,
		0xA2C, 0x00900000,
		0xA70, 0x101FFF00,
		0xA74, 0x00000008,
		0xA78, 0x00000900,
		0xA7C, 0x225B0606,
		0xA80, 0x218075A1,
		0xA84, 0x801F8C00,

};

void
ODM_ReadAndConfig_TC_8821B_PHY_REG(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
    #define READ_NEXT_PAIR(v1, v2, i) do { if (i+2 >= ArrayLen) break; i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)
    #define COND_ELSE  2
    #define COND_ENDIF 3
    u4Byte     i         = 0;
    u4Byte     ArrayLen    = sizeof(Array_TC_8821B_PHY_REG)/sizeof(u4Byte);
    pu4Byte    Array       = Array_TC_8821B_PHY_REG;
	
    ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD, ("===> ODM_ReadAndConfig_TC_8821B_PHY_REG\n"));

    for (i = 0; i < ArrayLen; i += 2 )
    {
        u4Byte v1 = Array[i];
        u4Byte v2 = Array[i+1];
    
        // This (offset, data) pair doesn't care the condition.
        if ( v1 < 0x40000000 )
        {
           odm_ConfigBB_PHY_8821B(pDM_Odm, v1, bMaskDWord, v2);
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
                    odm_ConfigBB_PHY_8821B(pDM_Odm, v1, bMaskDWord, v2);
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
ODM_GetVersion_TC_8821B_PHY_REG(
)
{
	   return 14;
}

/******************************************************************************
*                           PHY_REG_MP.TXT
******************************************************************************/

u4Byte Array_TC_8821B_PHY_REG_MP[] = { 
		0xE00, 0x00000000,

};

void
ODM_ReadAndConfig_TC_8821B_PHY_REG_MP(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
    #define READ_NEXT_PAIR(v1, v2, i) do { if (i+2 >= ArrayLen) break; i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)
    #define COND_ELSE  2
    #define COND_ENDIF 3
    u4Byte     i         = 0;
    u4Byte     ArrayLen    = sizeof(Array_TC_8821B_PHY_REG_MP)/sizeof(u4Byte);
    pu4Byte    Array       = Array_TC_8821B_PHY_REG_MP;
	
    ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD, ("===> ODM_ReadAndConfig_TC_8821B_PHY_REG_MP\n"));

    for (i = 0; i < ArrayLen; i += 2 )
    {
        u4Byte v1 = Array[i];
        u4Byte v2 = Array[i+1];
    
        // This (offset, data) pair doesn't care the condition.
        if ( v1 < 0x40000000 )
        {
           odm_ConfigBB_PHY_8821B(pDM_Odm, v1, bMaskDWord, v2);
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
                    odm_ConfigBB_PHY_8821B(pDM_Odm, v1, bMaskDWord, v2);
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
ODM_GetVersion_TC_8821B_PHY_REG_MP(
)
{
	   return 14;
}

/******************************************************************************
*                           PHY_REG_PG.TXT
******************************************************************************/

u4Byte Array_TC_8821B_PHY_REG_PG[] = { 
	0, 0, 0, 0x00000c20, 0xffffffff, 0x32343638,
	0, 0, 0, 0x00000c24, 0xffffffff, 0x36363838,
	0, 0, 0, 0x00000c28, 0xffffffff, 0x28303234,
	0, 0, 0, 0x00000c2c, 0xffffffff, 0x34363838,
	0, 0, 0, 0x00000c30, 0xffffffff, 0x26283032,
	0, 0, 0, 0x00000c3c, 0xffffffff, 0x32343636,
	0, 0, 0, 0x00000c40, 0xffffffff, 0x24262830,
	0, 0, 0, 0x00000c44, 0x0000ffff, 0x00002022,
	1, 0, 0, 0x00000c24, 0xffffffff, 0x34343636,
	1, 0, 0, 0x00000c28, 0xffffffff, 0x26283032,
	1, 0, 0, 0x00000c2c, 0xffffffff, 0x32343636,
	1, 0, 0, 0x00000c30, 0xffffffff, 0x24262830,
	1, 0, 0, 0x00000c3c, 0xffffffff, 0x32343636,
	1, 0, 0, 0x00000c40, 0xffffffff, 0x24262830,
	1, 0, 0, 0x00000c44, 0x0000ffff, 0x00002022
};

void
ODM_ReadAndConfig_TC_8821B_PHY_REG_PG(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	u4Byte     hex = 0;
	u4Byte     i           = 0;
	u2Byte     count       = 0;
	pu4Byte    ptr_array   = NULL;
	u1Byte     platform    = pDM_Odm->SupportPlatform;
	u1Byte     _interface   = pDM_Odm->SupportInterface;
	u1Byte     board       = pDM_Odm->BoardType;  
	u4Byte     ArrayLen    = sizeof(Array_TC_8821B_PHY_REG_PG)/sizeof(u4Byte);
	pu4Byte    Array       = Array_TC_8821B_PHY_REG_PG;

	pDM_Odm->PhyRegPgVersion = 1;
	pDM_Odm->PhyRegPgValueType = PHY_REG_PG_EXACT_VALUE;
	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	for (i = 0; i < ArrayLen; i += 6 )
	{
	    u4Byte v1 = Array[i];
	    u4Byte v2 = Array[i+1];
	    u4Byte v3 = Array[i+2];
	    u4Byte v4 = Array[i+3];
	    u4Byte v5 = Array[i+4];
	    u4Byte v6 = Array[i+5];

	    // this line is a line of pure_body
		 odm_ConfigBB_PHY_REG_PG_8821B(pDM_Odm, v1, v2, v3, v4, v5, v6);
	}
}



#endif // end of HWIMG_SUPPORT


/* THIS IS A MACHINE-GENERATED FILE. DO NOT EDIT ! */

#if HAVE_CONFIG_H
#include <config.h>
#endif

/* (optional) user includes go here */

#include "uni.h"
#include "atmsap.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include "op.h"
#include "qd.out.h"
#include "qlib.h"



static void q_put(unsigned char *table,int pos,int size,unsigned long value);

static unsigned char q_initial[Q_DATA_BYTES];

/*
 * Initialization of constant data. Could also do this in
 * the translator and output the resulting byte stream.
 */

static void q_init_global(void)
{
    memset(q_initial,0,sizeof(q_initial));
    q_put(q_initial,0,8,Q2931_PROTO_DSC); /* _pdsc */
    q_put(q_initial,8,8,3); /* _cr_len */
    q_put(q_initial,55,1,1); /* _ext */
    q_put(q_initial,52,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,48,2,0); /* _action_ind */
    q_put(q_initial,72,8,ATM_IE_AAL); /* _ie_id */
    q_put(q_initial,87,1,1); /* _ext */
    q_put(q_initial,85,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,84,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,80,3,0); /* _action_ind */
    q_put(q_initial,112,8,ATM_AALP_FW_MAX_SDU); /* _id */
    q_put(q_initial,136,8,ATM_AALP_BW_MAX_SDU); /* _id */
    q_put(q_initial,160,8,ATM_AALP_AAL_MODE); /* _id */
    q_put(q_initial,176,8,ATM_AALP_SSCS); /* _id */
    q_put(q_initial,192,8,ATM_IE_TD); /* _ie_id */
    q_put(q_initial,207,1,1); /* _ext */
    q_put(q_initial,205,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,204,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,200,3,0); /* _action_ind */
    q_put(q_initial,224,8,ATM_TD_FW_PCR_0); /* _id */
    q_put(q_initial,256,8,ATM_TD_BW_PCR_0); /* _id */
    q_put(q_initial,288,8,ATM_TD_FW_PCR_01); /* _id */
    q_put(q_initial,320,8,ATM_TD_BW_PCR_01); /* _id */
    q_put(q_initial,352,8,ATM_TD_FW_SCR_0); /* _id */
    q_put(q_initial,384,8,ATM_TD_BW_SCR_0); /* _id */
    q_put(q_initial,416,8,ATM_TD_FW_SCR_01); /* _id */
    q_put(q_initial,448,8,ATM_TD_BW_SCR_01); /* _id */
    q_put(q_initial,480,8,ATM_TD_FW_MBS_0); /* _id */
    q_put(q_initial,512,8,ATM_TD_BW_MBS_0); /* _id */
    q_put(q_initial,544,8,ATM_TD_FW_MBS_01); /* _id */
    q_put(q_initial,576,8,ATM_TD_BW_MBS_01); /* _id */
    q_put(q_initial,608,8,ATM_TD_BEST_EFFORT); /* _id */
    q_put(q_initial,616,8,ATM_TD_TM_OPT); /* _id */
    q_put(q_initial,631,1,ATM_FD_NO); /* fw_fdisc */
    q_put(q_initial,630,1,ATM_FD_NO); /* bw_fdisc */
    q_put(q_initial,625,1,ATM_TAG_NO); /* bw_tag */
    q_put(q_initial,624,1,ATM_TAG_NO); /* fw_tag */
    q_put(q_initial,632,8,ATM_IE_BBCAP); /* _ie_id */
    q_put(q_initial,647,1,1); /* _ext */
    q_put(q_initial,645,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,644,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,640,3,0); /* _action_ind */
    q_put(q_initial,671,1,0); /* _ext */
    q_put(q_initial,679,1,1); /* _ext */
    q_put(q_initial,687,1,1); /* _ext */
    q_put(q_initial,695,1,1); /* _ext */
    q_put(q_initial,693,2,ATM_STC_NO); /* susc_clip */
    q_put(q_initial,688,2,ATM_UPCC_P2P); /* upcc */
    q_put(q_initial,696,8,ATM_IE_BHLI); /* _ie_id */
    q_put(q_initial,711,1,1); /* _ext */
    q_put(q_initial,709,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,708,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,704,3,0); /* _action_ind */
    q_put(q_initial,735,1,1); /* _ext */
    q_put(q_initial,960,8,ATM_IE_BLLI); /* _ie_id */
    q_put(q_initial,975,1,1); /* _ext */
    q_put(q_initial,973,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,972,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,968,3,0); /* _action_ind */
    q_put(q_initial,997,2,1); /* _lid */
    q_put(q_initial,999,1,1); /* _ext */
    q_put(q_initial,1005,2,2); /* _lid */
    q_put(q_initial,1007,1,0); /* _ext */
    q_put(q_initial,1013,2,ATM_IMD_NORMAL); /* l2_mode */
    q_put(q_initial,1008,2,0); /* q933 */
    q_put(q_initial,1015,1,0); /* _ext */
    q_put(q_initial,1023,1,1); /* _ext */
    q_put(q_initial,1031,1,1); /* _ext */
    q_put(q_initial,1039,1,1); /* _ext */
    q_put(q_initial,1047,1,0); /* _ext */
    q_put(q_initial,1055,1,1); /* _ext */
    q_put(q_initial,1063,1,1); /* _ext */
    q_put(q_initial,1069,2,3); /* _lid */
    q_put(q_initial,1071,1,0); /* _ext */
    q_put(q_initial,1077,2,ATM_IMD_NORMAL); /* l3_mode */
    q_put(q_initial,1079,1,0); /* _ext */
    q_put(q_initial,1087,1,0); /* _ext */
    q_put(q_initial,1095,1,1); /* _ext */
    q_put(q_initial,1111,1,1); /* _ext */
    q_put(q_initial,1119,1,1); /* _ext */
    q_put(q_initial,1127,1,1); /* _ext */
    q_put(q_initial,1135,1,0); /* _ext */
    q_put(q_initial,1136,4,ATM_TT_RXTX); /* term_type */
    q_put(q_initial,1143,1,0); /* _ext */
    q_put(q_initial,1151,1,1); /* _ext */
    q_put(q_initial,1147,3,ATM_MC_NONE); /* fw_mpx_cap */
    q_put(q_initial,1144,3,ATM_MC_NONE); /* bw_mpx_cap */
    q_put(q_initial,1159,1,1); /* _ext */
    q_put(q_initial,1167,1,1); /* _ext */
    q_put(q_initial,1175,1,0); /* _ext */
    q_put(q_initial,1183,1,0); /* _ext */
    q_put(q_initial,1191,1,1); /* _ext */
    q_put(q_initial,1190,1,0); /* _ipi_low */
    q_put(q_initial,1199,1,1); /* _ext */
    q_put(q_initial,1197,2,0); /* _snap_id */
    q_put(q_initial,1246,1,1); /* _ipi_low */
    q_put(q_initial,1255,1,1); /* _ext */
    q_put(q_initial,1263,1,1); /* _ext */
    q_put(q_initial,1271,1,0); /* _ext */
    q_put(q_initial,1279,1,1); /* _ext */
    q_put(q_initial,1280,8,ATM_IE_BLLI); /* _ie_id */
    q_put(q_initial,1295,1,1); /* _ext */
    q_put(q_initial,1293,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,1292,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,1288,3,0); /* _action_ind */
    q_put(q_initial,1317,2,1); /* _lid */
    q_put(q_initial,1319,1,1); /* _ext */
    q_put(q_initial,1325,2,2); /* _lid */
    q_put(q_initial,1327,1,0); /* _ext */
    q_put(q_initial,1333,2,ATM_IMD_NORMAL); /* l2_mode */
    q_put(q_initial,1328,2,0); /* q933 */
    q_put(q_initial,1335,1,0); /* _ext */
    q_put(q_initial,1343,1,1); /* _ext */
    q_put(q_initial,1351,1,1); /* _ext */
    q_put(q_initial,1359,1,1); /* _ext */
    q_put(q_initial,1367,1,0); /* _ext */
    q_put(q_initial,1375,1,1); /* _ext */
    q_put(q_initial,1383,1,1); /* _ext */
    q_put(q_initial,1389,2,3); /* _lid */
    q_put(q_initial,1391,1,0); /* _ext */
    q_put(q_initial,1397,2,ATM_IMD_NORMAL); /* l3_mode */
    q_put(q_initial,1399,1,0); /* _ext */
    q_put(q_initial,1407,1,0); /* _ext */
    q_put(q_initial,1415,1,1); /* _ext */
    q_put(q_initial,1431,1,1); /* _ext */
    q_put(q_initial,1439,1,1); /* _ext */
    q_put(q_initial,1447,1,1); /* _ext */
    q_put(q_initial,1455,1,0); /* _ext */
    q_put(q_initial,1456,4,ATM_TT_RXTX); /* term_type */
    q_put(q_initial,1463,1,0); /* _ext */
    q_put(q_initial,1471,1,1); /* _ext */
    q_put(q_initial,1467,3,ATM_MC_NONE); /* fw_mpx_cap */
    q_put(q_initial,1464,3,ATM_MC_NONE); /* bw_mpx_cap */
    q_put(q_initial,1479,1,1); /* _ext */
    q_put(q_initial,1487,1,1); /* _ext */
    q_put(q_initial,1495,1,0); /* _ext */
    q_put(q_initial,1503,1,0); /* _ext */
    q_put(q_initial,1511,1,1); /* _ext */
    q_put(q_initial,1510,1,0); /* _ipi_low */
    q_put(q_initial,1519,1,1); /* _ext */
    q_put(q_initial,1517,2,0); /* _snap_id */
    q_put(q_initial,1566,1,1); /* _ipi_low */
    q_put(q_initial,1575,1,1); /* _ext */
    q_put(q_initial,1583,1,1); /* _ext */
    q_put(q_initial,1591,1,0); /* _ext */
    q_put(q_initial,1599,1,1); /* _ext */
    q_put(q_initial,1600,8,ATM_IE_BLLI); /* _ie_id */
    q_put(q_initial,1615,1,1); /* _ext */
    q_put(q_initial,1613,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,1612,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,1608,3,0); /* _action_ind */
    q_put(q_initial,1637,2,1); /* _lid */
    q_put(q_initial,1639,1,1); /* _ext */
    q_put(q_initial,1645,2,2); /* _lid */
    q_put(q_initial,1647,1,0); /* _ext */
    q_put(q_initial,1653,2,ATM_IMD_NORMAL); /* l2_mode */
    q_put(q_initial,1648,2,0); /* q933 */
    q_put(q_initial,1655,1,0); /* _ext */
    q_put(q_initial,1663,1,1); /* _ext */
    q_put(q_initial,1671,1,1); /* _ext */
    q_put(q_initial,1679,1,1); /* _ext */
    q_put(q_initial,1687,1,0); /* _ext */
    q_put(q_initial,1695,1,1); /* _ext */
    q_put(q_initial,1703,1,1); /* _ext */
    q_put(q_initial,1709,2,3); /* _lid */
    q_put(q_initial,1711,1,0); /* _ext */
    q_put(q_initial,1717,2,ATM_IMD_NORMAL); /* l3_mode */
    q_put(q_initial,1719,1,0); /* _ext */
    q_put(q_initial,1727,1,0); /* _ext */
    q_put(q_initial,1735,1,1); /* _ext */
    q_put(q_initial,1751,1,1); /* _ext */
    q_put(q_initial,1759,1,1); /* _ext */
    q_put(q_initial,1767,1,1); /* _ext */
    q_put(q_initial,1775,1,0); /* _ext */
    q_put(q_initial,1776,4,ATM_TT_RXTX); /* term_type */
    q_put(q_initial,1783,1,0); /* _ext */
    q_put(q_initial,1791,1,1); /* _ext */
    q_put(q_initial,1787,3,ATM_MC_NONE); /* fw_mpx_cap */
    q_put(q_initial,1784,3,ATM_MC_NONE); /* bw_mpx_cap */
    q_put(q_initial,1799,1,1); /* _ext */
    q_put(q_initial,1807,1,1); /* _ext */
    q_put(q_initial,1815,1,0); /* _ext */
    q_put(q_initial,1823,1,0); /* _ext */
    q_put(q_initial,1831,1,1); /* _ext */
    q_put(q_initial,1830,1,0); /* _ipi_low */
    q_put(q_initial,1839,1,1); /* _ext */
    q_put(q_initial,1837,2,0); /* _snap_id */
    q_put(q_initial,1886,1,1); /* _ipi_low */
    q_put(q_initial,1895,1,1); /* _ext */
    q_put(q_initial,1903,1,1); /* _ext */
    q_put(q_initial,1911,1,0); /* _ext */
    q_put(q_initial,1919,1,1); /* _ext */
    q_put(q_initial,1920,8,ATM_IE_CALL_STATE); /* _ie_id */
    q_put(q_initial,1935,1,1); /* _ext */
    q_put(q_initial,1933,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,1932,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,1928,3,0); /* _action_ind */
    q_put(q_initial,1960,8,ATM_IE_CDPN); /* _ie_id */
    q_put(q_initial,1975,1,1); /* _ext */
    q_put(q_initial,1973,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,1972,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,1968,3,0); /* _action_ind */
    q_put(q_initial,1999,1,1); /* _ext */
    q_put(q_initial,1992,4,ATM_NP_E164); /* _plan */
    q_put(q_initial,1996,3,ATM_TON_INTRNTNL); /* _type */
    q_put(q_initial,2096,4,ATM_NP_AEA); /* _plan */
    q_put(q_initial,2100,3,ATM_TON_UNKNOWN); /* _type */
    q_put(q_initial,2264,8,ATM_IE_CDPS); /* _ie_id */
    q_put(q_initial,2279,1,1); /* _ext */
    q_put(q_initial,2277,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,2276,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,2272,3,0); /* _action_ind */
    q_put(q_initial,2303,1,1); /* _ext */
    q_put(q_initial,2300,3,ATM_SAT_AEA); /* cdps_type */
    q_put(q_initial,2299,1,0); /* _oddeven */
    q_put(q_initial,2464,8,ATM_IE_CGPN); /* _ie_id */
    q_put(q_initial,2479,1,1); /* _ext */
    q_put(q_initial,2477,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,2476,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,2472,3,0); /* _action_ind */
    q_put(q_initial,2503,1,0); /* _ext */
    q_put(q_initial,2511,1,1); /* _ext */
    q_put(q_initial,2509,2,ATM_PRS_ALLOW); /* pres_ind */
    q_put(q_initial,2504,2,ATM_SCRN_UP_NS); /* scr_ind */
    q_put(q_initial,2519,1,1); /* _ext */
    q_put(q_initial,2680,8,ATM_IE_CGPS); /* _ie_id */
    q_put(q_initial,2695,1,1); /* _ext */
    q_put(q_initial,2693,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,2692,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,2688,3,0); /* _action_ind */
    q_put(q_initial,2719,1,1); /* _ext */
    q_put(q_initial,2716,3,ATM_SAT_AEA); /* cgps_type */
    q_put(q_initial,2715,1,0); /* _oddeven */
    q_put(q_initial,2880,8,ATM_IE_CAUSE); /* _ie_id */
    q_put(q_initial,2895,1,1); /* _ext */
    q_put(q_initial,2893,2,Q2931_CS_ITU); /* cause_cs */
    q_put(q_initial,2892,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,2888,3,0); /* _action_ind */
    q_put(q_initial,2919,1,1); /* _ext */
    q_put(q_initial,2912,4,ATM_LOC_USER); /* location */
    q_put(q_initial,2927,1,1); /* _ext */
    q_put(q_initial,2935,1,1); /* _ext */
    q_put(q_initial,2931,1,ATM_PU_USER); /* pu */
    q_put(q_initial,2930,1,ATM_NA_NORMAL); /* na */
    q_put(q_initial,2928,2,ATM_COND_UNKNOWN); /* cond2 */
    q_put(q_initial,2943,1,1); /* _ext */
    q_put(q_initial,2936,2,ATM_COND_UNKNOWN); /* cond3 */
    q_put(q_initial,3912,8,ATM_IE_CAUSE); /* _ie_id */
    q_put(q_initial,3927,1,1); /* _ext */
    q_put(q_initial,3925,2,Q2931_CS_ITU); /* cause_cs */
    q_put(q_initial,3924,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,3920,3,0); /* _action_ind */
    q_put(q_initial,3951,1,1); /* _ext */
    q_put(q_initial,3944,4,ATM_LOC_USER); /* location */
    q_put(q_initial,3959,1,1); /* _ext */
    q_put(q_initial,3967,1,1); /* _ext */
    q_put(q_initial,3963,1,ATM_PU_USER); /* pu */
    q_put(q_initial,3962,1,ATM_NA_NORMAL); /* na */
    q_put(q_initial,3960,2,ATM_COND_UNKNOWN); /* cond2 */
    q_put(q_initial,3975,1,1); /* _ext */
    q_put(q_initial,3968,2,ATM_COND_UNKNOWN); /* cond3 */
    q_put(q_initial,4944,8,ATM_IE_CONN_ID); /* _ie_id */
    q_put(q_initial,4959,1,1); /* _ext */
    q_put(q_initial,4957,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,4956,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,4952,3,0); /* _action_ind */
    q_put(q_initial,4983,1,1); /* _ext */
    q_put(q_initial,4979,2,ATM_VPA_EXPL); /* _vp_ass */
    q_put(q_initial,4976,3,0); /* _pref_exc */
    q_put(q_initial,5016,8,ATM_IE_E2E_TDL); /* _ie_id */
    q_put(q_initial,5031,1,1); /* _ext */
    q_put(q_initial,5029,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,5028,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,5024,3,0); /* _action_ind */
    q_put(q_initial,5048,8,ATM_TDL_CUM); /* _id */
    q_put(q_initial,5072,8,ATM_TDL_E2EMAX); /* _id */
    q_put(q_initial,5096,8,ATM_TDL_NGI); /* _id */
    q_put(q_initial,5104,8,ATM_IE_QOS); /* _ie_id */
    q_put(q_initial,5119,1,1); /* _ext */
    q_put(q_initial,5117,2,Q2931_CS_NET); /* qos_cs */
    q_put(q_initial,5116,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,5112,3,0); /* _action_ind */
    q_put(q_initial,5136,8,0); /* qos_fw */
    q_put(q_initial,5144,8,0); /* qos_bw */
    q_put(q_initial,5152,8,ATM_IE_BBREP); /* _ie_id */
    q_put(q_initial,5167,1,1); /* _ext */
    q_put(q_initial,5165,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,5164,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,5160,3,0); /* _action_ind */
    q_put(q_initial,5191,1,1); /* _ext */
    q_put(q_initial,5184,4,2); /* rep_ind */
    q_put(q_initial,5192,8,ATM_IE_RESTART); /* _ie_id */
    q_put(q_initial,5207,1,1); /* _ext */
    q_put(q_initial,5205,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,5204,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,5200,3,0); /* _action_ind */
    q_put(q_initial,5231,1,1); /* _ext */
    q_put(q_initial,5232,8,ATM_IE_BBS_COMP); /* _ie_id */
    q_put(q_initial,5247,1,1); /* _ext */
    q_put(q_initial,5245,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,5244,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,5240,3,0); /* _action_ind */
    q_put(q_initial,5271,1,1); /* _ext */
    q_put(q_initial,5264,7,0x21); /* bbsc_ind */
    q_put(q_initial,5272,8,ATM_IE_TNS); /* _ie_id */
    q_put(q_initial,5287,1,1); /* _ext */
    q_put(q_initial,5285,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,5284,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,5280,3,0); /* _action_ind */
    q_put(q_initial,5311,1,1); /* _ext */
    q_put(q_initial,5308,3,ATM_TNI_NNI); /* _net_type */
    q_put(q_initial,5304,4,ATM_NIP_CARRIER); /* _carrier_id */
    q_put(q_initial,5344,8,ATM_IE_NOTIFY); /* _ie_id */
    q_put(q_initial,5359,1,1); /* _ext */
    q_put(q_initial,5357,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,5356,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,5352,3,0); /* _action_ind */
    q_put(q_initial,5408,8,ATM_IE_OAM_TD); /* _ie_id */
    q_put(q_initial,5423,1,1); /* _ext */
    q_put(q_initial,5421,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,5420,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,5416,3,0); /* _action_ind */
    q_put(q_initial,5447,1,1); /* _ext */
    q_put(q_initial,5445,2,ATM_SHI_NONE); /* shaping */
    q_put(q_initial,5444,1,ATM_OCI_OPT); /* compliance */
    q_put(q_initial,5440,3,ATM_UNFM_NONE); /* fault */
    q_put(q_initial,5455,1,1); /* _ext */
    q_put(q_initial,5452,3,ATM_OFI_0_0); /* fwd_ofi */
    q_put(q_initial,5448,3,ATM_OFI_0_0); /* bwd_ofi */
    q_put(q_initial,5456,8,ATM_IE_GIT); /* _ie_id */
    q_put(q_initial,5471,1,1); /* _ext */
    q_put(q_initial,5469,2,Q2931_CS_NET); /* _cs */
    q_put(q_initial,5468,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,5464,3,0); /* _action_ind */
    q_put(q_initial,5495,1,0); /* _dummy */
    q_put(q_initial,5504,8,ATM_IT_SESSION); /* _type */
    q_put(q_initial,5680,8,ATM_IT_RESOURCE); /* _type */
    q_put(q_initial,5952,8,ATM_IE_GIT); /* _ie_id */
    q_put(q_initial,5967,1,1); /* _ext */
    q_put(q_initial,5965,2,Q2931_CS_NET); /* _cs */
    q_put(q_initial,5964,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,5960,3,0); /* _action_ind */
    q_put(q_initial,5991,1,0); /* _dummy */
    q_put(q_initial,6000,8,ATM_IT_SESSION); /* _type */
    q_put(q_initial,6176,8,ATM_IT_RESOURCE); /* _type */
    q_put(q_initial,6448,8,ATM_IE_GIT); /* _ie_id */
    q_put(q_initial,6463,1,1); /* _ext */
    q_put(q_initial,6461,2,Q2931_CS_NET); /* _cs */
    q_put(q_initial,6460,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,6456,3,0); /* _action_ind */
    q_put(q_initial,6487,1,0); /* _dummy */
    q_put(q_initial,6496,8,ATM_IT_SESSION); /* _type */
    q_put(q_initial,6672,8,ATM_IT_RESOURCE); /* _type */
    q_put(q_initial,6944,8,ATM_IE_LIJ_ID); /* _ie_id */
    q_put(q_initial,6959,1,1); /* _ext */
    q_put(q_initial,6957,2,Q2931_CS_NET); /* _cs */
    q_put(q_initial,6956,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,6952,3,0); /* _action_ind */
    q_put(q_initial,6983,1,1); /* _ext */
    q_put(q_initial,6976,7,ATM_LIT_ROOT); /* lij_id_type */
    q_put(q_initial,7016,8,ATM_IE_LIJ_PRM); /* _ie_id */
    q_put(q_initial,7031,1,1); /* _ext */
    q_put(q_initial,7029,2,Q2931_CS_NET); /* _cs */
    q_put(q_initial,7028,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,7024,3,0); /* _action_ind */
    q_put(q_initial,7055,1,1); /* _ext */
    q_put(q_initial,7056,8,ATM_IE_LEAF_SN); /* _ie_id */
    q_put(q_initial,7071,1,1); /* _ext */
    q_put(q_initial,7069,2,Q2931_CS_NET); /* _cs */
    q_put(q_initial,7068,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,7064,3,0); /* _action_ind */
    q_put(q_initial,7120,8,ATM_IE_SCOPE_SEL); /* _ie_id */
    q_put(q_initial,7135,1,1); /* _ext */
    q_put(q_initial,7133,2,Q2931_CS_NET); /* _cs */
    q_put(q_initial,7132,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,7128,3,0); /* _action_ind */
    q_put(q_initial,7159,1,1); /* _ext */
    q_put(q_initial,7152,4,ATM_TCS_ORGANIZATIONAL); /* scope_type */
    q_put(q_initial,7168,8,ATM_IE_ALT_TD); /* _ie_id */
    q_put(q_initial,7183,1,1); /* _ext */
    q_put(q_initial,7181,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,7180,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,7176,3,0); /* _action_ind */
    q_put(q_initial,7200,8,ATM_TD_FW_PCR_0); /* _id */
    q_put(q_initial,7232,8,ATM_TD_BW_PCR_0); /* _id */
    q_put(q_initial,7264,8,ATM_TD_FW_PCR_01); /* _id */
    q_put(q_initial,7296,8,ATM_TD_BW_PCR_01); /* _id */
    q_put(q_initial,7328,8,ATM_TD_FW_SCR_0); /* _id */
    q_put(q_initial,7360,8,ATM_TD_BW_SCR_0); /* _id */
    q_put(q_initial,7392,8,ATM_TD_FW_SCR_01); /* _id */
    q_put(q_initial,7424,8,ATM_TD_BW_SCR_01); /* _id */
    q_put(q_initial,7456,8,ATM_TD_FW_MBS_0); /* _id */
    q_put(q_initial,7488,8,ATM_TD_BW_MBS_0); /* _id */
    q_put(q_initial,7520,8,ATM_TD_FW_MBS_01); /* _id */
    q_put(q_initial,7552,8,ATM_TD_BW_MBS_01); /* _id */
    q_put(q_initial,7584,8,ATM_TD_BEST_EFFORT); /* _id */
    q_put(q_initial,7592,8,ATM_IE_MIN_TD); /* _ie_id */
    q_put(q_initial,7607,1,1); /* _ext */
    q_put(q_initial,7605,2,Q2931_CS_NET); /* _cs */
    q_put(q_initial,7604,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,7600,3,0); /* _action_ind */
    q_put(q_initial,7624,8,ATM_TD_FW_PCR_0); /* _id */
    q_put(q_initial,7656,8,ATM_TD_BW_PCR_0); /* _id */
    q_put(q_initial,7688,8,ATM_TD_FW_PCR_01); /* _id */
    q_put(q_initial,7720,8,ATM_TD_BW_PCR_01); /* _id */
    q_put(q_initial,7752,8,ATM_TD_FW_MCR_01); /* _id */
    q_put(q_initial,7784,8,ATM_TD_BW_MCR_01); /* _id */
    q_put(q_initial,7816,8,ATM_IE_EQOS); /* _ie_id */
    q_put(q_initial,7831,1,1); /* _ext */
    q_put(q_initial,7829,2,Q2931_CS_NET); /* _cs */
    q_put(q_initial,7828,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,7824,3,0); /* _action_ind */
    q_put(q_initial,7856,8,ATM_EQP_ACC_FW_CDV); /* _id */
    q_put(q_initial,7888,8,ATM_EQP_ACC_BW_CDV); /* _id */
    q_put(q_initial,7920,8,ATM_EQP_CUM_FW_CDV); /* _id */
    q_put(q_initial,7952,8,ATM_EQP_CUM_BW_CDV); /* _id */
    q_put(q_initial,7984,8,ATM_EQP_ACC_FW_CLR); /* _id */
    q_put(q_initial,8000,8,ATM_EQP_ACC_BW_CLR); /* _id */
    q_put(q_initial,8016,8,ATM_IE_ABR_ADD_PRM); /* _ie_id */
    q_put(q_initial,8031,1,1); /* _ext */
    q_put(q_initial,8029,2,Q2931_CS_NET); /* _cs */
    q_put(q_initial,8028,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,8024,3,0); /* _action_ind */
    q_put(q_initial,8048,8,ATM_AAP_FW_REC); /* _id */
    q_put(q_initial,8088,8,ATM_AAP_BW_REC); /* _id */
    q_put(q_initial,8128,8,ATM_IE_ABR_SET_PRM); /* _ie_id */
    q_put(q_initial,8143,1,1); /* _ext */
    q_put(q_initial,8141,2,Q2931_CS_NET); /* _cs */
    q_put(q_initial,8140,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,8136,3,0); /* _action_ind */
    q_put(q_initial,8160,8,ATM_ASP_FW_ICR); /* _id */
    q_put(q_initial,8192,8,ATM_ASP_BW_ICR); /* _id */
    q_put(q_initial,8224,8,ATM_ASP_FW_TBE); /* _id */
    q_put(q_initial,8256,8,ATM_ASP_BW_TBE); /* _id */
    q_put(q_initial,8288,8,ATM_ASP_CRF_RTT); /* _id */
    q_put(q_initial,8320,8,ATM_ASP_FW_RIF); /* _id */
    q_put(q_initial,8336,8,ATM_ASP_BW_RIF); /* _id */
    q_put(q_initial,8352,8,ATM_ASP_FW_RDF); /* _id */
    q_put(q_initial,8368,8,ATM_ASP_BW_RDF); /* _id */
    q_put(q_initial,8384,8,ATM_IE_EPR); /* _ie_id */
    q_put(q_initial,8399,1,1); /* _ext */
    q_put(q_initial,8397,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,8396,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,8392,3,0); /* _action_ind */
    q_put(q_initial,8416,8,0); /* _ep_type */
    q_put(q_initial,8440,8,ATM_IE_EP_STATE); /* _ie_id */
    q_put(q_initial,8455,1,1); /* _ext */
    q_put(q_initial,8453,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,8452,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,8448,3,0); /* _action_ind */
    q_put(q_initial,8480,8,ATM_IE_BBRT); /* _ie_id */
    q_put(q_initial,8495,1,1); /* _ext */
    q_put(q_initial,8493,2,Q2931_CS_ITU); /* _cs */
    q_put(q_initial,8492,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,8488,3,0); /* _action_ind */
    q_put(q_initial,8520,8,0); /* _ie_id */
    q_put(q_initial,8535,1,1); /* _ext */
    q_put(q_initial,8533,2,0); /* __cs */
    q_put(q_initial,8532,1,ATM_FLAG_NO); /* _flag */
    q_put(q_initial,8528,3,0); /* _action_ind */
}


/*
 * If a group contains required fields, these are listed in the
 * following arrays. Each list ends with -1. The variable names
 * end with the group number.
 */

static int required_0[] = {
    0, /* call_ref */
    1, /* msg_type */
    -1
};

static int required_3[] = {
    4, /* fw_max_sdu */
    -1
};

static int required_4[] = {
    5, /* bw_max_sdu */
    -1
};

static int required_5[] = {
    6, /* aal_mode */
    -1
};

static int required_6[] = {
    7, /* sscs_type */
    -1
};

static int required_8[] = {
    8, /* fw_pcr_0 */
    -1
};

static int required_9[] = {
    9, /* bw_pcr_0 */
    -1
};

static int required_10[] = {
    10, /* fw_pcr_01 */
    -1
};

static int required_11[] = {
    11, /* bw_pcr_01 */
    -1
};

static int required_12[] = {
    12, /* fw_scr_0 */
    -1
};

static int required_13[] = {
    13, /* bw_scr_0 */
    -1
};

static int required_14[] = {
    14, /* fw_scr_01 */
    -1
};

static int required_15[] = {
    15, /* bw_scr_01 */
    -1
};

static int required_16[] = {
    16, /* fw_mbs_0 */
    -1
};

static int required_17[] = {
    17, /* bw_mbs_0 */
    -1
};

static int required_18[] = {
    18, /* fw_mbs_01 */
    -1
};

static int required_19[] = {
    19, /* bw_mbs_01 */
    -1
};

static int required_20[] = {
    20, /* best_effort */
    -1
};

static int required_22[] = {
    25, /* bearer_class */
    -1
};

static int required_23[] = {
    26, /* trans_cap */
    -1
};

static int required_26[] = {
    30, /* iso_hli */
    -1
};

static int required_27[] = {
    31, /* user_hli */
    -1
};

static int required_28[] = {
    32, /* hlp */
    -1
};

static int required_29[] = {
    33, /* hli_oui */
    34, /* app_id */
    -1
};

static int required_30[] = {
    35, /* tobedefined */
    -1
};

static int required_32[] = {
    36, /* uil1_proto */
    -1
};

static int required_36[] = {
    40, /* window_size */
    -1
};

static int required_39[] = {
    41, /* user_l2 */
    -1
};

static int required_44[] = {
    44, /* def_pck_size */
    -1
};

static int required_45[] = {
    45, /* pck_win_size */
    -1
};

static int required_57[] = {
    50, /* oui */
    51, /* pid */
    -1
};

static int required_59[] = {
    52, /* ipi_low */
    -1
};

static int required_61[] = {
    53, /* user_l3 */
    -1
};

static int required_63[] = {
    54, /* uil1_proto */
    -1
};

static int required_67[] = {
    58, /* window_size */
    -1
};

static int required_70[] = {
    59, /* user_l2 */
    -1
};

static int required_75[] = {
    62, /* def_pck_size */
    -1
};

static int required_76[] = {
    63, /* pck_win_size */
    -1
};

static int required_88[] = {
    68, /* oui */
    69, /* pid */
    -1
};

static int required_90[] = {
    70, /* ipi_low */
    -1
};

static int required_92[] = {
    71, /* user_l3 */
    -1
};

static int required_94[] = {
    72, /* uil1_proto */
    -1
};

static int required_98[] = {
    76, /* window_size */
    -1
};

static int required_101[] = {
    77, /* user_l2 */
    -1
};

static int required_106[] = {
    80, /* def_pck_size */
    -1
};

static int required_107[] = {
    81, /* pck_win_size */
    -1
};

static int required_119[] = {
    86, /* oui */
    87, /* pid */
    -1
};

static int required_121[] = {
    88, /* ipi_low */
    -1
};

static int required_123[] = {
    89, /* user_l3 */
    -1
};

static int required_124[] = {
    90, /* call_state */
    -1
};

static int required_126[] = {
    91, /* cdpn_e164 */
    -1
};

static int required_127[] = {
    92, /* cdpn_esa */
    -1
};

static int required_128[] = {
    94, /* cdps */
    -1
};

static int required_129[] = {
    95, /* cgpn_plan */
    96, /* cgpn_type */
    99, /* cgpn */
    -1
};

static int required_132[] = {
    101, /* cgps */
    -1
};

static int required_136[] = {
    110, /* user_diag */
    -1
};

static int required_137[] = {
    111, /* ie_id3 */
    -1
};

static int required_149[] = {
    128, /* user_diag */
    -1
};

static int required_150[] = {
    129, /* ie_id3 */
    -1
};

static int required_159[] = {
    138, /* vpi */
    139, /* vci */
    -1
};

static int required_161[] = {
    140, /* cum_delay */
    -1
};

static int required_162[] = {
    141, /* max_delay */
    -1
};

static int required_166[] = {
    146, /* rst_class */
    -1
};

static int required_168[] = {
    148, /* net_id */
    -1
};

static int required_169[] = {
    149, /* notification */
    -1
};

static int required_172[] = {
    156, /* session_id */
    157, /* resource_id */
    -1
};

static int required_173[] = {
    158, /* unrecognized_git_identifiers */
    -1
};

static int required_175[] = {
    160, /* session_id */
    161, /* resource_id */
    -1
};

static int required_176[] = {
    162, /* unrecognized_git_identifiers */
    -1
};

static int required_178[] = {
    164, /* session_id */
    165, /* resource_id */
    -1
};

static int required_179[] = {
    166, /* unrecognized_git_identifiers */
    -1
};

static int required_180[] = {
    168, /* lij_id */
    -1
};

static int required_181[] = {
    169, /* lij_scr_ind */
    -1
};

static int required_182[] = {
    170, /* leaf_sn */
    -1
};

static int required_183[] = {
    172, /* scope_sel */
    -1
};

static int required_185[] = {
    173, /* altfw_pcr_0 */
    -1
};

static int required_186[] = {
    174, /* altbw_pcr_0 */
    -1
};

static int required_187[] = {
    175, /* altfw_pcr_01 */
    -1
};

static int required_188[] = {
    176, /* altbw_pcr_01 */
    -1
};

static int required_189[] = {
    177, /* altfw_scr_0 */
    -1
};

static int required_190[] = {
    178, /* altbw_scr_0 */
    -1
};

static int required_191[] = {
    179, /* altfw_scr_01 */
    -1
};

static int required_192[] = {
    180, /* altbw_scr_01 */
    -1
};

static int required_193[] = {
    181, /* altfw_mbs_0 */
    -1
};

static int required_194[] = {
    182, /* altbw_mbs_0 */
    -1
};

static int required_195[] = {
    183, /* altfw_mbs_01 */
    -1
};

static int required_196[] = {
    184, /* altbw_mbs_01 */
    -1
};

static int required_197[] = {
    185, /* altbest_effort */
    -1
};

static int required_199[] = {
    186, /* minfw_pcr_0 */
    -1
};

static int required_200[] = {
    187, /* minbw_pcr_0 */
    -1
};

static int required_201[] = {
    188, /* minfw_pcr_01 */
    -1
};

static int required_202[] = {
    189, /* minbw_pcr_01 */
    -1
};

static int required_203[] = {
    190, /* minfw_mcr_01 */
    -1
};

static int required_204[] = {
    191, /* minbw_mcr_01 */
    -1
};

static int required_205[] = {
    192, /* eqos_origin */
    -1
};

static int required_206[] = {
    193, /* acc_fw_cdv */
    -1
};

static int required_207[] = {
    194, /* acc_bw_cdv */
    -1
};

static int required_208[] = {
    195, /* cum_fw_cdv */
    -1
};

static int required_209[] = {
    196, /* cum_bw_cdv */
    -1
};

static int required_210[] = {
    197, /* acc_fw_clr */
    -1
};

static int required_211[] = {
    198, /* acc_bw_clr */
    -1
};

static int required_213[] = {
    199, /* abr_fw_add_rec */
    -1
};

static int required_214[] = {
    200, /* abr_bw_add_rec */
    -1
};

static int required_216[] = {
    201, /* abr_fw_icr */
    -1
};

static int required_217[] = {
    202, /* abr_bw_icr */
    -1
};

static int required_218[] = {
    203, /* abr_fw_tbe */
    -1
};

static int required_219[] = {
    204, /* abr_bw_tbe */
    -1
};

static int required_220[] = {
    205, /* atm_crf_rtt */
    -1
};

static int required_221[] = {
    206, /* atm_fw_rif */
    -1
};

static int required_222[] = {
    207, /* atm_bw_rif */
    -1
};

static int required_223[] = {
    208, /* atm_fw_rdf */
    -1
};

static int required_224[] = {
    209, /* atm_bw_rdf */
    -1
};

static int required_225[] = {
    210, /* ep_ref */
    -1
};

static int required_226[] = {
    211, /* ep_state */
    -1
};

static int required_227[] = {
    212, /* type_of_report */
    -1
};


/*
 * Various information about groups.
 */

typedef struct {
    int parent;
    int *required;
    int start;
    int length;
    int offset;
} GROUP;

static GROUP groups[] = {
    { -1, required_0 },
    { 0, NULL, -1, 0, 0 },
    { 1, NULL, -1, 0, 0 },
    { 2, required_3, -1, 0, 0 }, /* fw_max_sdu */
    { 2, required_4, -1, 0, 0 }, /* bw_max_sdu */
    { 2, required_5, -1, 0, 0 }, /* aal_mode */
    { 2, required_6, -1, 0, 0 }, /* sscs_type */
    { 0, NULL, -1, 0, 0 },
    { 7, required_8, -1, 0, 0 }, /* fw_pcr_0 */
    { 7, required_9, -1, 0, 0 }, /* bw_pcr_0 */
    { 7, required_10, -1, 0, 0 }, /* fw_pcr_01 */
    { 7, required_11, -1, 0, 0 }, /* bw_pcr_01 */
    { 7, required_12, -1, 0, 0 }, /* fw_scr_0 */
    { 7, required_13, -1, 0, 0 }, /* bw_scr_0 */
    { 7, required_14, -1, 0, 0 }, /* fw_scr_01 */
    { 7, required_15, -1, 0, 0 }, /* bw_scr_01 */
    { 7, required_16, -1, 0, 0 }, /* fw_mbs_0 */
    { 7, required_17, -1, 0, 0 }, /* bw_mbs_0 */
    { 7, required_18, -1, 0, 0 }, /* fw_mbs_01 */
    { 7, required_19, -1, 0, 0 }, /* bw_mbs_01 */
    { 7, required_20, -1, 0, 0 }, /* best_effort */
    { 7, NULL, -1, 0, 0 },
    { 0, required_22, -1, 0, 0 },
    { 22, required_23, -1, 0, 0 }, /* _ext */
    { 22, NULL, -1, 0, 0 },
    { 0, NULL, -1, 0, 0 },
    { 25, required_26, -1, 0, 0 }, /* iso_hli */
    { 25, required_27, -1, 0, 0 }, /* user_hli */
    { 25, required_28, -1, 0, 0 }, /* hlp */
    { 25, required_29, -1, 0, 0 }, /* hli_oui */
    { 25, required_30, -1, 0, 0 }, /* tobedefined */
    { 0, NULL, 36, 18, 0 },
    { 31, required_32, -1, 0, 0 }, /* _ext */
    { 31, NULL, -1, 0, 0 },
    { 33, NULL, -1, 0, 0 },
    { 34, NULL, -1, 0, 0 },
    { 35, required_36, -1, 0, 0 }, /* window_size */
    { 35, NULL, -1, 0, 0 },
    { 34, NULL, -1, 0, 0 },
    { 33, required_39, -1, 0, 0 }, /* _ext */
    { 33, NULL, -1, 0, 0 },
    { 31, NULL, -1, 0, 0 },
    { 41, NULL, -1, 0, 0 },
    { 42, NULL, -1, 0, 0 },
    { 43, required_44, -1, 0, 0 }, /* def_pck_size */
    { 44, required_45, -1, 0, 0 }, /* _ext */
    { 44, NULL, -1, 0, 0 },
    { 43, NULL, -1, 0, 0 },
    { 42, NULL, -1, 0, 0 },
    { 41, NULL, -1, 0, 0 },
    { 49, NULL, -1, 0, 0 },
    { 50, NULL, -1, 0, 0 },
    { 50, NULL, -1, 0, 0 },
    { 49, NULL, -1, 0, 0 },
    { 41, NULL, -1, 0, 0 },
    { 54, NULL, -1, 0, 0 },
    { 55, NULL, -1, 0, 0 },
    { 56, required_57, -1, 0, 0 }, /* _ext */
    { 56, NULL, -1, 0, 0 },
    { 55, required_59, -1, 0, 0 }, /* _ext */
    { 54, NULL, -1, 0, 0 },
    { 41, required_61, -1, 0, 0 }, /* _ext */
    { 0, NULL, 36, 18, 18 },
    { 62, required_63, -1, 0, 0 }, /* _ext */
    { 62, NULL, -1, 0, 0 },
    { 64, NULL, -1, 0, 0 },
    { 65, NULL, -1, 0, 0 },
    { 66, required_67, -1, 0, 0 }, /* window_size */
    { 66, NULL, -1, 0, 0 },
    { 65, NULL, -1, 0, 0 },
    { 64, required_70, -1, 0, 0 }, /* _ext */
    { 64, NULL, -1, 0, 0 },
    { 62, NULL, -1, 0, 0 },
    { 72, NULL, -1, 0, 0 },
    { 73, NULL, -1, 0, 0 },
    { 74, required_75, -1, 0, 0 }, /* def_pck_size */
    { 75, required_76, -1, 0, 0 }, /* _ext */
    { 75, NULL, -1, 0, 0 },
    { 74, NULL, -1, 0, 0 },
    { 73, NULL, -1, 0, 0 },
    { 72, NULL, -1, 0, 0 },
    { 80, NULL, -1, 0, 0 },
    { 81, NULL, -1, 0, 0 },
    { 81, NULL, -1, 0, 0 },
    { 80, NULL, -1, 0, 0 },
    { 72, NULL, -1, 0, 0 },
    { 85, NULL, -1, 0, 0 },
    { 86, NULL, -1, 0, 0 },
    { 87, required_88, -1, 0, 0 }, /* _ext */
    { 87, NULL, -1, 0, 0 },
    { 86, required_90, -1, 0, 0 }, /* _ext */
    { 85, NULL, -1, 0, 0 },
    { 72, required_92, -1, 0, 0 }, /* _ext */
    { 0, NULL, 36, 18, 36 },
    { 93, required_94, -1, 0, 0 }, /* _ext */
    { 93, NULL, -1, 0, 0 },
    { 95, NULL, -1, 0, 0 },
    { 96, NULL, -1, 0, 0 },
    { 97, required_98, -1, 0, 0 }, /* window_size */
    { 97, NULL, -1, 0, 0 },
    { 96, NULL, -1, 0, 0 },
    { 95, required_101, -1, 0, 0 }, /* _ext */
    { 95, NULL, -1, 0, 0 },
    { 93, NULL, -1, 0, 0 },
    { 103, NULL, -1, 0, 0 },
    { 104, NULL, -1, 0, 0 },
    { 105, required_106, -1, 0, 0 }, /* def_pck_size */
    { 106, required_107, -1, 0, 0 }, /* _ext */
    { 106, NULL, -1, 0, 0 },
    { 105, NULL, -1, 0, 0 },
    { 104, NULL, -1, 0, 0 },
    { 103, NULL, -1, 0, 0 },
    { 111, NULL, -1, 0, 0 },
    { 112, NULL, -1, 0, 0 },
    { 112, NULL, -1, 0, 0 },
    { 111, NULL, -1, 0, 0 },
    { 103, NULL, -1, 0, 0 },
    { 116, NULL, -1, 0, 0 },
    { 117, NULL, -1, 0, 0 },
    { 118, required_119, -1, 0, 0 }, /* _ext */
    { 118, NULL, -1, 0, 0 },
    { 117, required_121, -1, 0, 0 }, /* _ext */
    { 116, NULL, -1, 0, 0 },
    { 103, required_123, -1, 0, 0 }, /* _ext */
    { 0, required_124, -1, 0, 0 },
    { 0, NULL, -1, 0, 0 },
    { 125, required_126, -1, 0, 0 }, /* _type */
    { 125, required_127, -1, 0, 0 }, /* _type */
    { 0, required_128, -1, 0, 0 },
    { 0, required_129, -1, 0, 0 },
    { 129, NULL, -1, 0, 0 },
    { 129, NULL, -1, 0, 0 },
    { 0, required_132, -1, 0, 0 },
    { 0, NULL, 102, 18, 0 },
    { 133, NULL, -1, 0, 0 },
    { 133, NULL, -1, 0, 0 },
    { 135, required_136, -1, 0, 0 }, /* user_diag */
    { 135, required_137, -1, 0, 0 }, /* ie_id3 */
    { 133, NULL, -1, 0, 0 },
    { 133, NULL, -1, 0, 0 },
    { 133, NULL, -1, 0, 0 },
    { 133, NULL, -1, 0, 0 },
    { 133, NULL, -1, 0, 0 },
    { 133, NULL, -1, 0, 0 },
    { 133, NULL, -1, 0, 0 },
    { 133, NULL, -1, 0, 0 },
    { 0, NULL, 102, 18, 18 },
    { 146, NULL, -1, 0, 0 },
    { 146, NULL, -1, 0, 0 },
    { 148, required_149, -1, 0, 0 }, /* user_diag */
    { 148, required_150, -1, 0, 0 }, /* ie_id3 */
    { 146, NULL, -1, 0, 0 },
    { 146, NULL, -1, 0, 0 },
    { 146, NULL, -1, 0, 0 },
    { 146, NULL, -1, 0, 0 },
    { 146, NULL, -1, 0, 0 },
    { 146, NULL, -1, 0, 0 },
    { 146, NULL, -1, 0, 0 },
    { 146, NULL, -1, 0, 0 },
    { 0, required_159, -1, 0, 0 },
    { 0, NULL, -1, 0, 0 },
    { 160, required_161, -1, 0, 0 }, /* cum_delay */
    { 160, required_162, -1, 0, 0 }, /* max_delay */
    { 160, NULL, -1, 0, 0 },
    { 0, NULL, -1, 0, 0 },
    { 0, NULL, -1, 0, 0 },
    { 0, required_166, -1, 0, 0 },
    { 0, NULL, -1, 0, 0 },
    { 0, required_168, -1, 0, 0 },
    { 0, required_169, -1, 0, 0 },
    { 0, NULL, -1, 0, 0 },
    { 0, NULL, 155, 4, 0 },
    { 171, required_172, -1, 0, 0 }, /* _type */
    { 171, required_173, -1, 0, 0 }, /* unrecognized_git_identifiers */
    { 0, NULL, 155, 4, 4 },
    { 174, required_175, -1, 0, 0 }, /* _type */
    { 174, required_176, -1, 0, 0 }, /* unrecognized_git_identifiers */
    { 0, NULL, 155, 4, 8 },
    { 177, required_178, -1, 0, 0 }, /* _type */
    { 177, required_179, -1, 0, 0 }, /* unrecognized_git_identifiers */
    { 0, required_180, -1, 0, 0 },
    { 0, required_181, -1, 0, 0 },
    { 0, required_182, -1, 0, 0 },
    { 0, required_183, -1, 0, 0 },
    { 0, NULL, -1, 0, 0 },
    { 184, required_185, -1, 0, 0 }, /* altfw_pcr_0 */
    { 184, required_186, -1, 0, 0 }, /* altbw_pcr_0 */
    { 184, required_187, -1, 0, 0 }, /* altfw_pcr_01 */
    { 184, required_188, -1, 0, 0 }, /* altbw_pcr_01 */
    { 184, required_189, -1, 0, 0 }, /* altfw_scr_0 */
    { 184, required_190, -1, 0, 0 }, /* altbw_scr_0 */
    { 184, required_191, -1, 0, 0 }, /* altfw_scr_01 */
    { 184, required_192, -1, 0, 0 }, /* altbw_scr_01 */
    { 184, required_193, -1, 0, 0 }, /* altfw_mbs_0 */
    { 184, required_194, -1, 0, 0 }, /* altbw_mbs_0 */
    { 184, required_195, -1, 0, 0 }, /* altfw_mbs_01 */
    { 184, required_196, -1, 0, 0 }, /* altbw_mbs_01 */
    { 184, required_197, -1, 0, 0 }, /* altbest_effort */
    { 0, NULL, -1, 0, 0 },
    { 198, required_199, -1, 0, 0 }, /* minfw_pcr_0 */
    { 198, required_200, -1, 0, 0 }, /* minbw_pcr_0 */
    { 198, required_201, -1, 0, 0 }, /* minfw_pcr_01 */
    { 198, required_202, -1, 0, 0 }, /* minbw_pcr_01 */
    { 198, required_203, -1, 0, 0 }, /* minfw_mcr_01 */
    { 198, required_204, -1, 0, 0 }, /* minbw_mcr_01 */
    { 0, required_205, -1, 0, 0 },
    { 205, required_206, -1, 0, 0 }, /* acc_fw_cdv */
    { 205, required_207, -1, 0, 0 }, /* acc_bw_cdv */
    { 205, required_208, -1, 0, 0 }, /* cum_fw_cdv */
    { 205, required_209, -1, 0, 0 }, /* cum_bw_cdv */
    { 205, required_210, -1, 0, 0 }, /* acc_fw_clr */
    { 205, required_211, -1, 0, 0 }, /* acc_bw_clr */
    { 0, NULL, -1, 0, 0 },
    { 212, required_213, -1, 0, 0 }, /* abr_fw_add_rec */
    { 212, required_214, -1, 0, 0 }, /* abr_bw_add_rec */
    { 0, NULL, -1, 0, 0 },
    { 215, required_216, -1, 0, 0 }, /* abr_fw_icr */
    { 215, required_217, -1, 0, 0 }, /* abr_bw_icr */
    { 215, required_218, -1, 0, 0 }, /* abr_fw_tbe */
    { 215, required_219, -1, 0, 0 }, /* abr_bw_tbe */
    { 215, required_220, -1, 0, 0 }, /* atm_crf_rtt */
    { 215, required_221, -1, 0, 0 }, /* atm_fw_rif */
    { 215, required_222, -1, 0, 0 }, /* atm_bw_rif */
    { 215, required_223, -1, 0, 0 }, /* atm_fw_rdf */
    { 215, required_224, -1, 0, 0 }, /* atm_bw_rdf */
    { 0, required_225, -1, 0, 0 },
    { 0, required_226, -1, 0, 0 },
    { 0, required_227, -1, 0, 0 },
    { 0, NULL, -1, 0, 0 },
};


/*
 * Named case selectors only have a limited set of valid
 * values. They are listed in the following arrays, each followed
 * by the number of the group it enables.
 */

static int values_3[] = { /* aal_type */
    5, 2,
    -1, -1
};

static int values_29[] = { /* hli_type */
    0, 26,
    1, 27,
    2, 28,
    3, 29,
    4, 30,
    -1, -1
};

static int values_37[] = { /* uil2_proto */
    ATM_L2_X25_LL, 34,
    ATM_L2_X25_ML, 34,
    ATM_L2_HDLC_ARM, 34,
    ATM_L2_HDLC_NRM, 34,
    ATM_L2_HDLC_ABM, 34,
    ATM_L2_Q922, 34,
    ATM_L2_ISO7776, 34,
    ATM_L2_USER, 39,
    ATM_L2_ISO1745, 40,
    ATM_L2_Q291, 40,
    ATM_L2_LAPB, 40,
    ATM_L2_ISO8802, 40,
    ATM_L2_X75, 40,
    -2, 40,
    -1, -1
};

static int values_42[] = { /* uil3_proto */
    ATM_L3_X25, 42,
    ATM_L3_ISO8208, 42,
    ATM_L3_X223, 42,
    ATM_L3_H310, 49,
    ATM_L3_TR9577, 54,
    ATM_L3_USER, 61,
    -1, -1
};

static int values_49[] = { /* ipi_high */
    0x40, 56,
    0x0, 59,
    -2, 59,
    -1, -1
};

static int values_55[] = { /* uil2_proto */
    ATM_L2_X25_LL, 65,
    ATM_L2_X25_ML, 65,
    ATM_L2_HDLC_ARM, 65,
    ATM_L2_HDLC_NRM, 65,
    ATM_L2_HDLC_ABM, 65,
    ATM_L2_Q922, 65,
    ATM_L2_ISO7776, 65,
    ATM_L2_USER, 70,
    ATM_L2_ISO1745, 71,
    ATM_L2_Q291, 71,
    ATM_L2_LAPB, 71,
    ATM_L2_ISO8802, 71,
    ATM_L2_X75, 71,
    -2, 71,
    -1, -1
};

static int values_60[] = { /* uil3_proto */
    ATM_L3_X25, 73,
    ATM_L3_ISO8208, 73,
    ATM_L3_X223, 73,
    ATM_L3_H310, 80,
    ATM_L3_TR9577, 85,
    ATM_L3_USER, 92,
    -1, -1
};

static int values_67[] = { /* ipi_high */
    0x40, 87,
    0x0, 90,
    -2, 90,
    -1, -1
};

static int values_73[] = { /* uil2_proto */
    ATM_L2_X25_LL, 96,
    ATM_L2_X25_ML, 96,
    ATM_L2_HDLC_ARM, 96,
    ATM_L2_HDLC_NRM, 96,
    ATM_L2_HDLC_ABM, 96,
    ATM_L2_Q922, 96,
    ATM_L2_ISO7776, 96,
    ATM_L2_USER, 101,
    ATM_L2_ISO1745, 102,
    ATM_L2_Q291, 102,
    ATM_L2_LAPB, 102,
    ATM_L2_ISO8802, 102,
    ATM_L2_X75, 102,
    -2, 102,
    -1, -1
};

static int values_78[] = { /* uil3_proto */
    ATM_L3_X25, 104,
    ATM_L3_ISO8208, 104,
    ATM_L3_X223, 104,
    ATM_L3_H310, 111,
    ATM_L3_TR9577, 116,
    ATM_L3_USER, 123,
    -1, -1
};

static int values_85[] = { /* ipi_high */
    0x40, 118,
    0x0, 121,
    -2, 121,
    -1, -1
};

static int values_104[] = { /* cause */
    ATM_CV_UNALLOC, 134,
    ATM_CV_NO_ROUTE_DEST, 134,
    ATM_CV_QOS_UNAVAIL, 134,
    ATM_CV_CALL_REJ, 135,
    ATM_CV_NUM_CHANGED, 138,
    ATM_CV_REJ_CLIR, 139,
    ATM_CV_ACC_INF_DISC, 140,
    ATM_CV_INCOMP_DEST, 140,
    ATM_CV_MAND_IE_MISSING, 140,
    ATM_CV_UNKNOWN_IE, 140,
    ATM_CV_INVALID_IE, 140,
    ATM_CV_UCR_UNAVAIL_OLD, 141,
    ATM_CV_UCR_UNAVAIL_NEW, 141,
    ATM_CV_NO_SUCH_CHAN, 142,
    ATM_CV_UNKNOWN_MSG_TYPE, 143,
    ATM_CV_INCOMP_MSG, 143,
    ATM_CV_TIMER_EXP, 144,
    0, 145,
    -2, 145,
    -1, -1
};

static int values_109[] = { /* reason */
    ATM_RSN_USER, 136,
    ATM_RSN_IE_MISS, 137,
    ATM_RSN_IE_INSUFF, 137,
    -1, -1
};

static int values_122[] = { /* cause */
    ATM_CV_UNALLOC, 147,
    ATM_CV_NO_ROUTE_DEST, 147,
    ATM_CV_QOS_UNAVAIL, 147,
    ATM_CV_CALL_REJ, 148,
    ATM_CV_NUM_CHANGED, 151,
    ATM_CV_REJ_CLIR, 152,
    ATM_CV_ACC_INF_DISC, 153,
    ATM_CV_INCOMP_DEST, 153,
    ATM_CV_MAND_IE_MISSING, 153,
    ATM_CV_UNKNOWN_IE, 153,
    ATM_CV_INVALID_IE, 153,
    ATM_CV_UCR_UNAVAIL_OLD, 154,
    ATM_CV_UCR_UNAVAIL_NEW, 154,
    ATM_CV_NO_SUCH_CHAN, 155,
    ATM_CV_UNKNOWN_MSG_TYPE, 156,
    ATM_CV_INCOMP_MSG, 156,
    ATM_CV_TIMER_EXP, 157,
    0, 158,
    -2, 158,
    -1, -1
};

static int values_127[] = { /* reason */
    ATM_RSN_USER, 149,
    ATM_RSN_IE_MISS, 150,
    ATM_RSN_IE_INSUFF, 150,
    -1, -1
};

static int values_155[] = { /* id_std_app */
    ATM_IRS_DSMCC, 172,
    ATM_IRS_H245, 172,
    0, 173,
    -2, 173,
    -1, -1
};

static int values_159[] = { /* id_std_app */
    ATM_IRS_DSMCC, 175,
    ATM_IRS_H245, 175,
    0, 176,
    -2, 176,
    -1, -1
};

static int values_163[] = { /* id_std_app */
    ATM_IRS_DSMCC, 178,
    ATM_IRS_H245, 178,
    0, 179,
    -2, 179,
    -1, -1
};


/*
 * Various information about fields.
 */

typedef struct {
    int parent;
    int pos,size;
    int *values;
    int actual;
} FIELD;

static FIELD fields[] = {
    { 0, 16, 24, NULL, -1 }, /* call_ref */
    { 0, 40, 8, NULL, -1 }, /* msg_type */
    { 0, 56, 16, NULL, -1 }, /* msg_len */
    { 1, 104, 8, values_3, -1 }, /* aal_type */
    { 3, 120, 16, NULL, -1 }, /* fw_max_sdu */
    { 4, 144, 16, NULL, -1 }, /* bw_max_sdu */
    { 5, 168, 8, NULL, -1 }, /* aal_mode */
    { 6, 184, 8, NULL, -1 }, /* sscs_type */
    { 8, 232, 24, NULL, -1 }, /* fw_pcr_0 */
    { 9, 264, 24, NULL, -1 }, /* bw_pcr_0 */
    { 10, 296, 24, NULL, -1 }, /* fw_pcr_01 */
    { 11, 328, 24, NULL, -1 }, /* bw_pcr_01 */
    { 12, 360, 24, NULL, -1 }, /* fw_scr_0 */
    { 13, 392, 24, NULL, -1 }, /* bw_scr_0 */
    { 14, 424, 24, NULL, -1 }, /* fw_scr_01 */
    { 15, 456, 24, NULL, -1 }, /* bw_scr_01 */
    { 16, 488, 24, NULL, -1 }, /* fw_mbs_0 */
    { 17, 520, 24, NULL, -1 }, /* bw_mbs_0 */
    { 18, 552, 24, NULL, -1 }, /* fw_mbs_01 */
    { 19, 584, 24, NULL, -1 }, /* bw_mbs_01 */
    { 20, 616, 0, NULL, -1 }, /* best_effort */
    { 21, 631, 1, NULL, -1 }, /* fw_fdisc */
    { 21, 630, 1, NULL, -1 }, /* bw_fdisc */
    { 21, 625, 1, NULL, -1 }, /* bw_tag */
    { 21, 624, 1, NULL, -1 }, /* fw_tag */
    { 22, 664, 5, NULL, -1 }, /* bearer_class */
    { 23, 672, 7, NULL, -1 }, /* trans_cap */
    { 22, 693, 2, NULL, -1 }, /* susc_clip */
    { 22, 688, 2, NULL, -1 }, /* upcc */
    { 25, 728, 7, values_29, -1 }, /* hli_type */
    { 26, 736, 64, NULL, 0 }, /* iso_hli */
    { 27, 800, 64, NULL, 1 }, /* user_hli */
    { 28, 864, 32, NULL, -1 }, /* hlp */
    { 29, 896, 24, NULL, -1 }, /* hli_oui */
    { 29, 920, 32, NULL, -1 }, /* app_id */
    { 30, 952, 8, NULL, -1 }, /* tobedefined */
    { 32, 992, 5, NULL, -1 }, /* uil1_proto */
    { 33, 1000, 5, values_37, -1 }, /* uil2_proto */
    { 35, 1013, 2, NULL, -1 }, /* l2_mode */
    { 35, 1008, 2, NULL, -1 }, /* q933 */
    { 36, 1016, 7, NULL, -1 }, /* window_size */
    { 39, 1048, 7, NULL, -1 }, /* user_l2 */
    { 41, 1064, 5, values_42, -1 }, /* uil3_proto */
    { 43, 1077, 2, NULL, -1 }, /* l3_mode */
    { 44, 1080, 4, NULL, -1 }, /* def_pck_size */
    { 45, 1096, 7, NULL, -1 }, /* pck_win_size */
    { 50, 1136, 4, NULL, -1 }, /* term_type */
    { 51, 1147, 3, NULL, -1 }, /* fw_mpx_cap */
    { 51, 1144, 3, NULL, -1 }, /* bw_mpx_cap */
    { 55, 1176, 7, values_49, -1 }, /* ipi_high */
    { 57, 1200, 24, NULL, -1 }, /* oui */
    { 57, 1224, 16, NULL, -1 }, /* pid */
    { 59, 1254, 1, NULL, -1 }, /* ipi_low */
    { 61, 1272, 7, NULL, -1 }, /* user_l3 */
    { 63, 1312, 5, NULL, -1 }, /* uil1_proto */
    { 64, 1320, 5, values_55, -1 }, /* uil2_proto */
    { 66, 1333, 2, NULL, -1 }, /* l2_mode */
    { 66, 1328, 2, NULL, -1 }, /* q933 */
    { 67, 1336, 7, NULL, -1 }, /* window_size */
    { 70, 1368, 7, NULL, -1 }, /* user_l2 */
    { 72, 1384, 5, values_60, -1 }, /* uil3_proto */
    { 74, 1397, 2, NULL, -1 }, /* l3_mode */
    { 75, 1400, 4, NULL, -1 }, /* def_pck_size */
    { 76, 1416, 7, NULL, -1 }, /* pck_win_size */
    { 81, 1456, 4, NULL, -1 }, /* term_type */
    { 82, 1467, 3, NULL, -1 }, /* fw_mpx_cap */
    { 82, 1464, 3, NULL, -1 }, /* bw_mpx_cap */
    { 86, 1496, 7, values_67, -1 }, /* ipi_high */
    { 88, 1520, 24, NULL, -1 }, /* oui */
    { 88, 1544, 16, NULL, -1 }, /* pid */
    { 90, 1574, 1, NULL, -1 }, /* ipi_low */
    { 92, 1592, 7, NULL, -1 }, /* user_l3 */
    { 94, 1632, 5, NULL, -1 }, /* uil1_proto */
    { 95, 1640, 5, values_73, -1 }, /* uil2_proto */
    { 97, 1653, 2, NULL, -1 }, /* l2_mode */
    { 97, 1648, 2, NULL, -1 }, /* q933 */
    { 98, 1656, 7, NULL, -1 }, /* window_size */
    { 101, 1688, 7, NULL, -1 }, /* user_l2 */
    { 103, 1704, 5, values_78, -1 }, /* uil3_proto */
    { 105, 1717, 2, NULL, -1 }, /* l3_mode */
    { 106, 1720, 4, NULL, -1 }, /* def_pck_size */
    { 107, 1736, 7, NULL, -1 }, /* pck_win_size */
    { 112, 1776, 4, NULL, -1 }, /* term_type */
    { 113, 1787, 3, NULL, -1 }, /* fw_mpx_cap */
    { 113, 1784, 3, NULL, -1 }, /* bw_mpx_cap */
    { 117, 1816, 7, values_85, -1 }, /* ipi_high */
    { 119, 1840, 24, NULL, -1 }, /* oui */
    { 119, 1864, 16, NULL, -1 }, /* pid */
    { 121, 1894, 1, NULL, -1 }, /* ipi_low */
    { 123, 1912, 7, NULL, -1 }, /* user_l3 */
    { 124, 1952, 6, NULL, -1 }, /* call_state */
    { 126, 2000, 96, NULL, 2 }, /* cdpn_e164 */
    { 127, 2104, 160, NULL, 3 }, /* cdpn_esa */
    { 128, 2300, 3, NULL, -1 }, /* cdps_type */
    { 128, 2304, 160, NULL, 4 }, /* cdps */
    { 129, 2496, 4, NULL, -1 }, /* cgpn_plan */
    { 129, 2500, 3, NULL, -1 }, /* cgpn_type */
    { 130, 2509, 2, NULL, -1 }, /* pres_ind */
    { 130, 2504, 2, NULL, -1 }, /* scr_ind */
    { 129, 2520, 160, NULL, 5 }, /* cgpn */
    { 132, 2716, 3, NULL, -1 }, /* cgps_type */
    { 132, 2720, 160, NULL, 6 }, /* cgps */
    { 133, 2893, 2, NULL, -1 }, /* cause_cs */
    { 133, 2912, 4, NULL, -1 }, /* location */
    { 133, 2920, 7, values_104, -1 }, /* cause */
    { 134, 2931, 1, NULL, -1 }, /* pu */
    { 134, 2930, 1, NULL, -1 }, /* na */
    { 134, 2928, 2, NULL, -1 }, /* cond2 */
    { 135, 2936, 2, NULL, -1 }, /* cond3 */
    { 135, 2938, 5, values_109, -1 }, /* reason */
    { 136, 2944, 216, NULL, 7 }, /* user_diag */
    { 137, 3160, 8, NULL, -1 }, /* ie_id3 */
    { 138, 3168, 224, NULL, 8 }, /* new_dest */
    { 139, 3392, 8, NULL, -1 }, /* invalid */
    { 140, 3400, 224, NULL, 9 }, /* ie_id6 */
    { 141, 3624, 224, NULL, 10 }, /* ucr_id */
    { 142, 3848, 16, NULL, -1 }, /* unav_vpci */
    { 142, 3864, 16, NULL, -1 }, /* unav_vci */
    { 143, 3880, 8, NULL, -1 }, /* bad_msg_type */
    { 144, 3888, 24, NULL, -1 }, /* timer */
    { 146, 3925, 2, NULL, -1 }, /* cause_cs */
    { 146, 3944, 4, NULL, -1 }, /* location */
    { 146, 3952, 7, values_122, -1 }, /* cause */
    { 147, 3963, 1, NULL, -1 }, /* pu */
    { 147, 3962, 1, NULL, -1 }, /* na */
    { 147, 3960, 2, NULL, -1 }, /* cond2 */
    { 148, 3968, 2, NULL, -1 }, /* cond3 */
    { 148, 3970, 5, values_127, -1 }, /* reason */
    { 149, 3976, 216, NULL, 11 }, /* user_diag */
    { 150, 4192, 8, NULL, -1 }, /* ie_id3 */
    { 151, 4200, 224, NULL, 12 }, /* new_dest */
    { 152, 4424, 8, NULL, -1 }, /* invalid */
    { 153, 4432, 224, NULL, 13 }, /* ie_id6 */
    { 154, 4656, 224, NULL, 14 }, /* ucr_id */
    { 155, 4880, 16, NULL, -1 }, /* unav_vpci */
    { 155, 4896, 16, NULL, -1 }, /* unav_vci */
    { 156, 4912, 8, NULL, -1 }, /* bad_msg_type */
    { 157, 4920, 24, NULL, -1 }, /* timer */
    { 159, 4984, 16, NULL, -1 }, /* vpi */
    { 159, 5000, 16, NULL, -1 }, /* vci */
    { 161, 5056, 16, NULL, -1 }, /* cum_delay */
    { 162, 5080, 16, NULL, -1 }, /* max_delay */
    { 164, 5117, 2, NULL, -1 }, /* qos_cs */
    { 164, 5136, 8, NULL, -1 }, /* qos_fw */
    { 164, 5144, 8, NULL, -1 }, /* qos_bw */
    { 165, 5184, 4, NULL, -1 }, /* rep_ind */
    { 166, 5224, 3, NULL, -1 }, /* rst_class */
    { 167, 5264, 7, NULL, -1 }, /* bbsc_ind */
    { 168, 5312, 32, NULL, 15 }, /* net_id */
    { 169, 5376, 32, NULL, 16 }, /* notification */
    { 170, 5445, 2, NULL, -1 }, /* shaping */
    { 170, 5444, 1, NULL, -1 }, /* compliance */
    { 170, 5440, 3, NULL, -1 }, /* fault */
    { 170, 5452, 3, NULL, -1 }, /* fwd_ofi */
    { 170, 5448, 3, NULL, -1 }, /* bwd_ofi */
    { 171, 5496, 7, values_155, -1 }, /* id_std_app */
    { 172, 5520, 160, NULL, 17 }, /* session_id */
    { 172, 5696, 32, NULL, 18 }, /* resource_id */
    { 173, 5728, 224, NULL, 19 }, /* unrecognized_git_identifiers */
    { 174, 5992, 7, values_159, -1 }, /* id_std_app */
    { 175, 6016, 160, NULL, 20 }, /* session_id */
    { 175, 6192, 32, NULL, 21 }, /* resource_id */
    { 176, 6224, 224, NULL, 22 }, /* unrecognized_git_identifiers */
    { 177, 6488, 7, values_163, -1 }, /* id_std_app */
    { 178, 6512, 160, NULL, 23 }, /* session_id */
    { 178, 6688, 32, NULL, 24 }, /* resource_id */
    { 179, 6720, 224, NULL, 25 }, /* unrecognized_git_identifiers */
    { 180, 6976, 7, NULL, -1 }, /* lij_id_type */
    { 180, 6984, 32, NULL, -1 }, /* lij_id */
    { 181, 7048, 2, NULL, -1 }, /* lij_scr_ind */
    { 182, 7088, 32, NULL, -1 }, /* leaf_sn */
    { 183, 7152, 4, NULL, -1 }, /* scope_type */
    { 183, 7160, 8, NULL, -1 }, /* scope_sel */
    { 185, 7208, 24, NULL, -1 }, /* altfw_pcr_0 */
    { 186, 7240, 24, NULL, -1 }, /* altbw_pcr_0 */
    { 187, 7272, 24, NULL, -1 }, /* altfw_pcr_01 */
    { 188, 7304, 24, NULL, -1 }, /* altbw_pcr_01 */
    { 189, 7336, 24, NULL, -1 }, /* altfw_scr_0 */
    { 190, 7368, 24, NULL, -1 }, /* altbw_scr_0 */
    { 191, 7400, 24, NULL, -1 }, /* altfw_scr_01 */
    { 192, 7432, 24, NULL, -1 }, /* altbw_scr_01 */
    { 193, 7464, 24, NULL, -1 }, /* altfw_mbs_0 */
    { 194, 7496, 24, NULL, -1 }, /* altbw_mbs_0 */
    { 195, 7528, 24, NULL, -1 }, /* altfw_mbs_01 */
    { 196, 7560, 24, NULL, -1 }, /* altbw_mbs_01 */
    { 197, 7592, 0, NULL, -1 }, /* altbest_effort */
    { 199, 7632, 24, NULL, -1 }, /* minfw_pcr_0 */
    { 200, 7664, 24, NULL, -1 }, /* minbw_pcr_0 */
    { 201, 7696, 24, NULL, -1 }, /* minfw_pcr_01 */
    { 202, 7728, 24, NULL, -1 }, /* minbw_pcr_01 */
    { 203, 7760, 24, NULL, -1 }, /* minfw_mcr_01 */
    { 204, 7792, 24, NULL, -1 }, /* minbw_mcr_01 */
    { 205, 7848, 8, NULL, -1 }, /* eqos_origin */
    { 206, 7864, 24, NULL, -1 }, /* acc_fw_cdv */
    { 207, 7896, 24, NULL, -1 }, /* acc_bw_cdv */
    { 208, 7928, 24, NULL, -1 }, /* cum_fw_cdv */
    { 209, 7960, 24, NULL, -1 }, /* cum_bw_cdv */
    { 210, 7992, 8, NULL, -1 }, /* acc_fw_clr */
    { 211, 8008, 8, NULL, -1 }, /* acc_bw_clr */
    { 213, 8056, 32, NULL, -1 }, /* abr_fw_add_rec */
    { 214, 8096, 32, NULL, -1 }, /* abr_bw_add_rec */
    { 216, 8168, 24, NULL, -1 }, /* abr_fw_icr */
    { 217, 8200, 24, NULL, -1 }, /* abr_bw_icr */
    { 218, 8232, 24, NULL, -1 }, /* abr_fw_tbe */
    { 219, 8264, 24, NULL, -1 }, /* abr_bw_tbe */
    { 220, 8296, 24, NULL, -1 }, /* atm_crf_rtt */
    { 221, 8328, 8, NULL, -1 }, /* atm_fw_rif */
    { 222, 8344, 8, NULL, -1 }, /* atm_bw_rif */
    { 223, 8360, 8, NULL, -1 }, /* atm_fw_rdf */
    { 224, 8376, 8, NULL, -1 }, /* atm_bw_rdf */
    { 225, 8424, 16, NULL, -1 }, /* ep_ref */
    { 226, 8472, 6, NULL, -1 }, /* ep_state */
    { 227, 8512, 8, NULL, -1 }, /* type_of_report */
};


/*
 * "Microcode" used to parse messages. It detects the
 * presence of fields and copies them from the message to the
 * construction area.
 */

static int parse[] = {
    OP_DUMP, 0,
/*   2*/    OP_COPY, 1, 0, 8, /* _pdsc */
/*   6*/    OP_DUMP, 1,
/*   8*/    OP_COPY, 1, 8, 8, /* _cr_len */
/*  12*/    OP_DUMP, 2,
/*  14*/    OP_COPY, 3, 16, 24, /* call_ref */
/*  18*/    OP_DUMP, 3,
/*  20*/    OP_COPY, 1, 40, 8, /* msg_type */
/*  24*/    OP_DUMP, 4,
/*  26*/    OP_COPY, 0, 55, 1, /* _ext */
/*  30*/    OP_DUMP, 5,
/*  32*/    OP_COPY, 0, 52, 1, /* _flag */
/*  36*/    OP_DUMP, 6,
/*  38*/    OP_COPY, 1, 48, 2, /* _action_ind */
/*  42*/    OP_DUMP, 7,
/*  44*/    OP_BEGIN_LEN, 2, 56, 16, /* msg_len */
/*  48*/    OP_IFEND, 5021, /* _ie_id */
/*  50*/    OP_DUMP, 8,
/*  52*/    OP_COPY, 0, 0, 8, /* _ie_id */
/*  56*/    OP_CASE, 1, 0, 8, 39, /* _ie_id */
/*  61*/    ATM_IE_AAL, 1, 114,
/*  64*/    ATM_IE_TD, 7, 220,
/*  67*/    ATM_IE_BBCAP, 22, 438,
/*  70*/    ATM_IE_BHLI, 25, 528,
/*  73*/    ATM_IE_BLLI, 31, 639,
/*  76*/    ATM_IE_BLLI, 62, 1155,
/*  79*/    ATM_IE_BLLI, 93, 1671,
/*  82*/    ATM_IE_CALL_STATE, 124, 2187,
/*  85*/    ATM_IE_CDPN, 125, 2228,
/*  88*/    ATM_IE_CDPS, 128, 2312,
/*  91*/    ATM_IE_CGPN, 129, 2371,
/*  94*/    ATM_IE_CGPS, 132, 2461,
/*  97*/    ATM_IE_CAUSE, 133, 2520,
/* 100*/    ATM_IE_CAUSE, 146, 2792,
/* 103*/    ATM_IE_CONN_ID, 159, 3064,
/* 106*/    ATM_IE_E2E_TDL, 160, 3129,
/* 109*/    ATM_IE_QOS, 164, 3204,
/* 112*/    ATM_IE_BBREP, 165, 3251,
/* 115*/    ATM_IE_RESTART, 166, 3298,
/* 118*/    ATM_IE_BBS_COMP, 167, 3345,
/* 121*/    ATM_IE_TNS, 168, 3392,
/* 124*/    ATM_IE_NOTIFY, 169, 3451,
/* 127*/    ATM_IE_OAM_TD, 170, 3492,
/* 130*/    ATM_IE_GIT, 171, 3569,
/* 133*/    ATM_IE_GIT, 174, 3676,
/* 136*/    ATM_IE_GIT, 177, 3783,
/* 139*/    ATM_IE_LIJ_ID, 180, 3890,
/* 142*/    ATM_IE_LIJ_PRM, 181, 3943,
/* 145*/    ATM_IE_LEAF_SN, 182, 3990,
/* 148*/    ATM_IE_SCOPE_SEL, 183, 4031,
/* 151*/    ATM_IE_ALT_TD, 184, 4084,
/* 154*/    ATM_IE_MIN_TD, 198, 4273,
/* 157*/    ATM_IE_EQOS, 205, 4387,
/* 160*/    ATM_IE_ABR_ADD_PRM, 212, 4507,
/* 163*/    ATM_IE_ABR_SET_PRM, 215, 4577,
/* 166*/    ATM_IE_EPR, 225, 4724,
/* 169*/    ATM_IE_EP_STATE, 226, 4771,
/* 172*/    ATM_IE_BBRT, 227, 4812,
/* 175*/    -1, 228, 4853,
/* 178*/    OP_DUMP, 9,
/* 180*/    OP_COPY, 0, 87, 1, /* _ext */
/* 184*/    OP_DUMP, 10,
/* 186*/    OP_COPY, 0, 85, 2, /* _cs */
/* 190*/    OP_DUMP, 11,
/* 192*/    OP_COPY, 0, 84, 1, /* _flag */
/* 196*/    OP_DUMP, 12,
/* 198*/    OP_COPY, 1, 80, 3, /* _action_ind */
/* 202*/    OP_DUMP, 13,
/* 204*/    OP_BEGIN_LEN, 2, 88, 16, /* _ie_len */
/* 208*/    OP_BEGIN_REC, RECOV_IND_IE, 1, 284,
/* 212*/    OP_DUMP, 14,
/* 214*/    OP_COPY, 0, 104, 8, /* aal_type */
/* 218*/    OP_CASE, 1, 104, 8, 1, /* aal_type */
/* 223*/    5, 2, 0,
/* 226*/    OP_IFEND, 55, /* _id */
/* 228*/    OP_DUMP, 15,
/* 230*/    OP_COPY, 0, 0, 8, /* _id */
/* 234*/    OP_CASE, 1, 0, 8, 4, /* _id */
/* 239*/    ATM_AALP_FW_MAX_SDU, 3, 9,
/* 242*/    ATM_AALP_BW_MAX_SDU, 4, 14,
/* 245*/    ATM_AALP_AAL_MODE, 5, 19,
/* 248*/    ATM_AALP_SSCS, 6, 24,
/* 251*/    OP_DUMP, 16,
/* 253*/    OP_COPY, 2, 120, 16, /* fw_max_sdu */
/* 257*/    OP_JUMP, 22,
/* 259*/    OP_DUMP, 17,
/* 261*/    OP_COPY, 2, 144, 16, /* bw_max_sdu */
/* 265*/    OP_JUMP, 14,
/* 267*/    OP_DUMP, 18,
/* 269*/    OP_COPY, 1, 168, 8, /* aal_mode */
/* 273*/    OP_JUMP, 6,
/* 275*/    OP_DUMP, 19,
/* 277*/    OP_COPY, 1, 184, 8, /* sscs_type */
/* 281*/    OP_JUMP, -57,
/* 283*/    OP_END_REC,
/* 284*/    OP_END_LEN,  /* _ie_len */
/* 285*/    OP_JUMP, 4782,
/* 287*/    OP_DUMP, 20,
/* 289*/    OP_COPY, 0, 207, 1, /* _ext */
/* 293*/    OP_DUMP, 21,
/* 295*/    OP_COPY, 0, 205, 2, /* _cs */
/* 299*/    OP_DUMP, 22,
/* 301*/    OP_COPY, 0, 204, 1, /* _flag */
/* 305*/    OP_DUMP, 23,
/* 307*/    OP_COPY, 1, 200, 3, /* _action_ind */
/* 311*/    OP_DUMP, 24,
/* 313*/    OP_BEGIN_LEN, 2, 208, 16, /* _ie_len */
/* 317*/    OP_BEGIN_REC, RECOV_IND_IE, 7, 505,
/* 321*/    OP_IFEND, 181, /* _id */
/* 323*/    OP_DUMP, 25,
/* 325*/    OP_COPY, 0, 0, 8, /* _id */
/* 329*/    OP_CASE, 1, 0, 8, 14, /* _id */
/* 334*/    ATM_TD_FW_PCR_0, 8, 39,
/* 337*/    ATM_TD_BW_PCR_0, 9, 44,
/* 340*/    ATM_TD_FW_PCR_01, 10, 49,
/* 343*/    ATM_TD_BW_PCR_01, 11, 54,
/* 346*/    ATM_TD_FW_SCR_0, 12, 59,
/* 349*/    ATM_TD_BW_SCR_0, 13, 64,
/* 352*/    ATM_TD_FW_SCR_01, 14, 69,
/* 355*/    ATM_TD_BW_SCR_01, 15, 74,
/* 358*/    ATM_TD_FW_MBS_0, 16, 79,
/* 361*/    ATM_TD_BW_MBS_0, 17, 84,
/* 364*/    ATM_TD_FW_MBS_01, 18, 89,
/* 367*/    ATM_TD_BW_MBS_01, 19, 94,
/* 370*/    ATM_TD_BEST_EFFORT, 20, 99,
/* 373*/    ATM_TD_TM_OPT, 21, 102,
/* 376*/    OP_DUMP, 26,
/* 378*/    OP_COPY, 3, 232, 24, /* fw_pcr_0 */
/* 382*/    OP_JUMP, 118,
/* 384*/    OP_DUMP, 27,
/* 386*/    OP_COPY, 3, 264, 24, /* bw_pcr_0 */
/* 390*/    OP_JUMP, 110,
/* 392*/    OP_DUMP, 28,
/* 394*/    OP_COPY, 3, 296, 24, /* fw_pcr_01 */
/* 398*/    OP_JUMP, 102,
/* 400*/    OP_DUMP, 29,
/* 402*/    OP_COPY, 3, 328, 24, /* bw_pcr_01 */
/* 406*/    OP_JUMP, 94,
/* 408*/    OP_DUMP, 30,
/* 410*/    OP_COPY, 3, 360, 24, /* fw_scr_0 */
/* 414*/    OP_JUMP, 86,
/* 416*/    OP_DUMP, 31,
/* 418*/    OP_COPY, 3, 392, 24, /* bw_scr_0 */
/* 422*/    OP_JUMP, 78,
/* 424*/    OP_DUMP, 32,
/* 426*/    OP_COPY, 3, 424, 24, /* fw_scr_01 */
/* 430*/    OP_JUMP, 70,
/* 432*/    OP_DUMP, 33,
/* 434*/    OP_COPY, 3, 456, 24, /* bw_scr_01 */
/* 438*/    OP_JUMP, 62,
/* 440*/    OP_DUMP, 34,
/* 442*/    OP_COPY, 3, 488, 24, /* fw_mbs_0 */
/* 446*/    OP_JUMP, 54,
/* 448*/    OP_DUMP, 35,
/* 450*/    OP_COPY, 3, 520, 24, /* bw_mbs_0 */
/* 454*/    OP_JUMP, 46,
/* 456*/    OP_DUMP, 36,
/* 458*/    OP_COPY, 3, 552, 24, /* fw_mbs_01 */
/* 462*/    OP_JUMP, 38,
/* 464*/    OP_DUMP, 37,
/* 466*/    OP_COPY, 3, 584, 24, /* bw_mbs_01 */
/* 470*/    OP_JUMP, 30,
/* 472*/    OP_COPY, 0, 616, 0, /* best_effort */
/* 476*/    OP_JUMP, 24,
/* 478*/    OP_DUMP, 39,
/* 480*/    OP_COPY, 0, 631, 1, /* fw_fdisc */
/* 484*/    OP_DUMP, 40,
/* 486*/    OP_COPY, 0, 630, 1, /* bw_fdisc */
/* 490*/    OP_DUMP, 41,
/* 492*/    OP_COPY, 0, 625, 1, /* bw_tag */
/* 496*/    OP_DUMP, 42,
/* 498*/    OP_COPY, 1, 624, 1, /* fw_tag */
/* 502*/    OP_JUMP, -183,
/* 504*/    OP_END_REC,
/* 505*/    OP_END_LEN,  /* _ie_len */
/* 506*/    OP_JUMP, 4561,
/* 508*/    OP_DUMP, 43,
/* 510*/    OP_COPY, 0, 647, 1, /* _ext */
/* 514*/    OP_DUMP, 44,
/* 516*/    OP_COPY, 0, 645, 2, /* _cs */
/* 520*/    OP_DUMP, 45,
/* 522*/    OP_COPY, 0, 644, 1, /* _flag */
/* 526*/    OP_DUMP, 46,
/* 528*/    OP_COPY, 1, 640, 3, /* _action_ind */
/* 532*/    OP_DUMP, 47,
/* 534*/    OP_BEGIN_LEN, 2, 648, 16, /* _ie_len */
/* 538*/    OP_BEGIN_REC, RECOV_IND_IE, 22, 598,
/* 542*/    OP_DUMP, 48,
/* 544*/    OP_COPY, 0, 664, 5, /* bearer_class */
/* 548*/    OP_DUMP, 49,
/* 550*/    OP_COPY, 0, 7, 1, /* _ext */
/* 554*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 559*/    0, 23, 3,
/* 562*/    -1, 24, 14,
/* 565*/    OP_DUMP, 50,
/* 567*/    OP_COPY, 0, 679, 1, /* _ext */
/* 571*/    OP_DUMP, 51,
/* 573*/    OP_COPY, 1, 672, 7, /* trans_cap */
/* 577*/    OP_JUMP, 0,
/* 579*/    OP_DUMP, 52,
/* 581*/    OP_COPY, 0, 695, 1, /* _ext */
/* 585*/    OP_DUMP, 53,
/* 587*/    OP_COPY, 0, 693, 2, /* susc_clip */
/* 591*/    OP_DUMP, 54,
/* 593*/    OP_COPY, 1, 688, 2, /* upcc */
/* 597*/    OP_END_REC,
/* 598*/    OP_END_LEN,  /* _ie_len */
/* 599*/    OP_JUMP, 4468,
/* 601*/    OP_DUMP, 55,
/* 603*/    OP_COPY, 0, 711, 1, /* _ext */
/* 607*/    OP_DUMP, 56,
/* 609*/    OP_COPY, 0, 709, 2, /* _cs */
/* 613*/    OP_DUMP, 57,
/* 615*/    OP_COPY, 0, 708, 1, /* _flag */
/* 619*/    OP_DUMP, 58,
/* 621*/    OP_COPY, 1, 704, 3, /* _action_ind */
/* 625*/    OP_DUMP, 59,
/* 627*/    OP_BEGIN_LEN, 2, 712, 16, /* _ie_len */
/* 631*/    OP_BEGIN_REC, RECOV_IND_IE, 25, 712,
/* 635*/    OP_DUMP, 60,
/* 637*/    OP_COPY, 0, 735, 1, /* _ext */
/* 641*/    OP_DUMP, 61,
/* 643*/    OP_COPY, 0, 728, 7, /* hli_type */
/* 647*/    OP_CASE, 1, 728, 7, 5, /* hli_type */
/* 652*/    0, 26, 12,
/* 655*/    1, 27, 17,
/* 658*/    2, 28, 22,
/* 661*/    3, 29, 27,
/* 664*/    4, 30, 38,
/* 667*/    OP_DUMP, 62,
/* 669*/    OP_COPYVAR, 0, 736, 8, /* iso_hli */
/* 673*/    OP_JUMP, 36,
/* 675*/    OP_DUMP, 63,
/* 677*/    OP_COPYVAR, 1, 800, 8, /* user_hli */
/* 681*/    OP_JUMP, 28,
/* 683*/    OP_DUMP, 64,
/* 685*/    OP_COPY, 4, 864, 32, /* hlp */
/* 689*/    OP_JUMP, 20,
/* 691*/    OP_DUMP, 65,
/* 693*/    OP_COPY, 3, 896, 24, /* hli_oui */
/* 697*/    OP_DUMP, 66,
/* 699*/    OP_COPY, 4, 920, 32, /* app_id */
/* 703*/    OP_JUMP, 6,
/* 705*/    OP_DUMP, 67,
/* 707*/    OP_COPY, 1, 952, 8, /* tobedefined */
/* 711*/    OP_END_REC,
/* 712*/    OP_END_LEN,  /* _ie_len */
/* 713*/    OP_JUMP, 4354,
/* 715*/    OP_DUMP, 68,
/* 717*/    OP_COPY, 0, 975, 1, /* _ext */
/* 721*/    OP_DUMP, 69,
/* 723*/    OP_COPY, 0, 973, 2, /* _cs */
/* 727*/    OP_DUMP, 70,
/* 729*/    OP_COPY, 0, 972, 1, /* _flag */
/* 733*/    OP_DUMP, 71,
/* 735*/    OP_COPY, 1, 968, 3, /* _action_ind */
/* 739*/    OP_DUMP, 72,
/* 741*/    OP_BEGIN_LEN, 2, 976, 16, /* _ie_len */
/* 745*/    OP_BEGIN_REC, RECOV_IND_IE, 31, 1231,
/* 749*/    OP_IFEND, 479, /* _lid */
/* 751*/    OP_DUMP, 73,
/* 753*/    OP_COPY, 0, 5, 2, /* _lid */
/* 757*/    OP_CASE, 0, 5, 2, 3, /* _lid */
/* 762*/    1, 32, 6,
/* 765*/    2, 33, 17,
/* 768*/    3, 41, 156,
/* 771*/    OP_DUMP, 74,
/* 773*/    OP_COPY, 0, 999, 1, /* _ext */
/* 777*/    OP_DUMP, 75,
/* 779*/    OP_COPY, 1, 992, 5, /* uil1_proto */
/* 783*/    OP_JUMP, 443,
/* 785*/    OP_DUMP, 76,
/* 787*/    OP_COPY, 0, 1000, 5, /* uil2_proto */
/* 791*/    OP_CASE, 0, 1000, 5, 13, /* uil2_proto */
/* 796*/    ATM_L2_X25_LL, 34, 36,
/* 799*/    ATM_L2_X25_ML, 34, 33,
/* 802*/    ATM_L2_HDLC_ARM, 34, 30,
/* 805*/    ATM_L2_HDLC_NRM, 34, 27,
/* 808*/    ATM_L2_HDLC_ABM, 34, 24,
/* 811*/    ATM_L2_Q922, 34, 21,
/* 814*/    ATM_L2_ISO7776, 34, 18,
/* 817*/    ATM_L2_USER, 39, 79,
/* 820*/    -1, 40, 96,
/* 823*/    ATM_L2_Q291, 40, 93,
/* 826*/    ATM_L2_LAPB, 40, 90,
/* 829*/    ATM_L2_ISO8802, 40, 87,
/* 832*/    ATM_L2_X75, 40, 84,
/* 835*/    OP_DUMP, 77,
/* 837*/    OP_COPY, 0, 7, 1, /* _ext */
/* 841*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 846*/    0, 35, 3,
/* 849*/    -1, 38, 45,
/* 852*/    OP_DUMP, 78,
/* 854*/    OP_COPY, 0, 1013, 2, /* l2_mode */
/* 858*/    OP_DUMP, 79,
/* 860*/    OP_COPY, 0, 1008, 2, /* q933 */
/* 864*/    OP_DUMP, 80,
/* 866*/    OP_COPY, 0, 7, 1, /* _ext */
/* 870*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 875*/    0, 36, 3,
/* 878*/    -1, 37, 14,
/* 881*/    OP_DUMP, 81,
/* 883*/    OP_COPY, 0, 1016, 7, /* window_size */
/* 887*/    OP_DUMP, 82,
/* 889*/    OP_COPY, 1, 1023, 1, /* _ext */
/* 893*/    OP_JUMP, 0,
/* 895*/    OP_JUMP, 0,
/* 897*/    OP_JUMP, 26,
/* 899*/    OP_DUMP, 83,
/* 901*/    OP_COPY, 1, 1047, 1, /* _ext */
/* 905*/    OP_DUMP, 84,
/* 907*/    OP_COPY, 0, 1048, 7, /* user_l2 */
/* 911*/    OP_DUMP, 85,
/* 913*/    OP_COPY, 1, 1055, 1, /* _ext */
/* 917*/    OP_JUMP, 6,
/* 919*/    OP_DUMP, 86,
/* 921*/    OP_COPY, 1, 1063, 1, /* _ext */
/* 925*/    OP_JUMP, 301,
/* 927*/    OP_DUMP, 87,
/* 929*/    OP_COPY, 0, 1064, 5, /* uil3_proto */
/* 933*/    OP_CASE, 0, 1064, 5, 6, /* uil3_proto */
/* 938*/    ATM_L3_X25, 42, 15,
/* 941*/    ATM_L3_ISO8208, 42, 12,
/* 944*/    ATM_L3_X223, 42, 9,
/* 947*/    ATM_L3_H310, 49, 89,
/* 950*/    ATM_L3_TR9577, 54, 150,
/* 953*/    ATM_L3_USER, 61, 254,
/* 956*/    OP_DUMP, 88,
/* 958*/    OP_COPY, 0, 7, 1, /* _ext */
/* 962*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 967*/    0, 43, 3,
/* 970*/    -1, 48, 64,
/* 973*/    OP_DUMP, 89,
/* 975*/    OP_COPY, 0, 1077, 2, /* l3_mode */
/* 979*/    OP_DUMP, 90,
/* 981*/    OP_COPY, 0, 7, 1, /* _ext */
/* 985*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 990*/    0, 44, 3,
/* 993*/    -1, 47, 39,
/* 996*/    OP_DUMP, 91,
/* 998*/    OP_COPY, 0, 1080, 4, /* def_pck_size */
/*1002*/    OP_DUMP, 92,
/*1004*/    OP_COPY, 0, 7, 1, /* _ext */
/*1008*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1013*/    0, 45, 3,
/*1016*/    -1, 46, 14,
/*1019*/    OP_DUMP, 93,
/*1021*/    OP_COPY, 1, 1095, 1, /* _ext */
/*1025*/    OP_DUMP, 94,
/*1027*/    OP_COPY, 1, 1096, 7, /* pck_win_size */
/*1031*/    OP_JUMP, 0,
/*1033*/    OP_JUMP, 0,
/*1035*/    OP_JUMP, 0,
/*1037*/    OP_JUMP, 189,
/*1039*/    OP_DUMP, 95,
/*1041*/    OP_COPY, 0, 7, 1, /* _ext */
/*1045*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1050*/    0, 50, 3,
/*1053*/    -1, 53, 45,
/*1056*/    OP_DUMP, 96,
/*1058*/    OP_COPY, 0, 1136, 4, /* term_type */
/*1062*/    OP_DUMP, 97,
/*1064*/    OP_COPY, 0, 7, 1, /* _ext */
/*1068*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1073*/    0, 51, 3,
/*1076*/    -1, 52, 20,
/*1079*/    OP_DUMP, 98,
/*1081*/    OP_COPY, 0, 1151, 1, /* _ext */
/*1085*/    OP_DUMP, 99,
/*1087*/    OP_COPY, 0, 1147, 3, /* fw_mpx_cap */
/*1091*/    OP_DUMP, 100,
/*1093*/    OP_COPY, 1, 1144, 3, /* bw_mpx_cap */
/*1097*/    OP_JUMP, 0,
/*1099*/    OP_JUMP, 0,
/*1101*/    OP_JUMP, 125,
/*1103*/    OP_DUMP, 101,
/*1105*/    OP_COPY, 0, 7, 1, /* _ext */
/*1109*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1114*/    0, 55, 3,
/*1117*/    -1, 60, 88,
/*1120*/    OP_DUMP, 102,
/*1122*/    OP_COPY, 0, 1183, 1, /* _ext */
/*1126*/    OP_DUMP, 103,
/*1128*/    OP_COPY, 0, 1176, 7, /* ipi_high */
/*1132*/    OP_CASE, 1, 1176, 7, 2, /* ipi_high */
/*1137*/    0x40, 56, 3,
/*1140*/    -1, 59, 51,
/*1143*/    OP_DUMP, 104,
/*1145*/    OP_COPY, 0, 1191, 1, /* _ext */
/*1149*/    OP_DUMP, 105,
/*1151*/    OP_COPY, 0, 6, 1, /* _ipi_low */
/*1155*/    OP_CASE, 1, 6, 1, 2, /* _ipi_low */
/*1160*/    0, 57, 3,
/*1163*/    -1, 58, 26,
/*1166*/    OP_DUMP, 106,
/*1168*/    OP_COPY, 0, 1199, 1, /* _ext */
/*1172*/    OP_DUMP, 107,
/*1174*/    OP_COPY, 1, 1197, 2, /* _snap_id */
/*1178*/    OP_DUMP, 108,
/*1180*/    OP_COPY, 3, 1200, 24, /* oui */
/*1184*/    OP_DUMP, 109,
/*1186*/    OP_COPY, 2, 1224, 16, /* pid */
/*1190*/    OP_JUMP, 0,
/*1192*/    OP_JUMP, 12,
/*1194*/    OP_DUMP, 110,
/*1196*/    OP_COPY, 0, 1255, 1, /* _ext */
/*1200*/    OP_DUMP, 111,
/*1202*/    OP_COPY, 1, 1254, 1, /* ipi_low */
/*1206*/    OP_JUMP, 0,
/*1208*/    OP_JUMP, 18,
/*1210*/    OP_DUMP, 112,
/*1212*/    OP_COPY, 1, 1271, 1, /* _ext */
/*1216*/    OP_DUMP, 113,
/*1218*/    OP_COPY, 0, 1272, 7, /* user_l3 */
/*1222*/    OP_DUMP, 114,
/*1224*/    OP_COPY, 1, 1279, 1, /* _ext */
/*1228*/    OP_JUMP, -481,
/*1230*/    OP_END_REC,
/*1231*/    OP_END_LEN,  /* _ie_len */
/*1232*/    OP_JUMP, 3835,
/*1234*/    OP_DUMP, 115,
/*1236*/    OP_COPY, 0, 1295, 1, /* _ext */
/*1240*/    OP_DUMP, 116,
/*1242*/    OP_COPY, 0, 1293, 2, /* _cs */
/*1246*/    OP_DUMP, 117,
/*1248*/    OP_COPY, 0, 1292, 1, /* _flag */
/*1252*/    OP_DUMP, 118,
/*1254*/    OP_COPY, 1, 1288, 3, /* _action_ind */
/*1258*/    OP_DUMP, 119,
/*1260*/    OP_BEGIN_LEN, 2, 1296, 16, /* _ie_len */
/*1264*/    OP_BEGIN_REC, RECOV_IND_IE, 62, 1750,
/*1268*/    OP_IFEND, 479, /* _lid */
/*1270*/    OP_DUMP, 120,
/*1272*/    OP_COPY, 0, 5, 2, /* _lid */
/*1276*/    OP_CASE, 0, 5, 2, 3, /* _lid */
/*1281*/    1, 63, 6,
/*1284*/    2, 64, 17,
/*1287*/    3, 72, 156,
/*1290*/    OP_DUMP, 121,
/*1292*/    OP_COPY, 0, 1319, 1, /* _ext */
/*1296*/    OP_DUMP, 122,
/*1298*/    OP_COPY, 1, 1312, 5, /* uil1_proto */
/*1302*/    OP_JUMP, 443,
/*1304*/    OP_DUMP, 123,
/*1306*/    OP_COPY, 0, 1320, 5, /* uil2_proto */
/*1310*/    OP_CASE, 0, 1320, 5, 13, /* uil2_proto */
/*1315*/    ATM_L2_X25_LL, 65, 36,
/*1318*/    ATM_L2_X25_ML, 65, 33,
/*1321*/    ATM_L2_HDLC_ARM, 65, 30,
/*1324*/    ATM_L2_HDLC_NRM, 65, 27,
/*1327*/    ATM_L2_HDLC_ABM, 65, 24,
/*1330*/    ATM_L2_Q922, 65, 21,
/*1333*/    ATM_L2_ISO7776, 65, 18,
/*1336*/    ATM_L2_USER, 70, 79,
/*1339*/    -1, 71, 96,
/*1342*/    ATM_L2_Q291, 71, 93,
/*1345*/    ATM_L2_LAPB, 71, 90,
/*1348*/    ATM_L2_ISO8802, 71, 87,
/*1351*/    ATM_L2_X75, 71, 84,
/*1354*/    OP_DUMP, 124,
/*1356*/    OP_COPY, 0, 7, 1, /* _ext */
/*1360*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1365*/    0, 66, 3,
/*1368*/    -1, 69, 45,
/*1371*/    OP_DUMP, 125,
/*1373*/    OP_COPY, 0, 1333, 2, /* l2_mode */
/*1377*/    OP_DUMP, 126,
/*1379*/    OP_COPY, 0, 1328, 2, /* q933 */
/*1383*/    OP_DUMP, 127,
/*1385*/    OP_COPY, 0, 7, 1, /* _ext */
/*1389*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1394*/    0, 67, 3,
/*1397*/    -1, 68, 14,
/*1400*/    OP_DUMP, 128,
/*1402*/    OP_COPY, 0, 1336, 7, /* window_size */
/*1406*/    OP_DUMP, 129,
/*1408*/    OP_COPY, 1, 1343, 1, /* _ext */
/*1412*/    OP_JUMP, 0,
/*1414*/    OP_JUMP, 0,
/*1416*/    OP_JUMP, 26,
/*1418*/    OP_DUMP, 130,
/*1420*/    OP_COPY, 1, 1367, 1, /* _ext */
/*1424*/    OP_DUMP, 131,
/*1426*/    OP_COPY, 0, 1368, 7, /* user_l2 */
/*1430*/    OP_DUMP, 132,
/*1432*/    OP_COPY, 1, 1375, 1, /* _ext */
/*1436*/    OP_JUMP, 6,
/*1438*/    OP_DUMP, 133,
/*1440*/    OP_COPY, 1, 1383, 1, /* _ext */
/*1444*/    OP_JUMP, 301,
/*1446*/    OP_DUMP, 134,
/*1448*/    OP_COPY, 0, 1384, 5, /* uil3_proto */
/*1452*/    OP_CASE, 0, 1384, 5, 6, /* uil3_proto */
/*1457*/    ATM_L3_X25, 73, 15,
/*1460*/    ATM_L3_ISO8208, 73, 12,
/*1463*/    ATM_L3_X223, 73, 9,
/*1466*/    ATM_L3_H310, 80, 89,
/*1469*/    ATM_L3_TR9577, 85, 150,
/*1472*/    ATM_L3_USER, 92, 254,
/*1475*/    OP_DUMP, 135,
/*1477*/    OP_COPY, 0, 7, 1, /* _ext */
/*1481*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1486*/    0, 74, 3,
/*1489*/    -1, 79, 64,
/*1492*/    OP_DUMP, 136,
/*1494*/    OP_COPY, 0, 1397, 2, /* l3_mode */
/*1498*/    OP_DUMP, 137,
/*1500*/    OP_COPY, 0, 7, 1, /* _ext */
/*1504*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1509*/    0, 75, 3,
/*1512*/    -1, 78, 39,
/*1515*/    OP_DUMP, 138,
/*1517*/    OP_COPY, 0, 1400, 4, /* def_pck_size */
/*1521*/    OP_DUMP, 139,
/*1523*/    OP_COPY, 0, 7, 1, /* _ext */
/*1527*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1532*/    0, 76, 3,
/*1535*/    -1, 77, 14,
/*1538*/    OP_DUMP, 140,
/*1540*/    OP_COPY, 1, 1415, 1, /* _ext */
/*1544*/    OP_DUMP, 141,
/*1546*/    OP_COPY, 1, 1416, 7, /* pck_win_size */
/*1550*/    OP_JUMP, 0,
/*1552*/    OP_JUMP, 0,
/*1554*/    OP_JUMP, 0,
/*1556*/    OP_JUMP, 189,
/*1558*/    OP_DUMP, 142,
/*1560*/    OP_COPY, 0, 7, 1, /* _ext */
/*1564*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1569*/    0, 81, 3,
/*1572*/    -1, 84, 45,
/*1575*/    OP_DUMP, 143,
/*1577*/    OP_COPY, 0, 1456, 4, /* term_type */
/*1581*/    OP_DUMP, 144,
/*1583*/    OP_COPY, 0, 7, 1, /* _ext */
/*1587*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1592*/    0, 82, 3,
/*1595*/    -1, 83, 20,
/*1598*/    OP_DUMP, 145,
/*1600*/    OP_COPY, 0, 1471, 1, /* _ext */
/*1604*/    OP_DUMP, 146,
/*1606*/    OP_COPY, 0, 1467, 3, /* fw_mpx_cap */
/*1610*/    OP_DUMP, 147,
/*1612*/    OP_COPY, 1, 1464, 3, /* bw_mpx_cap */
/*1616*/    OP_JUMP, 0,
/*1618*/    OP_JUMP, 0,
/*1620*/    OP_JUMP, 125,
/*1622*/    OP_DUMP, 148,
/*1624*/    OP_COPY, 0, 7, 1, /* _ext */
/*1628*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1633*/    0, 86, 3,
/*1636*/    -1, 91, 88,
/*1639*/    OP_DUMP, 149,
/*1641*/    OP_COPY, 0, 1503, 1, /* _ext */
/*1645*/    OP_DUMP, 150,
/*1647*/    OP_COPY, 0, 1496, 7, /* ipi_high */
/*1651*/    OP_CASE, 1, 1496, 7, 2, /* ipi_high */
/*1656*/    0x40, 87, 3,
/*1659*/    -1, 90, 51,
/*1662*/    OP_DUMP, 151,
/*1664*/    OP_COPY, 0, 1511, 1, /* _ext */
/*1668*/    OP_DUMP, 152,
/*1670*/    OP_COPY, 0, 6, 1, /* _ipi_low */
/*1674*/    OP_CASE, 1, 6, 1, 2, /* _ipi_low */
/*1679*/    0, 88, 3,
/*1682*/    -1, 89, 26,
/*1685*/    OP_DUMP, 153,
/*1687*/    OP_COPY, 0, 1519, 1, /* _ext */
/*1691*/    OP_DUMP, 154,
/*1693*/    OP_COPY, 1, 1517, 2, /* _snap_id */
/*1697*/    OP_DUMP, 155,
/*1699*/    OP_COPY, 3, 1520, 24, /* oui */
/*1703*/    OP_DUMP, 156,
/*1705*/    OP_COPY, 2, 1544, 16, /* pid */
/*1709*/    OP_JUMP, 0,
/*1711*/    OP_JUMP, 12,
/*1713*/    OP_DUMP, 157,
/*1715*/    OP_COPY, 0, 1575, 1, /* _ext */
/*1719*/    OP_DUMP, 158,
/*1721*/    OP_COPY, 1, 1574, 1, /* ipi_low */
/*1725*/    OP_JUMP, 0,
/*1727*/    OP_JUMP, 18,
/*1729*/    OP_DUMP, 159,
/*1731*/    OP_COPY, 1, 1591, 1, /* _ext */
/*1735*/    OP_DUMP, 160,
/*1737*/    OP_COPY, 0, 1592, 7, /* user_l3 */
/*1741*/    OP_DUMP, 161,
/*1743*/    OP_COPY, 1, 1599, 1, /* _ext */
/*1747*/    OP_JUMP, -481,
/*1749*/    OP_END_REC,
/*1750*/    OP_END_LEN,  /* _ie_len */
/*1751*/    OP_JUMP, 3316,
/*1753*/    OP_DUMP, 162,
/*1755*/    OP_COPY, 0, 1615, 1, /* _ext */
/*1759*/    OP_DUMP, 163,
/*1761*/    OP_COPY, 0, 1613, 2, /* _cs */
/*1765*/    OP_DUMP, 164,
/*1767*/    OP_COPY, 0, 1612, 1, /* _flag */
/*1771*/    OP_DUMP, 165,
/*1773*/    OP_COPY, 1, 1608, 3, /* _action_ind */
/*1777*/    OP_DUMP, 166,
/*1779*/    OP_BEGIN_LEN, 2, 1616, 16, /* _ie_len */
/*1783*/    OP_BEGIN_REC, RECOV_IND_IE, 93, 2269,
/*1787*/    OP_IFEND, 479, /* _lid */
/*1789*/    OP_DUMP, 167,
/*1791*/    OP_COPY, 0, 5, 2, /* _lid */
/*1795*/    OP_CASE, 0, 5, 2, 3, /* _lid */
/*1800*/    1, 94, 6,
/*1803*/    2, 95, 17,
/*1806*/    3, 103, 156,
/*1809*/    OP_DUMP, 168,
/*1811*/    OP_COPY, 0, 1639, 1, /* _ext */
/*1815*/    OP_DUMP, 169,
/*1817*/    OP_COPY, 1, 1632, 5, /* uil1_proto */
/*1821*/    OP_JUMP, 443,
/*1823*/    OP_DUMP, 170,
/*1825*/    OP_COPY, 0, 1640, 5, /* uil2_proto */
/*1829*/    OP_CASE, 0, 1640, 5, 13, /* uil2_proto */
/*1834*/    ATM_L2_X25_LL, 96, 36,
/*1837*/    ATM_L2_X25_ML, 96, 33,
/*1840*/    ATM_L2_HDLC_ARM, 96, 30,
/*1843*/    ATM_L2_HDLC_NRM, 96, 27,
/*1846*/    ATM_L2_HDLC_ABM, 96, 24,
/*1849*/    ATM_L2_Q922, 96, 21,
/*1852*/    ATM_L2_ISO7776, 96, 18,
/*1855*/    ATM_L2_USER, 101, 79,
/*1858*/    -1, 102, 96,
/*1861*/    ATM_L2_Q291, 102, 93,
/*1864*/    ATM_L2_LAPB, 102, 90,
/*1867*/    ATM_L2_ISO8802, 102, 87,
/*1870*/    ATM_L2_X75, 102, 84,
/*1873*/    OP_DUMP, 171,
/*1875*/    OP_COPY, 0, 7, 1, /* _ext */
/*1879*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1884*/    0, 97, 3,
/*1887*/    -1, 100, 45,
/*1890*/    OP_DUMP, 172,
/*1892*/    OP_COPY, 0, 1653, 2, /* l2_mode */
/*1896*/    OP_DUMP, 173,
/*1898*/    OP_COPY, 0, 1648, 2, /* q933 */
/*1902*/    OP_DUMP, 174,
/*1904*/    OP_COPY, 0, 7, 1, /* _ext */
/*1908*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1913*/    0, 98, 3,
/*1916*/    -1, 99, 14,
/*1919*/    OP_DUMP, 175,
/*1921*/    OP_COPY, 0, 1656, 7, /* window_size */
/*1925*/    OP_DUMP, 176,
/*1927*/    OP_COPY, 1, 1663, 1, /* _ext */
/*1931*/    OP_JUMP, 0,
/*1933*/    OP_JUMP, 0,
/*1935*/    OP_JUMP, 26,
/*1937*/    OP_DUMP, 177,
/*1939*/    OP_COPY, 1, 1687, 1, /* _ext */
/*1943*/    OP_DUMP, 178,
/*1945*/    OP_COPY, 0, 1688, 7, /* user_l2 */
/*1949*/    OP_DUMP, 179,
/*1951*/    OP_COPY, 1, 1695, 1, /* _ext */
/*1955*/    OP_JUMP, 6,
/*1957*/    OP_DUMP, 180,
/*1959*/    OP_COPY, 1, 1703, 1, /* _ext */
/*1963*/    OP_JUMP, 301,
/*1965*/    OP_DUMP, 181,
/*1967*/    OP_COPY, 0, 1704, 5, /* uil3_proto */
/*1971*/    OP_CASE, 0, 1704, 5, 6, /* uil3_proto */
/*1976*/    ATM_L3_X25, 104, 15,
/*1979*/    ATM_L3_ISO8208, 104, 12,
/*1982*/    ATM_L3_X223, 104, 9,
/*1985*/    ATM_L3_H310, 111, 89,
/*1988*/    ATM_L3_TR9577, 116, 150,
/*1991*/    ATM_L3_USER, 123, 254,
/*1994*/    OP_DUMP, 182,
/*1996*/    OP_COPY, 0, 7, 1, /* _ext */
/*2000*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*2005*/    0, 105, 3,
/*2008*/    -1, 110, 64,
/*2011*/    OP_DUMP, 183,
/*2013*/    OP_COPY, 0, 1717, 2, /* l3_mode */
/*2017*/    OP_DUMP, 184,
/*2019*/    OP_COPY, 0, 7, 1, /* _ext */
/*2023*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*2028*/    0, 106, 3,
/*2031*/    -1, 109, 39,
/*2034*/    OP_DUMP, 185,
/*2036*/    OP_COPY, 0, 1720, 4, /* def_pck_size */
/*2040*/    OP_DUMP, 186,
/*2042*/    OP_COPY, 0, 7, 1, /* _ext */
/*2046*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*2051*/    0, 107, 3,
/*2054*/    -1, 108, 14,
/*2057*/    OP_DUMP, 187,
/*2059*/    OP_COPY, 1, 1735, 1, /* _ext */
/*2063*/    OP_DUMP, 188,
/*2065*/    OP_COPY, 1, 1736, 7, /* pck_win_size */
/*2069*/    OP_JUMP, 0,
/*2071*/    OP_JUMP, 0,
/*2073*/    OP_JUMP, 0,
/*2075*/    OP_JUMP, 189,
/*2077*/    OP_DUMP, 189,
/*2079*/    OP_COPY, 0, 7, 1, /* _ext */
/*2083*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*2088*/    0, 112, 3,
/*2091*/    -1, 115, 45,
/*2094*/    OP_DUMP, 190,
/*2096*/    OP_COPY, 0, 1776, 4, /* term_type */
/*2100*/    OP_DUMP, 191,
/*2102*/    OP_COPY, 0, 7, 1, /* _ext */
/*2106*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*2111*/    0, 113, 3,
/*2114*/    -1, 114, 20,
/*2117*/    OP_DUMP, 192,
/*2119*/    OP_COPY, 0, 1791, 1, /* _ext */
/*2123*/    OP_DUMP, 193,
/*2125*/    OP_COPY, 0, 1787, 3, /* fw_mpx_cap */
/*2129*/    OP_DUMP, 194,
/*2131*/    OP_COPY, 1, 1784, 3, /* bw_mpx_cap */
/*2135*/    OP_JUMP, 0,
/*2137*/    OP_JUMP, 0,
/*2139*/    OP_JUMP, 125,
/*2141*/    OP_DUMP, 195,
/*2143*/    OP_COPY, 0, 7, 1, /* _ext */
/*2147*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*2152*/    0, 117, 3,
/*2155*/    -1, 122, 88,
/*2158*/    OP_DUMP, 196,
/*2160*/    OP_COPY, 0, 1823, 1, /* _ext */
/*2164*/    OP_DUMP, 197,
/*2166*/    OP_COPY, 0, 1816, 7, /* ipi_high */
/*2170*/    OP_CASE, 1, 1816, 7, 2, /* ipi_high */
/*2175*/    0x40, 118, 3,
/*2178*/    -1, 121, 51,
/*2181*/    OP_DUMP, 198,
/*2183*/    OP_COPY, 0, 1831, 1, /* _ext */
/*2187*/    OP_DUMP, 199,
/*2189*/    OP_COPY, 0, 6, 1, /* _ipi_low */
/*2193*/    OP_CASE, 1, 6, 1, 2, /* _ipi_low */
/*2198*/    0, 119, 3,
/*2201*/    -1, 120, 26,
/*2204*/    OP_DUMP, 200,
/*2206*/    OP_COPY, 0, 1839, 1, /* _ext */
/*2210*/    OP_DUMP, 201,
/*2212*/    OP_COPY, 1, 1837, 2, /* _snap_id */
/*2216*/    OP_DUMP, 202,
/*2218*/    OP_COPY, 3, 1840, 24, /* oui */
/*2222*/    OP_DUMP, 203,
/*2224*/    OP_COPY, 2, 1864, 16, /* pid */
/*2228*/    OP_JUMP, 0,
/*2230*/    OP_JUMP, 12,
/*2232*/    OP_DUMP, 204,
/*2234*/    OP_COPY, 0, 1895, 1, /* _ext */
/*2238*/    OP_DUMP, 205,
/*2240*/    OP_COPY, 1, 1894, 1, /* ipi_low */
/*2244*/    OP_JUMP, 0,
/*2246*/    OP_JUMP, 18,
/*2248*/    OP_DUMP, 206,
/*2250*/    OP_COPY, 1, 1911, 1, /* _ext */
/*2254*/    OP_DUMP, 207,
/*2256*/    OP_COPY, 0, 1912, 7, /* user_l3 */
/*2260*/    OP_DUMP, 208,
/*2262*/    OP_COPY, 1, 1919, 1, /* _ext */
/*2266*/    OP_JUMP, -481,
/*2268*/    OP_END_REC,
/*2269*/    OP_END_LEN,  /* _ie_len */
/*2270*/    OP_JUMP, 2797,
/*2272*/    OP_DUMP, 209,
/*2274*/    OP_COPY, 0, 1935, 1, /* _ext */
/*2278*/    OP_DUMP, 210,
/*2280*/    OP_COPY, 0, 1933, 2, /* _cs */
/*2284*/    OP_DUMP, 211,
/*2286*/    OP_COPY, 0, 1932, 1, /* _flag */
/*2290*/    OP_DUMP, 212,
/*2292*/    OP_COPY, 1, 1928, 3, /* _action_ind */
/*2296*/    OP_DUMP, 213,
/*2298*/    OP_BEGIN_LEN, 2, 1936, 16, /* _ie_len */
/*2302*/    OP_BEGIN_REC, RECOV_IND_IE, 124, 2313,
/*2306*/    OP_DUMP, 214,
/*2308*/    OP_COPY, 1, 1952, 6, /* call_state */
/*2312*/    OP_END_REC,
/*2313*/    OP_END_LEN,  /* _ie_len */
/*2314*/    OP_JUMP, 2753,
/*2316*/    OP_DUMP, 215,
/*2318*/    OP_COPY, 0, 1975, 1, /* _ext */
/*2322*/    OP_DUMP, 216,
/*2324*/    OP_COPY, 0, 1973, 2, /* _cs */
/*2328*/    OP_DUMP, 217,
/*2330*/    OP_COPY, 0, 1972, 1, /* _flag */
/*2334*/    OP_DUMP, 218,
/*2336*/    OP_COPY, 1, 1968, 3, /* _action_ind */
/*2340*/    OP_DUMP, 219,
/*2342*/    OP_BEGIN_LEN, 2, 1976, 16, /* _ie_len */
/*2346*/    OP_BEGIN_REC, RECOV_IND_IE, 125, 2400,
/*2350*/    OP_DUMP, 220,
/*2352*/    OP_COPY, 0, 1999, 1, /* _ext */
/*2356*/    OP_DUMP, 221,
/*2358*/    OP_COPY, 0, 0, 4, /* _plan */
/*2362*/    OP_CASE, 0, 0, 4, 2, /* _plan */
/*2367*/    ATM_NP_E164, 126, 3,
/*2370*/    ATM_NP_AEA, 127, 14,
/*2373*/    OP_DUMP, 222,
/*2375*/    OP_COPY, 1, 1996, 3, /* _type */
/*2379*/    OP_DUMP, 223,
/*2381*/    OP_COPYVAR, 2, 2000, 12, /* cdpn_e164 */
/*2385*/    OP_JUMP, 12,
/*2387*/    OP_DUMP, 224,
/*2389*/    OP_COPY, 1, 2100, 3, /* _type */
/*2393*/    OP_DUMP, 225,
/*2395*/    OP_COPYVAR, 3, 2104, 20, /* cdpn_esa */
/*2399*/    OP_END_REC,
/*2400*/    OP_END_LEN,  /* _ie_len */
/*2401*/    OP_JUMP, 2666,
/*2403*/    OP_DUMP, 226,
/*2405*/    OP_COPY, 0, 2279, 1, /* _ext */
/*2409*/    OP_DUMP, 227,
/*2411*/    OP_COPY, 0, 2277, 2, /* _cs */
/*2415*/    OP_DUMP, 228,
/*2417*/    OP_COPY, 0, 2276, 1, /* _flag */
/*2421*/    OP_DUMP, 229,
/*2423*/    OP_COPY, 1, 2272, 3, /* _action_ind */
/*2427*/    OP_DUMP, 230,
/*2429*/    OP_BEGIN_LEN, 2, 2280, 16, /* _ie_len */
/*2433*/    OP_BEGIN_REC, RECOV_IND_IE, 128, 2462,
/*2437*/    OP_DUMP, 231,
/*2439*/    OP_COPY, 0, 2303, 1, /* _ext */
/*2443*/    OP_DUMP, 232,
/*2445*/    OP_COPY, 0, 2300, 3, /* cdps_type */
/*2449*/    OP_DUMP, 233,
/*2451*/    OP_COPY, 1, 2299, 1, /* _oddeven */
/*2455*/    OP_DUMP, 234,
/*2457*/    OP_COPYVAR, 4, 2304, 20, /* cdps */
/*2461*/    OP_END_REC,
/*2462*/    OP_END_LEN,  /* _ie_len */
/*2463*/    OP_JUMP, 2604,
/*2465*/    OP_DUMP, 235,
/*2467*/    OP_COPY, 0, 2479, 1, /* _ext */
/*2471*/    OP_DUMP, 236,
/*2473*/    OP_COPY, 0, 2477, 2, /* _cs */
/*2477*/    OP_DUMP, 237,
/*2479*/    OP_COPY, 0, 2476, 1, /* _flag */
/*2483*/    OP_DUMP, 238,
/*2485*/    OP_COPY, 1, 2472, 3, /* _action_ind */
/*2489*/    OP_DUMP, 239,
/*2491*/    OP_BEGIN_LEN, 2, 2480, 16, /* _ie_len */
/*2495*/    OP_BEGIN_REC, RECOV_IND_IE, 129, 2555,
/*2499*/    OP_DUMP, 240,
/*2501*/    OP_COPY, 0, 2496, 4, /* cgpn_plan */
/*2505*/    OP_DUMP, 241,
/*2507*/    OP_COPY, 0, 2500, 3, /* cgpn_type */
/*2511*/    OP_DUMP, 242,
/*2513*/    OP_COPY, 0, 7, 1, /* _ext */
/*2517*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*2522*/    0, 130, 3,
/*2525*/    -1, 131, 20,
/*2528*/    OP_DUMP, 243,
/*2530*/    OP_COPY, 0, 2511, 1, /* _ext */
/*2534*/    OP_DUMP, 244,
/*2536*/    OP_COPY, 0, 2509, 2, /* pres_ind */
/*2540*/    OP_DUMP, 245,
/*2542*/    OP_COPY, 1, 2504, 2, /* scr_ind */
/*2546*/    OP_JUMP, 0,
/*2548*/    OP_DUMP, 246,
/*2550*/    OP_COPYVAR, 5, 2520, 20, /* cgpn */
/*2554*/    OP_END_REC,
/*2555*/    OP_END_LEN,  /* _ie_len */
/*2556*/    OP_JUMP, 2511,
/*2558*/    OP_DUMP, 247,
/*2560*/    OP_COPY, 0, 2695, 1, /* _ext */
/*2564*/    OP_DUMP, 248,
/*2566*/    OP_COPY, 0, 2693, 2, /* _cs */
/*2570*/    OP_DUMP, 249,
/*2572*/    OP_COPY, 0, 2692, 1, /* _flag */
/*2576*/    OP_DUMP, 250,
/*2578*/    OP_COPY, 1, 2688, 3, /* _action_ind */
/*2582*/    OP_DUMP, 251,
/*2584*/    OP_BEGIN_LEN, 2, 2696, 16, /* _ie_len */
/*2588*/    OP_BEGIN_REC, RECOV_IND_IE, 132, 2617,
/*2592*/    OP_DUMP, 252,
/*2594*/    OP_COPY, 0, 2719, 1, /* _ext */
/*2598*/    OP_DUMP, 253,
/*2600*/    OP_COPY, 0, 2716, 3, /* cgps_type */
/*2604*/    OP_DUMP, 254,
/*2606*/    OP_COPY, 1, 2715, 1, /* _oddeven */
/*2610*/    OP_DUMP, 255,
/*2612*/    OP_COPYVAR, 6, 2720, 20, /* cgps */
/*2616*/    OP_END_REC,
/*2617*/    OP_END_LEN,  /* _ie_len */
/*2618*/    OP_JUMP, 2449,
/*2620*/    OP_DUMP, 256,
/*2622*/    OP_COPY, 0, 2895, 1, /* _ext */
/*2626*/    OP_DUMP, 257,
/*2628*/    OP_COPY, 0, 2893, 2, /* cause_cs */
/*2632*/    OP_DUMP, 258,
/*2634*/    OP_COPY, 0, 2892, 1, /* _flag */
/*2638*/    OP_DUMP, 259,
/*2640*/    OP_COPY, 1, 2888, 3, /* _action_ind */
/*2644*/    OP_DUMP, 260,
/*2646*/    OP_BEGIN_LEN, 2, 2896, 16, /* _ie_len */
/*2650*/    OP_BEGIN_REC, RECOV_IND_IE, 133, 2892,
/*2654*/    OP_DUMP, 261,
/*2656*/    OP_COPY, 0, 2919, 1, /* _ext */
/*2660*/    OP_DUMP, 262,
/*2662*/    OP_COPY, 1, 2912, 4, /* location */
/*2666*/    OP_DUMP, 263,
/*2668*/    OP_COPY, 0, 2927, 1, /* _ext */
/*2672*/    OP_DUMP, 264,
/*2674*/    OP_COPY, 0, 2920, 7, /* cause */
/*2678*/    OP_CASE, 1, 2920, 7, 18, /* cause */
/*2683*/    ATM_CV_UNALLOC, 134, 51,
/*2686*/    ATM_CV_NO_ROUTE_DEST, 134, 48,
/*2689*/    ATM_CV_QOS_UNAVAIL, 134, 45,
/*2692*/    ATM_CV_CALL_REJ, 135, 70,
/*2695*/    ATM_CV_NUM_CHANGED, 138, 117,
/*2698*/    ATM_CV_REJ_CLIR, 139, 124,
/*2701*/    ATM_CV_ACC_INF_DISC, 140, 131,
/*2704*/    ATM_CV_INCOMP_DEST, 140, 128,
/*2707*/    ATM_CV_MAND_IE_MISSING, 140, 125,
/*2710*/    ATM_CV_UNKNOWN_IE, 140, 122,
/*2713*/    ATM_CV_INVALID_IE, 140, 119,
/*2716*/    ATM_CV_UCR_UNAVAIL_OLD, 141, 126,
/*2719*/    ATM_CV_UCR_UNAVAIL_NEW, 141, 123,
/*2722*/    ATM_CV_NO_SUCH_CHAN, 142, 130,
/*2725*/    ATM_CV_UNKNOWN_MSG_TYPE, 143, 143,
/*2728*/    ATM_CV_INCOMP_MSG, 143, 140,
/*2731*/    ATM_CV_TIMER_EXP, 144, 147,
/*2734*/    -1, 145, 154,
/*2737*/    OP_IFEND, 153,
/*2739*/    OP_DUMP, 265,
/*2741*/    OP_COPY, 0, 2935, 1, /* _ext */
/*2745*/    OP_DUMP, 266,
/*2747*/    OP_COPY, 0, 2931, 1, /* pu */
/*2751*/    OP_DUMP, 267,
/*2753*/    OP_COPY, 0, 2930, 1, /* na */
/*2757*/    OP_DUMP, 268,
/*2759*/    OP_COPY, 1, 2928, 2, /* cond2 */
/*2763*/    OP_JUMP, 126,
/*2765*/    OP_IFEND, 125,
/*2767*/    OP_DUMP, 269,
/*2769*/    OP_COPY, 0, 2943, 1, /* _ext */
/*2773*/    OP_DUMP, 270,
/*2775*/    OP_COPY, 0, 2936, 2, /* cond3 */
/*2779*/    OP_DUMP, 271,
/*2781*/    OP_COPY, 0, 2938, 5, /* reason */
/*2785*/    OP_CASE, 1, 2938, 5, 3, /* reason */
/*2790*/    ATM_RSN_USER, 136, 6,
/*2793*/    ATM_RSN_IE_MISS, 137, 11,
/*2796*/    ATM_RSN_IE_INSUFF, 137, 8,
/*2799*/    OP_DUMP, 272,
/*2801*/    OP_COPYVAR, 7, 2944, 27, /* user_diag */
/*2805*/    OP_JUMP, 6,
/*2807*/    OP_DUMP, 273,
/*2809*/    OP_COPY, 1, 3160, 8, /* ie_id3 */
/*2813*/    OP_JUMP, 76,
/*2815*/    OP_IFEND, 75,
/*2817*/    OP_DUMP, 274,
/*2819*/    OP_COPYVAR, 8, 3168, 28, /* new_dest */
/*2823*/    OP_JUMP, 66,
/*2825*/    OP_IFEND, 65,
/*2827*/    OP_DUMP, 275,
/*2829*/    OP_COPY, 1, 3392, 8, /* invalid */
/*2833*/    OP_JUMP, 56,
/*2835*/    OP_IFEND, 55,
/*2837*/    OP_DUMP, 276,
/*2839*/    OP_COPYVAR, 9, 3400, 28, /* ie_id6 */
/*2843*/    OP_JUMP, 46,
/*2845*/    OP_IFEND, 45,
/*2847*/    OP_DUMP, 277,
/*2849*/    OP_COPYVAR, 10, 3624, 28, /* ucr_id */
/*2853*/    OP_JUMP, 36,
/*2855*/    OP_IFEND, 35,
/*2857*/    OP_DUMP, 278,
/*2859*/    OP_COPY, 2, 3848, 16, /* unav_vpci */
/*2863*/    OP_DUMP, 279,
/*2865*/    OP_COPY, 2, 3864, 16, /* unav_vci */
/*2869*/    OP_JUMP, 20,
/*2871*/    OP_IFEND, 19,
/*2873*/    OP_DUMP, 280,
/*2875*/    OP_COPY, 1, 3880, 8, /* bad_msg_type */
/*2879*/    OP_JUMP, 10,
/*2881*/    OP_IFEND, 9,
/*2883*/    OP_DUMP, 281,
/*2885*/    OP_COPY, 3, 3888, 24, /* timer */
/*2889*/    OP_JUMP, 0,
/*2891*/    OP_END_REC,
/*2892*/    OP_END_LEN,  /* _ie_len */
/*2893*/    OP_JUMP, 2174,
/*2895*/    OP_DUMP, 282,
/*2897*/    OP_COPY, 0, 3927, 1, /* _ext */
/*2901*/    OP_DUMP, 283,
/*2903*/    OP_COPY, 0, 3925, 2, /* cause_cs */
/*2907*/    OP_DUMP, 284,
/*2909*/    OP_COPY, 0, 3924, 1, /* _flag */
/*2913*/    OP_DUMP, 285,
/*2915*/    OP_COPY, 1, 3920, 3, /* _action_ind */
/*2919*/    OP_DUMP, 286,
/*2921*/    OP_BEGIN_LEN, 2, 3928, 16, /* _ie_len */
/*2925*/    OP_BEGIN_REC, RECOV_IND_IE, 146, 3167,
/*2929*/    OP_DUMP, 287,
/*2931*/    OP_COPY, 0, 3951, 1, /* _ext */
/*2935*/    OP_DUMP, 288,
/*2937*/    OP_COPY, 1, 3944, 4, /* location */
/*2941*/    OP_DUMP, 289,
/*2943*/    OP_COPY, 0, 3959, 1, /* _ext */
/*2947*/    OP_DUMP, 290,
/*2949*/    OP_COPY, 0, 3952, 7, /* cause */
/*2953*/    OP_CASE, 1, 3952, 7, 18, /* cause */
/*2958*/    ATM_CV_UNALLOC, 147, 51,
/*2961*/    ATM_CV_NO_ROUTE_DEST, 147, 48,
/*2964*/    ATM_CV_QOS_UNAVAIL, 147, 45,
/*2967*/    ATM_CV_CALL_REJ, 148, 70,
/*2970*/    ATM_CV_NUM_CHANGED, 151, 117,
/*2973*/    ATM_CV_REJ_CLIR, 152, 124,
/*2976*/    ATM_CV_ACC_INF_DISC, 153, 131,
/*2979*/    ATM_CV_INCOMP_DEST, 153, 128,
/*2982*/    ATM_CV_MAND_IE_MISSING, 153, 125,
/*2985*/    ATM_CV_UNKNOWN_IE, 153, 122,
/*2988*/    ATM_CV_INVALID_IE, 153, 119,
/*2991*/    ATM_CV_UCR_UNAVAIL_OLD, 154, 126,
/*2994*/    ATM_CV_UCR_UNAVAIL_NEW, 154, 123,
/*2997*/    ATM_CV_NO_SUCH_CHAN, 155, 130,
/*3000*/    ATM_CV_UNKNOWN_MSG_TYPE, 156, 143,
/*3003*/    ATM_CV_INCOMP_MSG, 156, 140,
/*3006*/    ATM_CV_TIMER_EXP, 157, 147,
/*3009*/    -1, 158, 154,
/*3012*/    OP_IFEND, 153,
/*3014*/    OP_DUMP, 291,
/*3016*/    OP_COPY, 0, 3967, 1, /* _ext */
/*3020*/    OP_DUMP, 292,
/*3022*/    OP_COPY, 0, 3963, 1, /* pu */
/*3026*/    OP_DUMP, 293,
/*3028*/    OP_COPY, 0, 3962, 1, /* na */
/*3032*/    OP_DUMP, 294,
/*3034*/    OP_COPY, 1, 3960, 2, /* cond2 */
/*3038*/    OP_JUMP, 126,
/*3040*/    OP_IFEND, 125,
/*3042*/    OP_DUMP, 295,
/*3044*/    OP_COPY, 0, 3975, 1, /* _ext */
/*3048*/    OP_DUMP, 296,
/*3050*/    OP_COPY, 0, 3968, 2, /* cond3 */
/*3054*/    OP_DUMP, 297,
/*3056*/    OP_COPY, 0, 3970, 5, /* reason */
/*3060*/    OP_CASE, 1, 3970, 5, 3, /* reason */
/*3065*/    ATM_RSN_USER, 149, 6,
/*3068*/    ATM_RSN_IE_MISS, 150, 11,
/*3071*/    ATM_RSN_IE_INSUFF, 150, 8,
/*3074*/    OP_DUMP, 298,
/*3076*/    OP_COPYVAR, 11, 3976, 27, /* user_diag */
/*3080*/    OP_JUMP, 6,
/*3082*/    OP_DUMP, 299,
/*3084*/    OP_COPY, 1, 4192, 8, /* ie_id3 */
/*3088*/    OP_JUMP, 76,
/*3090*/    OP_IFEND, 75,
/*3092*/    OP_DUMP, 300,
/*3094*/    OP_COPYVAR, 12, 4200, 28, /* new_dest */
/*3098*/    OP_JUMP, 66,
/*3100*/    OP_IFEND, 65,
/*3102*/    OP_DUMP, 301,
/*3104*/    OP_COPY, 1, 4424, 8, /* invalid */
/*3108*/    OP_JUMP, 56,
/*3110*/    OP_IFEND, 55,
/*3112*/    OP_DUMP, 302,
/*3114*/    OP_COPYVAR, 13, 4432, 28, /* ie_id6 */
/*3118*/    OP_JUMP, 46,
/*3120*/    OP_IFEND, 45,
/*3122*/    OP_DUMP, 303,
/*3124*/    OP_COPYVAR, 14, 4656, 28, /* ucr_id */
/*3128*/    OP_JUMP, 36,
/*3130*/    OP_IFEND, 35,
/*3132*/    OP_DUMP, 304,
/*3134*/    OP_COPY, 2, 4880, 16, /* unav_vpci */
/*3138*/    OP_DUMP, 305,
/*3140*/    OP_COPY, 2, 4896, 16, /* unav_vci */
/*3144*/    OP_JUMP, 20,
/*3146*/    OP_IFEND, 19,
/*3148*/    OP_DUMP, 306,
/*3150*/    OP_COPY, 1, 4912, 8, /* bad_msg_type */
/*3154*/    OP_JUMP, 10,
/*3156*/    OP_IFEND, 9,
/*3158*/    OP_DUMP, 307,
/*3160*/    OP_COPY, 3, 4920, 24, /* timer */
/*3164*/    OP_JUMP, 0,
/*3166*/    OP_END_REC,
/*3167*/    OP_END_LEN,  /* _ie_len */
/*3168*/    OP_JUMP, 1899,
/*3170*/    OP_DUMP, 308,
/*3172*/    OP_COPY, 0, 4959, 1, /* _ext */
/*3176*/    OP_DUMP, 309,
/*3178*/    OP_COPY, 0, 4957, 2, /* _cs */
/*3182*/    OP_DUMP, 310,
/*3184*/    OP_COPY, 0, 4956, 1, /* _flag */
/*3188*/    OP_DUMP, 311,
/*3190*/    OP_COPY, 1, 4952, 3, /* _action_ind */
/*3194*/    OP_DUMP, 312,
/*3196*/    OP_BEGIN_LEN, 2, 4960, 16, /* _ie_len */
/*3200*/    OP_BEGIN_REC, RECOV_IND_IE, 159, 3235,
/*3204*/    OP_DUMP, 313,
/*3206*/    OP_COPY, 0, 4983, 1, /* _ext */
/*3210*/    OP_DUMP, 314,
/*3212*/    OP_COPY, 0, 4979, 2, /* _vp_ass */
/*3216*/    OP_DUMP, 315,
/*3218*/    OP_COPY, 1, 4976, 3, /* _pref_exc */
/*3222*/    OP_DUMP, 316,
/*3224*/    OP_COPY, 2, 4984, 16, /* vpi */
/*3228*/    OP_DUMP, 317,
/*3230*/    OP_COPY, 2, 5000, 16, /* vci */
/*3234*/    OP_END_REC,
/*3235*/    OP_END_LEN,  /* _ie_len */
/*3236*/    OP_JUMP, 1831,
/*3238*/    OP_DUMP, 318,
/*3240*/    OP_COPY, 0, 5031, 1, /* _ext */
/*3244*/    OP_DUMP, 319,
/*3246*/    OP_COPY, 0, 5029, 2, /* _cs */
/*3250*/    OP_DUMP, 320,
/*3252*/    OP_COPY, 0, 5028, 1, /* _flag */
/*3256*/    OP_DUMP, 321,
/*3258*/    OP_COPY, 1, 5024, 3, /* _action_ind */
/*3262*/    OP_DUMP, 322,
/*3264*/    OP_BEGIN_LEN, 2, 5032, 16, /* _ie_len */
/*3268*/    OP_BEGIN_REC, RECOV_IND_IE, 160, 3313,
/*3272*/    OP_IFEND, 38, /* _id */
/*3274*/    OP_DUMP, 323,
/*3276*/    OP_COPY, 0, 0, 8, /* _id */
/*3280*/    OP_CASE, 1, 0, 8, 3, /* _id */
/*3285*/    ATM_TDL_CUM, 161, 6,
/*3288*/    ATM_TDL_E2EMAX, 162, 11,
/*3291*/    ATM_TDL_NGI, 163, 16,
/*3294*/    OP_DUMP, 324,
/*3296*/    OP_COPY, 2, 5056, 16, /* cum_delay */
/*3300*/    OP_JUMP, 8,
/*3302*/    OP_DUMP, 325,
/*3304*/    OP_COPY, 2, 5080, 16, /* max_delay */
/*3308*/    OP_JUMP, 0,
/*3310*/    OP_JUMP, -40,
/*3312*/    OP_END_REC,
/*3313*/    OP_END_LEN,  /* _ie_len */
/*3314*/    OP_JUMP, 1753,
/*3316*/    OP_DUMP, 326,
/*3318*/    OP_COPY, 0, 5119, 1, /* _ext */
/*3322*/    OP_DUMP, 327,
/*3324*/    OP_COPY, 0, 5117, 2, /* qos_cs */
/*3328*/    OP_DUMP, 328,
/*3330*/    OP_COPY, 0, 5116, 1, /* _flag */
/*3334*/    OP_DUMP, 329,
/*3336*/    OP_COPY, 1, 5112, 3, /* _action_ind */
/*3340*/    OP_DUMP, 330,
/*3342*/    OP_BEGIN_LEN, 2, 5120, 16, /* _ie_len */
/*3346*/    OP_BEGIN_REC, RECOV_IND_IE, 164, 3363,
/*3350*/    OP_DUMP, 331,
/*3352*/    OP_COPY, 1, 5136, 8, /* qos_fw */
/*3356*/    OP_DUMP, 332,
/*3358*/    OP_COPY, 1, 5144, 8, /* qos_bw */
/*3362*/    OP_END_REC,
/*3363*/    OP_END_LEN,  /* _ie_len */
/*3364*/    OP_JUMP, 1703,
/*3366*/    OP_DUMP, 333,
/*3368*/    OP_COPY, 0, 5167, 1, /* _ext */
/*3372*/    OP_DUMP, 334,
/*3374*/    OP_COPY, 0, 5165, 2, /* _cs */
/*3378*/    OP_DUMP, 335,
/*3380*/    OP_COPY, 0, 5164, 1, /* _flag */
/*3384*/    OP_DUMP, 336,
/*3386*/    OP_COPY, 1, 5160, 3, /* _action_ind */
/*3390*/    OP_DUMP, 337,
/*3392*/    OP_BEGIN_LEN, 2, 5168, 16, /* _ie_len */
/*3396*/    OP_BEGIN_REC, RECOV_IND_IE, 165, 3413,
/*3400*/    OP_DUMP, 338,
/*3402*/    OP_COPY, 0, 5191, 1, /* _ext */
/*3406*/    OP_DUMP, 339,
/*3408*/    OP_COPY, 1, 5184, 4, /* rep_ind */
/*3412*/    OP_END_REC,
/*3413*/    OP_END_LEN,  /* _ie_len */
/*3414*/    OP_JUMP, 1653,
/*3416*/    OP_DUMP, 340,
/*3418*/    OP_COPY, 0, 5207, 1, /* _ext */
/*3422*/    OP_DUMP, 341,
/*3424*/    OP_COPY, 0, 5205, 2, /* _cs */
/*3428*/    OP_DUMP, 342,
/*3430*/    OP_COPY, 0, 5204, 1, /* _flag */
/*3434*/    OP_DUMP, 343,
/*3436*/    OP_COPY, 1, 5200, 3, /* _action_ind */
/*3440*/    OP_DUMP, 344,
/*3442*/    OP_BEGIN_LEN, 2, 5208, 16, /* _ie_len */
/*3446*/    OP_BEGIN_REC, RECOV_IND_IE, 166, 3463,
/*3450*/    OP_DUMP, 345,
/*3452*/    OP_COPY, 0, 5231, 1, /* _ext */
/*3456*/    OP_DUMP, 346,
/*3458*/    OP_COPY, 1, 5224, 3, /* rst_class */
/*3462*/    OP_END_REC,
/*3463*/    OP_END_LEN,  /* _ie_len */
/*3464*/    OP_JUMP, 1603,
/*3466*/    OP_DUMP, 347,
/*3468*/    OP_COPY, 0, 5247, 1, /* _ext */
/*3472*/    OP_DUMP, 348,
/*3474*/    OP_COPY, 0, 5245, 2, /* _cs */
/*3478*/    OP_DUMP, 349,
/*3480*/    OP_COPY, 0, 5244, 1, /* _flag */
/*3484*/    OP_DUMP, 350,
/*3486*/    OP_COPY, 1, 5240, 3, /* _action_ind */
/*3490*/    OP_DUMP, 351,
/*3492*/    OP_BEGIN_LEN, 2, 5248, 16, /* _ie_len */
/*3496*/    OP_BEGIN_REC, RECOV_IND_IE, 167, 3513,
/*3500*/    OP_DUMP, 352,
/*3502*/    OP_COPY, 0, 5271, 1, /* _ext */
/*3506*/    OP_DUMP, 353,
/*3508*/    OP_COPY, 1, 5264, 7, /* bbsc_ind */
/*3512*/    OP_END_REC,
/*3513*/    OP_END_LEN,  /* _ie_len */
/*3514*/    OP_JUMP, 1553,
/*3516*/    OP_DUMP, 354,
/*3518*/    OP_COPY, 0, 5287, 1, /* _ext */
/*3522*/    OP_DUMP, 355,
/*3524*/    OP_COPY, 0, 5285, 2, /* _cs */
/*3528*/    OP_DUMP, 356,
/*3530*/    OP_COPY, 0, 5284, 1, /* _flag */
/*3534*/    OP_DUMP, 357,
/*3536*/    OP_COPY, 1, 5280, 3, /* _action_ind */
/*3540*/    OP_DUMP, 358,
/*3542*/    OP_BEGIN_LEN, 2, 5288, 16, /* _ie_len */
/*3546*/    OP_BEGIN_REC, RECOV_IND_IE, 168, 3575,
/*3550*/    OP_DUMP, 359,
/*3552*/    OP_COPY, 0, 5311, 1, /* _ext */
/*3556*/    OP_DUMP, 360,
/*3558*/    OP_COPY, 0, 5308, 3, /* _net_type */
/*3562*/    OP_DUMP, 361,
/*3564*/    OP_COPY, 1, 5304, 4, /* _carrier_id */
/*3568*/    OP_DUMP, 362,
/*3570*/    OP_COPYVAR, 15, 5312, 4, /* net_id */
/*3574*/    OP_END_REC,
/*3575*/    OP_END_LEN,  /* _ie_len */
/*3576*/    OP_JUMP, 1491,
/*3578*/    OP_DUMP, 363,
/*3580*/    OP_COPY, 0, 5359, 1, /* _ext */
/*3584*/    OP_DUMP, 364,
/*3586*/    OP_COPY, 0, 5357, 2, /* _cs */
/*3590*/    OP_DUMP, 365,
/*3592*/    OP_COPY, 0, 5356, 1, /* _flag */
/*3596*/    OP_DUMP, 366,
/*3598*/    OP_COPY, 1, 5352, 3, /* _action_ind */
/*3602*/    OP_DUMP, 367,
/*3604*/    OP_BEGIN_LEN, 2, 5360, 16, /* _ie_len */
/*3608*/    OP_BEGIN_REC, RECOV_IND_IE, 169, 3619,
/*3612*/    OP_DUMP, 368,
/*3614*/    OP_COPYVAR, 16, 5376, 4, /* notification */
/*3618*/    OP_END_REC,
/*3619*/    OP_END_LEN,  /* _ie_len */
/*3620*/    OP_JUMP, 1447,
/*3622*/    OP_DUMP, 369,
/*3624*/    OP_COPY, 0, 5423, 1, /* _ext */
/*3628*/    OP_DUMP, 370,
/*3630*/    OP_COPY, 0, 5421, 2, /* _cs */
/*3634*/    OP_DUMP, 371,
/*3636*/    OP_COPY, 0, 5420, 1, /* _flag */
/*3640*/    OP_DUMP, 372,
/*3642*/    OP_COPY, 1, 5416, 3, /* _action_ind */
/*3646*/    OP_DUMP, 373,
/*3648*/    OP_BEGIN_LEN, 2, 5424, 16, /* _ie_len */
/*3652*/    OP_BEGIN_REC, RECOV_IND_IE, 170, 3699,
/*3656*/    OP_DUMP, 374,
/*3658*/    OP_COPY, 0, 5447, 1, /* _ext */
/*3662*/    OP_DUMP, 375,
/*3664*/    OP_COPY, 0, 5445, 2, /* shaping */
/*3668*/    OP_DUMP, 376,
/*3670*/    OP_COPY, 0, 5444, 1, /* compliance */
/*3674*/    OP_DUMP, 377,
/*3676*/    OP_COPY, 1, 5440, 3, /* fault */
/*3680*/    OP_DUMP, 378,
/*3682*/    OP_COPY, 0, 5455, 1, /* _ext */
/*3686*/    OP_DUMP, 379,
/*3688*/    OP_COPY, 0, 5452, 3, /* fwd_ofi */
/*3692*/    OP_DUMP, 380,
/*3694*/    OP_COPY, 1, 5448, 3, /* bwd_ofi */
/*3698*/    OP_END_REC,
/*3699*/    OP_END_LEN,  /* _ie_len */
/*3700*/    OP_JUMP, 1367,
/*3702*/    OP_DUMP, 381,
/*3704*/    OP_COPY, 0, 5471, 1, /* _ext */
/*3708*/    OP_DUMP, 382,
/*3710*/    OP_COPY, 0, 5469, 2, /* _cs */
/*3714*/    OP_DUMP, 383,
/*3716*/    OP_COPY, 0, 5468, 1, /* _flag */
/*3720*/    OP_DUMP, 384,
/*3722*/    OP_COPY, 1, 5464, 3, /* _action_ind */
/*3726*/    OP_DUMP, 385,
/*3728*/    OP_BEGIN_LEN, 2, 5472, 16, /* _ie_len */
/*3732*/    OP_BEGIN_REC, RECOV_IND_IE, 171, 3809,
/*3736*/    OP_DUMP, 386,
/*3738*/    OP_COPY, 1, 5495, 1, /* _dummy */
/*3742*/    OP_DUMP, 387,
/*3744*/    OP_COPY, 0, 5496, 7, /* id_std_app */
/*3748*/    OP_CASE, 1, 5496, 7, 3, /* id_std_app */
/*3753*/    ATM_IRS_DSMCC, 172, 6,
/*3756*/    ATM_IRS_H245, 172, 3,
/*3759*/    -1, 173, 40,
/*3762*/    OP_DUMP, 388,
/*3764*/    OP_COPY, 1, 5504, 8, /* _type */
/*3768*/    OP_DUMP, 389,
/*3770*/    OP_BEGIN_LEN, 1, 5512, 8, /* _length */
/*3774*/    OP_DUMP, 390,
/*3776*/    OP_COPYVAR, 17, 5520, 20, /* session_id */
/*3780*/    OP_END_LEN,  /* _length */
/*3781*/    OP_DUMP, 391,
/*3783*/    OP_COPY, 1, 5680, 8, /* _type */
/*3787*/    OP_DUMP, 392,
/*3789*/    OP_BEGIN_LEN, 1, 5688, 8, /* _length */
/*3793*/    OP_DUMP, 393,
/*3795*/    OP_COPYVAR, 18, 5696, 4, /* resource_id */
/*3799*/    OP_END_LEN,  /* _length */
/*3800*/    OP_JUMP, 6,
/*3802*/    OP_DUMP, 394,
/*3804*/    OP_COPYVAR, 19, 5728, 28, /* unrecognized_git_identifiers */
/*3808*/    OP_END_REC,
/*3809*/    OP_END_LEN,  /* _ie_len */
/*3810*/    OP_JUMP, 1257,
/*3812*/    OP_DUMP, 395,
/*3814*/    OP_COPY, 0, 5967, 1, /* _ext */
/*3818*/    OP_DUMP, 396,
/*3820*/    OP_COPY, 0, 5965, 2, /* _cs */
/*3824*/    OP_DUMP, 397,
/*3826*/    OP_COPY, 0, 5964, 1, /* _flag */
/*3830*/    OP_DUMP, 398,
/*3832*/    OP_COPY, 1, 5960, 3, /* _action_ind */
/*3836*/    OP_DUMP, 399,
/*3838*/    OP_BEGIN_LEN, 2, 5968, 16, /* _ie_len */
/*3842*/    OP_BEGIN_REC, RECOV_IND_IE, 174, 3919,
/*3846*/    OP_DUMP, 400,
/*3848*/    OP_COPY, 1, 5991, 1, /* _dummy */
/*3852*/    OP_DUMP, 401,
/*3854*/    OP_COPY, 0, 5992, 7, /* id_std_app */
/*3858*/    OP_CASE, 1, 5992, 7, 3, /* id_std_app */
/*3863*/    ATM_IRS_DSMCC, 175, 6,
/*3866*/    ATM_IRS_H245, 175, 3,
/*3869*/    -1, 176, 40,
/*3872*/    OP_DUMP, 402,
/*3874*/    OP_COPY, 1, 6000, 8, /* _type */
/*3878*/    OP_DUMP, 403,
/*3880*/    OP_BEGIN_LEN, 1, 6008, 8, /* _length */
/*3884*/    OP_DUMP, 404,
/*3886*/    OP_COPYVAR, 20, 6016, 20, /* session_id */
/*3890*/    OP_END_LEN,  /* _length */
/*3891*/    OP_DUMP, 405,
/*3893*/    OP_COPY, 1, 6176, 8, /* _type */
/*3897*/    OP_DUMP, 406,
/*3899*/    OP_BEGIN_LEN, 1, 6184, 8, /* _length */
/*3903*/    OP_DUMP, 407,
/*3905*/    OP_COPYVAR, 21, 6192, 4, /* resource_id */
/*3909*/    OP_END_LEN,  /* _length */
/*3910*/    OP_JUMP, 6,
/*3912*/    OP_DUMP, 408,
/*3914*/    OP_COPYVAR, 22, 6224, 28, /* unrecognized_git_identifiers */
/*3918*/    OP_END_REC,
/*3919*/    OP_END_LEN,  /* _ie_len */
/*3920*/    OP_JUMP, 1147,
/*3922*/    OP_DUMP, 409,
/*3924*/    OP_COPY, 0, 6463, 1, /* _ext */
/*3928*/    OP_DUMP, 410,
/*3930*/    OP_COPY, 0, 6461, 2, /* _cs */
/*3934*/    OP_DUMP, 411,
/*3936*/    OP_COPY, 0, 6460, 1, /* _flag */
/*3940*/    OP_DUMP, 412,
/*3942*/    OP_COPY, 1, 6456, 3, /* _action_ind */
/*3946*/    OP_DUMP, 413,
/*3948*/    OP_BEGIN_LEN, 2, 6464, 16, /* _ie_len */
/*3952*/    OP_BEGIN_REC, RECOV_IND_IE, 177, 4029,
/*3956*/    OP_DUMP, 414,
/*3958*/    OP_COPY, 1, 6487, 1, /* _dummy */
/*3962*/    OP_DUMP, 415,
/*3964*/    OP_COPY, 0, 6488, 7, /* id_std_app */
/*3968*/    OP_CASE, 1, 6488, 7, 3, /* id_std_app */
/*3973*/    ATM_IRS_DSMCC, 178, 6,
/*3976*/    ATM_IRS_H245, 178, 3,
/*3979*/    -1, 179, 40,
/*3982*/    OP_DUMP, 416,
/*3984*/    OP_COPY, 1, 6496, 8, /* _type */
/*3988*/    OP_DUMP, 417,
/*3990*/    OP_BEGIN_LEN, 1, 6504, 8, /* _length */
/*3994*/    OP_DUMP, 418,
/*3996*/    OP_COPYVAR, 23, 6512, 20, /* session_id */
/*4000*/    OP_END_LEN,  /* _length */
/*4001*/    OP_DUMP, 419,
/*4003*/    OP_COPY, 1, 6672, 8, /* _type */
/*4007*/    OP_DUMP, 420,
/*4009*/    OP_BEGIN_LEN, 1, 6680, 8, /* _length */
/*4013*/    OP_DUMP, 421,
/*4015*/    OP_COPYVAR, 24, 6688, 4, /* resource_id */
/*4019*/    OP_END_LEN,  /* _length */
/*4020*/    OP_JUMP, 6,
/*4022*/    OP_DUMP, 422,
/*4024*/    OP_COPYVAR, 25, 6720, 28, /* unrecognized_git_identifiers */
/*4028*/    OP_END_REC,
/*4029*/    OP_END_LEN,  /* _ie_len */
/*4030*/    OP_JUMP, 1037,
/*4032*/    OP_DUMP, 423,
/*4034*/    OP_COPY, 0, 6959, 1, /* _ext */
/*4038*/    OP_DUMP, 424,
/*4040*/    OP_COPY, 0, 6957, 2, /* _cs */
/*4044*/    OP_DUMP, 425,
/*4046*/    OP_COPY, 0, 6956, 1, /* _flag */
/*4050*/    OP_DUMP, 426,
/*4052*/    OP_COPY, 1, 6952, 3, /* _action_ind */
/*4056*/    OP_DUMP, 427,
/*4058*/    OP_BEGIN_LEN, 2, 6960, 16, /* _ie_len */
/*4062*/    OP_BEGIN_REC, RECOV_IND_IE, 180, 4085,
/*4066*/    OP_DUMP, 428,
/*4068*/    OP_COPY, 0, 6983, 1, /* _ext */
/*4072*/    OP_DUMP, 429,
/*4074*/    OP_COPY, 1, 6976, 7, /* lij_id_type */
/*4078*/    OP_DUMP, 430,
/*4080*/    OP_COPY, 4, 6984, 32, /* lij_id */
/*4084*/    OP_END_REC,
/*4085*/    OP_END_LEN,  /* _ie_len */
/*4086*/    OP_JUMP, 981,
/*4088*/    OP_DUMP, 431,
/*4090*/    OP_COPY, 0, 7031, 1, /* _ext */
/*4094*/    OP_DUMP, 432,
/*4096*/    OP_COPY, 0, 7029, 2, /* _cs */
/*4100*/    OP_DUMP, 433,
/*4102*/    OP_COPY, 0, 7028, 1, /* _flag */
/*4106*/    OP_DUMP, 434,
/*4108*/    OP_COPY, 1, 7024, 3, /* _action_ind */
/*4112*/    OP_DUMP, 435,
/*4114*/    OP_BEGIN_LEN, 2, 7032, 16, /* _ie_len */
/*4118*/    OP_BEGIN_REC, RECOV_IND_IE, 181, 4135,
/*4122*/    OP_DUMP, 436,
/*4124*/    OP_COPY, 0, 7055, 1, /* _ext */
/*4128*/    OP_DUMP, 437,
/*4130*/    OP_COPY, 1, 7048, 2, /* lij_scr_ind */
/*4134*/    OP_END_REC,
/*4135*/    OP_END_LEN,  /* _ie_len */
/*4136*/    OP_JUMP, 931,
/*4138*/    OP_DUMP, 438,
/*4140*/    OP_COPY, 0, 7071, 1, /* _ext */
/*4144*/    OP_DUMP, 439,
/*4146*/    OP_COPY, 0, 7069, 2, /* _cs */
/*4150*/    OP_DUMP, 440,
/*4152*/    OP_COPY, 0, 7068, 1, /* _flag */
/*4156*/    OP_DUMP, 441,
/*4158*/    OP_COPY, 1, 7064, 3, /* _action_ind */
/*4162*/    OP_DUMP, 442,
/*4164*/    OP_BEGIN_LEN, 2, 7072, 16, /* _ie_len */
/*4168*/    OP_BEGIN_REC, RECOV_IND_IE, 182, 4179,
/*4172*/    OP_DUMP, 443,
/*4174*/    OP_COPY, 4, 7088, 32, /* leaf_sn */
/*4178*/    OP_END_REC,
/*4179*/    OP_END_LEN,  /* _ie_len */
/*4180*/    OP_JUMP, 887,
/*4182*/    OP_DUMP, 444,
/*4184*/    OP_COPY, 0, 7135, 1, /* _ext */
/*4188*/    OP_DUMP, 445,
/*4190*/    OP_COPY, 0, 7133, 2, /* _cs */
/*4194*/    OP_DUMP, 446,
/*4196*/    OP_COPY, 0, 7132, 1, /* _flag */
/*4200*/    OP_DUMP, 447,
/*4202*/    OP_COPY, 1, 7128, 3, /* _action_ind */
/*4206*/    OP_DUMP, 448,
/*4208*/    OP_BEGIN_LEN, 2, 7136, 16, /* _ie_len */
/*4212*/    OP_BEGIN_REC, RECOV_IND_IE, 183, 4235,
/*4216*/    OP_DUMP, 449,
/*4218*/    OP_COPY, 0, 7159, 1, /* _ext */
/*4222*/    OP_DUMP, 450,
/*4224*/    OP_COPY, 1, 7152, 4, /* scope_type */
/*4228*/    OP_DUMP, 451,
/*4230*/    OP_COPY, 1, 7160, 8, /* scope_sel */
/*4234*/    OP_END_REC,
/*4235*/    OP_END_LEN,  /* _ie_len */
/*4236*/    OP_JUMP, 831,
/*4238*/    OP_DUMP, 452,
/*4240*/    OP_COPY, 0, 7183, 1, /* _ext */
/*4244*/    OP_DUMP, 453,
/*4246*/    OP_COPY, 0, 7181, 2, /* _cs */
/*4250*/    OP_DUMP, 454,
/*4252*/    OP_COPY, 0, 7180, 1, /* _flag */
/*4256*/    OP_DUMP, 455,
/*4258*/    OP_COPY, 1, 7176, 3, /* _action_ind */
/*4262*/    OP_DUMP, 456,
/*4264*/    OP_BEGIN_LEN, 2, 7184, 16, /* _ie_len */
/*4268*/    OP_BEGIN_REC, RECOV_IND_IE, 184, 4427,
/*4272*/    OP_IFEND, 152, /* _id */
/*4274*/    OP_DUMP, 457,
/*4276*/    OP_COPY, 0, 0, 8, /* _id */
/*4280*/    OP_CASE, 1, 0, 8, 13, /* _id */
/*4285*/    ATM_TD_FW_PCR_0, 185, 36,
/*4288*/    ATM_TD_BW_PCR_0, 186, 41,
/*4291*/    ATM_TD_FW_PCR_01, 187, 46,
/*4294*/    ATM_TD_BW_PCR_01, 188, 51,
/*4297*/    ATM_TD_FW_SCR_0, 189, 56,
/*4300*/    ATM_TD_BW_SCR_0, 190, 61,
/*4303*/    ATM_TD_FW_SCR_01, 191, 66,
/*4306*/    ATM_TD_BW_SCR_01, 192, 71,
/*4309*/    ATM_TD_FW_MBS_0, 193, 76,
/*4312*/    ATM_TD_BW_MBS_0, 194, 81,
/*4315*/    ATM_TD_FW_MBS_01, 195, 86,
/*4318*/    ATM_TD_BW_MBS_01, 196, 91,
/*4321*/    ATM_TD_BEST_EFFORT, 197, 96,
/*4324*/    OP_DUMP, 458,
/*4326*/    OP_COPY, 3, 7208, 24, /* altfw_pcr_0 */
/*4330*/    OP_JUMP, 92,
/*4332*/    OP_DUMP, 459,
/*4334*/    OP_COPY, 3, 7240, 24, /* altbw_pcr_0 */
/*4338*/    OP_JUMP, 84,
/*4340*/    OP_DUMP, 460,
/*4342*/    OP_COPY, 3, 7272, 24, /* altfw_pcr_01 */
/*4346*/    OP_JUMP, 76,
/*4348*/    OP_DUMP, 461,
/*4350*/    OP_COPY, 3, 7304, 24, /* altbw_pcr_01 */
/*4354*/    OP_JUMP, 68,
/*4356*/    OP_DUMP, 462,
/*4358*/    OP_COPY, 3, 7336, 24, /* altfw_scr_0 */
/*4362*/    OP_JUMP, 60,
/*4364*/    OP_DUMP, 463,
/*4366*/    OP_COPY, 3, 7368, 24, /* altbw_scr_0 */
/*4370*/    OP_JUMP, 52,
/*4372*/    OP_DUMP, 464,
/*4374*/    OP_COPY, 3, 7400, 24, /* altfw_scr_01 */
/*4378*/    OP_JUMP, 44,
/*4380*/    OP_DUMP, 465,
/*4382*/    OP_COPY, 3, 7432, 24, /* altbw_scr_01 */
/*4386*/    OP_JUMP, 36,
/*4388*/    OP_DUMP, 466,
/*4390*/    OP_COPY, 3, 7464, 24, /* altfw_mbs_0 */
/*4394*/    OP_JUMP, 28,
/*4396*/    OP_DUMP, 467,
/*4398*/    OP_COPY, 3, 7496, 24, /* altbw_mbs_0 */
/*4402*/    OP_JUMP, 20,
/*4404*/    OP_DUMP, 468,
/*4406*/    OP_COPY, 3, 7528, 24, /* altfw_mbs_01 */
/*4410*/    OP_JUMP, 12,
/*4412*/    OP_DUMP, 469,
/*4414*/    OP_COPY, 3, 7560, 24, /* altbw_mbs_01 */
/*4418*/    OP_JUMP, 4,
/*4420*/    OP_COPY, 0, 7592, 0, /* altbest_effort */
/*4424*/    OP_JUMP, -154,
/*4426*/    OP_END_REC,
/*4427*/    OP_END_LEN,  /* _ie_len */
/*4428*/    OP_JUMP, 639,
/*4430*/    OP_DUMP, 471,
/*4432*/    OP_COPY, 0, 7607, 1, /* _ext */
/*4436*/    OP_DUMP, 472,
/*4438*/    OP_COPY, 0, 7605, 2, /* _cs */
/*4442*/    OP_DUMP, 473,
/*4444*/    OP_COPY, 0, 7604, 1, /* _flag */
/*4448*/    OP_DUMP, 474,
/*4450*/    OP_COPY, 1, 7600, 3, /* _action_ind */
/*4454*/    OP_DUMP, 475,
/*4456*/    OP_BEGIN_LEN, 2, 7608, 16, /* _ie_len */
/*4460*/    OP_BEGIN_REC, RECOV_IND_IE, 198, 4544,
/*4464*/    OP_IFEND, 77, /* _id */
/*4466*/    OP_DUMP, 476,
/*4468*/    OP_COPY, 0, 0, 8, /* _id */
/*4472*/    OP_CASE, 1, 0, 8, 6, /* _id */
/*4477*/    ATM_TD_FW_PCR_0, 199, 15,
/*4480*/    ATM_TD_BW_PCR_0, 200, 20,
/*4483*/    ATM_TD_FW_PCR_01, 201, 25,
/*4486*/    ATM_TD_BW_PCR_01, 202, 30,
/*4489*/    ATM_TD_FW_MCR_01, 203, 35,
/*4492*/    ATM_TD_BW_MCR_01, 204, 40,
/*4495*/    OP_DUMP, 477,
/*4497*/    OP_COPY, 3, 7632, 24, /* minfw_pcr_0 */
/*4501*/    OP_JUMP, 38,
/*4503*/    OP_DUMP, 478,
/*4505*/    OP_COPY, 3, 7664, 24, /* minbw_pcr_0 */
/*4509*/    OP_JUMP, 30,
/*4511*/    OP_DUMP, 479,
/*4513*/    OP_COPY, 3, 7696, 24, /* minfw_pcr_01 */
/*4517*/    OP_JUMP, 22,
/*4519*/    OP_DUMP, 480,
/*4521*/    OP_COPY, 3, 7728, 24, /* minbw_pcr_01 */
/*4525*/    OP_JUMP, 14,
/*4527*/    OP_DUMP, 481,
/*4529*/    OP_COPY, 3, 7760, 24, /* minfw_mcr_01 */
/*4533*/    OP_JUMP, 6,
/*4535*/    OP_DUMP, 482,
/*4537*/    OP_COPY, 3, 7792, 24, /* minbw_mcr_01 */
/*4541*/    OP_JUMP, -79,
/*4543*/    OP_END_REC,
/*4544*/    OP_END_LEN,  /* _ie_len */
/*4545*/    OP_JUMP, 522,
/*4547*/    OP_DUMP, 483,
/*4549*/    OP_COPY, 0, 7831, 1, /* _ext */
/*4553*/    OP_DUMP, 484,
/*4555*/    OP_COPY, 0, 7829, 2, /* _cs */
/*4559*/    OP_DUMP, 485,
/*4561*/    OP_COPY, 0, 7828, 1, /* _flag */
/*4565*/    OP_DUMP, 486,
/*4567*/    OP_COPY, 1, 7824, 3, /* _action_ind */
/*4571*/    OP_DUMP, 487,
/*4573*/    OP_BEGIN_LEN, 2, 7832, 16, /* _ie_len */
/*4577*/    OP_BEGIN_REC, RECOV_IND_IE, 205, 4667,
/*4581*/    OP_DUMP, 488,
/*4583*/    OP_COPY, 1, 7848, 8, /* eqos_origin */
/*4587*/    OP_IFEND, 77, /* _id */
/*4589*/    OP_DUMP, 489,
/*4591*/    OP_COPY, 0, 0, 8, /* _id */
/*4595*/    OP_CASE, 1, 0, 8, 6, /* _id */
/*4600*/    ATM_EQP_ACC_FW_CDV, 206, 15,
/*4603*/    ATM_EQP_ACC_BW_CDV, 207, 20,
/*4606*/    ATM_EQP_CUM_FW_CDV, 208, 25,
/*4609*/    ATM_EQP_CUM_BW_CDV, 209, 30,
/*4612*/    ATM_EQP_ACC_FW_CLR, 210, 35,
/*4615*/    ATM_EQP_ACC_BW_CLR, 211, 40,
/*4618*/    OP_DUMP, 490,
/*4620*/    OP_COPY, 3, 7864, 24, /* acc_fw_cdv */
/*4624*/    OP_JUMP, 38,
/*4626*/    OP_DUMP, 491,
/*4628*/    OP_COPY, 3, 7896, 24, /* acc_bw_cdv */
/*4632*/    OP_JUMP, 30,
/*4634*/    OP_DUMP, 492,
/*4636*/    OP_COPY, 3, 7928, 24, /* cum_fw_cdv */
/*4640*/    OP_JUMP, 22,
/*4642*/    OP_DUMP, 493,
/*4644*/    OP_COPY, 3, 7960, 24, /* cum_bw_cdv */
/*4648*/    OP_JUMP, 14,
/*4650*/    OP_DUMP, 494,
/*4652*/    OP_COPY, 1, 7992, 8, /* acc_fw_clr */
/*4656*/    OP_JUMP, 6,
/*4658*/    OP_DUMP, 495,
/*4660*/    OP_COPY, 1, 8008, 8, /* acc_bw_clr */
/*4664*/    OP_JUMP, -79,
/*4666*/    OP_END_REC,
/*4667*/    OP_END_LEN,  /* _ie_len */
/*4668*/    OP_JUMP, 399,
/*4670*/    OP_DUMP, 496,
/*4672*/    OP_COPY, 0, 8031, 1, /* _ext */
/*4676*/    OP_DUMP, 497,
/*4678*/    OP_COPY, 0, 8029, 2, /* _cs */
/*4682*/    OP_DUMP, 498,
/*4684*/    OP_COPY, 0, 8028, 1, /* _flag */
/*4688*/    OP_DUMP, 499,
/*4690*/    OP_COPY, 1, 8024, 3, /* _action_ind */
/*4694*/    OP_DUMP, 500,
/*4696*/    OP_BEGIN_LEN, 2, 8032, 16, /* _ie_len */
/*4700*/    OP_BEGIN_REC, RECOV_IND_IE, 212, 4740,
/*4704*/    OP_IFEND, 33, /* _id */
/*4706*/    OP_DUMP, 501,
/*4708*/    OP_COPY, 0, 0, 8, /* _id */
/*4712*/    OP_CASE, 1, 0, 8, 2, /* _id */
/*4717*/    ATM_AAP_FW_REC, 213, 3,
/*4720*/    ATM_AAP_BW_REC, 214, 8,
/*4723*/    OP_DUMP, 502,
/*4725*/    OP_COPY, 4, 8056, 32, /* abr_fw_add_rec */
/*4729*/    OP_JUMP, 6,
/*4731*/    OP_DUMP, 503,
/*4733*/    OP_COPY, 4, 8096, 32, /* abr_bw_add_rec */
/*4737*/    OP_JUMP, -35,
/*4739*/    OP_END_REC,
/*4740*/    OP_END_LEN,  /* _ie_len */
/*4741*/    OP_JUMP, 326,
/*4743*/    OP_DUMP, 504,
/*4745*/    OP_COPY, 0, 8143, 1, /* _ext */
/*4749*/    OP_DUMP, 505,
/*4751*/    OP_COPY, 0, 8141, 2, /* _cs */
/*4755*/    OP_DUMP, 506,
/*4757*/    OP_COPY, 0, 8140, 1, /* _flag */
/*4761*/    OP_DUMP, 507,
/*4763*/    OP_COPY, 1, 8136, 3, /* _action_ind */
/*4767*/    OP_DUMP, 508,
/*4769*/    OP_BEGIN_LEN, 2, 8144, 16, /* _ie_len */
/*4773*/    OP_BEGIN_REC, RECOV_IND_IE, 215, 4890,
/*4777*/    OP_IFEND, 110, /* _id */
/*4779*/    OP_DUMP, 509,
/*4781*/    OP_COPY, 0, 0, 8, /* _id */
/*4785*/    OP_CASE, 1, 0, 8, 9, /* _id */
/*4790*/    ATM_ASP_FW_ICR, 216, 24,
/*4793*/    ATM_ASP_BW_ICR, 217, 29,
/*4796*/    ATM_ASP_FW_TBE, 218, 34,
/*4799*/    ATM_ASP_BW_TBE, 219, 39,
/*4802*/    ATM_ASP_CRF_RTT, 220, 44,
/*4805*/    ATM_ASP_FW_RIF, 221, 49,
/*4808*/    ATM_ASP_BW_RIF, 222, 54,
/*4811*/    ATM_ASP_FW_RDF, 223, 59,
/*4814*/    ATM_ASP_BW_RDF, 224, 64,
/*4817*/    OP_DUMP, 510,
/*4819*/    OP_COPY, 3, 8168, 24, /* abr_fw_icr */
/*4823*/    OP_JUMP, 62,
/*4825*/    OP_DUMP, 511,
/*4827*/    OP_COPY, 3, 8200, 24, /* abr_bw_icr */
/*4831*/    OP_JUMP, 54,
/*4833*/    OP_DUMP, 512,
/*4835*/    OP_COPY, 3, 8232, 24, /* abr_fw_tbe */
/*4839*/    OP_JUMP, 46,
/*4841*/    OP_DUMP, 513,
/*4843*/    OP_COPY, 3, 8264, 24, /* abr_bw_tbe */
/*4847*/    OP_JUMP, 38,
/*4849*/    OP_DUMP, 514,
/*4851*/    OP_COPY, 3, 8296, 24, /* atm_crf_rtt */
/*4855*/    OP_JUMP, 30,
/*4857*/    OP_DUMP, 515,
/*4859*/    OP_COPY, 1, 8328, 8, /* atm_fw_rif */
/*4863*/    OP_JUMP, 22,
/*4865*/    OP_DUMP, 516,
/*4867*/    OP_COPY, 1, 8344, 8, /* atm_bw_rif */
/*4871*/    OP_JUMP, 14,
/*4873*/    OP_DUMP, 517,
/*4875*/    OP_COPY, 1, 8360, 8, /* atm_fw_rdf */
/*4879*/    OP_JUMP, 6,
/*4881*/    OP_DUMP, 518,
/*4883*/    OP_COPY, 1, 8376, 8, /* atm_bw_rdf */
/*4887*/    OP_JUMP, -112,
/*4889*/    OP_END_REC,
/*4890*/    OP_END_LEN,  /* _ie_len */
/*4891*/    OP_JUMP, 176,
/*4893*/    OP_DUMP, 519,
/*4895*/    OP_COPY, 0, 8399, 1, /* _ext */
/*4899*/    OP_DUMP, 520,
/*4901*/    OP_COPY, 0, 8397, 2, /* _cs */
/*4905*/    OP_DUMP, 521,
/*4907*/    OP_COPY, 0, 8396, 1, /* _flag */
/*4911*/    OP_DUMP, 522,
/*4913*/    OP_COPY, 1, 8392, 3, /* _action_ind */
/*4917*/    OP_DUMP, 523,
/*4919*/    OP_BEGIN_LEN, 2, 8400, 16, /* _ie_len */
/*4923*/    OP_BEGIN_REC, RECOV_IND_IE, 225, 4940,
/*4927*/    OP_DUMP, 524,
/*4929*/    OP_COPY, 1, 8416, 8, /* _ep_type */
/*4933*/    OP_DUMP, 525,
/*4935*/    OP_COPY, 2, 8424, 16, /* ep_ref */
/*4939*/    OP_END_REC,
/*4940*/    OP_END_LEN,  /* _ie_len */
/*4941*/    OP_JUMP, 126,
/*4943*/    OP_DUMP, 526,
/*4945*/    OP_COPY, 0, 8455, 1, /* _ext */
/*4949*/    OP_DUMP, 527,
/*4951*/    OP_COPY, 0, 8453, 2, /* _cs */
/*4955*/    OP_DUMP, 528,
/*4957*/    OP_COPY, 0, 8452, 1, /* _flag */
/*4961*/    OP_DUMP, 529,
/*4963*/    OP_COPY, 1, 8448, 3, /* _action_ind */
/*4967*/    OP_DUMP, 530,
/*4969*/    OP_BEGIN_LEN, 2, 8456, 16, /* _ie_len */
/*4973*/    OP_BEGIN_REC, RECOV_IND_IE, 226, 4984,
/*4977*/    OP_DUMP, 531,
/*4979*/    OP_COPY, 1, 8472, 6, /* ep_state */
/*4983*/    OP_END_REC,
/*4984*/    OP_END_LEN,  /* _ie_len */
/*4985*/    OP_JUMP, 82,
/*4987*/    OP_DUMP, 532,
/*4989*/    OP_COPY, 0, 8495, 1, /* _ext */
/*4993*/    OP_DUMP, 533,
/*4995*/    OP_COPY, 0, 8493, 2, /* _cs */
/*4999*/    OP_DUMP, 534,
/*5001*/    OP_COPY, 0, 8492, 1, /* _flag */
/*5005*/    OP_DUMP, 535,
/*5007*/    OP_COPY, 1, 8488, 3, /* _action_ind */
/*5011*/    OP_DUMP, 536,
/*5013*/    OP_BEGIN_LEN, 2, 8496, 16, /* _ie_len */
/*5017*/    OP_BEGIN_REC, RECOV_IND_IE, 227, 5028,
/*5021*/    OP_DUMP, 537,
/*5023*/    OP_COPY, 1, 8512, 8, /* type_of_report */
/*5027*/    OP_END_REC,
/*5028*/    OP_END_LEN,  /* _ie_len */
/*5029*/    OP_JUMP, 38,
/*5031*/    OP_DUMP, 538,
/*5033*/    OP_COPY, 0, 8535, 1, /* _ext */
/*5037*/    OP_DUMP, 539,
/*5039*/    OP_COPY, 0, 8533, 2, /* __cs */
/*5043*/    OP_DUMP, 540,
/*5045*/    OP_COPY, 0, 8532, 1, /* _flag */
/*5049*/    OP_DUMP, 541,
/*5051*/    OP_COPY, 1, 8528, 3, /* _action_ind */
/*5055*/    OP_DUMP, 542,
/*5057*/    OP_BEGIN_LEN, 2, 8536, 16, /* _ie_len */
/*5061*/    OP_BEGIN_REC, RECOV_IND_IE, 228, 5068,
/*5065*/    OP_ABORT, RECOV_ASE_UNKNOWN_IE,
/*5067*/    OP_END_REC,
/*5068*/    OP_END_LEN,  /* _ie_len */
/*5069*/    OP_JUMP, -5023,
/*5071*/    OP_END_LEN,  /* msg_len */
/*5072*/    OP_END
};


/*
 * Sorry, this is necessary ...
 */

#include "qlib.c"

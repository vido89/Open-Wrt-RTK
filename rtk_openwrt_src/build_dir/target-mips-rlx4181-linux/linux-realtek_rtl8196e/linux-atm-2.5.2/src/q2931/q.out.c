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
#include "q.out.h"
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
 * "Microcode" used to construct messages. It copies all
 * fields from the construction area to the resulting message.
 */

static int construct[] = {
    OP_COPY, 1, 0, 8, /* _pdsc */
/*   4*/    OP_COPY, 1, 8, 8, /* _cr_len */
/*   8*/    OP_COPY, 3, 16, 24, /* call_ref */
/*  12*/    OP_COPY, 1, 40, 8, /* msg_type */
/*  16*/    OP_COPY, 0, 55, 1, /* _ext */
/*  20*/    OP_COPY, 0, 52, 1, /* _flag */
/*  24*/    OP_COPY, 1, 48, 2, /* _action_ind */
/*  28*/    OP_BEGIN_LEN, 2, 56, 16, /* msg_len */
/*  32*/    OP_IFGROUP, 1, 76,
/*  35*/    OP_COPY, 1, 72, 8, /* ATM_IE_AAL */
/*  39*/    OP_COPY, 0, 87, 1, /* _ext */
/*  43*/    OP_COPY, 0, 85, 2, /* _cs */
/*  47*/    OP_COPY, 0, 84, 1, /* _flag */
/*  51*/    OP_COPY, 1, 80, 3, /* _action_ind */
/*  55*/    OP_BEGIN_LEN, 2, 88, 16, /* _ie_len */
/*  59*/    OP_COPY, 1, 104, 8, /* aal_type */
/*  63*/    OP_IFGROUP, 2, 44,
/*  66*/    OP_IFGROUP, 3, 8,
/*  69*/    OP_COPY, 1, 112, 8, /* ATM_AALP_FW_MAX_SDU */
/*  73*/    OP_COPY, 2, 120, 16, /* fw_max_sdu */
/*  77*/    OP_IFGROUP, 4, 8,
/*  80*/    OP_COPY, 1, 136, 8, /* ATM_AALP_BW_MAX_SDU */
/*  84*/    OP_COPY, 2, 144, 16, /* bw_max_sdu */
/*  88*/    OP_IFGROUP, 5, 8,
/*  91*/    OP_COPY, 1, 160, 8, /* ATM_AALP_AAL_MODE */
/*  95*/    OP_COPY, 1, 168, 8, /* aal_mode */
/*  99*/    OP_IFGROUP, 6, 8,
/* 102*/    OP_COPY, 1, 176, 8, /* ATM_AALP_SSCS */
/* 106*/    OP_COPY, 1, 184, 8, /* sscs_type */
/* 110*/    OP_END_LEN,
/* 111*/    OP_IFGROUP, 7, 191,
/* 114*/    OP_COPY, 1, 192, 8, /* ATM_IE_TD */
/* 118*/    OP_COPY, 0, 207, 1, /* _ext */
/* 122*/    OP_COPY, 0, 205, 2, /* _cs */
/* 126*/    OP_COPY, 0, 204, 1, /* _flag */
/* 130*/    OP_COPY, 1, 200, 3, /* _action_ind */
/* 134*/    OP_BEGIN_LEN, 2, 208, 16, /* _ie_len */
/* 138*/    OP_IFGROUP, 8, 8,
/* 141*/    OP_COPY, 1, 224, 8, /* ATM_TD_FW_PCR_0 */
/* 145*/    OP_COPY, 3, 232, 24, /* fw_pcr_0 */
/* 149*/    OP_IFGROUP, 9, 8,
/* 152*/    OP_COPY, 1, 256, 8, /* ATM_TD_BW_PCR_0 */
/* 156*/    OP_COPY, 3, 264, 24, /* bw_pcr_0 */
/* 160*/    OP_IFGROUP, 10, 8,
/* 163*/    OP_COPY, 1, 288, 8, /* ATM_TD_FW_PCR_01 */
/* 167*/    OP_COPY, 3, 296, 24, /* fw_pcr_01 */
/* 171*/    OP_IFGROUP, 11, 8,
/* 174*/    OP_COPY, 1, 320, 8, /* ATM_TD_BW_PCR_01 */
/* 178*/    OP_COPY, 3, 328, 24, /* bw_pcr_01 */
/* 182*/    OP_IFGROUP, 12, 8,
/* 185*/    OP_COPY, 1, 352, 8, /* ATM_TD_FW_SCR_0 */
/* 189*/    OP_COPY, 3, 360, 24, /* fw_scr_0 */
/* 193*/    OP_IFGROUP, 13, 8,
/* 196*/    OP_COPY, 1, 384, 8, /* ATM_TD_BW_SCR_0 */
/* 200*/    OP_COPY, 3, 392, 24, /* bw_scr_0 */
/* 204*/    OP_IFGROUP, 14, 8,
/* 207*/    OP_COPY, 1, 416, 8, /* ATM_TD_FW_SCR_01 */
/* 211*/    OP_COPY, 3, 424, 24, /* fw_scr_01 */
/* 215*/    OP_IFGROUP, 15, 8,
/* 218*/    OP_COPY, 1, 448, 8, /* ATM_TD_BW_SCR_01 */
/* 222*/    OP_COPY, 3, 456, 24, /* bw_scr_01 */
/* 226*/    OP_IFGROUP, 16, 8,
/* 229*/    OP_COPY, 1, 480, 8, /* ATM_TD_FW_MBS_0 */
/* 233*/    OP_COPY, 3, 488, 24, /* fw_mbs_0 */
/* 237*/    OP_IFGROUP, 17, 8,
/* 240*/    OP_COPY, 1, 512, 8, /* ATM_TD_BW_MBS_0 */
/* 244*/    OP_COPY, 3, 520, 24, /* bw_mbs_0 */
/* 248*/    OP_IFGROUP, 18, 8,
/* 251*/    OP_COPY, 1, 544, 8, /* ATM_TD_FW_MBS_01 */
/* 255*/    OP_COPY, 3, 552, 24, /* fw_mbs_01 */
/* 259*/    OP_IFGROUP, 19, 8,
/* 262*/    OP_COPY, 1, 576, 8, /* ATM_TD_BW_MBS_01 */
/* 266*/    OP_COPY, 3, 584, 24, /* bw_mbs_01 */
/* 270*/    OP_IFGROUP, 20, 8,
/* 273*/    OP_COPY, 1, 608, 8, /* ATM_TD_BEST_EFFORT */
/* 277*/    OP_COPY, 0, 616, 0, /* best_effort */
/* 281*/    OP_IFGROUP, 21, 20,
/* 284*/    OP_COPY, 1, 616, 8, /* ATM_TD_TM_OPT */
/* 288*/    OP_COPY, 0, 631, 1, /* fw_fdisc */
/* 292*/    OP_COPY, 0, 630, 1, /* bw_fdisc */
/* 296*/    OP_COPY, 0, 625, 1, /* bw_tag */
/* 300*/    OP_COPY, 1, 624, 1, /* fw_tag */
/* 304*/    OP_END_LEN,
/* 305*/    OP_IFGROUP, 22, 62,
/* 308*/    OP_COPY, 1, 632, 8, /* ATM_IE_BBCAP */
/* 312*/    OP_COPY, 0, 647, 1, /* _ext */
/* 316*/    OP_COPY, 0, 645, 2, /* _cs */
/* 320*/    OP_COPY, 0, 644, 1, /* _flag */
/* 324*/    OP_COPY, 1, 640, 3, /* _action_ind */
/* 328*/    OP_BEGIN_LEN, 2, 648, 16, /* _ie_len */
/* 332*/    OP_COPY, 0, 664, 5, /* bearer_class */
/* 336*/    OP_IFGROUP, 23, 14,
/* 339*/    OP_COPY, 1, 671, 1, /* 0 */
/* 343*/    OP_COPY, 0, 679, 1, /* _ext */
/* 347*/    OP_COPY, 1, 672, 7, /* trans_cap */
/* 351*/    OP_JUMP, 4,
/* 353*/    OP_COPY, 1, 687, 1, /* 1 */
/* 357*/    OP_COPY, 0, 695, 1, /* _ext */
/* 361*/    OP_COPY, 0, 693, 2, /* susc_clip */
/* 365*/    OP_COPY, 1, 688, 2, /* upcc */
/* 369*/    OP_END_LEN,
/* 370*/    OP_IFGROUP, 25, 80,
/* 373*/    OP_COPY, 1, 696, 8, /* ATM_IE_BHLI */
/* 377*/    OP_COPY, 0, 711, 1, /* _ext */
/* 381*/    OP_COPY, 0, 709, 2, /* _cs */
/* 385*/    OP_COPY, 0, 708, 1, /* _flag */
/* 389*/    OP_COPY, 1, 704, 3, /* _action_ind */
/* 393*/    OP_BEGIN_LEN, 2, 712, 16, /* _ie_len */
/* 397*/    OP_COPY, 0, 735, 1, /* _ext */
/* 401*/    OP_COPY, 1, 728, 7, /* hli_type */
/* 405*/    OP_IFGROUP, 26, 6,
/* 408*/    OP_COPYVAR, 0, 736, 8, /* iso_hli */
/* 412*/    OP_JUMP, 38,
/* 414*/    OP_IFGROUP, 27, 6,
/* 417*/    OP_COPYVAR, 1, 800, 8, /* user_hli */
/* 421*/    OP_JUMP, 29,
/* 423*/    OP_IFGROUP, 28, 6,
/* 426*/    OP_COPY, 4, 864, 32, /* hlp */
/* 430*/    OP_JUMP, 20,
/* 432*/    OP_IFGROUP, 29, 10,
/* 435*/    OP_COPY, 3, 896, 24, /* hli_oui */
/* 439*/    OP_COPY, 4, 920, 32, /* app_id */
/* 443*/    OP_JUMP, 7,
/* 445*/    OP_IFGROUP, 30, 4,
/* 448*/    OP_COPY, 1, 952, 8, /* tobedefined */
/* 452*/    OP_END_LEN,
/* 453*/    OP_IFGROUP, 31, 324,
/* 456*/    OP_COPY, 1, 960, 8, /* ATM_IE_BLLI */
/* 460*/    OP_COPY, 0, 975, 1, /* _ext */
/* 464*/    OP_COPY, 0, 973, 2, /* _cs */
/* 468*/    OP_COPY, 0, 972, 1, /* _flag */
/* 472*/    OP_COPY, 1, 968, 3, /* _action_ind */
/* 476*/    OP_BEGIN_LEN, 2, 976, 16, /* _ie_len */
/* 480*/    OP_IFGROUP, 32, 12,
/* 483*/    OP_COPY, 0, 997, 2, /* 1 */
/* 487*/    OP_COPY, 0, 999, 1, /* _ext */
/* 491*/    OP_COPY, 1, 992, 5, /* uil1_proto */
/* 495*/    OP_IFGROUP, 33, 76,
/* 498*/    OP_COPY, 0, 1005, 2, /* 2 */
/* 502*/    OP_COPY, 0, 1000, 5, /* uil2_proto */
/* 506*/    OP_IFGROUP, 34, 44,
/* 509*/    OP_IFGROUP, 35, 35,
/* 512*/    OP_COPY, 1, 1007, 1, /* 0 */
/* 516*/    OP_COPY, 0, 1013, 2, /* l2_mode */
/* 520*/    OP_COPY, 0, 1008, 2, /* q933 */
/* 524*/    OP_IFGROUP, 36, 14,
/* 527*/    OP_COPY, 1, 1015, 1, /* 0 */
/* 531*/    OP_COPY, 0, 1016, 7, /* window_size */
/* 535*/    OP_COPY, 1, 1023, 1, /* _ext */
/* 539*/    OP_JUMP, 4,
/* 541*/    OP_COPY, 1, 1031, 1, /* 1 */
/* 545*/    OP_JUMP, 4,
/* 547*/    OP_COPY, 1, 1039, 1, /* 1 */
/* 551*/    OP_JUMP, 21,
/* 553*/    OP_IFGROUP, 39, 14,
/* 556*/    OP_COPY, 1, 1047, 1, /* _ext */
/* 560*/    OP_COPY, 0, 1048, 7, /* user_l2 */
/* 564*/    OP_COPY, 1, 1055, 1, /* _ext */
/* 568*/    OP_JUMP, 4,
/* 570*/    OP_COPY, 1, 1063, 1, /* _ext */
/* 574*/    OP_IFGROUP, 41, 202,
/* 577*/    OP_COPY, 0, 1069, 2, /* 3 */
/* 581*/    OP_COPY, 0, 1064, 5, /* uil3_proto */
/* 585*/    OP_IFGROUP, 42, 57,
/* 588*/    OP_IFGROUP, 43, 48,
/* 591*/    OP_COPY, 1, 1071, 1, /* 0 */
/* 595*/    OP_COPY, 0, 1077, 2, /* l3_mode */
/* 599*/    OP_IFGROUP, 44, 31,
/* 602*/    OP_COPY, 1, 1079, 1, /* 0 */
/* 606*/    OP_COPY, 0, 1080, 4, /* def_pck_size */
/* 610*/    OP_IFGROUP, 45, 14,
/* 613*/    OP_COPY, 1, 1087, 1, /* 0 */
/* 617*/    OP_COPY, 1, 1095, 1, /* _ext */
/* 621*/    OP_COPY, 1, 1096, 7, /* pck_win_size */
/* 625*/    OP_JUMP, 4,
/* 627*/    OP_COPY, 1, 1111, 1, /* 1 */
/* 631*/    OP_JUMP, 4,
/* 633*/    OP_COPY, 1, 1119, 1, /* 1 */
/* 637*/    OP_JUMP, 4,
/* 639*/    OP_COPY, 1, 1127, 1, /* 1 */
/* 643*/    OP_JUMP, 134,
/* 645*/    OP_IFGROUP, 49, 44,
/* 648*/    OP_IFGROUP, 50, 35,
/* 651*/    OP_COPY, 1, 1135, 1, /* 0 */
/* 655*/    OP_COPY, 0, 1136, 4, /* term_type */
/* 659*/    OP_IFGROUP, 51, 18,
/* 662*/    OP_COPY, 1, 1143, 1, /* 0 */
/* 666*/    OP_COPY, 0, 1151, 1, /* _ext */
/* 670*/    OP_COPY, 0, 1147, 3, /* fw_mpx_cap */
/* 674*/    OP_COPY, 1, 1144, 3, /* bw_mpx_cap */
/* 678*/    OP_JUMP, 4,
/* 680*/    OP_COPY, 1, 1159, 1, /* 1 */
/* 684*/    OP_JUMP, 4,
/* 686*/    OP_COPY, 1, 1167, 1, /* 1 */
/* 690*/    OP_JUMP, 87,
/* 692*/    OP_IFGROUP, 54, 69,
/* 695*/    OP_IFGROUP, 55, 60,
/* 698*/    OP_COPY, 1, 1175, 1, /* 0 */
/* 702*/    OP_COPY, 0, 1183, 1, /* _ext */
/* 706*/    OP_COPY, 1, 1176, 7, /* ipi_high */
/* 710*/    OP_IFGROUP, 56, 35,
/* 713*/    OP_COPY, 0, 1191, 1, /* _ext */
/* 717*/    OP_IFGROUP, 57, 22,
/* 720*/    OP_COPY, 1, 1190, 1, /* 0 */
/* 724*/    OP_COPY, 0, 1199, 1, /* _ext */
/* 728*/    OP_COPY, 1, 1197, 2, /* _snap_id */
/* 732*/    OP_COPY, 3, 1200, 24, /* oui */
/* 736*/    OP_COPY, 2, 1224, 16, /* pid */
/* 740*/    OP_JUMP, 4,
/* 742*/    OP_COPY, 1, 1246, 1, /* 1 */
/* 746*/    OP_JUMP, 8,
/* 748*/    OP_COPY, 0, 1255, 1, /* _ext */
/* 752*/    OP_COPY, 1, 1254, 1, /* ipi_low */
/* 756*/    OP_JUMP, 4,
/* 758*/    OP_COPY, 1, 1263, 1, /* 1 */
/* 762*/    OP_JUMP, 15,
/* 764*/    OP_IFGROUP, 61, 12,
/* 767*/    OP_COPY, 1, 1271, 1, /* _ext */
/* 771*/    OP_COPY, 0, 1272, 7, /* user_l3 */
/* 775*/    OP_COPY, 1, 1279, 1, /* _ext */
/* 779*/    OP_END_LEN,
/* 780*/    OP_IFGROUP, 62, 324,
/* 783*/    OP_COPY, 1, 1280, 8, /* ATM_IE_BLLI */
/* 787*/    OP_COPY, 0, 1295, 1, /* _ext */
/* 791*/    OP_COPY, 0, 1293, 2, /* _cs */
/* 795*/    OP_COPY, 0, 1292, 1, /* _flag */
/* 799*/    OP_COPY, 1, 1288, 3, /* _action_ind */
/* 803*/    OP_BEGIN_LEN, 2, 1296, 16, /* _ie_len */
/* 807*/    OP_IFGROUP, 63, 12,
/* 810*/    OP_COPY, 0, 1317, 2, /* 1 */
/* 814*/    OP_COPY, 0, 1319, 1, /* _ext */
/* 818*/    OP_COPY, 1, 1312, 5, /* uil1_proto */
/* 822*/    OP_IFGROUP, 64, 76,
/* 825*/    OP_COPY, 0, 1325, 2, /* 2 */
/* 829*/    OP_COPY, 0, 1320, 5, /* uil2_proto */
/* 833*/    OP_IFGROUP, 65, 44,
/* 836*/    OP_IFGROUP, 66, 35,
/* 839*/    OP_COPY, 1, 1327, 1, /* 0 */
/* 843*/    OP_COPY, 0, 1333, 2, /* l2_mode */
/* 847*/    OP_COPY, 0, 1328, 2, /* q933 */
/* 851*/    OP_IFGROUP, 67, 14,
/* 854*/    OP_COPY, 1, 1335, 1, /* 0 */
/* 858*/    OP_COPY, 0, 1336, 7, /* window_size */
/* 862*/    OP_COPY, 1, 1343, 1, /* _ext */
/* 866*/    OP_JUMP, 4,
/* 868*/    OP_COPY, 1, 1351, 1, /* 1 */
/* 872*/    OP_JUMP, 4,
/* 874*/    OP_COPY, 1, 1359, 1, /* 1 */
/* 878*/    OP_JUMP, 21,
/* 880*/    OP_IFGROUP, 70, 14,
/* 883*/    OP_COPY, 1, 1367, 1, /* _ext */
/* 887*/    OP_COPY, 0, 1368, 7, /* user_l2 */
/* 891*/    OP_COPY, 1, 1375, 1, /* _ext */
/* 895*/    OP_JUMP, 4,
/* 897*/    OP_COPY, 1, 1383, 1, /* _ext */
/* 901*/    OP_IFGROUP, 72, 202,
/* 904*/    OP_COPY, 0, 1389, 2, /* 3 */
/* 908*/    OP_COPY, 0, 1384, 5, /* uil3_proto */
/* 912*/    OP_IFGROUP, 73, 57,
/* 915*/    OP_IFGROUP, 74, 48,
/* 918*/    OP_COPY, 1, 1391, 1, /* 0 */
/* 922*/    OP_COPY, 0, 1397, 2, /* l3_mode */
/* 926*/    OP_IFGROUP, 75, 31,
/* 929*/    OP_COPY, 1, 1399, 1, /* 0 */
/* 933*/    OP_COPY, 0, 1400, 4, /* def_pck_size */
/* 937*/    OP_IFGROUP, 76, 14,
/* 940*/    OP_COPY, 1, 1407, 1, /* 0 */
/* 944*/    OP_COPY, 1, 1415, 1, /* _ext */
/* 948*/    OP_COPY, 1, 1416, 7, /* pck_win_size */
/* 952*/    OP_JUMP, 4,
/* 954*/    OP_COPY, 1, 1431, 1, /* 1 */
/* 958*/    OP_JUMP, 4,
/* 960*/    OP_COPY, 1, 1439, 1, /* 1 */
/* 964*/    OP_JUMP, 4,
/* 966*/    OP_COPY, 1, 1447, 1, /* 1 */
/* 970*/    OP_JUMP, 134,
/* 972*/    OP_IFGROUP, 80, 44,
/* 975*/    OP_IFGROUP, 81, 35,
/* 978*/    OP_COPY, 1, 1455, 1, /* 0 */
/* 982*/    OP_COPY, 0, 1456, 4, /* term_type */
/* 986*/    OP_IFGROUP, 82, 18,
/* 989*/    OP_COPY, 1, 1463, 1, /* 0 */
/* 993*/    OP_COPY, 0, 1471, 1, /* _ext */
/* 997*/    OP_COPY, 0, 1467, 3, /* fw_mpx_cap */
/*1001*/    OP_COPY, 1, 1464, 3, /* bw_mpx_cap */
/*1005*/    OP_JUMP, 4,
/*1007*/    OP_COPY, 1, 1479, 1, /* 1 */
/*1011*/    OP_JUMP, 4,
/*1013*/    OP_COPY, 1, 1487, 1, /* 1 */
/*1017*/    OP_JUMP, 87,
/*1019*/    OP_IFGROUP, 85, 69,
/*1022*/    OP_IFGROUP, 86, 60,
/*1025*/    OP_COPY, 1, 1495, 1, /* 0 */
/*1029*/    OP_COPY, 0, 1503, 1, /* _ext */
/*1033*/    OP_COPY, 1, 1496, 7, /* ipi_high */
/*1037*/    OP_IFGROUP, 87, 35,
/*1040*/    OP_COPY, 0, 1511, 1, /* _ext */
/*1044*/    OP_IFGROUP, 88, 22,
/*1047*/    OP_COPY, 1, 1510, 1, /* 0 */
/*1051*/    OP_COPY, 0, 1519, 1, /* _ext */
/*1055*/    OP_COPY, 1, 1517, 2, /* _snap_id */
/*1059*/    OP_COPY, 3, 1520, 24, /* oui */
/*1063*/    OP_COPY, 2, 1544, 16, /* pid */
/*1067*/    OP_JUMP, 4,
/*1069*/    OP_COPY, 1, 1566, 1, /* 1 */
/*1073*/    OP_JUMP, 8,
/*1075*/    OP_COPY, 0, 1575, 1, /* _ext */
/*1079*/    OP_COPY, 1, 1574, 1, /* ipi_low */
/*1083*/    OP_JUMP, 4,
/*1085*/    OP_COPY, 1, 1583, 1, /* 1 */
/*1089*/    OP_JUMP, 15,
/*1091*/    OP_IFGROUP, 92, 12,
/*1094*/    OP_COPY, 1, 1591, 1, /* _ext */
/*1098*/    OP_COPY, 0, 1592, 7, /* user_l3 */
/*1102*/    OP_COPY, 1, 1599, 1, /* _ext */
/*1106*/    OP_END_LEN,
/*1107*/    OP_IFGROUP, 93, 324,
/*1110*/    OP_COPY, 1, 1600, 8, /* ATM_IE_BLLI */
/*1114*/    OP_COPY, 0, 1615, 1, /* _ext */
/*1118*/    OP_COPY, 0, 1613, 2, /* _cs */
/*1122*/    OP_COPY, 0, 1612, 1, /* _flag */
/*1126*/    OP_COPY, 1, 1608, 3, /* _action_ind */
/*1130*/    OP_BEGIN_LEN, 2, 1616, 16, /* _ie_len */
/*1134*/    OP_IFGROUP, 94, 12,
/*1137*/    OP_COPY, 0, 1637, 2, /* 1 */
/*1141*/    OP_COPY, 0, 1639, 1, /* _ext */
/*1145*/    OP_COPY, 1, 1632, 5, /* uil1_proto */
/*1149*/    OP_IFGROUP, 95, 76,
/*1152*/    OP_COPY, 0, 1645, 2, /* 2 */
/*1156*/    OP_COPY, 0, 1640, 5, /* uil2_proto */
/*1160*/    OP_IFGROUP, 96, 44,
/*1163*/    OP_IFGROUP, 97, 35,
/*1166*/    OP_COPY, 1, 1647, 1, /* 0 */
/*1170*/    OP_COPY, 0, 1653, 2, /* l2_mode */
/*1174*/    OP_COPY, 0, 1648, 2, /* q933 */
/*1178*/    OP_IFGROUP, 98, 14,
/*1181*/    OP_COPY, 1, 1655, 1, /* 0 */
/*1185*/    OP_COPY, 0, 1656, 7, /* window_size */
/*1189*/    OP_COPY, 1, 1663, 1, /* _ext */
/*1193*/    OP_JUMP, 4,
/*1195*/    OP_COPY, 1, 1671, 1, /* 1 */
/*1199*/    OP_JUMP, 4,
/*1201*/    OP_COPY, 1, 1679, 1, /* 1 */
/*1205*/    OP_JUMP, 21,
/*1207*/    OP_IFGROUP, 101, 14,
/*1210*/    OP_COPY, 1, 1687, 1, /* _ext */
/*1214*/    OP_COPY, 0, 1688, 7, /* user_l2 */
/*1218*/    OP_COPY, 1, 1695, 1, /* _ext */
/*1222*/    OP_JUMP, 4,
/*1224*/    OP_COPY, 1, 1703, 1, /* _ext */
/*1228*/    OP_IFGROUP, 103, 202,
/*1231*/    OP_COPY, 0, 1709, 2, /* 3 */
/*1235*/    OP_COPY, 0, 1704, 5, /* uil3_proto */
/*1239*/    OP_IFGROUP, 104, 57,
/*1242*/    OP_IFGROUP, 105, 48,
/*1245*/    OP_COPY, 1, 1711, 1, /* 0 */
/*1249*/    OP_COPY, 0, 1717, 2, /* l3_mode */
/*1253*/    OP_IFGROUP, 106, 31,
/*1256*/    OP_COPY, 1, 1719, 1, /* 0 */
/*1260*/    OP_COPY, 0, 1720, 4, /* def_pck_size */
/*1264*/    OP_IFGROUP, 107, 14,
/*1267*/    OP_COPY, 1, 1727, 1, /* 0 */
/*1271*/    OP_COPY, 1, 1735, 1, /* _ext */
/*1275*/    OP_COPY, 1, 1736, 7, /* pck_win_size */
/*1279*/    OP_JUMP, 4,
/*1281*/    OP_COPY, 1, 1751, 1, /* 1 */
/*1285*/    OP_JUMP, 4,
/*1287*/    OP_COPY, 1, 1759, 1, /* 1 */
/*1291*/    OP_JUMP, 4,
/*1293*/    OP_COPY, 1, 1767, 1, /* 1 */
/*1297*/    OP_JUMP, 134,
/*1299*/    OP_IFGROUP, 111, 44,
/*1302*/    OP_IFGROUP, 112, 35,
/*1305*/    OP_COPY, 1, 1775, 1, /* 0 */
/*1309*/    OP_COPY, 0, 1776, 4, /* term_type */
/*1313*/    OP_IFGROUP, 113, 18,
/*1316*/    OP_COPY, 1, 1783, 1, /* 0 */
/*1320*/    OP_COPY, 0, 1791, 1, /* _ext */
/*1324*/    OP_COPY, 0, 1787, 3, /* fw_mpx_cap */
/*1328*/    OP_COPY, 1, 1784, 3, /* bw_mpx_cap */
/*1332*/    OP_JUMP, 4,
/*1334*/    OP_COPY, 1, 1799, 1, /* 1 */
/*1338*/    OP_JUMP, 4,
/*1340*/    OP_COPY, 1, 1807, 1, /* 1 */
/*1344*/    OP_JUMP, 87,
/*1346*/    OP_IFGROUP, 116, 69,
/*1349*/    OP_IFGROUP, 117, 60,
/*1352*/    OP_COPY, 1, 1815, 1, /* 0 */
/*1356*/    OP_COPY, 0, 1823, 1, /* _ext */
/*1360*/    OP_COPY, 1, 1816, 7, /* ipi_high */
/*1364*/    OP_IFGROUP, 118, 35,
/*1367*/    OP_COPY, 0, 1831, 1, /* _ext */
/*1371*/    OP_IFGROUP, 119, 22,
/*1374*/    OP_COPY, 1, 1830, 1, /* 0 */
/*1378*/    OP_COPY, 0, 1839, 1, /* _ext */
/*1382*/    OP_COPY, 1, 1837, 2, /* _snap_id */
/*1386*/    OP_COPY, 3, 1840, 24, /* oui */
/*1390*/    OP_COPY, 2, 1864, 16, /* pid */
/*1394*/    OP_JUMP, 4,
/*1396*/    OP_COPY, 1, 1886, 1, /* 1 */
/*1400*/    OP_JUMP, 8,
/*1402*/    OP_COPY, 0, 1895, 1, /* _ext */
/*1406*/    OP_COPY, 1, 1894, 1, /* ipi_low */
/*1410*/    OP_JUMP, 4,
/*1412*/    OP_COPY, 1, 1903, 1, /* 1 */
/*1416*/    OP_JUMP, 15,
/*1418*/    OP_IFGROUP, 123, 12,
/*1421*/    OP_COPY, 1, 1911, 1, /* _ext */
/*1425*/    OP_COPY, 0, 1912, 7, /* user_l3 */
/*1429*/    OP_COPY, 1, 1919, 1, /* _ext */
/*1433*/    OP_END_LEN,
/*1434*/    OP_IFGROUP, 124, 29,
/*1437*/    OP_COPY, 1, 1920, 8, /* ATM_IE_CALL_STATE */
/*1441*/    OP_COPY, 0, 1935, 1, /* _ext */
/*1445*/    OP_COPY, 0, 1933, 2, /* _cs */
/*1449*/    OP_COPY, 0, 1932, 1, /* _flag */
/*1453*/    OP_COPY, 1, 1928, 3, /* _action_ind */
/*1457*/    OP_BEGIN_LEN, 2, 1936, 16, /* _ie_len */
/*1461*/    OP_COPY, 1, 1952, 6, /* call_state */
/*1465*/    OP_END_LEN,
/*1466*/    OP_IFGROUP, 125, 61,
/*1469*/    OP_COPY, 1, 1960, 8, /* ATM_IE_CDPN */
/*1473*/    OP_COPY, 0, 1975, 1, /* _ext */
/*1477*/    OP_COPY, 0, 1973, 2, /* _cs */
/*1481*/    OP_COPY, 0, 1972, 1, /* _flag */
/*1485*/    OP_COPY, 1, 1968, 3, /* _action_ind */
/*1489*/    OP_BEGIN_LEN, 2, 1976, 16, /* _ie_len */
/*1493*/    OP_COPY, 0, 1999, 1, /* _ext */
/*1497*/    OP_IFGROUP, 126, 14,
/*1500*/    OP_COPY, 0, 1992, 4, /* ATM_NP_E164 */
/*1504*/    OP_COPY, 1, 1996, 3, /* _type */
/*1508*/    OP_COPYVAR, 2, 2000, 12, /* cdpn_e164 */
/*1512*/    OP_JUMP, 15,
/*1514*/    OP_IFGROUP, 127, 12,
/*1517*/    OP_COPY, 0, 2096, 4, /* ATM_NP_AEA */
/*1521*/    OP_COPY, 1, 2100, 3, /* _type */
/*1525*/    OP_COPYVAR, 3, 2104, 20, /* cdpn_esa */
/*1529*/    OP_END_LEN,
/*1530*/    OP_IFGROUP, 128, 41,
/*1533*/    OP_COPY, 1, 2264, 8, /* ATM_IE_CDPS */
/*1537*/    OP_COPY, 0, 2279, 1, /* _ext */
/*1541*/    OP_COPY, 0, 2277, 2, /* _cs */
/*1545*/    OP_COPY, 0, 2276, 1, /* _flag */
/*1549*/    OP_COPY, 1, 2272, 3, /* _action_ind */
/*1553*/    OP_BEGIN_LEN, 2, 2280, 16, /* _ie_len */
/*1557*/    OP_COPY, 0, 2303, 1, /* _ext */
/*1561*/    OP_COPY, 0, 2300, 3, /* cdps_type */
/*1565*/    OP_COPY, 1, 2299, 1, /* _oddeven */
/*1569*/    OP_COPYVAR, 4, 2304, 20, /* cdps */
/*1573*/    OP_END_LEN,
/*1574*/    OP_IFGROUP, 129, 62,
/*1577*/    OP_COPY, 1, 2464, 8, /* ATM_IE_CGPN */
/*1581*/    OP_COPY, 0, 2479, 1, /* _ext */
/*1585*/    OP_COPY, 0, 2477, 2, /* _cs */
/*1589*/    OP_COPY, 0, 2476, 1, /* _flag */
/*1593*/    OP_COPY, 1, 2472, 3, /* _action_ind */
/*1597*/    OP_BEGIN_LEN, 2, 2480, 16, /* _ie_len */
/*1601*/    OP_COPY, 0, 2496, 4, /* cgpn_plan */
/*1605*/    OP_COPY, 0, 2500, 3, /* cgpn_type */
/*1609*/    OP_IFGROUP, 130, 18,
/*1612*/    OP_COPY, 1, 2503, 1, /* 0 */
/*1616*/    OP_COPY, 0, 2511, 1, /* _ext */
/*1620*/    OP_COPY, 0, 2509, 2, /* pres_ind */
/*1624*/    OP_COPY, 1, 2504, 2, /* scr_ind */
/*1628*/    OP_JUMP, 4,
/*1630*/    OP_COPY, 1, 2519, 1, /* 1 */
/*1634*/    OP_COPYVAR, 5, 2520, 20, /* cgpn */
/*1638*/    OP_END_LEN,
/*1639*/    OP_IFGROUP, 132, 41,
/*1642*/    OP_COPY, 1, 2680, 8, /* ATM_IE_CGPS */
/*1646*/    OP_COPY, 0, 2695, 1, /* _ext */
/*1650*/    OP_COPY, 0, 2693, 2, /* _cs */
/*1654*/    OP_COPY, 0, 2692, 1, /* _flag */
/*1658*/    OP_COPY, 1, 2688, 3, /* _action_ind */
/*1662*/    OP_BEGIN_LEN, 2, 2696, 16, /* _ie_len */
/*1666*/    OP_COPY, 0, 2719, 1, /* _ext */
/*1670*/    OP_COPY, 0, 2716, 3, /* cgps_type */
/*1674*/    OP_COPY, 1, 2715, 1, /* _oddeven */
/*1678*/    OP_COPYVAR, 6, 2720, 20, /* cgps */
/*1682*/    OP_END_LEN,
/*1683*/    OP_IFGROUP, 133, 162,
/*1686*/    OP_COPY, 1, 2880, 8, /* ATM_IE_CAUSE */
/*1690*/    OP_COPY, 0, 2895, 1, /* _ext */
/*1694*/    OP_COPY, 0, 2893, 2, /* cause_cs */
/*1698*/    OP_COPY, 0, 2892, 1, /* _flag */
/*1702*/    OP_COPY, 1, 2888, 3, /* _action_ind */
/*1706*/    OP_BEGIN_LEN, 2, 2896, 16, /* _ie_len */
/*1710*/    OP_COPY, 0, 2919, 1, /* _ext */
/*1714*/    OP_COPY, 1, 2912, 4, /* location */
/*1718*/    OP_COPY, 0, 2927, 1, /* _ext */
/*1722*/    OP_COPY, 1, 2920, 7, /* cause */
/*1726*/    OP_IFGROUP, 134, 18,
/*1729*/    OP_COPY, 0, 2935, 1, /* _ext */
/*1733*/    OP_COPY, 0, 2931, 1, /* pu */
/*1737*/    OP_COPY, 0, 2930, 1, /* na */
/*1741*/    OP_COPY, 1, 2928, 2, /* cond2 */
/*1745*/    OP_JUMP, 100,
/*1747*/    OP_IFGROUP, 135, 30,
/*1750*/    OP_COPY, 0, 2943, 1, /* _ext */
/*1754*/    OP_COPY, 0, 2936, 2, /* cond3 */
/*1758*/    OP_COPY, 1, 2938, 5, /* reason */
/*1762*/    OP_IFGROUP, 136, 6,
/*1765*/    OP_COPYVAR, 7, 2944, 27, /* user_diag */
/*1769*/    OP_JUMP, 7,
/*1771*/    OP_IFGROUP, 137, 4,
/*1774*/    OP_COPY, 1, 3160, 8, /* ie_id3 */
/*1778*/    OP_JUMP, 67,
/*1780*/    OP_IFGROUP, 138, 6,
/*1783*/    OP_COPYVAR, 8, 3168, 28, /* new_dest */
/*1787*/    OP_JUMP, 58,
/*1789*/    OP_IFGROUP, 139, 6,
/*1792*/    OP_COPY, 1, 3392, 8, /* invalid */
/*1796*/    OP_JUMP, 49,
/*1798*/    OP_IFGROUP, 140, 6,
/*1801*/    OP_COPYVAR, 9, 3400, 28, /* ie_id6 */
/*1805*/    OP_JUMP, 40,
/*1807*/    OP_IFGROUP, 141, 6,
/*1810*/    OP_COPYVAR, 10, 3624, 28, /* ucr_id */
/*1814*/    OP_JUMP, 31,
/*1816*/    OP_IFGROUP, 142, 10,
/*1819*/    OP_COPY, 2, 3848, 16, /* unav_vpci */
/*1823*/    OP_COPY, 2, 3864, 16, /* unav_vci */
/*1827*/    OP_JUMP, 18,
/*1829*/    OP_IFGROUP, 143, 6,
/*1832*/    OP_COPY, 1, 3880, 8, /* bad_msg_type */
/*1836*/    OP_JUMP, 9,
/*1838*/    OP_IFGROUP, 144, 6,
/*1841*/    OP_COPY, 3, 3888, 24, /* timer */
/*1845*/    OP_JUMP, 0,
/*1847*/    OP_END_LEN,
/*1848*/    OP_IFGROUP, 146, 162,
/*1851*/    OP_COPY, 1, 3912, 8, /* ATM_IE_CAUSE */
/*1855*/    OP_COPY, 0, 3927, 1, /* _ext */
/*1859*/    OP_COPY, 0, 3925, 2, /* cause_cs */
/*1863*/    OP_COPY, 0, 3924, 1, /* _flag */
/*1867*/    OP_COPY, 1, 3920, 3, /* _action_ind */
/*1871*/    OP_BEGIN_LEN, 2, 3928, 16, /* _ie_len */
/*1875*/    OP_COPY, 0, 3951, 1, /* _ext */
/*1879*/    OP_COPY, 1, 3944, 4, /* location */
/*1883*/    OP_COPY, 0, 3959, 1, /* _ext */
/*1887*/    OP_COPY, 1, 3952, 7, /* cause */
/*1891*/    OP_IFGROUP, 147, 18,
/*1894*/    OP_COPY, 0, 3967, 1, /* _ext */
/*1898*/    OP_COPY, 0, 3963, 1, /* pu */
/*1902*/    OP_COPY, 0, 3962, 1, /* na */
/*1906*/    OP_COPY, 1, 3960, 2, /* cond2 */
/*1910*/    OP_JUMP, 100,
/*1912*/    OP_IFGROUP, 148, 30,
/*1915*/    OP_COPY, 0, 3975, 1, /* _ext */
/*1919*/    OP_COPY, 0, 3968, 2, /* cond3 */
/*1923*/    OP_COPY, 1, 3970, 5, /* reason */
/*1927*/    OP_IFGROUP, 149, 6,
/*1930*/    OP_COPYVAR, 11, 3976, 27, /* user_diag */
/*1934*/    OP_JUMP, 7,
/*1936*/    OP_IFGROUP, 150, 4,
/*1939*/    OP_COPY, 1, 4192, 8, /* ie_id3 */
/*1943*/    OP_JUMP, 67,
/*1945*/    OP_IFGROUP, 151, 6,
/*1948*/    OP_COPYVAR, 12, 4200, 28, /* new_dest */
/*1952*/    OP_JUMP, 58,
/*1954*/    OP_IFGROUP, 152, 6,
/*1957*/    OP_COPY, 1, 4424, 8, /* invalid */
/*1961*/    OP_JUMP, 49,
/*1963*/    OP_IFGROUP, 153, 6,
/*1966*/    OP_COPYVAR, 13, 4432, 28, /* ie_id6 */
/*1970*/    OP_JUMP, 40,
/*1972*/    OP_IFGROUP, 154, 6,
/*1975*/    OP_COPYVAR, 14, 4656, 28, /* ucr_id */
/*1979*/    OP_JUMP, 31,
/*1981*/    OP_IFGROUP, 155, 10,
/*1984*/    OP_COPY, 2, 4880, 16, /* unav_vpci */
/*1988*/    OP_COPY, 2, 4896, 16, /* unav_vci */
/*1992*/    OP_JUMP, 18,
/*1994*/    OP_IFGROUP, 156, 6,
/*1997*/    OP_COPY, 1, 4912, 8, /* bad_msg_type */
/*2001*/    OP_JUMP, 9,
/*2003*/    OP_IFGROUP, 157, 6,
/*2006*/    OP_COPY, 3, 4920, 24, /* timer */
/*2010*/    OP_JUMP, 0,
/*2012*/    OP_END_LEN,
/*2013*/    OP_IFGROUP, 159, 45,
/*2016*/    OP_COPY, 1, 4944, 8, /* ATM_IE_CONN_ID */
/*2020*/    OP_COPY, 0, 4959, 1, /* _ext */
/*2024*/    OP_COPY, 0, 4957, 2, /* _cs */
/*2028*/    OP_COPY, 0, 4956, 1, /* _flag */
/*2032*/    OP_COPY, 1, 4952, 3, /* _action_ind */
/*2036*/    OP_BEGIN_LEN, 2, 4960, 16, /* _ie_len */
/*2040*/    OP_COPY, 0, 4983, 1, /* _ext */
/*2044*/    OP_COPY, 0, 4979, 2, /* _vp_ass */
/*2048*/    OP_COPY, 1, 4976, 3, /* _pref_exc */
/*2052*/    OP_COPY, 2, 4984, 16, /* vpi */
/*2056*/    OP_COPY, 2, 5000, 16, /* vci */
/*2060*/    OP_END_LEN,
/*2061*/    OP_IFGROUP, 160, 54,
/*2064*/    OP_COPY, 1, 5016, 8, /* ATM_IE_E2E_TDL */
/*2068*/    OP_COPY, 0, 5031, 1, /* _ext */
/*2072*/    OP_COPY, 0, 5029, 2, /* _cs */
/*2076*/    OP_COPY, 0, 5028, 1, /* _flag */
/*2080*/    OP_COPY, 1, 5024, 3, /* _action_ind */
/*2084*/    OP_BEGIN_LEN, 2, 5032, 16, /* _ie_len */
/*2088*/    OP_IFGROUP, 161, 8,
/*2091*/    OP_COPY, 1, 5048, 8, /* ATM_TDL_CUM */
/*2095*/    OP_COPY, 2, 5056, 16, /* cum_delay */
/*2099*/    OP_IFGROUP, 162, 8,
/*2102*/    OP_COPY, 1, 5072, 8, /* ATM_TDL_E2EMAX */
/*2106*/    OP_COPY, 2, 5080, 16, /* max_delay */
/*2110*/    OP_IFGROUP, 163, 4,
/*2113*/    OP_COPY, 1, 5096, 8, /* ATM_TDL_NGI */
/*2117*/    OP_END_LEN,
/*2118*/    OP_IFGROUP, 164, 33,
/*2121*/    OP_COPY, 1, 5104, 8, /* ATM_IE_QOS */
/*2125*/    OP_COPY, 0, 5119, 1, /* _ext */
/*2129*/    OP_COPY, 0, 5117, 2, /* qos_cs */
/*2133*/    OP_COPY, 0, 5116, 1, /* _flag */
/*2137*/    OP_COPY, 1, 5112, 3, /* _action_ind */
/*2141*/    OP_BEGIN_LEN, 2, 5120, 16, /* _ie_len */
/*2145*/    OP_COPY, 1, 5136, 8, /* qos_fw */
/*2149*/    OP_COPY, 1, 5144, 8, /* qos_bw */
/*2153*/    OP_END_LEN,
/*2154*/    OP_IFGROUP, 165, 33,
/*2157*/    OP_COPY, 1, 5152, 8, /* ATM_IE_BBREP */
/*2161*/    OP_COPY, 0, 5167, 1, /* _ext */
/*2165*/    OP_COPY, 0, 5165, 2, /* _cs */
/*2169*/    OP_COPY, 0, 5164, 1, /* _flag */
/*2173*/    OP_COPY, 1, 5160, 3, /* _action_ind */
/*2177*/    OP_BEGIN_LEN, 2, 5168, 16, /* _ie_len */
/*2181*/    OP_COPY, 0, 5191, 1, /* _ext */
/*2185*/    OP_COPY, 1, 5184, 4, /* rep_ind */
/*2189*/    OP_END_LEN,
/*2190*/    OP_IFGROUP, 166, 33,
/*2193*/    OP_COPY, 1, 5192, 8, /* ATM_IE_RESTART */
/*2197*/    OP_COPY, 0, 5207, 1, /* _ext */
/*2201*/    OP_COPY, 0, 5205, 2, /* _cs */
/*2205*/    OP_COPY, 0, 5204, 1, /* _flag */
/*2209*/    OP_COPY, 1, 5200, 3, /* _action_ind */
/*2213*/    OP_BEGIN_LEN, 2, 5208, 16, /* _ie_len */
/*2217*/    OP_COPY, 0, 5231, 1, /* _ext */
/*2221*/    OP_COPY, 1, 5224, 3, /* rst_class */
/*2225*/    OP_END_LEN,
/*2226*/    OP_IFGROUP, 167, 33,
/*2229*/    OP_COPY, 1, 5232, 8, /* ATM_IE_BBS_COMP */
/*2233*/    OP_COPY, 0, 5247, 1, /* _ext */
/*2237*/    OP_COPY, 0, 5245, 2, /* _cs */
/*2241*/    OP_COPY, 0, 5244, 1, /* _flag */
/*2245*/    OP_COPY, 1, 5240, 3, /* _action_ind */
/*2249*/    OP_BEGIN_LEN, 2, 5248, 16, /* _ie_len */
/*2253*/    OP_COPY, 0, 5271, 1, /* _ext */
/*2257*/    OP_COPY, 1, 5264, 7, /* bbsc_ind */
/*2261*/    OP_END_LEN,
/*2262*/    OP_IFGROUP, 168, 41,
/*2265*/    OP_COPY, 1, 5272, 8, /* ATM_IE_TNS */
/*2269*/    OP_COPY, 0, 5287, 1, /* _ext */
/*2273*/    OP_COPY, 0, 5285, 2, /* _cs */
/*2277*/    OP_COPY, 0, 5284, 1, /* _flag */
/*2281*/    OP_COPY, 1, 5280, 3, /* _action_ind */
/*2285*/    OP_BEGIN_LEN, 2, 5288, 16, /* _ie_len */
/*2289*/    OP_COPY, 0, 5311, 1, /* _ext */
/*2293*/    OP_COPY, 0, 5308, 3, /* _net_type */
/*2297*/    OP_COPY, 1, 5304, 4, /* _carrier_id */
/*2301*/    OP_COPYVAR, 15, 5312, 4, /* net_id */
/*2305*/    OP_END_LEN,
/*2306*/    OP_IFGROUP, 169, 29,
/*2309*/    OP_COPY, 1, 5344, 8, /* ATM_IE_NOTIFY */
/*2313*/    OP_COPY, 0, 5359, 1, /* _ext */
/*2317*/    OP_COPY, 0, 5357, 2, /* _cs */
/*2321*/    OP_COPY, 0, 5356, 1, /* _flag */
/*2325*/    OP_COPY, 1, 5352, 3, /* _action_ind */
/*2329*/    OP_BEGIN_LEN, 2, 5360, 16, /* _ie_len */
/*2333*/    OP_COPYVAR, 16, 5376, 4, /* notification */
/*2337*/    OP_END_LEN,
/*2338*/    OP_IFGROUP, 170, 53,
/*2341*/    OP_COPY, 1, 5408, 8, /* ATM_IE_OAM_TD */
/*2345*/    OP_COPY, 0, 5423, 1, /* _ext */
/*2349*/    OP_COPY, 0, 5421, 2, /* _cs */
/*2353*/    OP_COPY, 0, 5420, 1, /* _flag */
/*2357*/    OP_COPY, 1, 5416, 3, /* _action_ind */
/*2361*/    OP_BEGIN_LEN, 2, 5424, 16, /* _ie_len */
/*2365*/    OP_COPY, 0, 5447, 1, /* _ext */
/*2369*/    OP_COPY, 0, 5445, 2, /* shaping */
/*2373*/    OP_COPY, 0, 5444, 1, /* compliance */
/*2377*/    OP_COPY, 1, 5440, 3, /* fault */
/*2381*/    OP_COPY, 0, 5455, 1, /* _ext */
/*2385*/    OP_COPY, 0, 5452, 3, /* fwd_ofi */
/*2389*/    OP_COPY, 1, 5448, 3, /* bwd_ofi */
/*2393*/    OP_END_LEN,
/*2394*/    OP_IFGROUP, 171, 68,
/*2397*/    OP_COPY, 1, 5456, 8, /* ATM_IE_GIT */
/*2401*/    OP_COPY, 0, 5471, 1, /* _ext */
/*2405*/    OP_COPY, 0, 5469, 2, /* _cs */
/*2409*/    OP_COPY, 0, 5468, 1, /* _flag */
/*2413*/    OP_COPY, 1, 5464, 3, /* _action_ind */
/*2417*/    OP_BEGIN_LEN, 2, 5472, 16, /* _ie_len */
/*2421*/    OP_COPY, 1, 5495, 1, /* _dummy */
/*2425*/    OP_COPY, 1, 5496, 7, /* id_std_app */
/*2429*/    OP_IFGROUP, 172, 28,
/*2432*/    OP_COPY, 1, 5504, 8, /* _type */
/*2436*/    OP_BEGIN_LEN, 1, 5512, 8, /* _length */
/*2440*/    OP_COPYVAR, 17, 5520, 20, /* session_id */
/*2444*/    OP_END_LEN,
/*2445*/    OP_COPY, 1, 5680, 8, /* _type */
/*2449*/    OP_BEGIN_LEN, 1, 5688, 8, /* _length */
/*2453*/    OP_COPYVAR, 18, 5696, 4, /* resource_id */
/*2457*/    OP_END_LEN,
/*2458*/    OP_JUMP, 4,
/*2460*/    OP_COPYVAR, 19, 5728, 28, /* unrecognized_git_identifiers */
/*2464*/    OP_END_LEN,
/*2465*/    OP_IFGROUP, 174, 68,
/*2468*/    OP_COPY, 1, 5952, 8, /* ATM_IE_GIT */
/*2472*/    OP_COPY, 0, 5967, 1, /* _ext */
/*2476*/    OP_COPY, 0, 5965, 2, /* _cs */
/*2480*/    OP_COPY, 0, 5964, 1, /* _flag */
/*2484*/    OP_COPY, 1, 5960, 3, /* _action_ind */
/*2488*/    OP_BEGIN_LEN, 2, 5968, 16, /* _ie_len */
/*2492*/    OP_COPY, 1, 5991, 1, /* _dummy */
/*2496*/    OP_COPY, 1, 5992, 7, /* id_std_app */
/*2500*/    OP_IFGROUP, 175, 28,
/*2503*/    OP_COPY, 1, 6000, 8, /* _type */
/*2507*/    OP_BEGIN_LEN, 1, 6008, 8, /* _length */
/*2511*/    OP_COPYVAR, 20, 6016, 20, /* session_id */
/*2515*/    OP_END_LEN,
/*2516*/    OP_COPY, 1, 6176, 8, /* _type */
/*2520*/    OP_BEGIN_LEN, 1, 6184, 8, /* _length */
/*2524*/    OP_COPYVAR, 21, 6192, 4, /* resource_id */
/*2528*/    OP_END_LEN,
/*2529*/    OP_JUMP, 4,
/*2531*/    OP_COPYVAR, 22, 6224, 28, /* unrecognized_git_identifiers */
/*2535*/    OP_END_LEN,
/*2536*/    OP_IFGROUP, 177, 68,
/*2539*/    OP_COPY, 1, 6448, 8, /* ATM_IE_GIT */
/*2543*/    OP_COPY, 0, 6463, 1, /* _ext */
/*2547*/    OP_COPY, 0, 6461, 2, /* _cs */
/*2551*/    OP_COPY, 0, 6460, 1, /* _flag */
/*2555*/    OP_COPY, 1, 6456, 3, /* _action_ind */
/*2559*/    OP_BEGIN_LEN, 2, 6464, 16, /* _ie_len */
/*2563*/    OP_COPY, 1, 6487, 1, /* _dummy */
/*2567*/    OP_COPY, 1, 6488, 7, /* id_std_app */
/*2571*/    OP_IFGROUP, 178, 28,
/*2574*/    OP_COPY, 1, 6496, 8, /* _type */
/*2578*/    OP_BEGIN_LEN, 1, 6504, 8, /* _length */
/*2582*/    OP_COPYVAR, 23, 6512, 20, /* session_id */
/*2586*/    OP_END_LEN,
/*2587*/    OP_COPY, 1, 6672, 8, /* _type */
/*2591*/    OP_BEGIN_LEN, 1, 6680, 8, /* _length */
/*2595*/    OP_COPYVAR, 24, 6688, 4, /* resource_id */
/*2599*/    OP_END_LEN,
/*2600*/    OP_JUMP, 4,
/*2602*/    OP_COPYVAR, 25, 6720, 28, /* unrecognized_git_identifiers */
/*2606*/    OP_END_LEN,
/*2607*/    OP_IFGROUP, 180, 37,
/*2610*/    OP_COPY, 1, 6944, 8, /* ATM_IE_LIJ_ID */
/*2614*/    OP_COPY, 0, 6959, 1, /* _ext */
/*2618*/    OP_COPY, 0, 6957, 2, /* _cs */
/*2622*/    OP_COPY, 0, 6956, 1, /* _flag */
/*2626*/    OP_COPY, 1, 6952, 3, /* _action_ind */
/*2630*/    OP_BEGIN_LEN, 2, 6960, 16, /* _ie_len */
/*2634*/    OP_COPY, 0, 6983, 1, /* _ext */
/*2638*/    OP_COPY, 1, 6976, 7, /* lij_id_type */
/*2642*/    OP_COPY, 4, 6984, 32, /* lij_id */
/*2646*/    OP_END_LEN,
/*2647*/    OP_IFGROUP, 181, 33,
/*2650*/    OP_COPY, 1, 7016, 8, /* ATM_IE_LIJ_PRM */
/*2654*/    OP_COPY, 0, 7031, 1, /* _ext */
/*2658*/    OP_COPY, 0, 7029, 2, /* _cs */
/*2662*/    OP_COPY, 0, 7028, 1, /* _flag */
/*2666*/    OP_COPY, 1, 7024, 3, /* _action_ind */
/*2670*/    OP_BEGIN_LEN, 2, 7032, 16, /* _ie_len */
/*2674*/    OP_COPY, 0, 7055, 1, /* _ext */
/*2678*/    OP_COPY, 1, 7048, 2, /* lij_scr_ind */
/*2682*/    OP_END_LEN,
/*2683*/    OP_IFGROUP, 182, 29,
/*2686*/    OP_COPY, 1, 7056, 8, /* ATM_IE_LEAF_SN */
/*2690*/    OP_COPY, 0, 7071, 1, /* _ext */
/*2694*/    OP_COPY, 0, 7069, 2, /* _cs */
/*2698*/    OP_COPY, 0, 7068, 1, /* _flag */
/*2702*/    OP_COPY, 1, 7064, 3, /* _action_ind */
/*2706*/    OP_BEGIN_LEN, 2, 7072, 16, /* _ie_len */
/*2710*/    OP_COPY, 4, 7088, 32, /* leaf_sn */
/*2714*/    OP_END_LEN,
/*2715*/    OP_IFGROUP, 183, 37,
/*2718*/    OP_COPY, 1, 7120, 8, /* ATM_IE_SCOPE_SEL */
/*2722*/    OP_COPY, 0, 7135, 1, /* _ext */
/*2726*/    OP_COPY, 0, 7133, 2, /* _cs */
/*2730*/    OP_COPY, 0, 7132, 1, /* _flag */
/*2734*/    OP_COPY, 1, 7128, 3, /* _action_ind */
/*2738*/    OP_BEGIN_LEN, 2, 7136, 16, /* _ie_len */
/*2742*/    OP_COPY, 0, 7159, 1, /* _ext */
/*2746*/    OP_COPY, 1, 7152, 4, /* scope_type */
/*2750*/    OP_COPY, 1, 7160, 8, /* scope_sel */
/*2754*/    OP_END_LEN,
/*2755*/    OP_IFGROUP, 184, 168,
/*2758*/    OP_COPY, 1, 7168, 8, /* ATM_IE_ALT_TD */
/*2762*/    OP_COPY, 0, 7183, 1, /* _ext */
/*2766*/    OP_COPY, 0, 7181, 2, /* _cs */
/*2770*/    OP_COPY, 0, 7180, 1, /* _flag */
/*2774*/    OP_COPY, 1, 7176, 3, /* _action_ind */
/*2778*/    OP_BEGIN_LEN, 2, 7184, 16, /* _ie_len */
/*2782*/    OP_IFGROUP, 185, 8,
/*2785*/    OP_COPY, 1, 7200, 8, /* ATM_TD_FW_PCR_0 */
/*2789*/    OP_COPY, 3, 7208, 24, /* altfw_pcr_0 */
/*2793*/    OP_IFGROUP, 186, 8,
/*2796*/    OP_COPY, 1, 7232, 8, /* ATM_TD_BW_PCR_0 */
/*2800*/    OP_COPY, 3, 7240, 24, /* altbw_pcr_0 */
/*2804*/    OP_IFGROUP, 187, 8,
/*2807*/    OP_COPY, 1, 7264, 8, /* ATM_TD_FW_PCR_01 */
/*2811*/    OP_COPY, 3, 7272, 24, /* altfw_pcr_01 */
/*2815*/    OP_IFGROUP, 188, 8,
/*2818*/    OP_COPY, 1, 7296, 8, /* ATM_TD_BW_PCR_01 */
/*2822*/    OP_COPY, 3, 7304, 24, /* altbw_pcr_01 */
/*2826*/    OP_IFGROUP, 189, 8,
/*2829*/    OP_COPY, 1, 7328, 8, /* ATM_TD_FW_SCR_0 */
/*2833*/    OP_COPY, 3, 7336, 24, /* altfw_scr_0 */
/*2837*/    OP_IFGROUP, 190, 8,
/*2840*/    OP_COPY, 1, 7360, 8, /* ATM_TD_BW_SCR_0 */
/*2844*/    OP_COPY, 3, 7368, 24, /* altbw_scr_0 */
/*2848*/    OP_IFGROUP, 191, 8,
/*2851*/    OP_COPY, 1, 7392, 8, /* ATM_TD_FW_SCR_01 */
/*2855*/    OP_COPY, 3, 7400, 24, /* altfw_scr_01 */
/*2859*/    OP_IFGROUP, 192, 8,
/*2862*/    OP_COPY, 1, 7424, 8, /* ATM_TD_BW_SCR_01 */
/*2866*/    OP_COPY, 3, 7432, 24, /* altbw_scr_01 */
/*2870*/    OP_IFGROUP, 193, 8,
/*2873*/    OP_COPY, 1, 7456, 8, /* ATM_TD_FW_MBS_0 */
/*2877*/    OP_COPY, 3, 7464, 24, /* altfw_mbs_0 */
/*2881*/    OP_IFGROUP, 194, 8,
/*2884*/    OP_COPY, 1, 7488, 8, /* ATM_TD_BW_MBS_0 */
/*2888*/    OP_COPY, 3, 7496, 24, /* altbw_mbs_0 */
/*2892*/    OP_IFGROUP, 195, 8,
/*2895*/    OP_COPY, 1, 7520, 8, /* ATM_TD_FW_MBS_01 */
/*2899*/    OP_COPY, 3, 7528, 24, /* altfw_mbs_01 */
/*2903*/    OP_IFGROUP, 196, 8,
/*2906*/    OP_COPY, 1, 7552, 8, /* ATM_TD_BW_MBS_01 */
/*2910*/    OP_COPY, 3, 7560, 24, /* altbw_mbs_01 */
/*2914*/    OP_IFGROUP, 197, 8,
/*2917*/    OP_COPY, 1, 7584, 8, /* ATM_TD_BEST_EFFORT */
/*2921*/    OP_COPY, 0, 7592, 0, /* altbest_effort */
/*2925*/    OP_END_LEN,
/*2926*/    OP_IFGROUP, 198, 91,
/*2929*/    OP_COPY, 1, 7592, 8, /* ATM_IE_MIN_TD */
/*2933*/    OP_COPY, 0, 7607, 1, /* _ext */
/*2937*/    OP_COPY, 0, 7605, 2, /* _cs */
/*2941*/    OP_COPY, 0, 7604, 1, /* _flag */
/*2945*/    OP_COPY, 1, 7600, 3, /* _action_ind */
/*2949*/    OP_BEGIN_LEN, 2, 7608, 16, /* _ie_len */
/*2953*/    OP_IFGROUP, 199, 8,
/*2956*/    OP_COPY, 1, 7624, 8, /* ATM_TD_FW_PCR_0 */
/*2960*/    OP_COPY, 3, 7632, 24, /* minfw_pcr_0 */
/*2964*/    OP_IFGROUP, 200, 8,
/*2967*/    OP_COPY, 1, 7656, 8, /* ATM_TD_BW_PCR_0 */
/*2971*/    OP_COPY, 3, 7664, 24, /* minbw_pcr_0 */
/*2975*/    OP_IFGROUP, 201, 8,
/*2978*/    OP_COPY, 1, 7688, 8, /* ATM_TD_FW_PCR_01 */
/*2982*/    OP_COPY, 3, 7696, 24, /* minfw_pcr_01 */
/*2986*/    OP_IFGROUP, 202, 8,
/*2989*/    OP_COPY, 1, 7720, 8, /* ATM_TD_BW_PCR_01 */
/*2993*/    OP_COPY, 3, 7728, 24, /* minbw_pcr_01 */
/*2997*/    OP_IFGROUP, 203, 8,
/*3000*/    OP_COPY, 1, 7752, 8, /* ATM_TD_FW_MCR_01 */
/*3004*/    OP_COPY, 3, 7760, 24, /* minfw_mcr_01 */
/*3008*/    OP_IFGROUP, 204, 8,
/*3011*/    OP_COPY, 1, 7784, 8, /* ATM_TD_BW_MCR_01 */
/*3015*/    OP_COPY, 3, 7792, 24, /* minbw_mcr_01 */
/*3019*/    OP_END_LEN,
/*3020*/    OP_IFGROUP, 205, 95,
/*3023*/    OP_COPY, 1, 7816, 8, /* ATM_IE_EQOS */
/*3027*/    OP_COPY, 0, 7831, 1, /* _ext */
/*3031*/    OP_COPY, 0, 7829, 2, /* _cs */
/*3035*/    OP_COPY, 0, 7828, 1, /* _flag */
/*3039*/    OP_COPY, 1, 7824, 3, /* _action_ind */
/*3043*/    OP_BEGIN_LEN, 2, 7832, 16, /* _ie_len */
/*3047*/    OP_COPY, 1, 7848, 8, /* eqos_origin */
/*3051*/    OP_IFGROUP, 206, 8,
/*3054*/    OP_COPY, 1, 7856, 8, /* ATM_EQP_ACC_FW_CDV */
/*3058*/    OP_COPY, 3, 7864, 24, /* acc_fw_cdv */
/*3062*/    OP_IFGROUP, 207, 8,
/*3065*/    OP_COPY, 1, 7888, 8, /* ATM_EQP_ACC_BW_CDV */
/*3069*/    OP_COPY, 3, 7896, 24, /* acc_bw_cdv */
/*3073*/    OP_IFGROUP, 208, 8,
/*3076*/    OP_COPY, 1, 7920, 8, /* ATM_EQP_CUM_FW_CDV */
/*3080*/    OP_COPY, 3, 7928, 24, /* cum_fw_cdv */
/*3084*/    OP_IFGROUP, 209, 8,
/*3087*/    OP_COPY, 1, 7952, 8, /* ATM_EQP_CUM_BW_CDV */
/*3091*/    OP_COPY, 3, 7960, 24, /* cum_bw_cdv */
/*3095*/    OP_IFGROUP, 210, 8,
/*3098*/    OP_COPY, 1, 7984, 8, /* ATM_EQP_ACC_FW_CLR */
/*3102*/    OP_COPY, 1, 7992, 8, /* acc_fw_clr */
/*3106*/    OP_IFGROUP, 211, 8,
/*3109*/    OP_COPY, 1, 8000, 8, /* ATM_EQP_ACC_BW_CLR */
/*3113*/    OP_COPY, 1, 8008, 8, /* acc_bw_clr */
/*3117*/    OP_END_LEN,
/*3118*/    OP_IFGROUP, 212, 47,
/*3121*/    OP_COPY, 1, 8016, 8, /* ATM_IE_ABR_ADD_PRM */
/*3125*/    OP_COPY, 0, 8031, 1, /* _ext */
/*3129*/    OP_COPY, 0, 8029, 2, /* _cs */
/*3133*/    OP_COPY, 0, 8028, 1, /* _flag */
/*3137*/    OP_COPY, 1, 8024, 3, /* _action_ind */
/*3141*/    OP_BEGIN_LEN, 2, 8032, 16, /* _ie_len */
/*3145*/    OP_IFGROUP, 213, 8,
/*3148*/    OP_COPY, 1, 8048, 8, /* ATM_AAP_FW_REC */
/*3152*/    OP_COPY, 4, 8056, 32, /* abr_fw_add_rec */
/*3156*/    OP_IFGROUP, 214, 8,
/*3159*/    OP_COPY, 1, 8088, 8, /* ATM_AAP_BW_REC */
/*3163*/    OP_COPY, 4, 8096, 32, /* abr_bw_add_rec */
/*3167*/    OP_END_LEN,
/*3168*/    OP_IFGROUP, 215, 124,
/*3171*/    OP_COPY, 1, 8128, 8, /* ATM_IE_ABR_SET_PRM */
/*3175*/    OP_COPY, 0, 8143, 1, /* _ext */
/*3179*/    OP_COPY, 0, 8141, 2, /* _cs */
/*3183*/    OP_COPY, 0, 8140, 1, /* _flag */
/*3187*/    OP_COPY, 1, 8136, 3, /* _action_ind */
/*3191*/    OP_BEGIN_LEN, 2, 8144, 16, /* _ie_len */
/*3195*/    OP_IFGROUP, 216, 8,
/*3198*/    OP_COPY, 1, 8160, 8, /* ATM_ASP_FW_ICR */
/*3202*/    OP_COPY, 3, 8168, 24, /* abr_fw_icr */
/*3206*/    OP_IFGROUP, 217, 8,
/*3209*/    OP_COPY, 1, 8192, 8, /* ATM_ASP_BW_ICR */
/*3213*/    OP_COPY, 3, 8200, 24, /* abr_bw_icr */
/*3217*/    OP_IFGROUP, 218, 8,
/*3220*/    OP_COPY, 1, 8224, 8, /* ATM_ASP_FW_TBE */
/*3224*/    OP_COPY, 3, 8232, 24, /* abr_fw_tbe */
/*3228*/    OP_IFGROUP, 219, 8,
/*3231*/    OP_COPY, 1, 8256, 8, /* ATM_ASP_BW_TBE */
/*3235*/    OP_COPY, 3, 8264, 24, /* abr_bw_tbe */
/*3239*/    OP_IFGROUP, 220, 8,
/*3242*/    OP_COPY, 1, 8288, 8, /* ATM_ASP_CRF_RTT */
/*3246*/    OP_COPY, 3, 8296, 24, /* atm_crf_rtt */
/*3250*/    OP_IFGROUP, 221, 8,
/*3253*/    OP_COPY, 1, 8320, 8, /* ATM_ASP_FW_RIF */
/*3257*/    OP_COPY, 1, 8328, 8, /* atm_fw_rif */
/*3261*/    OP_IFGROUP, 222, 8,
/*3264*/    OP_COPY, 1, 8336, 8, /* ATM_ASP_BW_RIF */
/*3268*/    OP_COPY, 1, 8344, 8, /* atm_bw_rif */
/*3272*/    OP_IFGROUP, 223, 8,
/*3275*/    OP_COPY, 1, 8352, 8, /* ATM_ASP_FW_RDF */
/*3279*/    OP_COPY, 1, 8360, 8, /* atm_fw_rdf */
/*3283*/    OP_IFGROUP, 224, 8,
/*3286*/    OP_COPY, 1, 8368, 8, /* ATM_ASP_BW_RDF */
/*3290*/    OP_COPY, 1, 8376, 8, /* atm_bw_rdf */
/*3294*/    OP_END_LEN,
/*3295*/    OP_IFGROUP, 225, 33,
/*3298*/    OP_COPY, 1, 8384, 8, /* ATM_IE_EPR */
/*3302*/    OP_COPY, 0, 8399, 1, /* _ext */
/*3306*/    OP_COPY, 0, 8397, 2, /* _cs */
/*3310*/    OP_COPY, 0, 8396, 1, /* _flag */
/*3314*/    OP_COPY, 1, 8392, 3, /* _action_ind */
/*3318*/    OP_BEGIN_LEN, 2, 8400, 16, /* _ie_len */
/*3322*/    OP_COPY, 1, 8416, 8, /* _ep_type */
/*3326*/    OP_COPY, 2, 8424, 16, /* ep_ref */
/*3330*/    OP_END_LEN,
/*3331*/    OP_IFGROUP, 226, 29,
/*3334*/    OP_COPY, 1, 8440, 8, /* ATM_IE_EP_STATE */
/*3338*/    OP_COPY, 0, 8455, 1, /* _ext */
/*3342*/    OP_COPY, 0, 8453, 2, /* _cs */
/*3346*/    OP_COPY, 0, 8452, 1, /* _flag */
/*3350*/    OP_COPY, 1, 8448, 3, /* _action_ind */
/*3354*/    OP_BEGIN_LEN, 2, 8456, 16, /* _ie_len */
/*3358*/    OP_COPY, 1, 8472, 6, /* ep_state */
/*3362*/    OP_END_LEN,
/*3363*/    OP_IFGROUP, 227, 29,
/*3366*/    OP_COPY, 1, 8480, 8, /* ATM_IE_BBRT */
/*3370*/    OP_COPY, 0, 8495, 1, /* _ext */
/*3374*/    OP_COPY, 0, 8493, 2, /* _cs */
/*3378*/    OP_COPY, 0, 8492, 1, /* _flag */
/*3382*/    OP_COPY, 1, 8488, 3, /* _action_ind */
/*3386*/    OP_BEGIN_LEN, 2, 8496, 16, /* _ie_len */
/*3390*/    OP_COPY, 1, 8512, 8, /* type_of_report */
/*3394*/    OP_END_LEN,
/*3395*/    OP_IFGROUP, 228, 25,
/*3398*/    OP_COPY, 1, 8520, 8, /* 0 */
/*3402*/    OP_COPY, 0, 8535, 1, /* _ext */
/*3406*/    OP_COPY, 0, 8533, 2, /* __cs */
/*3410*/    OP_COPY, 0, 8532, 1, /* _flag */
/*3414*/    OP_COPY, 1, 8528, 3, /* _action_ind */
/*3418*/    OP_BEGIN_LEN, 2, 8536, 16, /* _ie_len */
/*3422*/    OP_END_LEN,
/*3423*/    OP_END_LEN,
/*3424*/    OP_END
};


/*
 * "Microcode" used to parse messages. It detects the
 * presence of fields and copies them from the message to the
 * construction area.
 */

static int parse[] = {
    OP_COPY, 1, 0, 8, /* _pdsc */
/*   4*/    OP_COPY, 1, 8, 8, /* _cr_len */
/*   8*/    OP_COPY, 3, 16, 24, /* call_ref */
/*  12*/    OP_COPY, 1, 40, 8, /* msg_type */
/*  16*/    OP_COPY, 1, 48, 2, /* _action_ind */
/*  20*/    OP_BEGIN_LEN, 2, 56, 16, /* msg_len */
/*  24*/    OP_IFEND, 3151, /* _ie_id */
/*  26*/    OP_CASE, 1, 0, 8, 39, /* _ie_id */
/*  31*/    ATM_IE_AAL, 1, 114,
/*  34*/    ATM_IE_TD, 7, 182,
/*  37*/    ATM_IE_BBCAP, 22, 340,
/*  40*/    ATM_IE_BHLI, 25, 382,
/*  43*/    ATM_IE_BLLI, 31, 451,
/*  46*/    ATM_IE_BLLI, 62, 797,
/*  49*/    ATM_IE_BLLI, 93, 1143,
/*  52*/    ATM_IE_CALL_STATE, 124, 1489,
/*  55*/    ATM_IE_CDPN, 125, 1506,
/*  58*/    ATM_IE_CDPS, 128, 1548,
/*  61*/    ATM_IE_CGPN, 129, 1573,
/*  64*/    ATM_IE_CGPS, 132, 1619,
/*  67*/    ATM_IE_CAUSE, 133, 1644,
/*  70*/    ATM_IE_CAUSE, 146, 1840,
/*  73*/    ATM_IE_CONN_ID, 159, 2036,
/*  76*/    ATM_IE_E2E_TDL, 160, 2061,
/*  79*/    ATM_IE_QOS, 164, 2104,
/*  82*/    ATM_IE_BBREP, 165, 2129,
/*  85*/    ATM_IE_RESTART, 166, 2146,
/*  88*/    ATM_IE_BBS_COMP, 167, 2163,
/*  91*/    ATM_IE_TNS, 168, 2180,
/*  94*/    ATM_IE_NOTIFY, 169, 2201,
/*  97*/    ATM_IE_OAM_TD, 170, 2218,
/* 100*/    ATM_IE_GIT, 171, 2251,
/* 103*/    ATM_IE_GIT, 174, 2318,
/* 106*/    ATM_IE_GIT, 177, 2385,
/* 109*/    ATM_IE_LIJ_ID, 180, 2452,
/* 112*/    ATM_IE_LIJ_PRM, 181, 2473,
/* 115*/    ATM_IE_LEAF_SN, 182, 2490,
/* 118*/    ATM_IE_SCOPE_SEL, 183, 2507,
/* 121*/    ATM_IE_ALT_TD, 184, 2528,
/* 124*/    ATM_IE_MIN_TD, 198, 2665,
/* 127*/    ATM_IE_EQOS, 205, 2739,
/* 130*/    ATM_IE_ABR_ADD_PRM, 212, 2817,
/* 133*/    ATM_IE_ABR_SET_PRM, 215, 2855,
/* 136*/    ATM_IE_EPR, 225, 2956,
/* 139*/    ATM_IE_EP_STATE, 226, 2977,
/* 142*/    ATM_IE_BBRT, 227, 2994,
/* 145*/    -1, 228, 3011,
/* 148*/    OP_COPY, 1, 80, 3, /* _action_ind */
/* 152*/    OP_BEGIN_LEN, 2, 88, 16, /* _ie_len */
/* 156*/    OP_BEGIN_REC, RECOV_IND_IE, 1, 216,
/* 160*/    OP_COPY, 0, 104, 8, /* aal_type */
/* 164*/    OP_CASE, 1, 104, 8, 1, /* aal_type */
/* 169*/    5, 2, 0,
/* 172*/    OP_IFEND, 41, /* _id */
/* 174*/    OP_CASE, 1, 0, 8, 4, /* _id */
/* 179*/    ATM_AALP_FW_MAX_SDU, 3, 9,
/* 182*/    ATM_AALP_BW_MAX_SDU, 4, 12,
/* 185*/    ATM_AALP_AAL_MODE, 5, 15,
/* 188*/    ATM_AALP_SSCS, 6, 18,
/* 191*/    OP_COPY, 2, 120, 16, /* fw_max_sdu */
/* 195*/    OP_JUMP, 16,
/* 197*/    OP_COPY, 2, 144, 16, /* bw_max_sdu */
/* 201*/    OP_JUMP, 10,
/* 203*/    OP_COPY, 1, 168, 8, /* aal_mode */
/* 207*/    OP_JUMP, 4,
/* 209*/    OP_COPY, 1, 184, 8, /* sscs_type */
/* 213*/    OP_JUMP, -43,
/* 215*/    OP_END_REC,
/* 216*/    OP_END_LEN,  /* _ie_len */
/* 217*/    OP_JUMP, 2956,
/* 219*/    OP_COPY, 1, 200, 3, /* _action_ind */
/* 223*/    OP_BEGIN_LEN, 2, 208, 16, /* _ie_len */
/* 227*/    OP_BEGIN_REC, RECOV_IND_IE, 7, 377,
/* 231*/    OP_IFEND, 143, /* _id */
/* 233*/    OP_CASE, 1, 0, 8, 14, /* _id */
/* 238*/    ATM_TD_FW_PCR_0, 8, 39,
/* 241*/    ATM_TD_BW_PCR_0, 9, 42,
/* 244*/    ATM_TD_FW_PCR_01, 10, 45,
/* 247*/    ATM_TD_BW_PCR_01, 11, 48,
/* 250*/    ATM_TD_FW_SCR_0, 12, 51,
/* 253*/    ATM_TD_BW_SCR_0, 13, 54,
/* 256*/    ATM_TD_FW_SCR_01, 14, 57,
/* 259*/    ATM_TD_BW_SCR_01, 15, 60,
/* 262*/    ATM_TD_FW_MBS_0, 16, 63,
/* 265*/    ATM_TD_BW_MBS_0, 17, 66,
/* 268*/    ATM_TD_FW_MBS_01, 18, 69,
/* 271*/    ATM_TD_BW_MBS_01, 19, 72,
/* 274*/    ATM_TD_BEST_EFFORT, 20, 75,
/* 277*/    ATM_TD_TM_OPT, 21, 78,
/* 280*/    OP_COPY, 3, 232, 24, /* fw_pcr_0 */
/* 284*/    OP_JUMP, 88,
/* 286*/    OP_COPY, 3, 264, 24, /* bw_pcr_0 */
/* 290*/    OP_JUMP, 82,
/* 292*/    OP_COPY, 3, 296, 24, /* fw_pcr_01 */
/* 296*/    OP_JUMP, 76,
/* 298*/    OP_COPY, 3, 328, 24, /* bw_pcr_01 */
/* 302*/    OP_JUMP, 70,
/* 304*/    OP_COPY, 3, 360, 24, /* fw_scr_0 */
/* 308*/    OP_JUMP, 64,
/* 310*/    OP_COPY, 3, 392, 24, /* bw_scr_0 */
/* 314*/    OP_JUMP, 58,
/* 316*/    OP_COPY, 3, 424, 24, /* fw_scr_01 */
/* 320*/    OP_JUMP, 52,
/* 322*/    OP_COPY, 3, 456, 24, /* bw_scr_01 */
/* 326*/    OP_JUMP, 46,
/* 328*/    OP_COPY, 3, 488, 24, /* fw_mbs_0 */
/* 332*/    OP_JUMP, 40,
/* 334*/    OP_COPY, 3, 520, 24, /* bw_mbs_0 */
/* 338*/    OP_JUMP, 34,
/* 340*/    OP_COPY, 3, 552, 24, /* fw_mbs_01 */
/* 344*/    OP_JUMP, 28,
/* 346*/    OP_COPY, 3, 584, 24, /* bw_mbs_01 */
/* 350*/    OP_JUMP, 22,
/* 352*/    OP_COPY, 0, 616, 0, /* best_effort */
/* 356*/    OP_JUMP, 16,
/* 358*/    OP_COPY, 0, 631, 1, /* fw_fdisc */
/* 362*/    OP_COPY, 0, 630, 1, /* bw_fdisc */
/* 366*/    OP_COPY, 0, 625, 1, /* bw_tag */
/* 370*/    OP_COPY, 1, 624, 1, /* fw_tag */
/* 374*/    OP_JUMP, -145,
/* 376*/    OP_END_REC,
/* 377*/    OP_END_LEN,  /* _ie_len */
/* 378*/    OP_JUMP, 2795,
/* 380*/    OP_COPY, 1, 640, 3, /* _action_ind */
/* 384*/    OP_BEGIN_LEN, 2, 648, 16, /* _ie_len */
/* 388*/    OP_BEGIN_REC, RECOV_IND_IE, 22, 422,
/* 392*/    OP_COPY, 0, 664, 5, /* bearer_class */
/* 396*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 401*/    0, 23, 3,
/* 404*/    -1, 24, 6,
/* 407*/    OP_COPY, 1, 672, 7, /* trans_cap */
/* 411*/    OP_JUMP, 0,
/* 413*/    OP_COPY, 0, 693, 2, /* susc_clip */
/* 417*/    OP_COPY, 1, 688, 2, /* upcc */
/* 421*/    OP_END_REC,
/* 422*/    OP_END_LEN,  /* _ie_len */
/* 423*/    OP_JUMP, 2750,
/* 425*/    OP_COPY, 1, 704, 3, /* _action_ind */
/* 429*/    OP_BEGIN_LEN, 2, 712, 16, /* _ie_len */
/* 433*/    OP_BEGIN_REC, RECOV_IND_IE, 25, 494,
/* 437*/    OP_COPY, 0, 728, 7, /* hli_type */
/* 441*/    OP_CASE, 1, 728, 7, 5, /* hli_type */
/* 446*/    0, 26, 12,
/* 449*/    1, 27, 15,
/* 452*/    2, 28, 18,
/* 455*/    3, 29, 21,
/* 458*/    4, 30, 28,
/* 461*/    OP_COPYVAR, 0, 736, 8, /* iso_hli */
/* 465*/    OP_JUMP, 26,
/* 467*/    OP_COPYVAR, 1, 800, 8, /* user_hli */
/* 471*/    OP_JUMP, 20,
/* 473*/    OP_COPY, 4, 864, 32, /* hlp */
/* 477*/    OP_JUMP, 14,
/* 479*/    OP_COPY, 3, 896, 24, /* hli_oui */
/* 483*/    OP_COPY, 4, 920, 32, /* app_id */
/* 487*/    OP_JUMP, 4,
/* 489*/    OP_COPY, 1, 952, 8, /* tobedefined */
/* 493*/    OP_END_REC,
/* 494*/    OP_END_LEN,  /* _ie_len */
/* 495*/    OP_JUMP, 2678,
/* 497*/    OP_COPY, 1, 968, 3, /* _action_ind */
/* 501*/    OP_BEGIN_LEN, 2, 976, 16, /* _ie_len */
/* 505*/    OP_BEGIN_REC, RECOV_IND_IE, 31, 843,
/* 509*/    OP_IFEND, 331, /* _lid */
/* 511*/    OP_CASE, 0, 5, 2, 3, /* _lid */
/* 516*/    1, 32, 6,
/* 519*/    2, 33, 9,
/* 522*/    3, 41, 118,
/* 525*/    OP_COPY, 1, 992, 5, /* uil1_proto */
/* 529*/    OP_JUMP, 309,
/* 531*/    OP_COPY, 0, 1000, 5, /* uil2_proto */
/* 535*/    OP_CASE, 0, 1000, 5, 13, /* uil2_proto */
/* 540*/    ATM_L2_X25_LL, 34, 36,
/* 543*/    ATM_L2_X25_ML, 34, 33,
/* 546*/    ATM_L2_HDLC_ARM, 34, 30,
/* 549*/    ATM_L2_HDLC_NRM, 34, 27,
/* 552*/    ATM_L2_HDLC_ABM, 34, 24,
/* 555*/    ATM_L2_Q922, 34, 21,
/* 558*/    ATM_L2_ISO7776, 34, 18,
/* 561*/    ATM_L2_USER, 39, 59,
/* 564*/    -1, 40, 70,
/* 567*/    ATM_L2_Q291, 40, 67,
/* 570*/    ATM_L2_LAPB, 40, 64,
/* 573*/    ATM_L2_ISO8802, 40, 61,
/* 576*/    ATM_L2_X75, 40, 58,
/* 579*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 584*/    0, 35, 3,
/* 587*/    -1, 38, 31,
/* 590*/    OP_COPY, 0, 1013, 2, /* l2_mode */
/* 594*/    OP_COPY, 0, 1008, 2, /* q933 */
/* 598*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 603*/    0, 36, 3,
/* 606*/    -1, 37, 10,
/* 609*/    OP_COPY, 0, 1016, 7, /* window_size */
/* 613*/    OP_COPY, 1, 1023, 1, /* _ext */
/* 617*/    OP_JUMP, 0,
/* 619*/    OP_JUMP, 0,
/* 621*/    OP_JUMP, 18,
/* 623*/    OP_COPY, 1, 1047, 1, /* _ext */
/* 627*/    OP_COPY, 0, 1048, 7, /* user_l2 */
/* 631*/    OP_COPY, 1, 1055, 1, /* _ext */
/* 635*/    OP_JUMP, 4,
/* 637*/    OP_COPY, 1, 1063, 1, /* _ext */
/* 641*/    OP_JUMP, 197,
/* 643*/    OP_COPY, 0, 1064, 5, /* uil3_proto */
/* 647*/    OP_CASE, 0, 1064, 5, 6, /* uil3_proto */
/* 652*/    ATM_L3_X25, 42, 15,
/* 655*/    ATM_L3_ISO8208, 42, 12,
/* 658*/    ATM_L3_X223, 42, 9,
/* 661*/    ATM_L3_H310, 49, 63,
/* 664*/    ATM_L3_TR9577, 54, 100,
/* 667*/    ATM_L3_USER, 61, 158,
/* 670*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 675*/    0, 43, 3,
/* 678*/    -1, 48, 44,
/* 681*/    OP_COPY, 0, 1077, 2, /* l3_mode */
/* 685*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 690*/    0, 44, 3,
/* 693*/    -1, 47, 27,
/* 696*/    OP_COPY, 0, 1080, 4, /* def_pck_size */
/* 700*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 705*/    0, 45, 3,
/* 708*/    -1, 46, 10,
/* 711*/    OP_COPY, 1, 1095, 1, /* _ext */
/* 715*/    OP_COPY, 1, 1096, 7, /* pck_win_size */
/* 719*/    OP_JUMP, 0,
/* 721*/    OP_JUMP, 0,
/* 723*/    OP_JUMP, 0,
/* 725*/    OP_JUMP, 113,
/* 727*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 732*/    0, 50, 3,
/* 735*/    -1, 53, 27,
/* 738*/    OP_COPY, 0, 1136, 4, /* term_type */
/* 742*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 747*/    0, 51, 3,
/* 750*/    -1, 52, 10,
/* 753*/    OP_COPY, 0, 1147, 3, /* fw_mpx_cap */
/* 757*/    OP_COPY, 1, 1144, 3, /* bw_mpx_cap */
/* 761*/    OP_JUMP, 0,
/* 763*/    OP_JUMP, 0,
/* 765*/    OP_JUMP, 73,
/* 767*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 772*/    0, 55, 3,
/* 775*/    -1, 60, 48,
/* 778*/    OP_COPY, 0, 1176, 7, /* ipi_high */
/* 782*/    OP_CASE, 1, 1176, 7, 2, /* ipi_high */
/* 787*/    0x40, 56, 3,
/* 790*/    -1, 59, 27,
/* 793*/    OP_CASE, 1, 6, 1, 2, /* _ipi_low */
/* 798*/    0, 57, 3,
/* 801*/    -1, 58, 14,
/* 804*/    OP_COPY, 1, 1197, 2, /* _snap_id */
/* 808*/    OP_COPY, 3, 1200, 24, /* oui */
/* 812*/    OP_COPY, 2, 1224, 16, /* pid */
/* 816*/    OP_JUMP, 0,
/* 818*/    OP_JUMP, 4,
/* 820*/    OP_COPY, 1, 1254, 1, /* ipi_low */
/* 824*/    OP_JUMP, 0,
/* 826*/    OP_JUMP, 12,
/* 828*/    OP_COPY, 1, 1271, 1, /* _ext */
/* 832*/    OP_COPY, 0, 1272, 7, /* user_l3 */
/* 836*/    OP_COPY, 1, 1279, 1, /* _ext */
/* 840*/    OP_JUMP, -333,
/* 842*/    OP_END_REC,
/* 843*/    OP_END_LEN,  /* _ie_len */
/* 844*/    OP_JUMP, 2329,
/* 846*/    OP_COPY, 1, 1288, 3, /* _action_ind */
/* 850*/    OP_BEGIN_LEN, 2, 1296, 16, /* _ie_len */
/* 854*/    OP_BEGIN_REC, RECOV_IND_IE, 62, 1192,
/* 858*/    OP_IFEND, 331, /* _lid */
/* 860*/    OP_CASE, 0, 5, 2, 3, /* _lid */
/* 865*/    1, 63, 6,
/* 868*/    2, 64, 9,
/* 871*/    3, 72, 118,
/* 874*/    OP_COPY, 1, 1312, 5, /* uil1_proto */
/* 878*/    OP_JUMP, 309,
/* 880*/    OP_COPY, 0, 1320, 5, /* uil2_proto */
/* 884*/    OP_CASE, 0, 1320, 5, 13, /* uil2_proto */
/* 889*/    ATM_L2_X25_LL, 65, 36,
/* 892*/    ATM_L2_X25_ML, 65, 33,
/* 895*/    ATM_L2_HDLC_ARM, 65, 30,
/* 898*/    ATM_L2_HDLC_NRM, 65, 27,
/* 901*/    ATM_L2_HDLC_ABM, 65, 24,
/* 904*/    ATM_L2_Q922, 65, 21,
/* 907*/    ATM_L2_ISO7776, 65, 18,
/* 910*/    ATM_L2_USER, 70, 59,
/* 913*/    -1, 71, 70,
/* 916*/    ATM_L2_Q291, 71, 67,
/* 919*/    ATM_L2_LAPB, 71, 64,
/* 922*/    ATM_L2_ISO8802, 71, 61,
/* 925*/    ATM_L2_X75, 71, 58,
/* 928*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 933*/    0, 66, 3,
/* 936*/    -1, 69, 31,
/* 939*/    OP_COPY, 0, 1333, 2, /* l2_mode */
/* 943*/    OP_COPY, 0, 1328, 2, /* q933 */
/* 947*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/* 952*/    0, 67, 3,
/* 955*/    -1, 68, 10,
/* 958*/    OP_COPY, 0, 1336, 7, /* window_size */
/* 962*/    OP_COPY, 1, 1343, 1, /* _ext */
/* 966*/    OP_JUMP, 0,
/* 968*/    OP_JUMP, 0,
/* 970*/    OP_JUMP, 18,
/* 972*/    OP_COPY, 1, 1367, 1, /* _ext */
/* 976*/    OP_COPY, 0, 1368, 7, /* user_l2 */
/* 980*/    OP_COPY, 1, 1375, 1, /* _ext */
/* 984*/    OP_JUMP, 4,
/* 986*/    OP_COPY, 1, 1383, 1, /* _ext */
/* 990*/    OP_JUMP, 197,
/* 992*/    OP_COPY, 0, 1384, 5, /* uil3_proto */
/* 996*/    OP_CASE, 0, 1384, 5, 6, /* uil3_proto */
/*1001*/    ATM_L3_X25, 73, 15,
/*1004*/    ATM_L3_ISO8208, 73, 12,
/*1007*/    ATM_L3_X223, 73, 9,
/*1010*/    ATM_L3_H310, 80, 63,
/*1013*/    ATM_L3_TR9577, 85, 100,
/*1016*/    ATM_L3_USER, 92, 158,
/*1019*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1024*/    0, 74, 3,
/*1027*/    -1, 79, 44,
/*1030*/    OP_COPY, 0, 1397, 2, /* l3_mode */
/*1034*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1039*/    0, 75, 3,
/*1042*/    -1, 78, 27,
/*1045*/    OP_COPY, 0, 1400, 4, /* def_pck_size */
/*1049*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1054*/    0, 76, 3,
/*1057*/    -1, 77, 10,
/*1060*/    OP_COPY, 1, 1415, 1, /* _ext */
/*1064*/    OP_COPY, 1, 1416, 7, /* pck_win_size */
/*1068*/    OP_JUMP, 0,
/*1070*/    OP_JUMP, 0,
/*1072*/    OP_JUMP, 0,
/*1074*/    OP_JUMP, 113,
/*1076*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1081*/    0, 81, 3,
/*1084*/    -1, 84, 27,
/*1087*/    OP_COPY, 0, 1456, 4, /* term_type */
/*1091*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1096*/    0, 82, 3,
/*1099*/    -1, 83, 10,
/*1102*/    OP_COPY, 0, 1467, 3, /* fw_mpx_cap */
/*1106*/    OP_COPY, 1, 1464, 3, /* bw_mpx_cap */
/*1110*/    OP_JUMP, 0,
/*1112*/    OP_JUMP, 0,
/*1114*/    OP_JUMP, 73,
/*1116*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1121*/    0, 86, 3,
/*1124*/    -1, 91, 48,
/*1127*/    OP_COPY, 0, 1496, 7, /* ipi_high */
/*1131*/    OP_CASE, 1, 1496, 7, 2, /* ipi_high */
/*1136*/    0x40, 87, 3,
/*1139*/    -1, 90, 27,
/*1142*/    OP_CASE, 1, 6, 1, 2, /* _ipi_low */
/*1147*/    0, 88, 3,
/*1150*/    -1, 89, 14,
/*1153*/    OP_COPY, 1, 1517, 2, /* _snap_id */
/*1157*/    OP_COPY, 3, 1520, 24, /* oui */
/*1161*/    OP_COPY, 2, 1544, 16, /* pid */
/*1165*/    OP_JUMP, 0,
/*1167*/    OP_JUMP, 4,
/*1169*/    OP_COPY, 1, 1574, 1, /* ipi_low */
/*1173*/    OP_JUMP, 0,
/*1175*/    OP_JUMP, 12,
/*1177*/    OP_COPY, 1, 1591, 1, /* _ext */
/*1181*/    OP_COPY, 0, 1592, 7, /* user_l3 */
/*1185*/    OP_COPY, 1, 1599, 1, /* _ext */
/*1189*/    OP_JUMP, -333,
/*1191*/    OP_END_REC,
/*1192*/    OP_END_LEN,  /* _ie_len */
/*1193*/    OP_JUMP, 1980,
/*1195*/    OP_COPY, 1, 1608, 3, /* _action_ind */
/*1199*/    OP_BEGIN_LEN, 2, 1616, 16, /* _ie_len */
/*1203*/    OP_BEGIN_REC, RECOV_IND_IE, 93, 1541,
/*1207*/    OP_IFEND, 331, /* _lid */
/*1209*/    OP_CASE, 0, 5, 2, 3, /* _lid */
/*1214*/    1, 94, 6,
/*1217*/    2, 95, 9,
/*1220*/    3, 103, 118,
/*1223*/    OP_COPY, 1, 1632, 5, /* uil1_proto */
/*1227*/    OP_JUMP, 309,
/*1229*/    OP_COPY, 0, 1640, 5, /* uil2_proto */
/*1233*/    OP_CASE, 0, 1640, 5, 13, /* uil2_proto */
/*1238*/    ATM_L2_X25_LL, 96, 36,
/*1241*/    ATM_L2_X25_ML, 96, 33,
/*1244*/    ATM_L2_HDLC_ARM, 96, 30,
/*1247*/    ATM_L2_HDLC_NRM, 96, 27,
/*1250*/    ATM_L2_HDLC_ABM, 96, 24,
/*1253*/    ATM_L2_Q922, 96, 21,
/*1256*/    ATM_L2_ISO7776, 96, 18,
/*1259*/    ATM_L2_USER, 101, 59,
/*1262*/    -1, 102, 70,
/*1265*/    ATM_L2_Q291, 102, 67,
/*1268*/    ATM_L2_LAPB, 102, 64,
/*1271*/    ATM_L2_ISO8802, 102, 61,
/*1274*/    ATM_L2_X75, 102, 58,
/*1277*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1282*/    0, 97, 3,
/*1285*/    -1, 100, 31,
/*1288*/    OP_COPY, 0, 1653, 2, /* l2_mode */
/*1292*/    OP_COPY, 0, 1648, 2, /* q933 */
/*1296*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1301*/    0, 98, 3,
/*1304*/    -1, 99, 10,
/*1307*/    OP_COPY, 0, 1656, 7, /* window_size */
/*1311*/    OP_COPY, 1, 1663, 1, /* _ext */
/*1315*/    OP_JUMP, 0,
/*1317*/    OP_JUMP, 0,
/*1319*/    OP_JUMP, 18,
/*1321*/    OP_COPY, 1, 1687, 1, /* _ext */
/*1325*/    OP_COPY, 0, 1688, 7, /* user_l2 */
/*1329*/    OP_COPY, 1, 1695, 1, /* _ext */
/*1333*/    OP_JUMP, 4,
/*1335*/    OP_COPY, 1, 1703, 1, /* _ext */
/*1339*/    OP_JUMP, 197,
/*1341*/    OP_COPY, 0, 1704, 5, /* uil3_proto */
/*1345*/    OP_CASE, 0, 1704, 5, 6, /* uil3_proto */
/*1350*/    ATM_L3_X25, 104, 15,
/*1353*/    ATM_L3_ISO8208, 104, 12,
/*1356*/    ATM_L3_X223, 104, 9,
/*1359*/    ATM_L3_H310, 111, 63,
/*1362*/    ATM_L3_TR9577, 116, 100,
/*1365*/    ATM_L3_USER, 123, 158,
/*1368*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1373*/    0, 105, 3,
/*1376*/    -1, 110, 44,
/*1379*/    OP_COPY, 0, 1717, 2, /* l3_mode */
/*1383*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1388*/    0, 106, 3,
/*1391*/    -1, 109, 27,
/*1394*/    OP_COPY, 0, 1720, 4, /* def_pck_size */
/*1398*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1403*/    0, 107, 3,
/*1406*/    -1, 108, 10,
/*1409*/    OP_COPY, 1, 1735, 1, /* _ext */
/*1413*/    OP_COPY, 1, 1736, 7, /* pck_win_size */
/*1417*/    OP_JUMP, 0,
/*1419*/    OP_JUMP, 0,
/*1421*/    OP_JUMP, 0,
/*1423*/    OP_JUMP, 113,
/*1425*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1430*/    0, 112, 3,
/*1433*/    -1, 115, 27,
/*1436*/    OP_COPY, 0, 1776, 4, /* term_type */
/*1440*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1445*/    0, 113, 3,
/*1448*/    -1, 114, 10,
/*1451*/    OP_COPY, 0, 1787, 3, /* fw_mpx_cap */
/*1455*/    OP_COPY, 1, 1784, 3, /* bw_mpx_cap */
/*1459*/    OP_JUMP, 0,
/*1461*/    OP_JUMP, 0,
/*1463*/    OP_JUMP, 73,
/*1465*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1470*/    0, 117, 3,
/*1473*/    -1, 122, 48,
/*1476*/    OP_COPY, 0, 1816, 7, /* ipi_high */
/*1480*/    OP_CASE, 1, 1816, 7, 2, /* ipi_high */
/*1485*/    0x40, 118, 3,
/*1488*/    -1, 121, 27,
/*1491*/    OP_CASE, 1, 6, 1, 2, /* _ipi_low */
/*1496*/    0, 119, 3,
/*1499*/    -1, 120, 14,
/*1502*/    OP_COPY, 1, 1837, 2, /* _snap_id */
/*1506*/    OP_COPY, 3, 1840, 24, /* oui */
/*1510*/    OP_COPY, 2, 1864, 16, /* pid */
/*1514*/    OP_JUMP, 0,
/*1516*/    OP_JUMP, 4,
/*1518*/    OP_COPY, 1, 1894, 1, /* ipi_low */
/*1522*/    OP_JUMP, 0,
/*1524*/    OP_JUMP, 12,
/*1526*/    OP_COPY, 1, 1911, 1, /* _ext */
/*1530*/    OP_COPY, 0, 1912, 7, /* user_l3 */
/*1534*/    OP_COPY, 1, 1919, 1, /* _ext */
/*1538*/    OP_JUMP, -333,
/*1540*/    OP_END_REC,
/*1541*/    OP_END_LEN,  /* _ie_len */
/*1542*/    OP_JUMP, 1631,
/*1544*/    OP_COPY, 1, 1928, 3, /* _action_ind */
/*1548*/    OP_BEGIN_LEN, 2, 1936, 16, /* _ie_len */
/*1552*/    OP_BEGIN_REC, RECOV_IND_IE, 124, 1561,
/*1556*/    OP_COPY, 1, 1952, 6, /* call_state */
/*1560*/    OP_END_REC,
/*1561*/    OP_END_LEN,  /* _ie_len */
/*1562*/    OP_JUMP, 1611,
/*1564*/    OP_COPY, 1, 1968, 3, /* _action_ind */
/*1568*/    OP_BEGIN_LEN, 2, 1976, 16, /* _ie_len */
/*1572*/    OP_BEGIN_REC, RECOV_IND_IE, 125, 1606,
/*1576*/    OP_CASE, 0, 0, 4, 2, /* _plan */
/*1581*/    ATM_NP_E164, 126, 3,
/*1584*/    ATM_NP_AEA, 127, 10,
/*1587*/    OP_COPY, 1, 1996, 3, /* _type */
/*1591*/    OP_COPYVAR, 2, 2000, 12, /* cdpn_e164 */
/*1595*/    OP_JUMP, 8,
/*1597*/    OP_COPY, 1, 2100, 3, /* _type */
/*1601*/    OP_COPYVAR, 3, 2104, 20, /* cdpn_esa */
/*1605*/    OP_END_REC,
/*1606*/    OP_END_LEN,  /* _ie_len */
/*1607*/    OP_JUMP, 1566,
/*1609*/    OP_COPY, 1, 2272, 3, /* _action_ind */
/*1613*/    OP_BEGIN_LEN, 2, 2280, 16, /* _ie_len */
/*1617*/    OP_BEGIN_REC, RECOV_IND_IE, 128, 1634,
/*1621*/    OP_COPY, 0, 2300, 3, /* cdps_type */
/*1625*/    OP_COPY, 1, 2299, 1, /* _oddeven */
/*1629*/    OP_COPYVAR, 4, 2304, 20, /* cdps */
/*1633*/    OP_END_REC,
/*1634*/    OP_END_LEN,  /* _ie_len */
/*1635*/    OP_JUMP, 1538,
/*1637*/    OP_COPY, 1, 2472, 3, /* _action_ind */
/*1641*/    OP_BEGIN_LEN, 2, 2480, 16, /* _ie_len */
/*1645*/    OP_BEGIN_REC, RECOV_IND_IE, 129, 1683,
/*1649*/    OP_COPY, 0, 2496, 4, /* cgpn_plan */
/*1653*/    OP_COPY, 0, 2500, 3, /* cgpn_type */
/*1657*/    OP_CASE, 1, 7, 1, 2, /* _ext */
/*1662*/    0, 130, 3,
/*1665*/    -1, 131, 10,
/*1668*/    OP_COPY, 0, 2509, 2, /* pres_ind */
/*1672*/    OP_COPY, 1, 2504, 2, /* scr_ind */
/*1676*/    OP_JUMP, 0,
/*1678*/    OP_COPYVAR, 5, 2520, 20, /* cgpn */
/*1682*/    OP_END_REC,
/*1683*/    OP_END_LEN,  /* _ie_len */
/*1684*/    OP_JUMP, 1489,
/*1686*/    OP_COPY, 1, 2688, 3, /* _action_ind */
/*1690*/    OP_BEGIN_LEN, 2, 2696, 16, /* _ie_len */
/*1694*/    OP_BEGIN_REC, RECOV_IND_IE, 132, 1711,
/*1698*/    OP_COPY, 0, 2716, 3, /* cgps_type */
/*1702*/    OP_COPY, 1, 2715, 1, /* _oddeven */
/*1706*/    OP_COPYVAR, 6, 2720, 20, /* cgps */
/*1710*/    OP_END_REC,
/*1711*/    OP_END_LEN,  /* _ie_len */
/*1712*/    OP_JUMP, 1461,
/*1714*/    OP_COPY, 0, 2893, 2, /* cause_cs */
/*1718*/    OP_COPY, 1, 2888, 3, /* _action_ind */
/*1722*/    OP_BEGIN_LEN, 2, 2896, 16, /* _ie_len */
/*1726*/    OP_BEGIN_REC, RECOV_IND_IE, 133, 1910,
/*1730*/    OP_COPY, 1, 2912, 4, /* location */
/*1734*/    OP_COPY, 0, 2920, 7, /* cause */
/*1738*/    OP_CASE, 1, 2920, 7, 18, /* cause */
/*1743*/    ATM_CV_UNALLOC, 134, 51,
/*1746*/    ATM_CV_NO_ROUTE_DEST, 134, 48,
/*1749*/    ATM_CV_QOS_UNAVAIL, 134, 45,
/*1752*/    ATM_CV_CALL_REJ, 135, 58,
/*1755*/    ATM_CV_NUM_CHANGED, 138, 91,
/*1758*/    ATM_CV_REJ_CLIR, 139, 96,
/*1761*/    ATM_CV_ACC_INF_DISC, 140, 101,
/*1764*/    ATM_CV_INCOMP_DEST, 140, 98,
/*1767*/    ATM_CV_MAND_IE_MISSING, 140, 95,
/*1770*/    ATM_CV_UNKNOWN_IE, 140, 92,
/*1773*/    ATM_CV_INVALID_IE, 140, 89,
/*1776*/    ATM_CV_UCR_UNAVAIL_OLD, 141, 94,
/*1779*/    ATM_CV_UCR_UNAVAIL_NEW, 141, 91,
/*1782*/    ATM_CV_NO_SUCH_CHAN, 142, 96,
/*1785*/    ATM_CV_UNKNOWN_MSG_TYPE, 143, 105,
/*1788*/    ATM_CV_INCOMP_MSG, 143, 102,
/*1791*/    ATM_CV_TIMER_EXP, 144, 107,
/*1794*/    -1, 145, 112,
/*1797*/    OP_IFEND, 111,
/*1799*/    OP_COPY, 0, 2931, 1, /* pu */
/*1803*/    OP_COPY, 0, 2930, 1, /* na */
/*1807*/    OP_COPY, 1, 2928, 2, /* cond2 */
/*1811*/    OP_JUMP, 96,
/*1813*/    OP_IFEND, 95,
/*1815*/    OP_COPY, 0, 2936, 2, /* cond3 */
/*1819*/    OP_COPY, 0, 2938, 5, /* reason */
/*1823*/    OP_CASE, 1, 2938, 5, 3, /* reason */
/*1828*/    ATM_RSN_USER, 136, 6,
/*1831*/    ATM_RSN_IE_MISS, 137, 9,
/*1834*/    ATM_RSN_IE_INSUFF, 137, 6,
/*1837*/    OP_COPYVAR, 7, 2944, 27, /* user_diag */
/*1841*/    OP_JUMP, 4,
/*1843*/    OP_COPY, 1, 3160, 8, /* ie_id3 */
/*1847*/    OP_JUMP, 60,
/*1849*/    OP_IFEND, 59,
/*1851*/    OP_COPYVAR, 8, 3168, 28, /* new_dest */
/*1855*/    OP_JUMP, 52,
/*1857*/    OP_IFEND, 51,
/*1859*/    OP_COPY, 1, 3392, 8, /* invalid */
/*1863*/    OP_JUMP, 44,
/*1865*/    OP_IFEND, 43,
/*1867*/    OP_COPYVAR, 9, 3400, 28, /* ie_id6 */
/*1871*/    OP_JUMP, 36,
/*1873*/    OP_IFEND, 35,
/*1875*/    OP_COPYVAR, 10, 3624, 28, /* ucr_id */
/*1879*/    OP_JUMP, 28,
/*1881*/    OP_IFEND, 27,
/*1883*/    OP_COPY, 2, 3848, 16, /* unav_vpci */
/*1887*/    OP_COPY, 2, 3864, 16, /* unav_vci */
/*1891*/    OP_JUMP, 16,
/*1893*/    OP_IFEND, 15,
/*1895*/    OP_COPY, 1, 3880, 8, /* bad_msg_type */
/*1899*/    OP_JUMP, 8,
/*1901*/    OP_IFEND, 7,
/*1903*/    OP_COPY, 3, 3888, 24, /* timer */
/*1907*/    OP_JUMP, 0,
/*1909*/    OP_END_REC,
/*1910*/    OP_END_LEN,  /* _ie_len */
/*1911*/    OP_JUMP, 1262,
/*1913*/    OP_COPY, 0, 3925, 2, /* cause_cs */
/*1917*/    OP_COPY, 1, 3920, 3, /* _action_ind */
/*1921*/    OP_BEGIN_LEN, 2, 3928, 16, /* _ie_len */
/*1925*/    OP_BEGIN_REC, RECOV_IND_IE, 146, 2109,
/*1929*/    OP_COPY, 1, 3944, 4, /* location */
/*1933*/    OP_COPY, 0, 3952, 7, /* cause */
/*1937*/    OP_CASE, 1, 3952, 7, 18, /* cause */
/*1942*/    ATM_CV_UNALLOC, 147, 51,
/*1945*/    ATM_CV_NO_ROUTE_DEST, 147, 48,
/*1948*/    ATM_CV_QOS_UNAVAIL, 147, 45,
/*1951*/    ATM_CV_CALL_REJ, 148, 58,
/*1954*/    ATM_CV_NUM_CHANGED, 151, 91,
/*1957*/    ATM_CV_REJ_CLIR, 152, 96,
/*1960*/    ATM_CV_ACC_INF_DISC, 153, 101,
/*1963*/    ATM_CV_INCOMP_DEST, 153, 98,
/*1966*/    ATM_CV_MAND_IE_MISSING, 153, 95,
/*1969*/    ATM_CV_UNKNOWN_IE, 153, 92,
/*1972*/    ATM_CV_INVALID_IE, 153, 89,
/*1975*/    ATM_CV_UCR_UNAVAIL_OLD, 154, 94,
/*1978*/    ATM_CV_UCR_UNAVAIL_NEW, 154, 91,
/*1981*/    ATM_CV_NO_SUCH_CHAN, 155, 96,
/*1984*/    ATM_CV_UNKNOWN_MSG_TYPE, 156, 105,
/*1987*/    ATM_CV_INCOMP_MSG, 156, 102,
/*1990*/    ATM_CV_TIMER_EXP, 157, 107,
/*1993*/    -1, 158, 112,
/*1996*/    OP_IFEND, 111,
/*1998*/    OP_COPY, 0, 3963, 1, /* pu */
/*2002*/    OP_COPY, 0, 3962, 1, /* na */
/*2006*/    OP_COPY, 1, 3960, 2, /* cond2 */
/*2010*/    OP_JUMP, 96,
/*2012*/    OP_IFEND, 95,
/*2014*/    OP_COPY, 0, 3968, 2, /* cond3 */
/*2018*/    OP_COPY, 0, 3970, 5, /* reason */
/*2022*/    OP_CASE, 1, 3970, 5, 3, /* reason */
/*2027*/    ATM_RSN_USER, 149, 6,
/*2030*/    ATM_RSN_IE_MISS, 150, 9,
/*2033*/    ATM_RSN_IE_INSUFF, 150, 6,
/*2036*/    OP_COPYVAR, 11, 3976, 27, /* user_diag */
/*2040*/    OP_JUMP, 4,
/*2042*/    OP_COPY, 1, 4192, 8, /* ie_id3 */
/*2046*/    OP_JUMP, 60,
/*2048*/    OP_IFEND, 59,
/*2050*/    OP_COPYVAR, 12, 4200, 28, /* new_dest */
/*2054*/    OP_JUMP, 52,
/*2056*/    OP_IFEND, 51,
/*2058*/    OP_COPY, 1, 4424, 8, /* invalid */
/*2062*/    OP_JUMP, 44,
/*2064*/    OP_IFEND, 43,
/*2066*/    OP_COPYVAR, 13, 4432, 28, /* ie_id6 */
/*2070*/    OP_JUMP, 36,
/*2072*/    OP_IFEND, 35,
/*2074*/    OP_COPYVAR, 14, 4656, 28, /* ucr_id */
/*2078*/    OP_JUMP, 28,
/*2080*/    OP_IFEND, 27,
/*2082*/    OP_COPY, 2, 4880, 16, /* unav_vpci */
/*2086*/    OP_COPY, 2, 4896, 16, /* unav_vci */
/*2090*/    OP_JUMP, 16,
/*2092*/    OP_IFEND, 15,
/*2094*/    OP_COPY, 1, 4912, 8, /* bad_msg_type */
/*2098*/    OP_JUMP, 8,
/*2100*/    OP_IFEND, 7,
/*2102*/    OP_COPY, 3, 4920, 24, /* timer */
/*2106*/    OP_JUMP, 0,
/*2108*/    OP_END_REC,
/*2109*/    OP_END_LEN,  /* _ie_len */
/*2110*/    OP_JUMP, 1063,
/*2112*/    OP_COPY, 1, 4952, 3, /* _action_ind */
/*2116*/    OP_BEGIN_LEN, 2, 4960, 16, /* _ie_len */
/*2120*/    OP_BEGIN_REC, RECOV_IND_IE, 159, 2137,
/*2124*/    OP_COPY, 1, 4976, 3, /* _pref_exc */
/*2128*/    OP_COPY, 2, 4984, 16, /* vpi */
/*2132*/    OP_COPY, 2, 5000, 16, /* vci */
/*2136*/    OP_END_REC,
/*2137*/    OP_END_LEN,  /* _ie_len */
/*2138*/    OP_JUMP, 1035,
/*2140*/    OP_COPY, 1, 5024, 3, /* _action_ind */
/*2144*/    OP_BEGIN_LEN, 2, 5032, 16, /* _ie_len */
/*2148*/    OP_BEGIN_REC, RECOV_IND_IE, 160, 2183,
/*2152*/    OP_IFEND, 28, /* _id */
/*2154*/    OP_CASE, 1, 0, 8, 3, /* _id */
/*2159*/    ATM_TDL_CUM, 161, 6,
/*2162*/    ATM_TDL_E2EMAX, 162, 9,
/*2165*/    ATM_TDL_NGI, 163, 12,
/*2168*/    OP_COPY, 2, 5056, 16, /* cum_delay */
/*2172*/    OP_JUMP, 6,
/*2174*/    OP_COPY, 2, 5080, 16, /* max_delay */
/*2178*/    OP_JUMP, 0,
/*2180*/    OP_JUMP, -30,
/*2182*/    OP_END_REC,
/*2183*/    OP_END_LEN,  /* _ie_len */
/*2184*/    OP_JUMP, 989,
/*2186*/    OP_COPY, 0, 5117, 2, /* qos_cs */
/*2190*/    OP_COPY, 1, 5112, 3, /* _action_ind */
/*2194*/    OP_BEGIN_LEN, 2, 5120, 16, /* _ie_len */
/*2198*/    OP_BEGIN_REC, RECOV_IND_IE, 164, 2211,
/*2202*/    OP_COPY, 1, 5136, 8, /* qos_fw */
/*2206*/    OP_COPY, 1, 5144, 8, /* qos_bw */
/*2210*/    OP_END_REC,
/*2211*/    OP_END_LEN,  /* _ie_len */
/*2212*/    OP_JUMP, 961,
/*2214*/    OP_COPY, 1, 5160, 3, /* _action_ind */
/*2218*/    OP_BEGIN_LEN, 2, 5168, 16, /* _ie_len */
/*2222*/    OP_BEGIN_REC, RECOV_IND_IE, 165, 2231,
/*2226*/    OP_COPY, 1, 5184, 4, /* rep_ind */
/*2230*/    OP_END_REC,
/*2231*/    OP_END_LEN,  /* _ie_len */
/*2232*/    OP_JUMP, 941,
/*2234*/    OP_COPY, 1, 5200, 3, /* _action_ind */
/*2238*/    OP_BEGIN_LEN, 2, 5208, 16, /* _ie_len */
/*2242*/    OP_BEGIN_REC, RECOV_IND_IE, 166, 2251,
/*2246*/    OP_COPY, 1, 5224, 3, /* rst_class */
/*2250*/    OP_END_REC,
/*2251*/    OP_END_LEN,  /* _ie_len */
/*2252*/    OP_JUMP, 921,
/*2254*/    OP_COPY, 1, 5240, 3, /* _action_ind */
/*2258*/    OP_BEGIN_LEN, 2, 5248, 16, /* _ie_len */
/*2262*/    OP_BEGIN_REC, RECOV_IND_IE, 167, 2271,
/*2266*/    OP_COPY, 1, 5264, 7, /* bbsc_ind */
/*2270*/    OP_END_REC,
/*2271*/    OP_END_LEN,  /* _ie_len */
/*2272*/    OP_JUMP, 901,
/*2274*/    OP_COPY, 1, 5280, 3, /* _action_ind */
/*2278*/    OP_BEGIN_LEN, 2, 5288, 16, /* _ie_len */
/*2282*/    OP_BEGIN_REC, RECOV_IND_IE, 168, 2295,
/*2286*/    OP_COPY, 1, 5304, 4, /* _carrier_id */
/*2290*/    OP_COPYVAR, 15, 5312, 4, /* net_id */
/*2294*/    OP_END_REC,
/*2295*/    OP_END_LEN,  /* _ie_len */
/*2296*/    OP_JUMP, 877,
/*2298*/    OP_COPY, 1, 5352, 3, /* _action_ind */
/*2302*/    OP_BEGIN_LEN, 2, 5360, 16, /* _ie_len */
/*2306*/    OP_BEGIN_REC, RECOV_IND_IE, 169, 2315,
/*2310*/    OP_COPYVAR, 16, 5376, 4, /* notification */
/*2314*/    OP_END_REC,
/*2315*/    OP_END_LEN,  /* _ie_len */
/*2316*/    OP_JUMP, 857,
/*2318*/    OP_COPY, 1, 5416, 3, /* _action_ind */
/*2322*/    OP_BEGIN_LEN, 2, 5424, 16, /* _ie_len */
/*2326*/    OP_BEGIN_REC, RECOV_IND_IE, 170, 2351,
/*2330*/    OP_COPY, 0, 5445, 2, /* shaping */
/*2334*/    OP_COPY, 0, 5444, 1, /* compliance */
/*2338*/    OP_COPY, 1, 5440, 3, /* fault */
/*2342*/    OP_COPY, 0, 5452, 3, /* fwd_ofi */
/*2346*/    OP_COPY, 1, 5448, 3, /* bwd_ofi */
/*2350*/    OP_END_REC,
/*2351*/    OP_END_LEN,  /* _ie_len */
/*2352*/    OP_JUMP, 821,
/*2354*/    OP_COPY, 1, 5464, 3, /* _action_ind */
/*2358*/    OP_BEGIN_LEN, 2, 5472, 16, /* _ie_len */
/*2362*/    OP_BEGIN_REC, RECOV_IND_IE, 171, 2421,
/*2366*/    OP_COPY, 1, 5495, 1, /* _dummy */
/*2370*/    OP_COPY, 0, 5496, 7, /* id_std_app */
/*2374*/    OP_CASE, 1, 5496, 7, 3, /* id_std_app */
/*2379*/    ATM_IRS_DSMCC, 172, 6,
/*2382*/    ATM_IRS_H245, 172, 3,
/*2385*/    -1, 173, 28,
/*2388*/    OP_COPY, 1, 5504, 8, /* _type */
/*2392*/    OP_BEGIN_LEN, 1, 5512, 8, /* _length */
/*2396*/    OP_COPYVAR, 17, 5520, 20, /* session_id */
/*2400*/    OP_END_LEN,  /* _length */
/*2401*/    OP_COPY, 1, 5680, 8, /* _type */
/*2405*/    OP_BEGIN_LEN, 1, 5688, 8, /* _length */
/*2409*/    OP_COPYVAR, 18, 5696, 4, /* resource_id */
/*2413*/    OP_END_LEN,  /* _length */
/*2414*/    OP_JUMP, 4,
/*2416*/    OP_COPYVAR, 19, 5728, 28, /* unrecognized_git_identifiers */
/*2420*/    OP_END_REC,
/*2421*/    OP_END_LEN,  /* _ie_len */
/*2422*/    OP_JUMP, 751,
/*2424*/    OP_COPY, 1, 5960, 3, /* _action_ind */
/*2428*/    OP_BEGIN_LEN, 2, 5968, 16, /* _ie_len */
/*2432*/    OP_BEGIN_REC, RECOV_IND_IE, 174, 2491,
/*2436*/    OP_COPY, 1, 5991, 1, /* _dummy */
/*2440*/    OP_COPY, 0, 5992, 7, /* id_std_app */
/*2444*/    OP_CASE, 1, 5992, 7, 3, /* id_std_app */
/*2449*/    ATM_IRS_DSMCC, 175, 6,
/*2452*/    ATM_IRS_H245, 175, 3,
/*2455*/    -1, 176, 28,
/*2458*/    OP_COPY, 1, 6000, 8, /* _type */
/*2462*/    OP_BEGIN_LEN, 1, 6008, 8, /* _length */
/*2466*/    OP_COPYVAR, 20, 6016, 20, /* session_id */
/*2470*/    OP_END_LEN,  /* _length */
/*2471*/    OP_COPY, 1, 6176, 8, /* _type */
/*2475*/    OP_BEGIN_LEN, 1, 6184, 8, /* _length */
/*2479*/    OP_COPYVAR, 21, 6192, 4, /* resource_id */
/*2483*/    OP_END_LEN,  /* _length */
/*2484*/    OP_JUMP, 4,
/*2486*/    OP_COPYVAR, 22, 6224, 28, /* unrecognized_git_identifiers */
/*2490*/    OP_END_REC,
/*2491*/    OP_END_LEN,  /* _ie_len */
/*2492*/    OP_JUMP, 681,
/*2494*/    OP_COPY, 1, 6456, 3, /* _action_ind */
/*2498*/    OP_BEGIN_LEN, 2, 6464, 16, /* _ie_len */
/*2502*/    OP_BEGIN_REC, RECOV_IND_IE, 177, 2561,
/*2506*/    OP_COPY, 1, 6487, 1, /* _dummy */
/*2510*/    OP_COPY, 0, 6488, 7, /* id_std_app */
/*2514*/    OP_CASE, 1, 6488, 7, 3, /* id_std_app */
/*2519*/    ATM_IRS_DSMCC, 178, 6,
/*2522*/    ATM_IRS_H245, 178, 3,
/*2525*/    -1, 179, 28,
/*2528*/    OP_COPY, 1, 6496, 8, /* _type */
/*2532*/    OP_BEGIN_LEN, 1, 6504, 8, /* _length */
/*2536*/    OP_COPYVAR, 23, 6512, 20, /* session_id */
/*2540*/    OP_END_LEN,  /* _length */
/*2541*/    OP_COPY, 1, 6672, 8, /* _type */
/*2545*/    OP_BEGIN_LEN, 1, 6680, 8, /* _length */
/*2549*/    OP_COPYVAR, 24, 6688, 4, /* resource_id */
/*2553*/    OP_END_LEN,  /* _length */
/*2554*/    OP_JUMP, 4,
/*2556*/    OP_COPYVAR, 25, 6720, 28, /* unrecognized_git_identifiers */
/*2560*/    OP_END_REC,
/*2561*/    OP_END_LEN,  /* _ie_len */
/*2562*/    OP_JUMP, 611,
/*2564*/    OP_COPY, 1, 6952, 3, /* _action_ind */
/*2568*/    OP_BEGIN_LEN, 2, 6960, 16, /* _ie_len */
/*2572*/    OP_BEGIN_REC, RECOV_IND_IE, 180, 2585,
/*2576*/    OP_COPY, 1, 6976, 7, /* lij_id_type */
/*2580*/    OP_COPY, 4, 6984, 32, /* lij_id */
/*2584*/    OP_END_REC,
/*2585*/    OP_END_LEN,  /* _ie_len */
/*2586*/    OP_JUMP, 587,
/*2588*/    OP_COPY, 1, 7024, 3, /* _action_ind */
/*2592*/    OP_BEGIN_LEN, 2, 7032, 16, /* _ie_len */
/*2596*/    OP_BEGIN_REC, RECOV_IND_IE, 181, 2605,
/*2600*/    OP_COPY, 1, 7048, 2, /* lij_scr_ind */
/*2604*/    OP_END_REC,
/*2605*/    OP_END_LEN,  /* _ie_len */
/*2606*/    OP_JUMP, 567,
/*2608*/    OP_COPY, 1, 7064, 3, /* _action_ind */
/*2612*/    OP_BEGIN_LEN, 2, 7072, 16, /* _ie_len */
/*2616*/    OP_BEGIN_REC, RECOV_IND_IE, 182, 2625,
/*2620*/    OP_COPY, 4, 7088, 32, /* leaf_sn */
/*2624*/    OP_END_REC,
/*2625*/    OP_END_LEN,  /* _ie_len */
/*2626*/    OP_JUMP, 547,
/*2628*/    OP_COPY, 1, 7128, 3, /* _action_ind */
/*2632*/    OP_BEGIN_LEN, 2, 7136, 16, /* _ie_len */
/*2636*/    OP_BEGIN_REC, RECOV_IND_IE, 183, 2649,
/*2640*/    OP_COPY, 1, 7152, 4, /* scope_type */
/*2644*/    OP_COPY, 1, 7160, 8, /* scope_sel */
/*2648*/    OP_END_REC,
/*2649*/    OP_END_LEN,  /* _ie_len */
/*2650*/    OP_JUMP, 523,
/*2652*/    OP_COPY, 1, 7176, 3, /* _action_ind */
/*2656*/    OP_BEGIN_LEN, 2, 7184, 16, /* _ie_len */
/*2660*/    OP_BEGIN_REC, RECOV_IND_IE, 184, 2789,
/*2664*/    OP_IFEND, 122, /* _id */
/*2666*/    OP_CASE, 1, 0, 8, 13, /* _id */
/*2671*/    ATM_TD_FW_PCR_0, 185, 36,
/*2674*/    ATM_TD_BW_PCR_0, 186, 39,
/*2677*/    ATM_TD_FW_PCR_01, 187, 42,
/*2680*/    ATM_TD_BW_PCR_01, 188, 45,
/*2683*/    ATM_TD_FW_SCR_0, 189, 48,
/*2686*/    ATM_TD_BW_SCR_0, 190, 51,
/*2689*/    ATM_TD_FW_SCR_01, 191, 54,
/*2692*/    ATM_TD_BW_SCR_01, 192, 57,
/*2695*/    ATM_TD_FW_MBS_0, 193, 60,
/*2698*/    ATM_TD_BW_MBS_0, 194, 63,
/*2701*/    ATM_TD_FW_MBS_01, 195, 66,
/*2704*/    ATM_TD_BW_MBS_01, 196, 69,
/*2707*/    ATM_TD_BEST_EFFORT, 197, 72,
/*2710*/    OP_COPY, 3, 7208, 24, /* altfw_pcr_0 */
/*2714*/    OP_JUMP, 70,
/*2716*/    OP_COPY, 3, 7240, 24, /* altbw_pcr_0 */
/*2720*/    OP_JUMP, 64,
/*2722*/    OP_COPY, 3, 7272, 24, /* altfw_pcr_01 */
/*2726*/    OP_JUMP, 58,
/*2728*/    OP_COPY, 3, 7304, 24, /* altbw_pcr_01 */
/*2732*/    OP_JUMP, 52,
/*2734*/    OP_COPY, 3, 7336, 24, /* altfw_scr_0 */
/*2738*/    OP_JUMP, 46,
/*2740*/    OP_COPY, 3, 7368, 24, /* altbw_scr_0 */
/*2744*/    OP_JUMP, 40,
/*2746*/    OP_COPY, 3, 7400, 24, /* altfw_scr_01 */
/*2750*/    OP_JUMP, 34,
/*2752*/    OP_COPY, 3, 7432, 24, /* altbw_scr_01 */
/*2756*/    OP_JUMP, 28,
/*2758*/    OP_COPY, 3, 7464, 24, /* altfw_mbs_0 */
/*2762*/    OP_JUMP, 22,
/*2764*/    OP_COPY, 3, 7496, 24, /* altbw_mbs_0 */
/*2768*/    OP_JUMP, 16,
/*2770*/    OP_COPY, 3, 7528, 24, /* altfw_mbs_01 */
/*2774*/    OP_JUMP, 10,
/*2776*/    OP_COPY, 3, 7560, 24, /* altbw_mbs_01 */
/*2780*/    OP_JUMP, 4,
/*2782*/    OP_COPY, 0, 7592, 0, /* altbest_effort */
/*2786*/    OP_JUMP, -124,
/*2788*/    OP_END_REC,
/*2789*/    OP_END_LEN,  /* _ie_len */
/*2790*/    OP_JUMP, 383,
/*2792*/    OP_COPY, 1, 7600, 3, /* _action_ind */
/*2796*/    OP_BEGIN_LEN, 2, 7608, 16, /* _ie_len */
/*2800*/    OP_BEGIN_REC, RECOV_IND_IE, 198, 2866,
/*2804*/    OP_IFEND, 59, /* _id */
/*2806*/    OP_CASE, 1, 0, 8, 6, /* _id */
/*2811*/    ATM_TD_FW_PCR_0, 199, 15,
/*2814*/    ATM_TD_BW_PCR_0, 200, 18,
/*2817*/    ATM_TD_FW_PCR_01, 201, 21,
/*2820*/    ATM_TD_BW_PCR_01, 202, 24,
/*2823*/    ATM_TD_FW_MCR_01, 203, 27,
/*2826*/    ATM_TD_BW_MCR_01, 204, 30,
/*2829*/    OP_COPY, 3, 7632, 24, /* minfw_pcr_0 */
/*2833*/    OP_JUMP, 28,
/*2835*/    OP_COPY, 3, 7664, 24, /* minbw_pcr_0 */
/*2839*/    OP_JUMP, 22,
/*2841*/    OP_COPY, 3, 7696, 24, /* minfw_pcr_01 */
/*2845*/    OP_JUMP, 16,
/*2847*/    OP_COPY, 3, 7728, 24, /* minbw_pcr_01 */
/*2851*/    OP_JUMP, 10,
/*2853*/    OP_COPY, 3, 7760, 24, /* minfw_mcr_01 */
/*2857*/    OP_JUMP, 4,
/*2859*/    OP_COPY, 3, 7792, 24, /* minbw_mcr_01 */
/*2863*/    OP_JUMP, -61,
/*2865*/    OP_END_REC,
/*2866*/    OP_END_LEN,  /* _ie_len */
/*2867*/    OP_JUMP, 306,
/*2869*/    OP_COPY, 1, 7824, 3, /* _action_ind */
/*2873*/    OP_BEGIN_LEN, 2, 7832, 16, /* _ie_len */
/*2877*/    OP_BEGIN_REC, RECOV_IND_IE, 205, 2947,
/*2881*/    OP_COPY, 1, 7848, 8, /* eqos_origin */
/*2885*/    OP_IFEND, 59, /* _id */
/*2887*/    OP_CASE, 1, 0, 8, 6, /* _id */
/*2892*/    ATM_EQP_ACC_FW_CDV, 206, 15,
/*2895*/    ATM_EQP_ACC_BW_CDV, 207, 18,
/*2898*/    ATM_EQP_CUM_FW_CDV, 208, 21,
/*2901*/    ATM_EQP_CUM_BW_CDV, 209, 24,
/*2904*/    ATM_EQP_ACC_FW_CLR, 210, 27,
/*2907*/    ATM_EQP_ACC_BW_CLR, 211, 30,
/*2910*/    OP_COPY, 3, 7864, 24, /* acc_fw_cdv */
/*2914*/    OP_JUMP, 28,
/*2916*/    OP_COPY, 3, 7896, 24, /* acc_bw_cdv */
/*2920*/    OP_JUMP, 22,
/*2922*/    OP_COPY, 3, 7928, 24, /* cum_fw_cdv */
/*2926*/    OP_JUMP, 16,
/*2928*/    OP_COPY, 3, 7960, 24, /* cum_bw_cdv */
/*2932*/    OP_JUMP, 10,
/*2934*/    OP_COPY, 1, 7992, 8, /* acc_fw_clr */
/*2938*/    OP_JUMP, 4,
/*2940*/    OP_COPY, 1, 8008, 8, /* acc_bw_clr */
/*2944*/    OP_JUMP, -61,
/*2946*/    OP_END_REC,
/*2947*/    OP_END_LEN,  /* _ie_len */
/*2948*/    OP_JUMP, 225,
/*2950*/    OP_COPY, 1, 8024, 3, /* _action_ind */
/*2954*/    OP_BEGIN_LEN, 2, 8032, 16, /* _ie_len */
/*2958*/    OP_BEGIN_REC, RECOV_IND_IE, 212, 2988,
/*2962*/    OP_IFEND, 23, /* _id */
/*2964*/    OP_CASE, 1, 0, 8, 2, /* _id */
/*2969*/    ATM_AAP_FW_REC, 213, 3,
/*2972*/    ATM_AAP_BW_REC, 214, 6,
/*2975*/    OP_COPY, 4, 8056, 32, /* abr_fw_add_rec */
/*2979*/    OP_JUMP, 4,
/*2981*/    OP_COPY, 4, 8096, 32, /* abr_bw_add_rec */
/*2985*/    OP_JUMP, -25,
/*2987*/    OP_END_REC,
/*2988*/    OP_END_LEN,  /* _ie_len */
/*2989*/    OP_JUMP, 184,
/*2991*/    OP_COPY, 1, 8136, 3, /* _action_ind */
/*2995*/    OP_BEGIN_LEN, 2, 8144, 16, /* _ie_len */
/*2999*/    OP_BEGIN_REC, RECOV_IND_IE, 215, 3092,
/*3003*/    OP_IFEND, 86, /* _id */
/*3005*/    OP_CASE, 1, 0, 8, 9, /* _id */
/*3010*/    ATM_ASP_FW_ICR, 216, 24,
/*3013*/    ATM_ASP_BW_ICR, 217, 27,
/*3016*/    ATM_ASP_FW_TBE, 218, 30,
/*3019*/    ATM_ASP_BW_TBE, 219, 33,
/*3022*/    ATM_ASP_CRF_RTT, 220, 36,
/*3025*/    ATM_ASP_FW_RIF, 221, 39,
/*3028*/    ATM_ASP_BW_RIF, 222, 42,
/*3031*/    ATM_ASP_FW_RDF, 223, 45,
/*3034*/    ATM_ASP_BW_RDF, 224, 48,
/*3037*/    OP_COPY, 3, 8168, 24, /* abr_fw_icr */
/*3041*/    OP_JUMP, 46,
/*3043*/    OP_COPY, 3, 8200, 24, /* abr_bw_icr */
/*3047*/    OP_JUMP, 40,
/*3049*/    OP_COPY, 3, 8232, 24, /* abr_fw_tbe */
/*3053*/    OP_JUMP, 34,
/*3055*/    OP_COPY, 3, 8264, 24, /* abr_bw_tbe */
/*3059*/    OP_JUMP, 28,
/*3061*/    OP_COPY, 3, 8296, 24, /* atm_crf_rtt */
/*3065*/    OP_JUMP, 22,
/*3067*/    OP_COPY, 1, 8328, 8, /* atm_fw_rif */
/*3071*/    OP_JUMP, 16,
/*3073*/    OP_COPY, 1, 8344, 8, /* atm_bw_rif */
/*3077*/    OP_JUMP, 10,
/*3079*/    OP_COPY, 1, 8360, 8, /* atm_fw_rdf */
/*3083*/    OP_JUMP, 4,
/*3085*/    OP_COPY, 1, 8376, 8, /* atm_bw_rdf */
/*3089*/    OP_JUMP, -88,
/*3091*/    OP_END_REC,
/*3092*/    OP_END_LEN,  /* _ie_len */
/*3093*/    OP_JUMP, 80,
/*3095*/    OP_COPY, 1, 8392, 3, /* _action_ind */
/*3099*/    OP_BEGIN_LEN, 2, 8400, 16, /* _ie_len */
/*3103*/    OP_BEGIN_REC, RECOV_IND_IE, 225, 3116,
/*3107*/    OP_COPY, 1, 8416, 8, /* _ep_type */
/*3111*/    OP_COPY, 2, 8424, 16, /* ep_ref */
/*3115*/    OP_END_REC,
/*3116*/    OP_END_LEN,  /* _ie_len */
/*3117*/    OP_JUMP, 56,
/*3119*/    OP_COPY, 1, 8448, 3, /* _action_ind */
/*3123*/    OP_BEGIN_LEN, 2, 8456, 16, /* _ie_len */
/*3127*/    OP_BEGIN_REC, RECOV_IND_IE, 226, 3136,
/*3131*/    OP_COPY, 1, 8472, 6, /* ep_state */
/*3135*/    OP_END_REC,
/*3136*/    OP_END_LEN,  /* _ie_len */
/*3137*/    OP_JUMP, 36,
/*3139*/    OP_COPY, 1, 8488, 3, /* _action_ind */
/*3143*/    OP_BEGIN_LEN, 2, 8496, 16, /* _ie_len */
/*3147*/    OP_BEGIN_REC, RECOV_IND_IE, 227, 3156,
/*3151*/    OP_COPY, 1, 8512, 8, /* type_of_report */
/*3155*/    OP_END_REC,
/*3156*/    OP_END_LEN,  /* _ie_len */
/*3157*/    OP_JUMP, 16,
/*3159*/    OP_COPY, 1, 8528, 3, /* _action_ind */
/*3163*/    OP_BEGIN_LEN, 2, 8536, 16, /* _ie_len */
/*3167*/    OP_BEGIN_REC, RECOV_IND_IE, 228, 3174,
/*3171*/    OP_ABORT, RECOV_ASE_UNKNOWN_IE,
/*3173*/    OP_END_REC,
/*3174*/    OP_END_LEN,  /* _ie_len */
/*3175*/    OP_JUMP, -3153,
/*3177*/    OP_END_LEN,  /* msg_len */
/*3178*/    OP_END
};


/*
 * Sorry, this is necessary ...
 */

#include "qlib.c"

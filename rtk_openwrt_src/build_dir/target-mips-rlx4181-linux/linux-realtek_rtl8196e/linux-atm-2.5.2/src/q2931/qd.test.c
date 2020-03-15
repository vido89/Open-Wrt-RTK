/* THIS IS A MACHINE-GENERATED FILE. DO NOT EDIT ! */

#if HAVE_CONFIG_H
#include <config.h>
#endif

/* (optional) user includes go here */

#include "uni.h"
#include "atmsap.h"

#ifndef NULL
#define NULL ((void *) 0)
#endif

static const char *fields[] = {
    "call_ref",
    "msg_type",
    "msg_len",
    "aal_type",
    "fw_max_sdu",
    "bw_max_sdu",
    "aal_mode",
    "sscs_type",
    "fw_pcr_0",
    "bw_pcr_0",
    "fw_pcr_01",
    "bw_pcr_01",
    "fw_scr_0",
    "bw_scr_0",
    "fw_scr_01",
    "bw_scr_01",
    "fw_mbs_0",
    "bw_mbs_0",
    "fw_mbs_01",
    "bw_mbs_01",
    "best_effort",
    "fw_fdisc",
    "bw_fdisc",
    "bw_tag",
    "fw_tag",
    "bearer_class",
    "trans_cap",
    "susc_clip",
    "upcc",
    "hli_type",
    "iso_hli",
    "user_hli",
    "hlp",
    "hli_oui",
    "app_id",
    "tobedefined",
    "uil1_proto",
    "uil2_proto",
    "l2_mode",
    "q933",
    "window_size",
    "user_l2",
    "uil3_proto",
    "l3_mode",
    "def_pck_size",
    "pck_win_size",
    "term_type",
    "fw_mpx_cap",
    "bw_mpx_cap",
    "ipi_high",
    "oui",
    "pid",
    "ipi_low",
    "user_l3",
    "uil1_proto",
    "uil2_proto",
    "l2_mode",
    "q933",
    "window_size",
    "user_l2",
    "uil3_proto",
    "l3_mode",
    "def_pck_size",
    "pck_win_size",
    "term_type",
    "fw_mpx_cap",
    "bw_mpx_cap",
    "ipi_high",
    "oui",
    "pid",
    "ipi_low",
    "user_l3",
    "uil1_proto",
    "uil2_proto",
    "l2_mode",
    "q933",
    "window_size",
    "user_l2",
    "uil3_proto",
    "l3_mode",
    "def_pck_size",
    "pck_win_size",
    "term_type",
    "fw_mpx_cap",
    "bw_mpx_cap",
    "ipi_high",
    "oui",
    "pid",
    "ipi_low",
    "user_l3",
    "call_state",
    "cdpn_e164",
    "cdpn_esa",
    "cdps_type",
    "cdps",
    "cgpn_plan",
    "cgpn_type",
    "pres_ind",
    "scr_ind",
    "cgpn",
    "cgps_type",
    "cgps",
    "cause_cs",
    "location",
    "cause",
    "pu",
    "na",
    "cond2",
    "cond3",
    "reason",
    "user_diag",
    "ie_id3",
    "new_dest",
    "invalid",
    "ie_id6",
    "ucr_id",
    "unav_vpci",
    "unav_vci",
    "bad_msg_type",
    "timer",
    "cause_cs",
    "location",
    "cause",
    "pu",
    "na",
    "cond2",
    "cond3",
    "reason",
    "user_diag",
    "ie_id3",
    "new_dest",
    "invalid",
    "ie_id6",
    "ucr_id",
    "unav_vpci",
    "unav_vci",
    "bad_msg_type",
    "timer",
    "vpi",
    "vci",
    "cum_delay",
    "max_delay",
    "qos_cs",
    "qos_fw",
    "qos_bw",
    "rep_ind",
    "rst_class",
    "bbsc_ind",
    "net_id",
    "notification",
    "shaping",
    "compliance",
    "fault",
    "fwd_ofi",
    "bwd_ofi",
    "id_std_app",
    "session_id",
    "resource_id",
    "unrecognized_git_identifiers",
    "id_std_app",
    "session_id",
    "resource_id",
    "unrecognized_git_identifiers",
    "id_std_app",
    "session_id",
    "resource_id",
    "unrecognized_git_identifiers",
    "lij_id_type",
    "lij_id",
    "lij_scr_ind",
    "leaf_sn",
    "scope_type",
    "scope_sel",
    "altfw_pcr_0",
    "altbw_pcr_0",
    "altfw_pcr_01",
    "altbw_pcr_01",
    "altfw_scr_0",
    "altbw_scr_0",
    "altfw_scr_01",
    "altbw_scr_01",
    "altfw_mbs_0",
    "altbw_mbs_0",
    "altfw_mbs_01",
    "altbw_mbs_01",
    "altbest_effort",
    "minfw_pcr_0",
    "minbw_pcr_0",
    "minfw_pcr_01",
    "minbw_pcr_01",
    "minfw_mcr_01",
    "minbw_mcr_01",
    "eqos_origin",
    "acc_fw_cdv",
    "acc_bw_cdv",
    "cum_fw_cdv",
    "cum_bw_cdv",
    "acc_fw_clr",
    "acc_bw_clr",
    "abr_fw_add_rec",
    "abr_bw_add_rec",
    "abr_fw_icr",
    "abr_bw_icr",
    "abr_fw_tbe",
    "abr_bw_tbe",
    "atm_crf_rtt",
    "atm_fw_rif",
    "atm_bw_rif",
    "atm_fw_rdf",
    "atm_bw_rdf",
    "ep_ref",
    "ep_state",
    "type_of_report",
    NULL
};

static const char *groups[] = {
    "aal",
    "td",
    "bbcap",
    "bhli",
    "blli1",
    "blli2",
    "blli3",
    "call_state",
    "cdpn",
    "cdps",
    "cgpn",
    "cgps",
    "cause",
    "cause2",
    "conn_id",
    "e2e_tdl",
    "qos",
    "bbrep",
    "restart",
    "bbs_comp",
    "tns",
    "notify",
    "oam_td",
    "git",
    "git2",
    "git3",
    "lij_id",
    "lij_prm",
    "leaf_sn",
    "scope_sel",
    "alt_td",
    "min_td",
    "eqos",
    "abr_add_prm",
    "abr_set_prm",
    "ep_ref",
    "ep_state",
    "bbrt",
    NULL
};

static int unique_0[] = { /* _id */
    ATM_AALP_FW_MAX_SDU,
    ATM_AALP_BW_MAX_SDU,
    ATM_AALP_AAL_MODE,
    ATM_AALP_SSCS,
    -1
};

static int unique_1[] = { /* aal_type */
    5,
    -1
};

static int unique_2[] = { /* _id */
    ATM_TD_FW_PCR_0,
    ATM_TD_BW_PCR_0,
    ATM_TD_FW_PCR_01,
    ATM_TD_BW_PCR_01,
    ATM_TD_FW_SCR_0,
    ATM_TD_BW_SCR_0,
    ATM_TD_FW_SCR_01,
    ATM_TD_BW_SCR_01,
    ATM_TD_FW_MBS_0,
    ATM_TD_BW_MBS_0,
    ATM_TD_FW_MBS_01,
    ATM_TD_BW_MBS_01,
    ATM_TD_BEST_EFFORT,
    ATM_TD_TM_OPT,
    -1
};

static int unique_3[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_4[] = { /* hli_type */
    0,
    1,
    2,
    3,
    4,
    -1
};

static int unique_5[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_6[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_7[] = { /* uil2_proto */
    ATM_L2_X25_LL,
    ATM_L2_X25_ML,
    ATM_L2_HDLC_ARM,
    ATM_L2_HDLC_NRM,
    ATM_L2_HDLC_ABM,
    ATM_L2_Q922,
    ATM_L2_ISO7776,
    ATM_L2_USER,
    ATM_L2_ISO1745,
    ATM_L2_Q291,
    ATM_L2_LAPB,
    ATM_L2_ISO8802,
    ATM_L2_X75,
    -1
};

static int unique_8[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_9[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_10[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_11[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_12[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_13[] = { /* _ipi_low */
    0,
    1,
    -1
};

static int unique_14[] = { /* ipi_high */
    0x40,
    0x0,
    -1
};

static int unique_15[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_16[] = { /* uil3_proto */
    ATM_L3_X25,
    ATM_L3_ISO8208,
    ATM_L3_X223,
    ATM_L3_H310,
    ATM_L3_TR9577,
    ATM_L3_USER,
    -1
};

static int unique_17[] = { /* _lid */
    1,
    2,
    3,
    -1
};

static int unique_18[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_19[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_20[] = { /* uil2_proto */
    ATM_L2_X25_LL,
    ATM_L2_X25_ML,
    ATM_L2_HDLC_ARM,
    ATM_L2_HDLC_NRM,
    ATM_L2_HDLC_ABM,
    ATM_L2_Q922,
    ATM_L2_ISO7776,
    ATM_L2_USER,
    ATM_L2_ISO1745,
    ATM_L2_Q291,
    ATM_L2_LAPB,
    ATM_L2_ISO8802,
    ATM_L2_X75,
    -1
};

static int unique_21[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_22[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_23[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_24[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_25[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_26[] = { /* _ipi_low */
    0,
    1,
    -1
};

static int unique_27[] = { /* ipi_high */
    0x40,
    0x0,
    -1
};

static int unique_28[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_29[] = { /* uil3_proto */
    ATM_L3_X25,
    ATM_L3_ISO8208,
    ATM_L3_X223,
    ATM_L3_H310,
    ATM_L3_TR9577,
    ATM_L3_USER,
    -1
};

static int unique_30[] = { /* _lid */
    1,
    2,
    3,
    -1
};

static int unique_31[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_32[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_33[] = { /* uil2_proto */
    ATM_L2_X25_LL,
    ATM_L2_X25_ML,
    ATM_L2_HDLC_ARM,
    ATM_L2_HDLC_NRM,
    ATM_L2_HDLC_ABM,
    ATM_L2_Q922,
    ATM_L2_ISO7776,
    ATM_L2_USER,
    ATM_L2_ISO1745,
    ATM_L2_Q291,
    ATM_L2_LAPB,
    ATM_L2_ISO8802,
    ATM_L2_X75,
    -1
};

static int unique_34[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_35[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_36[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_37[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_38[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_39[] = { /* _ipi_low */
    0,
    1,
    -1
};

static int unique_40[] = { /* ipi_high */
    0x40,
    0x0,
    -1
};

static int unique_41[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_42[] = { /* uil3_proto */
    ATM_L3_X25,
    ATM_L3_ISO8208,
    ATM_L3_X223,
    ATM_L3_H310,
    ATM_L3_TR9577,
    ATM_L3_USER,
    -1
};

static int unique_43[] = { /* _lid */
    1,
    2,
    3,
    -1
};

static int unique_44[] = { /* _plan */
    ATM_NP_E164,
    ATM_NP_AEA,
    -1
};

static int unique_45[] = { /* _ext */
    0,
    1,
    -1
};

static int unique_46[] = { /* reason */
    ATM_RSN_USER,
    ATM_RSN_IE_MISS,
    ATM_RSN_IE_INSUFF,
    -1
};

static int unique_47[] = { /* cause */
    ATM_CV_UNALLOC,
    ATM_CV_NO_ROUTE_DEST,
    ATM_CV_QOS_UNAVAIL,
    ATM_CV_CALL_REJ,
    ATM_CV_NUM_CHANGED,
    ATM_CV_REJ_CLIR,
    ATM_CV_ACC_INF_DISC,
    ATM_CV_INCOMP_DEST,
    ATM_CV_MAND_IE_MISSING,
    ATM_CV_UNKNOWN_IE,
    ATM_CV_INVALID_IE,
    ATM_CV_UCR_UNAVAIL_OLD,
    ATM_CV_UCR_UNAVAIL_NEW,
    ATM_CV_NO_SUCH_CHAN,
    ATM_CV_UNKNOWN_MSG_TYPE,
    ATM_CV_INCOMP_MSG,
    ATM_CV_TIMER_EXP,
    0,
    -1
};

static int unique_48[] = { /* reason */
    ATM_RSN_USER,
    ATM_RSN_IE_MISS,
    ATM_RSN_IE_INSUFF,
    -1
};

static int unique_49[] = { /* cause */
    ATM_CV_UNALLOC,
    ATM_CV_NO_ROUTE_DEST,
    ATM_CV_QOS_UNAVAIL,
    ATM_CV_CALL_REJ,
    ATM_CV_NUM_CHANGED,
    ATM_CV_REJ_CLIR,
    ATM_CV_ACC_INF_DISC,
    ATM_CV_INCOMP_DEST,
    ATM_CV_MAND_IE_MISSING,
    ATM_CV_UNKNOWN_IE,
    ATM_CV_INVALID_IE,
    ATM_CV_UCR_UNAVAIL_OLD,
    ATM_CV_UCR_UNAVAIL_NEW,
    ATM_CV_NO_SUCH_CHAN,
    ATM_CV_UNKNOWN_MSG_TYPE,
    ATM_CV_INCOMP_MSG,
    ATM_CV_TIMER_EXP,
    0,
    -1
};

static int unique_50[] = { /* _id */
    ATM_TDL_CUM,
    ATM_TDL_E2EMAX,
    ATM_TDL_NGI,
    -1
};

static int unique_51[] = { /* id_std_app */
    ATM_IRS_DSMCC,
    ATM_IRS_H245,
    0,
    -1
};

static int unique_52[] = { /* id_std_app */
    ATM_IRS_DSMCC,
    ATM_IRS_H245,
    0,
    -1
};

static int unique_53[] = { /* id_std_app */
    ATM_IRS_DSMCC,
    ATM_IRS_H245,
    0,
    -1
};

static int unique_54[] = { /* _id */
    ATM_TD_FW_PCR_0,
    ATM_TD_BW_PCR_0,
    ATM_TD_FW_PCR_01,
    ATM_TD_BW_PCR_01,
    ATM_TD_FW_SCR_0,
    ATM_TD_BW_SCR_0,
    ATM_TD_FW_SCR_01,
    ATM_TD_BW_SCR_01,
    ATM_TD_FW_MBS_0,
    ATM_TD_BW_MBS_0,
    ATM_TD_FW_MBS_01,
    ATM_TD_BW_MBS_01,
    ATM_TD_BEST_EFFORT,
    -1
};

static int unique_55[] = { /* _id */
    ATM_TD_FW_PCR_0,
    ATM_TD_BW_PCR_0,
    ATM_TD_FW_PCR_01,
    ATM_TD_BW_PCR_01,
    ATM_TD_FW_MCR_01,
    ATM_TD_BW_MCR_01,
    -1
};

static int unique_56[] = { /* _id */
    ATM_EQP_ACC_FW_CDV,
    ATM_EQP_ACC_BW_CDV,
    ATM_EQP_CUM_FW_CDV,
    ATM_EQP_CUM_BW_CDV,
    ATM_EQP_ACC_FW_CLR,
    ATM_EQP_ACC_BW_CLR,
    -1
};

static int unique_57[] = { /* _id */
    ATM_AAP_FW_REC,
    ATM_AAP_BW_REC,
    -1
};

static int unique_58[] = { /* _id */
    ATM_ASP_FW_ICR,
    ATM_ASP_BW_ICR,
    ATM_ASP_FW_TBE,
    ATM_ASP_BW_TBE,
    ATM_ASP_CRF_RTT,
    ATM_ASP_FW_RIF,
    ATM_ASP_BW_RIF,
    ATM_ASP_FW_RDF,
    ATM_ASP_BW_RDF,
    -1
};

static int unique_59[] = { /* _ie_id */
    ATM_IE_AAL,
    ATM_IE_TD,
    ATM_IE_BBCAP,
    ATM_IE_BHLI,
    ATM_IE_BLLI,
    ATM_IE_BLLI,
    ATM_IE_BLLI,
    ATM_IE_CALL_STATE,
    ATM_IE_CDPN,
    ATM_IE_CDPS,
    ATM_IE_CGPN,
    ATM_IE_CGPS,
    ATM_IE_CAUSE,
    ATM_IE_CAUSE,
    ATM_IE_CONN_ID,
    ATM_IE_E2E_TDL,
    ATM_IE_QOS,
    ATM_IE_BBREP,
    ATM_IE_RESTART,
    ATM_IE_BBS_COMP,
    ATM_IE_TNS,
    ATM_IE_NOTIFY,
    ATM_IE_OAM_TD,
    ATM_IE_GIT,
    ATM_IE_GIT,
    ATM_IE_GIT,
    ATM_IE_LIJ_ID,
    ATM_IE_LIJ_PRM,
    ATM_IE_LEAF_SN,
    ATM_IE_SCOPE_SEL,
    ATM_IE_ALT_TD,
    ATM_IE_MIN_TD,
    ATM_IE_EQOS,
    ATM_IE_ABR_ADD_PRM,
    ATM_IE_ABR_SET_PRM,
    ATM_IE_EPR,
    ATM_IE_EP_STATE,
    ATM_IE_BBRT,
    0,
    -1
};

static int *unique[] = {
    unique_0,
    unique_1,
    unique_2,
    unique_3,
    unique_4,
    unique_5,
    unique_6,
    unique_7,
    unique_8,
    unique_9,
    unique_10,
    unique_11,
    unique_12,
    unique_13,
    unique_14,
    unique_15,
    unique_16,
    unique_17,
    unique_18,
    unique_19,
    unique_20,
    unique_21,
    unique_22,
    unique_23,
    unique_24,
    unique_25,
    unique_26,
    unique_27,
    unique_28,
    unique_29,
    unique_30,
    unique_31,
    unique_32,
    unique_33,
    unique_34,
    unique_35,
    unique_36,
    unique_37,
    unique_38,
    unique_39,
    unique_40,
    unique_41,
    unique_42,
    unique_43,
    unique_44,
    unique_45,
    unique_46,
    unique_47,
    unique_48,
    unique_49,
    unique_50,
    unique_51,
    unique_52,
    unique_53,
    unique_54,
    unique_55,
    unique_56,
    unique_57,
    unique_58,
    unique_59,
    NULL
};


/*
 * Sorry, this is necessary ...
 */

#include "qtest.c"

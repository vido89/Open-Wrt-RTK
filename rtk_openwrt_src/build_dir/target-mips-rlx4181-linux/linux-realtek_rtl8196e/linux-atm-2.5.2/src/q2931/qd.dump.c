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

typedef struct {
    unsigned long value;
    const char *name;
} SYM_NAME;

static SYM_NAME dump_sym_0[] = { /* q2931_proto */
    { 9, "9 \"Q.2931 user-network call/connection control message\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_1[] = {
    { 3, "3" },
    { 0, NULL }
};

static SYM_NAME dump_sym_3[] = { /* atm_msg */
    { 0x00, "0x00 \"National specific message escape\"" },
    { 0x05, "0x05 \"SETUP\"" },
    { 0x01, "0x01 \"ALERTING\"" },
    { 0x02, "0x02 \"CALL PROCEEDING\"" },
    { 0x07, "0x07 \"CONNECT\"" },
    { 0x0f, "0x0f \"CONNECT ACKNOWLEDGE\"" },
    { 0x46, "0x46 \"RESTART\"" },
    { 0x4d, "0x4d \"RELEASE\"" },
    { 0x4e, "0x4e \"RESTART ACKNOWLEDGE\"" },
    { 0x5a, "0x5a \"RELEASE COMPLETE\"" },
    { 0x6e, "0x6e \"NOTIFY\"" },
    { 0x75, "0x75 \"STATUS ENQUIRY\"" },
    { 0x7d, "0x7d \"STATUS\"" },
    { 0x80, "0x80 \"ADD PARTY\"" },
    { 0x81, "0x81 \"ADD PARTY ACKNOWLEDGE\"" },
    { 0x82, "0x82 \"ADD PART REJECT\"" },
    { 0x85, "0x85 \"PARTY ALERTING\"" },
    { 0x83, "0x83 \"DROP PARTY\"" },
    { 0x84, "0x84 \"DROP PARTY ACKNOWLEDGE\"" },
    { 0x88, "0x88 \"MODIFY REQUEST\"" },
    { 0x89, "0x89 \"MODIFY ACKNOWLEDGE\"" },
    { 0x8a, "0x8a \"MODIFY REJECT\"" },
    { 0x8b, "0x8b \"CONNECTION AVAILABLE\"" },
    { 0x90, "0x90 \"LEAF SETUP FAILURE\"" },
    { 0x91, "0x91 \"LEAF SETUP REQUEST\"" },
    { 0xff, "0xff \"reserved for EVEN MORE msg types\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_4[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_5[] = { /* atm_flag */
    { 0, "0 \"instruction field not significant\"" },
    { 1, "1 \"follow explicit instructions\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_6[] = { /* atm_ai_msg */
    { 0, "0 \"clear call\"" },
    { 1, "1 \"discard and ignore\"" },
    { 2, "2 \"discard and report status\"" },
    { 3, "3 \"reserved\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_7[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_8[] = { /* atm_ie */
    { 0x08, "0x08 \"Cause\"" },
    { 0x14, "0x14 \"Call state\"" },
    { 0x27, "0x27 \"Notification indicator\"" },
    { 0x42, "0x42 \"End-to-end transit delay\"" },
    { 0x54, "0x54 \"Endpoint reference\"" },
    { 0x55, "0x55 \"Endpoint state\"" },
    { 0x58, "0x58 \"ATM adaption layer parameters\"" },
    { 0x59, "0x59 \"ATM traffic descriptor\"" },
    { 0x5a, "0x5a \"Connection identifier\"" },
    { 0x5b, "0x5b \"OAM traffic descriptor\"" },
    { 0x5c, "0x5c \"Quality of service parameter\"" },
    { 0x5d, "0x5d \"Broadband high layer information\"" },
    { 0x5e, "0x5e \"Broadband bearer capability\"" },
    { 0x5f, "0x5f \"Broadband low-layer information\"" },
    { 0x62, "0x62 \"Broadband sending complete\"" },
    { 0x63, "0x63 \"Broadband repeat indicator\"" },
    { 0x6c, "0x6c \"Calling party number\"" },
    { 0x6d, "0x6d \"Calling party subaddress\"" },
    { 0x70, "0x70 \"Called party number\"" },
    { 0x71, "0x71 \"Called party subaddress\"" },
    { 0x78, "0x78 \"Transit network selection\"" },
    { 0x79, "0x79 \"Restart indicator\"" },
    { 0x7f, "0x7f \"Generic identifier transport\"" },
    { 0x81, "0x81 \"Alternate ATM traffic descriptor\"" },
    { 0x80, "0x80 \"Minimum acceptable ATM traffic desc.\"" },
    { 0x84, "0x84 \"ABR setup parameters\"" },
    { 0x89, "0x89 \"Broadband report type\"" },
    { 0xe4, "0xe4 \"ABR additional parameters\"" },
    { 0xe8, "0xe8 \"Leaf initiated join call identifer\"" },
    { 0xe9, "0xe9 \"Leaf initiated join parameters\"" },
    { 0xea, "0xea \"Leaf sequence number\"" },
    { 0xeb, "0xeb \"Connection Scope Selection\"" },
    { 0xec, "0xec \"Extended QOS parameters\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_9[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_10[] = { /* q2931_cs */
    { 0, "0 \"ITU-T standardized\"" },
    { 3, "3 \"Standard defined for the network\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_12[] = { /* atm_ai_ie */
    { 0, "0 \"clear call\"" },
    { 1, "1 \"discard IE and proceed\"" },
    { 2, "2 \"discard IE, procees, and report status\"" },
    { 5, "5 \"discard message, and ignore\"" },
    { 6, "6 \"discard message, and report status\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_13[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_14[] = {
    { 5, "5" },
    { 0, NULL }
};

static SYM_NAME dump_sym_15[] = { /* atm_aalp */
    { 0x8c, "0x8c \"Forward maximum CPCS-SDU size\"" },
    { 0x81, "0x81 \"Backward maximum CPCS-SDU size\"" },
    { 0x83, "0x83 \"AAL mode (UNI 3.0 only)\"" },
    { 0x84, "0x84 \"SSCS type\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_20[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_24[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_25[] = { /* atm_td */
    { 0x82, "0x82 \"Forward peak cell rate (CLP=0)\"" },
    { 0x83, "0x83 \"Backward peak cell rate (CLP=0)\"" },
    { 0x84, "0x84 \"Forward peak cell rate (CLP=0+1)\"" },
    { 0x85, "0x85 \"Backward peak cell rate (CLP=0+1)\"" },
    { 0x88, "0x88 \"Forward sustained cell rate (CLP=0)\"" },
    { 0x89, "0x89 \"Backward sustained cell rate (CLP=0)\"" },
    { 0x90, "0x90 \"Forward sustained cell rate (CLP=0+1)\"" },
    { 0x91, "0x91 \"Backward sustained cell rate (CLP=0+1)\"" },
    { 0x92, "0x92 \"Forward ABR min. cell rate (CLP=0+1)\"" },
    { 0x93, "0x93 \"Backward ABR min. cell rate (CLP=0+1)\"" },
    { 0xa0, "0xa0 \"Forward maximum burst size (CLP=0)\"" },
    { 0xa1, "0xa1 \"Backward maximum burst size (CLP=0)\"" },
    { 0xb0, "0xb0 \"Forward maximum burst size (CLP=0+1)\"" },
    { 0xb1, "0xb1 \"Backward maximum burst size (CLP=0+1)\"" },
    { 0xbe, "0xbe \"Best effort indicator\"" },
    { 0xbf, "0xbf \"Traffic management options\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_39[] = { /* atm_fd */
    { 0, "0 \"No Frame discard allowed\"" },
    { 1, "1 \"Frame discard allowed\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_41[] = { /* atm_tag */
    { 0, "0 \"Tagging not requested\"" },
    { 1, "1 \"Tagging requested\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_43[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_47[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_48[] = { /* atm_bc */
    { 1, "1 \"BCOB-A\"" },
    { 3, "3 \"BCOB-C\"" },
    { 16, "16 \"BCOB-X\"" },
    { 24, "24 \"Transparent VP service\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_49[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_50[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_51[] = { /* atm_tc */
    { 0x05, "0x05 \"CBR\"" },
    { 0x07, "0x07 \"CBR with CLR commitment on CLP=0+1\"" },
    { 0x09, "0x09 \"Real time VBR\"" },
    { 0x13, "0x13 \"Real time VBR w/ CLR comm. on CLP=0+1\"" },
    { 0x0a, "0x0a \"Non-real time VBR\"" },
    { 0x0b, "0x0b \"Non-real time VBR w/ CLR com. CLP=0+1\"" },
    { 0x0c, "0x0c \"ABR\"" },
    { 0x00, "0x00 \"Non-real time VBR (reception only)\"" },
    { 0x01, "0x01 \"Real time VBR (reception only)\"" },
    { 0x02, "0x02 \"Non-real time VBR (reception only)\"" },
    { 0x04, "0x04 \"CBR (reception only)\"" },
    { 0x06, "0x06 \"CBR (reception only)\"" },
    { 0x08, "0x08 \"Non-real time VBR (reception only)\"" },
    { 0x20, "0x20 \"Reserved for backward compatibility\"" },
    { 0x21, "0x21 \"Reserved for backward compatibility\"" },
    { 0x22, "0x22 \"Reserved for backward compatibility\"" },
    { 0x24, "0x24 \"Reserved for backward compatibility\"" },
    { 0x25, "0x25 \"Reserved for backward compatibility\"" },
    { 0x26, "0x26 \"Reserved for backward compatibility\"" },
    { 0x28, "0x28 \"Reserved for backward compatibility\"" },
    { 0x29, "0x29 \"Reserved for backward compatibility\"" },
    { 0x2a, "0x2a \"Reserved for backward compatibility\"" },
    { 0x40, "0x40 \"Reserved for backward compatibility\"" },
    { 0x41, "0x41 \"Reserved for backward compatibility\"" },
    { 0x42, "0x42 \"Reserved for backward compatibility\"" },
    { 0x44, "0x44 \"Reserved for backward compatibility\"" },
    { 0x45, "0x45 \"Reserved for backward compatibility\"" },
    { 0x46, "0x46 \"Reserved for backward compatibility\"" },
    { 0x48, "0x48 \"Reserved for backward compatibility\"" },
    { 0x49, "0x49 \"Reserved for backward compatibility\"" },
    { 0x4a, "0x4a \"Reserved for backward compatibility\"" },
    { 0x60, "0x60 \"Reserved for backward compatibility\"" },
    { 0x61, "0x61 \"Reserved for backward compatibility\"" },
    { 0x62, "0x62 \"Reserved for backward compatibility\"" },
    { 0x64, "0x64 \"Reserved for backward compatibility\"" },
    { 0x65, "0x65 \"Reserved for backward compatibility\"" },
    { 0x66, "0x66 \"Reserved for backward compatibility\"" },
    { 0x68, "0x68 \"Reserved for backward compatibility\"" },
    { 0x69, "0x69 \"Reserved for backward compatibility\"" },
    { 0x6a, "0x6a \"Reserved for backward compatibility\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_52[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_53[] = { /* atm_stc */
    { 0, "0 \"not susceptible to clipping\"" },
    { 1, "1 \"susceptible to clipping\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_54[] = { /* atm_upcc */
    { 0, "0 \"point-to-point\"" },
    { 1, "1 \"point-to-multipoint\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_55[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_59[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_60[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_61[] = {
    { 0, "0" },
    { 1, "1" },
    { 2, "2" },
    { 3, "3" },
    { 4, "4" },
    { 0, NULL }
};

static SYM_NAME dump_sym_68[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_72[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_73[] = {
    { 1, "1" },
    { 2, "2" },
    { 3, "3" },
    { 0, NULL }
};

static SYM_NAME dump_sym_74[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_76[] = { /* atm_l2 */
    { 0, "0 \"L2 not specified\"" },
    { 0x01, "0x01 \"Basic mode ISO 1745\"" },
    { 0x02, "0x02 \"ITU-T Q.291 (Rec. I.441)\"" },
    { 0x06, "0x06 \"ITU-T X.25, link layer\"" },
    { 0x07, "0x07 \"ITU-T X.25, multilink\"" },
    { 0x08, "0x08 \"Extended LAPB, half-duplex (Rec. T.71)\"" },
    { 0x09, "0x09 \"HDLC ARM (ISO/IEC 4335)\"" },
    { 0x0a, "0x0a \"HDLC NRM (ISO/IEC 4335)\"" },
    { 0x0b, "0x0b \"HDLC ABM (ISO/IEC 4335)\"" },
    { 0x0c, "0x0c \"LAN LLC (ISO/IEC 8802/2)\"" },
    { 0x0d, "0x0d \"ITU-T X.75, SLP\"" },
    { 0x0e, "0x0e \"ITU-T Q.922\"" },
    { 0x10, "0x10 \"user-specified\"" },
    { 0x11, "0x11 \"ISO 7776 DTE-DTE\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_77[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_78[] = { /* atm_imd */
    { 0, "0 \"mode not specified\"" },
    { 1, "1 \"normal mode of operation\"" },
    { 2, "2 \"extended mode of operation\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_79[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_80[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_82[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_83[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_85[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_86[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_87[] = { /* atm_l3 */
    { 0, "0 \"L3 not specified\"" },
    { 0x06, "0x06 \"ITU-T X.25, packet layer\"" },
    { 0x07, "0x07 \"ISO/IEC 8208\"" },
    { 0x08, "0x08 \"ITU-T X.223 | ISO/IEC 8878\"" },
    { 0x09, "0x09 \"ITU-T X.233 | ISO/IEC 8473\"" },
    { 0x0a, "0x0a \"ITU-T T.70 minimum network layer\"" },
    { 0x0b, "0x0b \"ISO/IEC TR 9577\"" },
    { 0x0c, "0x0c \"ITU-T Recommendation H.310\"" },
    { 0x0d, "0x0d \"ITU-T Recommendation H.321\"" },
    { 0x10, "0x10 \"user-specified\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_88[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_90[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_92[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_93[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_95[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_96[] = { /* atm_tt */
    { 0, "0 \"terminal type not specified\"" },
    { 1, "1 \"receive only\"" },
    { 2, "2 \"send only\"" },
    { 3, "3 \"receive and send\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_97[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_98[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_99[] = { /* atm_mc */
    { 0, "0 \"no multiplexing\"" },
    { 1, "1 \"transport stream (TS)\"" },
    { 2, "2 \"transport stream with forward error corr.\"" },
    { 3, "3 \"program stream (PS)\"" },
    { 4, "4 \"program stream with forward error corr.\"" },
    { 5, "5 \"ITU-T Rec. H.221\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_101[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_102[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_103[] = {
    { 0x40, "0x40" },
    { 0x0, "0x0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_104[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_105[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_106[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_107[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_110[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_112[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_114[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_115[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_119[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_120[] = {
    { 1, "1" },
    { 2, "2" },
    { 3, "3" },
    { 0, NULL }
};

static SYM_NAME dump_sym_121[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_124[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_126[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_127[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_129[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_130[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_132[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_133[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_135[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_137[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_139[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_140[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_142[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_144[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_145[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_148[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_149[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_150[] = {
    { 0x40, "0x40" },
    { 0x0, "0x0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_151[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_152[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_153[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_154[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_157[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_159[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_161[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_162[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_166[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_167[] = {
    { 1, "1" },
    { 2, "2" },
    { 3, "3" },
    { 0, NULL }
};

static SYM_NAME dump_sym_168[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_171[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_173[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_174[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_176[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_177[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_179[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_180[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_182[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_184[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_186[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_187[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_189[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_191[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_192[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_195[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_196[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_197[] = {
    { 0x40, "0x40" },
    { 0x0, "0x0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_198[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_199[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_200[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_201[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_204[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_206[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_208[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_209[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_213[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_215[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_219[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_220[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_221[] = { /* atm_np */
    { 0, "0 \"unknown\"" },
    { 1, "1 \"ISDN numbering plan (E.164)\"" },
    { 2, "2 \"ATM endsystem address\"" },
    { 9, "9 \"private numbering plan\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_222[] = { /* atm_ton */
    { 0, "0 \"unknown\"" },
    { 1, "1 \"international number\"" },
    { 2, "2 \"national number\"" },
    { 3, "3 \"network specific number\"" },
    { 4, "4 \"subscriber number\"" },
    { 6, "6 \"abbreviated number\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_226[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_230[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_231[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_232[] = { /* atm_sat */
    { 0, "0 \"NSAP (Rec. X.213 ISO/IEC 8348)\"" },
    { 1, "1 \"ATM endsystem address\"" },
    { 2, "2 \"user-specified\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_233[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_235[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_239[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_242[] = {
    { 0, "0" },
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_243[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_244[] = { /* atm_prs */
    { 0, "0 \"presentation allowed\"" },
    { 1, "1 \"presentation restricted\"" },
    { 2, "2 \"number not available\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_245[] = { /* atm_scrn */
    { 0, "0 \"user-provided, not screened\"" },
    { 1, "1 \"user-provided, verified and passed\"" },
    { 2, "2 \"user-provided, verified and failed\"" },
    { 3, "3 \"network provided\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_247[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_251[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_252[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_254[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_256[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_260[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_261[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_262[] = { /* atm_loc */
    { 0, "0 \"user\"" },
    { 1, "1 \"private network serving the local user\"" },
    { 2, "2 \"public network serving the local user\"" },
    { 3, "3 \"transit network\"" },
    { 4, "4 \"public network serving the remote user\"" },
    { 5, "5 \"private network serving the remote user\"" },
    { 7, "7 \"international network\"" },
    { 10, "10 \"network beyond interworking point\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_263[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_264[] = { /* atm_cv */
    { 1, "1 \"unallocated (unassigned) number\"" },
    { 2, "2 \"no route to specified transit network\"" },
    { 3, "3 \"no route to destination\"" },
    { 10, "10 \"VPCI/VCI unacceptable\"" },
    { 16, "16 \"normal call clearing\"" },
    { 17, "17 \"user busy\"" },
    { 18, "18 \"no user responding\"" },
    { 21, "21 \"call rejected\"" },
    { 22, "22 \"number changed\"" },
    { 23, "23 \"user rejects all calls with calling line identification restriction (CLIR)\"" },
    { 27, "27 \"destination out of order\"" },
    { 28, "28 \"invalid number format (address incomplete)\"" },
    { 30, "30 \"response to STATUS ENQUIRY\"" },
    { 31, "31 \"normal, unspecified\"" },
    { 35, "35 \"requested VPCI/VCI unavailable\"" },
    { 36, "36 \"VPCI/VCI assignment failure\"" },
    { 37, "37 \"user cell rate not available (>3.0)\"" },
    { 38, "38 \"network out of order - unused\"" },
    { 41, "41 \"temporary failure\"" },
    { 43, "43 \"access information discarded\"" },
    { 45, "45 \"no VPCI/VCI available\"" },
    { 47, "47 \"resource unavailable, unspecified\"" },
    { 49, "49 \"Quality of Service unavailable\"" },
    { 51, "51 \"user cell rate not available (3.0)\"" },
    { 57, "57 \"bearer capability not authorized\"" },
    { 58, "58 \"bearer capability not presently available\"" },
    { 63, "63 \"service or option not available, unspecified\"" },
    { 65, "65 \"bearer capability not implemented\"" },
    { 73, "73 \"unsupported combination of traffic parameters\"" },
    { 78, "78 \"AAL param. cannot be supported (>3.0)\"" },
    { 81, "81 \"invalid call reference value\"" },
    { 82, "82 \"identified channel does not exist\"" },
    { 88, "88 \"incompatible destination\"" },
    { 89, "89 \"invalid endpoint reference\"" },
    { 91, "91 \"invalid transit network selection\"" },
    { 92, "92 \"too many pending add party requests\"" },
    { 93, "93 \"AAL param. cannot be supported (3.0)\"" },
    { 96, "96 \"mandatory information element is missing\"" },
    { 97, "97 \"message type non-existent or not implemented\"" },
    { 99, "99 \"information element non-existent or not implemented\"" },
    { 100, "100 \"invalid information element contents\"" },
    { 101, "101 \"message not compatible with call state\"" },
    { 102, "102 \"recovery on timer expiry\"" },
    { 104, "104 \"incorrect message length\"" },
    { 111, "111 \"protocol error, unspecified\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_265[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_266[] = { /* atm_pu */
    { 0, "0 \"Network service - Provider\"" },
    { 1, "1 \"Network service - User\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_267[] = { /* atm_na */
    { 0, "0 \"Normal\"" },
    { 1, "1 \"Abnormal\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_268[] = { /* atm_cond */
    { 0, "0 \"Unknown\"" },
    { 1, "1 \"Permanent\"" },
    { 2, "2 \"Transient\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_269[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_271[] = {
    { ATM_RSN_USER, "ATM_RSN_USER" },
    { ATM_RSN_IE_MISS, "ATM_RSN_IE_MISS" },
    { ATM_RSN_IE_INSUFF, "ATM_RSN_IE_INSUFF" },
    { 0, NULL }
};

static SYM_NAME dump_sym_282[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_286[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_287[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_289[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_291[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_295[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_297[] = {
    { ATM_RSN_USER, "ATM_RSN_USER" },
    { ATM_RSN_IE_MISS, "ATM_RSN_IE_MISS" },
    { ATM_RSN_IE_INSUFF, "ATM_RSN_IE_INSUFF" },
    { 0, NULL }
};

static SYM_NAME dump_sym_308[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_312[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_313[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_314[] = { /* atm_vpa */
    { 0, "0 \"VP-associated signalling\"" },
    { 1, "1 \"explicit indication of VPCI\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_315[] = { /* atm_poe */
    { 0, "0 \"exclusive VPCI; exclusive VCI\"" },
    { 1, "1 \"exclusive VPCI; any VCI\"" },
    { 2, "2 \"exclusive VPCI; no VCI (used for VPCs)\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_318[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_322[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_323[] = { /* atm_tdl */
    { 0x01, "0x01 \"Cumulative transit delay value\"" },
    { 0x03, "0x03 \"Maximum end-to-end transit delay value\"" },
    { 0x0a, "0x0a \"Network generated indicator\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_326[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_330[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_331[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_332[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_333[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_337[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_338[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_339[] = {
    { 2, "2" },
    { 0, NULL }
};

static SYM_NAME dump_sym_340[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_344[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_345[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_347[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_351[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_352[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_353[] = {
    { 0x21, "0x21" },
    { 0, NULL }
};

static SYM_NAME dump_sym_354[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_358[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_359[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_360[] = { /* atm_tni */
    { 0x00, "0x00 \"User-specified\"" },
    { 0x02, "0x02 \"National network identification\"" },
    { 0x04, "0x04 \"International network identification\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_361[] = { /* atm_nip */
    { 0x00, "0x00 \"Unknown\"" },
    { 0x01, "0x01 \"Carrier identification code\"" },
    { 0x03, "0x03 \"Data network id. code (X.121)\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_363[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_367[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_369[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_373[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_374[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_375[] = { /* atm_shi */
    { 0x00, "0x00 \"No user specified requirement\"" },
    { 0x01, "0x01 \"Aggr. shaping of user & OAM not all.\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_376[] = { /* atm_oci */
    { 0x00, "0x00 \"Use of e2e OAM F5 flow is optional\"" },
    { 0x01, "0x01 \"Use of e2e OAM F5 flow is mandatory\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_377[] = { /* atm_unfm */
    { 0x00, "0x00 \"No user-orig. fault mg. indications\"" },
    { 0x01, "0x01 \"Use of u-o fm. ind. w/ rate 1 cps\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_378[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_379[] = { /* atm_ofi */
    { 0x00, "0x00 \"0% of cell rate (CLP=0+1) in ATM TD\"" },
    { 0x01, "0x01 \"0.1% of cell rate (CLP=0+1) in ATM TD\"" },
    { 0x04, "0x04 \"1% of cell rate (CLP=0+1) in ATM TD\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_381[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_385[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_386[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_387[] = { /* atm_irs */
    { 0x01, "0x01 \"DSM-CC ISO/IEC 13818-6\"" },
    { 0x02, "0x02 \"Recommendation H.245\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_388[] = { /* atm_it */
    { 0x01, "0x01 \"Session\"" },
    { 0x02, "0x02 \"Resource\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_389[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_392[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_395[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_399[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_400[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_403[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_406[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_409[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_413[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_414[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_417[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_420[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_423[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_427[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_428[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_429[] = { /* atm_lit */
    { 0x00, "0x00 \"Root assigned\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_431[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_435[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_436[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_437[] = { /* atm_lsi */
    { 0x00, "0x00 \"Network Join Without Root Notif.\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_438[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_442[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_444[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_448[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_449[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_450[] = { /* atm_tcs */
    { 0x00, "0x00 \"Organizational\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_451[] = { /* atm_css */
    { 0x00, "0x00 \"Reserved\"" },
    { 0x01, "0x01 \"Local network\"" },
    { 0x02, "0x02 \"Local network plus one\"" },
    { 0x03, "0x03 \"Local network plus two\"" },
    { 0x04, "0x04 \"Site minus one\"" },
    { 0x05, "0x05 \"Intra-site\"" },
    { 0x06, "0x06 \"Site plus one\"" },
    { 0x07, "0x07 \"Organization minus one\"" },
    { 0x08, "0x08 \"Intra-organization\"" },
    { 0x09, "0x09 \"Organization plus one\"" },
    { 0x0a, "0x0a \"Community minus one\"" },
    { 0x0b, "0x0b \"Intra-community\"" },
    { 0x0c, "0x0c \"Community plus one\"" },
    { 0x0d, "0x0d \"Regional\"" },
    { 0x0e, "0x0e \"Inter-regional\"" },
    { 0x0f, "0x0f \"Global\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_452[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_456[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_471[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_475[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_483[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_487[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_488[] = { /* atm_eqo */
    { 0x00, "0x00 \"Originating user\"" },
    { 0x01, "0x01 \"Intermediate network\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_489[] = { /* atm_eqp */
    { 0x94, "0x94 \"Acceptable fwd peak-to-peak CDV\"" },
    { 0x95, "0x95 \"Acceptable bwd peak-to-peak CDV\"" },
    { 0x96, "0x96 \"Cumulative fwd peak-to-peak CDV\"" },
    { 0x97, "0x97 \"Cumulative bwd peak-to-peak CDV\"" },
    { 0xa2, "0xa2 \"Acceptable fwd cell loss ratio\"" },
    { 0xa3, "0xa3 \"Acceptable bwd cell loss ratio\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_496[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_500[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_501[] = { /* atm_aap */
    { 0xc2, "0xc2 \"Forward additional parameters record\"" },
    { 0xc3, "0xc3 \"Backward additional parameters record\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_504[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_508[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_509[] = { /* atm_asp */
    { 0xc2, "0xc2 \"Forward ABR initial cell rate, CLP01\"" },
    { 0xc3, "0xc3 \"Backward ABR initial cell rate, CLP01\"" },
    { 0xc4, "0xc4 \"Fwd ABR transient buffer exposure\"" },
    { 0xc5, "0xc5 \"Bwd ABR transient buffer exposure\"" },
    { 0xc6, "0xc6 \"Cumulative RM fixed round trip time\"" },
    { 0xc8, "0xc8 \"Forward rate increase factor\"" },
    { 0xc9, "0xc9 \"Backward rate increase factor\"" },
    { 0xca, "0xca \"Forward rate decrease factor\"" },
    { 0xcb, "0xcb \"Backward rate decrease factor\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_519[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_523[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_524[] = {
    { 0, "0" },
    { 0, NULL }
};

static SYM_NAME dump_sym_526[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_530[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_532[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_536[] = {
    { 0, NULL }
};

static SYM_NAME dump_sym_537[] = { /* atm_tor */
    { 0x01, "0x01 \"Modification confirmation\"" },
    { 0, NULL }
};

static SYM_NAME dump_sym_538[] = {
    { 1, "1" },
    { 0, NULL }
};

static SYM_NAME dump_sym_542[] = {
    { 0, NULL }
};

typedef struct {
    int level;
    const SYM_NAME *sym;
    const char *name;
} DUMP_FIELD;

static DUMP_FIELD dump_fields[] = {
    { 0, dump_sym_0, "_pdsc" },
    { 0, dump_sym_1, "_cr_len" },
    { 0, NULL, "call_ref" },
    { 0, dump_sym_3, "msg_type" },
    { 0, dump_sym_4, "_ext" },
    { 0, dump_sym_5, "_flag" },
    { 0, dump_sym_6, "_action_ind" },
    { 0, dump_sym_7, "msg_len" },
    { 1, dump_sym_8, "_ie_id" },
    { 2, dump_sym_9, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_13, "_ie_len" },
    { 3, dump_sym_14, "aal_type" },
    { 4, dump_sym_15, "_id" },
    { 5, NULL, "fw_max_sdu" },
    { 5, NULL, "bw_max_sdu" },
    { 5, NULL, "aal_mode" },
    { 5, NULL, "sscs_type" },
    { 2, dump_sym_20, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_24, "_ie_len" },
    { 3, dump_sym_25, "_id" },
    { 4, NULL, "fw_pcr_0" },
    { 4, NULL, "bw_pcr_0" },
    { 4, NULL, "fw_pcr_01" },
    { 4, NULL, "bw_pcr_01" },
    { 4, NULL, "fw_scr_0" },
    { 4, NULL, "bw_scr_0" },
    { 4, NULL, "fw_scr_01" },
    { 4, NULL, "bw_scr_01" },
    { 4, NULL, "fw_mbs_0" },
    { 4, NULL, "bw_mbs_0" },
    { 4, NULL, "fw_mbs_01" },
    { 4, NULL, "bw_mbs_01" },
    { 4, NULL, "best_effort" },
    { 4, dump_sym_39, "fw_fdisc" },
    { 4, dump_sym_39, "bw_fdisc" },
    { 4, dump_sym_41, "bw_tag" },
    { 4, dump_sym_41, "fw_tag" },
    { 2, dump_sym_43, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_47, "_ie_len" },
    { 3, dump_sym_48, "bearer_class" },
    { 3, dump_sym_49, "_ext" },
    { 4, dump_sym_50, "_ext" },
    { 4, dump_sym_51, "trans_cap" },
    { 3, dump_sym_52, "_ext" },
    { 3, dump_sym_53, "susc_clip" },
    { 3, dump_sym_54, "upcc" },
    { 2, dump_sym_55, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_59, "_ie_len" },
    { 3, dump_sym_60, "_ext" },
    { 3, dump_sym_61, "hli_type" },
    { 4, NULL, "iso_hli" },
    { 4, NULL, "user_hli" },
    { 4, NULL, "hlp" },
    { 4, NULL, "hli_oui" },
    { 4, NULL, "app_id" },
    { 4, NULL, "tobedefined" },
    { 2, dump_sym_68, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_72, "_ie_len" },
    { 3, dump_sym_73, "_lid" },
    { 4, dump_sym_74, "_ext" },
    { 4, NULL, "uil1_proto" },
    { 4, dump_sym_76, "uil2_proto" },
    { 5, dump_sym_77, "_ext" },
    { 6, dump_sym_78, "l2_mode" },
    { 6, dump_sym_79, "q933" },
    { 6, dump_sym_80, "_ext" },
    { 7, NULL, "window_size" },
    { 7, dump_sym_82, "_ext" },
    { 5, dump_sym_83, "_ext" },
    { 5, NULL, "user_l2" },
    { 5, dump_sym_85, "_ext" },
    { 5, dump_sym_86, "_ext" },
    { 4, dump_sym_87, "uil3_proto" },
    { 5, dump_sym_88, "_ext" },
    { 6, dump_sym_78, "l3_mode" },
    { 6, dump_sym_90, "_ext" },
    { 7, NULL, "def_pck_size" },
    { 7, dump_sym_92, "_ext" },
    { 8, dump_sym_93, "_ext" },
    { 8, NULL, "pck_win_size" },
    { 5, dump_sym_95, "_ext" },
    { 6, dump_sym_96, "term_type" },
    { 6, dump_sym_97, "_ext" },
    { 7, dump_sym_98, "_ext" },
    { 7, dump_sym_99, "fw_mpx_cap" },
    { 7, dump_sym_99, "bw_mpx_cap" },
    { 5, dump_sym_101, "_ext" },
    { 6, dump_sym_102, "_ext" },
    { 6, dump_sym_103, "ipi_high" },
    { 7, dump_sym_104, "_ext" },
    { 7, dump_sym_105, "_ipi_low" },
    { 8, dump_sym_106, "_ext" },
    { 8, dump_sym_107, "_snap_id" },
    { 8, NULL, "oui" },
    { 8, NULL, "pid" },
    { 7, dump_sym_110, "_ext" },
    { 7, NULL, "ipi_low" },
    { 5, dump_sym_112, "_ext" },
    { 5, NULL, "user_l3" },
    { 5, dump_sym_114, "_ext" },
    { 2, dump_sym_115, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_119, "_ie_len" },
    { 3, dump_sym_120, "_lid" },
    { 4, dump_sym_121, "_ext" },
    { 4, NULL, "uil1_proto" },
    { 4, dump_sym_76, "uil2_proto" },
    { 5, dump_sym_124, "_ext" },
    { 6, dump_sym_78, "l2_mode" },
    { 6, dump_sym_126, "q933" },
    { 6, dump_sym_127, "_ext" },
    { 7, NULL, "window_size" },
    { 7, dump_sym_129, "_ext" },
    { 5, dump_sym_130, "_ext" },
    { 5, NULL, "user_l2" },
    { 5, dump_sym_132, "_ext" },
    { 5, dump_sym_133, "_ext" },
    { 4, dump_sym_87, "uil3_proto" },
    { 5, dump_sym_135, "_ext" },
    { 6, dump_sym_78, "l3_mode" },
    { 6, dump_sym_137, "_ext" },
    { 7, NULL, "def_pck_size" },
    { 7, dump_sym_139, "_ext" },
    { 8, dump_sym_140, "_ext" },
    { 8, NULL, "pck_win_size" },
    { 5, dump_sym_142, "_ext" },
    { 6, dump_sym_96, "term_type" },
    { 6, dump_sym_144, "_ext" },
    { 7, dump_sym_145, "_ext" },
    { 7, dump_sym_99, "fw_mpx_cap" },
    { 7, dump_sym_99, "bw_mpx_cap" },
    { 5, dump_sym_148, "_ext" },
    { 6, dump_sym_149, "_ext" },
    { 6, dump_sym_150, "ipi_high" },
    { 7, dump_sym_151, "_ext" },
    { 7, dump_sym_152, "_ipi_low" },
    { 8, dump_sym_153, "_ext" },
    { 8, dump_sym_154, "_snap_id" },
    { 8, NULL, "oui" },
    { 8, NULL, "pid" },
    { 7, dump_sym_157, "_ext" },
    { 7, NULL, "ipi_low" },
    { 5, dump_sym_159, "_ext" },
    { 5, NULL, "user_l3" },
    { 5, dump_sym_161, "_ext" },
    { 2, dump_sym_162, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_166, "_ie_len" },
    { 3, dump_sym_167, "_lid" },
    { 4, dump_sym_168, "_ext" },
    { 4, NULL, "uil1_proto" },
    { 4, dump_sym_76, "uil2_proto" },
    { 5, dump_sym_171, "_ext" },
    { 6, dump_sym_78, "l2_mode" },
    { 6, dump_sym_173, "q933" },
    { 6, dump_sym_174, "_ext" },
    { 7, NULL, "window_size" },
    { 7, dump_sym_176, "_ext" },
    { 5, dump_sym_177, "_ext" },
    { 5, NULL, "user_l2" },
    { 5, dump_sym_179, "_ext" },
    { 5, dump_sym_180, "_ext" },
    { 4, dump_sym_87, "uil3_proto" },
    { 5, dump_sym_182, "_ext" },
    { 6, dump_sym_78, "l3_mode" },
    { 6, dump_sym_184, "_ext" },
    { 7, NULL, "def_pck_size" },
    { 7, dump_sym_186, "_ext" },
    { 8, dump_sym_187, "_ext" },
    { 8, NULL, "pck_win_size" },
    { 5, dump_sym_189, "_ext" },
    { 6, dump_sym_96, "term_type" },
    { 6, dump_sym_191, "_ext" },
    { 7, dump_sym_192, "_ext" },
    { 7, dump_sym_99, "fw_mpx_cap" },
    { 7, dump_sym_99, "bw_mpx_cap" },
    { 5, dump_sym_195, "_ext" },
    { 6, dump_sym_196, "_ext" },
    { 6, dump_sym_197, "ipi_high" },
    { 7, dump_sym_198, "_ext" },
    { 7, dump_sym_199, "_ipi_low" },
    { 8, dump_sym_200, "_ext" },
    { 8, dump_sym_201, "_snap_id" },
    { 8, NULL, "oui" },
    { 8, NULL, "pid" },
    { 7, dump_sym_204, "_ext" },
    { 7, NULL, "ipi_low" },
    { 5, dump_sym_206, "_ext" },
    { 5, NULL, "user_l3" },
    { 5, dump_sym_208, "_ext" },
    { 2, dump_sym_209, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_213, "_ie_len" },
    { 3, NULL, "call_state" },
    { 2, dump_sym_215, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_219, "_ie_len" },
    { 3, dump_sym_220, "_ext" },
    { 3, dump_sym_221, "_plan" },
    { 4, dump_sym_222, "_type" },
    { 4, NULL, "cdpn_e164" },
    { 4, dump_sym_222, "_type" },
    { 4, NULL, "cdpn_esa" },
    { 2, dump_sym_226, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_230, "_ie_len" },
    { 3, dump_sym_231, "_ext" },
    { 3, dump_sym_232, "cdps_type" },
    { 3, dump_sym_233, "_oddeven" },
    { 3, NULL, "cdps" },
    { 2, dump_sym_235, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_239, "_ie_len" },
    { 3, dump_sym_221, "cgpn_plan" },
    { 3, dump_sym_222, "cgpn_type" },
    { 3, dump_sym_242, "_ext" },
    { 4, dump_sym_243, "_ext" },
    { 4, dump_sym_244, "pres_ind" },
    { 4, dump_sym_245, "scr_ind" },
    { 3, NULL, "cgpn" },
    { 2, dump_sym_247, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_251, "_ie_len" },
    { 3, dump_sym_252, "_ext" },
    { 3, dump_sym_232, "cgps_type" },
    { 3, dump_sym_254, "_oddeven" },
    { 3, NULL, "cgps" },
    { 2, dump_sym_256, "_ext" },
    { 2, dump_sym_10, "cause_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_260, "_ie_len" },
    { 3, dump_sym_261, "_ext" },
    { 3, dump_sym_262, "location" },
    { 3, dump_sym_263, "_ext" },
    { 3, dump_sym_264, "cause" },
    { 4, dump_sym_265, "_ext" },
    { 4, dump_sym_266, "pu" },
    { 4, dump_sym_267, "na" },
    { 4, dump_sym_268, "cond2" },
    { 4, dump_sym_269, "_ext" },
    { 4, dump_sym_268, "cond3" },
    { 4, dump_sym_271, "reason" },
    { 5, NULL, "user_diag" },
    { 5, dump_sym_8, "ie_id3" },
    { 4, NULL, "new_dest" },
    { 4, NULL, "invalid" },
    { 4, NULL, "ie_id6" },
    { 4, NULL, "ucr_id" },
    { 4, NULL, "unav_vpci" },
    { 4, NULL, "unav_vci" },
    { 4, dump_sym_3, "bad_msg_type" },
    { 4, NULL, "timer" },
    { 2, dump_sym_282, "_ext" },
    { 2, dump_sym_10, "cause_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_286, "_ie_len" },
    { 3, dump_sym_287, "_ext" },
    { 3, dump_sym_262, "location" },
    { 3, dump_sym_289, "_ext" },
    { 3, dump_sym_264, "cause" },
    { 4, dump_sym_291, "_ext" },
    { 4, dump_sym_266, "pu" },
    { 4, dump_sym_267, "na" },
    { 4, dump_sym_268, "cond2" },
    { 4, dump_sym_295, "_ext" },
    { 4, dump_sym_268, "cond3" },
    { 4, dump_sym_297, "reason" },
    { 5, NULL, "user_diag" },
    { 5, dump_sym_8, "ie_id3" },
    { 4, NULL, "new_dest" },
    { 4, NULL, "invalid" },
    { 4, NULL, "ie_id6" },
    { 4, NULL, "ucr_id" },
    { 4, NULL, "unav_vpci" },
    { 4, NULL, "unav_vci" },
    { 4, dump_sym_3, "bad_msg_type" },
    { 4, NULL, "timer" },
    { 2, dump_sym_308, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_312, "_ie_len" },
    { 3, dump_sym_313, "_ext" },
    { 3, dump_sym_314, "_vp_ass" },
    { 3, dump_sym_315, "_pref_exc" },
    { 3, NULL, "vpi" },
    { 3, NULL, "vci" },
    { 2, dump_sym_318, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_322, "_ie_len" },
    { 3, dump_sym_323, "_id" },
    { 4, NULL, "cum_delay" },
    { 4, NULL, "max_delay" },
    { 2, dump_sym_326, "_ext" },
    { 2, dump_sym_10, "qos_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_330, "_ie_len" },
    { 3, dump_sym_331, "qos_fw" },
    { 3, dump_sym_332, "qos_bw" },
    { 2, dump_sym_333, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_337, "_ie_len" },
    { 3, dump_sym_338, "_ext" },
    { 3, dump_sym_339, "rep_ind" },
    { 2, dump_sym_340, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_344, "_ie_len" },
    { 3, dump_sym_345, "_ext" },
    { 3, NULL, "rst_class" },
    { 2, dump_sym_347, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_351, "_ie_len" },
    { 3, dump_sym_352, "_ext" },
    { 3, dump_sym_353, "bbsc_ind" },
    { 2, dump_sym_354, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_358, "_ie_len" },
    { 3, dump_sym_359, "_ext" },
    { 3, dump_sym_360, "_net_type" },
    { 3, dump_sym_361, "_carrier_id" },
    { 3, NULL, "net_id" },
    { 2, dump_sym_363, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_367, "_ie_len" },
    { 3, NULL, "notification" },
    { 2, dump_sym_369, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_373, "_ie_len" },
    { 3, dump_sym_374, "_ext" },
    { 3, dump_sym_375, "shaping" },
    { 3, dump_sym_376, "compliance" },
    { 3, dump_sym_377, "fault" },
    { 3, dump_sym_378, "_ext" },
    { 3, dump_sym_379, "fwd_ofi" },
    { 3, dump_sym_379, "bwd_ofi" },
    { 2, dump_sym_381, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_385, "_ie_len" },
    { 3, dump_sym_386, "_dummy" },
    { 3, dump_sym_387, "id_std_app" },
    { 4, dump_sym_388, "_type" },
    { 4, dump_sym_389, "_length" },
    { 5, NULL, "session_id" },
    { 4, dump_sym_388, "_type" },
    { 4, dump_sym_392, "_length" },
    { 5, NULL, "resource_id" },
    { 4, NULL, "unrecognized_git_identifiers" },
    { 2, dump_sym_395, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_399, "_ie_len" },
    { 3, dump_sym_400, "_dummy" },
    { 3, dump_sym_387, "id_std_app" },
    { 4, dump_sym_388, "_type" },
    { 4, dump_sym_403, "_length" },
    { 5, NULL, "session_id" },
    { 4, dump_sym_388, "_type" },
    { 4, dump_sym_406, "_length" },
    { 5, NULL, "resource_id" },
    { 4, NULL, "unrecognized_git_identifiers" },
    { 2, dump_sym_409, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_413, "_ie_len" },
    { 3, dump_sym_414, "_dummy" },
    { 3, dump_sym_387, "id_std_app" },
    { 4, dump_sym_388, "_type" },
    { 4, dump_sym_417, "_length" },
    { 5, NULL, "session_id" },
    { 4, dump_sym_388, "_type" },
    { 4, dump_sym_420, "_length" },
    { 5, NULL, "resource_id" },
    { 4, NULL, "unrecognized_git_identifiers" },
    { 2, dump_sym_423, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_427, "_ie_len" },
    { 3, dump_sym_428, "_ext" },
    { 3, dump_sym_429, "lij_id_type" },
    { 3, NULL, "lij_id" },
    { 2, dump_sym_431, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_435, "_ie_len" },
    { 3, dump_sym_436, "_ext" },
    { 3, dump_sym_437, "lij_scr_ind" },
    { 2, dump_sym_438, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_442, "_ie_len" },
    { 3, NULL, "leaf_sn" },
    { 2, dump_sym_444, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_448, "_ie_len" },
    { 3, dump_sym_449, "_ext" },
    { 3, dump_sym_450, "scope_type" },
    { 3, dump_sym_451, "scope_sel" },
    { 2, dump_sym_452, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_456, "_ie_len" },
    { 3, dump_sym_25, "_id" },
    { 4, NULL, "altfw_pcr_0" },
    { 4, NULL, "altbw_pcr_0" },
    { 4, NULL, "altfw_pcr_01" },
    { 4, NULL, "altbw_pcr_01" },
    { 4, NULL, "altfw_scr_0" },
    { 4, NULL, "altbw_scr_0" },
    { 4, NULL, "altfw_scr_01" },
    { 4, NULL, "altbw_scr_01" },
    { 4, NULL, "altfw_mbs_0" },
    { 4, NULL, "altbw_mbs_0" },
    { 4, NULL, "altfw_mbs_01" },
    { 4, NULL, "altbw_mbs_01" },
    { 4, NULL, "altbest_effort" },
    { 2, dump_sym_471, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_475, "_ie_len" },
    { 3, dump_sym_25, "_id" },
    { 4, NULL, "minfw_pcr_0" },
    { 4, NULL, "minbw_pcr_0" },
    { 4, NULL, "minfw_pcr_01" },
    { 4, NULL, "minbw_pcr_01" },
    { 4, NULL, "minfw_mcr_01" },
    { 4, NULL, "minbw_mcr_01" },
    { 2, dump_sym_483, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_487, "_ie_len" },
    { 3, dump_sym_488, "eqos_origin" },
    { 3, dump_sym_489, "_id" },
    { 4, NULL, "acc_fw_cdv" },
    { 4, NULL, "acc_bw_cdv" },
    { 4, NULL, "cum_fw_cdv" },
    { 4, NULL, "cum_bw_cdv" },
    { 4, NULL, "acc_fw_clr" },
    { 4, NULL, "acc_bw_clr" },
    { 2, dump_sym_496, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_500, "_ie_len" },
    { 3, dump_sym_501, "_id" },
    { 4, NULL, "abr_fw_add_rec" },
    { 4, NULL, "abr_bw_add_rec" },
    { 2, dump_sym_504, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_508, "_ie_len" },
    { 3, dump_sym_509, "_id" },
    { 4, NULL, "abr_fw_icr" },
    { 4, NULL, "abr_bw_icr" },
    { 4, NULL, "abr_fw_tbe" },
    { 4, NULL, "abr_bw_tbe" },
    { 4, NULL, "atm_crf_rtt" },
    { 4, NULL, "atm_fw_rif" },
    { 4, NULL, "atm_bw_rif" },
    { 4, NULL, "atm_fw_rdf" },
    { 4, NULL, "atm_bw_rdf" },
    { 2, dump_sym_519, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_523, "_ie_len" },
    { 3, dump_sym_524, "_ep_type" },
    { 3, NULL, "ep_ref" },
    { 2, dump_sym_526, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_530, "_ie_len" },
    { 3, NULL, "ep_state" },
    { 2, dump_sym_532, "_ext" },
    { 2, dump_sym_10, "_cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_536, "_ie_len" },
    { 3, dump_sym_537, "type_of_report" },
    { 2, dump_sym_538, "_ext" },
    { 2, dump_sym_10, "__cs" },
    { 2, dump_sym_5, "_flag" },
    { 2, dump_sym_12, "_action_ind" },
    { 2, dump_sym_542, "_ie_len" },
};


/*
 * Sorry, this is necessary ...
 */

#define DUMP_MODE

#include "qd.out.c"

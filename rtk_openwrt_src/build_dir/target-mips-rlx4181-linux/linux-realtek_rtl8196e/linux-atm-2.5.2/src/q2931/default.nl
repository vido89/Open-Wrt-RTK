# THIS IS A MACHINE-GENERATED FILE. DO NOT EDIT !

:q2931_proto
9=9 \"Q.2931 user-network call/connection control message\"

:q2931_cs
0=0 \"ITU-T standardized\"
3=3 \"Standard defined for the network\"

:atm_msg
0x00=0x00 \"National specific message escape\"
0x05=0x05 \"SETUP\"
0x01=0x01 \"ALERTING\"
0x02=0x02 \"CALL PROCEEDING\"
0x07=0x07 \"CONNECT\"
0x0f=0x0f \"CONNECT ACKNOWLEDGE\"
0x46=0x46 \"RESTART\"
0x4d=0x4d \"RELEASE\"
0x4e=0x4e \"RESTART ACKNOWLEDGE\"
0x5a=0x5a \"RELEASE COMPLETE\"
0x6e=0x6e \"NOTIFY\"
0x75=0x75 \"STATUS ENQUIRY\"
0x7d=0x7d \"STATUS\"
0x80=0x80 \"ADD PARTY\"
0x81=0x81 \"ADD PARTY ACKNOWLEDGE\"
0x82=0x82 \"ADD PART REJECT\"
0x85=0x85 \"PARTY ALERTING\"
0x83=0x83 \"DROP PARTY\"
0x84=0x84 \"DROP PARTY ACKNOWLEDGE\"
0x88=0x88 \"MODIFY REQUEST\"
0x89=0x89 \"MODIFY ACKNOWLEDGE\"
0x8a=0x8a \"MODIFY REJECT\"
0x8b=0x8b \"CONNECTION AVAILABLE\"
0x90=0x90 \"LEAF SETUP FAILURE\"
0x91=0x91 \"LEAF SETUP REQUEST\"
0xff=0xff \"reserved for EVEN MORE msg types\"

:atm_ie
0x08=0x08 \"Cause\"
0x14=0x14 \"Call state\"
0x27=0x27 \"Notification indicator\"
0x42=0x42 \"End-to-end transit delay\"
0x54=0x54 \"Endpoint reference\"
0x55=0x55 \"Endpoint state\"
0x58=0x58 \"ATM adaption layer parameters\"
0x59=0x59 \"ATM traffic descriptor\"
0x5a=0x5a \"Connection identifier\"
0x5b=0x5b \"OAM traffic descriptor\"
0x5c=0x5c \"Quality of service parameter\"
0x5d=0x5d \"Broadband high layer information\"
0x5e=0x5e \"Broadband bearer capability\"
0x5f=0x5f \"Broadband low-layer information\"
0x62=0x62 \"Broadband sending complete\"
0x63=0x63 \"Broadband repeat indicator\"
0x6c=0x6c \"Calling party number\"
0x6d=0x6d \"Calling party subaddress\"
0x70=0x70 \"Called party number\"
0x71=0x71 \"Called party subaddress\"
0x78=0x78 \"Transit network selection\"
0x79=0x79 \"Restart indicator\"
0x7f=0x7f \"Generic identifier transport\"
0x81=0x81 \"Alternate ATM traffic descriptor\"
0x80=0x80 \"Minimum acceptable ATM traffic desc.\"
0x84=0x84 \"ABR setup parameters\"
0x89=0x89 \"Broadband report type\"
0xe4=0xe4 \"ABR additional parameters\"
0xe8=0xe8 \"Leaf initiated join call identifer\"
0xe9=0xe9 \"Leaf initiated join parameters\"
0xea=0xea \"Leaf sequence number\"
0xeb=0xeb \"Connection Scope Selection\"
0xec=0xec \"Extended QOS parameters\"

:atm_loc
0=0 \"user\"
1=1 \"private network serving the local user\"
2=2 \"public network serving the local user\"
3=3 \"transit network\"
4=4 \"public network serving the remote user\"
5=5 \"private network serving the remote user\"
7=7 \"international network\"
10=10 \"network beyond interworking point\"

:atm_cv
1=1 \"unallocated (unassigned) number\"
2=2 \"no route to specified transit network\"
3=3 \"no route to destination\"
10=10 \"VPCI/VCI unacceptable\"
16=16 \"normal call clearing\"
17=17 \"user busy\"
18=18 \"no user responding\"
21=21 \"call rejected\"
22=22 \"number changed\"
23=23 \"user rejects all calls with calling line identification restriction (CLIR)\"
27=27 \"destination out of order\"
28=28 \"invalid number format (address incomplete)\"
30=30 \"response to STATUS ENQUIRY\"
31=31 \"normal, unspecified\"
35=35 \"requested VPCI/VCI unavailable\"
36=36 \"VPCI/VCI assignment failure\"
37=37 \"user cell rate not available (>3.0)\"
38=38 \"network out of order - unused\"
41=41 \"temporary failure\"
43=43 \"access information discarded\"
45=45 \"no VPCI/VCI available\"
47=47 \"resource unavailable, unspecified\"
49=49 \"Quality of Service unavailable\"
51=51 \"user cell rate not available (3.0)\"
57=57 \"bearer capability not authorized\"
58=58 \"bearer capability not presently available\"
63=63 \"service or option not available, unspecified\"
65=65 \"bearer capability not implemented\"
73=73 \"unsupported combination of traffic parameters\"
78=78 \"AAL param. cannot be supported (>3.0)\"
81=81 \"invalid call reference value\"
82=82 \"identified channel does not exist\"
88=88 \"incompatible destination\"
89=89 \"invalid endpoint reference\"
91=91 \"invalid transit network selection\"
92=92 \"too many pending add party requests\"
93=93 \"AAL param. cannot be supported (3.0)\"
96=96 \"mandatory information element is missing\"
97=97 \"message type non-existent or not implemented\"
99=99 \"information element non-existent or not implemented\"
100=100 \"invalid information element contents\"
101=101 \"message not compatible with call state\"
102=102 \"recovery on timer expiry\"
104=104 \"incorrect message length\"
111=111 \"protocol error, unspecified\"

:atm_pu
0=0 \"Network service - Provider\"
1=1 \"Network service - User\"

:atm_na
0=0 \"Normal\"
1=1 \"Abnormal\"

:atm_cond
0=0 \"Unknown\"
1=1 \"Permanent\"
2=2 \"Transient\"

:atm_ai_msg
0=0 \"clear call\"
1=1 \"discard and ignore\"
2=2 \"discard and report status\"
3=3 \"reserved\"

:atm_ai_ie
0=0 \"clear call\"
1=1 \"discard IE and proceed\"
2=2 \"discard IE, procees, and report status\"
5=5 \"discard message, and ignore\"
6=6 \"discard message, and report status\"

:atm_ton
0=0 \"unknown\"
1=1 \"international number\"
2=2 \"national number\"
3=3 \"network specific number\"
4=4 \"subscriber number\"
6=6 \"abbreviated number\"

:atm_np
0=0 \"unknown\"
1=1 \"ISDN numbering plan (E.164)\"
2=2 \"ATM endsystem address\"
9=9 \"private numbering plan\"

:atm_sat
0=0 \"NSAP (Rec. X.213 ISO/IEC 8348)\"
1=1 \"ATM endsystem address\"
2=2 \"user-specified\"

:atm_prs
0=0 \"presentation allowed\"
1=1 \"presentation restricted\"
2=2 \"number not available\"

:atm_scrn
0=0 \"user-provided, not screened\"
1=1 \"user-provided, verified and passed\"
2=2 \"user-provided, verified and failed\"
3=3 \"network provided\"

:atm_vpa
0=0 \"VP-associated signalling\"
1=1 \"explicit indication of VPCI\"

:atm_poe
0=0 \"exclusive VPCI; exclusive VCI\"
1=1 \"exclusive VPCI; any VCI\"
2=2 \"exclusive VPCI; no VCI (used for VPCs)\"

:atm_td
0x82=0x82 \"Forward peak cell rate (CLP=0)\"
0x83=0x83 \"Backward peak cell rate (CLP=0)\"
0x84=0x84 \"Forward peak cell rate (CLP=0+1)\"
0x85=0x85 \"Backward peak cell rate (CLP=0+1)\"
0x88=0x88 \"Forward sustained cell rate (CLP=0)\"
0x89=0x89 \"Backward sustained cell rate (CLP=0)\"
0x90=0x90 \"Forward sustained cell rate (CLP=0+1)\"
0x91=0x91 \"Backward sustained cell rate (CLP=0+1)\"
0x92=0x92 \"Forward ABR min. cell rate (CLP=0+1)\"
0x93=0x93 \"Backward ABR min. cell rate (CLP=0+1)\"
0xa0=0xa0 \"Forward maximum burst size (CLP=0)\"
0xa1=0xa1 \"Backward maximum burst size (CLP=0)\"
0xb0=0xb0 \"Forward maximum burst size (CLP=0+1)\"
0xb1=0xb1 \"Backward maximum burst size (CLP=0+1)\"
0xbe=0xbe \"Best effort indicator\"
0xbf=0xbf \"Traffic management options\"

:atm_fd
0=0 \"No Frame discard allowed\"
1=1 \"Frame discard allowed\"

:atm_tag
0=0 \"Tagging not requested\"
1=1 \"Tagging requested\"

:atm_bc
1=1 \"BCOB-A\"
3=3 \"BCOB-C\"
16=16 \"BCOB-X\"
24=24 \"Transparent VP service\"

:atm_tc
0x05=0x05 \"CBR\"
0x07=0x07 \"CBR with CLR commitment on CLP=0+1\"
0x09=0x09 \"Real time VBR\"
0x13=0x13 \"Real time VBR w/ CLR comm. on CLP=0+1\"
0x0a=0x0a \"Non-real time VBR\"
0x0b=0x0b \"Non-real time VBR w/ CLR com. CLP=0+1\"
0x0c=0x0c \"ABR\"
0x00=0x00 \"Non-real time VBR (reception only)\"
0x01=0x01 \"Real time VBR (reception only)\"
0x02=0x02 \"Non-real time VBR (reception only)\"
0x04=0x04 \"CBR (reception only)\"
0x06=0x06 \"CBR (reception only)\"
0x08=0x08 \"Non-real time VBR (reception only)\"
0x20=0x20 \"Reserved for backward compatibility\"
0x21=0x21 \"Reserved for backward compatibility\"
0x22=0x22 \"Reserved for backward compatibility\"
0x24=0x24 \"Reserved for backward compatibility\"
0x25=0x25 \"Reserved for backward compatibility\"
0x26=0x26 \"Reserved for backward compatibility\"
0x28=0x28 \"Reserved for backward compatibility\"
0x29=0x29 \"Reserved for backward compatibility\"
0x2a=0x2a \"Reserved for backward compatibility\"
0x40=0x40 \"Reserved for backward compatibility\"
0x41=0x41 \"Reserved for backward compatibility\"
0x42=0x42 \"Reserved for backward compatibility\"
0x44=0x44 \"Reserved for backward compatibility\"
0x45=0x45 \"Reserved for backward compatibility\"
0x46=0x46 \"Reserved for backward compatibility\"
0x48=0x48 \"Reserved for backward compatibility\"
0x49=0x49 \"Reserved for backward compatibility\"
0x4a=0x4a \"Reserved for backward compatibility\"
0x60=0x60 \"Reserved for backward compatibility\"
0x61=0x61 \"Reserved for backward compatibility\"
0x62=0x62 \"Reserved for backward compatibility\"
0x64=0x64 \"Reserved for backward compatibility\"
0x65=0x65 \"Reserved for backward compatibility\"
0x66=0x66 \"Reserved for backward compatibility\"
0x68=0x68 \"Reserved for backward compatibility\"
0x69=0x69 \"Reserved for backward compatibility\"
0x6a=0x6a \"Reserved for backward compatibility\"

:atm_stc
0=0 \"not susceptible to clipping\"
1=1 \"susceptible to clipping\"

:atm_upcc
0=0 \"point-to-point\"
1=1 \"point-to-multipoint\"

:atm_flag
0=0 \"instruction field not significant\"
1=1 \"follow explicit instructions\"

:atm_aalp
0x8c=0x8c \"Forward maximum CPCS-SDU size\"
0x81=0x81 \"Backward maximum CPCS-SDU size\"
0x83=0x83 \"AAL mode (UNI 3.0 only)\"
0x84=0x84 \"SSCS type\"

:atm_tdl
0x01=0x01 \"Cumulative transit delay value\"
0x03=0x03 \"Maximum end-to-end transit delay value\"
0x0a=0x0a \"Network generated indicator\"

:atm_tni
0x00=0x00 \"User-specified\"
0x02=0x02 \"National network identification\"
0x04=0x04 \"International network identification\"

:atm_nip
0x00=0x00 \"Unknown\"
0x01=0x01 \"Carrier identification code\"
0x03=0x03 \"Data network id. code (X.121)\"

:atm_shi
0x00=0x00 \"No user specified requirement\"
0x01=0x01 \"Aggr. shaping of user & OAM not all.\"

:atm_oci
0x00=0x00 \"Use of e2e OAM F5 flow is optional\"
0x01=0x01 \"Use of e2e OAM F5 flow is mandatory\"

:atm_unfm
0x00=0x00 \"No user-orig. fault mg. indications\"
0x01=0x01 \"Use of u-o fm. ind. w/ rate 1 cps\"

:atm_ofi
0x00=0x00 \"0% of cell rate (CLP=0+1) in ATM TD\"
0x01=0x01 \"0.1% of cell rate (CLP=0+1) in ATM TD\"
0x04=0x04 \"1% of cell rate (CLP=0+1) in ATM TD\"

:atm_irs
0x01=0x01 \"DSM-CC ISO/IEC 13818-6\"
0x02=0x02 \"Recommendation H.245\"

:atm_it
0x01=0x01 \"Session\"
0x02=0x02 \"Resource\"

:atm_lit
0x00=0x00 \"Root assigned\"

:atm_lsi
0x00=0x00 \"Network Join Without Root Notif.\"

:atm_tcs
0x00=0x00 \"Organizational\"

:atm_css
0x00=0x00 \"Reserved\"
0x01=0x01 \"Local network\"
0x02=0x02 \"Local network plus one\"
0x03=0x03 \"Local network plus two\"
0x04=0x04 \"Site minus one\"
0x05=0x05 \"Intra-site\"
0x06=0x06 \"Site plus one\"
0x07=0x07 \"Organization minus one\"
0x08=0x08 \"Intra-organization\"
0x09=0x09 \"Organization plus one\"
0x0a=0x0a \"Community minus one\"
0x0b=0x0b \"Intra-community\"
0x0c=0x0c \"Community plus one\"
0x0d=0x0d \"Regional\"
0x0e=0x0e \"Inter-regional\"
0x0f=0x0f \"Global\"

:atm_eqo
0x00=0x00 \"Originating user\"
0x01=0x01 \"Intermediate network\"

:atm_eqp
0x94=0x94 \"Acceptable fwd peak-to-peak CDV\"
0x95=0x95 \"Acceptable bwd peak-to-peak CDV\"
0x96=0x96 \"Cumulative fwd peak-to-peak CDV\"
0x97=0x97 \"Cumulative bwd peak-to-peak CDV\"
0xa2=0xa2 \"Acceptable fwd cell loss ratio\"
0xa3=0xa3 \"Acceptable bwd cell loss ratio\"

:atm_aap
0xc2=0xc2 \"Forward additional parameters record\"
0xc3=0xc3 \"Backward additional parameters record\"

:atm_asp
0xc2=0xc2 \"Forward ABR initial cell rate, CLP01\"
0xc3=0xc3 \"Backward ABR initial cell rate, CLP01\"
0xc4=0xc4 \"Fwd ABR transient buffer exposure\"
0xc5=0xc5 \"Bwd ABR transient buffer exposure\"
0xc6=0xc6 \"Cumulative RM fixed round trip time\"
0xc8=0xc8 \"Forward rate increase factor\"
0xc9=0xc9 \"Backward rate increase factor\"
0xca=0xca \"Forward rate decrease factor\"
0xcb=0xcb \"Backward rate decrease factor\"

:atm_tor
0x01=0x01 \"Modification confirmation\"

:atm_l2
0=0 \"L2 not specified\"
0x01=0x01 \"Basic mode ISO 1745\"
0x02=0x02 \"ITU-T Q.291 (Rec. I.441)\"
0x06=0x06 \"ITU-T X.25, link layer\"
0x07=0x07 \"ITU-T X.25, multilink\"
0x08=0x08 \"Extended LAPB, half-duplex (Rec. T.71)\"
0x09=0x09 \"HDLC ARM (ISO/IEC 4335)\"
0x0a=0x0a \"HDLC NRM (ISO/IEC 4335)\"
0x0b=0x0b \"HDLC ABM (ISO/IEC 4335)\"
0x0c=0x0c \"LAN LLC (ISO/IEC 8802/2)\"
0x0d=0x0d \"ITU-T X.75, SLP\"
0x0e=0x0e \"ITU-T Q.922\"
0x10=0x10 \"user-specified\"
0x11=0x11 \"ISO 7776 DTE-DTE\"

:atm_l3
0=0 \"L3 not specified\"
0x06=0x06 \"ITU-T X.25, packet layer\"
0x07=0x07 \"ISO/IEC 8208\"
0x08=0x08 \"ITU-T X.223 | ISO/IEC 8878\"
0x09=0x09 \"ITU-T X.233 | ISO/IEC 8473\"
0x0a=0x0a \"ITU-T T.70 minimum network layer\"
0x0b=0x0b \"ISO/IEC TR 9577\"
0x0c=0x0c \"ITU-T Recommendation H.310\"
0x0d=0x0d \"ITU-T Recommendation H.321\"
0x10=0x10 \"user-specified\"

:atm_hl
0=0 \"HL not specified\"
0x01=0x01 \"ISO\"
0x02=0x02 \"user-specific\"
0x03=0x03 \"high layer profile - UNI 3.0 only\"
0x04=0x04 \"vendor-specific application identifier\"

:atm_imd
0=0 \"mode not specified\"
1=1 \"normal mode of operation\"
2=2 \"extended mode of operation\"

:atm_tt
0=0 \"terminal type not specified\"
1=1 \"receive only\"
2=2 \"send only\"
3=3 \"receive and send\"

:atm_mc
0=0 \"no multiplexing\"
1=1 \"transport stream (TS)\"
2=2 \"transport stream with forward error corr.\"
3=3 \"program stream (PS)\"
4=4 \"program stream with forward error corr.\"
5=5 \"ITU-T Rec. H.221\"

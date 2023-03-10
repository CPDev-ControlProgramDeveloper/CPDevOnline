#define VMACH_VERSION	0x2900

// Grupy funkcji

#define FG_ADD	0x01
#define FG_SUB	0x02
#define FG_MUL	0x03
#define FG_DIV_MOD	0x04
#define FG_NEG_NOT	0x05
#define FG_EXPT_ABS_DOW	0x06
#define FG_SYSMEM   0x07
#define FG_AND	0x08
#define FG_OR	0x09
#define FG_XOR	0x0A
#define FG_SHI_ROT	0x0B
#define FG_SEL	0x0C
#define FG_LIMIT	0x0D
#define FG_MAX	0x0E
#define FG_MIN	0x0F
#define FG_GT	0x10
#define FG_GE	0x11
#define FG_EQ	0x12
#define FG_LE	0x13
#define FG_LT	0x14
#define FG_NE	0x15
#define FG_MUX	0x16
#define FG_STRING	0x18
#define FG_CONV	0x19
#define FG_SYSCTRL	0x1C
#define FG_CUSTOMSPACE 0x1D
#define FG_POINTERS	0x1E
#define FG_HALT		0xFF

// Funkcje maszyny wirtualnej

#define VMF_ADD_SINT	0x01F1
#define VMF_ADD_INT		0x01F2
#define VMF_ADD_DINT	0x01F3
#define VMF_ADD_LINT	0x01F4
#define VMF_ADD_BYTE	0x01F5
#define VMF_ADD_WORD	0x01F6
#define VMF_ADD_DWORD	0x01F7
#define VMF_ADD_LWORD	0x01F8
#define VMF_ADD_REAL	0x01F9
#define VMF_ADD_LREAL	0x01FA
#define VMF_ADD_TIME    0x01FB
#define VMF_ADD_STRING	0x01FF
#define VMF_ADD_WSTRING	0x01FF
#define VMF_CONCAT_STRING	0x01FF
#define VMF_CONCAT_WSTRING	0x01FF

#define VMF_SUB_SINT_SINT	0x0201
#define VMF_SUB_INT_INT	0x0202
#define VMF_SUB_DINT_DINT	0x0203
#define VMF_SUB_LINT_LINT	0x0204
#define VMF_SUB_BYTE_BYTE	0x0205
#define VMF_SUB_WORD_WORD	0x0206
#define VMF_SUB_DWORD_DWORD	0x0207
#define VMF_SUB_LWORD_LWORD	0x0208
#define VMF_SUB_REAL_REAL	0x0209
#define VMF_SUB_LREAL_LREAL	0x020A
#define VMF_SUB_TIME_TIME	0x020B
#define VMF_MUL_SINT	0x03F1
#define VMF_MUL_INT	0x03F2
#define VMF_MUL_DINT	0x03F3
#define VMF_MUL_LINT	0x03F4
#define VMF_MUL_BYTE	0x03F5
#define VMF_MUL_WORD	0x03F6
#define VMF_MUL_DWORD	0x03F7
#define VMF_MUL_LWORD	0x03F8
#define VMF_MUL_REAL	0x03F9
#define VMF_MUL_LREAL	0x03FA
#define VMF_DIV_SINT_SINT	0x0401
#define VMF_DIV_INT_INT	0x0402
#define VMF_DIV_DINT_DINT	0x0403
#define VMF_DIV_LINT_LINT	0x0404
#define VMF_DIV_BYTE_BYTE	0x0405
#define VMF_DIV_WORD_WORD	0x0406
#define VMF_DIV_DWORD_DWORD	0x0407
#define VMF_DIV_LWORD_LWORD	0x0408
#define VMF_DIV_REAL_REAL	0x0409
#define VMF_DIV_LREAL_LREAL	0x040A
#define VMF_MOD_SINT_SINT	0x0411
#define VMF_MOD_INT_INT	0x0412
#define VMF_MOD_DINT_DINT	0x0413
#define VMF_MOD_LINT_LINT	0x0414
#define VMF_MOD_BYTE_BYTE	0x0415
#define VMF_MOD_WORD_WORD	0x0416
#define VMF_MOD_DWORD_DWORD	0x0417
#define VMF_MOD_LWORD_LWORD	0x0418
#define VMF_NEG_SINT	0x0501
#define VMF_NEG_INT	0x0502
#define VMF_NEG_DINT	0x0503
#define VMF_NEG_LINT	0x0504
#define VMF_NEG_REAL	0x0507
#define VMF_NEG_LREAL	0x0509
#define VMF_NOT_BOOL	0x0510
#define VMF_NOT_BYTE	0x0511
#define VMF_NOT_WORD	0x0512
#define VMF_NOT_DWORD	0x0513
#define VMF_NOT_LWORD	0x0514
#define VMF_EXPT_SINT_SINT	0x0601
#define VMF_EXPT_INT_SINT	0x0602
#define VMF_EXPT_DINT_SINT	0x0603
#define VMF_EXPT_REAL_SINT	0x0604
#define VMF_EXPT_REAL_INT	0x0605
#define VMF_EXPT_REAL_DINT	0x0606
#define VMF_EXPT_REAL_REAL	0x0607
#define VMF_EXPT_LREAL_LREAL	0x0608
#define VMF_ABS_SINT	0x0611
#define VMF_ABS_INT	0x0612
#define VMF_ABS_DINT	0x0613
#define VMF_ABS_LINT	0x0614
#define VMF_ABS_BYTE	0x0615
#define VMF_ABS_WORD	0x0616
#define VMF_ABS_DWORD	0x0617
#define VMF_ABS_LWORD	0x0618
#define VMF_ABS_REAL	0x0619
#define VMF_ABS_LREAL	0x061A

#define VMF_SQRT_REAL	0x0620
#define VMF_SQRT_LREAL	0x0621
#define VMF_LN_REAL	0x0622
#define VMF_LN_LREAL	0x0623
#define VMF_LOG_REAL	0x0624
#define VMF_LOG_LREAL	0x0625
#define VMF_EXP_REAL	0x0626
#define VMF_EXP_LREAL	0x0627
#define VMF_SIN_REAL	0x0628
#define VMF_SIN_LREAL	0x0629
#define VMF_COS_REAL	0x062A
#define VMF_COS_LREAL	0x062B
#define VMF_TAN_REAL	0x062C
#define VMF_TAN_LREAL	0x062D
#define VMF_ASIN_REAL	0x062E
#define VMF_ASIN_LREAL	0x062F
#define VMF_ACOS_REAL	0x0630
#define VMF_ACOS_LREAL	0x0631
#define VMF_ATAN_REAL	0x0632
#define VMF_ATAN_LREAL	0x0633
#define VMF_TRUNC_REAL	0x0634
#define VMF_TRUNC_LREAL	0x0635
#define VMF_ROUND_REAL	0x0636
#define VMF_ROUND_LREAL	0x0637

#define VMF_GET_DAYOFWEEK_DATE	0x0640
#define VMF_GET_DAYOFWEEK_DATETIME	0x0641

#define VMF_AND_BOOL	0x08F0
#define VMF_AND_BYTE	0x08F1
#define VMF_AND_WORD	0x08F2
#define VMF_AND_DWORD	0x08F3
#define VMF_AND_LWORD	0x08F4
#define VMF_OR_BOOL	0x09F0
#define VMF_OR_BYTE	0x09F1
#define VMF_OR_WORD	0x09F2
#define VMF_OR_DWORD	0x09F3
#define VMF_OR_LWORD	0x09F4
#define VMF_XOR_BOOL	0x0AF0
#define VMF_XOR_BYTE	0x0AF1
#define VMF_XOR_WORD	0x0AF2
#define VMF_XOR_DWORD	0x0AF4
#define VMF_XOR_LWORD	0x0AF5
#define VMF_SHL_BYTE_INT	0x0B01
#define VMF_SHL_WORD_INT	0x0B02
#define VMF_SHL_DWORD_INT	0x0B03
#define VMF_SHL_LWORD_INT	0x0B04
#define VMF_SHR_BYTE_INT	0x0B11
#define VMF_SHR_WORD_INT	0x0B12
#define VMF_SHR_DWORD_INT	0x0B13
#define VMF_SHR_LWORD_INT	0x0B14
#define VMF_ROL_BYTE_INT	0x0B21
#define VMF_ROL_WORD_INT	0x0B22
#define VMF_ROL_DWORD_INT	0x0B23
#define VMF_ROL_LWORD_INT	0x0B24
#define VMF_ROR_BYTE_INT	0x0B31
#define VMF_ROR_WORD_INT	0x0B32
#define VMF_ROR_DWORD_INT	0x0B33
#define VMF_ROR_LWORD_INT	0x0B34
#define VMF_SEL_BOOL_BOOL_BOOL	0x0C00
#define VMF_SEL_BOOL_SINT_SINT	0x0C01
#define VMF_SEL_BOOL_INT_INT	0x0C02
#define VMF_SEL_BOOL_DINT_DINT	0x0C03
#define VMF_SEL_BOOL_LINT_LINT	0x0C04
#define VMF_SEL_BOOL_BYTE_BYTE	0x0C05
#define VMF_SEL_BOOL_WORD_WORD	0x0C06
#define VMF_SEL_BOOL_DWORD_DWORD	0x0C07
#define VMF_SEL_BOOL_LWORD_LWORD	0x0C08
#define VMF_SEL_BOOL_REAL_REAL	0x0C09
#define VMF_SEL_BOOL_LREAL_LREAL	0x0C0A
#define VMF_SEL_BOOL_TIME_TIME	0x0C0B
#define VMF_SEL_BOOL_DATE_DATE	0x0C0C
#define VMF_SEL_BOOL_TOD_TOD	0x0C0D
#define VMF_SEL_BOOL_DATE_AND_TIME_DATE_AND_TIME	0x0C0E
#define VMF_SEL_BOOL_STRING_STRING	0x0C0F
#define VMF_SEL_BOOL_WSTRING_WSTRING	0x0C0F

#define VMF_LIMIT_BOOL_BOOL_BOOL	0x0D00
#define VMF_LIMIT_SINT_SINT_SINT	0x0D01
#define VMF_LIMIT_INT_INT_INT	0x0D02
#define VMF_LIMIT_DINT_DINT_DINT	0x0D03
#define VMF_LIMIT_LINT_LINT_LINT	0x0D04
#define VMF_LIMIT_BYTE_BYTE_BYTE	0x0D05
#define VMF_LIMIT_WORD_WORD_WORD	0x0D06
#define VMF_LIMIT_DWORD_DWORD_DWORD	0x0D07
#define VMF_LIMIT_LWORD_LWORD_LWORD	0x0D08
#define VMF_LIMIT_REAL_REAL_REAL	0x0D09
#define VMF_LIMIT_LREAL_LREAL_LREAL	0x0D0A
#define VMF_LIMIT_TIME_TIME_TIME	0x0D0B
#define VMF_LIMIT_DATE_DATE_DATE	0x0D0C
#define VMF_LIMIT_TIME_OF_DAY_TIME_OF_DAY_TIME_OF_DAY	0x0D0D
#define VMF_LIMIT_DATE_AND_TIME_DATE_AND_TIME_DATE_AND_TIME	0x0D0E
#define VMF_LIMIT_STRING_STRING_STRING	0x0D0F
#define VMF_LIMIT_WSTRING_WSTRING_WSTRING	0x0D0F

#define VMF_MAX_BOOL_BOOL	0x0E00
#define VMF_MAX_SINT_SINT	0x0E01
#define VMF_MAX_INT_INT	0x0E02
#define VMF_MAX_DINT_DINT	0x0E03
#define VMF_MAX_LINT_LINT	0x0E04
#define VMF_MAX_BYTE_BYTE	0x0E05
#define VMF_MAX_WORD_WORD	0x0E06
#define VMF_MAX_DWORD_DWORD	0x0E07
#define VMF_MAX_LWORD_LWORD	0x0E08
#define VMF_MAX_REAL_REAL	0x0E09
#define VMF_MAX_LREAL_LREAL	0x0E0A
#define VMF_MAX_TIME_TIME	0x0E0B
#define VMF_MAX_DATE_DATE	0x0E0C
#define VMF_MAX_TIME_OF_DAY_TIME_OF_DAY	0x0E0D
#define VMF_MAX_DATE_AND_TIME_DATE_AND_TIME	0x0E0E
#define VMF_MAX_STRING_STRING	0x0E0F
#define VMF_MAX_WSTRING_WSTRING	0x0E0F

#define VMF_MIN_BOOL_BOOL	0x0F00
#define VMF_MIN_SINT_SINT	0x0F01
#define VMF_MIN_INT_INT	0x0F02
#define VMF_MIN_DINT_DINT	0x0F03
#define VMF_MIN_LINT_LINT	0x0F04
#define VMF_MIN_BYTE_BYTE	0x0F05
#define VMF_MIN_WORD_WORD	0x0F06
#define VMF_MIN_DWORD_DWORD	0x0F07
#define VMF_MIN_LWORD_LWORD	0x0F08
#define VMF_MIN_REAL_REAL	0x0F09
#define VMF_MIN_LREAL_LREAL	0x0F0A
#define VMF_MIN_TIME_TIME	0x0F0B
#define VMF_MIN_DATE_DATE	0x0F0C
#define VMF_MIN_TIME_OF_DAY_TIME_OF_DAY	0x0F0D
#define VMF_MIN_DATE_AND_TIME_DATE_AND_TIME	0x0F0E
#define VMF_MIN_STRING_STRING	0x0F0F
#define VMF_MIN_WSTRING_WSTRING	0x0F0F

#define VMF_GT_BOOL_BOOL	0x1000
#define VMF_GT_SINT_SINT	0x1001
#define VMF_GT_INT_INT	0x1002
#define VMF_GT_DINT_DINT	0x1003
#define VMF_GT_LINT_LINT	0x1004
#define VMF_GT_BYTE_BYTE	0x1005
#define VMF_GT_WORD_WORD	0x1006
#define VMF_GT_DWORD_DWORD	0x1007
#define VMF_GT_LWORD_LWORD	0x1008
#define VMF_GT_REAL_REAL	0x1009
#define VMF_GT_LREAL_LREAL	0x100A
#define VMF_GT_TIME_TIME	0x100B
#define VMF_GT_DATE_DATE	0x100C
#define VMF_GT_TIME_OF_DAY_TIME_OF_DAY	0x100D
#define VMF_GT_DATE_AND_TIME_DATE_AND_TIME	0x100E
#define VMF_GT_STRING_STRING	0x100F
#define VMF_GT_WSTRING_WSTRING	0x100F

#define VMF_GE_BOOL_BOOL	0x1100
#define VMF_GE_SINT_SINT	0x1101
#define VMF_GE_INT_INT	0x1102
#define VMF_GE_DINT_DINT	0x1103
#define VMF_GE_LINT_LINT	0x1104
#define VMF_GE_BYTE_BYTE	0x1105
#define VMF_GE_WORD_WORD	0x1106
#define VMF_GE_DWORD_DWORD	0x1107
#define VMF_GE_LWORD_LWORD	0x1108
#define VMF_GE_REAL_REAL	0x1109
#define VMF_GE_LREAL_LREAL	0x110A
#define VMF_GE_TIME_TIME	0x110B
#define VMF_GE_DATE_DATE	0x110C
#define VMF_GE_TIME_OF_DAY_TIME_OF_DAY	0x110D
#define VMF_GE_DATE_AND_TIME_DATE_AND_TIME	0x110E
#define VMF_GE_STRING_STRING	0x110F
#define VMF_GE_WSTRING_WSTRING	0x110F

#define VMF_EQ_BOOL_BOOL	0x1200
#define VMF_EQ_SINT_SINT	0x1201
#define VMF_EQ_INT_INT	0x1202
#define VMF_EQ_DINT_DINT	0x1203
#define VMF_EQ_LINT_LINT	0x1204
#define VMF_EQ_BYTE_BYTE	0x1205
#define VMF_EQ_WORD_WORD	0x1206
#define VMF_EQ_DWORD_DWORD	0x1207
#define VMF_EQ_LWORD_LWORD	0x1208
#define VMF_EQ_REAL_REAL	0x1209
#define VMF_EQ_LREAL_LREAL	0x120A
#define VMF_EQ_TIME_TIME	0x120B
#define VMF_EQ_DATE_DATE	0x120C
#define VMF_EQ_TIME_OF_DAY_TIME_OF_DAY	0x120D
#define VMF_EQ_DATE_AND_TIME_DATE_AND_TIME	0x120E
#define VMF_EQ_STRING_STRING	0x120F
#define VMF_EQ_WSTRING_WSTRING	0x120F

#define VMF_LE_BOOL_BOOL	0x1300
#define VMF_LE_SINT_SINT	0x1301
#define VMF_LE_INT_INT	0x1302
#define VMF_LE_DINT_DINT	0x1303
#define VMF_LE_LINT_LINT	0x1304
#define VMF_LE_BYTE_BYTE	0x1305
#define VMF_LE_WORD_WORD	0x1306
#define VMF_LE_DWORD_DWORD	0x1307
#define VMF_LE_LWORD_LWORD	0x1308
#define VMF_LE_REAL_REAL	0x1309
#define VMF_LE_LREAL_LREAL	0x130A
#define VMF_LE_TIME_TIME	0x130B
#define VMF_LE_DATE_DATE	0x130C
#define VMF_LE_TIME_OF_DAY_TIME_OF_DAY	0x130D
#define VMF_LE_DATE_AND_TIME_DATE_AND_TIME	0x130E
#define VMF_LE_STRING_STRING	0x130F
#define VMF_LE_WSTRING_WSTRING	0x130F

#define VMF_LT_BOOL_BOOL	0x1400
#define VMF_LT_SINT_SINT	0x1401
#define VMF_LT_INT_INT	0x1402
#define VMF_LT_DINT_DINT	0x1403
#define VMF_LT_LINT_LINT	0x1404
#define VMF_LT_BYTE_BYTE	0x1405
#define VMF_LT_WORD_WORD	0x1406
#define VMF_LT_DWORD_DWORD	0x1407
#define VMF_LT_LWORD_LWORD	0x1408
#define VMF_LT_REAL_REAL	0x1409
#define VMF_LT_LREAL_LREAL	0x140A
#define VMF_LT_TIME_TIME	0x140B
#define VMF_LT_DATE_DATE	0x140C
#define VMF_LT_TIME_OF_DAY_TIME_OF_DAY	0x140D
#define VMF_LT_DATE_AND_TIME_DATE_AND_TIME	0x140E
#define VMF_LT_STRING_STRING	0x140F
#define VMF_LT_WSTRING_WSTRING	0x140F

#define VMF_NE_BOOL_BOOL	0x1500
#define VMF_NE_SINT_SINT	0x1501
#define VMF_NE_INT_INT	0x1502
#define VMF_NE_DINT_DINT	0x1503
#define VMF_NE_LINT_LINT	0x1504
#define VMF_NE_BYTE_BYTE	0x1505
#define VMF_NE_WORD_WORD	0x1506
#define VMF_NE_DWORD_DWORD	0x1507
#define VMF_NE_LWORD_LWORD	0x1508
#define VMF_NE_REAL_REAL	0x1509
#define VMF_NE_LREAL_LREAL	0x150A
#define VMF_NE_TIME_TIME	0x150B
#define VMF_NE_DATE_DATE	0x150C
#define VMF_NE_TIME_OF_DAY_TIME_OF_DAY	0x150D
#define VMF_NE_DATE_AND_TIME_DATE_AND_TIME	0x150E
#define VMF_NE_STRING_STRING	0x150F
#define VMF_NE_WSTRING_WSTRING	0x150F

#define VMF_MUX_INT_BOOL	0x16F0
#define VMF_MUX_INT_SINT	0x16F1
#define VMF_MUX_INT_INT		0x16F2
#define VMF_MUX_INT_DINT	0x16F3
#define VMF_MUX_INT_LINT	0x16F4
#define VMF_MUX_INT_BYTE	0x16F5
#define VMF_MUX_INT_WORD	0x16F6
#define VMF_MUX_INT_DWORD	0x16F7
#define VMF_MUX_INT_LWORD	0x16F8
#define VMF_MUX_INT_REAL	0x16F9
#define VMF_MUX_INT_LREAL	0x16FA
#define VMF_MUX_INT_TIME	0x16FB
#define VMF_MUX_INT_DATE	0x16FC
#define VMF_MUX_INT_TIME_OF_DAY	0x16FD
#define VMF_MUX_INT_DATE_AND_TIME	0x16FE
#define VMF_MUX_INT_STRING	0x16FF
#define VMF_MUX_INT_WSTRING	0x16FF

#define VMF_STRASGN			0x1800
#define VMF_LEN_STRING_INT	0x1801
#define VMF_LEN_WSTRING_INT	0x1801

#define VMF_LEFT_STRING_INT	0x1802
#define VMF_LEFT_WSTRING_INT	0x1802

#define VMF_RIGHT_STRING_INT	0x1803
#define VMF_RIGHT_WSTRING_INT	0x1803

#define VMF_MID_STRING_INT_INT	0x1804
#define VMF_MID_WSTRING_INT_INT	0x1804

#define VMF_INSERT_STRING_STRING_INT	0x1805
#define VMF_INSERT_WSTRING_WSTRING_INT	0x1805

#define VMF_DELETE_STRING_INT_INT	0x1806
#define VMF_DELETE_WSTRING_INT_INT	0x1806

#define VMF_REPLACE_STRING_STRING_INT_INT	0x1807
#define VMF_REPLACE_WSTRING_WSTRING_INT_INT	0x1807

#define VMF_FIND_INT_STRING_STRING	0x1808
#define VMF_FIND_INT_WSTRING_WSTRING	0x1808

#define VMF_STRING_TO_REAL		0x1809
#define VMF_WSTRING_TO_REAL		0x1809

#define VMF_STRING_TO_INT		0x180A
#define VMF_WSTRING_TO_INT		0x180A

#define VMF_INT_TO_STRING		0x180B
#define VMF_INT_TO_WSTRING		0x180B

#define VMF_REAL_TO_STRING		0x180C
#define VMF_REAL_TO_WSTRING		0x180C

#define VMF_STRING_TO_LREAL		0x180D
#define VMF_WSTRING_TO_LREAL		0x180D

#define VMF_STRING_TO_DINT		0x180E
#define VMF_WSTRING_TO_DINT		0x180E

#define VMF_DINT_TO_STRING		0x180F
#define VMF_DINT_TO_WSTRING		0x180F

#define VMF_LREAL_TO_STRING		0x1810
#define VMF_LREAL_TO_WSTRING		0x1810

#define VMF_STRING_TO_LINT		0x1811
#define VMF_WSTRING_TO_LINT		0x1811

#define VMF_LINT_TO_STRING		0x1812
#define VMF_LINT_TO_WSTRING		0x1812

#define VMF_CHAR_AT_STRING_INT	0x1813

#define VMF_CHAR_SET_STRING_INT_BYTE	0x1814
#define VMF_FINDREPLACE_STRING_STRING_INT_INT_STRING	0x1815
#define VMF_FINDREPLACE_WSTRING_WSTRING_INT_INT_WSTRING	0x1815

#define VMF_FINDEX_INT_STRING_STRING_INT_INT	0x1816
#define VMF_FINDEX_INT_WSTRING_WSTRING_INT_INT	0x1816

#define VMF_WCHAR_AT_WSTRING_INT	0x1817

#define VMF_WCHAR_SET_WSTRING_INT_WORD	0x1818

#define VMF_WSTRING_TO_STRING	0x1819
#define VMF_STRING_TO_WSTRING	0x181A

/*
#define VMF_ADD_TIME_OF_DAY_TIME
#define VMF_ADD_DATE_AND_TIME_TIME
#define VMF_SUB_DATE_DATE
#define VMF_SUB_TIME_OF_DAY_TIME
#define VMF_SUB_TIME_OF_DAY_TIME_OF_DAY
#define VMF_SUB_DATE_AND_TIME_TIME
#define VMF_SUB_DATE_AND_TIME_DATE_AND_TIME
#define VMF_MUL_TIME_INT
#define VMF_MUL_TIME_REAL
#define VMF_DIV_TIME_INT
#define VMF_DIV_TIME_REAL
#define VMF_CONCAT_DATE_TIME_OF_DAY
*/

#define VMF_INT_TO_REAL		0x1900
#define VMF_DINT_TO_REAL	0x1901
#define VMF_TIME_TO_DINT	0x1902
#define VMF_DINT_TO_TIME	0x1903
#define VMF_TIME_TO_REAL	0x1904
#define VMF_REAL_TO_TIME	0x1905
#define VMF_BCD_TO_INT_BYTE		0x1906
#define VMF_BCD_TO_INT_WORD		0x1907
#define VMF_INT_TO_BYTE_BCD		0x1908
#define VMF_INT_TO_WORD_BCD		0x1909
#define VMF_REAL_TO_INT		0x190A
#define VMF_INT_TO_BOOL		0x190B
#define VMF_INT_TO_DINT		0x190C
#define VMF_REAL_TO_LREAL	0x190D
#define VMF_LREAL_TO_REAL	0x190E
#define VMF_LINT_TO_LREAL	0x190F
#define VMF_DWORD_TO_REAL	0x1910
#define VMF_REAL_TO_DWORD	0x1911

#define VMF_JMP	0x1C00
#define VMF_JNZ	0x1C01
#define VMF_JZ	0x1C02
#define VMF_JR	0x1C03
#define VMF_JRN	0x1C04
#define VMF_JRZ	0x1C05

#define VMF_CALF	0x1C10

#define VMF_RETURN	0x1C13

#define VMF_MCD		0x1C15
#define VMF_CALB	0x1C16
#define VMF_CUR_TIME	0x1C17
#define VMF_RETFB	0x1C18

#define VMF_TRML	0x1C1D
#define VMF_CALP	0x1C1E
#define VMF_MEMCP	0x1C1F

#define VMF_READ_RTC	0x1C20
#define VMF_WRITE_RTC	0x1C21

#define VMF_RANDOML	0x1C22

#define VMF_FPAT	0x1C23
#define VMF_AURD	0x1C24
#define VMF_AUWR	0x1C25

#define VMF_AORD	0x1C26
#define VMF_AOWR	0x1C27	

#define VMF_ATRD	0x1C28
#define VMF_ATWR	0x1C29

#define VMF_AFRD	0x1C2A
#define VMF_AFWR	0x1C2B

#define VMF_AQRD	0x1C2C
#define VMF_AQWR	0x1C2D

#define VMF_CEAC	0x1C2E

#define VMF_GET_STATUS_WORD1	0x1C2F
#define VMF_GET_TST_DATETIME	0x1C30

#define VMF_TASK_CYCLE	0x1C31
#define VMF_GET_VMACH_VERSION	0x1C32

#define VMF_MCD2A	0x1C33 // for FPGA
#define VMF_GARD	0x1C34
#define VMF_GAWR	0x1C35
#define VMF_TASKSETUP	0x1C36 // for FPGA

#define VMF_MCD4A	0x1C37
#define VMF_FPAT4A	0x1C38
#define VMF_MEMCP4A	0x1C39

/* Pointer instructions */
#define VMF_DPSTO	0x1E00
#define VMF_DPRDL	0x1E01
#define VMF_DPWRL	0x1E02
#define VMF_CALBR	0x1E03
#define VMF_JNUL	0x1E04
#define VMF_MEMCPP	0x1E05

#define VMF_DPRDL4A	0x1E11
#define VMF_DPWRL4A	0x1E12
#define VMF_HWFBC4A	0x1E13
#define VMF_HWFBI4A 0x1E14

#define VMF_MMV		0x0700

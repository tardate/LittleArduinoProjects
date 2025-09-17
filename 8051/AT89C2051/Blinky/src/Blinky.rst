                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler
                                      3 ; Version 4.5.0 #15242 (Mac OS X ppc)
                                      4 ;--------------------------------------------------------
                                      5 	.module Blinky
                                      6 	
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _DELAY
                                     12 	.globl _main
                                     13 	.globl _TF1
                                     14 	.globl _TR1
                                     15 	.globl _TF0
                                     16 	.globl _TR0
                                     17 	.globl _IE1
                                     18 	.globl _IT1
                                     19 	.globl _IE0
                                     20 	.globl _IT0
                                     21 	.globl _SM0
                                     22 	.globl _SM1
                                     23 	.globl _SM2
                                     24 	.globl _REN
                                     25 	.globl _TB8
                                     26 	.globl _RB8
                                     27 	.globl _TI
                                     28 	.globl _RI
                                     29 	.globl _CY
                                     30 	.globl _AC
                                     31 	.globl _F0
                                     32 	.globl _RS1
                                     33 	.globl _RS0
                                     34 	.globl _OV
                                     35 	.globl _F1
                                     36 	.globl _P
                                     37 	.globl _RD
                                     38 	.globl _WR
                                     39 	.globl _T1
                                     40 	.globl _T0
                                     41 	.globl _INT1
                                     42 	.globl _INT0
                                     43 	.globl _TXD0
                                     44 	.globl _TXD
                                     45 	.globl _RXD0
                                     46 	.globl _RXD
                                     47 	.globl _P3_7
                                     48 	.globl _P3_6
                                     49 	.globl _P3_5
                                     50 	.globl _P3_4
                                     51 	.globl _P3_3
                                     52 	.globl _P3_2
                                     53 	.globl _P3_1
                                     54 	.globl _P3_0
                                     55 	.globl _P1_7
                                     56 	.globl _P1_6
                                     57 	.globl _P1_5
                                     58 	.globl _P1_4
                                     59 	.globl _P1_3
                                     60 	.globl _P1_2
                                     61 	.globl _P1_1
                                     62 	.globl _P1_0
                                     63 	.globl _PS
                                     64 	.globl _PT1
                                     65 	.globl _PX1
                                     66 	.globl _PT0
                                     67 	.globl _PX0
                                     68 	.globl _EA
                                     69 	.globl _ES
                                     70 	.globl _ET1
                                     71 	.globl _EX1
                                     72 	.globl _ET0
                                     73 	.globl _EX0
                                     74 	.globl _BREG_F7
                                     75 	.globl _BREG_F6
                                     76 	.globl _BREG_F5
                                     77 	.globl _BREG_F4
                                     78 	.globl _BREG_F3
                                     79 	.globl _BREG_F2
                                     80 	.globl _BREG_F1
                                     81 	.globl _BREG_F0
                                     82 	.globl _TMOD
                                     83 	.globl _TL1
                                     84 	.globl _TL0
                                     85 	.globl _TH1
                                     86 	.globl _TH0
                                     87 	.globl _TCON
                                     88 	.globl _SP
                                     89 	.globl _SCON
                                     90 	.globl _SBUF0
                                     91 	.globl _SBUF
                                     92 	.globl _PSW
                                     93 	.globl _PCON
                                     94 	.globl _P3
                                     95 	.globl _P1
                                     96 	.globl _IP
                                     97 	.globl _IE
                                     98 	.globl _DP0L
                                     99 	.globl _DPL
                                    100 	.globl _DP0H
                                    101 	.globl _DPH
                                    102 	.globl _B
                                    103 	.globl _ACC
                                    104 	.globl _ms_delay
                                    105 ;--------------------------------------------------------
                                    106 ; special function registers
                                    107 ;--------------------------------------------------------
                                    108 	.area RSEG    (ABS,DATA)
      000000                        109 	.org 0x0000
                           0000E0   110 _ACC	=	0x00e0
                           0000F0   111 _B	=	0x00f0
                           000083   112 _DPH	=	0x0083
                           000083   113 _DP0H	=	0x0083
                           000082   114 _DPL	=	0x0082
                           000082   115 _DP0L	=	0x0082
                           0000A8   116 _IE	=	0x00a8
                           0000B8   117 _IP	=	0x00b8
                           000090   118 _P1	=	0x0090
                           0000B0   119 _P3	=	0x00b0
                           000087   120 _PCON	=	0x0087
                           0000D0   121 _PSW	=	0x00d0
                           000099   122 _SBUF	=	0x0099
                           000099   123 _SBUF0	=	0x0099
                           000098   124 _SCON	=	0x0098
                           000081   125 _SP	=	0x0081
                           000088   126 _TCON	=	0x0088
                           00008C   127 _TH0	=	0x008c
                           00008D   128 _TH1	=	0x008d
                           00008A   129 _TL0	=	0x008a
                           00008B   130 _TL1	=	0x008b
                           000089   131 _TMOD	=	0x0089
                                    132 ;--------------------------------------------------------
                                    133 ; special function bits
                                    134 ;--------------------------------------------------------
                                    135 	.area RSEG    (ABS,DATA)
      000000                        136 	.org 0x0000
                           0000F0   137 _BREG_F0	=	0x00f0
                           0000F1   138 _BREG_F1	=	0x00f1
                           0000F2   139 _BREG_F2	=	0x00f2
                           0000F3   140 _BREG_F3	=	0x00f3
                           0000F4   141 _BREG_F4	=	0x00f4
                           0000F5   142 _BREG_F5	=	0x00f5
                           0000F6   143 _BREG_F6	=	0x00f6
                           0000F7   144 _BREG_F7	=	0x00f7
                           0000A8   145 _EX0	=	0x00a8
                           0000A9   146 _ET0	=	0x00a9
                           0000AA   147 _EX1	=	0x00aa
                           0000AB   148 _ET1	=	0x00ab
                           0000AC   149 _ES	=	0x00ac
                           0000AF   150 _EA	=	0x00af
                           0000B8   151 _PX0	=	0x00b8
                           0000B9   152 _PT0	=	0x00b9
                           0000BA   153 _PX1	=	0x00ba
                           0000BB   154 _PT1	=	0x00bb
                           0000BC   155 _PS	=	0x00bc
                           000090   156 _P1_0	=	0x0090
                           000091   157 _P1_1	=	0x0091
                           000092   158 _P1_2	=	0x0092
                           000093   159 _P1_3	=	0x0093
                           000094   160 _P1_4	=	0x0094
                           000095   161 _P1_5	=	0x0095
                           000096   162 _P1_6	=	0x0096
                           000097   163 _P1_7	=	0x0097
                           0000B0   164 _P3_0	=	0x00b0
                           0000B1   165 _P3_1	=	0x00b1
                           0000B2   166 _P3_2	=	0x00b2
                           0000B3   167 _P3_3	=	0x00b3
                           0000B4   168 _P3_4	=	0x00b4
                           0000B5   169 _P3_5	=	0x00b5
                           0000B6   170 _P3_6	=	0x00b6
                           0000B7   171 _P3_7	=	0x00b7
                           0000B0   172 _RXD	=	0x00b0
                           0000B0   173 _RXD0	=	0x00b0
                           0000B1   174 _TXD	=	0x00b1
                           0000B1   175 _TXD0	=	0x00b1
                           0000B2   176 _INT0	=	0x00b2
                           0000B3   177 _INT1	=	0x00b3
                           0000B4   178 _T0	=	0x00b4
                           0000B5   179 _T1	=	0x00b5
                           0000B6   180 _WR	=	0x00b6
                           0000B7   181 _RD	=	0x00b7
                           0000D0   182 _P	=	0x00d0
                           0000D1   183 _F1	=	0x00d1
                           0000D2   184 _OV	=	0x00d2
                           0000D3   185 _RS0	=	0x00d3
                           0000D4   186 _RS1	=	0x00d4
                           0000D5   187 _F0	=	0x00d5
                           0000D6   188 _AC	=	0x00d6
                           0000D7   189 _CY	=	0x00d7
                           000098   190 _RI	=	0x0098
                           000099   191 _TI	=	0x0099
                           00009A   192 _RB8	=	0x009a
                           00009B   193 _TB8	=	0x009b
                           00009C   194 _REN	=	0x009c
                           00009D   195 _SM2	=	0x009d
                           00009E   196 _SM1	=	0x009e
                           00009F   197 _SM0	=	0x009f
                           000088   198 _IT0	=	0x0088
                           000089   199 _IE0	=	0x0089
                           00008A   200 _IT1	=	0x008a
                           00008B   201 _IE1	=	0x008b
                           00008C   202 _TR0	=	0x008c
                           00008D   203 _TF0	=	0x008d
                           00008E   204 _TR1	=	0x008e
                           00008F   205 _TF1	=	0x008f
                                    206 ;--------------------------------------------------------
                                    207 ; overlayable register banks
                                    208 ;--------------------------------------------------------
                                    209 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        210 	.ds 8
                                    211 ;--------------------------------------------------------
                                    212 ; internal ram data
                                    213 ;--------------------------------------------------------
                                    214 	.area DSEG    (DATA)
                                    215 ;--------------------------------------------------------
                                    216 ; overlayable items in internal ram
                                    217 ;--------------------------------------------------------
                                    218 	.area	OSEG    (OVR,DATA)
                                    219 ;--------------------------------------------------------
                                    220 ; Stack segment in internal ram
                                    221 ;--------------------------------------------------------
                                    222 	.area SSEG
      000008                        223 __start__stack:
      000008                        224 	.ds	1
                                    225 
                                    226 ;--------------------------------------------------------
                                    227 ; indirectly addressable internal ram data
                                    228 ;--------------------------------------------------------
                                    229 	.area ISEG    (DATA)
                                    230 ;--------------------------------------------------------
                                    231 ; absolute internal ram data
                                    232 ;--------------------------------------------------------
                                    233 	.area IABS    (ABS,DATA)
                                    234 	.area IABS    (ABS,DATA)
                                    235 ;--------------------------------------------------------
                                    236 ; bit data
                                    237 ;--------------------------------------------------------
                                    238 	.area BSEG    (BIT)
                                    239 ;--------------------------------------------------------
                                    240 ; paged external ram data
                                    241 ;--------------------------------------------------------
                                    242 	.area PSEG    (PAG,XDATA)
                                    243 ;--------------------------------------------------------
                                    244 ; uninitialized external ram data
                                    245 ;--------------------------------------------------------
                                    246 	.area XSEG    (XDATA)
                                    247 ;--------------------------------------------------------
                                    248 ; absolute external ram data
                                    249 ;--------------------------------------------------------
                                    250 	.area XABS    (ABS,XDATA)
                                    251 ;--------------------------------------------------------
                                    252 ; initialized external ram data
                                    253 ;--------------------------------------------------------
                                    254 	.area XISEG   (XDATA)
                                    255 	.area HOME    (CODE)
                                    256 	.area GSINIT0 (CODE)
                                    257 	.area GSINIT1 (CODE)
                                    258 	.area GSINIT2 (CODE)
                                    259 	.area GSINIT3 (CODE)
                                    260 	.area GSINIT4 (CODE)
                                    261 	.area GSINIT5 (CODE)
                                    262 	.area GSINIT  (CODE)
                                    263 	.area GSFINAL (CODE)
                                    264 	.area CSEG    (CODE)
                                    265 ;--------------------------------------------------------
                                    266 ; interrupt vector
                                    267 ;--------------------------------------------------------
                                    268 	.area HOME    (CODE)
      000000                        269 __interrupt_vect:
      000000 02 00 4C         [24]  270 	ljmp	__sdcc_gsinit_startup
                                    271 ; restartable atomic support routines
      000003                        272 	.ds	5
      000008                        273 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  274 	nop
      000009 00               [12]  275 	nop
      00000A                        276 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  277 	movx	a, @r0
      00000B FB               [12]  278 	mov	r3, a
      00000C EA               [12]  279 	mov	a, r2
      00000D F2               [24]  280 	movx	@r0, a
      00000E 80 2C            [24]  281 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  282 	nop
      000011 00               [12]  283 	nop
      000012                        284 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  285 	movx	a, @dptr
      000013 FB               [12]  286 	mov	r3, a
      000014 EA               [12]  287 	mov	a, r2
      000015 F0               [24]  288 	movx	@dptr, a
      000016 80 24            [24]  289 	sjmp	sdcc_atomic_exchange_exit
      000018                        290 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  291 	mov	a, @r0
      000019 B5 02 02         [24]  292 	cjne	a, ar2, .+#5
      00001C EB               [12]  293 	mov	a, r3
      00001D F6               [12]  294 	mov	@r0, a
      00001E 22               [24]  295 	ret
      00001F 00               [12]  296 	nop
      000020                        297 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  298 	movx	a, @r0
      000021 B5 02 02         [24]  299 	cjne	a, ar2, .+#5
      000024 EB               [12]  300 	mov	a, r3
      000025 F2               [24]  301 	movx	@r0, a
      000026 22               [24]  302 	ret
      000027 00               [12]  303 	nop
      000028                        304 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  305 	movx	a, @dptr
      000029 B5 02 02         [24]  306 	cjne	a, ar2, .+#5
      00002C EB               [12]  307 	mov	a, r3
      00002D F0               [24]  308 	movx	@dptr, a
      00002E 22               [24]  309 	ret
      00002F                        310 sdcc_atomic_exchange_rollback_end::
                                    311 
      00002F                        312 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  313 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  314 	mov	r0, dpl
      000034 20 F5 D3         [24]  315 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        316 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  317 	mov	a, r2
      000038 C6               [12]  318 	xch	a, @r0
      000039 F5 82            [12]  319 	mov	dpl, a
      00003B 22               [24]  320 	ret
      00003C                        321 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  322 	mov	dpl, r3
      00003E 22               [24]  323 	ret
      00003F                        324 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  325 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  326 	mov	r0, dpl
      000044 20 F5 D9         [24]  327 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  328 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    329 ;--------------------------------------------------------
                                    330 ; global & static initialisations
                                    331 ;--------------------------------------------------------
                                    332 	.area HOME    (CODE)
                                    333 	.area GSINIT  (CODE)
                                    334 	.area GSFINAL (CODE)
                                    335 	.area GSINIT  (CODE)
                                    336 	.globl __sdcc_gsinit_startup
                                    337 	.globl __sdcc_program_startup
                                    338 	.globl __start__stack
                                    339 	.globl __mcs51_genXINIT
                                    340 	.globl __mcs51_genXRAMCLEAR
                                    341 	.globl __mcs51_genRAMCLEAR
                                    342 	.area GSFINAL (CODE)
      0000A5 02 00 49         [24]  343 	ljmp	__sdcc_program_startup
                                    344 ;--------------------------------------------------------
                                    345 ; Home
                                    346 ;--------------------------------------------------------
                                    347 	.area HOME    (CODE)
                                    348 	.area HOME    (CODE)
      000049                        349 __sdcc_program_startup:
      000049 02 00 A8         [24]  350 	ljmp	_main
                                    351 ;	return from main will return to caller
                                    352 ;--------------------------------------------------------
                                    353 ; code
                                    354 ;--------------------------------------------------------
                                    355 	.area CSEG    (CODE)
                                    356 ;------------------------------------------------------------
                                    357 ;Allocation info for local variables in function 'main'
                                    358 ;------------------------------------------------------------
                                    359 ;	Blinky.c:20: void main(void)
                                    360 ;	-----------------------------------------
                                    361 ;	 function main
                                    362 ;	-----------------------------------------
      0000A8                        363 _main:
                           000007   364 	ar7 = 0x07
                           000006   365 	ar6 = 0x06
                           000005   366 	ar5 = 0x05
                           000004   367 	ar4 = 0x04
                           000003   368 	ar3 = 0x03
                           000002   369 	ar2 = 0x02
                           000001   370 	ar1 = 0x01
                           000000   371 	ar0 = 0x00
                                    372 ;	Blinky.c:22: while(1) {
      0000A8                        373 00102$:
                                    374 ;	Blinky.c:23: P1_0 = 1;
                                    375 ;	assignBit
      0000A8 D2 90            [12]  376 	setb	_P1_0
                                    377 ;	Blinky.c:24: ms_delay(DELAY);
      0000AA 90 03 E8         [24]  378 	mov	dptr,#0x03e8
      0000AD 12 00 BA         [24]  379 	lcall	_ms_delay
                                    380 ;	Blinky.c:25: P1_0 = 0;
                                    381 ;	assignBit
      0000B0 C2 90            [12]  382 	clr	_P1_0
                                    383 ;	Blinky.c:26: ms_delay(DELAY);
      0000B2 90 03 E8         [24]  384 	mov	dptr,#0x03e8
      0000B5 12 00 BA         [24]  385 	lcall	_ms_delay
                                    386 ;	Blinky.c:28: }
      0000B8 80 EE            [24]  387 	sjmp	00102$
                                    388 ;------------------------------------------------------------
                                    389 ;Allocation info for local variables in function 'ms_delay'
                                    390 ;------------------------------------------------------------
                                    391 ;ms            Allocated to registers r6 r7 
                                    392 ;i             Allocated to registers r4 r5 
                                    393 ;j             Allocated to registers r3 
                                    394 ;------------------------------------------------------------
                                    395 ;	Blinky.c:34: void ms_delay(unsigned int ms) {
                                    396 ;	-----------------------------------------
                                    397 ;	 function ms_delay
                                    398 ;	-----------------------------------------
      0000BA                        399 _ms_delay:
      0000BA AE 82            [24]  400 	mov	r6, dpl
      0000BC AF 83            [24]  401 	mov	r7, dph
                                    402 ;	Blinky.c:35: for(unsigned int i=0; i<ms; i++) {
      0000BE 7C 00            [12]  403 	mov	r4,#0x00
      0000C0 7D 00            [12]  404 	mov	r5,#0x00
      0000C2                        405 00107$:
      0000C2 C3               [12]  406 	clr	c
      0000C3 EC               [12]  407 	mov	a,r4
      0000C4 9E               [12]  408 	subb	a,r6
      0000C5 ED               [12]  409 	mov	a,r5
      0000C6 9F               [12]  410 	subb	a,r7
      0000C7 50 11            [24]  411 	jnc	00109$
                                    412 ;	Blinky.c:36: for(unsigned int j=0; j<186; j++);
      0000C9 7B 00            [12]  413 	mov	r3,#0x00
      0000CB                        414 00104$:
      0000CB BB BA 00         [24]  415 	cjne	r3,#0xba,00138$
      0000CE                        416 00138$:
      0000CE 50 03            [24]  417 	jnc	00108$
      0000D0 0B               [12]  418 	inc	r3
      0000D1 80 F8            [24]  419 	sjmp	00104$
      0000D3                        420 00108$:
                                    421 ;	Blinky.c:35: for(unsigned int i=0; i<ms; i++) {
      0000D3 0C               [12]  422 	inc	r4
      0000D4 BC 00 EB         [24]  423 	cjne	r4,#0x00,00107$
      0000D7 0D               [12]  424 	inc	r5
      0000D8 80 E8            [24]  425 	sjmp	00107$
      0000DA                        426 00109$:
                                    427 ;	Blinky.c:38: }
      0000DA 22               [24]  428 	ret
                                    429 	.area CSEG    (CODE)
                                    430 	.area CONST   (CODE)
                                    431 	.area CONST   (CODE)
      0000DF                        432 _DELAY:
      0000DF E8 03                  433 	.byte #0xe8, #0x03	;  1000
                                    434 	.area CSEG    (CODE)
                                    435 	.area XINIT   (CODE)
                                    436 	.area CABS    (ABS,CODE)

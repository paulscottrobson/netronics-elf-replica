case 0x00: /***** idl *****/
    ;;
    break;

case 0x01: /***** ldn r1 *****/
    MA = R1;READ();D = MB;
    break;

case 0x02: /***** ldn r2 *****/
    MA = R2;READ();D = MB;
    break;

case 0x03: /***** ldn r3 *****/
    MA = R3;READ();D = MB;
    break;

case 0x04: /***** ldn r4 *****/
    MA = R4;READ();D = MB;
    break;

case 0x05: /***** ldn r5 *****/
    MA = R5;READ();D = MB;
    break;

case 0x06: /***** ldn r6 *****/
    MA = R6;READ();D = MB;
    break;

case 0x07: /***** ldn r7 *****/
    MA = R7;READ();D = MB;
    break;

case 0x08: /***** ldn r8 *****/
    MA = R8;READ();D = MB;
    break;

case 0x09: /***** ldn r9 *****/
    MA = R9;READ();D = MB;
    break;

case 0x0a: /***** ldn ra *****/
    MA = R10;READ();D = MB;
    break;

case 0x0b: /***** ldn rb *****/
    MA = R11;READ();D = MB;
    break;

case 0x0c: /***** ldn rc *****/
    MA = R12;READ();D = MB;
    break;

case 0x0d: /***** ldn rd *****/
    MA = R13;READ();D = MB;
    break;

case 0x0e: /***** ldn re *****/
    MA = R14;READ();D = MB;
    break;

case 0x0f: /***** ldn rf *****/
    MA = R15;READ();D = MB;
    break;

case 0x10: /***** inc r0 *****/
    R0++;
    break;

case 0x11: /***** inc r1 *****/
    R1++;
    break;

case 0x12: /***** inc r2 *****/
    R2++;
    break;

case 0x13: /***** inc r3 *****/
    R3++;
    break;

case 0x14: /***** inc r4 *****/
    R4++;
    break;

case 0x15: /***** inc r5 *****/
    R5++;
    break;

case 0x16: /***** inc r6 *****/
    R6++;
    break;

case 0x17: /***** inc r7 *****/
    R7++;
    break;

case 0x18: /***** inc r8 *****/
    R8++;
    break;

case 0x19: /***** inc r9 *****/
    R9++;
    break;

case 0x1a: /***** inc ra *****/
    R10++;
    break;

case 0x1b: /***** inc rb *****/
    R11++;
    break;

case 0x1c: /***** inc rc *****/
    R12++;
    break;

case 0x1d: /***** inc rd *****/
    R13++;
    break;

case 0x1e: /***** inc re *****/
    R14++;
    break;

case 0x1f: /***** inc rf *****/
    R15++;
    break;

case 0x20: /***** dec r0 *****/
    R0--;
    break;

case 0x21: /***** dec r1 *****/
    R1--;
    break;

case 0x22: /***** dec r2 *****/
    R2--;
    break;

case 0x23: /***** dec r3 *****/
    R3--;
    break;

case 0x24: /***** dec r4 *****/
    R4--;
    break;

case 0x25: /***** dec r5 *****/
    R5--;
    break;

case 0x26: /***** dec r6 *****/
    R6--;
    break;

case 0x27: /***** dec r7 *****/
    R7--;
    break;

case 0x28: /***** dec r8 *****/
    R8--;
    break;

case 0x29: /***** dec r9 *****/
    R9--;
    break;

case 0x2a: /***** dec ra *****/
    R10--;
    break;

case 0x2b: /***** dec rb *****/
    R11--;
    break;

case 0x2c: /***** dec rc *****/
    R12--;
    break;

case 0x2d: /***** dec rd *****/
    R13--;
    break;

case 0x2e: /***** dec re *****/
    R14--;
    break;

case 0x2f: /***** dec rf *****/
    R15--;
    break;

case 0x30: /***** br $1 *****/
    FETCH();SBRANCH();;
    break;

case 0x31: /***** bq $1 *****/
    FETCH();if (Q != 0) SBRANCH();
    break;

case 0x32: /***** bz $1 *****/
    FETCH();if (D == 0) SBRANCH();
    break;

case 0x33: /***** bdf $1 *****/
    FETCH();if (DF != 0) SBRANCH();
    break;

case 0x34: /***** b1 $1 *****/
    FETCH();if (EFLAG1() != 0) SBRANCH();
    break;

case 0x35: /***** b2 $1 *****/
    FETCH();if (EFLAG2() != 0) SBRANCH();
    break;

case 0x36: /***** b3 $1 *****/
    FETCH();if (EFLAG3() != 0) SBRANCH();
    break;

case 0x37: /***** b4 $1 *****/
    FETCH();if (EFLAG4() != 0) SBRANCH();
    break;

case 0x38: /***** skp *****/
    (*pP)++;
    break;

case 0x39: /***** bnq $1 *****/
    FETCH();if (Q == 0) SBRANCH();
    break;

case 0x3a: /***** bnz $1 *****/
    FETCH();if (D != 0) SBRANCH();
    break;

case 0x3b: /***** bnf $1 *****/
    FETCH();if (DF == 0) SBRANCH();
    break;

case 0x3c: /***** bn1 $1 *****/
    FETCH();if (EFLAG1() == 0) SBRANCH();
    break;

case 0x3d: /***** bn2 $1 *****/
    FETCH();if (EFLAG2() == 0) SBRANCH();
    break;

case 0x3e: /***** bn3 $1 *****/
    FETCH();if (EFLAG3() == 0) SBRANCH();
    break;

case 0x3f: /***** bn4 $1 *****/
    FETCH();if (EFLAG4() == 0) SBRANCH();
    break;

case 0x40: /***** lda r0 *****/
    MA = R0;READ();D = MB;R0++;
    break;

case 0x41: /***** lda r1 *****/
    MA = R1;READ();D = MB;R1++;
    break;

case 0x42: /***** lda r2 *****/
    MA = R2;READ();D = MB;R2++;
    break;

case 0x43: /***** lda r3 *****/
    MA = R3;READ();D = MB;R3++;
    break;

case 0x44: /***** lda r4 *****/
    MA = R4;READ();D = MB;R4++;
    break;

case 0x45: /***** lda r5 *****/
    MA = R5;READ();D = MB;R5++;
    break;

case 0x46: /***** lda r6 *****/
    MA = R6;READ();D = MB;R6++;
    break;

case 0x47: /***** lda r7 *****/
    MA = R7;READ();D = MB;R7++;
    break;

case 0x48: /***** lda r8 *****/
    MA = R8;READ();D = MB;R8++;
    break;

case 0x49: /***** lda r9 *****/
    MA = R9;READ();D = MB;R9++;
    break;

case 0x4a: /***** lda ra *****/
    MA = R10;READ();D = MB;R10++;
    break;

case 0x4b: /***** lda rb *****/
    MA = R11;READ();D = MB;R11++;
    break;

case 0x4c: /***** lda rc *****/
    MA = R12;READ();D = MB;R12++;
    break;

case 0x4d: /***** lda rd *****/
    MA = R13;READ();D = MB;R13++;
    break;

case 0x4e: /***** lda re *****/
    MA = R14;READ();D = MB;R14++;
    break;

case 0x4f: /***** lda rf *****/
    MA = R15;READ();D = MB;R15++;
    break;

case 0x50: /***** str r0 *****/
    MA = R0;MB = D;WRITE();
    break;

case 0x51: /***** str r1 *****/
    MA = R1;MB = D;WRITE();
    break;

case 0x52: /***** str r2 *****/
    MA = R2;MB = D;WRITE();
    break;

case 0x53: /***** str r3 *****/
    MA = R3;MB = D;WRITE();
    break;

case 0x54: /***** str r4 *****/
    MA = R4;MB = D;WRITE();
    break;

case 0x55: /***** str r5 *****/
    MA = R5;MB = D;WRITE();
    break;

case 0x56: /***** str r6 *****/
    MA = R6;MB = D;WRITE();
    break;

case 0x57: /***** str r7 *****/
    MA = R7;MB = D;WRITE();
    break;

case 0x58: /***** str r8 *****/
    MA = R8;MB = D;WRITE();
    break;

case 0x59: /***** str r9 *****/
    MA = R9;MB = D;WRITE();
    break;

case 0x5a: /***** str ra *****/
    MA = R10;MB = D;WRITE();
    break;

case 0x5b: /***** str rb *****/
    MA = R11;MB = D;WRITE();
    break;

case 0x5c: /***** str rc *****/
    MA = R12;MB = D;WRITE();
    break;

case 0x5d: /***** str rd *****/
    MA = R13;MB = D;WRITE();
    break;

case 0x5e: /***** str re *****/
    MA = R14;MB = D;WRITE();
    break;

case 0x5f: /***** str rf *****/
    MA = R15;MB = D;WRITE();
    break;

case 0x60: /***** irx *****/
    (*pX)++;
    break;

case 0x61: /***** out 1 *****/
    MA = *pX;READ();OUTPORT1(MB);(*pX)++;
    break;

case 0x62: /***** out 2 *****/
    MA = *pX;READ();OUTPORT2(MB);(*pX)++;
    break;

case 0x63: /***** out 3 *****/
    MA = *pX;READ();OUTPORT3(MB);(*pX)++;
    break;

case 0x64: /***** out 4 *****/
    MA = *pX;READ();OUTPORT4(MB);(*pX)++;
    break;

case 0x65: /***** out 5 *****/
    MA = *pX;READ();OUTPORT5(MB);(*pX)++;
    break;

case 0x66: /***** out 6 *****/
    MA = *pX;READ();OUTPORT6(MB);(*pX)++;
    break;

case 0x67: /***** out 7 *****/
    MA = *pX;READ();OUTPORT7(MB);(*pX)++;
    break;

case 0x68: /***** db 68 *****/
    ;;
    break;

case 0x69: /***** inp 1 *****/
    MB = D = INPORT1();MA = *pX;WRITE();;
    break;

case 0x6a: /***** inp 2 *****/
    MB = D = INPORT2();MA = *pX;WRITE();;
    break;

case 0x6b: /***** inp 3 *****/
    MB = D = INPORT3();MA = *pX;WRITE();;
    break;

case 0x6c: /***** inp 4 *****/
    MB = D = INPORT4();MA = *pX;WRITE();;
    break;

case 0x6d: /***** inp 5 *****/
    MB = D = INPORT5();MA = *pX;WRITE();;
    break;

case 0x6e: /***** inp 6 *****/
    MB = D = INPORT6();MA = *pX;WRITE();;
    break;

case 0x6f: /***** inp 7 *****/
    MB = D = INPORT7();MA = *pX;WRITE();;
    break;

case 0x70: /***** ret *****/
    __Return();IE = 1;
    break;

case 0x71: /***** dis *****/
    __Return();IE = 0;
    break;

case 0x72: /***** ldxa *****/
    MA = *pX;READ();D = MB;(*pX)++;
    break;

case 0x73: /***** stxd *****/
    MA = *pX;MB = D;WRITE();(*pX)--;
    break;

case 0x74: /***** adc *****/
    MA = *pX;READ();ADD(DF);
    break;

case 0x75: /***** sdb *****/
    MA = *pX;READ();SUB(MB,D,DF);
    break;

case 0x76: /***** rshr *****/
    temp16 = D | (DF << 8);DF = D & 1;D = temp16 >> 1;
    break;

case 0x77: /***** smb *****/
    MA = *pX;READ();SUB(D,MB,DF);
    break;

case 0x78: /***** sav *****/
    MA = *pX;MB = T;WRITE();;
    break;

case 0x79: /***** mark *****/
    __Mark();;
    break;

case 0x7a: /***** req *****/
    Q = 0;OUTPORT0(0);
    break;

case 0x7b: /***** seq *****/
    Q = 1;OUTPORT0(1);
    break;

case 0x7c: /***** adci $1 *****/
    FETCH();ADD(DF);
    break;

case 0x7d: /***** sdbi $1 *****/
    FETCH();SUB(MB,D,DF);
    break;

case 0x7e: /***** rshl *****/
    temp16 = (D << 1) | DF;D = temp16;DF = temp16 >> 8;
    break;

case 0x7f: /***** smbi $1 *****/
    FETCH();SUB(D,MB,DF);
    break;

case 0x80: /***** glo r0 *****/
    D = R0;
    break;

case 0x81: /***** glo r1 *****/
    D = R1;
    break;

case 0x82: /***** glo r2 *****/
    D = R2;
    break;

case 0x83: /***** glo r3 *****/
    D = R3;
    break;

case 0x84: /***** glo r4 *****/
    D = R4;
    break;

case 0x85: /***** glo r5 *****/
    D = R5;
    break;

case 0x86: /***** glo r6 *****/
    D = R6;
    break;

case 0x87: /***** glo r7 *****/
    D = R7;
    break;

case 0x88: /***** glo r8 *****/
    D = R8;
    break;

case 0x89: /***** glo r9 *****/
    D = R9;
    break;

case 0x8a: /***** glo ra *****/
    D = R10;
    break;

case 0x8b: /***** glo rb *****/
    D = R11;
    break;

case 0x8c: /***** glo rc *****/
    D = R12;
    break;

case 0x8d: /***** glo rd *****/
    D = R13;
    break;

case 0x8e: /***** glo re *****/
    D = R14;
    break;

case 0x8f: /***** glo rf *****/
    D = R15;
    break;

case 0x90: /***** ghi r0 *****/
    D = R0 >> 8;
    break;

case 0x91: /***** ghi r1 *****/
    D = R1 >> 8;
    break;

case 0x92: /***** ghi r2 *****/
    D = R2 >> 8;
    break;

case 0x93: /***** ghi r3 *****/
    D = R3 >> 8;
    break;

case 0x94: /***** ghi r4 *****/
    D = R4 >> 8;
    break;

case 0x95: /***** ghi r5 *****/
    D = R5 >> 8;
    break;

case 0x96: /***** ghi r6 *****/
    D = R6 >> 8;
    break;

case 0x97: /***** ghi r7 *****/
    D = R7 >> 8;
    break;

case 0x98: /***** ghi r8 *****/
    D = R8 >> 8;
    break;

case 0x99: /***** ghi r9 *****/
    D = R9 >> 8;
    break;

case 0x9a: /***** ghi ra *****/
    D = R10 >> 8;
    break;

case 0x9b: /***** ghi rb *****/
    D = R11 >> 8;
    break;

case 0x9c: /***** ghi rc *****/
    D = R12 >> 8;
    break;

case 0x9d: /***** ghi rd *****/
    D = R13 >> 8;
    break;

case 0x9e: /***** ghi re *****/
    D = R14 >> 8;
    break;

case 0x9f: /***** ghi rf *****/
    D = R15 >> 8;
    break;

case 0xa0: /***** plo r0 *****/
    R0 = (R0 & 0xFF00) | D;
    break;

case 0xa1: /***** plo r1 *****/
    R1 = (R1 & 0xFF00) | D;
    break;

case 0xa2: /***** plo r2 *****/
    R2 = (R2 & 0xFF00) | D;
    break;

case 0xa3: /***** plo r3 *****/
    R3 = (R3 & 0xFF00) | D;
    break;

case 0xa4: /***** plo r4 *****/
    R4 = (R4 & 0xFF00) | D;
    break;

case 0xa5: /***** plo r5 *****/
    R5 = (R5 & 0xFF00) | D;
    break;

case 0xa6: /***** plo r6 *****/
    R6 = (R6 & 0xFF00) | D;
    break;

case 0xa7: /***** plo r7 *****/
    R7 = (R7 & 0xFF00) | D;
    break;

case 0xa8: /***** plo r8 *****/
    R8 = (R8 & 0xFF00) | D;
    break;

case 0xa9: /***** plo r9 *****/
    R9 = (R9 & 0xFF00) | D;
    break;

case 0xaa: /***** plo ra *****/
    R10 = (R10 & 0xFF00) | D;
    break;

case 0xab: /***** plo rb *****/
    R11 = (R11 & 0xFF00) | D;
    break;

case 0xac: /***** plo rc *****/
    R12 = (R12 & 0xFF00) | D;
    break;

case 0xad: /***** plo rd *****/
    R13 = (R13 & 0xFF00) | D;
    break;

case 0xae: /***** plo re *****/
    R14 = (R14 & 0xFF00) | D;
    break;

case 0xaf: /***** plo rf *****/
    R15 = (R15 & 0xFF00) | D;
    break;

case 0xb0: /***** phi r0 *****/
    R0 = (R0 & 0x00FF) | (D << 8);
    break;

case 0xb1: /***** phi r1 *****/
    R1 = (R1 & 0x00FF) | (D << 8);
    break;

case 0xb2: /***** phi r2 *****/
    R2 = (R2 & 0x00FF) | (D << 8);
    break;

case 0xb3: /***** phi r3 *****/
    R3 = (R3 & 0x00FF) | (D << 8);
    break;

case 0xb4: /***** phi r4 *****/
    R4 = (R4 & 0x00FF) | (D << 8);
    break;

case 0xb5: /***** phi r5 *****/
    R5 = (R5 & 0x00FF) | (D << 8);
    break;

case 0xb6: /***** phi r6 *****/
    R6 = (R6 & 0x00FF) | (D << 8);
    break;

case 0xb7: /***** phi r7 *****/
    R7 = (R7 & 0x00FF) | (D << 8);
    break;

case 0xb8: /***** phi r8 *****/
    R8 = (R8 & 0x00FF) | (D << 8);
    break;

case 0xb9: /***** phi r9 *****/
    R9 = (R9 & 0x00FF) | (D << 8);
    break;

case 0xba: /***** phi ra *****/
    R10 = (R10 & 0x00FF) | (D << 8);
    break;

case 0xbb: /***** phi rb *****/
    R11 = (R11 & 0x00FF) | (D << 8);
    break;

case 0xbc: /***** phi rc *****/
    R12 = (R12 & 0x00FF) | (D << 8);
    break;

case 0xbd: /***** phi rd *****/
    R13 = (R13 & 0x00FF) | (D << 8);
    break;

case 0xbe: /***** phi re *****/
    R14 = (R14 & 0x00FF) | (D << 8);
    break;

case 0xbf: /***** phi rf *****/
    R15 = (R15 & 0x00FF) | (D << 8);
    break;

case 0xc0: /***** lbr $2 *****/
    FETCH2();LBRANCH();;
    break;

case 0xc1: /***** lbq $2 *****/
    FETCH2();if (Q != 0) LBRANCH();
    break;

case 0xc2: /***** lbz $2 *****/
    FETCH2();if (D == 0) LBRANCH();
    break;

case 0xc3: /***** lbdf $2 *****/
    FETCH2();if (DF != 0) LBRANCH();
    break;

case 0xc4: /***** nop *****/
    Cycles--;
    break;

case 0xc5: /***** lsnq *****/
    Cycles--;if (Q == 0) LSKIP();
    break;

case 0xc6: /***** lsnz *****/
    Cycles--;if (D != 0) LSKIP();
    break;

case 0xc7: /***** lsnf *****/
    Cycles--;if (DF == 0) LSKIP();
    break;

case 0xc8: /***** lskp *****/
    Cycles--;LSKIP();;
    break;

case 0xc9: /***** lbnq $2 *****/
    FETCH2();if (Q == 0) LBRANCH();
    break;

case 0xca: /***** lbnz $2 *****/
    FETCH2();if (D != 0) LBRANCH();
    break;

case 0xcb: /***** lbnf $2 *****/
    FETCH2();if (DF == 0) LBRANCH();
    break;

case 0xcc: /***** lsie *****/
    Cycles--;if (IE != 0) LSKIP();
    break;

case 0xcd: /***** lsq *****/
    Cycles--;if (Q != 0) LSKIP();
    break;

case 0xce: /***** lsz *****/
    Cycles--;if (D == 0) LSKIP();
    break;

case 0xcf: /***** lsdf *****/
    Cycles--;if (DF != 0) LSKIP();
    break;

case 0xd0: /***** sep r0 *****/
    P = 0;pP = &R0;
    break;

case 0xd1: /***** sep r1 *****/
    P = 1;pP = &R1;
    break;

case 0xd2: /***** sep r2 *****/
    P = 2;pP = &R2;
    break;

case 0xd3: /***** sep r3 *****/
    P = 3;pP = &R3;
    break;

case 0xd4: /***** sep r4 *****/
    P = 4;pP = &R4;
    break;

case 0xd5: /***** sep r5 *****/
    P = 5;pP = &R5;
    break;

case 0xd6: /***** sep r6 *****/
    P = 6;pP = &R6;
    break;

case 0xd7: /***** sep r7 *****/
    P = 7;pP = &R7;
    break;

case 0xd8: /***** sep r8 *****/
    P = 8;pP = &R8;
    break;

case 0xd9: /***** sep r9 *****/
    P = 9;pP = &R9;
    break;

case 0xda: /***** sep ra *****/
    P = 10;pP = &R10;
    break;

case 0xdb: /***** sep rb *****/
    P = 11;pP = &R11;
    break;

case 0xdc: /***** sep rc *****/
    P = 12;pP = &R12;
    break;

case 0xdd: /***** sep rd *****/
    P = 13;pP = &R13;
    break;

case 0xde: /***** sep re *****/
    P = 14;pP = &R14;
    break;

case 0xdf: /***** sep rf *****/
    P = 15;pP = &R15;
    break;

case 0xe0: /***** sex r0 *****/
    X = 0;pX = &R0;
    break;

case 0xe1: /***** sex r1 *****/
    X = 1;pX = &R1;
    break;

case 0xe2: /***** sex r2 *****/
    X = 2;pX = &R2;
    break;

case 0xe3: /***** sex r3 *****/
    X = 3;pX = &R3;
    break;

case 0xe4: /***** sex r4 *****/
    X = 4;pX = &R4;
    break;

case 0xe5: /***** sex r5 *****/
    X = 5;pX = &R5;
    break;

case 0xe6: /***** sex r6 *****/
    X = 6;pX = &R6;
    break;

case 0xe7: /***** sex r7 *****/
    X = 7;pX = &R7;
    break;

case 0xe8: /***** sex r8 *****/
    X = 8;pX = &R8;
    break;

case 0xe9: /***** sex r9 *****/
    X = 9;pX = &R9;
    break;

case 0xea: /***** sex ra *****/
    X = 10;pX = &R10;
    break;

case 0xeb: /***** sex rb *****/
    X = 11;pX = &R11;
    break;

case 0xec: /***** sex rc *****/
    X = 12;pX = &R12;
    break;

case 0xed: /***** sex rd *****/
    X = 13;pX = &R13;
    break;

case 0xee: /***** sex re *****/
    X = 14;pX = &R14;
    break;

case 0xef: /***** sex rf *****/
    X = 15;pX = &R15;
    break;

case 0xf0: /***** ldx *****/
    MA = *pX;READ();D = MB;
    break;

case 0xf1: /***** or *****/
    MA = *pX;READ();D |= MB;
    break;

case 0xf2: /***** and *****/
    MA = *pX;READ();D &= MB;
    break;

case 0xf3: /***** xor *****/
    MA = *pX;READ();D ^= MB;
    break;

case 0xf4: /***** add *****/
    MA = *pX;READ();ADD(0);
    break;

case 0xf5: /***** sd *****/
    MA = *pX;READ();SUB(MB,D,1);
    break;

case 0xf6: /***** shr *****/
    DF = D & 1;D = (D >> 1) & 0x7F;
    break;

case 0xf7: /***** sm *****/
    MA = *pX;READ();SUB(D,MB,1);
    break;

case 0xf8: /***** ldi $1 *****/
    FETCH();D = MB;
    break;

case 0xf9: /***** ori $1 *****/
    FETCH();D |= MB;
    break;

case 0xfa: /***** ani $1 *****/
    FETCH();D &= MB;
    break;

case 0xfb: /***** xri $1 *****/
    FETCH();D ^= MB;
    break;

case 0xfc: /***** adi $1 *****/
    FETCH();ADD(0);
    break;

case 0xfd: /***** sdi $1 *****/
    FETCH();SUB(MB,D,1);
    break;

case 0xfe: /***** shl *****/
    DF = (D >> 7) & 1;D = D << 1;
    break;

case 0xff: /***** smi $1 *****/
    FETCH();SUB(D,MB,1);
    break;


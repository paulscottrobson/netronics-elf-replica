static BYTE8  D,DF,MB,Q,IE,P,X,T;
static WORD16 R0,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11,R12,R13,R14,R15,Cycles,temp16,MA;
static WORD16 *pX,*pP;
static void __1802Reset(void) {
 Q = 0;IE = 1;X = 0;P = 0;R0 = 0;
 pX = pP = &R0;
 DF &= 1;
 OUTPORT0(0);
}
#define FETCH()   MA = (*pP)++;READ()
#define ADD(c) temp16 = D + MB + (c);D = temp16;DF = (temp16 >> 8) & 1
#define SUB(a,b,c) temp16 = (a) + ((b)^0xFF) + (c);D = temp16;DF = (temp16 >> 8) & 1
#define SBRANCH()   { *pP = ((*pP) & 0xFF00) | MB; }
#define FETCH2()  { FETCH();temp16 = (MB << 8);FETCH();temp16 |= MB; Cycles++; }
#define LBRANCH()   { *pP = temp16; }
#define LSKIP()   { *pP = (*pP) + 2; }
static void inline __Mark(void) {
 T = (X << 4) | P;
 MB = T;MA = R2;WRITE();
 X = P;pX = pP;
 R2--;
}
static WORD16 *__RPtr[] = { &R0,&R1,&R2,&R3,&R4,&R5,&R6,&R7,&R8,&R9,&R10,&R11,&R12,&R13,&R14,&R15 };
static void inline __Return(void) {
 MA = *pX;READ();
 (*pX)++;
 X = (MB >> 4);P = (MB & 0x0F);
 pX = __RPtr[X];
 pP = __RPtr[P];
}
static void __1802Interrupt(void) {
 if (IE != 0) {
  T = (X << 4) | P;
  P = 1;X = 2;
  pP = &R1;pX = &R2;
  IE = 0;
 }
}
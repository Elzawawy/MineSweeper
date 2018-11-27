#ifndef UTILS_H
#define UTILS_H
#define GetBit(Reg,No) (Reg&(1<<No))
#define SetBit(number,n) number=(number | (1 << n))
#define ClearBit(number,n) number=(number & ~(1 << n))
#define ToggleBit(number,n) number=(number ^(1 << n))
#define ClearPort(number) number=(number &(0b00000000))
#define SetPort(number) number=(number |(0b11111111))
#define TogglePort(number) number=(number ^(0b11111111))
#define AssignBit(number,BitNo,Value)  number=(number & (~(1<<BitNo)))|(Value<<BitNo)
#define ConcByteHelper(x7,x6,x5,x4,x3,x2,x1,x0) 0b##x7##x6##x5##x4##x3##x2##x1##x0
#define Concbyte(x7,x6,x5,x4,x3,x2,x1,x0) ConcByteHelper(x7,x6,x5,x4,x3,x2,x1,x0)
#define Conc2XByteHelper(x15,x14,x13,x12,x11,x10,x8x7,x6,x5,x4,x3,x2,x1,x0) 0b##x7##x6##x5##x4##x3##x2##x1##x0
#define Conc2Xbyte(x7,x6,x5,x4,x3,x2,x1,x0) ConcByteHelper(x7,x6,x5,x4,x3,x2,x1,x0)

#endif

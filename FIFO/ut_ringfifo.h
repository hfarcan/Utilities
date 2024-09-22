#ifndef     UT_RING_H_
#define     UT_RING_H_

#include "Types.h"

typedef struct
{
	tU8     Buf[16];
	tU32    Wrt;
	tU32    Read;
	tU32    Cnt;
	tU32 		OverWriteEnb;
}tRing16Byte;

typedef struct
{
	tU8     Buf[64];
	tU32    Wrt;
	tU32    Read;
	tU32    Cnt;
	tU32		Ovf;
	tU32		Peak;
}tRing64;


typedef struct
{
	tU8     Buf[128];
	tU32    Wrt;
	tU32    Read;
	tU32    Cnt;
	tU32 		OverWriteEnb;

}tRing128Byte;


typedef struct
{
	tU8     Buf[256];
	tU32 		Wrt;
	tU32    Read;
	tU32    Cnt;
	tU32 		OverWriteEnb;

}tRing256Byte;



typedef struct
{
	tU32    Buf[16];
	tU32    Wrt;
	tU32    Read;
	tU32    Cnt;
	tU32 		OverWriteEnb;

}tRing16Quad;


typedef struct
{
	tU32    Buf[128];
	tU32    Wrt;
	tU32    Read;
	tU32    Cnt;
	tU32 		OverWriteEnb;

}tRing128Quad;


typedef struct
{
	tU32    Buf[256];
	tU32 		Wrt;
	tU32    Read;
	tU32    Cnt;
	tU32 		OverWriteEnb;

}tRing256Quad;


void Ring16InitByte(tRing16Byte* pRing, tU32 Sta);
void Ring16InitQuad(tRing16Quad* pRing, tU32 Sta);
void Ring16NewByte(tRing16Byte* pRing, tU8 Data);
tU32 Ring16ReadByte(tRing16Byte* pRing, tU8* pDst, tU32 Len);
void Ring16NewQuad(tRing16Quad* pRing, tU32 Data);
tU32 Ring16ReadQuad(tRing16Quad* pRing, tU32* pDst, tU32 Len);


void Ring64Init(tRing64* pRing);
tU32 Ring64NewByte(tRing64* pRing, tU8 Byte);
tU32 Ring64Read(tRing64* pRing, tU8* pDst, tU32 Len);



#endif  /*UT_RING_H_*/

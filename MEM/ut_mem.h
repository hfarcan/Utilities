#ifndef     UT_MEM_H_
#define     UT_MEM_H_

#include "Types.h"

void	MemMove(tU8* pDst, tU8* pSrc, tU16 Len);
void	MemSet(tU8* pDst, tU8 Val, tU16 Len);
tS16	MemCompare(tU8* pMemA, tU8* pMemB, tU16 Len);
tS16 	MemPutStr(tS8* pDst, void* pSrc);
void 	MemPutChar(tS8* pDst, tU8 Char);
void	MemPutU16(tU8* pDst, tU16 Val);
void	MemPutU16I(tU8* pDst, tU16 Val);
void	MemPutS16(tU8* pDst, tS16 Val);
void	MemPutU32(tU8* pDst, tU32 Val);
void	MemPutU32I(tU8* pDst, tU32 Val);
void	MemPutFLOAT(tU8* pDst, float Val);
tS16 	MemPutFlags(tS8* pDst,void* pStr, tU32 Flags);
tS16 	MemGetDigitCnt(tS32 Val);
tS16 	MemPutS32Digits(tS8* pDst, tS32 Val, tU16 MinDigits);
tU16	MemGetU16(tU8* pSrc);
tS16	MemGetS16(tU8* pSrc);
tU32	MemGetU32(tU8* pSrc);
tS32	MemGetS32(tU8* pSrc);
float	MemGetFLOAT(tU8* pSrc);

typedef struct
{
	void	(*Move)(tU8* pDst, tU8* pSrc, tU16 Len);
	void	(*Set)(tU8* pDst, tU8 Val, tU16 Len);
	tS16	(*Compare)(tU8* pMemA, tU8* pMemB, tU16 Len);
	tS16 	(*PutStr)(tS8* pDst, void* pSrc);
	void 	(*PutChar)(tS8* pDst, tU8 Char);
	void	(*PutU16)(tU8* pDst, tU16 Val);
	void	(*PutS16)(tU8* pDst, tS16 Val);
	void	(*PutU32)(tU8* pDst, tU32 Val);
	void	(*PutFLOAT)(tU8* pDst, float Val);
	tS16 	(*PutFlags)(tS8* pDst,void* pStr, tU32 Flags);
	tS16 	(*GetDigitCnt)(tS32 Val);
	tS16 	(*PutS32Digits)(tS8* pDst, tS32 Val, tU16 MinDigits);
	tU16	(*GetU16)(tU8* pSrc);
	tS16	(*GetS16)(tU8* pSrc);
	tU32	(*GetU32)(tU8* pSrc);
	tS32	(*GetS32)(tU8* pSrc);
	float	(*GetFLOAT)(tU8* pSrc);
} tUtMem;




#endif  /*UT_MEM_H_*/




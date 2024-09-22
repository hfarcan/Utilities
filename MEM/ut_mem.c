#include "Types.h"

void	MemMove(tU8* pDst, tU8* pSrc, tU16 Len)
{
	if(pDst > pSrc)
	{
		pDst += Len;
		pSrc += Len;
		while(Len--)
			*(--pDst) = *(--pSrc);
	}
	else
	{
		while(Len--)
			*pDst++ = *pSrc++;			
	}
}

void	MemSet(tU8* pDst, tU8 Val, tU16 Len)
{
	while(Len--)
		*pDst++ = Val;			
}

tS16	MemCompare(tU8* pMemA, tU8* pMemB, tU16 Len)
{
tS16	ret;

	ret = 0;
	while(Len--)
	{
		ret += *pMemA++ - *pMemB++;
		if(ret)
			break;
	}
	return ret;
}

tS16 MemPutStr(tS8* pDst, void* pSrc)
{
tU8* p;
tS16 len;	

	p = pSrc;
	len = 0;
	while(p && *p)
	{
		*pDst++ = *p++;	
		len++;
	}
	*pDst = 0x00;
	return len;
}

void MemPutChar(tS8* pDst, tU8 Char)
{
	if(pDst)
	{
		*pDst = Char;	
	}
}

void	MemPutU16(tU8* pDst, tU16 Val)
{
	*pDst++ = Val >> 8;
	*pDst = Val;
}

void	MemPutU16I(tU8* pDst, tU16 Val)
{
	*pDst++ = Val;
	*pDst = Val >> 8;
}

void	MemPutS16(tU8* pDst, tS16 Val)
{
	*pDst++ = Val >> 8;
	*pDst = Val;
}

void	MemPutU32(tU8* pDst, tU32 Val)
{
	*pDst++ = Val >> 24;
	*pDst++ = Val >> 16;
	*pDst++ = Val >> 8;
	*pDst = Val;
}

void	MemPutU32I(tU8* pDst, tU32 Val)
{
	*pDst++ = Val;
	*pDst++ = Val >> 8;
	*pDst++ = Val >> 16;
	*pDst = Val >> 24;
}

void	MemPutFLOAT(tU8* pDst, float Val)
{
	MemPutU32(pDst, *(tU32*) &Val);
}

tS16 MemPutFlags(tS8* pDst,void* pStr, tU32 Flags)
{
tU16 i;
tU8 nibble;	
tS16 len;	
	
	len = MemPutStr(pDst,pStr);
	pDst+=len;
	for(i = 0; i<8; i++)
	{
		nibble = (0x0F)&(Flags>>((7-i)*4));
		if(nibble<0x0A)
			nibble = nibble + '0';
		else
			nibble = nibble - 10 + 'A';			
		MemPutChar(pDst++, nibble);	
	}
	*pDst = 0x00;
	len +=8;
		
	return len;
}

tS16 MemGetDigitCnt(tS32 Val)
{
tS16 len;

	len = 0;
	while(Val)
	{
		len++;
		Val /= 10;
	}
		
	return len;
}

tS16 MemPutS32Digits(tS8* pDst, tS32 Val, tU16 MinDigits)
{
tS16 len;
tS32 div;
tS32 res;	
tU8	 ch;	
tS16 digcnt;	
	
	len = 0;
	if(Val < 0)
	{
		MemPutChar(&pDst[len++], '-');
		Val = -Val;
	}
	
	digcnt = MemGetDigitCnt(Val);
	div = 1;
	if(digcnt < MinDigits)
		digcnt = MinDigits;
	while(--digcnt)
		div *= 10;
	
	while(div)
	{
		if(Val >= div)
		{
			res = Val / div;
			ch = res;
			Val -= res * div;
			MemPutChar(&pDst[len++], ch + '0');
		}
		else
		{
			MemPutChar(&pDst[len++], '0');
		}
		div /= 10;
	}	
	MemPutChar(&pDst[len], 0x00);
	return len;
}


tU16	MemGetU16(tU8* pSrc)
{
tU16	ret;
			
	ret = 0;
	ret += *pSrc++;	ret <<= 8;
	ret += *pSrc;
	return ret;
}


tS16	MemGetS16(tU8* pSrc)
{
tS16	ret;
			
	ret = 0;
	ret += *pSrc++;	ret <<= 8;
	ret += *pSrc;
	return ret;
}

tU32	MemGetU32(tU8* pSrc)
{
tU32	ret;
			
	ret = 0;
	ret += *pSrc++;	ret <<= 8;
	ret += *pSrc++;	ret <<= 8;
	ret += *pSrc++;	ret <<= 8;
	ret += *pSrc;
	return ret;
}


tS32	MemGetS32(tU8* pSrc)
{
tS32	ret;
			
	ret = 0;
	ret += *pSrc++;	ret <<= 8;
	ret += *pSrc++;	ret <<= 8;
	ret += *pSrc++;	ret <<= 8;
	ret += *pSrc;
	return ret;
}

float	MemGetFLOAT(tU8* pSrc)
{
float	ret;
tU32	val;	
				
	val = MemGetU32(pSrc);
	ret = *(float*)&val;
	return ret;
}



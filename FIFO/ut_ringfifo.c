#include "ut_po.h"


void Ring16InitByte(tRing16Byte* pRing, tU32 Sta)
{
	pRing->Wrt = 0;
	pRing->Cnt = 0;
	pRing->Read = 0;
	pRing->OverWriteEnb = Sta;
}

void Ring16InitQuad(tRing16Quad* pRing, tU32 Sta)
{
	pRing->Wrt = 0;
	pRing->Cnt = 0;
	pRing->Read = 0;
	pRing->OverWriteEnb = Sta;
	
}

void Ring16NewByte(tRing16Byte* pRing, tU8 Data)
{
		if (pRing->Cnt >= 16)
		{
			if (!pRing->OverWriteEnb)
				return;
		}
		
		if (pRing->Wrt >= 16)		
			pRing->Wrt = 0;
		
		pRing->Buf[pRing->Wrt++] = Data;
		
		pRing->Cnt++;
		if (pRing->Cnt > 16)
		{
			pRing->Cnt = 16;
			if (pRing->Wrt >= 16)
				pRing->Wrt = 0;
			pRing->Read = pRing->Wrt;
		}
}

void Ring64Init(tRing64* pRing)
{
	pRing->Wrt = 0;
	pRing->Cnt = 0;
	pRing->Read = 0;
	pRing->Ovf = 0;
	pRing->Peak = 0;
}


tU32 Ring64NewByte(tRing64* pRing, tU8 Data)
{
		if(pRing->Cnt < 64)		
		{
			pRing->Cnt++;
			if(pRing->Cnt > pRing->Peak)
				pRing->Peak = pRing->Cnt;
		}
		else
		{
			pRing->Ovf++;
		}
		
		if(pRing->Wrt >= 64)		
			pRing->Wrt = 0;
		
		pRing->Buf[pRing->Wrt++] = Data;
		
		return pRing->Cnt;
}

tU32 Ring64Read(tRing64* pRing, tU8* pDst, tU32 Len)
{
tU32 i;

		if (Len > pRing->Cnt)	Len = pRing->Cnt;
	
		for (i = 0; i < Len; i++)
		{
			if (pRing->Read >= 64)
				pRing->Read = 0;
	
			pDst[i] = pRing->Buf[pRing->Read++];
			pRing->Cnt--;
		}
		return Len;
}


tU32 Ring16ReadByte(tRing16Byte* pRing, tU8* pDst, tU32 Len)
{
	
tU32 i;

		if (Len > pRing->Cnt)	Len = pRing->Cnt;
	
		for (i = 0; i < Len; i++)
		{
			if (pRing->Read >= 16)
				pRing->Read = 0;
	
			pDst[i] = pRing->Buf[pRing->Read++];
			pRing->Cnt--;
		}

		return Len;

}





void Ring16NewQuad(tRing16Quad* pRing, tU32 Data)
{
		if (pRing->Cnt >= 16)
		{
			if (!pRing->OverWriteEnb)
				return;
		}
		
		if (pRing->Wrt >= 16)		
			pRing->Wrt = 0;
		
		pRing->Buf[pRing->Wrt++] = Data;
		
		pRing->Cnt++;
		if (pRing->Cnt > 16)
		{
			pRing->Cnt = 16;
			if (pRing->Wrt >= 16)
				pRing->Wrt = 0;
			pRing->Read = pRing->Wrt;
		}
}



tU32 Ring16ReadQuad(tRing16Quad* pRing, tU32* pDst, tU32 Len)
{
	
tU32 i;

		if (Len > pRing->Cnt)	Len = pRing->Cnt;
	
		for (i = 0; i < Len; i++)
		{
			if (pRing->Read >= 16)
				pRing->Read = 0;
	
			pDst[i] = pRing->Buf[pRing->Read++];
			pRing->Cnt--;
		}

		return Len;

}




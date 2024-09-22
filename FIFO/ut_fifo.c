#include "ut_fifo.h"


void	FifoF10Write(tFifoF10* pFifo, float In)
{
			if(pFifo->WrtIdx >= 10)
				pFifo->WrtIdx = 0;
			
			pFifo->Delta = In - pFifo->Data[pFifo->WrtIdx];
			pFifo->Data[pFifo->WrtIdx++] = In;
}


void	FifoF10Clear(tFifoF10* pFifo)
{
tU16	i;	
	
			for(i = 0; i < 10; i++)
				pFifo->Data[i] = 0.0f;
			
			pFifo->Delta = 0.0f;
			pFifo->WrtIdx = 0;
}

void	FifoS10Write(tFifoS10* pFifo, tS32 In)
{
			if(pFifo->WrtIdx >= 10)
				pFifo->WrtIdx = 0;
			
			pFifo->Delta = In - pFifo->Data[pFifo->WrtIdx];
			pFifo->Data[pFifo->WrtIdx++] = In;
}


void	FifoS10Clear(tFifoS10* pFifo)
{
tU16	i;	
	
			for(i = 0; i < 10; i++)
				pFifo->Data[i] = 0;
			
			pFifo->Delta = 0;
			pFifo->WrtIdx = 0;
}



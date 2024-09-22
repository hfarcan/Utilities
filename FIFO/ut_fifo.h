#ifndef     UT_FIFO_H_
#define     UT_FIFO_H_

#include "po_Types.h"

typedef struct
{
	tU32	WrtIdx;
	float Data[10];
	float Delta;
} tFifoF10;

typedef struct
{
	tU32	WrtIdx;
	tS32	Data[10];
	tS32	Delta;
} tFifoS10;

void	FifoF10Write(tFifoF10* pFifo, float In);
void	FifoF10Clear(tFifoF10* pFifo);

void	FifoS10Write(tFifoS10* pFifo, tS32 In);
void	FifoS10Clear(tFifoS10* pFifo);

#endif  /*UT_FIFO_H_*/

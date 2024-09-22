
#ifndef     UT_ANGLE_H_
#define     UT_ANGLE_H_

#include "Types.h"

typedef struct 
{   
		float	Theta;		
		float	Sin;			
		float	Cos;			
} tSinCos;


void	TrimTheta(float* pTh);
float	DeltaTheta(float Th, float ThPrev);
void	SinCosCalc(float Theta, float* pSinTheta, float* pCosTheta);


typedef struct
{
	void	(*TrimTheta)(float* pTh);
	void	(*SinCosCalc)(float Theta, float* SinTheta, float* CosTheta);
} tUtAngle;


#endif  /*UT_ANGLE_H_*/









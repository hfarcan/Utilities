#include "Types.h"


#define	X_DELTA	(0.5f/32)	
#define	IDX_COEF	64.0f				// 1.0f/X_DELTA

const	float	SinTableF[] = // 0...  pi/2
{			
	0,	
	0.049067674f,			0.098017140f,		0.146730474f,	0.195090322f,
	0.242980180f,			0.290284677f,		0.336889853f,	0.382683432f,	
	0.427555093f,			0.471396737f,		0.514102744f,	0.555570233f,
	0.595699304f,			0.634393284f,		0.671558955f,	0.707106781f,
	0.740951125f,			0.773010453f,		0.803207531f,	0.831469612f,
	0.857728610f,			0.881921264f,		0.903989293f,	0.923879533f,
	0.941544065f,			0.956940336f,		0.970031253f,	0.980785280f,
	0.989176510f,			0.995184727f,		0.998795456f,	1.0f
};

const	float	CosTableF[] = // 0...  pi/2
{			
	1.0f,
	0.998795456f,	0.995184727f,	0.989176510f ,	0.980785280f ,	
	0.970031253f,	0.956940336f,	0.941544065f,	0.923879533f,	
	0.903989293f,	0.881921264f,	0.857728610f ,	0.831469612f,	
	0.803207531f,	0.773010453f,	0.740951125f,	0.707106781f,	
	0.671558955f,	0.634393284f,	0.595699304f,	0.555570233f,	
	0.514102744f,	0.471396737f,	0.427555093f,	0.382683432f,	
	0.336889853f,	0.290284677f,	0.242980180f ,	0.195090322f,	
	0.146730474f,	0.098017140f ,	0.049067674f,	0.0f
};

void	TrimTheta(float* pTh)
{
			*pTh -= ((tS32)*(pTh))&(~1);
			if(*pTh < 0.0f)
				*pTh += 2.0f;				
}

float	DeltaTheta(float Th, float ThPrev)
{
float	delta;

			delta = Th - ThPrev;
			if(delta > 1.0f)	delta -= 2.0f;
			if(delta < -1.0f)	delta += 2.0f;

			return delta;
}


//y = y1 + (x - x1)*((y2 - y1)/(x2 - x1));
void	SinCosCalc(float Theta, float* pSinTheta, float* pCosTheta)
{	
tU32	k;
float	frac;
tU32	zone;

		TrimTheta(&Theta);

		zone = 1;
		if(Theta > 1.0f)																					// sin(a+pi) = -sin(a)
		{																													// cos(a+pi) = cos(a)
			zone += 2;
			Theta -= 1.0f;
		}
		if(Theta > 0.5f)																					// sin(a + pi/2) = sin(pi/2 - a)
		{																													//
			zone++;
			Theta = 1.0f - Theta;
		}		

		k = Theta * IDX_COEF;
		frac = Theta * IDX_COEF - k;
		(*pSinTheta) = SinTableF[k] + frac * (SinTableF[k+1] - SinTableF[k]);													
		(*pCosTheta) = CosTableF[k] + frac * (CosTableF[k+1] - CosTableF[k]);													
		if(zone > 2)
			(*pSinTheta) = -(*pSinTheta);
		if((zone == 2) || (zone == 3))
			(*pCosTheta) = -(*pCosTheta);

}





#ifndef     TYPES_H_
#define     TYPES_H_


#define	SIGNATURE						0x17071783	
#define	N_TCB_SLOTS					32
#define TASK_ID_ANY					(N_TCB_SLOTS+10)
#define TASK_ID_HW					(N_TCB_SLOTS+15)
#define TASK_ID_NON					(N_TCB_SLOTS+20)
#define	N_HW_MSG						16
#define	N_SEMAPHORES				32
#define	N_MUTEXES						32

#define OFFSETOF(Type, Item, Child)    (((tU32)(&(((Type*)0)->Item))) / sizeof(Child))



#define	ID2BIT(Id)					      (0x00000001 << (Id))
#define	SATURATE(a, Min, Max)		  (a)=(a)>(Max)?(Max):(a)<(Min)?(Min):(a)
#define	FILTER(Out, In, Coef) 		Out+=(Coef)*((In)-(Out))
#define	MAX(A,B) 					        ((A) > (B)? (A): (B))
#define	MIN(A,B) 					        ((A) < (B)? (A): (B))
#define	ABS(Val) 					        ((Val) > 0? (Val): -(Val))
#define COUNTOF(a)   		          (sizeof((a)) / sizeof((a)[0]))
#define COUNTOFU32(a)             (sizeof(a) / sizeof(tU32))
	

typedef signed char						tS8;
typedef unsigned char					tU8;
typedef signed	short int			tS16;
typedef unsigned short int		tU16;
typedef signed	int						tS32;
typedef unsigned int					tU32;
typedef signed	long long			tS64;
typedef unsigned long long		tU64;

#endif  /*TYPES_H_*/


/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  22 Aug 2023                                  */
/*     Version  :  V01                                          */
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"


void STK_Void_STKInit(void)
{
#if STK_CLOCK_INPUT    ==  STK_CLOCK_AHB

	/* To Select AHB as input clock source , Disable interrupt , Disable Timer */
	STK->CTRL = 0x00000004;

#elif STK_CLOCK_INPUT ==   STK_CLOCK_AHB_DIV8
	/* To Select AHB/8 as input clock source , Disable interrupt , Disable Timer */
	STK->CTRL = 0x00000000;

#endif

}

void STK_Void_STKSetBusyWait(u32 Copy_U32_Ticks)
{

     /* To Reset VALUE Register */
     STK->VAL = 0 ;

     /* Writing number of ticks to be counted by timer */
     STK->LOAD = Copy_U32_Ticks ;

     /* To Enable Timer to start counting  */
     SET_BIT(STK->CTRL,0);

     /* To force processor to stuck until Timer finishes counting */
     while(GET_BIT(STK->CTRL,16) == 0);

     /* To Disable Timer  */
     CLR_BIT(STK->CTRL,0);
     /* To Clear LOAD Register to count one time */
     STK->LOAD =0;


}
void STK_Void_STKSetIntervalSingle(u32 Copy_U32_Ticks , void (*Copy_ptr)(void))
{
   /* To Disable Timer */
   CLR_BIT(STK->CTRL,0);


  STK_callback = Copy_ptr;


  /* To Reset VALUE Register */
  STK->VAL = 0 ;

  /* To Enable interrupt */
  SET_BIT(STK->CTRL,1);

 /* To Select Single Interval mode in ISR */
  Local_U8_STKMode = STK_SINGLE_INTERVAL ;

  /* Writing number of ticks to be counted by timer */
  STK->LOAD = Copy_U32_Ticks ;

  /* To Enable Timer to start counting  */
  SET_BIT(STK->CTRL,0);


}
void STK_Void_STKSetIntervalPeriodic(u32 Copy_U32_Ticks , void (*Copy_ptr)(void))
{
	  STK_callback = Copy_ptr;

	  /* To Reset VALUE Register */
	  STK->VAL = 0 ;

	  /* To Enable interrupt */
	  SET_BIT(STK->CTRL,1);

	  /* To Select Periodic Interval mode in ISR */
       Local_U8_STKMode = STK_PERIODIC_INTERVAL ;

	  /* Writing number of ticks to be counted by timer */
	  STK->LOAD = Copy_U32_Ticks ;

	  /* To Enable Timer to start counting  */
	  SET_BIT(STK->CTRL,0);


}
u32 STK_U32_STKGetElapsedTime(void)
{
	u32 Local_U32_Time = STK->LOAD - STK->VAL;
	return Local_U32_Time;

}
u32 STK_U32_STKGetRemainingTime()
{
   return STK->VAL ;
}
void STK_U32_STKStopTimer()
{
	/* To Disable Timer   */
	CLR_BIT(STK->CTRL,0);
}

void SysTick_Handler(void)
{
	u8 Local_U8_Temporary ;

	if(Local_U8_STKMode == STK_SINGLE_INTERVAL)
	{
		/* To Disable Timer   */
		STK->LOAD = 0 ;
		CLR_BIT(STK->CTRL,0);

		/* To Disable interrupt */
		CLR_BIT(STK->CTRL,1);
	}

   STK_callback();

   /* To clear Interrupt flag */
   Local_U8_Temporary = GET_BIT(STK->CTRL,16);

}






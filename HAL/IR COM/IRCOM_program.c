/*********************************************************/
/*  Author    :  Ahmed Yousry                            */
/*  Date      :  2 Sep 2023                              */
/*  Version   :  V01                                     */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"

#include "IRCOM_interface.h"
#include "IRCOM_config.h"
#include "IRCOM_private.h"

volatile u8 U8_IRData = 0;

 void IRCOM_Void_InitIR(void)
{
	 /* EXTI configuration for  PA0 */
	 GPIO_Void_SetPinDirection(PORTA , PIN0 , GPIO_INPUT_FLOATING);

     EXTI_Void_SetCallBack(IRCOM_Void_GetFrame,0);
     EXTI_Void_ExtiInit(0,FALLING_EDGE);
     EXTI_Void_ExtiEnable(0);

     NVIC_Void_EnableInterrupt(6);



}
static void IRCOM_Void_GetFrame(void)
{
	if(startFlag == 0)
	{
	   STK_Void_STKSetIntervalSingle(50000, IRCOM_Void_TakeAction);
	   startFlag = 1;
	}
	else
	{
		DataFrame[counter++] = STK_U32_STKGetElapsedTime();
		STK_Void_STKSetIntervalSingle(50000, IRCOM_Void_TakeAction);

	}
}
void IRCOM_Void_TakeAction(void)
{
	u8 DataCounter;


	for(DataCounter = 0 ; DataCounter < 8 ; DataCounter ++)
	{
	  if(DataFrame[17 + DataCounter]>2000 && DataFrame[17 + DataCounter]< 2500)
	  {
		  SET_BIT(IRCOM_Data , DataCounter);
	  }
	  else
	  {
		  CLR_BIT(IRCOM_Data , DataCounter);
	  }
	}

	   U8_IRData = IRCOM_Data ;


	   IRCOM_Data = 0;
	   counter = 0;
	   DataFrame[0] = 0;
	   startFlag = 0;

}



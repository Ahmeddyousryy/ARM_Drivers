/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  15 Aug 2023                                  */
/*     Version  :  V01                                          */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void EXTI_Void_ExtiInit(u8 Copy_U8_Line,u8 Copy_U8_Mode)
{
	switch(Copy_U8_Mode)
	{
	case RISING_EDGE  :  SET_BIT(EXTI->RTSR,Copy_U8_Line);                      break;
	case FALLING_EDGE :  SET_BIT(EXTI->FTSR,Copy_U8_Line);                      break;
    case ON_CHANGE    :  SET_BIT(EXTI->RTSR,Copy_U8_Line);
	                     SET_BIT(EXTI->FTSR,Copy_U8_Line);                      break;
	default           :                                                         break;
	}

}
void EXTI_Void_ExtiEnable(u8 Copy_U8_Line)
{
	 SET_BIT(EXTI->IMR , Copy_U8_Line);

}
void EXTI_Void_ExtiDisable(u8 Copy_U8_Line)
{
	 CLR_BIT(EXTI->IMR , Copy_U8_Line);
}
void EXTI_Void_SWTrigger(u8 Copy_U8_Line)
{
	SET_BIT(EXTI->SWIER , Copy_U8_Line);
}
void EXTI_Void_SetCallBack(void(*Copy_ptr)(void),u8 Copy_U8_Line)
{
	EXTI_callBack[Copy_U8_Line] = Copy_ptr;
}

void EXTI0_IRQHandler(void)
{
	EXTI_callBack[0]();

	/* To clear pending bit */
	SET_BIT(EXTI->PR,0);

}
void EXTI1_IRQHandler(void)
{
   EXTI_callBack[1]();

	/* To clear pending bit */
	SET_BIT(EXTI->PR,0);


}
void EXTI5_IRQHandler(void)
{
   EXTI_callBack[4]();

	/* To clear pending bit */
	SET_BIT(EXTI->PR,0);


}



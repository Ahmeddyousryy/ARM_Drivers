/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  1 Aug 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SWITCH_interface.h"
#include "SWITCH_config.h"
#include "SWITCH_private.h"

void SWITCH_Void_SwitchInit(u8 Copy_U8_Switch)
{
	switch (Copy_U8_Switch)
	{
	case SWITCH1 : GPIO_Void_SetPinDirection(SWITCH_1_PORT,SWITCH_1_PIN,GPIO_INPUT_PULL_UP_DOWN);
                    GPIO_Void_SetPinValue(SWITCH_1_PORT,SWITCH_1_PIN,GPIO_PIN_HIGH);        break;

	case SWITCH2 : GPIO_Void_SetPinDirection(SWITCH_2_PORT,SWITCH_2_PIN,GPIO_INPUT_PULL_UP_DOWN);
                    GPIO_Void_SetPinValue(SWITCH_2_PORT,SWITCH_2_PIN,GPIO_PIN_HIGH);        break;

	case SWITCH3 : GPIO_Void_SetPinDirection(SWITCH_3_PORT,SWITCH_3_PIN,GPIO_INPUT_PULL_UP_DOWN);
                    GPIO_Void_SetPinValue(SWITCH_3_PORT,SWITCH_3_PIN,GPIO_PIN_HIGH);        break;
	default       :                                                                         break;

	}
}
u8 SWITCH_U8_SwitchState(u8 Copy_U8_Switch)
{
   u8 Local_U8_SwitchState = 1;

   switch (Copy_U8_Switch)
   {
	case SWITCH1 : Local_U8_SwitchState = GPIO_U8_GetPinValue(SWITCH_1_PORT,SWITCH_1_PIN);  break;

	case SWITCH2 : Local_U8_SwitchState = GPIO_U8_GetPinValue(SWITCH_2_PORT,SWITCH_2_PIN);  break;

	case SWITCH3 : Local_U8_SwitchState = GPIO_U8_GetPinValue(SWITCH_3_PORT,SWITCH_3_PIN);  break;
	default       :                                                                          break;

   }

	return Local_U8_SwitchState;
}







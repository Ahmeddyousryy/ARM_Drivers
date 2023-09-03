/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  1 Aug 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

void LED_Void_RGB_LedInit(u8 Copy_U8_LED)
{
   switch(Copy_U8_LED)
   {
   case LED_RED   : GPIO_Void_SetPinDirection(LED_RED_PORT,LED_RED_PIN,GPIO_OUTPUT_10MHZ_PP);    break;

   case LED_GREEN : GPIO_Void_SetPinDirection(LED_GREEN_PORT,LED_GREEN_PIN,GPIO_OUTPUT_10MHZ_PP);break;

   case LED_BLUE  : GPIO_Void_SetPinDirection(LED_BLUE_PORT,LED_BLUE_PIN,GPIO_OUTPUT_10MHZ_PP);  break;

    default        :                                                                             break;

   }



}


void LED_Void_RGB_LedOn(u8 Copy_U8_LED)
{
	switch(Copy_U8_LED)
	{
    case LED_RED  :  GPIO_Void_SetPinValue(LED_RED_PORT,LED_RED_PIN,GPIO_PIN_HIGH);
                     GPIO_Void_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,GPIO_PIN_LOW);
                     GPIO_Void_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,GPIO_PIN_LOW);        break;

    case LED_GREEN : GPIO_Void_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,GPIO_PIN_HIGH);
                     GPIO_Void_SetPinValue(LED_RED_PORT,LED_RED_PIN,GPIO_PIN_LOW);
                     GPIO_Void_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,GPIO_PIN_LOW);        break;

    case LED_BLUE  : GPIO_Void_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,GPIO_PIN_HIGH);
                     GPIO_Void_SetPinValue(LED_RED_PORT,LED_RED_PIN,GPIO_PIN_LOW);
                     GPIO_Void_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,GPIO_PIN_LOW);      break;

    default        :                                                                        break;

    }
}
void LED_Void_RGB_LedOff(u8 Copy_U8_LED)
{
	switch(Copy_U8_LED)
	{
    case LED_RED  :  GPIO_Void_SetPinValue(LED_RED_PORT,LED_RED_PIN,GPIO_PIN_LOW);          break;

    case LED_GREEN : GPIO_Void_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,GPIO_PIN_LOW);      break;

    case LED_BLUE  : GPIO_Void_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,GPIO_PIN_LOW);        break;

    default        :                                                                        break;

    }
}

void LED_Void_RGB_LedTogg(u8 Copy_U8_LED)
{
	switch(Copy_U8_LED)
	{
    case LED_RED  :  GPIO_Void_PinToggle(LED_RED_PORT,LED_RED_PIN);                        break;

    case LED_GREEN : GPIO_Void_PinToggle(LED_GREEN_PORT,LED_GREEN_PIN);                    break;

    case LED_BLUE  : GPIO_Void_PinToggle(LED_BLUE_PORT,LED_BLUE_PIN);                      break;

    default        :                                                                       break;

    }
}




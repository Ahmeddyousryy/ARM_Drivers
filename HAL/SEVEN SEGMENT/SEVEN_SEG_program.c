/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  1 Aug 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SEVEN_SEG_interface.h"
#include "SEVEN_SEG_config.h"
#include "SEVEN_SEG_private.h"

void delay_1_ms(void);

void SEVEN_SEG_Void_SevenSegInit(void)
{
	GPIO_Void_SetPinDirection(SEVEN_SEG_A_PORT,SEVEN_SEG_A_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(SEVEN_SEG_B_PORT,SEVEN_SEG_B_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(SEVEN_SEG_C_PORT,SEVEN_SEG_C_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(SEVEN_SEG_D_PORT,SEVEN_SEG_D_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(SEVEN_SEG_E_PORT,SEVEN_SEG_E_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(SEVEN_SEG_F_PORT,SEVEN_SEG_F_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(SEVEN_SEG_G_PORT,SEVEN_SEG_G_PIN,GPIO_OUTPUT_10MHZ_PP);

	GPIO_Void_SetPinDirection(SEVEN_SEG_COM1_PORT,SEVEN_SEG_COM1_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(SEVEN_SEG_COM2_PORT,SEVEN_SEG_COM2_PIN,GPIO_OUTPUT_10MHZ_PP);
}
void SEVEN_SEG_Void_SevenSegDisplay1(u8 Copy_U8_Number)
{
	  u8 Local_U8_NumArr [10] = {64 , 121 , 36 , 48 , 25 , 18 , 2 , 120 , 0 , 16}; // Number Decoder

	   GPIO_Void_SetPinValue(SEVEN_SEG_A_PORT,SEVEN_SEG_A_PIN,GET_BIT(Local_U8_NumArr[Copy_U8_Number],0));
	   GPIO_Void_SetPinValue(SEVEN_SEG_B_PORT,SEVEN_SEG_B_PIN,GET_BIT(Local_U8_NumArr[Copy_U8_Number],1));
	   GPIO_Void_SetPinValue(SEVEN_SEG_C_PORT,SEVEN_SEG_C_PIN,GET_BIT(Local_U8_NumArr[Copy_U8_Number],2));
	   GPIO_Void_SetPinValue(SEVEN_SEG_D_PORT,SEVEN_SEG_D_PIN,GET_BIT(Local_U8_NumArr[Copy_U8_Number],3));
	   GPIO_Void_SetPinValue(SEVEN_SEG_E_PORT,SEVEN_SEG_E_PIN,GET_BIT(Local_U8_NumArr[Copy_U8_Number],4));
	   GPIO_Void_SetPinValue(SEVEN_SEG_F_PORT,SEVEN_SEG_F_PIN,GET_BIT(Local_U8_NumArr[Copy_U8_Number],5));
	   GPIO_Void_SetPinValue(SEVEN_SEG_G_PORT,SEVEN_SEG_G_PIN,GET_BIT(Local_U8_NumArr[Copy_U8_Number],6));

	   GPIO_Void_SetPinValue(SEVEN_SEG_COM1_PORT,SEVEN_SEG_COM2_PIN,GPIO_PIN_HIGH);
}

void SEVEN_SEG_Void_SevenSegDisplay2(u8 Copy_U8_Number)
{
	u8 Local_U8_Tens = Copy_U8_Number / 10 ;
	u8 Local_U8_Digit = Copy_U8_Number % 10 ;
	u16 Local_U16_Counter ;

    u8 Local_U8_NumArr [10] = {64 , 121 , 36 , 48 , 25 , 18 , 2 , 120 , 0 , 16}; // Number Decoder



    for(Local_U16_Counter = 0 ; Local_U16_Counter <300 ; Local_U16_Counter++)
    {
   GPIO_Void_SetPinValue(SEVEN_SEG_A_PORT,SEVEN_SEG_A_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Tens],0));
   GPIO_Void_SetPinValue(SEVEN_SEG_B_PORT,SEVEN_SEG_B_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Tens],1));
   GPIO_Void_SetPinValue(SEVEN_SEG_C_PORT,SEVEN_SEG_C_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Tens],2));
   GPIO_Void_SetPinValue(SEVEN_SEG_D_PORT,SEVEN_SEG_D_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Tens],3));
   GPIO_Void_SetPinValue(SEVEN_SEG_E_PORT,SEVEN_SEG_E_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Tens],4));
   GPIO_Void_SetPinValue(SEVEN_SEG_F_PORT,SEVEN_SEG_F_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Tens],5));
   GPIO_Void_SetPinValue(SEVEN_SEG_G_PORT,SEVEN_SEG_G_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Tens],6));

   GPIO_Void_SetPinValue(SEVEN_SEG_COM1_PORT,SEVEN_SEG_COM1_PIN,GPIO_PIN_HIGH);
   delay_1_ms();
   GPIO_Void_SetPinValue(SEVEN_SEG_COM1_PORT,SEVEN_SEG_COM1_PIN,GPIO_PIN_LOW);


   GPIO_Void_SetPinValue(SEVEN_SEG_A_PORT,SEVEN_SEG_A_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Digit],0));
   GPIO_Void_SetPinValue(SEVEN_SEG_B_PORT,SEVEN_SEG_B_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Digit],1));
   GPIO_Void_SetPinValue(SEVEN_SEG_C_PORT,SEVEN_SEG_C_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Digit],2));
   GPIO_Void_SetPinValue(SEVEN_SEG_D_PORT,SEVEN_SEG_D_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Digit],3));
   GPIO_Void_SetPinValue(SEVEN_SEG_E_PORT,SEVEN_SEG_E_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Digit],4));
   GPIO_Void_SetPinValue(SEVEN_SEG_F_PORT,SEVEN_SEG_F_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Digit],5));
   GPIO_Void_SetPinValue(SEVEN_SEG_G_PORT,SEVEN_SEG_G_PIN,GET_BIT(Local_U8_NumArr[Local_U8_Digit],6));

   GPIO_Void_SetPinValue(SEVEN_SEG_COM2_PORT,SEVEN_SEG_COM2_PIN,GPIO_PIN_HIGH);
   delay_1_ms();
   GPIO_Void_SetPinValue(SEVEN_SEG_COM2_PORT,SEVEN_SEG_COM2_PIN,GPIO_PIN_LOW);


    }
}
void delay_1_ms(void)
{
  volatile u32 i;
  for(i=0; i<1000; ++i) {
    // Adjust this loop count to achieve the desired delay
  }
}


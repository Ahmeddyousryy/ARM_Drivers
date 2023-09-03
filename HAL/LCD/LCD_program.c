/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  2 Aug 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "string.h"

#include "GPIO_interface.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

void delay_1ms(void);
void delay_5ms(void);


void LCD_Void_LcdInit(void)
{
#if   LCD_MODE == LCD_4_BIT_MODE
   // To Select LCD Pins as Output Push Pull
	GPIO_Void_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LCD_RW_PORT,LCD_RW_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LCD_EN_PORT,LCD_EN_PIN,GPIO_OUTPUT_10MHZ_PP);

	GPIO_Void_SetPinDirection(LCD_D4_PORT,LCD_D4_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LCD_D5_PORT,LCD_D5_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LCD_D6_PORT,LCD_D6_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LCD_D7_PORT,LCD_D7_PIN,GPIO_OUTPUT_10MHZ_PP);

	/*                LCD Commands                          */

	LCD_Void_LcdWriteCommand(0x28);   // to select 4_BIT_MODE
	LCD_Void_LcdWriteCommand(0x0C);   // Display on command
	LCD_Void_LcdWriteCommand(0x01);   // to clear display

	LCD_Void_LcdWriteCommand(0x33);
	LCD_Void_LcdWriteCommand(0x32);
	LCD_Void_LcdWriteCommand(0x02);   // Return home command


#elif LCD_MODE == LCD_8_BIT_MODE
	   // To Select LCD Pins as Output Push Pull
		GPIO_Void_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,GPIO_OUTPUT_10MHZ_PP);
		GPIO_Void_SetPinDirection(LCD_RW_PORT,LCD_RW_PIN,GPIO_OUTPUT_10MHZ_PP);
		GPIO_Void_SetPinDirection(LCD_EN_PORT,LCD_EN_PIN,GPIO_OUTPUT_10MHZ_PP);

		GPIO_Void_SetPinDirection(LCD_D0_PORT,LCD_D0_PIN,GPIO_OUTPUT_10MHZ_PP);
		GPIO_Void_SetPinDirection(LCD_D1_PORT,LCD_D1_PIN,GPIO_OUTPUT_10MHZ_PP);
		GPIO_Void_SetPinDirection(LCD_D2_PORT,LCD_D2_PIN,GPIO_OUTPUT_10MHZ_PP);
		GPIO_Void_SetPinDirection(LCD_D3_PORT,LCD_D3_PIN,GPIO_OUTPUT_10MHZ_PP);
		GPIO_Void_SetPinDirection(LCD_D4_PORT,LCD_D4_PIN,GPIO_OUTPUT_10MHZ_PP);
		GPIO_Void_SetPinDirection(LCD_D5_PORT,LCD_D5_PIN,GPIO_OUTPUT_10MHZ_PP);
		GPIO_Void_SetPinDirection(LCD_D6_PORT,LCD_D6_PIN,GPIO_OUTPUT_10MHZ_PP);
		GPIO_Void_SetPinDirection(LCD_D7_PORT,LCD_D7_PIN,GPIO_OUTPUT_10MHZ_PP);

		/*                LCD Commands                          */

		LCD_Void_LcdWriteCommand(0x38);   // to select 8_BIT_MODE
		LCD_Void_LcdWriteCommand(0x0C);   // Display On Command
		LCD_Void_LcdWriteCommand(0x01);   // to clear display
		LCD_Void_LcdWriteCommand(0x02);   // Return home command


#endif


}


void LCD_Void_LcdWriteCharacter(u8 Copy_U8_Char)
{
	 GPIO_Void_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,GPIO_PIN_LOW); // To select write mode
	 GPIO_Void_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,GPIO_PIN_HIGH); // To select send data mode

#if   LCD_MODE == LCD_4_BIT_MODE

	 // To send upper 4 bits of number
	 GPIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Char,4));
	 GPIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Char,5));
	 GPIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Char,6));
	 GPIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Char,7));

	 GPIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_HIGH);
	 delay_1ms();
	 GPIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_LOW);

	 // To send lower 4 bits of number
	 GPIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Char,0));
	 GPIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Char,1));
	 GPIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Char,2));
	 GPIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Char,3));

	 GPIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_HIGH);
	 delay_1ms();
	 GPIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_LOW);


#elif LCD_MODE == LCD_8_BIT_MODE
	 GPIO_Void_SetPinValue(LCD_D0_PORT,LCD_D0_PIN,GET_BIT(Copy_U8_Char,0));
	 GPIO_Void_SetPinValue(LCD_D1_PORT,LCD_D1_PIN,GET_BIT(Copy_U8_Char,1));
	 GPIO_Void_SetPinValue(LCD_D2_PORT,LCD_D2_PIN,GET_BIT(Copy_U8_Char,2));
	 GPIO_Void_SetPinValue(LCD_D3_PORT,LCD_D3_PIN,GET_BIT(Copy_U8_Char,3));
	 GPIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Char,4));
	 GPIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Char,5));
	 GPIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Char,6));
	 GPIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Char,7));
#endif

  /*                            5ms delay                  */
	 delay_5ms();

}

void LCD_Void_LcdWriteCommand(u8 Copy_U8_Command)
{
	 GPIO_Void_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,GPIO_PIN_LOW); // To select write mode
	 GPIO_Void_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,GPIO_PIN_LOW); // To select send command mode

#if   LCD_MODE == LCD_4_BIT_MODE

	 // To send upper 4 bits of number
	 GPIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Command,4));
	 GPIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Command,5));
	 GPIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Command,6));
	 GPIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Command,7));

	 GPIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_HIGH);
	 delay_1ms();
	 GPIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_LOW);

	 // To send lower 4 bits of number
	 GPIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Command,0));
	 GPIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Command,1));
	 GPIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Command,2));
	 GPIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Command,3));

	 GPIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_HIGH);
	 delay_1ms();
	 GPIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_LOW);



#elif LCD_MODE == LCD_8_BIT_MODE
	 GPIO_Void_SetPinValue(LCD_D0_PORT,LCD_D0_PIN,GET_BIT(Copy_U8_Command,0));
	 GPIO_Void_SetPinValue(LCD_D1_PORT,LCD_D1_PIN,GET_BIT(Copy_U8_Command,1));
	 GPIO_Void_SetPinValue(LCD_D2_PORT,LCD_D2_PIN,GET_BIT(Copy_U8_Command,2));
	 GPIO_Void_SetPinValue(LCD_D3_PORT,LCD_D3_PIN,GET_BIT(Copy_U8_Command,3));
	 GPIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Command,4));
	 GPIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Command,5));
	 GPIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Command,6));
	 GPIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Command,7));
#endif

	  /*                            5ms delay                       */
	 delay_5ms();

}

void LCD_Void_LcdWriteString(u8* Copy_U8_String)
{
   while(*Copy_U8_String != '\0')
   {
	   LCD_Void_LcdWriteCharacter(*Copy_U8_String);
	   Copy_U8_String++;
   }

}
void LCD_Void_LcdWriteNumber(s32 Copy_U23_Number)
{

   u8 Local_U8_NumDigit = 1;
   u8 Local_U8_NumberArr[10] ={0};
   u8 Local_U8_Digits = 0;
   s32 Local_U32_Tens;

   if(Copy_U23_Number<0)               // If number is negative
   {
	  LCD_Void_LcdWriteCharacter('-');
	  Copy_U23_Number = Copy_U23_Number * -1;
   }
      Local_U32_Tens = Copy_U23_Number;
   while((Copy_U23_Number /= 10) !=0)
   {
	   Local_U8_NumDigit++;
   }
    for(s8 i = Local_U8_NumDigit-1 ; i >= 0 ; i--)
    {
    	Local_U8_Digits = Local_U32_Tens % 10 ;
    	Local_U8_NumberArr[i] = Local_U8_Digits;
    	Local_U32_Tens = Local_U32_Tens / 10;

    }

    for(u8 i = 0 ; i<Local_U8_NumDigit ; i++)
    {
        LCD_Void_LcdWriteCharacter(Local_U8_NumberArr[i]+'0');


    }

}

void LCD_Void_LcdClear(void)
{
	LCD_Void_LcdWriteCommand(0x01);
}


void delay_1ms(void)
{
  volatile u32 i;
  for(i=0; i<600; ++i) {
    // Adjust this loop count to achieve the desired delay
  }
}
void delay_5ms(void)
{
  volatile u32 i; volatile u8 j ;
 for(j=0;j<5;j++)
 {
  for(i=0; i<600; ++i) {
    // Adjust this loop count to achieve the desired delay
  }
 }
}

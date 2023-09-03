/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  3 Aug 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

void delay_5ms(void);

void KEYPAD_Void_KeyPadInit()
{
	// To set row pins as output
	GPIO_Void_SetPinDirection(KEYPAD_R1_PORT, KEYPAD_R1_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(KEYPAD_R2_PORT, KEYPAD_R2_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(KEYPAD_R3_PORT, KEYPAD_R3_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(KEYPAD_R4_PORT, KEYPAD_R4_PIN,GPIO_OUTPUT_10MHZ_PP);

	// To set column pins as input pull up or down
	GPIO_Void_SetPinDirection(KEYPAD_C1_PORT, KEYPAD_C1_PIN,GPIO_INPUT_PULL_UP_DOWN);
	GPIO_Void_SetPinDirection(KEYPAD_C2_PORT, KEYPAD_C2_PIN,GPIO_INPUT_PULL_UP_DOWN);
	GPIO_Void_SetPinDirection(KEYPAD_C3_PORT, KEYPAD_C3_PIN,GPIO_INPUT_PULL_UP_DOWN);
	GPIO_Void_SetPinDirection(KEYPAD_C4_PORT, KEYPAD_C4_PIN,GPIO_INPUT_PULL_UP_DOWN);

	// To select column pins as pull up
	GPIO_Void_SetPinValue(KEYPAD_C1_PORT, KEYPAD_C1_PIN, GPIO_PIN_HIGH);
	GPIO_Void_SetPinValue(KEYPAD_C2_PORT, KEYPAD_C2_PIN, GPIO_PIN_HIGH);
	GPIO_Void_SetPinValue(KEYPAD_C3_PORT, KEYPAD_C3_PIN, GPIO_PIN_HIGH);
	GPIO_Void_SetPinValue(KEYPAD_C4_PORT, KEYPAD_C4_PIN, GPIO_PIN_HIGH);

	// To set pin rows high
	GPIO_Void_SetPinValue(KEYPAD_R1_PORT, KEYPAD_R1_PIN, GPIO_PIN_HIGH);
	GPIO_Void_SetPinValue(KEYPAD_R2_PORT, KEYPAD_R2_PIN, GPIO_PIN_HIGH);
	GPIO_Void_SetPinValue(KEYPAD_R3_PORT, KEYPAD_R3_PIN, GPIO_PIN_HIGH);
	GPIO_Void_SetPinValue(KEYPAD_R4_PORT, KEYPAD_R4_PIN, GPIO_PIN_HIGH);

}
u8 KEYPAD_U8_KeyPadRead(void)
{
	u8 Local_U8_KeyPressed = 0;
	u8 Local_U8_row;
	u8 Local_U8_col;
	u8 Local_U8_KeyPad[4][4] = {
			                   { '1', '2', '3', 'A' },
		                   	   { '4', '5', '6', 'B' },
			                   { '7', '8', '9', 'C' },
			                   { '*', '0', '#', 'D' } };

	for (Local_U8_row = 0; Local_U8_row < ROW_4; Local_U8_row++)
	{
		GPIO_Void_SetPinValue(KEYPAD_R1_PORT, KEYPAD_R1_PIN + Local_U8_row,GPIO_PIN_LOW);
		                                                    // To shift between 4 pins

		for (Local_U8_col = 0; Local_U8_col < COL_4; Local_U8_col++)
		{
			if (GPIO_U8_GetPinValue(KEYPAD_C1_PORT,KEYPAD_C1_PIN + Local_U8_col) == 0)
			{
				delay_5ms();  // To avoid bouncing effect
				if (GPIO_U8_GetPinValue(KEYPAD_C1_PORT,KEYPAD_C1_PIN + Local_U8_col) == 0)

					while (GPIO_U8_GetPinValue(KEYPAD_C1_PORT,KEYPAD_C1_PIN + Local_U8_col) == 0);

				Local_U8_KeyPressed = Local_U8_KeyPad[Local_U8_row][Local_U8_col];
				break;
			}
		}
		if (Local_U8_KeyPressed != 0)
			break;

		GPIO_Void_SetPinValue(KEYPAD_R1_PORT, KEYPAD_R1_PIN + Local_U8_row,GPIO_PIN_HIGH);

	}

	return Local_U8_KeyPressed;

}


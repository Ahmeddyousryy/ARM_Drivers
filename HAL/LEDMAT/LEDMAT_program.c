/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  29 Aug 2023                                  */
/*     Version  :  V02                                          */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "TIMER_interface.h"

#include "LEDMAT_interface.h"
#include "LEDMAT_config.h"
#include "LEDMAT_private.h"



void LEDMAT_Void_LedMatInit(void)
{
	/* To select Led Matrix row pins as Output */
	GPIO_Void_SetPinDirection(LEDMAT_ROW0_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_ROW1_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_ROW2_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_ROW3_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_ROW4_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_ROW5_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_ROW6_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_ROW7_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);

	/* To select Led Matrix column pins as Output */
	GPIO_Void_SetPinDirection(LEDMAT_COL0_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_COL1_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_COL2_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_COL3_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_COL4_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_COL5_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_COL6_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(LEDMAT_COL7_PORT_PIN,GPIO_OUTPUT_10MHZ_PP);

	TIMER4_Void_InitTimer();


}

void LEDMAT_Void_LedMatShiftedDisplay(u8 * Copy_U8_DataDisplayed , u8 Copy_U8_Array)
{
	Local_U8_ArrayLength = Copy_U8_Array ;

	Local_U8_Frame = Copy_U8_DataDisplayed ;

	for(u8 i = 0 ;i<100;i++)
	{
	LEDMAT_Void_LedMatDisplay(Local_U8_Frame);
	LEDMAT_Delay(20);
	LEDMAT_Void_ShitArray();
	}

}


void LEDMAT_Void_LedMatDisplay(u8 * Copy_U8_DataDisplayed)
{

	 Local_U8_Index = 0 ;
	 Local_U8_Frame = Copy_U8_DataDisplayed ;

	 LEDMAT_Void_ColActivate(Local_U8_Index);
	 LEDMAT_Void_SetRow(Local_U8_Frame[Local_U8_Index]);

	 TIMER4_Void_SetIntervalPeriodic(10 , LEDMAT_Void_LedMatDisplayNextCol);


}

void LEDMAT_Void_LedMatDisplayNextCol()
{

	Local_U8_Index ++;

	if(Local_U8_Index == 8)
	{
		Local_U8_Index = 0;
	}
	LEDMAT_Void_ColActivate(Local_U8_Index);
	LEDMAT_Void_SetRow(Local_U8_Frame[Local_U8_Index]);

}
static void LEDMAT_Void_ColActivate(u8 Copy_U8_Col)
{
	LEDMAT_Void_DisableColumns();

	switch (Copy_U8_Col)
	{
	case 0  : GPIO_Void_SetPinValue(LEDMAT_COL0_PORT_PIN,GPIO_PIN_LOW) ;   break;
	case 1  : GPIO_Void_SetPinValue(LEDMAT_COL1_PORT_PIN,GPIO_PIN_LOW) ;   break;
	case 2  : GPIO_Void_SetPinValue(LEDMAT_COL2_PORT_PIN,GPIO_PIN_LOW) ;   break;
	case 3  : GPIO_Void_SetPinValue(LEDMAT_COL3_PORT_PIN,GPIO_PIN_LOW) ;   break;
	case 4  : GPIO_Void_SetPinValue(LEDMAT_COL4_PORT_PIN,GPIO_PIN_LOW) ;   break;
	case 5  : GPIO_Void_SetPinValue(LEDMAT_COL5_PORT_PIN,GPIO_PIN_LOW) ;   break;
	case 6  : GPIO_Void_SetPinValue(LEDMAT_COL6_PORT_PIN,GPIO_PIN_LOW) ;   break;
	case 7  : GPIO_Void_SetPinValue(LEDMAT_COL7_PORT_PIN,GPIO_PIN_LOW) ;   break;
	default :                                                              break;
	}
}
static void LEDMAT_Void_SetRow(u8 Copy_U8_Data)
{
	  GPIO_Void_SetPinValue(LEDMAT_ROW0_PORT_PIN,GET_BIT(Copy_U8_Data,0));
	  GPIO_Void_SetPinValue(LEDMAT_ROW1_PORT_PIN,GET_BIT(Copy_U8_Data,1));
	  GPIO_Void_SetPinValue(LEDMAT_ROW2_PORT_PIN,GET_BIT(Copy_U8_Data,2));
	  GPIO_Void_SetPinValue(LEDMAT_ROW3_PORT_PIN,GET_BIT(Copy_U8_Data,3));
	  GPIO_Void_SetPinValue(LEDMAT_ROW4_PORT_PIN,GET_BIT(Copy_U8_Data,4));
	  GPIO_Void_SetPinValue(LEDMAT_ROW5_PORT_PIN,GET_BIT(Copy_U8_Data,5));
	  GPIO_Void_SetPinValue(LEDMAT_ROW6_PORT_PIN,GET_BIT(Copy_U8_Data,6));
	  GPIO_Void_SetPinValue(LEDMAT_ROW7_PORT_PIN,GET_BIT(Copy_U8_Data,7));


}
static void LEDMAT_Void_DisableColumns(void)
{
	  /* Disable all columns with high value as they are connected to -ve of LED */
	  GPIO_Void_SetPinValue(LEDMAT_COL0_PORT_PIN,GPIO_PIN_HIGH);
	  GPIO_Void_SetPinValue(LEDMAT_COL1_PORT_PIN,GPIO_PIN_HIGH);
	  GPIO_Void_SetPinValue(LEDMAT_COL2_PORT_PIN,GPIO_PIN_HIGH);
	  GPIO_Void_SetPinValue(LEDMAT_COL3_PORT_PIN,GPIO_PIN_HIGH);
	  GPIO_Void_SetPinValue(LEDMAT_COL4_PORT_PIN,GPIO_PIN_HIGH);
	  GPIO_Void_SetPinValue(LEDMAT_COL5_PORT_PIN,GPIO_PIN_HIGH);
	  GPIO_Void_SetPinValue(LEDMAT_COL6_PORT_PIN,GPIO_PIN_HIGH);
	  GPIO_Void_SetPinValue(LEDMAT_COL7_PORT_PIN,GPIO_PIN_HIGH);

}

void LEDMAT_Void_ShitArray()
{
  u8 Local_U8_Temp;

  Local_U8_Temp = Local_U8_Frame[0];

  for(u8 i=0 ; i<Local_U8_ArrayLength ; i++)
  {
	  Local_U8_Frame[i] = Local_U8_Frame[i+1];
  }
     Local_U8_Frame[Local_U8_ArrayLength -1] = Local_U8_Temp;
}

void LEDMAT_Delay(u8 Copy_U8_Speed)
{
	 for(u32 i=0 ; i<Copy_U8_Speed;i++)
	 {
		 for(u32 j=0 ; j<10000;j++)
		 {
         asm("NOP");
		 }
	 }
}



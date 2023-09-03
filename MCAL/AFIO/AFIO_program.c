/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  15 Aug 2023                                  */
/*     Version  :  V01                                          */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"


void AFIO_Void_ExtiConfiguration(u8 Copy_U8_Line,u8 Copy_U8_Port)
{
	u8 Local_U8_Index = 0 ;

	if(Copy_U8_Line <= 3)
	{

	}
	else if(Copy_U8_Line <= 7)
	{
		Local_U8_Index = 1 ;
		Copy_U8_Line = Copy_U8_Line - 4 ;
	}
	else if(Copy_U8_Line <= 11)
	{
		Local_U8_Index = 2 ;
		Copy_U8_Line = Copy_U8_Line - 8 ;
	}
	else if(Copy_U8_Line <= 15)
	{
		Local_U8_Index = 3 ;
		Copy_U8_Line = Copy_U8_Line - 12 ;
	}
	else
	{
		/*              Return Error              */
	}

	AFIO->EXTICR[Local_U8_Index] &= ~ ((0b1111)<<(Copy_U8_Line * 4));
	AFIO->EXTICR[Local_U8_Index] |=   ((Copy_U8_Port)<<(Copy_U8_Line * 4));

}



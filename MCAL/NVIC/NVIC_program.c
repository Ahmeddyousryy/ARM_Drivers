/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  13 Aug 2023                                  */
/*     Version  :  V02                                          */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "NVIC_interface.h"
#include "NVIC_config.h"
#include "NVIC_private.h"


void NVIC_Void_EnableInterrupt(u8 Copy_U8_Interrupt)
{
	if(Copy_U8_Interrupt<=31)
	{
		NVIC_ISER0 = (1 << Copy_U8_Interrupt);
	}
	else if (Copy_U8_Interrupt<=59)
	{
		Copy_U8_Interrupt = Copy_U8_Interrupt - 32 ;
		NVIC_ISER1 = (1 << Copy_U8_Interrupt);
	}
	else
	{
		/*      Return Error      */
	}

}
void NVIC_Void_DisableInterrupt(u8 Copy_U8_Interrupt)
{
	if(Copy_U8_Interrupt<=31)
	{
		NVIC_ICER0 = (1 << Copy_U8_Interrupt);
	}
	else if (Copy_U8_Interrupt<=59)
	{
		Copy_U8_Interrupt = Copy_U8_Interrupt - 32 ;
		NVIC_ICER1 = (1 << Copy_U8_Interrupt);
	}
	else
	{
		/*      Return Error      */
	}


}
void NVIC_Void_SetPending(u8 Copy_U8_Interrupt)
{
	if(Copy_U8_Interrupt<=31)
	{
		NVIC_ISPR0 = (1 << Copy_U8_Interrupt);
	}
	else if (Copy_U8_Interrupt<=59)
	{
		Copy_U8_Interrupt = Copy_U8_Interrupt - 32 ;
		NVIC_ISPR1 = (1 << Copy_U8_Interrupt);
	}
	else
	{
		/*      Return Error      */
	}

}
void NVIC_Void_ClearPending(u8 Copy_U8_Interrupt)
{
	if(Copy_U8_Interrupt<=31)
	{
		NVIC_ICPR0 = (1 << Copy_U8_Interrupt);
	}
	else if (Copy_U8_Interrupt<=59)
	{
		Copy_U8_Interrupt = Copy_U8_Interrupt - 32 ;
		NVIC_ICPR1 = (1 << Copy_U8_Interrupt);
	}
	else
	{
		/*      Return Error      */
	}

}

u8 NVIC_U8_GetActiveFlag(u8 Copy_U8_Interrupt)
{
	u8 Local_U8_ActiveFlag = 0;

	if(Copy_U8_Interrupt<=31)
	{
		Local_U8_ActiveFlag = GET_BIT(NVIC_IABR0,Copy_U8_Interrupt);
	}
	else if (Copy_U8_Interrupt<=59)
	{
		Copy_U8_Interrupt = Copy_U8_Interrupt - 32 ;
		Local_U8_ActiveFlag = GET_BIT(NVIC_IABR1,Copy_U8_Interrupt);
	}
	else
	{
		/*      Return Error      */
	}
	return Local_U8_ActiveFlag ;

}
void NVIC_Void_SetPriority(u8 Copy_U8_Interrupt,u8 Copy_U8_Group,u8 Copy_U8_Sub)
{

	u8 Local_U8_Priority = Copy_U8_Sub | (Copy_U8_Group<<((NVIC_GROUP_SUB - 0x05FA0300)/256));

	NVIC_IPR[Copy_U8_Interrupt] = Local_U8_Priority << 4;

	SCB_AIRCR = NVIC_GROUP_SUB ;
}



/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  9 Sup 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


void DMA_Void_InitDMA(DMA_Config * ChannelConfig)
{
	/* Disable Channel  */
	CLR_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR,0);

  switch(ChannelConfig->InterruptSource)
  {
  case TRANSFER_COMPLETE       : SET_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR , 1);  break ;
  case HALF_TRANSFER_COMPLETE  : SET_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR , 2);  break ;
  case TRANSFER_ERROR          : SET_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR , 3);  break ;
  default                      :                                                           break ;
  }

  switch(ChannelConfig->DataDireciton)
  {
  case READ_FROM_PERIPHERAL    : CLR_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR ,4);   break ;
  case READ_FROM_MEMORY        : SET_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR ,4);   break ;
  default                      :                                                           break ;
  }

  switch(ChannelConfig->CircularMode)
  {
  case CIRCULAR_DISABLE  : CLR_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR ,5);         break ;
  case CIRCULAR_ENABLE   : SET_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR ,5);         break ;
  default                :                                                                 break ;
  }

  switch(ChannelConfig->PINC)
  {
  case PINC_DISABLE  : CLR_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR ,6);             break ;
  case PINC_ENABLE   : SET_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR ,6);             break ;
  default                :                                                                 break ;
  }
  switch(ChannelConfig->MINC)
  {
  case MINC_DISABLE  : CLR_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR ,7);             break ;
  case MINC_ENABLE   : SET_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR ,7);             break ;
  default            :                                                                     break ;
  }
  switch(ChannelConfig->PerSize)
  {
  case PER_SIZE_8    : DMA->Channel[ChannelConfig->ChannelID].CCR &=~ (0b11 << 8) ;
                       DMA->Channel[ChannelConfig->ChannelID].CCR |=  (0b00 << 8) ;        break ;

  case PER_SIZE_16    : DMA->Channel[ChannelConfig->ChannelID].CCR &=~ (0b11 << 8) ;
                        DMA->Channel[ChannelConfig->ChannelID].CCR |=  (0b01 << 8) ;       break ;

  case PER_SIZE_32    : DMA->Channel[ChannelConfig->ChannelID].CCR &=~ (0b11 << 8) ;
                        DMA->Channel[ChannelConfig->ChannelID].CCR |=  (0b10 << 8) ;       break ;
  default             :                                                                    break ;

  }
  switch(ChannelConfig->MemSize)
  {
  case MEM_SIZE_8    :  DMA->Channel[ChannelConfig->ChannelID].CCR &=~ (0b11 << 10) ;
                        DMA->Channel[ChannelConfig->ChannelID].CCR |=  (0b00 << 10) ;      break ;

  case MEM_SIZE_16    : DMA->Channel[ChannelConfig->ChannelID].CCR &=~ (0b11 << 10) ;
                        DMA->Channel[ChannelConfig->ChannelID].CCR |=  (0b01 << 10) ;      break ;

  case MEM_SIZE_32    : DMA->Channel[ChannelConfig->ChannelID].CCR &=~ (0b11 << 10) ;
                        DMA->Channel[ChannelConfig->ChannelID].CCR |=  (0b10 << 10) ;      break ;
  default             :                                                                    break ;

  }

 switch(ChannelConfig->ChannelPriority)
 {
  case LOW            : DMA->Channel[ChannelConfig->ChannelID].CCR &=~ (0b11 << 12) ;
                        DMA->Channel[ChannelConfig->ChannelID].CCR |=  (0b00 << 12) ;      break ;

  case MEDIUM         : DMA->Channel[ChannelConfig->ChannelID].CCR &=~ (0b11 << 12) ;
                        DMA->Channel[ChannelConfig->ChannelID].CCR |=  (0b01 << 12) ;      break ;

  case HIGH           : DMA->Channel[ChannelConfig->ChannelID].CCR &=~ (0b11 << 12) ;
                        DMA->Channel[ChannelConfig->ChannelID].CCR |=  (0b10 << 12) ;      break ;

  case VERY_HIGH      : DMA->Channel[ChannelConfig->ChannelID].CCR &=~ (0b11 << 12) ;
                        DMA->Channel[ChannelConfig->ChannelID].CCR |=  (0b11 << 12) ;      break ;
  default             :                                                                    break ;

 }

 switch(ChannelConfig->MemToMemMode)
 {
  case MEM_TO_MEM_DISABLE   :   CLR_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR ,14);   break ;
  case MEM_TO_MEM_ENABLE    :   SET_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR ,14);   break ;
  default                   :                                                              break ;
 }


}
void DMA_Void_StartTransfer(DMA_Config * ChannelConfig, u32* Copy_U32_Source , u32* Copy_U32_Destination , u16 Copy_U16_BlockLength)
{
	/* Disable Channel  */
	CLR_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR,0);

    if(ChannelConfig->MemToMemMode == MEM_TO_MEM_ENABLE)
    {

    	DMA->Channel[ChannelConfig->ChannelID].CPAR = Copy_U32_Source ;
        DMA->Channel[ChannelConfig->ChannelID].CMAR = Copy_U32_Destination ;

    }
    else
    {
    	if(ChannelConfig->DataDireciton == READ_FROM_PERIPHERAL)
    	{
          DMA->Channel[ChannelConfig->ChannelID].CPAR = Copy_U32_Source ;
          DMA->Channel[ChannelConfig->ChannelID].CMAR = Copy_U32_Destination ;

    	}
    	else
    	{
          DMA->Channel[ChannelConfig->ChannelID].CPAR = Copy_U32_Destination ;
          DMA->Channel[ChannelConfig->ChannelID].CMAR = Copy_U32_Source ;


    	}
    }

    DMA->Channel[ChannelConfig->ChannelID].CNDTR = Copy_U16_BlockLength ;

    /* Enable Channel */
    SET_BIT(DMA->Channel[ChannelConfig->ChannelID].CCR,0);

}
void DMA1_Channel1_IRQHandler(void)
{
	/*Clear Interrupt flag*/

	DMA->IFCR=1<<0;		/*Clear Global Interrupt flag of channel1*/
	DMA->IFCR=1<<1;		/*Clear transfer complete Interrupt flag of channel1*/
}

/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  13 Aug 2023                                  */
/*     Version  :  V02                                          */
/****************************************************************/

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_


void NVIC_Void_EnableInterrupt(u8);
void NVIC_Void_DisableInterrupt(u8);
void NVIC_Void_SetPending(u8);
void NVIC_Void_ClearPending(u8);
u8 NVIC_U8_GetActiveFlag(u8);
void NVIC_Void_SetPriority(u8,u8,u8);
#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */

/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  15 Aug 2023                                  */
/*     Version  :  V01                                          */
/****************************************************************/


#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/*                                  INTERRUPT MODES                                     */
#define RISING_EDGE                                   1
#define FALLING_EDGE                                  2
#define ON_CHANGE                                     3



void EXTI_Void_ExtiInit(u8,u8);
void EXTI_Void_ExtiEnable(u8);
void EXTI_Void_ExtiDisable(u8);
void EXTI_Void_SWTrigger(u8);
void EXTI_Void_SetCallBack(void(*)(void),u8);



#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */

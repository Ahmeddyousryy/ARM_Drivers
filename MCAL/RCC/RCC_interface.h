/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  27 Jul 2023                                  */
/*     Version  :  V01                                          */
/****************************************************************/

#ifndef RCC_RCC_INTERFACE_H_
#define RCC_RCC_INTERFACE_H_


#define RCC_AHB                      0
#define RCC_APB1                     1
#define RCC_APB2                     2



void RCC_Void_EnableClock(u8,u8);
void RCC_Void_DisableClock(u8,u8);
void RCC_Void_InitClockSystem(void);



#endif /* RCC_RCC_INTERFACE_H_ */

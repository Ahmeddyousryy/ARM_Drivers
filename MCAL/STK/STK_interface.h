/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  22 Aug 2023                                  */
/*     Version  :  V01                                          */
/****************************************************************/

#ifndef MCAL_STK_STK_INTERFACE_H_
#define MCAL_STK_STK_INTERFACE_H_

void STK_Void_STKInit(void);
void STK_Void_STKSetBusyWait(u32);
void STK_Void_STKSetIntervalSingle(u32 ,void (*)(void));
void STK_Void_STKSetIntervalPeriodic(u32,void (*)(void));
u32 STK_U32_STKGetElapsedTime(void);
u32 STK_U32_STKGetRemainingTime();
void STK_U32_STKStopTimer();




#endif /* MCAL_STK_STK_INTERFACE_H_ */

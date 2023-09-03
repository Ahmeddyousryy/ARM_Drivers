/**********************************************************/
/* Author    :  Ahmed Yousry                              */
/* Date      :  29 Aug 2023                               */
/* Version   :  V01                                       */
/**********************************************************/
#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

void TIMER2_Void_PwmInit(u8);
void TIMER2_Void_PwmSetDutyCycle(u8,u32);
void TIMER2_Void_PwmStart();

#define TIMER2_CHANNEL1                            1
#define TIMER2_CHANNEL2                            2
#define TIMER2_CHANNEL3                            3




#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */

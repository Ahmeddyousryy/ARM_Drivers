/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  15 Aug 2023                                  */
/*     Version  :  V01                                          */
/****************************************************************/

#ifndef MCAL_AFIO_AFIO_INTERFACE_H_
#define MCAL_AFIO_AFIO_INTERFACE_H_
/*                            EXTI CONFIGURATIONS                      */
#define AFIO_EXTICR_PORTA                     0b0000
#define AFIO_EXTICR_PORTB                     0b0001
#define AFIO_EXTICR_PORTC                     0b0010

void AFIO_Void_ExtiConfiguration(u8,u8);



#endif /* MCAL_AFIO_AFIO_INTERFACE_H_ */

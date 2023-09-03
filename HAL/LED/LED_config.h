/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  1 Aug 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/
#ifndef HAL_LED_LED_CONFIG_H_
#define HAL_LED_LED_CONFIG_H_

/*                        RGB LED Configurations               */
/*              Choose between 3 Ports  [ PORTA , PORTB , PORTC ]
 *              Choose between 16 Pins  [ PIN0 , PIN1 --- PIN15 ]
 */
#define LED_RED_PORT                   PORTB
#define LED_RED_PIN                    PIN0

#define LED_GREEN_PORT                 PORTB
#define LED_GREEN_PIN                  PIN3

#define LED_BLUE_PORT                  PORTB
#define LED_BLUE_PIN                   PIN1



#endif /* HAL_LED_LED_CONFIG_H_ */

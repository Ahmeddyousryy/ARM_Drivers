/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  1 Aug 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/
#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#define LED_RED                           1
#define LED_GREEN                         2
#define LED_BLUE                          3


void LED_Void_RGB_LedInit(u8);
void LED_Void_RGB_LedOn(u8);
void LED_Void_RGB_LedOff(u8);
void LED_Void_RGB_LedTogg(u8);



#endif /* HAL_LED_LED_INTERFACE_H_ */

/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  3 Aug 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

/*                    KeyPad configurations                    */

/*       Choose between 3 Ports [ PORTA , PORTB ]
 *       Note : Row pins or Column pins must connect to the same port
 */
#define KEYPAD_R1_PORT                     PORTB
#define KEYPAD_R2_PORT                     PORTB
#define KEYPAD_R3_PORT                     PORTB
#define KEYPAD_R4_PORT                     PORTB

#define KEYPAD_C1_PORT                     PORTB
#define KEYPAD_C2_PORT                     PORTB
#define KEYPAD_C3_PORT                     PORTB
#define KEYPAD_C4_PORT                     PORTB

/*        Choose between 16 Pins [ PIN0 , PIN1  --- PIN15 ]
 *        Note : Row pins or Column pins must connect to consecutive pins
 */
#define  KEYPAD_R1_PIN                     PIN5
#define  KEYPAD_R2_PIN                     PIN6
#define  KEYPAD_R3_PIN                     PIN7
#define  KEYPAD_R4_PIN                     PIN8

#define  KEYPAD_C1_PIN                     PIN9
#define  KEYPAD_C2_PIN                     PIN10
#define  KEYPAD_C3_PIN                     PIN11
#define  KEYPAD_C4_PIN                     PIN12

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */

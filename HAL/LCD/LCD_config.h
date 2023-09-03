/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  2 Aug 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/
#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_


/*                         LCD MODE                   */
/*       Choose between 2 Modes  [ LCD_4_BIT_MODE - LCD_8_BIT_MODE ]
 */

#define LCD_MODE                                 LCD_4_BIT_MODE

/*                LCD Pins Configurations             */
/*       Choose between 3 Ports [ PORTA , PORTB , PORTC ]
 */

#define LCD_RS_PORT                             PORTA
#define LCD_RW_PORT                             PORTA
#define LCD_EN_PORT                             PORTA

#define LCD_D0_PORT                             PORTB
#define LCD_D1_PORT                             PORTB
#define LCD_D2_PORT                             PORTB
#define LCD_D3_PORT                             PORTB

#define LCD_D4_PORT                             PORTA
#define LCD_D5_PORT                             PORTA
#define LCD_D6_PORT                             PORTA
#define LCD_D7_PORT                             PORTA

/*        Choose between 16 Pins [ PIN0 , PIN1  --- PIN15 ]
 */

#define LCD_RS_PIN                              PIN0
#define LCD_RW_PIN                              PIN1
#define LCD_EN_PIN                              PIN2

#define LCD_D0_PIN                              PIN0
#define LCD_D1_PIN                              PIN1
#define LCD_D2_PIN                              PIN2
#define LCD_D3_PIN                              PIN3

#define LCD_D4_PIN                              PIN8
#define LCD_D5_PIN                              PIN9
#define LCD_D6_PIN                              PIN10
#define LCD_D7_PIN                              PIN11


#endif /* HAL_LCD_LCD_CONFIG_H_ */

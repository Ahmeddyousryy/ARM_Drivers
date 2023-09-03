/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  29 Aug 2023                                  */
/*     Version  :  V02                                          */
/****************************************************************/

#ifndef HAL_LEDMAT_LEDMAT_CONFIG_H_
#define HAL_LEDMAT_LEDMAT_CONFIG_H_

/*                       LED MATRIX PINS CONFIGURATION                      */
/*      Choose between  [ PORTA , PORTB , PORTC ]
 *                      [ PIN0 , PIN1 --> PIN15 ]
 *      Note :  Select pairs of port and pin
 */

#define LEDMAT_ROW0_PORT_PIN                     PORTA,PIN10
#define LEDMAT_ROW1_PORT_PIN                     PORTA,PIN1
#define LEDMAT_ROW2_PORT_PIN                     PORTA,PIN2
#define LEDMAT_ROW3_PORT_PIN                     PORTA,PIN5
#define LEDMAT_ROW4_PORT_PIN                     PORTA,PIN6
#define LEDMAT_ROW5_PORT_PIN                     PORTA,PIN7
#define LEDMAT_ROW6_PORT_PIN                     PORTA,PIN8
#define LEDMAT_ROW7_PORT_PIN                     PORTA,PIN9

#define LEDMAT_COL0_PORT_PIN                     PORTB,PIN0
#define LEDMAT_COL1_PORT_PIN                     PORTB,PIN1
#define LEDMAT_COL2_PORT_PIN                     PORTB,PIN5
#define LEDMAT_COL3_PORT_PIN                     PORTB,PIN6
#define LEDMAT_COL4_PORT_PIN                     PORTB,PIN7
#define LEDMAT_COL5_PORT_PIN                     PORTB,PIN8
#define LEDMAT_COL6_PORT_PIN                     PORTB,PIN9
#define LEDMAT_COL7_PORT_PIN                     PORTB,PIN10




#endif /* HAL_LEDMAT_LEDMAT_CONFIG_H_ */

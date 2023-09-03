/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  1 Aug 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/

#ifndef HAL_SEVEN_SEGMENT_SEVEN_SEG_CONFIG_H_
#define HAL_SEVEN_SEGMENT_SEVEN_SEG_CONFIG_H_

/*                Seven Segment Configuration            */

/*        Choose between 3 Ports [ PORTA , PORTB , PORTC ]
 */
#define SEVEN_SEG_A_PORT                  PORTA
#define SEVEN_SEG_B_PORT                  PORTA
#define SEVEN_SEG_C_PORT                  PORTA
#define SEVEN_SEG_D_PORT                  PORTA
#define SEVEN_SEG_E_PORT                  PORTA
#define SEVEN_SEG_F_PORT                  PORTA
#define SEVEN_SEG_G_PORT                  PORTA
#define SEVEN_SEG_COM1_PORT               PORTA
#define SEVEN_SEG_COM2_PORT               PORTA

/* Choose between 16 Pins [ PIN0 , PIN1 --- PIN15 ]
 */
#define SEVEN_SEG_A_PIN                   PIN0
#define SEVEN_SEG_B_PIN                   PIN1
#define SEVEN_SEG_C_PIN                   PIN2
#define SEVEN_SEG_D_PIN                   PIN3
#define SEVEN_SEG_E_PIN                   PIN8
#define SEVEN_SEG_F_PIN                   PIN9
#define SEVEN_SEG_G_PIN                   PIN10
#define SEVEN_SEG_COM1_PIN                PIN11
#define SEVEN_SEG_COM2_PIN                PIN12


#endif /* HAL_SEVEN_SEGMENT_SEVEN_SEG_CONFIG_H_ */

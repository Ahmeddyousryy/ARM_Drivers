/*************************************************************/
/*   Author    :  Ahmed Yousry                               */
/*   Date      :  25 Aug 2023                                */
/*   Version   :  V01                                        */
/*************************************************************/

#ifndef HAL_MOTOR_MOTOR_CONFIG_H_
#define HAL_MOTOR_MOTOR_CONFIG_H_

/*                    MOTOR PINS CONFIGURATIONS                */
/*       Choose between [ PORTA , PORTB , PORTC ]
 */
#define MOTOR_IN1_PORT                       PORTA
#define MOTOR_IN2_PORT                       PORTA
#define MOTOR_IN3_PORT                       PORTA
#define MOTOR_IN4_PORT                       PORTA
#define MOTOR_ENA_PORT                       PORTA
#define MOTOR_ENB_PORT                       PORTA

/*    Choose between [ PIN0 , PIN1 --> PIN15 ]
 */

#define MOTOR_IN1_PIN                       PIN5
#define MOTOR_IN2_PIN                       PIN6
#define MOTOR_IN3_PIN                       PIN7
#define MOTOR_IN4_PIN                       PIN8
#define MOTOR_ENA_PIN                       PIN0
#define MOTOR_ENB_PIN                       PIN1

#endif /* HAL_MOTOR_MOTOR_CONFIG_H_ */

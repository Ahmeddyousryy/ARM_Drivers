#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "LED_interface.h"
#include "SWITCH_interface.h"
#include "SEVEN_SEG_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "STK_interface.h"
#include "IR_interface.h"
#include "MOTOR_interface.h"
#include "TIMER_interface.h"
#include "LEDMAT_interface.h"
#include "IRCOM_interface.h"
#include "RTOS_interface.h"
#include "DMA_interface.h"
#include "UART_interface.h"


void APP_Init();
void Delay(void);



int main()
{

	APP_Init();

	 while(1)

	 {

	 }
}





void APP_Init()
{
    RCC_Void_InitClockSystem();              /* Initiate clock system as HSE Crystal */
    RCC_Void_EnableClock(RCC_APB2 , 2);      /* Enable PORTA clock                   */
    RCC_Void_EnableClock(RCC_APB2 , 3);      /* Enable PORTB clock                   */
    RCC_Void_EnableClock(RCC_APB2 , 0);      /* Enable AFIO clock                    */
    RCC_Void_EnableClock(RCC_APB1 , 0);      /* Enable Timer 2 clock                 */
//    RCC_Void_EnableClock(RCC_APB1 , 2);      /* Enable Timer 4 clock                 */
//    NVIC_Void_EnableInterrupt(30);

//    STK_Void_STKInit();                      /* Initiate SysTick                     */

}

void Delay(void)
{
	 for(u32 i=0 ; i<700;i++)
	 {
		 for(u32 j=0 ; j<10000;j++)
		 {
         asm("NOP");
		 }
	 }
}


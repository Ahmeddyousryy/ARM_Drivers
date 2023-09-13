/****************************************************************/
/*  Author    :  Ahmed Yousry                                   */
/*  Date      :  7 Sep 2023                                     */
/*  Version   :  V01                                            */
/****************************************************************/

#ifndef SERVICES_RTOS_RTOS_PRIVATE_H_
#define SERVICES_RTOS_RTOS_PRIVATE_H_

#define NULL ((void *)0)

/*                               RTOS private functions                            */
static void RTOS_Void_Scheduler();

typedef struct {

	 u8 RTOS_TaskID ;
	 u16 RTOS_TaskPeriod ;
	 void(*TaskHandler)(void);
	 u16 RTOS_TaskFirstDelay ;
	 u8 RTOS_TaskState ;

}Task;







#endif /* SERVICES_RTOS_RTOS_PRIVATE_H_ */

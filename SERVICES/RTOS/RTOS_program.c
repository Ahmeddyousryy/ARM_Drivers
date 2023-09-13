/****************************************************************/
/*  Author    :  Ahmed Yousry                                   */
/*  Date      :  7 Sep 2023                                     */
/*  Version   :  V01                                            */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"

static Task RTOS_Tasks [RTOS_NUMBER_OF_TASKS] ;

void RTOS_Void_CreateTask(u8 Copy_U8_TaskID,u16 Copy_U16_TaskPeriod,void(*Copy_ptr)(void),u16 Copy_U16_TaskDelay,u8 Copy_U8_TaskState)
{
	 RTOS_Tasks[Copy_U8_TaskID].RTOS_TaskID = Copy_U8_TaskID ;
	 RTOS_Tasks[Copy_U8_TaskID].RTOS_TaskPeriod = Copy_U16_TaskPeriod ;
	 RTOS_Tasks[Copy_U8_TaskID].TaskHandler = Copy_ptr ;
	 RTOS_Tasks[Copy_U8_TaskID].RTOS_TaskFirstDelay = Copy_U16_TaskDelay ;
	 RTOS_Tasks[Copy_U8_TaskID].RTOS_TaskState = Copy_U8_TaskState ;
}
void RTOS_Void_StartRTOS()
{
   STK_Void_STKSetIntervalPeriodic(RTOS_SCHEDULER_TICK_TIME ,RTOS_Void_Scheduler);
}
void RTOS_Void_SuspendTask(u8 Copy_U8_TaskID)
{
	RTOS_Tasks[Copy_U8_TaskID].RTOS_TaskState = RTOS_TASK_SUSPENDED ;

}
void RTOS_Void_ResumeTask(u8 Copy_U8_TaskID)
{
	RTOS_Tasks[Copy_U8_TaskID].RTOS_TaskState = RTOS_TASK_READY ;
}
void RTOS_Void_DeleteTask(u8 Copy_U8_TaskID)
{
	RTOS_Tasks[Copy_U8_TaskID].TaskHandler = NULL ;
}

static void RTOS_Void_Scheduler()
{
	u8 Local_U8_Counter ;
	for(Local_U8_Counter = 0 ; Local_U8_Counter < RTOS_NUMBER_OF_TASKS ; Local_U8_Counter++)
	{
	 if(RTOS_Tasks[Local_U8_Counter].RTOS_TaskState == RTOS_TASK_READY)
	 {
	    if(RTOS_Tasks[Local_U8_Counter].RTOS_TaskFirstDelay == 0)
	    {
	    	RTOS_Tasks[Local_U8_Counter].RTOS_TaskFirstDelay = RTOS_Tasks[Local_U8_Counter].RTOS_TaskPeriod - 1 ;
			RTOS_Tasks[Local_U8_Counter].TaskHandler();
	    }
	    else
	    {
	    	RTOS_Tasks[Local_U8_Counter].RTOS_TaskFirstDelay -- ;
	    }
	 }
	}
}

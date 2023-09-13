/****************************************************************/
/*  Author    :  Ahmed Yousry                                   */
/*  Date      :  7 Sep 2023                                     */
/*  Version   :  V01                                            */
/****************************************************************/

#ifndef SERVICES_RTOS_RTOS_INTERFACE_H_
#define SERVICES_RTOS_RTOS_INTERFACE_H_

/*                                  RTOS API                                         */

void RTOS_Void_CreateTask(u8,u16,void(*)(void),u16,u8);
void RTOS_Void_StartRTOS();
void RTOS_Void_SuspendTask(u8);
void RTOS_Void_ResumeTask(u8);
void RTOS_Void_DeleteTask(u8);

/*                              Tasks states                                        */

#define RTOS_TASK_SUSPENDED                             0
#define RTOS_TASK_READY                                 1


#endif /* SERVICES_RTOS_RTOS_INTERFACE_H_ */

/*********************************************************/
/*  Author    :  Ahmed Yousry                            */
/*  Date      :  2 Sep 2023                              */
/*  Version   :  V01                                     */
/*********************************************************/
#ifndef HAL_IR_COM_IRCOM_PRIVATE_H_
#define HAL_IR_COM_IRCOM_PRIVATE_H_

volatile u8 startFlag = 0 ;
volatile u8 counter = 0 ;
volatile u32 DataFrame[50] = {0};
volatile u8 IRCOM_Data = 0;



static void IRCOM_Void_GetFrame(void);
static void IRCOM_Void_TakeAction(void);




#endif /* HAL_IR_COM_IRCOM_PRIVATE_H_ */

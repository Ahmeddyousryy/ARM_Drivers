/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  29 Aug 2023                                  */
/*     Version  :  V02                                          */
/****************************************************************/

#ifndef HAL_LEDMAT_LEDMAT_PRIVATE_H_
#define HAL_LEDMAT_LEDMAT_PRIVATE_H_

static void LEDMAT_Void_DisableColumns(void);
static void LEDMAT_Void_SetRow(u8);
static void LEDMAT_Void_ColActivate(u8);
static void LEDMAT_Void_LedMatDisplayNextCol();
static void LEDMAT_Void_ShitArray();
static void LEDMAT_Delay(u8);

volatile u8 Local_U8_Index;
volatile u8 * Local_U8_Frame ;
volatile u8 Local_U8_ArrayLength;




#endif /* HAL_LEDMAT_LEDMAT_PRIVATE_H_ */

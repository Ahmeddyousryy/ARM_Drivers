/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  2 Aug 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_


void LCD_Void_LcdInit(void);
void LCD_Void_LcdWriteCharacter(u8);
void LCD_Void_LcdWriteCommand(u8);
void LCD_Void_LcdWriteString(u8*);
void LCD_Void_LcdWriteNumber(s32);
void LCD_Void_LcdClear(void);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */

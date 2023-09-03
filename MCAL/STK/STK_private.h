/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  22 Aug 2023                                  */
/*     Version  :  V01                                          */
/****************************************************************/

#ifndef MCAL_STK_STK_PRIVATE_H_
#define MCAL_STK_STK_PRIVATE_H_

/*                    REGISTERS DESCRIPTION                  */
#define STK_BASE_ADDRESS                           0xE000E010


typedef struct{

	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
	volatile u32 CALIB ;


}STK_type;

#define STK                      ((volatile STK_type *)STK_BASE_ADDRESS)

/*                     INPUT TIMER CLOCK SOURCE              */

#define STK_CLOCK_AHB                                           1
#define STK_CLOCK_AHB_DIV8                                      8

/*                          STK MODES                          */
#define STK_SINGLE_INTERVAL                                     1
#define STK_PERIODIC_INTERVAL                                   2


void(*STK_callback)(void);
static u8 Local_U8_STKMode ;



#endif /* MCAL_STK_STK_PRIVATE_H_ */

/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  27 Jul 2023                                  */
/*     Version  :  V01                                          */
/****************************************************************/

#ifndef RCC_RCC_CONFIG_H_
#define RCC_RCC_CONFIG_H_

/*  Clock System configurations */

/*   CHOOSE BETWEEN 4 MODES       [ RCC_HSI_MODE
 *                                  RCC_HSE_RC_MODE
 *                                  RCC_HSE_CRYSTAL_MODE
 *                                  RCC_PLL_MODE         ]
 */
#define RCC_CLOCK_SYSTEM              RCC_HSE_CRYSTAL_MODE



#if RCC_CLOCK_SYSTEM == RCC_PLL_MODE
/*   CHOOSE BETWEEN 2 PLL INPUTS   [ RCC_PLL_SRC_HSI_DIV_2
 *                                   RCC_PLL_SRC_HSE       ]
 *
 */
#define RCC_PLL_SRC                 RCC_PLL_SRC_HSE


/* CHOOSE PLL MUL            [ 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 16 ]
 *
 */
#define RCC_PLL_MUL                        14


#endif


#endif /* RCC_RCC_CONFIG_H_ */

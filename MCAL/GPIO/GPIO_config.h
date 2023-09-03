/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  31 Jul 2023                                  */
/*     Version  :  V02                                          */
/****************************************************************/

#ifndef GPIO_GPIO_CONFIG_H_
#define GPIO_GPIO_CONFIG_H_

/*                    Set / Clear registers configurations          */

/*        Choose between [GPIO_ODR_REG - GPIO_BSRR_REG] for setting bits
 */
#define GPIO_SET_REG                    GPIO_ODR_REG

/*        Choose between [GPIO_ODR_REG - GPIO_BRR_REG] for clearing bits
 */
#define GPIO_CLR_REG                    GPIO_ODR_REG




#endif /* GPIO_GPIO_CONFIG_H_ */

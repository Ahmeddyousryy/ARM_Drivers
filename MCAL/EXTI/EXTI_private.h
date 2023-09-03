/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  15 Aug 2023                                  */
/*     Version  :  V01                                          */
/****************************************************************/


#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

/*                                  BASE ADDRESS                                      */
#define EXTI_BASE_ADDRESS                         0x40010400
/*                               CallBack Pointers                                     */
static void(*EXTI_callBack[15])(void);

/*                               REGISTER DESCRIPTION                                  */
typedef struct{

	volatile u32 IMR ;
	volatile u32 EMR ;
	volatile u32 RTSR ;
	volatile u32 FTSR ;
	volatile u32 SWIER ;
	volatile u32 PR ;

}EXTI_t;
/*          EXTI AS A POINTER TO BASE ADDRESS CASTING TO STRUCT (STEP BY 4 BYTE u32)   */
#define EXTI                            ((volatile EXTI_t*)EXTI_BASE_ADDRESS)



#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */

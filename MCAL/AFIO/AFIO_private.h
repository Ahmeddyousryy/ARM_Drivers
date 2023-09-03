/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  15 Aug 2023                                  */
/*     Version  :  V01                                          */
/****************************************************************/

#ifndef MCAL_AFIO_AFIO_PRIVATE_H_
#define MCAL_AFIO_AFIO_PRIVATE_H_

#define AFIO_BASE_ADDRESS                        0x40010000

/*                            REGISTERS DESCRIPTION                                    */

typedef struct{

     volatile u32 EVCR      ;
     volatile u32 MAPR      ;
     volatile u32 EXTICR[4] ;
//   volatile u32 MAPR2     ;

}AFIO_t;

#define AFIO                           ((volatile AFIO_t*)AFIO_BASE_ADDRESS)

#endif /* MCAL_AFIO_AFIO_PRIVATE_H_ */

/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  9 Sup 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/

#ifndef MCAL_DMA_DMA_PRIVATE_H_
#define MCAL_DMA_DMA_PRIVATE_H_

/*                            REGISTERS DESCRIPTION                                */

typedef struct{

	  volatile u32 CCR ;
	  volatile u32 CNDTR ;
	  volatile u32 CPAR ;
	  volatile u32 CMAR ;
	  volatile u32 Reserved ;

}Channel_reg;

typedef struct{

	  volatile u32 ISR ;
	  volatile u32 IFCR ;
	  volatile Channel_reg Channel [7];


}DMA_reg;


#define DMA                             ((volatile DMA_reg *)0x40020000)


#endif /* MCAL_DMA_DMA_PRIVATE_H_ */

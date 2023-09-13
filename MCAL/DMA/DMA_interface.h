/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  9 Sup 2023                                   */
/*     Version  :  V01                                          */
/****************************************************************/

#ifndef MCAL_DMA_DMA_INTERFACE_H_
#define MCAL_DMA_DMA_INTERFACE_H_

/*                                 DMA CONFIGURATIONS                                */

typedef struct{

	volatile u8 ChannelID ;
	volatile u8 InterruptSource ;
	volatile u8 DataDireciton ;
	volatile u8 CircularMode ;
	volatile u8 MINC ;
	volatile u8 PINC ;
	volatile u8 MemSize ;
	volatile u8 PerSize ;
	volatile u8 ChannelPriority ;
	volatile u8 MemToMemMode ;

}DMA_Config;

#define TRANSFER_COMPLETE                               1
#define HALF_TRANSFER_COMPLETE                          2
#define TRANSFER_ERROR                                  3

#define READ_FROM_PERIPHERAL                            1
#define READ_FROM_MEMORY                                2

#define CIRCULAR_DISABLE                                0
#define CIRCULAR_ENABLE                                 1

#define PINC_DISABLE                                    0
#define PINC_ENABLE                                     1

#define MINC_DISABLE                                    0
#define MINC_ENABLE                                     1

#define PER_SIZE_8                                      0
#define PER_SIZE_16                                     1
#define PER_SIZE_32                                     2

#define MEM_SIZE_8                                      0
#define MEM_SIZE_16                                     1
#define MEM_SIZE_32                                     2

#define VERY_HIGH                                       0
#define HIGH                                            1
#define MEDIUM                                          2
#define LOW                                             3

#define MEM_TO_MEM_DISABLE                              0
#define MEM_TO_MEM_ENABLE                               1



/*                                     DMA APIs                                       */
void DMA_Void_InitDMA(DMA_Config *);
void DMA_Void_StartTransfer(DMA_Config *,u32* , u32*,u16);


#endif /* MCAL_DMA_DMA_INTERFACE_H_ */

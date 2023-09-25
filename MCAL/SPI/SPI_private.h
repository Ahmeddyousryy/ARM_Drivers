/*
 * Author   : Ahmed Yousry
 * Date     : 25 Sep 2023
 * Version  : V01
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#define SPI_BASE_ADDRESS       0x40013000

typedef struct
{
	volatile u32 CR1     ;
	volatile u32 CR2     ;
	volatile u32 SR      ;
	volatile u32 DR      ;
	volatile u32 CRCPR   ;
	volatile u32 RXCRCR  ;
	volatile u32 TXCRCR  ;
	volatile u32 I2SCFGR ;
	volatile u32 I2SPR   ;

}SPI_reg;

#define SPI             ((SPI_reg*) SPI_BASE_ADDRESS)




#endif /* MCAL_SPI_SPI_PRIVATE_H_ */

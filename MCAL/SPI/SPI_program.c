/*
 * Author   : Ahmed Yousry
 * Date     : 25 Sep 2023
 * Version  : V01
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_Void_InitSPI(void)
{
	/* Select slave select pin as output */
	GPIO_Void_SetPinDirection(SPI_SLAVE_PIN,GPIO_OUTPUT_2MHZ_PP);

	/* SPI Configurations */
	SPI -> CR1 = 0x0347;
}
void SPI_Void_SendReceiveSynch(u8 Copy_U8_DataToTransmit , u8 * Copy_U8_DataToRevceive)
{
	/* Clear for slave select pin */
	GPIO_Void_SetPinValue(SPI_SLAVE_PIN,GPIO_PIN_LOW);

	/* Send Data */
	SPI->DR = Copy_U8_DataToTransmit ;

	/* Wait for busy flag to be cleared */
	while(GET_BIT(SPI -> SR,7) == 1);

	/* Return to received data */
	*Copy_U8_DataToRevceive = SPI ->DR ;

	/* Set for slave select pin */
	GPIO_Void_SetPinValue(SPI_SLAVE_PIN,GPIO_PIN_LOW);
}




/************************************************************************/
/* Name: MUART_program.c                                                */
/* Author: MUHAMED HASSEN                                                 */
/* Version: V1.0                                                        */
/* Usage: This file contains logical implementations of UART Module     */
/************************************************************************/

/************************************************************************/
/*                              Includes                                */
/************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MUART_private.h"
#include "MUART_interface.h"

/************************************************************************/
/*                          Functions' definitions                      */
/************************************************************************/

void muart_init(u16_t au16_baudRate)
{
	/*Disable double speed and multi processor communication mode*/
	MUART_UCSRA = 0;
	
	/*Enable TX and RX operations*/	
	MUART_UCSRB = 0x18;
	
	/*Enable asynchronous mode, disable parity, selecting one stop bit and 8-bit character size*/
	MUART_UCSRC = 0x86;
	
	/*Setting the low byte of baud rate*/
	MUART_UBRRL = (u8_t) au16_baudRate;
	
	/*Setting the high byte of baud rate*/
	MUART_UBRRH = (u8_t) (au16_baudRate >> 8); 
	
	return;
}

void muart_sendByte(u8_t au8_dataByte)
{
	/*Checking if the UART data register is empty or not*/
	if(GET_BIT(MUART_UCSRA, 5))
	{
		/*Setting the sent byte*/
		MUART_UDR = au8_dataByte;
		
		/*Wait until the transmission is completed*/
		while(GET_BIT(MUART_UCSRA, 6) == 0);
		
		/*Clearing the TXC bit*/
		SET_BIT(MUART_UCSRA, 6);
	}
	else
	{
		
		/*Do nothing*/
	
	}
	
	return;
}


void muart_recvByte(u8_t* pu8_dataByte)
{
	/*Checking if there's any received data or not*/
	if(GET_BIT(MUART_UCSRA, 7))
	{
		/*Getting the received byte*/
		*pu8_dataByte = MUART_UDR;
	}
	else
	{
		
		/*Do nothing*/
		
	}
	
	return;
}

void muart_sendStream(u8_t* pu8_dataStream, u8_t au8_dataSize)
{
	/*Looping over data bytes*/
	while(au8_dataSize--)
	{
		/*Check whether the UART data register is empty or not*/
		if(GET_BIT(MUART_UCSRA, 5))
		{
			/*Setting the byte that will be sent*/
			MUART_UDR = *pu8_dataStream;
		
			/*Wait until the transmission is completed*/
			while(GET_BIT(MUART_UCSRA, 6) == 0);
		
			/*Clearing the TXC bit*/
			SET_BIT(MUART_UCSRA, 6);
			
			/*Increasing the pointer address*/
			pu8_dataStream++;
		}
		else
		{
			
			/*Do nothing*/
			
		}			
	}
	
	return;
}

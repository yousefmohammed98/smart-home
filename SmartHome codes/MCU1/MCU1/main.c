/************************************************************************/
/* Name:MDIO_interface.h                                                */
/* Author: MUHAMED HASSEN                                               */
/* Version:V1.0                                                         */
/* Usage: this file contains the main program of the MCU1               */
/************************************************************************/
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#define  F_CPU 16000000UL
#include "util/delay.h"
#include "MSPI_interface.h"
#include "MUART_interface.h"
int main(void)
{
	/*Variables*/
	u8_t spi_sentValue; // variable carry address sent by slave to master
	u8_t uart_recivedByte='-'; // variable carry the character sent from blue tooth module (initialized with '*' as dummy character)
	
	/* Atmega PINS status*/
    mdio_setPinStatus(PORTB,PIN5 | PIN4 | PIN7,OUTPUT); //PORT B PIN 5 ,4 & 7 set as an output PINS
	mdio_setPinStatus(PORTB,PIN6,INPUT_FLOAT); //PORTB PIN 6 set as an input PIN
	mdio_setPinStatus(PORTD,PIN0,INPUT_FLOAT); //PORTD PIN 0 set as an input PIN
	mdio_setPinStatus(PORTD,PIN1,OUTPUT); //PORTD PIN 1 set as an output PIN
	
	/*Initializations*/
	muart_init(MUART_9600_BR); //UART initialization function at 9600 baud rate
	mspi_init(MSPI_MASTER_DEVICE,MSPI_LSB_FIRST,MSPI_SAMPLE_R_SETUP_F,MSPI_CLK_PRE_16); //SPI initialization function for master device at LSB order,sample R setup F & 16 bit prescaler frequency


	muart_sendStream((u8_t*)"WELCOME TO SMARTHOME\r",22 ); // Message to be shown on the mobile device
	_delay_ms(50);
	START:
	muart_sendStream((u8_t*)"please choose between : (write only the number in the left) \r", 62); // Message to be shown on the mobile device
	_delay_ms(50);
	muart_sendStream((u8_t*)"1) TURN AC ON ONLY\r", 19); // Message to be shown on the mobile device
	_delay_ms(50);
	muart_sendStream((u8_t*)"2) TURN AC OFF ONLY\r", 20); // Message to be shown on the mobile device
	_delay_ms(50);
	muart_sendStream((u8_t*)"3) TURN LIGHT ON ONLY\r", 22); // Message to be shown on the mobile device
	_delay_ms(50);
	muart_sendStream((u8_t*)"4) TURN LIGHT OFF ONLY\r", 23); // Message to be shown on the mobile device
	_delay_ms(50);
	muart_sendStream((u8_t*)"5) TURN ON BOTH\r", 17);// Message to be shown on the mobile device
	_delay_ms(50);
	muart_sendStream((u8_t*)"6) TURN OFF BOTH\r", 18); // Message to be shown on the mobile device
	
    while (1) 
    {
		uart_recivedByte='-';  //Re-initialization for the variable to be used in case of the user types again
		muart_recvByte(&uart_recivedByte); //Read the received byte from BLUETOOTH module
		if (uart_recivedByte=='1') //If the received byte is '1'
		{
			muart_sendStream((u8_t*)"\r\rAC is turned on\r\r",20); // Message to be shown on the mobile device			
			mspi_masterSendRecv(0x10,&spi_sentValue);//Send address 0x10 to slave MCU and receive the address sent from slave MCU
			goto START; //goto start in order to show the messages above again
		}
		else  if (uart_recivedByte=='2') //If the received byte is '2'
		{
			muart_sendStream((u8_t*)"\r\rAC is turned off\r\r",21); // Message to be shown on the mobile device
			mspi_masterSendRecv(0x20,&spi_sentValue); //Send address 0x20 to slave MCU and receive the address sent from slave MCU
			goto START; //goto start in order to show the messages above again
		}
		else  if (uart_recivedByte=='3') //If the received byte is '3'
		{
			muart_sendStream((u8_t*)"\r\rlight is turned on\r\r",23);// Message to be shown on the mobile device
			mspi_masterSendRecv(0x30,&spi_sentValue); //Send address 0x30 to slave MCU and receive the address sent from slave MCU
			goto START; //goto start in order to show the messages above again
		}
		else  if (uart_recivedByte=='4') //If the received byte is '4'
		{
			muart_sendStream((u8_t*)"\r\rlight is turned off\r\r",24); // Message to be shown on the mobile device
			mspi_masterSendRecv(0x40,&spi_sentValue); //Send address 0x40 to slave MCU and receive the address sent from slave MCU
			goto START; //goto start in order to show the messages above again
		}
		else  if (uart_recivedByte=='5') //If the received byte is '5'
		{
			muart_sendStream((u8_t*)"\r\rBOTH LIGHT AND AC ARE TURNED ON\r\r",36); // Message to be shown on the mobile device
			mspi_masterSendRecv(0x50,&spi_sentValue); //Send address 0x50 to slave MCU and receive the address sent from slave MCU
			goto START; //goto start in order to show the messages above again
		} 
		
		else  if (uart_recivedByte=='6') //If the received byte is '6'
		{
			muart_sendStream((u8_t*)"\r\rBOTH LIGHT AND AC ARE TURNED OFF\r\r",37); // Message to be shown on the mobile device
			mspi_masterSendRecv(0x60,&spi_sentValue); //Send address 0x60 to slave MCU and receive the address sent from slave MCU
			goto START; //goto start in order to show the messages above again
		}
		
		else if(uart_recivedByte!= '-' ) //If the received byte is not '1' or '2' or '3' or '4' or '5' or '6'
		{
			muart_sendStream((u8_t*)"\r\rWRONG ENTERY\r\r",16); // Message to be shown on the mobile device
			goto START; //goto start in order to show the messages above again in case of the user pressed again
		}
    }
	return 0;
}




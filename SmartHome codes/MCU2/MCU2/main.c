/************************************************************************/
/* Name:MDIO_interface.h                                                */
/* Author: MUHAMED HASSEN                                               */
/* Version:V1.0                                                         */
/* Usage: this file contains the main program of the MCU2               */
/************************************************************************/
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#define  F_CPU 16000000UL
#include "util/delay.h"
#include "MSPI_interface.h"


int main(void)
{
	/*Variables*/
	u8_t spi_recivedValue; // variable carry address sent by master to slave
	
	/* Atmega PINS status*/
	mdio_setPinStatus(PORTB,PIN5 | PIN4 | PIN7,OUTPUT);//PORT B PIN 5 ,4 & 7 set as an output PINS
	mdio_setPinStatus(PORTB,PIN6,INPUT_FLOAT);//PORTB PIN 6 set as an input PIN
	mdio_setPinStatus(PORTD, PIN0 | PIN1 ,OUTPUT); //PORT D PIN 0 & 1 set as an output PINS for AC and LIGHT respectively
	
	/*Initializations*/
	mspi_init(MSPI_SLAVE_DEVICE,MSPI_LSB_FIRST,MSPI_SAMPLE_R_SETUP_F,MSPI_CLK_PRE_16); //SPI initialization function for slave device at LSB order,sample R setup F & 16 bit prescaler frequency
	
    while (1) 
    {
		mspi_slaveSendRecv(0xFF,&spi_recivedValue); //Send address 0x60 to master MCU and receive the address sent from master MCU
		if (spi_recivedValue == 0x10) //If the received address is 0x10
		{
			mdio_setPinValue(PORTD,PIN0,HIGH); //Activate AC
			mdio_setPinValue(PORTD,PIN1,LOW); //Deactivate LIGHTS
		}
		else if (spi_recivedValue == 0x20) //If the received address is 0x20
		{
			mdio_setPinValue(PORTD,PIN0,LOW);//Deactivate the AC
		}
		else if (spi_recivedValue == 0x30)  //If the received address is 0x30
		{
			mdio_setPinValue(PORTD,PIN0,LOW);//Deactivate the AC
			mdio_setPinValue(PORTD,PIN1,HIGH);//Activate LIGHTS
		}
		else if (spi_recivedValue == 0x40) //If the received address is 0x40
		{
			mdio_setPinValue(PORTD,PIN1,LOW); //Deactivate LIGHTS
		}
		else if (spi_recivedValue == 0x50) //If the received address is 0x50
		{
			mdio_setPinValue(PORTD,PIN0,HIGH);//Activate the AC
			mdio_setPinValue(PORTD,PIN1,HIGH);//Activate LIGHTS
		}
		else if (spi_recivedValue == 0x60) //If the received address is 0x60
		{
			mdio_setPinValue(PORTD,PIN0,LOW);//Deactivate the AC
			mdio_setPinValue(PORTD,PIN1,LOW); //Deactivate LIGHTS
		}		
    }
	return 0;
}


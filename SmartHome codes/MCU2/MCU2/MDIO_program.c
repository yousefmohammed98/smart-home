/************************************************************************/
/* Name:MDIO_prpgram.c                                         */
/* Author: MUHAMED HASSEN                                      */
/* Version:V1.0                                                */
/* Usage: this file contains logical implementation information of DIO module */
/************************************************************************/

/************************************************************************/
/*                                 Includes                             */
/************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

/************************************************************************/
/*                               Function's definitions                 */
/************************************************************************/

void mdio_setPinStatus ( u8_t au8_port,u8_t au8_pin,u8_t au8_status){
	
	/*switching over GPIO Ports*/
	switch(au8_port){
		/* in case of PORTA*/
		case PORTA:
			/*switching over pin status*/	
			switch(au8_status)
			{   /*in case of OUTPUt*/
				case OUTPUT:
					MDIO_DDRA|= au8_pin;
					/*break from this case*/
					break;
				/*in case of INPUT_FLOAT*/
				case INPUT_FLOAT:
					/*set the specified pins to 0 in DDR*/
					MDIO_DDRA&=~au8_pin;
					/*break from this case*/
					break;
				/*in case of INPUT_PULLUP*/
				case INPUT_PULLUP:
					/*set the specified pins to 0 in DDR*/
					MDIO_DDRA&= ~au8_pin;
					/*set the specified pins to 1 in Port*/
					MDIO_PORTA|= au8_pin;
					/*break from this case*/
					break;
			}
				break;
				
		case PORTB:
			/*switching over pin status*/	
			switch(au8_status)
			{   /*in case of OUTPUt*/
				case OUTPUT:
					MDIO_DDRB|= au8_pin;
					/*break from this case*/
					break;
				/*in case of INPUT_FLOAT*/
				case INPUT_FLOAT:
					/*set the specified pins to 0 in DDR*/
					MDIO_DDRB&=~au8_pin;
					/*break from this case*/
					break;
				/*in case of INPUT_PULLUP*/
				case INPUT_PULLUP:
					/*set the specified pins to 0 in DDR*/
					MDIO_DDRB&= ~au8_pin;
					/*set the specified pins to 1 in Port*/
					MDIO_PORTB|= au8_pin;
					/*break from this case*/
					break;
			}
				break;
				
		case PORTC:
			/*switching over pin status*/	
			switch(au8_status)
			{   /*in case of OUTPUt*/
				case OUTPUT:
					MDIO_DDRC|= au8_pin;
					/*break from this case*/
					break;
				/*in case of INPUT_FLOAT*/
				case INPUT_FLOAT:
					/*set the specified pins to 0 in DDR*/
					MDIO_DDRC&=~au8_pin;
					/*break from this case*/
					break;
				/*in case of INPUT_PULLUP*/
				case INPUT_PULLUP:
					/*set the specified pins to 0 in DDR*/
					MDIO_DDRC&= ~au8_pin;
					/*set the specified pins to 1 in Port*/
					MDIO_PORTC|= au8_pin;
					/*break from this case*/
					break;
			}
				break;
		case PORTD:
			/*switching over pin status*/	
			switch(au8_status)
			{   /*in case of OUTPUt*/
				case OUTPUT:
					MDIO_DDRD|= au8_pin;
					/*break from this case*/
					break;
				/*in case of INPUT_FLOAT*/
				case INPUT_FLOAT:
					/*set the specified pins to 0 in DDR*/
					MDIO_DDRD&=~au8_pin;
					/*break from this case*/
					break;
				/*in case of INPUT_PULLUP*/
				case INPUT_PULLUP:
					/*set the specified pins to 0 in DDR*/
					MDIO_DDRD&= ~au8_pin;
					/*set the specified pins to 1 in Port*/
					MDIO_PORTD|= au8_pin;
					/*break from this case*/
					break;
			}
	/*break from this case*/
	break;
	}
	return;
}

void mdio_setPinValue ( u8_t au8_port,u8_t au8_pin,u8_t au8_value){
	
	/*switching over GPIO Ports*/
	switch(au8_port){
		/* in case of PORTA*/
		case PORTA:
		/*switching over pin status*/
		switch(au8_value)
		{   /*in case of LOW*/
			case LOW:
				MDIO_PORTA&= ~au8_pin;
			/*break from this case*/
				break;
			/*in case of HIGH*/
			case HIGH:
			/*set the specified pins to 0 in PORT*/
				MDIO_PORTA|=au8_pin;
			/*break from this case*/
				break;
		}
		break;
		
		/* in case of PORTB*/
		case PORTB:
		/*switching over pin status*/
		switch(au8_value)
		{   /*in case of LOW*/
			case LOW:
				MDIO_PORTB&= ~au8_pin;
			/*break from this case*/
				break;
			/*in case of HIGH*/
			case HIGH:
			/*set the specified pins to 0 in PORT*/
				MDIO_PORTB|=au8_pin;
			/*break from this case*/
				break;
		}
		break;
		/* in case of PORTC*/
		case PORTC:
		/*switching over pin status*/
		switch(au8_value)
		{   /*in case of LOW*/
			case LOW:
				MDIO_PORTC&= ~au8_pin;
			/*break from this case*/
				break;
			/*in case of HIGH*/
			case HIGH:
			/*set the specified pins to 0 in PORT*/
				MDIO_PORTC|=au8_pin;
			/*break from this case*/
				break;
		}
		break;
		/* in case of PORTD*/
		case PORTD:
		/*switching over pin status*/
		switch(au8_value)
		{   /*in case of LOW*/
			case LOW:
				MDIO_PORTD&= ~au8_pin;
			/*break from this case*/
				break;
			/*in case of HIGH*/
			case HIGH:
			/*set the specified pins to 0 in PORT*/
				MDIO_PORTD|=au8_pin;
			/*break from this case*/
				break;
		}
		break;
	}
	
	return;
}

void mdio_togglePinValue ( u8_t au8_port,u8_t au8_pin){
	
	switch(au8_port){
		/* in case of PORTA*/
		case PORTA:
			/*Toggle a specified pin value in PORT*/
			MDIO_PORTA^= au8_pin;
			/*break from this case*/
			break;
		
		case PORTB:
			/*Toggle a specified pin value in PORT*/
			MDIO_PORTB^= au8_pin;
			/*break from this case*/
			break;
			
		case PORTC:
			/*Toggle a specified pin value in PORT*/
			MDIO_PORTC^= au8_pin;
			/*break from this case*/
			break;
			
		case PORTD:
			/*Toggle a specified pin value in PORT*/
			MDIO_PORTD^= au8_pin;
			/*break from this case*/
			break;
	}	
	return;
}

u8_t mdio_getPinValue ( u8_t au8_port,u8_t au8_pin){
	/* A local variable is used to carry the current pin value */
	u8_t au8_pinValue=0;
	
	switch(au8_port){
		/* in case of PORTA*/
		case PORTA:
			/*Checking the current value of the specified PIN in PIN register*/
			if (MDIO_PINA & au8_pin)
			{
				/*set the pin value to HIGH*/
				au8_pinValue= HIGH;
			}
			else
			{
				au8_pinValue= LOW;
			}
			/*break from this case*/
		break;
		/* in case of PORTB*/
		case PORTB:
			/*Checking the current value of the specified PIN in PIN register*/
			if (MDIO_PINB & au8_pin)
			{
				/*set the pin value to HIGH*/
				au8_pinValue= HIGH;
			}
			else
			{
				au8_pinValue= LOW;
			}
			/*break from this case*/
		break;
		/* in case of PORTC*/		
		case PORTC:
			/*Checking the current value of the specified PIN in PIN register*/
			if (MDIO_PINC & au8_pin)
			{
				/*set the pin value to HIGH*/
				au8_pinValue= HIGH;
			}
			else
			{
				au8_pinValue= LOW;
			}
			/*break from this case*/
		break;
		/* in case of PORTD*/
		case PORTD:
			/*Checking the current value of the specified PIN in PIN register*/
			if (MDIO_PIND & au8_pin)
			{
				/*set the pin value to HIGH*/
				au8_pinValue= HIGH;
			}
			else
			{
				au8_pinValue= LOW;
			}
			/*break from this case*/
		break;
	}
	return au8_pinValue;
}
/************************************************************************/
/* Name:MDIO_interface.h                                         */
/* Author: MUHAMED HASSEN                                      */
/* Version:V1.0                                                */
/* Usage: this file contains interfacing information of DIO module */
/************************************************************************/


/************************************************************************/
/*                             DIO Register                           */
/************************************************************************/


#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

/*GPIO PORT A*/
#define MDIO_PORTA (*(volatile u8_t *)(0x3B))
#define MDIO_DDRA  (*(volatile u8_t *)(0x3A))
#define MDIO_PINA  (*(volatile u8_t *)(0x39))

/*GPIO PORT B*/
#define MDIO_PORTB (*(volatile u8_t *)(0x38))
#define MDIO_DDRB  (*(volatile u8_t *)(0x37))
#define MDIO_PINB  (*(volatile u8_t *)(0x36))

/*GPIO PORT C*/
#define MDIO_PORTC (*(volatile u8_t *)(0x35))
#define MDIO_DDRC  (*(volatile u8_t *)(0x34))
#define MDIO_PINC  (*(volatile u8_t *)(0x33))

/*GPIO PORT D*/
#define MDIO_PORTD (*(volatile u8_t *)(0x32))
#define MDIO_DDRD  (*(volatile u8_t *)(0x31))
#define MDIO_PIND  (*(volatile u8_t *)(0x30))

/************************************************************************/
/*                            Interfacing macros                        */
/************************************************************************/
/*GPIO PORTs*/
#define PORTA   (0)
#define PORTB   (1)
#define PORTC   (2)
#define PORTD   (3)

/* PORT PINs*/
#define PIN0    (0b00000001)
#define PIN1    (0b00000010)
#define PIN2    (0b00000100)
#define PIN3    (0b00001000)
#define PIN4    (0b00010000)
#define PIN5    (0b00100000)
#define PIN6    (0b01000000)
#define PIN7    (0b10000000)

/* PORT PIN's status*/
#define OUTPUT  (0)
#define INPUT_FLOAT  (1) 
#define INPUT_PULLUP  (2)

/* PORT PIN's output values */
#define LOW   (0)
#define HIGH  (1)

/************************************************************************/
/*                            Function's prototypes                     */
/************************************************************************/

/* this function is responsible for setting status for GPIO pin [output - INPUT_FLOAT- INPUT_PULLUP]*/
void mdio_setPinStatus ( u8_t au8_port,u8_t au8_pin,u8_t au8_status);

/* this function is responsible for setting a defined value for an output GPIO pin [HIGh - LOW]*/
void mdio_setPinValue ( u8_t au8_port,u8_t au8_pin,u8_t au8_value);

/* this function is responsible for toggling a defined value for an output GPIO pin [HIGh - LOW]*/
void mdio_togglePinValue ( u8_t au8_port,u8_t au8_pin);

/* this function is responsible for reading a defined value for an input GPIO pin [HIGh - LOW]*/
u8_t mdio_getPinValue ( u8_t au8_port,u8_t au8_pin);
#endif /*_MDIO_INTERFACE_H_*/

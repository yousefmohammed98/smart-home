/************************************************************************/
/* Name: MUART_interface.h                                              */
/* Author: MUHAMED HASSEN                                                 */
/* Version: V1.0                                                        */
/* Usage: This file contains interfacing information of UART Module     */
/************************************************************************/

/*Header file guard*/
#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_

/************************************************************************/
/*                           Interfacing macros                         */
/************************************************************************/

/*UART Baud rates*/
#define MUART_2400_BR      (416)
#define MUART_4800_BR      (207)
#define MUART_9600_BR      (103)
#define MUART_19200_BR     (51)
#define MUART_115200_BR    (8)

/************************************************************************/
/*                           Functions' prototypes                      */
/************************************************************************/

/*This function is used to initialize UART with specific baud rate*/
void muart_init(u16_t au16_baudRate);

/*This function is used to send data of 1 byte size over UART*/
void muart_sendByte(u8_t au8_dataByte);

/*This function is used to receive data 1 byte size over UART*/
void muart_recvByte(u8_t* pu8_dataByte);

/*This function is used to send data of many size of bytes over UART*/
void muart_sendStream(u8_t* pu8_dataStream, u8_t au8_dataSize);

#endif /* MUART_INTERFACE_H_ */
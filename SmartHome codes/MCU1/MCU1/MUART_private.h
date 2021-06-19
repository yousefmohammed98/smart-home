/************************************************************************/
/* Name: MUART_private.h                                                */
/* Author: MUHAMED HASSEN                                               */
/* Version: V1.0                                                        */
/* Usage: This file contains private information of UART Module         */
/************************************************************************/

/*							Header file guard							*/
#ifndef MUART_PRIVATE_H_
#define MUART_PRIVATE_H_

/************************************************************************/
/*                            UART Registers                            */
/************************************************************************/

#define MUART_UDR      (*(volatile u8_t *)(0x2C))
#define MUART_UCSRA    (*(volatile u8_t *)(0x2B))
#define MUART_UCSRB    (*(volatile u8_t *)(0x2A))
#define MUART_UCSRC    (*(volatile u8_t *)(0x40))
#define MUART_UBRRH    (*(volatile u8_t *)(0x40))
#define MUART_UBRRL    (*(volatile u8_t *)(0x29))

#endif /* MUART_PRIVATE_H_ */
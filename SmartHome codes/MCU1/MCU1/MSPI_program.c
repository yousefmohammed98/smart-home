/************************************************************************/
/* Name: MSPI_program.c                                                 */
/* Author: MUHAMED HASSEN                                               */
/* Version: V1.0                                                        */
/* Usage: This file contains logical implementations of SPI Module      */
/************************************************************************/

/************************************************************************/
/*                              Includes                                */
/************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"

#define F_CPU  16000000UL
#include "util/delay.h"

/************************************************************************/
/*                             Important macros                         */
/************************************************************************/

#define TIMEOUT_VALUE   (50)

/************************************************************************/
/*                          Functions' definitions                      */
/************************************************************************/

void mspi_init(u8_t au8_spiDevType, u8_t au8_dataOrder, u8_t au8_dataTransfer_clkType, u8_t au8_clkFrequency)
{
    /*Reset the control register*/
    MSPI_SPCR = 0;

    /*Checking the CLK frequency value to enable double speed or to disable it*/
    if( (au8_clkFrequency % 2) == 0 )
    {
        /*Enable double speed*/
        SET_BIT(MSPI_SPSR, 0);
    }
    else
    {
        /*Disable double speed*/
        CLEAR_BIT(MSPI_SPSR, 0);
    }

    /*Setting the SPI control register parameters*/
    MSPI_SPCR = (1<<6) | au8_spiDevType | au8_dataOrder | (au8_dataTransfer_clkType << 2) | (au8_clkFrequency / 2);

    return;
}

void mspi_masterSendRecv(u8_t au8_sendData, u8_t* au8_recvData)
{
    /*This variable used in timing out mechanism*/
    u8_t au8_timeOut = 0;

    /*Set the master data that will be sent*/
    MSPI_SPDR = au8_sendData;

    /*Wait until the SPI flag rises*/
    while( (GET_BIT(MSPI_SPSR, 7) == 0) && (au8_timeOut < TIMEOUT_VALUE) )
    {
        /*Increasing the timeout variable*/
        au8_timeOut++;

        /*Wait for 1 microsecond*/
        _delay_us(1);
    }
    
    /*Get the received data from slave*/
    *au8_recvData = MSPI_SPDR;

    return;
}

void mspi_slaveSendRecv(u8_t au8_sendData, u8_t* au8_recvData)
{   
    /*Checking if the SPI flag rises*/
    if( GET_BIT(MSPI_SPSR, 7) )
    {
        /*Get the received master data*/
        *au8_recvData = MSPI_SPDR;

        /*Set the new data*/
        MSPI_SPDR = au8_sendData;
    }
    else
    {
        /*Do nothing*/
    }

    return;
}
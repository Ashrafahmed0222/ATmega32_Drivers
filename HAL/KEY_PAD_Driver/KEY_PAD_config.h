
/*
 ********************************************* KEY_PAD_config.h ************************************************
 *  Author:  Ashraf Ahmed Hamed
 *  Date:    4/6/2023
 *  Layer:   HAL
 *  SWC:     KeyPad
 */

#include "../../MCAL/DIO_Driver/DIO_interface.h"

#ifndef _KEY_PAD_CONFIG_H_
#define _KEY_PAD_CONFIG_H_

#define KEY_PAD_ROW_Init    DIO_PIN0
#define KEY_PAD_ROW_End     DIO_PIN3

#define KEY_PAD_COLUMN_Init DIO_PIN4
#define KEY_PAD_COLUMN_End  DIO_PIN7

#define KEY_PAD_PORT        DIO_PORTD

#define KEY_PAD_R0          DIO_PIN0
#define KEY_PAD_R1          DIO_PIN1
#define KEY_PAD_R2   		DIO_PIN2
#define KEY_PAD_R3			DIO_PIN3

#define KEY_PAD_C0			DIO_PIN4
#define KEY_PAD_C1			DIO_PIN5
#define KEY_PAD_C2			DIO_PIN6
#define KEY_PAD_C3			DIO_PIN7

u8 KEY_PAD_u8Buttons[4][4] = {

{ '7', '8', '9', '/' },
{ '4', '5', '6', '*' },
{ '1', '2', '3', '-' },
{ '?', '0', '=', '+' }
};

#endif


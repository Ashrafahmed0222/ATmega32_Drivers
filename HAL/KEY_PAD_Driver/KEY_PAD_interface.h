









/*
********************************************* KEY_PAD_interface.h ************************************************
*  Author:  Ashraf Ahmed Hamed
*  Date:    4/6/2023
*  Layer:   HAL
*  SWC:     KeyPad
*/



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#ifndef _KEY_PAD_INTERFACE_H_
#define _KEY_PAD_INTERFACE_H_

#define  NOT_PRESSED 0xFF


void KEY_PAD_voidInit(void);
u8 KEY_PAD_u8GetPressed(void);


#endif









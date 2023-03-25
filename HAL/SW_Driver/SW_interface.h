









/*
********************************************* SW_INTERFACE.h ************************************************
*  Author:  Ashraf Ahmed Hamed
*  Date:    2/19/2023
*  Layer:   HAL
*  SWC:     SWITCH
*/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#ifndef _SW_INTERFACE_H_
#define _SW_INTERFACE_H_



#define SW_PRESSED 1
#define SW_NOT_PRESSED 0


#define SW_INT_PULL_UP    0
#define SW_EXT_PULL_UP    1
#define SW_EXT_PULL_DOWN  2
#define SW_FLOATING       3


typedef struct {
	u8 Port;
	u8 Pin;
	u8 Pull_State;
} SW_TYPE;



void SW_voidInitial            (SW_TYPE SW_CONF);
u8 SW_u8getPressed             (SW_TYPE SW_CONF);
void SW_voidEnableIternalPullUp(SW_TYPE SW_CONF);
void SW_voidDisableIternalPullUp(SW_TYPE SW_CONF);







#endif





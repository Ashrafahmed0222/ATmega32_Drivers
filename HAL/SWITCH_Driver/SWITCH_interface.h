









/*
********************************************* SWITCH_INTERFACE.h ************************************************
*  Author:  Ashraf Ahmed Hamed
*  Date:    2/19/2023
*  Layer:   HAL
*  SWC:     SWITCH
*/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#ifndef _SWITCH_INTERFACE_H_
#define _SWITCH_INTERFACE_H_



#define SWITCH_PRESSED 1
#define SWITCH_NOT_PRESSED 0


#define SWITCH_INT_PULL_UP    0
#define SWITCH_EXT_PULL_UP    1
#define SWITCH_EXT_PULL_DOWN  2
#define SWITCH_FLOATING       3


typedef struct {
	u8 Port;
	u8 Pin;
	u8 Pull_State;
} SWITCH_TYPE;



void SWITCH_voidInitial            (SWITCH_TYPE SWITCH_CONF);
u8 SWITCH_u8getPressed             (SWITCH_TYPE SWITCH_CONF);
void SWITCH_voidEnableIternalPullUp(SWITCH_TYPE SWITCH_CONF);
void SWITCH_voidDisableIternalPullUp(SWITCH_TYPE SWITCH_CONF);







#endif





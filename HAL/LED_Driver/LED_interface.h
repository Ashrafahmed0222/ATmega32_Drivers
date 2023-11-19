/*
********************************************* LED_interface.h ************************************************
*  Author:  Ashraf Ahmed Hamed
*  Date:    2/13/2023
*  Layer:   HAL
*  SWC:     LED
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"



#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#define ACTIVE_HIGH 1
#define ACTIVE_LOW 0

#define LED_PIN_HIGH 1
#define LED_PIN_LOW 0

#define LED_PORTA 0
#define LED_PORTB 1
#define LED_PORTC 2
#define LED_PORTD 3


#define LED_PIN0 0
#define LED_PIN1 1
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5
#define LED_PIN6 6
#define LED_PIN7 7


typedef struct
{
	u8 Port;
	u8 Pin;
	u8 Active_State;
}LED_CONF;

void LED_voidInIt  (LED_CONF LED_CONFIGRATION);
void LED_voidON    (LED_CONF LED_CONFIGRATION);
void LED_voidOFF   (LED_CONF LED_CONFIGRATION);
void LED_voidToggle(LED_CONF LED_CONFIGRATION);










#endif

/*
********************************************* LED_program.c ************************************************
*  Author:  Ashraf Ahmed Hamed
*  Date:    2/13/2023
*  Layer:   HAL
*  SWC:     LED
*/



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*---------------------------------------*/

#include "../../MCAL/DIO_Driver/DIO_interface.h"
/*--------------------------------------*/

#include "LED_interface.h"


/*Initializing the LED*/
void LED_voidInIt  (LED_CONF LED_CONFIGRATION)
{
	DIO_enumSetPinDirection(LED_CONFIGRATION.Port, LED_CONFIGRATION.Pin, DIO_PIN_OUTPUT);
}

/*-------------------------------------------------------------------------------------*/


void LED_voidON    (LED_CONF LED_CONFIGRATION)
{
	if(LED_CONFIGRATION.Active_State == ACTIVE_HIGH)
	{
		DIO_enumSetPinValue(LED_CONFIGRATION.Port, LED_CONFIGRATION.Pin, LED_PIN_HIGH);
	}
	else if(LED_CONFIGRATION.Active_State == ACTIVE_LOW)
	{
		DIO_enumSetPinValue(LED_CONFIGRATION.Port, LED_CONFIGRATION.Pin, LED_PIN_LOW);
	}
}

/*-------------------------------------------------------------------------------------------*/


void LED_voidOFF   (LED_CONF LED_CONFIGRATION)
{
	if(LED_CONFIGRATION.Active_State == ACTIVE_HIGH)
		{
			DIO_enumSetPinValue(LED_CONFIGRATION.Port, LED_CONFIGRATION.Pin, LED_PIN_LOW);
		}
		else if(LED_CONFIGRATION.Active_State == ACTIVE_LOW)
		{
			DIO_enumSetPinValue(LED_CONFIGRATION.Port, LED_CONFIGRATION.Pin, LED_PIN_HIGH);
		}
}

/*------------------------------------------------------------------------------------------*/



void LED_voidToggle(LED_CONF LED_CONFIGRATION)
{
	DIO_enumTogglePinValue(LED_CONFIGRATION.Port, LED_CONFIGRATION.Pin);
}

/*-----------------------------------------------------------------------------------------*/














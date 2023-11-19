




/*
********************************************* BUZZER_PROGRAM.C ************************************************
*  Author:  Ashraf Ahmed Hamed
*  Date:    2/13/2023
*  Layer:   HAL
*  SWC:     Buzzer
*/



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*---------------------------------------*/

#include "../../MCAL/DIO_Driver/DIO_interface.h"

/*---------------------------------------*/

#include "Buzzer_interface.h"

/*--------------------------------------*/



void BUZZER_voidInit        ( BUZZER_CONF BUZZER_Configuration ){

	DIO_enumSetPinDirection(BUZZER_Configuration.Port, BUZZER_Configuration.Pin, DIO_PIN_OUTPUT);

}

void BUZZER_voidOn          ( BUZZER_CONF BUZZER_Configuration ){

	if( BUZZER_Configuration.Active_State == ACTIVE_HIGH ){

			DIO_enumSetPinValue( BUZZER_Configuration.Port , BUZZER_Configuration.Pin , DIO_PIN_HIGH );

		}
	else if( BUZZER_Configuration.Active_State == ACTIVE_LOW ){

			DIO_enumSetPinValue( BUZZER_Configuration.Port , BUZZER_Configuration.Pin , DIO_PIN_LOW  );

		}

}

void BUZZER_voidOff         ( BUZZER_CONF BUZZER_Configuration ){

	if( BUZZER_Configuration.Active_State == ACTIVE_HIGH ){

				DIO_enumSetPinValue( BUZZER_Configuration.Port , BUZZER_Configuration.Pin , DIO_PIN_LOW );

			}
		else if( BUZZER_Configuration.Active_State == ACTIVE_LOW ){

				DIO_enumSetPinValue( BUZZER_Configuration.Port , BUZZER_Configuration.Pin , DIO_PIN_HIGH  );

			}

}

void BUZZER_voidToggle      ( BUZZER_CONF BUZZER_Configuration ){

	DIO_enumTogglePinValue(BUZZER_Configuration.Port, BUZZER_Configuration.Pin);

}


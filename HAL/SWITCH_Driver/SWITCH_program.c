/*
 ********************************************* SWITCH_PROGRAM.c ************************************************
 *  Author:  Ashraf Ahmed Hamed
 *  Date:    2/19/2023
 *  Layer:   HAL
 *  SWC:     SWITCH
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#include "../../MCAL/DIO_Driver/DIO_interface.h"
#include "../../MCAL/DIO_Driver/DIO_private.h"


#include "SWITCH_interface.h"

void SWITCH_voidInitial(SWITCH_TYPE SWITCH_CONF) {
	DIO_enumSetPinDirection(SWITCH_CONF.Port, SWITCH_CONF.Pin, DIO_PIN_INPUT);
	if (SWITCH_CONF.Pull_State == SWITCH_INT_PULL_UP) {
		DIO_enumSetPinValue(SWITCH_CONF.Port, SWITCH_CONF.Pin, DIO_PIN_HIGH);
	}

}

u8 SWITCH_u8getPressed(SWITCH_TYPE SWITCH_CONF) {
	if (SWITCH_CONF.Pull_State == SWITCH_EXT_PULL_UP
			|| SWITCH_CONF.Pull_State == SWITCH_INT_PULL_UP) {
		switch (SWITCH_CONF.Port) {

		case DIO_PORTA:
			if (GET_BIT(PINA,SWITCH_CONF.Pin) == DIO_PIN_LOW) {
				return SWITCH_PRESSED;
			} else {
				return SWITCH_NOT_PRESSED;
			}
			break;
		case DIO_PORTB:
			if (GET_BIT(PINB,SWITCH_CONF.Pin) == DIO_PIN_LOW) {
				return SWITCH_PRESSED;
			} else {
				return SWITCH_NOT_PRESSED;
			}
			break;
		case DIO_PORTC:
			if (GET_BIT(PINC,SWITCH_CONF.Pin) == DIO_PIN_LOW) {
				return SWITCH_PRESSED;
			} else {
				return SWITCH_NOT_PRESSED;
			}
			break;
		case DIO_PORTD:
			if (GET_BIT(PIND,SWITCH_CONF.Pin) == DIO_PIN_LOW) {
				return SWITCH_PRESSED;
			} else {
				return SWITCH_NOT_PRESSED;
			}
			break;
		default:
			return SWITCH_NOT_PRESSED;
		}
	} else if (SWITCH_CONF.Pull_State == SWITCH_EXT_PULL_DOWN) {
		switch (SWITCH_CONF.Port) {

		case DIO_PORTA:
			if (GET_BIT(PINA,SWITCH_CONF.Pin) == DIO_PIN_HIGH) {
				return SWITCH_PRESSED;
			} else {
				return SWITCH_NOT_PRESSED;
			}
			break;
		case DIO_PORTB:
			if (GET_BIT(PINB,SWITCH_CONF.Pin) == DIO_PIN_HIGH) {
				return SWITCH_PRESSED;
			} else {
				return SWITCH_NOT_PRESSED;
			}
			break;
		case DIO_PORTC:
			if (GET_BIT(PINC,SWITCH_CONF.Pin) == DIO_PIN_HIGH) {
				return SWITCH_PRESSED;
			} else {
				return SWITCH_NOT_PRESSED;
			}
			break;
		case DIO_PORTD:
			if (GET_BIT(PIND,SWITCH_CONF.Pin) == DIO_PIN_HIGH) {
				return SWITCH_PRESSED;
			} else {
				return SWITCH_NOT_PRESSED;
			}
			break;
		default:
			return SWITCH_NOT_PRESSED;
		}
	} else
		return SWITCH_NOT_PRESSED;

}

void SWITCH_voidEnableIternalPullUp(SWITCH_TYPE SWITCH_CONF) {
	switch (SWITCH_CONF.Port) {
	case DIO_PORTA:
		DIO_enumSetPinValue(PORTA, SWITCH_CONF.Pin, DIO_PIN_HIGH);
		break;
	case DIO_PORTB:
		DIO_enumSetPinValue(PORTB, SWITCH_CONF.Pin, DIO_PIN_HIGH);
		break;
	case DIO_PORTC:
		DIO_enumSetPinValue(PORTC, SWITCH_CONF.Pin, DIO_PIN_HIGH);
		break;
	case DIO_PORTD:
		DIO_enumSetPinValue(PORTD, SWITCH_CONF.Pin, DIO_PIN_HIGH);
		break;
	default:break;

	}

}

void SWITCH_voidDisableIternalPullUp(SWITCH_TYPE SWITCH_CONF) {
	switch (SWITCH_CONF.Port) {
		case DIO_PORTA:
			DIO_enumSetPinValue(PORTA, SWITCH_CONF.Pin, DIO_PIN_LOW);
			break;
		case DIO_PORTB:
			DIO_enumSetPinValue(PORTB, SWITCH_CONF.Pin, DIO_PIN_LOW);
			break;
		case DIO_PORTC:
			DIO_enumSetPinValue(PORTC, SWITCH_CONF.Pin, DIO_PIN_LOW);
			break;
		case DIO_PORTD:
			DIO_enumSetPinValue(PORTD, SWITCH_CONF.Pin, DIO_PIN_LOW);
			break;
		default:break;

		}
}


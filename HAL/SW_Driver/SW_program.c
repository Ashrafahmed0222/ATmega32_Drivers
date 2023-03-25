/*
 ********************************************* SW_PROGRAM.c ************************************************
 *  Author:  Ashraf Ahmed Hamed
 *  Date:    2/19/2023
 *  Layer:   HAL
 *  SWC:     SWITCH
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#include "../../MCAL/DIO_Driver/DIO_interface.h"
#include "../../MCAL/DIO_Driver/DIO_private.h"


#include "SW_interface.h"

void SW_voidInitial(SW_TYPE SW_CONF) {
	DIO_enumSetPinDirection(SW_CONF.Port, SW_CONF.Pin, DIO_PIN_INPUT);
	if (SW_CONF.Pull_State == SW_INT_PULL_UP) {
		DIO_enumSetPinValue(SW_CONF.Port, SW_CONF.Pin, DIO_PIN_HIGH);
	}

}

u8 SW_u8getPressed(SW_TYPE SW_CONF) {
	if (SW_CONF.Pull_State == SW_EXT_PULL_UP
			|| SW_CONF.Pull_State == SW_INT_PULL_UP) {
		switch (SW_CONF.Port) {

		case DIO_PORTA:
			if (GET_BIT(PINA,SW_CONF.Pin) == DIO_PIN_LOW) {
				return SW_PRESSED;
			} else {
				return SW_NOT_PRESSED;
			}
			break;
		case DIO_PORTB:
			if (GET_BIT(PINB,SW_CONF.Pin) == DIO_PIN_LOW) {
				return SW_PRESSED;
			} else {
				return SW_NOT_PRESSED;
			}
			break;
		case DIO_PORTC:
			if (GET_BIT(PINC,SW_CONF.Pin) == DIO_PIN_LOW) {
				return SW_PRESSED;
			} else {
				return SW_NOT_PRESSED;
			}
			break;
		case DIO_PORTD:
			if (GET_BIT(PIND,SW_CONF.Pin) == DIO_PIN_LOW) {
				return SW_PRESSED;
			} else {
				return SW_NOT_PRESSED;
			}
			break;
		default:
			return SW_NOT_PRESSED;
		}
	} else if (SW_CONF.Pull_State == SW_EXT_PULL_DOWN) {
		switch (SW_CONF.Port) {

		case DIO_PORTA:
			if (GET_BIT(PINA,SW_CONF.Pin) == DIO_PIN_HIGH) {
				return SW_PRESSED;
			} else {
				return SW_NOT_PRESSED;
			}
			break;
		case DIO_PORTB:
			if (GET_BIT(PINB,SW_CONF.Pin) == DIO_PIN_HIGH) {
				return SW_PRESSED;
			} else {
				return SW_NOT_PRESSED;
			}
			break;
		case DIO_PORTC:
			if (GET_BIT(PINC,SW_CONF.Pin) == DIO_PIN_HIGH) {
				return SW_PRESSED;
			} else {
				return SW_NOT_PRESSED;
			}
			break;
		case DIO_PORTD:
			if (GET_BIT(PIND,SW_CONF.Pin) == DIO_PIN_HIGH) {
				return SW_PRESSED;
			} else {
				return SW_NOT_PRESSED;
			}
			break;
		default:
			return SW_NOT_PRESSED;
		}
	} else
		return SW_NOT_PRESSED;

}

void SW_voidEnableIternalPullUp(SW_TYPE SW_CONF) {
	switch (SW_CONF.Port) {
	case DIO_PORTA:
		DIO_enumSetPinValue(PORTA, SW_CONF.Pin, DIO_PIN_HIGH);
		break;
	case DIO_PORTB:
		DIO_enumSetPinValue(PORTB, SW_CONF.Pin, DIO_PIN_HIGH);
		break;
	case DIO_PORTC:
		DIO_enumSetPinValue(PORTC, SW_CONF.Pin, DIO_PIN_HIGH);
		break;
	case DIO_PORTD:
		DIO_enumSetPinValue(PORTD, SW_CONF.Pin, DIO_PIN_HIGH);
		break;
	default:break;

	}

}

void SW_voidDisableIternalPullUp(SW_TYPE SW_CONF) {
	switch (SW_CONF.Port) {
		case DIO_PORTA:
			DIO_enumSetPinValue(PORTA, SW_CONF.Pin, DIO_PIN_LOW);
			break;
		case DIO_PORTB:
			DIO_enumSetPinValue(PORTB, SW_CONF.Pin, DIO_PIN_LOW);
			break;
		case DIO_PORTC:
			DIO_enumSetPinValue(PORTC, SW_CONF.Pin, DIO_PIN_LOW);
			break;
		case DIO_PORTD:
			DIO_enumSetPinValue(PORTD, SW_CONF.Pin, DIO_PIN_LOW);
			break;
		default:break;

		}
}


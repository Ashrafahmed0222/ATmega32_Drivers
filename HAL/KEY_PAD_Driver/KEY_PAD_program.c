


/*
 ********************************************* KEY_PAD_program.c ************************************************
 *  Author:  Ashraf Ahmed Hamed
 *  Date:    4/6/2023
 *  Layer:   HAL
 *  SWC:     KeyPad
 */

#include "../../MCAL/DIO_Driver/DIO_interface.h"

#include "KEY_PAD_interface.h"
#include "KEY_PAD_private.h"
#include "KEY_PAD_config.h"

#include <util/delay.h>

void KEY_PAD_voidInit(void){
	DIO_enumConnectPullUp(KEY_PAD_PORT, KEY_PAD_R0, DIO_PIN_HIGH);
	DIO_enumConnectPullUp(KEY_PAD_PORT, KEY_PAD_R1, DIO_PIN_HIGH);
	DIO_enumConnectPullUp(KEY_PAD_PORT, KEY_PAD_R2, DIO_PIN_HIGH);
	DIO_enumConnectPullUp(KEY_PAD_PORT, KEY_PAD_R3, DIO_PIN_HIGH);

	DIO_enumSetPinDirection(KEY_PAD_PORT, KEY_PAD_C0, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(KEY_PAD_PORT, KEY_PAD_C1, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(KEY_PAD_PORT, KEY_PAD_C2, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(KEY_PAD_PORT, KEY_PAD_C3, DIO_PIN_OUTPUT);

	DIO_enumSetPinValue(KEY_PAD_PORT, KEY_PAD_C0, DIO_PIN_HIGH);
	DIO_enumSetPinValue(KEY_PAD_PORT, KEY_PAD_C1, DIO_PIN_HIGH);
	DIO_enumSetPinValue(KEY_PAD_PORT, KEY_PAD_C2, DIO_PIN_HIGH);
	DIO_enumSetPinValue(KEY_PAD_PORT, KEY_PAD_C3, DIO_PIN_HIGH);

}
u8 KEY_PAD_u8GetPressed(void){
	u8 LOC_u8ReturnData = NOT_PRESSED;
	u8 LOC_u8GetPressed ;
	u8 LOC_u8ROW;
	u8 LOC_u8COL;


	for(LOC_u8COL = 0 + KEY_PAD_COLUMN_Init ;LOC_u8COL < KEY_PAD_COLUMN_End; LOC_u8COL++){
		DIO_enumSetPinValue(KEY_PAD_PORT, LOC_u8COL, DIO_PIN_LOW);
		for(LOC_u8ROW = 0 + KEY_PAD_ROW_Init ;LOC_u8ROW < KEY_PAD_ROW_End; LOC_u8ROW++){
			DIO_enumGetPinValue(KEY_PAD_PORT, LOC_u8ROW, &LOC_u8GetPressed);
			if(LOC_u8GetPressed == 0){
				_delay_ms(20);
				DIO_enumGetPinValue(KEY_PAD_PORT, LOC_u8ROW, &LOC_u8GetPressed);
				if(LOC_u8GetPressed == 0){
					LOC_u8ReturnData = KEY_PAD_u8Buttons[LOC_u8ROW - KEY_PAD_ROW_Init][LOC_u8COL -  KEY_PAD_COLUMN_Init];
				}
				DIO_enumGetPinValue(KEY_PAD_PORT, LOC_u8ROW, &LOC_u8GetPressed);
				while( LOC_u8GetPressed == DIO_PIN_LOW ){
					DIO_enumGetPinValue(KEY_PAD_PORT, LOC_u8ROW, &LOC_u8GetPressed);
				}
				break;
			}

		}
		DIO_enumSetPinValue(KEY_PAD_PORT, LOC_u8COL, DIO_PIN_HIGH);
	}
	return LOC_u8ReturnData;


}











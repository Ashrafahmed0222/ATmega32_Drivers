#include <util/delay.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO_Driver/DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"
#include "CLCD_externalChars.h"
void CLCD_voidInit(void) {

	DIO_enumSetPortDirection( CLCD_DATA_PORT, 0xFF);
	DIO_enumSetPinDirection( CLCD_CONTROL_PORT, CLCD_RS, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection( CLCD_CONTROL_PORT, CLCD_RW, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection( CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_OUTPUT);

	_delay_ms(100);

	CLCD_voidSendCommand(lcd_Home);
	_delay_ms(5);

	CLCD_voidSendCommand( lcd_DispalyOn_CursorOff);
	_delay_ms(5);

	CLCD_voidClearScreen();

	_delay_ms(5);

	CLCD_voidSendCommand( lcd_EntryMode);
	_delay_ms(10);

}

void CLCD_voidSendData(u8 copy_u8Data) {

	DIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_RS, DIO_PIN_HIGH);
	DIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_RW, DIO_PIN_LOW);
	DIO_enumSetPortValue(CLCD_DATA_PORT, copy_u8Data);
	CLCD_voidSendFallingEdge();

}

void CLCD_voidSendCommand(u8 Copy_u8Command) {

	DIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_RS, DIO_PIN_LOW);
	DIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_RW, DIO_PIN_LOW);
	DIO_enumSetPortValue(CLCD_DATA_PORT, Copy_u8Command);
	CLCD_voidSendFallingEdge();

}

void CLCD_voidSendFallingEdge(void) {
	DIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_LOW);
	_delay_ms(1);

}

void CLCD_voidClearScreen(void) {
	CLCD_voidSendCommand(lcd_Clear);
	_delay_ms(10);

}

void CLCD_voidSendString(const u8 *copy_u8ptrString) {
	u8 Loc_Iterator = 0;
	while (copy_u8ptrString[Loc_Iterator] != '\0') {
		CLCD_voidSendData(copy_u8ptrString[Loc_Iterator]);
		Loc_Iterator++;
	}
}
void CLCD_voidSetPosition(u8 Copy_u8ROW, u8 Copy_u8Column) {/*DDRAM*/
	u8 LCD_u8Data;
	if (Copy_u8ROW > 2 || Copy_u8ROW < 1 || Copy_u8Column < 1
			|| Copy_u8Column > 16) {
		LCD_u8Data = lcd_SetCurser;
	} else if (Copy_u8ROW == 1) {
		LCD_u8Data = lcd_SetCurser + (Copy_u8Column - 1);
	} else if (Copy_u8ROW == 2) {
		LCD_u8Data = lcd_SetCurser + 64 + (Copy_u8Column - 1);
	}
	CLCD_voidSendCommand(LCD_u8Data);
	_delay_ms(1);
}

void CLCD_voidSendExternAlChar(u8 Copy_u8ROW, u8 Copy_u8COLUMN) {
	u8 Loc_Iterator = 0;

	CLCD_voidSendCommand(lcd_CGRAM);

	for (Loc_Iterator = 0;
			Loc_Iterator
					< (sizeof(CLCD_u8ExternalChars)
							/ sizeof(CLCD_u8ExternalChars[0]));
			Loc_Iterator++) {
		CLCD_voidSendData(CLCD_u8ExternalChars[Loc_Iterator]);
	}

	CLCD_voidSetPosition(Copy_u8ROW, Copy_u8COLUMN);

	for (Loc_Iterator = 0; Loc_Iterator < 8; Loc_Iterator++) {
		CLCD_voidSendData(Loc_Iterator);
	}

}





















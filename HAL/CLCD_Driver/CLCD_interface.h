









/*
********************************************* CLCD_INTERFACE.h ************************************************
*  Author:  Ashraf Ahmed Hamed
*  Date:    2/19/2023
*  Layer:   HAL
*  SWC:     CLCD
*/



#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"



#ifndef _CLCD_INTERFACE_H_
#define _CLCD_INTERFACE_H_

#include "CLCD_config.h"


#if CLCD_MODE == 4
#define FOUR_BITS    0x28
#elif CLCD_MODE == 8
#define EIGHT_BITS   0x38
#endif


#define lcd_DispalyOn_CursorOff     0x0C
#define lcd_DispalyOn_CursorOn      0x0e
#define lcd_DispalyOff_CursorOff    0x08
#define lcd_Clear                   0x01
#define lcd_EntryMode               0x06
#define lcd_Home                    0x02
#define lcd_CGRAM                   0x40
#define lcd_SetCurser               0x80
#define lcd_FunctionReset           0x30



#define LCD_ROW1  1
#define LCD_ROW2  2

#define LCD_COLUMN1    1
#define LCD_COLUMN2    2
#define LCD_COLUMN3    3
#define LCD_COLUMN4    4
#define LCD_COLUMN5    5
#define LCD_COLUMN6    6
#define LCD_COLUMN7    7
#define LCD_COLUMN8    8
#define LCD_COLUMN9    9
#define LCD_COLUMN10  10
#define LCD_COLUMN11  11
#define LCD_COLUMN12  12
#define LCD_COLUMN13  13
#define LCD_COLUMN14  14
#define LCD_COLUMN15  15
#define LCD_COLUMN16  16



void CLCD_voidInit             (void);
void CLCD_voidSendData         (u8 copy_u8Data);
void CLCD_voidSendCommand      (u8 Copy_u8Command);
void CLCD_voidSendString       (const u8 *copy_u8ptrString);
void CLCD_voidClearScreen      (void);
void CLCD_voidSetposition      (u8 Copy_u8ROW, u8 COPY_u8Column);





#endif




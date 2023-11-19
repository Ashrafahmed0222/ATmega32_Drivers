




/*
********************************************* BUZZER_INTERFACE.h ************************************************
*  Author:  Ashraf Ahmed Hamed
*  Date:    2/13/2023
*  Layer:   HAL
*  SWC:     Buzzer
*/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*--------------------------------------------------------------------------------------------*/

#ifndef _BUZZER_INTERFACE_H_
#define _BUZZER_INTERFACE_H_


// BUZZER PORT
#define  BUZZER_PORTA  0
#define  BUZZER_PORTB  1
#define  BUZZER_PORTC  2
#define  BUZZER_PORTD  3


// BUZZER PIN
#define BUZZER_PIN0   0
#define BUZZER_PIN1   1
#define BUZZER_PIN2   2
#define BUZZER_PIN3   3
#define BUZZER_PIN4   4
#define BUZZER_PIN5   5
#define BUZZER_PIN6   6
#define BUZZER_PIN7   7


//ACTIVE STATE
#define ACTIVE_HIGH    1
#define ACTIVE_LOW     0


//BUZZER CONFIGRATION
typedef struct{

	u8 Port         ;
	u8 Pin          ;
	u8 Active_State ;

}BUZZER_CONF;


void BUZZER_voidInit        ( BUZZER_CONF BUZZER_Configuration );

void BUZZER_voidOn          ( BUZZER_CONF BUZZER_Configuration );

void BUZZER_voidOff         ( BUZZER_CONF BUZZER_Configuration );

void BUZZER_voidToggle      ( BUZZER_CONF BUZZER_Configuration );















#endif

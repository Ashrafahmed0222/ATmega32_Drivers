









/*
********************************************* CLCD_CONFIG.h ************************************************
*  Author:  Ashraf Ahmed Hamed
*  Date:    2/19/2023
*  Layer:   HAL
*  SWC:     CLCD
*/


#include "../../MCAL/DIO_Driver/DIO_interface.h"




#ifndef _CLCD_CONFIG_H_
#define _CLCD_CONFIG_H_


#define CLCD_MODE 8



#define CLCD_RS DIO_PIN0
#define CLCD_RW DIO_PIN1
#define CLCD_EN DIO_PIN2


#define CLCD_DATA_PORT          DIO_PORTA
#define CLCD_CONTROL_PORT  DIO_PORTC











#endif




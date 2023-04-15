




/*
********************************************* EXTI_private.h ************************************************
*  Author:  Ashraf Ahmed Hamed
*  Date:    4/15/2023
*  Layer:   M_CAL
*  SWC:     EXTERNAL INTERRUPT
*/

#include "../DIO_Driver/DIO_interface.h"

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_


#define MCUCR_REG   *((volatile u8 *)0x55)
#define MCUCSR_REG  *((volatile u8 *)0x54)
#define GICR_REG    *((volatile u8 *)0x5B)
#define GIFR_REG    *((volatile u8 *)0x5A)




#endif

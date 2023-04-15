







/*
********************************************* EXTI_interface.h ************************************************
*  Author:  Ashraf Ahmed Hamed
*  Date:    4/15/2023
*  Layer:   M_CAL
*  SWC:     EXTERNAL INTERRUPT
*/

#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_


#define EXTI_LINE0 6
#define EXTI_LINE1 7
#define EXTI_LINE2 5

#define EXTI_FALLING_EDGE  0
#define EXTI_RISING_EDGE   1
#define EXTI_LOW_LEVEL     2
#define EXTI_ON_CHANGE     3


#define NULL 0


void EXTI_voidInit            (void);
void EXTI_voidSendSignalLatch (u8 Copy_u8SenceMode, u8 Copy_u8Line);
u8 EXTI_voidDisableInterrupt  (u8 Copy_u8Line);
u8 EXTI_voidEnableInterrupt   (u8 Copy_u8Line);
void EXTI_voidClearFalg       (u8 Copy_u8Line);
u8 EXTI_u8GetFlag             (u8 Copy_u8Line);
void EXTI_voidSetCallBack     (void(*copy_pvoidCallBack)(void), u8 Copy_u8EXTI_LINE);









#endif


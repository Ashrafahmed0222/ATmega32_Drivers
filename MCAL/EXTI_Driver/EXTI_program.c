
/*
 ********************************************* EXTI_program.c ************************************************
 *  Author:  Ashraf Ahmed Hamed
 *  Date:    4/15/2023
 *  Layer:   M_CAL
 *  SWC:     EXTERNAL INTERRUPT
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO_Driver/DIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"



void (*EXTI_CallBack[3])(void) = {NULL};

void EXTI_voidInit            (void){
#ifdef EXTI_LINE

		#if EXTI_LINE == EXTI_LINE1


			#if     EXTI_SENSE_MODE == EXTI_LOW_LEVEL

				CLR_BIT( MCUCR_REG , 2 ); CLR_BIT( MCUCR_REG , 3 );

			#elif     EXTI_SENSE_MODE == EXTI_ON_CHANGE

				SET_BIT( MCUCR_REG , 2 ); CLR_BIT( MCUCR_REG , 3 );

			#elif     EXTI_SENSE_MODE == EXTI_FALLING_EDGE

				CLR_BIT( MCUCR_REG , 2 ); SET_BIT( MCUCR_REG , 3 );

			#elif     EXTI_SENSE_MODE == EXTI_RISING_EDGE

				SET_BIT( MCUCR_REG , 2 ); SET_BIT( MCUCR_REG , 3 );

			#endif


		#elif EXTI_LINE == EXTI_LINE0

			#if     EXTI_SENSE_MODE == EXTI_LOW_LEVEL

				CLR_BIT( MCUCR_REG , 0 ); CLR_BIT( MCUCR_REG , 1 );

			#elif     EXTI_SENSE_MODE == EXTI_ON_CHANGE

				SET_BIT( MCUCR_REG , 0 ); CLR_BIT( MCUCR_REG , 1 );

			#elif     EXTI_SENSE_MODE == EXTI_FALLING_EDGE

				CLR_BIT( MCUCR_REG , 0 ); SET_BIT( MCUCR_REG , 1 );

			#elif     EXTI_SENSE_MODE == EXTI_RISING_EDGE

				SET_BIT( MCUCR_REG , 0 ); SET_BIT( MCUCR_REG , 1 );

			#endif

		#elif EXTI_LINE == EXTI_LINE2

				#if     EXTI_SENSE_MODE == EXTI_FALLING_EDGE

					CLR_BIT( MCUCSR_REG , 6 );

				#elif     EXTI_SENSE_MODE == EXTI_RISING_EDGE

					SET_BIT( MCUCSR_REG , 6 );

				#endif

		#else
				#error "Wrong INT0_SENSE configuration option (Choose The Right One)"

		#endif

	#endif
}

//Runtime configuration  (Post Build)
void EXTI_voidSendSignalLatch (u8 Copy_u8SenseMode,u8 Copy_u8Line){
	if( Copy_u8Line >= EXTI_LINE0 && Copy_u8Line <= EXTI_LINE1 ){

		Copy_u8Line = ( 6 - Copy_u8Line ) * -2 ;
		// if EXTI_LINE0  then Copy_u8Line = 6
		// if EXTI_LINE1  then Copy_u8Line = 7
		// then select the right bits to clear or set

		switch( Copy_u8SenseMode ){
		case EXTI_LOW_LEVEL    : CLR_BIT( MCUCR_REG , Copy_u8Line ); CLR_BIT( MCUCR_REG , (Copy_u8Line + 1 )); break;
		case EXTI_ON_CHANGE    : SET_BIT( MCUCR_REG , Copy_u8Line ); CLR_BIT( MCUCR_REG , (Copy_u8Line + 1 ) ); break;
		case EXTI_FALLING_EDGE : CLR_BIT( MCUCR_REG , Copy_u8Line ); SET_BIT( MCUCR_REG , (Copy_u8Line + 1 ) ); break;
		case EXTI_RISING_EDGE  : SET_BIT( MCUCR_REG , Copy_u8Line ); SET_BIT( MCUCR_REG , (Copy_u8Line + 1 ) ); break;

		}
	}

	else{

		switch( Copy_u8SenseMode ){

		case EXTI_FALLING_EDGE : CLR_BIT( MCUCSR_REG , 6 );  break;
		case EXTI_RISING_EDGE  : SET_BIT( MCUCSR_REG , 6 );  break;

		}

	}
}

u8 EXTI_voidDisableInterrupt(u8 Copy_u8Line) {
	u8 Local_u8ErrorState = DIO_OK;
	if ((Copy_u8Line > EXTI_LINE2) && (Copy_u8Line < EXTI_LINE1)) /* Check [5:7] */
	{

		CLR_BIT(GICR_REG, Copy_u8Line);
	} else {
		Local_u8ErrorState = DIO_NOK;
	}

	return Local_u8ErrorState;
}

u8 EXTI_voidEnableInterrupt(u8 Copy_u8Line) {
	u8 Local_u8ErrorState = DIO_OK;
	if ((Copy_u8Line > EXTI_LINE2) && (Copy_u8Line < EXTI_LINE1)) /* Check [5:7] */
	{
		SET_BIT(GICR_REG, Copy_u8Line);
	} else {
		Local_u8ErrorState = DIO_NOK;
	}

	return Local_u8ErrorState;
}


void EXTI_voidClearFlag ( u8 Copy_u8Line ){

	SET_BIT( GIFR_REG , Copy_u8Line );

}

u8 EXTI_u8GetFlag( u8 Copy_u8Line ){

	return GET_BIT( GIFR_REG , Copy_u8Line );

}


void EXTI_voidSetCallBack(void(*copy_pvoidCallBack)(void), u8 Copy_u8EXTI_LINE){
	if(copy_pvoidCallBack != NULL){
		EXTI_CallBack[Copy_u8EXTI_LINE] = copy_pvoidCallBack;
	}
}


void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	if(EXTI_CallBack[0] != NULL){
		EXTI_CallBack[0]();
		EXTI_voidClearFlag(EXTI_LINE0);
	}
}


void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if(EXTI_CallBack[1] != NULL){
		EXTI_CallBack[1]();
		EXTI_voidClearFlag(EXTI_LINE1);
	}
}


void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	if(EXTI_CallBack[2] != NULL){
		EXTI_CallBack[3]();
		EXTI_voidClearFlag(EXTI_LINE2);
	}
}



















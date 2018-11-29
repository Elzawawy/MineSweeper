/*
 * Timer0_prog.c
 *
 *  Created on: 26 September, 2018
 *      Author: Amr Elzawawy
 */
#include "../libs/STD_TYPES.h"
#include "../libs/Registers.h"
#include "../utils/BIT_LIB.h"
#include "Timer0_int.h"
#include "Timer0_config.h"
#include "Timer0_private.h"
void Timer0_voidInit(void)
{
    TCCR0 = TCCR0_INITVAL;
    ASSIGN_BIT(TIMSK,OCIE0,OCIE0_VAL);
    ASSIGN_BIT(TIMSK,TOIE0,TOIE0_VAL);
}


u8 Timer0_u8SetTCNT(u8 Copy_u8value){
    Timer0_enuState Local_TimerState;
    TCNT0 = Copy_u8value;
    Local_TimerState=Timer0_enuNormalState;
    return Local_TimerState;
}

u8 Timer0_u8SetOCR(u8 Copy_u8value){
    Timer0_enuState Local_TimerState;
    OCR0 = Copy_u8value;
    Local_TimerState=Timer0_enuNormalState;
    return Local_TimerState;
}

u8 Timer0_u8EnableOverflowInt(void)
{
    Timer0_enuState Local_TimerState;
    if( voidPtrToOVISR != NULL)
    {
        RESET_BIT(TIMSK,OCIE0);
        SET_BIT(TIMSK,TOIE0);
        SET_BIT(SREG,I);
        Local_TimerState = Timer0_enuNormalState;
    }
    else 
        Local_TimerState = Timer0_enuInterruptError;
    return Local_TimerState;
}
u8 Timer0_u8EnableCompareMatchInt(void)
{
    Timer0_enuState Local_TimerState;
    if( voidPtrToCMISR != NULL )
    {
        RESET_BIT(TIMSK,TOIE0);
        SET_BIT(TIMSK,OCIE0);
        SET_BIT(SREG,I);
        Local_TimerState = Timer0_enuNormalState;
    }
    else 
        Local_TimerState = Timer0_enuInterruptError;
    return Local_TimerState;
}

u8 Timer0_u8SetOverflowInt(void (* voidPtrToFunc) (void))
{
    Timer0_enuState Local_TimerState;
    if( voidPtrToFunc != NULL )
    {
        voidPtrToOVISR = voidPtrToFunc;
        Local_TimerState = Timer0_enuNormalState;
    }
    else 
        Local_TimerState = Timer0_enuNullPointerException;

    return Local_TimerState;   
    
}

u8 Timer0_u8SetCompareMatchInt(void (* voidPtrToFunc) (void))
{
    Timer0_enuState Local_TimerState;
    if( voidPtrToFunc != NULL )
    {
        voidPtrToCMISR = voidPtrToFunc;
        Local_TimerState = Timer0_enuNormalState;
    }
    else 
        Local_TimerState = Timer0_enuNullPointerException;

    return Local_TimerState;   
    
}

ISR(__vector_11) {
    voidPtrToOVISR();
}

ISR(__vector_10) {
    voidPtrToCMISR();
}

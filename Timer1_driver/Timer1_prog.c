/*
 * TIMER1_PROG.c
 *
 *  Created on: Nov 22, 2018
 *      Author: Abdallah
 */
#include "../libs/STD_TYPES.h"
#include "../utils/BIT_LIB.h"
#include "../libs/Registers.h"
#include "Timer1_int.h"
#include "Timer1_config.h"
#include "Timer1_private.h"

void Timer1_voidInit(void)
{
	ASSIGN_BIT(TCCR1A,WGM10,WGM10_VAL);
	ASSIGN_BIT(TCCR1A,WGM11,WGM11_VAL);
	ASSIGN_BIT(TCCR1A,COM1A1,COM1A1_VAL);
	ASSIGN_BIT(TCCR1A,COM1A0,COM1A0_VAL);
	ASSIGN_BIT(TCCR1A,COM1B1,COM1B1_VAL);
	ASSIGN_BIT(TCCR1A,COM1B0,COM1B0_VAL);
	ASSIGN_BIT(TCCR1B,WGM12,WGM12_VAL);
	ASSIGN_BIT(TCCR1B,WGM13,WGM13_VAL);
	ASSIGN_BIT(TCCR1B,CS10,CS10_VAL);
	ASSIGN_BIT(TCCR1B,CS11,CS11_VAL);
	ASSIGN_BIT(TCCR1B,CS12,CS12_VAL);
	ASSIGN_BIT(TCCR1B,ICNC1,ICNC1_VAL);
	ASSIGN_BIT(TCCR1B,ICES1_VAL,ICES1_VAL);
}

u8 Timer1_u8setTCNT1(u16 Copy_u16TCNT1Val)
{
	TCNT1 = Copy_u16TCNT1Val;
	return Timer1_enuNormalState;
}
u8 Timer1_u8getTCNT1(u16* u16_ptrtoVal)
{
	*u16_ptrtoVal = TCNT1;
	return Timer1_enuNormalState;

}

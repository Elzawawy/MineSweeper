/*
 * TIMER1_PROG.c
 *
 *  Created on: Nov 22, 2018
 *      Author: Abdallah
 */
#include "../libs/STD_TYPES.h"
#include "../utils/BIT_LIB.h"
#include "TIMER1_REG_DEFINE1.h"
#include "Timer1_int.h"
#include "Timer1_config.h"
#include "Timer1_private.h"

u8 TIMER1_INITALIZE()
{
	AssignBit(TCCR1A,WGM10,WGM10_VAL);
	AssignBit(TCCR1A,WGM11,WGM11_VAL);
	AssignBit(TCCR1A,COM1A1,COM1A1_VAL);
	AssignBit(TCCR1A,COM1A0,COM1A0_VAL);
	AssignBit(TCCR1A,COM1B1,COM1B1_VAL);
	AssignBit(TCCR1A,COM1B0,COM1B0_VAL);


	AssignBit(TCCR1B,WGM12,WGM12_VAL);
	AssignBit(TCCR1B,WGM13,WGM13_VAL);

	AssignBit(TCCR1B,CS10,CS10_VAL);
	AssignBit(TCCR1B,CS11,CS11_VAL);
	AssignBit(TCCR1B,CS12,CS12_VAL);

	AssignBit(TCCR1B,ICNC1,ICNC1_VAL);
	AssignBit(TCCR1B,ICES1_VAL,ICES1_VAL);

return NORMALSTATE;
}

u8 TIMER1_SET_TCNT1(u16 Copy_u16TCNT1Val)
{
	TCNT1 = Copy_u16TCNT1Val;
	return NORMALSTATE;
}
u8 TIMER1_GET_TCNT1(u16* u16_ptrtoVal)
{
	*u16_ptrtoVal = TCNT1;
	return NORMALSTATE;

}

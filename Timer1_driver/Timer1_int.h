/*
 * TIMER1_INT.h
 *
 *  Created on: Nov 22, 2018
 *      Author: Abdallah
 */
#ifndef TIMER1_INT_H_
#define TIMER1_INT_H_

enum TIMER1_ERRORTYPES{
	NORMALSTATE=0,
	NULLPOINTER,
};
enum TIMER_MODE{
	NORMAL=0,
	CTC,
	PWM,
	FAST_PWM,
};



void Timer1_voidInit();
u8 Timer1_u8setTimerR(u16 Copy_u16TCNT1Val);
u8 TIMER1_GET_TCNT1(u16*u16_ptrtoVal);


#endif /* TIMER1_INT_H_ */

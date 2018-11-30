/*
 * TIMER1_INT.h
 *
 *  Created on: Nov 22, 2018
 *      Author: Abdallah
 */
#ifndef TIMER1_INT_H_
#define TIMER1_INT_H_

typedef enum Timer1_enuState
{
	Timer1_enuNormalState,
	Timer1_enuNullPointerException
}Timer1_enuState;
typedef enum Timer1_enuWorkingMode
{
	Timer1_enuNormalMode=0,
	Timer1_enuCompareOutputMode,
	Timer1_enuPWM,
	TImer1_enuFastPWM,
}Timer1_enuWorkingMode;

typedef enum Timer1_enuRegister
{
	Timer1_enuTCNT,
	Timer1_enuOCR,
	Timer1_enuICR
}Timer1_enuRegister;

void Timer1_voidInit(void);
u8 Timer1_u8setTCNT1(u16 Copy_u16TCNT1Val);
u8 Timer1_u8getTCNT1(u16*u16_ptrtoVal);


#endif /* TIMER1_INT_H_ */

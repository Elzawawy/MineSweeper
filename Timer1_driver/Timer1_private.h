/*
 * TIMER1_PRIV.h
 *
 *  Created on: Nov 22, 2018
 *      Author: Abdallah
 */

#ifndef TIMER1_PRIV_H_
#define TIMER1_PRIV_H_
#define HIGH 1
#define LOW 0
#define NULL (void*)0X00
/////////////////////////TIMER1/////////////////////

//TCCR1A
#define WGM10 0
#define WGM11  1

#define COM1A1  7
#define COM1A0   6
#define COM1B1  5
#define COM1B0   4
//TCCR1A


//TCCR1B
#define WGM12 3
#define WGM13  4

#define CS10 0
#define CS11 1
#define CS12 2

#define ICNC1 6
#define ICES1 7
//TCCR1B


//TIMSK
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
//TIMSK

#define ISR(__vector_num) 															\
	void __vector_num(void)	__attribute__((signal,used,externally_visible));		\
	void __vector_num(void)
void (*ptrToFuncOVERFLOW)(void)=NULL;

void (*ptrToFuncCTC)(void)=NULL;



#endif /* TIMER1_PRIV_H_ */

/*
 * TIMER1_CONFIG.h
 *
 *  Created on: Nov 22, 2018
 *      Author: Abdallah
 */

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

#define LOW 0
#define HIGH 1
///////////////////TIMER1/////////////////////
//TCCR1A
#define WGM10_VAL LOW
#define WGM11_VAL  LOW

#define COM1A1_VAL  LOW
#define COM1A0_VAL   LOW
#define COM1B1_VAL  LOW
#define COM1B0_VAL   LOW
//TCCR1A


//TCCR1B
#define WGM12_VAL LOW
#define WGM13_VAL  LOW

#define CS10_VAL LOW
#define CS11_VAL HIGH
#define CS12_VAL LOW

#define ICNC1_VAL LOW
#define ICES1_VAL LOW
//TCCR1B


//TIMSK
#define TOIE1_VAL LOW
#define OCIE1B_VAL LOW
#define OCIE1A_VAL LOW
#define TICIE1_VAL LOW
//TIMSK



#endif /* TIMER1_CONFIG_H_ */

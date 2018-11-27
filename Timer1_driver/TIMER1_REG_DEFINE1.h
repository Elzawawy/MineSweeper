/*
 * TIMER1_REG_DEFINE1.h
 *
 *  Created on: Nov 22, 2018
 *      Author: Abdallah
 */

#ifndef TIMER1_REG_DEFINE1_H_
#define TIMER1_REG_DEFINE1_H_
///////////////////////////TIMER1////////////////////
#define TCCR1A     *((u8*)0X4F)
#define TCCR1B     *((u8*)0X4E)
#define TCNT1H     *((u8*)0X4D)
#define TCNT1L     *((u8*)0X4C)
#define TCNT1      *((u16*)0X4C)
#define OCR1AH     *((u8*)0X4B)
#define OCR1AL     *((u8*)0X4A)
#define OCR1BH     *((u8*)0X49)
#define OCR1BL     *((u8*)0X48)
#define ICR1H      *((u8*)0X47)
#define ICR1L      *((u8*)0X46)




#endif /* TIMER1_REG_DEFINE1_H_ */

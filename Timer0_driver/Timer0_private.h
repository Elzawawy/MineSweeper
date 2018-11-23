/*
 * Timer0_private.h
 *
 *  Created on: 26 September, 2018
 *      Author: Amr Elzawawy
 */

#define HIGH 1
#define LOW 0
#define NULL ( void * )0x00
/*************** Registers Addresses Definition *****************/

#define  TCCR0 	(*(volatile u8 *) 0x53 )
#define  TCNT0 	(*(volatile u8 *) 0x52 )
#define  OCR0	(*(volatile u8 *) 0x5C )
#define  TIMSK	(*(volatile u8 *) 0x59 )
#define  TIFR	(*(volatile u8 *) 0x58 )
#define  SREG   (*(volatile u8 *) 0x5F )

/*************** Registers Bits Definition *****************/
/* Timer/Counter0 Control Register – TCCR0 */
#define FOC0 7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02 2
#define CS01 1
#define CS00 0

/* Timer/Counter Interrupt Mask Register – TIMSK */
#define OCIE0 1
#define TOIE0 0

/* Timer/Counter Interrupt Flag Register – TIFR */
#define OCF0 1
#define TOV0 0

#define I 7

/*************** Registers Initial Values *****************/
#define TCCR0_INITVAL concByte(CS00_VAL,CS01_VAL,CS02_VAL,WGM01_VAL,COM00_VAL,COM01_VAL,WGM00_VAL,0)

/*************** ISR *********************/

#define ISR(vector_num) 															\
	void vector_num(void)	__attribute__((signal,used,externally_visible));		\
	void vector_num(void)

void (* voidPtrToOVISR) (void) = NULL;
void (* voidPtrToCMISR) (void) = NULL;



/*
 * MainApplication.c
 *
 *  Created on: Nov 23, 2018
 *      Author: zawawy
 */

/*
 * main.c
 *
 *  Created on: Nov 24, 2018
 *      Author: ENG A
 */
#include "libs/STD_TYPES.h"
#include "utils/BIT_LIB.h"
#include "avr/delay.h"
#define F_CPU 12000000
#include "Timer1_driver/Timer1_int.h"
#include "Extint_driver/Extint_int.h"
#include "DIO_driver/DIO_int.h"

u16 VALFRONT=0;
u16 VALRIGHT=0;
u16 VALLEFT=0;
void TRIG1(void){

	DIO_u8SetPinValue(DIO_enuPin8,DIO_u8HIGHVAL);
	_delay_us(10);
	DIO_u8SetPinValue(DIO_enuPin8,DIO_u8LOWVAL);
}
void TRIG2(void){

	DIO_u8SetPinValue(DIO_enuPin9,DIO_u8HIGHVAL);
	_delay_us(10);
	DIO_u8SetPinValue(DIO_enuPin9,DIO_u8LOWVAL);
}
void TRIG3(void){

	DIO_u8SetPinValue(DIO_enuPin12,DIO_u8HIGHVAL);
	_delay_us(10);
	DIO_u8SetPinValue(DIO_enuPin12,DIO_u8LOWVAL);

}


void UltraSonic_Front_INT0(void)
{
	static u8 count=0;
	if(count==0){
//TIMER1_SET_TCNT1(0);
count++;
	}
	else{
		//u16*TCNT1_END;
 //TIMER1_GET_TCNT1(TCNT1_END);
//VALFRONT=*TCNT1_END;
count=0;
	   }

}
void UltraSonic_Right_INT1(void)
{
	static u8 count=0;
	static u16 TCNT1BEGIN;
	if(count==0){
		//u16 *ptrTCNT1_BEGIN;

//TIMER1_GET_TCNT1(ptrTCNT1_BEGIN);
//TCNT1BEGIN=*ptrTCNT1_BEGIN;
		count++;
	}
	else{
		//u16*TCNT1_END;
 //TIMER1_GET_TCNT1(TCNT1_END);
//VALRIGHT=(*TCNT1_END)-(TCNT1BEGIN);


count=0;

}}
void UltraSonic_Left_INT2(void)
{
	static u8 count=0;
	static u16 TCNT1BEGIN;
	if(count==0){
			//u16 *ptrTCNT1_BEGIN;
		//TIMER1_GET_TCNT1(ptrTCNT1_BEGIN);
		//TCNT1BEGIN=*ptrTCNT1_BEGIN;
				count++;
				Extint_u8SetIntState(Extint_enuInt2,Extint_enuFallingEdge);


	}
		else{
			//u16*TCNT1_END;
	 //TIMER1_GET_TCNT1(TCNT1_END);
	//VALLEFT=(*TCNT1_END)-(TCNT1BEGIN);
count=0;
Extint_u8SetIntState(Extint_enuInt2,Extint_enuRisingEdge);


		}

}

void main(void){
	DIO_voidInit();
	DIO_u8SetPinDir(DIO_enuPin8,DIO_u8PIN_OUTPUTDIR);
	DIO_u8SetPinDir(DIO_enuPin9,DIO_u8PIN_OUTPUTDIR);
	DIO_u8SetPinDir(DIO_enuPin12,DIO_u8PIN_OUTPUTDIR);
	Timer1_voidInit();
	Extint_voidInit();
	Extint_u8SetIntHanlder(Extint_enuInt0,UltraSonic_Front_INT0);
	Extint_u8EnableInt(Extint_enuInt0);
	Extint_u8SetIntHanlder(Extint_enuInt1,UltraSonic_Right_INT1);
	Extint_u8EnableInt(Extint_enuInt1);
	Extint_u8SetIntHanlder(Extint_enuInt2,UltraSonic_Left_INT2);
	Extint_u8EnableInt(Extint_enuInt2);

	while(1){
		TRIG1();
		TRIG2();
		TRIG3();
	}
}





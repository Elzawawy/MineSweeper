/*
 * MainApplication.c
 *
 *  Created on: Nov 23, 2018
 *      Author: zawawy
 */

// /*
//  * main.c
//  *
//  *  Created on: Nov 24, 2018
//  *      Author: ENG A
//  */
// #include "libs/STD_TYPES.h"
// #include "utils/BIT_LIB.h"
// #include "avr/delay.h"
// #define F_CPU 12000000
// #include "Timer1_driver/Timer1_int.h"
// #include "Extint_driver/Extint_int.h"
// #include "DIO_driver/DIO_int.h"

// u16 VALFRONT=0;
// u16 VALRIGHT=0;
// u16 VALLEFT=0;
// void TRIG1(void){

// 	DIO_u8SetPinValue(DIO_enuPin8,DIO_u8HIGHVAL);
// 	_delay_us(10);
// 	DIO_u8SetPinValue(DIO_enuPin8,DIO_u8LOWVAL);
// }
// void TRIG2(void){

// 	DIO_u8SetPinValue(DIO_enuPin9,DIO_u8HIGHVAL);
// 	_delay_us(10);
// 	DIO_u8SetPinValue(DIO_enuPin9,DIO_u8LOWVAL);
// }
// void TRIG3(void){

// 	DIO_u8SetPinValue(DIO_enuPin12,DIO_u8HIGHVAL);
// 	_delay_us(10);
// 	DIO_u8SetPinValue(DIO_enuPin12,DIO_u8LOWVAL);

// }


// void UltraSonic_Front_INT0(void)
// {
// 	static u8 count=0;
// 	if(count==0){
// //TIMER1_SET_TCNT1(0);
// count++;
// 	}
// 	else{
// 		//u16*TCNT1_END;
//  //TIMER1_GET_TCNT1(TCNT1_END);
// //VALFRONT=*TCNT1_END;
// count=0;
// 	   }

// }
// void UltraSonic_Right_INT1(void)
// {
// 	static u8 count=0;
// 	static u16 TCNT1BEGIN;
// 	if(count==0){
// 		//u16 *ptrTCNT1_BEGIN;

// //TIMER1_GET_TCNT1(ptrTCNT1_BEGIN);
// //TCNT1BEGIN=*ptrTCNT1_BEGIN;
// 		count++;
// 	}
// 	else{
// 		//u16*TCNT1_END;
//  //TIMER1_GET_TCNT1(TCNT1_END);
// //VALRIGHT=(*TCNT1_END)-(TCNT1BEGIN);


// count=0;

// }}
// void UltraSonic_Left_INT2(void)
// {
// 	static u8 count=0;
// 	static u16 TCNT1BEGIN;
// 	if(count==0){
// 			//u16 *ptrTCNT1_BEGIN;
// 		//TIMER1_GET_TCNT1(ptrTCNT1_BEGIN);
// 		//TCNT1BEGIN=*ptrTCNT1_BEGIN;
// 				count++;
// 				Extint_u8SetIntState(Extint_enuInt2,Extint_enuFallingEdge);


// 	}
// 		else{
// 			//u16*TCNT1_END;
// 	 //TIMER1_GET_TCNT1(TCNT1_END);
// 	//VALLEFT=(*TCNT1_END)-(TCNT1BEGIN);
// count=0;
// Extint_u8SetIntState(Extint_enuInt2,Extint_enuRisingEdge);


// 		}

// }

// void main(void){
// 	DIO_voidInit();
// 	DIO_u8SetPinDir(DIO_enuPin8,DIO_u8PIN_OUTPUTDIR);
// 	DIO_u8SetPinDir(DIO_enuPin9,DIO_u8PIN_OUTPUTDIR);
// 	DIO_u8SetPinDir(DIO_enuPin12,DIO_u8PIN_OUTPUTDIR);
// 	Timer1_voidInit();
// 	Extint_voidInit();
// 	Extint_u8SetIntHanlder(Extint_enuInt0,UltraSonic_Front_INT0);
// 	Extint_u8EnableInt(Extint_enuInt0);
// 	Extint_u8SetIntHanlder(Extint_enuInt1,UltraSonic_Right_INT1);
// 	Extint_u8EnableInt(Extint_enuInt1);
// 	Extint_u8SetIntHanlder(Extint_enuInt2,UltraSonic_Left_INT2);
// 	Extint_u8EnableInt(Extint_enuInt2);

// 	while(1){
// 		TRIG1();
// 		TRIG2();
// 		TRIG3();
// 	}
// }
#include "libs/STD_TYPES.h"
#include "libs/Registers.h"
#include "utils/BIT_LIB.h"
#include "DIO_driver/DIO_int.h"
#include "UltraSonic_driver/UltraSonic_int.h"
#include "Timer1_driver/Timer1_int.h"
#include "Extint_driver/Extint_int.h"
#include "LCD_driver/LCD_int.h"
#include "Timer0_driver/Timer0_int.h"
#include "RTOS/RTOS.h"
#include "avr/delay.h"

u8 device1Val,device2Val,device3Val;
void Task1(void);
void Task2(void);
void Task3(void);
void Task4(void);

void main(void)
{
//	DIO_voidInit();
//	Timer0_voidInit();
//	Timer1_voidInit();
//	Extint_voidInit();
//	UltraSonic_voidInit();
//	DIO_u8SetPinDir(DIO_enuPin16, DIO_u8PIN_OUTPUTDIR);
//	DIO_u8SetPinDir(DIO_enuPin17, DIO_u8PIN_OUTPUTDIR);
//	DIO_u8SetPinDir(DIO_enuPin18, DIO_u8PIN_OUTPUTDIR);
//	createTask(0, 1004, 0, Task1);
//	createTask(0, 1004, 1, Task2);
//	createTask(0, 1004, 2, Task3);
//	createTask(1, 2, 3, Task4);
//	startSchedular();
//	while(1)
//	{
//
//	}
	DIO_voidInit();
	Timer0_voidInit();
	Timer1_voidInit();
	Extint_voidInit();
	LCD_voidInit();
	UltraSonic_voidInit();
	while(1)
	{
//		Task1();
//		Task2();
//		Task3();
//		Task4();
//		_delay_ms(120);
	}


}

void Task1(void)
{
	UltraSonic_u8Trigger(UltraSonic_enuDevice1);
}

void Task2(void)
{
	UltraSonic_u8Trigger(UltraSonic_enuDevice2);
}

void Task3(void)
{
	UltraSonic_u8Trigger(UltraSonic_enuDevice3);
}

void Task4(void)
{
//	if( UltraSonic_u8GetVal(UltraSonic_enuDevice1,&device1Val, Centimeter) < 8 )
//		DIO_u8SetPinValue(DIO_enuPin16,DIO_u8HIGHVAL);
//	else
//		DIO_u8SetPinValue(DIO_enuPin16,DIO_u8LOWVAL);
//
//	if( UltraSonic_u8GetVal(UltraSonic_enuDevice2,&device2Val, Centimeter) < 8 )
//		DIO_u8SetPinValue(DIO_enuPin17,DIO_u8HIGHVAL);
//	else
//		DIO_u8SetPinValue(DIO_enuPin17,DIO_u8LOWVAL);
//
//	if( UltraSonic_u8GetVal(UltraSonic_enuDevice3,&device3Val, Centimeter) < 8 )
//		DIO_u8SetPinValue(DIO_enuPin18,DIO_u8HIGHVAL);
//	else
//		DIO_u8SetPinValue(DIO_enuPin18,DIO_u8LOWVAL);

	UltraSonic_u8GetVal(UltraSonic_enuDevice1,&device1Val, Centimeter);
	LCD_u8WriteNumeric(device1Val);
	LCD_u8WriteData(' ');
	UltraSonic_u8GetVal(UltraSonic_enuDevice2,&device2Val, Centimeter);
	LCD_u8WriteNumeric(device2Val);
	LCD_u8WriteData(' ');
	UltraSonic_u8GetVal(UltraSonic_enuDevice3,&device3Val, Centimeter);
	LCD_u8WriteNumeric(device3Val);


}


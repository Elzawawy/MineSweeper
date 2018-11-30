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
#include "MotorDriver_driver/MotorDriver_int.h"
#include "DecisionMaker.h"
#include "RTOS/RTOS.h"
#include "avr/delay.h"
#define  F_CPU 12000000

u16 device1Val=0,device2Val=0,device3Val=0;
u8 metalVal;
void Task1(void);
void Task2(void);
void Task3(void);
void Task4(void);
void Task5(void);

void main(void)
{
	DIO_voidInit();
	Timer0_voidInit();
	Timer1_voidInit();
	Extint_voidInit();
	UltraSonic_voidInit();
	MotorDriver_voidInit();
	createTask(0, 600, 0, Task1);
	createTask(4, 600, 1, Task2);
	createTask(8, 600, 2, Task3);
	createTask(11, 3, 3, Task4);
	createTask(12,2,4,Task5);
	startSchedular();
	while(1)
	{

	}
//	DIO_voidInit();
//	Timer0_voidInit();
//	Timer1_voidInit();
//	Extint_voidInit();
//	LCD_voidInit();
//	UltraSonic_voidInit();
//	DIO_u8SetPinDir(DIO_enuPin11, DIO_u8PIN_OUTPUTDIR);
//	DIO_u8SetPinDir(DIO_enuPin12, DIO_u8PIN_OUTPUTDIR);
//	DIO_u8SetPinDir(DIO_enuPin13, DIO_u8PIN_OUTPUTDIR);
//
//	while(1)
//	{
//		Task1();
//		Task2();
//		Task3();
//		Task4();
//		_delay_ms(120);
//	}


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
//  if( UltraSonic_u8GetVal(UltraSonic_enuDevice1,&device1Val, Centimeter) > 8 )
//		DIO_u8SetPinValue(DIO_enuPin11,DIO_u8HIGHVAL);
//	else
//		DIO_u8SetPinValue(DIO_enuPin11,DIO_u8LOWVAL);
//
//	if( UltraSonic_u8GetVal(UltraSonic_enuDevice2,&device2Val, Centimeter) > 8 )
//		DIO_u8SetPinValue(DIO_enuPin12,DIO_u8HIGHVAL);
//	else
//		DIO_u8SetPinValue(DIO_enuPin12,DIO_u8LOWVAL);
//
//	if( UltraSonic_u8GetVal(UltraSonic_enuDevice3,&device3Val, Centimeter) > 8 )
//		DIO_u8SetPinValue(DIO_enuPin13,DIO_u8HIGHVAL);
//	else
//		DIO_u8SetPinValue(DIO_enuPin13,DIO_u8LOWVAL);

//	 UltraSonic_u8GetVal(UltraSonic_enuDevice1,&device1Val, Centimeter);
//	 if(device1Val < 10)
//		 DIO_u8SetPinValue(DIO_enuPin3,DIO_u8HIGHVAL);
//	 else
//		 DIO_u8SetPinValue(DIO_enuPin3,DIO_u8LOWVAL);
//	 UltraSonic_u8GetVal(UltraSonic_enuDevice2,&device2Val, Centimeter);
//	 if(device2Val < 10)
//		 DIO_u8SetPinValue(DIO_enuPin4,DIO_u8HIGHVAL);
//	 else
//		 DIO_u8SetPinValue(DIO_enuPin4,DIO_u8LOWVAL);
//
//	 UltraSonic_u8GetVal(UltraSonic_enuDevice3,&device3Val, Centimeter);
//	 if(device3Val < 10)
//		 DIO_u8SetPinValue(DIO_enuPin5,DIO_u8HIGHVAL);
//	 else
//		 DIO_u8SetPinValue(DIO_enuPin5,DIO_u8LOWVAL);

	UltraSonic_u8GetVal(UltraSonic_enuDevice1,&device1Val, Centimeter);
	UltraSonic_u8GetVal(UltraSonic_enuDevice2,&device2Val, Centimeter);
	UltraSonic_u8GetVal(UltraSonic_enuDevice3,&device3Val, Centimeter);
	MakeUltraSonicDecision(device1Val, device3Val, device2Val);

}
void Task5(void)
{
	DIO_u8GetPinValue(DIO_enuPin16,&metalVal);
	MakeMotorDecision(metalVal);
}


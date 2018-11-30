/*
 * UltraSonic_prog.c
 *
 *  Created on: Nov 26, 2018
 *      Author: ENG A
 */
#include "../libs/STD_TYPES.h"
#include "../Extint_driver/Extint_int.h"
#include "../Timer1_driver/Timer1_int.h"
#include "UltraSonic_int.h"
#include "UltraSonic_config.h"
#include "UltraSonic_priv.h"
#include "avr/delay.h"
#define  F_CPU 12000000
#define SENSORDELAY 10

void UltraSonic1(void);
void UltraSonic2(void);
void UltraSonic3(void);

tstrdevicecreator US[3]={{UltraSonic1,Extint_enuInt0,INITIALVAL,UltraSonic_Device1TriggerPin},{UltraSonic2,Extint_enuInt1,INITIALVAL,UltraSonic_Device2TriggerPin},{UltraSonic3,Extint_enuInt2,INITIALVAL,UltraSonic_Device3TriggerPin}};

void UltraSonic1(void)
{
	static u8 count=0;
	u16 TCNT1_END=0;
	if(count==0){
		Timer1_u8setTCNT1(0);
		count++;
	}
	else{
		Timer1_u8getTCNT1(&TCNT1_END);
		US[UltraSonic_enuDevice1].Val= TCNT1_END;
		count=0;
	   }

}
void UltraSonic2(void)
{
	static u8 count=0;
	static u16 TCNT1BEGIN;
	u16 TCNT1_END=0;
	if(count==0){
		Timer1_u8getTCNT1(&TCNT1BEGIN);
		count++;
	}
	else{

		Timer1_u8getTCNT1(&TCNT1_END);
		US[UltraSonic_enuDevice2].Val=(TCNT1_END)-(TCNT1BEGIN);
		count=0;

}}
void UltraSonic3(void)
{
	static u8 count=0;
	static u16 TCNT1BEGIN;
	u16 TCNT1_END=0;
	if(count==0){
			Timer1_u8getTCNT1(&TCNT1BEGIN);
			count++;
			Extint_u8SetIntState(Extint_enuInt2,Extint_enuFallingEdge);


	}
		else{

			Timer1_u8getTCNT1(&TCNT1_END);
			US[UltraSonic_enuDevice3].Val=(TCNT1_END)-(TCNT1BEGIN);
			count=0;
			Extint_u8SetIntState(Extint_enuInt2,Extint_enuRisingEdge);


		}

}




void UltraSonic_voidInit(void){

//	if(UltarSonic_Devices<MINDEVICES || UltarSonic_Devices>MAXDEVICES){
//
//	}
//	else {
//		for(u8 i=0;i<UltarSonic_Devices;i++){
//			DIO_u8SetPinDir(US[i].Trigger,DIO_u8PIN_OUTPUTDIR);
//			Extint_u8SetIntHanlder(US[i].Int_num,US[i].fptr);
//			Extint_u8EnableInt(US[i].Int_num);
//		}
	DIO_u8SetPinDir(UltraSonic_Device1TriggerPin,DIO_u8PIN_OUTPUTDIR);
	Extint_u8SetIntHanlder(Extint_enuInt0,UltraSonic1);
	Extint_u8EnableInt(Extint_enuInt0);
	DIO_u8SetPinDir(UltraSonic_Device2TriggerPin,DIO_u8PIN_OUTPUTDIR);
	Extint_u8SetIntHanlder(Extint_enuInt1,UltraSonic2);
	Extint_u8EnableInt(Extint_enuInt1);
	DIO_u8SetPinDir(UltraSonic_Device3TriggerPin,DIO_u8PIN_OUTPUTDIR);
	Extint_u8SetIntHanlder(Extint_enuInt2,UltraSonic3);
	Extint_u8EnableInt(Extint_enuInt2);





}

u8 UltraSonic_u8Trigger(u8 Copy_u8UltraSonicNum){
//validation
	UltraSonic_enuState Local_UltraSonicState=UltraSonic_enuNormalState;
	if(Copy_u8UltraSonicNum<UltraSonic_enuDevice1||Copy_u8UltraSonicNum>UltraSonic_enuDevice3){
		Local_UltraSonicState=UltraSonic_enuWrongDeviceNum;
	}
	else{
	DIO_u8SetPinValue(US[Copy_u8UltraSonicNum].Trigger,DIO_u8HIGHVAL);
	_delay_us(SENSORDELAY);
	DIO_u8SetPinValue(US[Copy_u8UltraSonicNum].Trigger,DIO_u8LOWVAL);
	}
	return Local_UltraSonicState;
}

u8 UltraSonic_u8GetVal(u8 Copy_u8UltraSonicNum,u16 *Copy_u16UltraSonicVal,u8 Copy_u8Unit){
//validation
	UltraSonic_enuState Local_UltraSonicState=UltraSonic_enuNormalState;
	if(Copy_u8UltraSonicNum<UltraSonic_enuDevice1||Copy_u8UltraSonicNum>UltraSonic_enuDevice3){
		Local_UltraSonicState=UltraSonic_enuWrongDeviceNum;
	}
	else{
		switch (Copy_u8Unit){
		case Centimeter:
			*Copy_u16UltraSonicVal= (US[Copy_u8UltraSonicNum].Val*Timer1Prescaler)/(OscillatorFreqInMHz*DivisionFactorForCm);
			break;
		case Inch:
			*Copy_u16UltraSonicVal= (US[Copy_u8UltraSonicNum].Val*Timer1Prescaler)/(OscillatorFreqInMHz*DivisionFactorForInch);
			break;
		default: Local_UltraSonicState=UltraSonic_enuWrongUnit;
		}
	}
	return Local_UltraSonicState;
}

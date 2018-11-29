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

void UltraSonic1(void);
void UltraSonic2(void);
void UltraSonic3(void);


tstrdevicecreator US[3]={{UltraSonic1,Extint_enuInt0,INITIALVAL,UltraSonic_Device1TriggerPin},{UltraSonic2,Extint_enuInt1,INITIALVAL,UltraSonic_Device2TriggerPin},{UltraSonic2,Extint_enuInt2,INITIALVAL,UltraSonic_Device3TriggerPin}};
void UltraSonic_voidInit(void){

	if(UltarSonic_Devices<MINDEVICES||UltarSonic_Devices>MAXDEVICES){

	}
	else {
		DIO_u8SetPinDir(UltraSonic_Device1TriggerPin,DIO_u8PIN_OUTPUTDIR);
		DIO_u8SetPinDir(UltraSonic_Device2TriggerPin,DIO_u8PIN_OUTPUTDIR);
		DIO_u8SetPinDir(UltraSonic_Device3TriggerPin,DIO_u8PIN_OUTPUTDIR);
		tstrdevicecreator US[UltarSonic_Devices];
		for(u8 i=0;i<UltarSonic_Devices;i++){
			Extint_u8SetIntHanlder(US[i].Int_num,US[i].fptr);
			Extint_u8EnableInt(US[i].Int_num);
		}

	}
}
void UltraSonic1(void)
{
	static u8 count=0;
	if(count==0){
		Timer1_u8setTCNT1(0);
count++;
	}
	else{
		u16*TCNT1_END;
		Timer1_u8getTCNT1(TCNT1_END);
		US[UltraSonic_enuDevice1].Val=*TCNT1_END;
count=0;
	   }

}
void UltraSonic2(void)
{
	static u8 count=0;
	static u16 TCNT1BEGIN;
	if(count==0){
		u16 *ptrTCNT1_BEGIN;
		Timer1_u8getTCNT1(ptrTCNT1_BEGIN);
		TCNT1BEGIN=*ptrTCNT1_BEGIN;
		count++;
	}
	else{
		u16*TCNT1_END;
		Timer1_u8getTCNT1(TCNT1_END);
		US[UltraSonic_enuDevice2].Val=(*TCNT1_END)-(TCNT1BEGIN);
count=0;

}}
void UltraSonic3(void)
{
	static u8 count=0;
	static u16 TCNT1BEGIN;
	if(count==0){
			u16 *ptrTCNT1_BEGIN;
			Timer1_u8getTCNT1(ptrTCNT1_BEGIN);
			TCNT1BEGIN=*ptrTCNT1_BEGIN;
			count++;
			Extint_u8SetIntState(Extint_enuInt2,Extint_enuFallingEdge);


	}
		else{
			u16*TCNT1_END;
			Timer1_u8getTCNT1(TCNT1_END);
			US[UltraSonic_enuDevice3].Val=(*TCNT1_END)-(TCNT1BEGIN);
			count=0;
			Extint_u8SetIntState(Extint_enuInt2,Extint_enuRisingEdge);


		}

}

u8 UltraSonic_u8Trigger(u8 Copy_u8UltraSonicNum){
//validation
	UltraSonic_enuState Local_UltraSonicState=UltraSonic_enuNormalState;
	if(Copy_u8UltraSonicNum<UltraSonic_enuDevice1||Copy_u8UltraSonicNum>UltraSonic_enuDevice3){
		Local_UltraSonicState=UltraSonic_enuWrongDeviceNum;
	}
	else{
	DIO_u8SetPinValue(US[Copy_u8UltraSonicNum].Trigger,DIO_u8HIGHVAL);
	_delay_us(10);
	DIO_u8SetPinValue(US[Copy_u8UltraSonicNum].Trigger,DIO_u8LOWVAL);
	}
	return Local_UltraSonicState;
}

u8 UltraSonic_u8GetVal(u8 Copy_u8UltraSonicNum,u8 *Copy_u8UltraSonicVal,u8 Copy_u8Unit){
//validation
	UltraSonic_enuState Local_UltraSonicState=UltraSonic_enuNormalState;
	if(Copy_u8UltraSonicNum<UltraSonic_enuDevice1||Copy_u8UltraSonicNum>UltraSonic_enuDevice3){
		Local_UltraSonicState=UltraSonic_enuWrongDeviceNum;
	}
	else{
		switch (Copy_u8Unit){
		case Centimeter:
			*Copy_u8UltraSonicVal= (US[Copy_u8UltraSonicNum].Val*Timer1Prescaler)/(OscillatorFreqInMHz*DivisionFactorForCm);
			break;
		case Inch:
			*Copy_u8UltraSonicVal= (US[Copy_u8UltraSonicNum].Val*Timer1Prescaler)/(OscillatorFreqInMHz*DivisionFactorForInch);
			break;
		default: Local_UltraSonicState=UltraSonic_enuWrongUnit;
		}
	}
	return Local_UltraSonicState;
}

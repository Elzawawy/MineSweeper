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
#include <avr/io.h>
#include "avr/delay.h"
#define F_CPU 12000000
#include "TIMER1_DRIVER/TIMER1_INT.h"
#include "TIMER1_DRIVER/TIMER1_CONFIG.h"
#include "Extint_driver/Extint_int.h"

u16 VALFRONT=0;
u16 VALRIGHT=0;
u16 VALLEFT=0;
/*
void TRIG(void){
	//SET_BIT(DDRB,0);
	SET_BIT(PORTB,0);
	//SET_BIT(DDRB,1);
	SET_BIT(PORTB,1);
	//SET_BIT(DDRB,4);
	SET_BIT(PORTB,4);
	_delay_us(10);
	CLEAR_BIT(PORTB,0);
	CLEAR_BIT(PORTB,1);
	CLEAR_BIT(PORTB,4);
}
*/
void TRIG1(void){
	SET_BIT(DDRB,0);
	SET_BIT(PORTB,0);
	_delay_us(10);
	CLEAR_BIT(PORTB,0);
}
void TRIG2(void){
	SET_BIT(DDRB,1);
	SET_BIT(PORTB,1);
	_delay_us(10);
	CLEAR_BIT(PORTB,1);
}
void TRIG3(void){
	SET_BIT(DDRB,4);
	SET_BIT(PORTB,4);
	_delay_us(10);
	CLEAR_BIT(PORTB,4);

}


void UltraSonic_Front_INT0(void)
{
	static u8 count=0;
	if(count==0){
TIMER1_SET_TCNT1(0);
count++;
	}
	else{
		u16*TCNT1_END;
 TIMER1_GET_TCNT1(TCNT1_END);
VALFRONT=*TCNT1_END;
count=0;
	   }

}
void UltraSonic_Right_INT1(void)
{
	static u8 count=0;
	static u16 TCNT1BEGIN;
	if(count==0){
		u16 *ptrTCNT1_BEGIN;

TIMER1_GET_TCNT1(ptrTCNT1_BEGIN);
TCNT1BEGIN=*ptrTCNT1_BEGIN;
		count++;
	}
	else{
		u16*TCNT1_END;
 TIMER1_GET_TCNT1(TCNT1_END);
VALRIGHT=(*TCNT1_END)-(TCNT1BEGIN);


count=0;

}}
void UltraSonic_Left_INT2(void)
{
	static u8 count=0;
	static u16 TCNT1BEGIN;
	if(count==0){
			u16 *ptrTCNT1_BEGIN;
		TIMER1_GET_TCNT1(ptrTCNT1_BEGIN);
		TCNT1BEGIN=*ptrTCNT1_BEGIN;
				count++;
				Extint_u8SetIntState(Extint_enuInt2,Extint_enuFallingEdge);


	}
		else{
			u16*TCNT1_END;
	 TIMER1_GET_TCNT1(TCNT1_END);
	VALLEFT=(*TCNT1_END)-(TCNT1BEGIN);
count=0;
Extint_u8SetIntState(Extint_enuInt2,Extint_enuRisingEdge);


		}

}

void main(void){
	SET_BIT(DDRB,0);
	SET_BIT(DDRB,1);
	SET_BIT(DDRB,4);
	//DDRD=0X00;
//PORTD=0XFF;
//CLEAR_BIT(DDRB,2);
//SET_BIT(DDRB,2);
	/*
	 *#### WARNING ####
	 */
//u16 x;
	LCD_u8Init();
	TIMER1_INITALIZE();
	Extint_voidInit();
	Extint_u8SetIntHanlder(Extint_enuInt0,UltraSonic_Front_INT0);
	Extint_u8EnableInt(Extint_enuInt0);
	Extint_u8SetIntHanlder(Extint_enuInt1,UltraSonic_Right_INT1);
	Extint_u8EnableInt(Extint_enuInt1);
	Extint_u8SetIntHanlder(Extint_enuInt2,UltraSonic_Left_INT2);
	Extint_u8EnableInt(Extint_enuInt2);

	while(1){
//		if(!(VALFRONT==0||VALRIGHT==0||VALLEFT==0)){
//
//		}
//		TRIG();
		TRIG1();
		TRIG2();
		TRIG3();


		//TIMER1_GET_TCNT1(&x);

		LCD_Write_Var ((VALFRONT*8)/(12*58),3);
		LCD_Write_Data(' ');
		LCD_Write_Var ((VALRIGHT*8)/(12*58),3);
		LCD_Write_Data(' ');
		LCD_Write_Var ((VALLEFT*8)/(12*58),3);
		LCD_Write_Data(' ');

		_delay_ms(60);
		LCD_Write_Cmd(1);
	}
}



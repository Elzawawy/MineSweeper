/*
 * MOTORDRIVER_prog.c
 *
 *  Created on: Nov 26, 2018
 *      Author: Abdallah
 */
#include "../libs/STD_TYPES.h"
#include "../utils/BIT_LIB.h"
#include "MOTORDRIVER_INT.h"
#include "MOTORDRIVER_CONFIG.h"
#include "MOTORDRIVER_priv.h"



void MOTORDRIVER_INIT()
{
//setting direction of Motor1 DIO pins
DIO_u8SetPinDir(IN1_PINno,OUTPUT);
DIO_u8SetPinDir(IN2_PINno,OUTPUT);
DIO_u8SetPinDir(EN1_PINno,OUTPUT);


//setting direction of Motor2 DIO pins
DIO_u8SetPinDir(IN3_PINno,OUTPUT);
DIO_u8SetPinDir(IN4_PINno,OUTPUT);
DIO_u8SetPinDir(EN2_PINno,OUTPUT);

//enabling directions and enable of motor1 initial values
DIO_u8SetPinValue(IN1_PINno,IN1_INITVAL);
DIO_u8SetPinValue(IN2_PINno,IN2_INITVAL);
DIO_u8SetPinValue(EN1_PINno,EN1_INITVAL);
//enabling directions and enable of motor2 initial values
DIO_u8SetPinValue(IN3_PINno,IN3_INITVAL);
DIO_u8SetPinValue(IN4_PINno,IN4_INITVAL);
DIO_u8SetPinValue(EN2_PINno,EN2_INITVAL);


}
u8 MOTORDRIVER_MOVE_FORWARD()
{
	//MOVE MOTOR1 forward
	DIO_u8SetPinValue(IN1_PINno,HIGH);
	DIO_u8SetPinValue(IN2_PINno,LOW);
	DIO_u8SetPinValue(EN1_PINno,HIGH);

    //MOVE MOTOR2 forward
	DIO_u8SetPinValue(IN3_PINno,HIGH);
	DIO_u8SetPinValue(IN4_PINno,LOW);
	DIO_u8SetPinValue(EN2_PINno,HIGH);

}

u8 MOTORDRIVER_ROTATE_CLOCKWISE()
{
	    //MOVE MOTOR1 forward
		 DIO_u8SetPinValue(IN1_PINno,HIGH);
		 DIO_u8SetPinValue(IN2_PINno,LOW);
		 DIO_u8SetPinValue(EN1_PINno,HIGH);

		  //MOVE MOTOR2 backward
		  DIO_u8SetPinValue(IN3_PINno,LOW);
		  DIO_u8SetPinValue(IN4_PINno,HIGH);
		  DIO_u8SetPinValue(EN2_PINno,HIGH);
}
u8 MOTORDRIVER_ROTATE_ANTICLOCKWISE()
{
	//MOVE MOTOR1 backward
		DIO_u8SetPinValue(IN1_PINno,LOW);
		DIO_u8SetPinValue(IN2_PINno,HIGH);
		DIO_u8SetPinValue(EN1_PINno,HIGH);
	    //MOVE MOTOR2 forward
		DIO_u8SetPinValue(IN3_PINno,HIGH);
		DIO_u8SetPinValue(IN4_PINno,LOW);
		DIO_u8SetPinValue(EN2_PINno,HIGH);

}

u8 MOTORDRIVER_MOVE_BACKWARD()
{
	//MOVE MOTOR1 backward
	DIO_u8SetPinValue(IN1_PINno,LOW);
	DIO_u8SetPinValue(IN2_PINno,HIGH);
	DIO_u8SetPinValue(EN1_PINno,HIGH);

    //MOVE MOTOR2 backward
	DIO_u8SetPinValue(IN3_PINno,LOW);
	DIO_u8SetPinValue(IN4_PINno,HIGH);
	DIO_u8SetPinValue(EN2_PINno,HIGH);

}

u8 STOP()
{
	//STOP MOTOR1
	DIO_u8SetPinValue(IN1_PINno,LOW);
	DIO_u8SetPinValue(IN2_PINno,LOW);
	DIO_u8SetPinValue(EN1_PINno,LOW);

    //STOP MOTOR2
	DIO_u8SetPinValue(IN3_PINno,LOW);
	DIO_u8SetPinValue(IN4_PINno,LOW);
	DIO_u8SetPinValue(EN2_PINno,LOW);

}

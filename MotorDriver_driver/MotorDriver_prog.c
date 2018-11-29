/*
 * MOTORDRIVER_prog.c
 *
 *  Created on: Nov 26, 2018
 *      Author: Abdallah
 */
#include "../libs/STD_TYPES.h"
#include "../utils/BIT_LIB.h"
#include "MotorDriver_int.h"
#include "MotorDriver_config.h"
#include "MotorDriver_private.h"

void MotorDriver_voidInit(void)
{
	//setting direction of Motor1 DIO pins
	DIO_u8SetPinDir(IN1_INITPIN, OUTPUT);
	DIO_u8SetPinDir(IN2_INITPIN, OUTPUT);
	DIO_u8SetPinDir(EN1_INITPIN, OUTPUT);

	//setting direction of Motor2 DIO pins
	DIO_u8SetPinDir(IN3_INITPIN, OUTPUT);
	DIO_u8SetPinDir(IN4_INITPIN, OUTPUT);
	DIO_u8SetPinDir(EN2_INITPIN, OUTPUT);

	//enabling directions and enable of motor1 initial values
	DIO_u8SetPinValue(IN1_INITPIN, IN1_INITVAL);
	DIO_u8SetPinValue(IN2_INITPIN, IN2_INITVAL);
	DIO_u8SetPinValue(EN1_INITPIN, EN1_INITVAL);
	//enabling directions and enable of motor2 initial values
	DIO_u8SetPinValue(IN3_INITPIN, IN3_INITVAL);
	DIO_u8SetPinValue(IN4_INITPIN, IN4_INITVAL);
	DIO_u8SetPinValue(EN2_INITPIN, EN2_INITVAL);
}
u8 MotorDriver_u8MoveForward(void)
{
	//MOVE MOTOR1 forward
	DIO_u8SetPinValue(IN1_INITPIN, HIGH);
	DIO_u8SetPinValue(IN2_INITPIN, LOW);
	DIO_u8SetPinValue(EN1_INITPIN, HIGH);

	//MOVE MOTOR2 forward
	DIO_u8SetPinValue(IN3_INITPIN, HIGH);
	DIO_u8SetPinValue(IN4_INITPIN, LOW);
	DIO_u8SetPinValue(EN2_INITPIN, HIGH);
	return MotorDriver_enuNormalState;
}

u8 MotorDriver_u8RotateRight(void)
{
	//MOVE MOTOR1 forward
	DIO_u8SetPinValue(IN1_INITPIN, HIGH);
	DIO_u8SetPinValue(IN2_INITPIN, LOW);
	DIO_u8SetPinValue(EN1_INITPIN, HIGH);

	//MOVE MOTOR2 backward
	DIO_u8SetPinValue(IN3_INITPIN, LOW);
	DIO_u8SetPinValue(IN4_INITPIN, HIGH);
	DIO_u8SetPinValue(EN2_INITPIN, HIGH);
	return MotorDriver_enuNormalState;
}
u8 MotorDriver_u8RotateLeft(void)
{
	//MOVE MOTOR1 backward
	DIO_u8SetPinValue(IN1_INITPIN, LOW);
	DIO_u8SetPinValue(IN2_INITPIN, HIGH);
	DIO_u8SetPinValue(EN1_INITPIN, HIGH);
	//MOVE MOTOR2 forward
	DIO_u8SetPinValue(IN3_INITPIN, HIGH);
	DIO_u8SetPinValue(IN4_INITPIN, LOW);
	DIO_u8SetPinValue(EN2_INITPIN, HIGH);
	return MotorDriver_enuNormalState;
}

u8 MotorDriver_u8MoveBackward(void)
{
	//MOVE MOTOR1 backward
	DIO_u8SetPinValue(IN1_INITPIN, LOW);
	DIO_u8SetPinValue(IN2_INITPIN, HIGH);
	DIO_u8SetPinValue(EN1_INITPIN, HIGH);

	//MOVE MOTOR2 backward
	DIO_u8SetPinValue(IN3_INITPIN, LOW);
	DIO_u8SetPinValue(IN4_INITPIN, HIGH);
	DIO_u8SetPinValue(EN2_INITPIN, HIGH);
	return MotorDriver_enuNormalState;
}

u8 MotorDriver_u8StopMotor()
{
	//STOP MOTOR1
	DIO_u8SetPinValue(IN1_INITPIN, LOW);
	DIO_u8SetPinValue(IN2_INITPIN, LOW);
	DIO_u8SetPinValue(EN2_INITPIN, LOW);

	//STOP MOTOR2
	DIO_u8SetPinValue(IN3_INITPIN, LOW);
	DIO_u8SetPinValue(IN4_INITPIN, LOW);
	DIO_u8SetPinValue(EN2_INITPIN, LOW);
	return MotorDriver_enuNormalState;
}

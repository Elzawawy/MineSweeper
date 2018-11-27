/*
 * MOTORDRIVR_INT.h
 *
 *  Created on: Nov 26, 2018
 *      Author: Abdallah
 */

#ifndef MOTORDRIVER_INT_H_
#define MOTORDRIVER_INT_H_

typedef enum MotorDriver_enuState
{
	MotorDriver_enuNormalState = 0,
} MotorDriver_enuState;

void MotorDriver_voidInit(void);
u8 MotorDriver_u8MoveForward(void);
u8 MotorDriver_u8MoveBackward(void);
u8 MotorDriver_u8RotateRight(void);
u8 MotorDriver_u8RotateLeft(void);
u8 MotorDriver_u8StopMotor(void);

#endif /* MOTORDRIVER_INT_H_ */

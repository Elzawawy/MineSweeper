/*
 * MOTORDRIVER_CONFIG.h
 *
 *  Created on: Nov 26, 2018
 *      Author: Abdallah
 */
#ifndef MOTORDRIVER_CONFIG_H_
#define MOTORDRIVER_CONFIG_H_
//Include the DIO driver to support variuos pin configurations.
#include "../DIO_driver/DIO_int.h"

/* Motor Driver Pins
 * IN1 ---> Motor1 Direction.
 * IN2 ---> Motor1 Opposite Direction.
 * IN3 ---> Motor2 Direction.
 * IN4 ---> Motor2 Opposite Direction.
 * EN1 ---> DC Motor1 Enable.
 * EN2 ---> DC Motor2 Enable.
 *
***************** Range of Initial Pin Values ****************
    ( min : DIO_enuPin0 ------->  max : DIO_enuPin31 )
*/

/* IN1 Pin.
 * IN1_INITPIN is the DIO Pin connected with MotorDriver N1 Pin
 * IN1_INITVAL is the initial value for this direction. */
#define IN1_INITPIN  DIO_enuPin1
#define IN1_INITVAL  DISABLE

/* IN2 Pin.
 * IN2_INITPIN is the DIO Pin connected with MotorDriver N2 Pin 
 * IN2_INITVAL is the initial value for this direction. */
#define IN2_INITPIN  DIO_enuPin2
#define IN2_INITVAL  DISABLE

/* IN3 Pin.
 * IN3_INITPIN is the DIO Pin connected with MotorDriver N3 Pin 
 * IN3_INITVAL is the initial value for this direction. */
#define IN3_INITPIN  DIO_enuPin5
#define IN3_INITVAL  DISABLE

/* IN4 Pin.
 * IN4_INITPIN is the DIO Pin connected with MotorDriver N4 Pin 
 * IN4_INITVAL is the initial value for this direction. */
#define IN4_INITPIN  DIO_enuPin4
#define IN4_INITVAL  DISABLE

/* EN1 Pin.
 * EN1_INITPIN is the DIO Pin connected with MotorDriver EN1 Pin 
 * EN1_INITVAL is the initial value for this direction. */
#define EN1_INITPIN  DIO_enuPin0
#define EN1_INITVAL  ENABLE

/* EN2 Pin.
 * EN2_INITPIN is the DIO Pin connected with MotorDriver EN1 Pin 
 * EN2_INITVAL is the initial value for this direction. */
#define EN2_INITPIN  DIO_enuPin3
#define EN2_INITVAL  ENABLE

//Leave this in place when using a stepper motor. Connect to PWM output for DC motor speed control.

#endif

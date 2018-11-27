/*
 * MOTORDRIVER_CONFIG.h
 *
 *  Created on: Nov 26, 2018
 *      Author: Abdallah
 */
#include "../DIO_driver/DIO_int.h"

//IN1-->direction MOTOR1
//IN2-->opposite direction MOTOR1
//IN3-->direction MOTOR2
//IN4-->opposite direction MOTOR2
#define IN1_PINno  0
#define IN2_PINno  1
#define IN3_PINno  2
#define IN4_PINno  3

//DC motor 1 enable jumper. Leave this in place when using a stepper motor. Connect to PWM output for DC motor speed control.
#define EN1_PINno  4
//DC motor 2 enable jumper. Leave this in place when using a stepper motor. Connect to PWM output for DC motor speed control.
#define EN2_PINno  5

//set initial value directions of motor 1
#define IN1_INITVAL   ENABLE
#define IN2_INITVAL   DISABLE

//set initial value directions of motor 2
#define IN3_INITVAL   ENABLE
#define IN4_INITVAL   DISABLE

//set initial value of enable in motor 1
#define EN1_INITVAL   DISABLE

//set initial value of enable in motor 2
#define EN2_INITVAL   DISABLE

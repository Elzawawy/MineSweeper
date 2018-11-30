/*
 * UltraSonic_int.h
 *
 *  Created on: Nov 26, 2018
 *      Author: ENG A
 */

#ifndef ULTRASONIC_DRIVER_ULTRASONIC_INT_H_
#define ULTRASONIC_DRIVER_ULTRASONIC_INT_H_


typedef enum {
    UltraSonic_enuDevice1=0,
	UltraSonic_enuDevice2,
	UltraSonic_enuDevice3
}UltraSonic_enuDeviceNum;

typedef enum {
	Centimeter=0,
	Inch
}UltraSonic_enuUnit;

typedef enum {
    UltraSonic_enuNormalState=0,
    UltraSonic_enuWrongDeviceNum,
	UltraSonic_enuWrongUnit
}UltraSonic_enuState;

void UltraSonic_voidInit(void);
u8 UltraSonic_u8Trigger(u8 Copy_u8UltraSonicNum);
u8 UltraSonic_u8GetVal(u8 Copy_u8UltraSonicNum,u16 *Copy_u16UltraSonicVal,u8 Copy_u8Unit);


#endif /* ULTRASONIC_DRIVER_ULTRASONIC_INT_H_ */

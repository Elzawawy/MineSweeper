/*
 * UltraSonic_priv.h
 *
 *  Created on: Nov 27, 2018
 *      Author: ENG A
 */

#ifndef ULTRASONIC_DRIVER_ULTRASONIC_PRIV_H_
#define ULTRASONIC_DRIVER_ULTRASONIC_PRIV_H_

#define MAXDEVICES 3
#define MINDEVICES 1
#define INITIALVAL 0
#define DivisionFactorForCm 58
#define DivisionFactorForInch 148

typedef struct {
	void (*fptr)(void);
	Extint_enuIntNum Int_num;
	u8 Val;
	UltraSonic_DeviceNumTriggerPin Trigger;
}tstrdevicecreator;

#endif /* ULTRASONIC_DRIVER_ULTRASONIC_PRIV_H_ */

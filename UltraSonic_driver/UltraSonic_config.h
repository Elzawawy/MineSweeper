/*
 * UltraSonic_config.h
 *
 *  Created on: Nov 27, 2018
 *      Author: ENG A
 */

#ifndef ULTRASONIC_DRIVER_ULTRASONIC_CONFIG_H_
#define ULTRASONIC_DRIVER_ULTRASONIC_CONFIG_H_

//Include the DIO driver to support variuos pin configurations.
#include "../DIO_driver/DIO_int.h"

#define UltarSonic_Devices 3
#define OscillatorFreqInMHz 12
#define Timer1Prescaler 8
typedef enum {
	UltraSonic_Device1TriggerPin=DIO_enuPin29,
	UltraSonic_Device2TriggerPin=DIO_enuPin30,
	UltraSonic_Device3TriggerPin=DIO_enuPin31
}UltraSonic_DeviceNumTriggerPin;





#endif /* ULTRASONIC_DRIVER_ULTRASONIC_CONFIG_H_ */
                                               

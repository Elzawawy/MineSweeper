/*
 * RTOS.h
 *
 *  Created on: Oct 13, 2018
 *      Author: zawawy
 */
#ifndef RTOS_H_
#define RTOS_H_
#include "../libs/STD_TYPES.h"
#include "../Timer0_driver/Timer0_int.h"

u8 createTask(u8 Copy_u8FirstDelay, u8 Copy_u8Periodicty , u8 Copy_u8Priority, void (*TaskCode)(void));
u8 startSchedular(void);



#endif

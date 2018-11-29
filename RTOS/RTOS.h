/*
 * RTOS.h
 *
 *  Created on: Oct 13, 2018
 *      Author: zawawy
 */
#ifndef RTOS_H_
#define RTOS_H_



void createTask(u16 Copy_u8FirstDelay, u16 Copy_u8Periodicty , u16 Copy_u8Priority, void (*TaskCode)(void));
void startSchedular(void);



#endif

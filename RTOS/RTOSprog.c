/*
 * RTOSprog.c
 *
 *  Created on: Oct 13, 2018
 *      Author: zawawy
 */
#include "../libs/STD_TYPES.h"
#include "../Timer0_driver/Timer0_int.h"
#include "RTOS.h"
#include "RTOSconfig.h"
#include "RTOSprivate.h"
typedef struct
{
	u16 periodicty;
	void (*ptrToFunc)(void);
	u16 firstDelay;
}RTOSTask;

RTOSTask Global_TaskArray[NUM_TASKS];
void TimerOverFlowISR(void);

void createTask(u16 Copy_u8FirstDelay, u16 Copy_u8Periodicty , u16 Copy_u8Priority, void (*TaskCode)(void))
{
    RTOSTask Local_Task = {Copy_u8Periodicty, TaskCode , Copy_u8FirstDelay};
    Global_TaskArray[Copy_u8Priority] = Local_Task;

}

void startSchedular(void)
{
	Timer0_voidInit();
	Timer0_u8SetOverflowInt(TimerOverFlowISR);
	Timer0_u8SetTCNT(TCNT_value);
	Timer0_u8EnableOverflowInt();
}

void TimerOverFlowISR(void)
{
	Timer0_u8SetTCNT(TCNT_value);
	Schedular();
}


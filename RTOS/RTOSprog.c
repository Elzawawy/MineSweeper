/*
 * RTOSprog.c
 *
 *  Created on: Oct 13, 2018
 *      Author: zawawy
 */
#include "RTOS.h"
#include "RTOSconfig.h"
#include "RTOSprivate.h"
typedef struct
{
	u8 periodicty;
	void (*ptrToFunc)(void);
	u8 firstDelay;
}RTOSTask;

RTOSTask Global_TaskArray[NUM_TASKS];
void TimerOverFlowISR(void);

u8 createTask(u8 Copy_u8FirstDelay, u8 Copy_u8Periodicty , u8 Copy_u8Priority, void (*TaskCode)(void))
{
    RTOSTask Local_Task = {Copy_u8Periodicty, TaskCode , Copy_u8FirstDelay};
    Global_TaskArray[Copy_u8Priority] = Local_Task;

}

u8 startSchedular(void)
{
	Timer0_voidInit();
	Timer0_u8SetOverflowInt(TimerOverFlowISR);
	Timer0_u8EnableOverflowInt();
}

void TimerOverFlowISR(void)
{
	Timer0_u8SetTCNT(TCNT_value);
	Schedular();
}


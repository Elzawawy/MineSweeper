/*
 * RTOSprivate.h
 *
 *  Created on: Nov 23, 2018
 *      Author: zawawy
 */

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

#define Schedular()                                                                  \
	do                                                                               \
	{                                                                                \
		int i;                                                                       \
		for (i = 0; i < NUM_TASKS; i++)                                              \
		{                                                                            \
			if (Global_TaskArray[i].firstDelay == 0)                                 \
			{                                                                        \
				Global_TaskArray[i].ptrToFunc();                                     \
				Global_TaskArray[i].firstDelay = Global_TaskArray[i].periodicty - 1; \
			}                                                                        \
			else                                                                     \
				Global_TaskArray[i].firstDelay--;                                    \
		}                                                                            \
	} while (0)

#endif /* RTOS_PRIVATE_H_ */

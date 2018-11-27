/*
* DecisionMaker.h Service layer Module to make desicions.
*
* Created on: Nov 26, 2018
* Author: Amr Elzawawy
*/

#ifndef DECISION_MAKER_H
#define DECISION_MAKER_H
typedef enum enuDecisionMakerState
{
    enuNormalState=0,
    enuErrorState,
}enuDecisionMakerState;

//Minimum Distance "Guard Band" to avoid crash.
#define GUARD_BAND_DISTANCE 8
//Make Decision based on ultrasonic readings collected as input.
u8 MakeUltraSonicDecision(u8 Copy_u8FrontUltraSonicVal, u8 Copy_u8RightUltraSonicVal, u8 Copy_u8LeftUltraSonicVal);
//Make Decision to Motor based on ultrasonic readings and metal detector value collected.
u8 MakeMotorDecision(u8 Copy_u8MetalDetectorVal);

#endif
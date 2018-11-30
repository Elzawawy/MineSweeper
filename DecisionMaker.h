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
#define GUARD_BAND_DISTANCE 20
#define ERROR_BAND_DISTANCE 122
//Make Decision based on ultrasonic readings collected as input.
void MakeUltraSonicDecision(u16 Copy_u16FrontUltraSonicVal, u16 Copy_u16RightUltraSonicVal, u16 Copy_u16LeftUltraSonicVal);
//Make Decision to Motor based on ultrasonic readings and metal detector value collected.
void MakeMotorDecision(u8 Copy_u8MetalDetectorVal);

#endif

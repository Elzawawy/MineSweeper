/*
* DecisionMaker.c Service layer Module to make desicions.
*
* Created on: Nov 26, 2018
* Author: Amr Elzawawy
*/

#include "libs/STD_TYPES.h"
#include "utils/BIT_LIB.h"
#include "DecisionMaker.h"
#include "MotorDriver_driver/MotorDriver_int.h"

#define LOW 0
#define HIGH 1
//DecisionMode to select according to input Readings from sensors.
typedef enum UltraSonicDecisionMode{
    UltraSonicNormal=0,
    UltraSonicRotateLeft,
    UltraSonicRotateRight,
    UltraSonicCrash
}UltraSonicDecisionMode;
//Global Variable to be shared among file methods "File Scope"
UltraSonicDecisionMode Global_DecisionMode;

//Make Decision based on ultrasonic readings collected as input.
u8 MakeUltraSonicDecision(u8 Copy_u8FrontUltraSonicVal, u8 Copy_u8RightUltraSonicVal, u8 Copy_u8LeftUltraSonicVal)
{
    //If Front Value is less than the minimum allowed distance. Danger !
    if( Copy_u8FrontUltraSonicVal < GUARD_BAND_DISTANCE)
    {
        //Check My Right.
        if( Copy_u8RightUltraSonicVal >= GUARD_BAND_DISTANCE)
            Global_DecisionMode = UltraSonicRotateRight;
        //Check My Left.
        else if (Copy_u8LeftUltraSonicVal >= GUARD_BAND_DISTANCE)
            Global_DecisionMode = UltraSonicRotateLeft;
        //Oops ! Gotta go back !
        else 
            Global_DecisionMode = UltraSonicCrash;
    }
    //It's Okay ! 
    else 
        Global_DecisionMode = UltraSonicNormal;
}

//Make Decision to Motor based on ultrasonic readings and metal detector value collected.
u8 MakeMotorDecision(u8 Copy_u8MetalDetectorVal)
{
    
    if(Copy_u8MetalDetectorVal == HIGH)
    {
        MotorDriver_u8StopMotor();
    }
    else 
    {
        switch(Global_DecisionMode)
        {
            case UltraSonicNormal:
                MotorDriver_u8MoveForward();
                break;
            case UltraSonicRotateLeft:
            	MotorDriver_u8RotateLeft();
                break;
            case UltraSonicRotateRight :
            	MotorDriver_u8RotateRight();
                break;
            case UltraSonicCrash :
                MotorDriver_u8MoveBackward();
                break;
        }
    }
}

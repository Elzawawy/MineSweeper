/*
 * Timer0_int.h
 *
 *  Created on: 26 September, 2018
 *      Author: Amr Elzawawy
 */
#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

typedef enum  Timer0_enuState {
    Timer0_enuNormalState =0,
    Timer0_enuInvalidOperationMode,
    Timer0_enuInvalidCompareOutputMode,
    Timer0_enuInterruptError,
    Timer0_enuNullPointerException,
}Timer0_enuState;

#define TCNT 0
#define OCR  1
//Compare Output Modes
/*typedef enum Timer0_enuCOMode {
    Timer0_enuNormalMode1,
    Timer0_enuNormalMode2,
    Timer0_enuNormalMode3,
    Timer0_enuNormalMode4,
}Timer0_enuCOMode;*/
void Timer0_voidInit(void);
//u8 Timer0_u8SetCompareOutputMode();
u8 Timer0_u8SetTCNT(u8 Copy_u8value);
u8 Timer0_u8SetOCR(u8 Copy_u8value);
u8 Timer0_u8EnableOverflowInt(void);
u8 Timer0_u8EnableCompareMatchInt(void);
u8 Timer0_u8SetOverflowInt(void (* voidPtrToFunc)(void));
u8 Timer0_u8SetCompareMatchInt(void (* voidPtrToFunc) (void));
#endif

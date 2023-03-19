/*
 * Timer_types.h
 *
 *  Created on: Feb 25, 2023
 *      Author: NTI
 */

#ifndef TIMER0_TIMER_TYPES_H_
#define TIMER0_TIMER_TYPES_H_


typedef enum{
	prescaler_0,
	prescaler_1,
	prescaler_8,
	prescaler_64,
	prescaler_256,
	prescaler_1024,
	External_clock_falling,
	External_clock_rising
}Prescaler_t;



typedef enum{
	normal,
	toggel,
	set,
	clear
}OC0_options;

typedef enum{
	Normal_mode,
	PWM_phaseCorrect,
	CTC_mode,
	fast_PWM

}Wave_GEN_Modes;

typedef enum{
	OV_INT_ID,
	CMP_INT_ID

}Timer_INT_ID;


typedef enum{
	NON_inverting_mode,
	inverting_mode

}Timer0_PWM_mode;

#endif /* TIMER0_TIMER_TYPES_H_ */

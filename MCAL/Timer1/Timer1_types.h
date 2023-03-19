/*
 * Timer1_types.h
 *
 *  Created on: Mar 1, 2023
 *      Author: nasser
 */

#ifndef TIMER1_TIMER1_TYPES_H_
#define TIMER1_TIMER1_TYPES_H_

typedef enum{
	prescaler_timer1_0,
	prescaler_timer1_1,
	prescaler_timer1_8,
	prescaler_timer1_64,
	prescaler_timer_256,
	prescaler_timer_1024,
	External_clock_timer1_falling,
	External_clock_timer1_rising
}Prescaler_timer1;

typedef enum{
	normal_t1,
	toggel_t1,
	set_t1,
	clear_t1
}OCR1_options;

typedef enum{
	Normal_mode_t1,
	PWM_phaseCorrect_t1,
	CTC_mode_t1,
	fast_PWM_t1,
	ICU_t1

}Timer1_Wave_GEN_Modes;

typedef enum{
	OV_INT_ID_t1,
	CMP_INT_ID_t1

}Timer1_INT_ID;


typedef enum{
	NON_inverting_mode_timer1,
	inverting_mode_timer1

}Timer1_PWM_mode;


#endif /* TIMER1_TIMER1_TYPES_H_ */

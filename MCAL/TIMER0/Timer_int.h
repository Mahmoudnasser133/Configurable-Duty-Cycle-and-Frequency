/*
 * Timer_int.h
 *
 *  Created on: Feb 25, 2023
 *      Author: NTI
 */

#ifndef TIMER0_TIMER_INT_H_
#define TIMER0_TIMER_INT_H_

#include "STD_TYPES.h"

#include "Timer_cfg.h"


void M_Timer0_void_Init(Timer0_config *configptr_timer0);

void M_Timer0_void_start(u16 prescaler);

void M_Timer0_void_stop(void);

u32 M_Timer0_u32_GetCounts(void);

void M_Timer0_void_setDelayTimeMilliSec(Timer0_config *configptr_timer0,u32 delay);

void M_Timer0_void_Enable_INT(u8 Timer_INT_ID);

void M_Timer0_void_Disable_INT(u8 Timer_INT_ID);

void M_Timer0_void_setCallBack(void (*copy_callBack)(void));

void M_v_Timer0_setFastPWM( u8 duty_cycle,Timer0_PWM_mode timer0_pwm_mode);

void M_v_Timer0_PhaseCorrect( u8 duty_cycle,Timer0_PWM_mode timer0_pwm_mode);

#endif /* TIMER0_TIMER_INT_H_ */

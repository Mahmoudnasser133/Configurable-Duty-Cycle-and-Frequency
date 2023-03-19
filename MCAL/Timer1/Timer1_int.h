/*
 * Timer1_int.h
 *
 *  Created on: Mar 1, 2023
 *      Author: nasser
 */

#ifndef TIMER1_TIMER1_INT_H_
#define TIMER1_TIMER1_INT_H_

#include "STD_TYPES.h"

#include "Timer1_cfg.h"

void M_Timer1_void_Init(u8 timer1_mode);

void M_Timer1_void_start(u8 prescaler);

void M_Timer1_void_ICU(u8 prescaler, u16 *duty_cycle,u16 *frequency );

u16 M_Timer1_u16_ICU_TON(u8 prescaler_val);



void M_Timer1_void_stop(void);

#endif /* TIMER1_TIMER1_INT_H_ */

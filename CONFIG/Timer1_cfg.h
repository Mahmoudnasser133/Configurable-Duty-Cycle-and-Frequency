/*
 * Timer1_cfg.h
 *
 *  Created on: Mar 1, 2023
 *      Author: nasser
 */

#ifndef TIMER1_CFG_H_
#define TIMER1_CFG_H_

#include "STD_TYPES.h"
#include "Timer1_types.h"

#define FCPU		16000000UL

typedef struct{
Prescaler_timer1			timer1_prescaler_value;
Timer1_Wave_GEN_Modes		timer1_wave_mode;
OCR1_options				OCR1;

}Timer1_config;

#endif /* TIMER1_CFG_H_ */

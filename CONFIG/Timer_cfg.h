/*
 * Timer_cfg.h
 *
 *  Created on: Feb 25, 2023
 *      Author: NTI
 */

#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

#include "STD_TYPES.h"
#include "Timer_types.h"

#define FCU		16

typedef struct{
Prescaler_t			prescaler_value;
Wave_GEN_Modes		wave_mode;
OC0_options			OC0;

}Timer0_config;

#endif /* TIMER_CFG_H_ */

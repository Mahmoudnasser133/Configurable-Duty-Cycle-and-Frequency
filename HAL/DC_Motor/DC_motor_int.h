/*
 * DC_motor_int.h
 *
 *  Created on: Mar 5, 2023
 *      Author: nasser
 */

#ifndef DC_MOTOR_DC_MOTOR_INT_H_
#define DC_MOTOR_DC_MOTOR_INT_H_

#include "DC_Motor_cfg.h"

#define CLockWith			1
#define Anti_ClockWith		0

#define STOP				2

void H_DC_Motor_void_Enabel(u8 Direction);

void H_DC_Motor_void_STOP(void);

#endif /* DC_MOTOR_DC_MOTOR_INT_H_ */

/*
 * DC_motor_prog.c
 *
 *  Created on: Mar 5, 2023
 *      Author: nasser
 */

#include "STD_TYPES.h"
#include "Dio_int.h"
#include "DC_motor_int.h"

void H_DC_Motor_void_Enabel(u8 Direction)
{
	M_Dio_void_setPinValue(MOTOR_EN_BIT, DIO_HIGH);


	switch(Direction)
	{
	 case CLockWith:
		 	 M_Dio_void_setPinValue(MOTOR_DIR_BIT, DIO_HIGH);
		 	// M_Dio_void_setPinValue(MOTOR_IN2_BIT, DIO_LOW);
		 	 break;


	case Anti_ClockWith:
				M_Dio_void_setPinValue(MOTOR_DIR_BIT, DIO_LOW);
				//M_Dio_void_setPinValue(MOTOR_IN2_BIT, DIO_HIGH);
				break;
	}

}
void H_DC_Motor_void_STOP(void)
{
	M_Dio_void_setPinValue(MOTOR_EN_BIT, DIO_LOW);
	M_Dio_void_setPinValue(MOTOR_DIR_BIT, DIO_LOW);
}


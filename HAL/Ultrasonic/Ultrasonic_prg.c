/*
 * Ultrasonic_prg.c
 *
 *  Created on: Mar 2, 2023
 *      Author: nasser
 */
#include <util/delay.h>
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu_HW.h"
#include "Dio_int.h"
#include "Timer1_int.h"
#include "Ultrasonic_cfg.h"
#include "Ultrasonic_int.h"

void H_Ultrasonic_void_trigger(void)
{
	M_Dio_void_setPinValue(Ultrasonic_trigger_bin, DIO_HIGH);
	_delay_ms(50);
	M_Dio_void_setPinValue(Ultrasonic_trigger_bin, DIO_LOW);
}
/*
u16 H_Ultrasonic_u16_distance(void)
{
	u16 distance=0;

	distance = M_Timer1_u16_ICU_TON(prescaler_val);

	return distance;
}
*/
//	distance= ((duty_cycle/frequency)*(34600)/2) ;

/*
 * Timer_prg.c
 *
 *  Created on: Feb 25, 2023
 *      Author: NTI
 */


#include <avr/interrupt.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu_HW.h"
#include "Timer_priv.h"
#include "Timer_int.h"

static u32 NO_of_OverFlow_counts=0;
static u32 NO_of_compareMatch_counts=0;
static u32 NO_of_Renaming_counts=0;
static u8 value;
static volatile u32 counter=0;

static void (*callBack_ptr)(void)=NULL;

Timer0_config *configptr_timer0_global;

//static u8 mode_global=configptr_timer0_global->wave_mode;

void M_Timer0_void_Init(Timer0_config *configptr_timer0)
{

	switch(configptr_timer0->wave_mode)
		{
			case Normal_mode:
							CLR_BIT(TCCR0_REG,WGM00_BIT );
							CLR_BIT(TCCR0_REG,WGM01_BIT );

						break;

			case PWM_phaseCorrect:
							SET_BIT(TCCR0_REG,WGM00_BIT );
							CLR_BIT(TCCR0_REG,WGM01_BIT );
							break;
			case CTC_mode:
							CLR_BIT(TCCR0_REG,WGM00_BIT );
							SET_BIT(TCCR0_REG,WGM01_BIT );
							break;
			case fast_PWM:
							SET_BIT(TCCR0_REG,WGM00_BIT );
							SET_BIT(TCCR0_REG,WGM01_BIT );
							break;

		}
	switch(configptr_timer0->OC0)
	{
				case normal:
								CLR_BIT(TCCR0_REG,COM00_BIT );
								CLR_BIT(TCCR0_REG,COM01_BIT );
								break;

				case toggel:
								SET_BIT(TCCR0_REG,COM00_BIT );
								CLR_BIT(TCCR0_REG,COM01_BIT );
								break;
				case clear:
								CLR_BIT(TCCR0_REG,COM00_BIT );
								SET_BIT(TCCR0_REG,COM01_BIT );
								break;
				case set:
								SET_BIT(TCCR0_REG,COM00_BIT );
								SET_BIT(TCCR0_REG,COM01_BIT );
								break;
	}

}

void M_Timer0_void_start(u16 prescaler)
{
	// step1 : apply mask

	TCCR0_REG &= PRESCALER_MASK;

	// step 2 insert Mask

	TCCR0_REG |= prescaler;
}

void M_Timer0_void_stop(void)
{
	CLR_BIT(TCCR0_REG,CS00_BIT);
	CLR_BIT(TCCR0_REG,CS01_BIT);
	CLR_BIT(TCCR0_REG,CS02_BIT);
}
u32 M_Timer0_u32_GetCounts(void)
{
	u32 counts=0;
	counts= NO_of_OverFlow_counts *255 +TCNT0_REG;
	return counts;

}

void M_Timer0_void_setDelayTimeMilliSec(Timer0_config *configptr_timer0,u32 delay_ms)
{
	u16 Prescaler_arr[5]={1,8,64,256,1024};
	//calculate ticks time
	f32 Tick_time =(f32) Prescaler_arr[(configptr_timer0->prescaler_value)-1] / FCU;

	u32 desired_ticks = (delay_ms *1000)/Tick_time;

	if(configptr_timer0->wave_mode == Normal_mode )
	{
		NO_of_OverFlow_counts=desired_ticks/256;

			NO_of_Renaming_counts=desired_ticks%256;

			if(NO_of_Renaming_counts!=0)
			{
				TCNT0_REG = 256 - NO_of_Renaming_counts;
				NO_of_OverFlow_counts++;
			}
	}
	else if(configptr_timer0->wave_mode == CTC_mode)
	{
		 value =255;

		while(desired_ticks % value)
		{
			value--;
		}

		NO_of_compareMatch_counts = desired_ticks/ value;
		OCR0_REG = value;
	}


}

void M_Timer0_void_Enable_INT(u8 Timer_INT_ID)
{
	switch (Timer_INT_ID)
	{
	case OV_INT_ID:
		SET_BIT(TIMSK_REG,TOIE0_BIT);
		break;
	case CMP_INT_ID:
		SET_BIT(TIMSK_REG,OCIE0_BIT);
		break;
	}



}

void M_Timer0_void_Disable_INT(u8 Timer_INT_ID)
{
	switch (Timer_INT_ID)
		{
		case OV_INT_ID:
			CLR_BIT(TIMSK_REG,TOIE0_BIT);
			break;
		case CMP_INT_ID:
			CLR_BIT(TIMSK_REG,OCIE0_BIT);
			break;
		}

}

void M_Timer0_void_setCallBack(void (*copy_callBack_ptr)(void))
{
	//if(mode_global==Normal_mode)
	callBack_ptr = copy_callBack_ptr;

}


void M_v_Timer0_setFastPWM( u8 duty_cycle,Timer0_PWM_mode timer0_pwm_mode)
{
	u8 OCR0_value;
	//u16 required_prescaler;

	switch(timer0_pwm_mode)
	{
		case NON_inverting_mode:
							OCR0_value = ((duty_cycle*256)/100)-1;
							OCR0_REG = OCR0_value;
							break;
		case inverting_mode:
							OCR0_value = ((255/256) - (duty_cycle/100))*256;
							OCR0_REG = OCR0_value;
							break;
	}

	//required_prescaler = FCU*1000000/(256*frequency);

	//Timer_start(required_prescaler);

}

void M_v_Timer0_PhaseCorrect( u8 duty_cycle,Timer0_PWM_mode timer0_pwm_mode)
{
	u8 OCR0_value;
	//u16 required_prescaler;

	switch(timer0_pwm_mode)
	{
		case NON_inverting_mode:
							OCR0_value = ((duty_cycle*256)/100);
							OCR0_REG = OCR0_value;
							break;
		case inverting_mode:
							OCR0_value = ( 1 - (duty_cycle/100))*255;
							OCR0_REG = OCR0_value;
							break;
	}

	//required_prescaler = FCU*1000000/(256*frequency);

	//Timer_start(required_prescaler);

}

ISR(TIMER0_OVF_vect)
{
	//if(callBack_ptr!=NULL)

	counter++;

	if(counter==NO_of_OverFlow_counts)
	{
		callBack_ptr();
		counter=0;
		TCNT0_REG = 256 -NO_of_Renaming_counts;
	}

}

ISR(TIMER0_COMP_vect)
{
	//if(callBack_ptr!=NULL)

	counter++;

	if(counter==NO_of_compareMatch_counts)
	{
		callBack_ptr();
		counter=0;
		//OCR0_REG = value;
	}

}



/*
 * Timer1_prg.c
 *
 *  Created on: Mar 1, 2023
 *      Author: nasser
 */
#include "avr/interrupt.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu_HW.h"
#include "Timer1_priv.h"
//#include "Timer1_types.h"
#include "Timer1_int.h"



void M_Timer1_void_Init(u8 timer1_mode)
{

	switch(timer1_mode)
		{
			case Normal_mode_t1:
							CLR_BIT(TCCR1B_REG,WGM10_BIT );
							CLR_BIT(TCCR1B_REG,WGM11_BIT );
							CLR_BIT(TCCR1B_REG,WGM12_BIT );
							CLR_BIT(TCCR1B_REG,WGM13_BIT );

						break;

		}
}

void M_Timer1_void_start(u8 prescaler)
{
	// step1 : apply mask

	TCCR1B_REG &= PRESCALER_MASK;

	// step 2 insert Mask

	TCCR1B_REG |= prescaler;
}

void M_Timer1_void_stop(void)
{
	CLR_BIT(TCCR1B_REG,CS00_BIT);
	CLR_BIT(TCCR1B_REG,CS01_BIT);
	CLR_BIT(TCCR1B_REG,CS02_BIT);
}



void M_Timer1_void_ICU(u8 prescaler_val, u16 *duty_cycle,u16 *frequency )
{

	unsigned short a,b,c,high,period;
	u16 Prescaler_arr[5]={1,8,64,256,1024};

	//M_Timer1_void_start(prescaler_val);
	TCNT1_REG=0;
	TIFR_REG = (1<<ICF1_BIT);  	/* Clear ICF (Input Capture flag)  */

		/* Rising edge,  noise canceler*/
			SET_BIT(TCCR1B_REG,ICES1_BIT);
			SET_BIT(TCCR1B_REG,ICNC1_BIT);

		while ((TIFR_REG&(1<<ICF1_BIT)) == 0);
		a = ICR1_REG;  		/* Take value of capture register */
		TIFR_REG = (1<<ICF1_BIT);  	/* Clear ICF flag */

		/* Falling edge ,noise canceler*/
		CLR_BIT(TCCR1B_REG,ICES1_BIT);
		SET_BIT(TCCR1B_REG,ICNC1_BIT);

		while ((TIFR_REG & (1<<ICF1_BIT)) == 0);
		b = ICR1_REG;  		/* Take value of capture register */
		TIFR_REG = (1<<ICF1_BIT);  	/* Clear ICF flag */

		/* Rising edge,  noise canceler*/
		SET_BIT(TCCR1B_REG,ICES1_BIT);
		SET_BIT(TCCR1B_REG,ICNC1_BIT);

		while ((TIFR_REG &(1<<ICF1_BIT)) == 0);
		c = ICR1_REG;  		/* Take value of capture register */
		TIFR_REG = (1<<ICF1_BIT);  	/* Clear ICF flag */

				high=b-a;

				period=c-a;

				*duty_cycle=((float)high/period)*100;

				*frequency = ((F_CPU / Prescaler_arr[prescaler_val-1]) / (period));

}

u16 M_Timer1_u16_ICU_TON(u8 prescaler_val)
{

	u16 a,b,high;
	u16 distance;
	u16 Prescaler_arr[5]={1,8,64,256,1024};

	//M_Timer1_void_start(prescaler_val);
	TCNT1_REG=0;
		TIFR_REG = (1<<ICF1_BIT);  	/* Clear ICF (Input Capture flag)  */

			/* Rising edge,  noise canceler*/
				SET_BIT(TCCR1B_REG,ICES1_BIT);
				SET_BIT(TCCR1B_REG,ICNC1_BIT);

			while ((TIFR_REG&(1<<ICF1_BIT)) == 0);
			a = ICR1_REG;  		/* Take value of capture register */
			TIFR_REG = (1<<ICF1_BIT);  	/* Clear ICF flag */

			/* Falling edge ,noise canceler*/
			CLR_BIT(TCCR1B_REG,ICES1_BIT);
			SET_BIT(TCCR1B_REG,ICNC1_BIT);

			while ((TIFR_REG & (1<<ICF1_BIT)) == 0);
			b = ICR1_REG;  		/* Take value of capture register */
			TIFR_REG = (1<<ICF1_BIT);  	/* Clear ICF flag */

			high=b-a;
			distance=((high*34600)/(F_CPU*2 / Prescaler_arr[prescaler_val-1])) ;

return distance;
}
#if 0

#endif


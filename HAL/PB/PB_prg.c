/*
 * PB_prg.c
 *
 *  Created on: Feb 18, 2023
 *      Author: NTI
 */
#include "avr/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu_HW.h"
#include "Dio_int.h"
#include "PB_priv.h"
#include "PB_cfg.h"
#include "PB_int.h"

u8 H_PB_u8_Read(u8 PB_ID)
{
	u8 states;
	switch(PB_ID)
	{
	case PB1_ID:
#if(PB1_status == PULL_UP)


	if(M_Dio_en_getPinValue(PB1_PIN)== ACTIVE_LOW)
	{
		_delay_ms(30);

		if(M_Dio_en_getPinValue(PB1_PIN)== ACTIVE_LOW)
		{
			states=PB_PREESED;
		}

	}
	else
	{
		states=PB_RELEASED;
	}

#elif(PB1_status == PULL_DOWN)
	if(M_Dio_en_getPinValue(PB1_PIN)== ACTIVE_HIGH)
		{
			_delay_ms(30);

			if(M_Dio_en_getPinValue(PB1_PIN)== ACTIVE_HIGH)
			{
				states=PB_PREESED;
			}

		}
		else
		{
			states=PB_RELEASED;
		}
#else
#error ("Wrong PB Direction");
#endif
		_delay_ms(200);
		break;
	/*****************PB2******************/
	case PB2_ID:
	#if(PB2_status == PULL_UP)

	if(M_Dio_en_getPinValue(PB2_PIN)== ACTIVE_LOW)
		{
			_delay_ms(30);

			if(M_Dio_en_getPinValue(PB2_PIN)== ACTIVE_LOW)
			{
				states=PB_PREESED;
			}

		}
		else
		{
			states=PB_RELEASED;
		}

	#elif(PB2_status == PULL_DOWN)
		if(M_Dio_en_getPinValue(PB2_PIN)== ACTIVE_HIGH)
			{
				_delay_ms(30);

				if(M_Dio_en_getPinValue(PB2_PIN)== ACTIVE_HIGH)
				{
					states=PB_PREESED;
				}

			}
			else
			{
				states=PB_RELEASED;
			}
	#else
	#error ("Wrong PB Direction");
	#endif
			_delay_ms(250);
			break;
	/*****************PB3******************/
		case PB3_ID:
		#if(PB3_status == PULL_UP)
			if(M_Dio_en_getPinValue(PB3_PIN)== ACTIVE_LOW)
			{
				_delay_ms(30);

				if(M_Dio_en_getPinValue(PB3_PIN)== ACTIVE_LOW)
				{
					states=PB_PREESED;
				}

			}
			else
			{
				states=PB_RELEASED;
			}

		#elif(PB3_status == PULL_DOWN)
			if(M_Dio_en_getPinValue(PB3_PIN)== ACTIVE_HIGH)
				{
					_delay_ms(30);

					if(M_Dio_en_getPinValue(PB3_PIN)== ACTIVE_HIGH)
					{
						states=PB_PREESED;
					}

				}
				else
				{
					states=PB_RELEASED;
				}
			#else
			#error ("Wrong PB Direction");
			#endif
				_delay_ms(250);
				break;
		/*****************PB4******************/
			case PB4_ID:
			#if(PB4_status == PULL_UP)
				if(M_Dio_en_getPinValue(PB4_PIN)== ACTIVE_LOW)
					{
						_delay_ms(30);

						if(M_Dio_en_getPinValue(PB4_PIN)== ACTIVE_LOW)
						{
							states=PB_PREESED;
						}

					}
					else
					{
						states=PB_RELEASED;
					}

				#elif(PB1_status == PULL_DOWN)
					if(M_Dio_en_getPinValue(PB4_PIN)== ACTIVE_HIGH)
						{
							_delay_ms(30);

							if(M_Dio_en_getPinValue(PB4_PIN)== ACTIVE_HIGH)
							{
								states=PB_PREESED;
							}

						}
						else
						{
							states=PB_RELEASED;
						}
				#else
				#error ("Wrong PB Direction");
				#endif
						_delay_ms(250);
					break;

	}


return states;
}

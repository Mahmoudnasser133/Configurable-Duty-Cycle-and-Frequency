/*
 * ADC_prg.c
 *
 *  Created on: Mar 3, 2023
 *      Author: NTI
 */



#include "avr/interrupt.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu_HW.h"
#include "ADC_priv.h"
#include "ADC_int.h"
#include "Lcd_int.h"

static void (*callBack__ADC_ptr)(void)= NULL;

 void M_ADC_void_Init(ADC_config *configptr_ADC)
 {
	 	switch(configptr_ADC->Vref)
	 	{
	 	case Internalturnedoff:
	 				CLR_BIT(ADMUX_REG,REFS0_BIT);
					CLR_BIT(ADMUX_REG,REFS1_BIT);
					break;
	 	case VCC_external:
	 				SET_BIT(ADMUX_REG,REFS0_BIT);
	 				CLR_BIT(ADMUX_REG,REFS1_BIT);
	 				break;
	 	case Internal:
	 		 			SET_BIT(ADMUX_REG,REFS0_BIT);
	 		 			SET_BIT(ADMUX_REG,REFS1_BIT);
	 		 			break;

	 		/*
	 		 *  // step1 : apply mask
	 	ADMUX_REG &= vref_mask;

	 	// step 2 insert Mask
	 	ADMUX_REG |= configptr_ADC->Vref;
	 		 */
	 	}

	 	// step1 : apply mask for PRESCALER
			ADCSRA_REG &= ADC_PRESCALER_mask;

			// step 2 insert Mask
			ADCSRA_REG |= configptr_ADC->Prescaler_value;

		switch(configptr_ADC->Adjust_result)
				{
				case Right_adjust:
							CLR_BIT(ADMUX_REG,ADLAR_BIT);
							break;
				case Left_adjust:
							SET_BIT(ADMUX_REG,ADLAR_BIT);
							break;
				}

		//ENABEL ADC
		SET_BIT(ADCSRA_REG,ADEN_BIT);

 }

 u16 M_ADC_u16_getDigitalValueSynchNonBlocking(ADC_config* configptr_ADC)
 {

	 u16 counter=0,read_value;

	 // step1 : apply mask for PRESCALER
	 ADMUX_REG&= ADC_channal_mask;

	 // step 2 insert Mask
	 ADMUX_REG |= configptr_ADC->ADC_channel;

	 //start conversion
	 SET_BIT(ADCSRA_REG,ADSC_BIT);



	 while(( (GET_BIT(ADCSRA_REG,ADIF_BIT))== 0) && counter < MAX_COUNTER)

	 {
		 counter++;
	 }

if( ( GET_BIT(ADCSRA_REG,ADIF_BIT))== 1)
		{
			//clear flag
			SET_BIT(ADCSRA_REG,ADIF_BIT);
		}

/*
	 read_value = ADCL_REG ;
	 read_value = (ADCH_REG << 8);
*/
read_value = ADC_REG ;
	 return read_value;

 }


 void M_ADC_getDigitalValueAsynchCallBack(void (*copy_callBack_ptr)(void), ADC_config* configptr_ADC)
 {
if(copy_callBack_ptr != NULL)

	{
		callBack__ADC_ptr = copy_callBack_ptr;
	}
/*************** select channel***********************/
	 // step1 : apply mask for PRESCALER
	 ADMUX_REG&= ADC_channal_mask;

	 // step 2 insert Mask
	 ADMUX_REG |= configptr_ADC->ADC_channel;


		/********************* Enable interrupt *********/
		SET_BIT(ADCSRA_REG,ADIE_BIT);
	/*************************** start conversion ***************/
		SET_BIT(ADCSRA_REG,ADSC_BIT);

//		if( ( GET_BIT(ADCSRA_REG,ADIF_BIT))== 1)
//				{
//					//clear flag
//					SET_BIT(ADCSRA_REG,ADIF_BIT);
//				}
 }

ISR(ADC_vect)
{

		callBack__ADC_ptr();



}

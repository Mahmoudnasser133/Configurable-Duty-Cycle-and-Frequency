/*
 * ADC_cfg.h
 *
 *  Created on: Mar 3, 2023
 *      Author: NTI
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

typedef struct
{
	ADC_PrescalerSelections		Prescaler_value;
	ADC_adjust					Adjust_result;
	Volt_refrence				Vref;
	ADC_channal_Singel_ended	ADC_channel;
}ADC_config;

#endif /* ADC_CFG_H_ */

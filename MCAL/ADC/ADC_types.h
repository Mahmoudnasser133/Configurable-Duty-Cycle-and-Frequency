/*
 * ADC_types.h
 *
 *  Created on: Mar 3, 2023
 *      Author: NTI
 */

#ifndef ADC_ADC_TYPES_H_
#define ADC_ADC_TYPES_H_

typedef enum
{
	Internalturnedoff,
	VCC_external,
	Internal=3
}Volt_refrence;

typedef enum
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
}ADC_channal_Singel_ended;

typedef enum
{
	Prescaler_2,
	Prescaler_4=2,
	Prescaler_8,
	Prescaler_16,
	Prescaler_32,
	Prescaler_64,
	Prescaler_128

}ADC_PrescalerSelections;

typedef enum
{
	Right_adjust,
	Left_adjust
}ADC_adjust;

#endif /* ADC_ADC_TYPES_H_ */

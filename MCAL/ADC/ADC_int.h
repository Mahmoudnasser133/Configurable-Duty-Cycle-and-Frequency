/*
 * ADC_int.h
 *
 *  Created on: Mar 3, 2023
 *      Author: NTI
 */

#ifndef ADC_ADC_INT_H_
#define ADC_ADC_INT_H_

#include "STD_TYPES.h"
#include "ADC_types.h"
#include "ADC_cfg.h"

/*
 * this function should select ( Vref , Right or Left adjust
, prescaler , autotrigger or Not , and ADC enable).
 */
 void M_ADC_void_Init(ADC_config* configptr_ADC);

 /*
  *
needs to know the channel , this fn works in a polling
fashion but with time out .
  *
  */
 u16 M_ADC_u16_getDigitalValueSynchNonBlocking(ADC_config* configptr_ADC);

 void M_ADC_getDigitalValueAsynchCallBack(void (*copy_callBack_ptr)(void), ADC_config* configptr_ADC);
#endif /* ADC_ADC_INT_H_ */

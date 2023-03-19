/*
 * SSD_prg.c
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */
#include "avr/delay.h"
#include "STD_TYPES.h" //library
#include "Dio_int.h" // lower layer
			// driver
#include "SSD_priv.h"
#include "SSD_types.h"
#include "SSD_cfg.h"
#include "SSD_int.h"

void H_SSD_void_displayIntNumber(u16 copy_Number)
{
	u8 arr[4]={0};
	u8 i=0;
	while(copy_Number>0 && i<4)
	{
		arr[i]=copy_Number%10;
		copy_Number/=10;
		i++;
	}
u8 j=0;
	for (j=0;j<SSD_DISPLAY_TIME;j++)
	{
		// prepare units to be send to BCD
		i=0;
		M_Dio_void_setPinValue(SSD_A_PIN, (arr[i]>>0)&1 );
		M_Dio_void_setPinValue(SSD_B_PIN, (arr[i]>>1)&1 );
		M_Dio_void_setPinValue(SSD_C_PIN, (arr[i]>>2)&1 );
		M_Dio_void_setPinValue(SSD_D_PIN, (arr[i]>>3)&1 );

		//Enable  Digit 1 (it is pnp)(active low)
		M_Dio_void_setPinValue(SSD_DIG1_EN,DIO_LOW );
		_delay_ms(1);
		M_Dio_void_setPinValue(SSD_DIG1_EN,DIO_HIGH );

		// prepare tens to be send to BCD
		i=1;
		M_Dio_void_setPinValue(SSD_A_PIN, (arr[i]>>0)&1 );
		M_Dio_void_setPinValue(SSD_B_PIN, (arr[i]>>1)&1 );
		M_Dio_void_setPinValue(SSD_C_PIN, (arr[i]>>2)&1 );
		M_Dio_void_setPinValue(SSD_D_PIN, (arr[i]>>3)&1 );

		//Enable  Digit 1 (it is pnp)(active low)
		M_Dio_void_setPinValue(SSD_DIG2_EN,DIO_LOW );
		_delay_ms(1);
		M_Dio_void_setPinValue(SSD_DIG2_EN,DIO_HIGH );
		// prepare 100 to be send to BCD
			i=2;
			M_Dio_void_setPinValue(SSD_A_PIN, (arr[i]>>0)&1 );
			M_Dio_void_setPinValue(SSD_B_PIN, (arr[i]>>1)&1 );
			M_Dio_void_setPinValue(SSD_C_PIN, (arr[i]>>2)&1 );
			M_Dio_void_setPinValue(SSD_D_PIN, (arr[i]>>3)&1 );

			//Enable  Digit 1 (it is pnp)(active low)
			M_Dio_void_setPinValue(SSD_DIG3_EN,DIO_LOW );
			_delay_ms(1);
			M_Dio_void_setPinValue(SSD_DIG3_EN,DIO_HIGH );

			// prepare thousand to be send to BCD
			i=3;
			M_Dio_void_setPinValue(SSD_A_PIN, (arr[i]>>0)&1 );
			M_Dio_void_setPinValue(SSD_B_PIN, (arr[i]>>1)&1 );
			M_Dio_void_setPinValue(SSD_C_PIN, (arr[i]>>2)&1 );
			M_Dio_void_setPinValue(SSD_D_PIN, (arr[i]>>3)&1 );

			//Enable  Digit 1 (it is pnp)(active low)
			M_Dio_void_setPinValue(SSD_DIG4_EN,DIO_LOW );
			_delay_ms(1);
			M_Dio_void_setPinValue(SSD_DIG4_EN,DIO_HIGH );
	}
}

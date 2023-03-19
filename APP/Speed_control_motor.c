/*
 * Speed_control_motor.c
 *
 *  Created on: Mar 5, 2023
 *      Author: nasser
 */


#include <avr/delay.h>
#include "STD_TYPES.h"
#include "Port_int.h"
#include "Dio_int.h"
#include "Led_int.h"

#include "Mcu_HW.h"
#include "BIT_MATH.h"

#include "Lcd_int.h"
#include "Keypad_int.h"

#include "Glint.h"
#include "Timer_int.h"
#include "Timer1_int.h"
#include "DC_motor_int.h"


extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];

Timer0_config Timer0_config_struct1={prescaler_1024,PWM_phaseCorrect,clear};




int main()
{
Port_Init(PORT_Config_Arr);

	H_LCD_void_Init();
	H_DC_Motor_void_Enabel(Anti_ClockWith);

	M_Timer0_void_Init(&Timer0_config_struct1);
	//M_v_Timer0_PhaseCorrect(80, NON_inverting_mode);
	//M_Timer0_void_start(Timer0_config_struct1.prescaler_value);


while(1)
{
		H_LCD_void_clearScreen();
		H_LCD_void_sendString("Enter Duty");
		H_LCD_void_gotoXY(2,1);


/*************************** scan tens ******************************/
		u8 duty_choice_tens = NO_PRESSED_KEY;

		do
		{
			duty_choice_tens = H_KEYPAD_u8_getPressedKey();

		}while(duty_choice_tens == NO_PRESSED_KEY);
		_delay_ms(200);

		H_LCD_void_sendData(duty_choice_tens);

/***************************** scan ones *******************************/
		u8 duty_choice_ones = NO_PRESSED_KEY;

			do
			{
				duty_choice_ones = H_KEYPAD_u8_getPressedKey();

			}while(duty_choice_ones == NO_PRESSED_KEY);
			_delay_ms(250);

			H_LCD_void_sendData(duty_choice_ones);

u8 duty_cycle = (duty_choice_tens - 48) * 10 + (duty_choice_ones-48);


		H_LCD_void_gotoXY(3,1);
		H_LCD_void_sendString("Duty= ");
		H_LCD_void_sendIntNum(duty_cycle);
		_delay_ms(1000);

		M_v_Timer0_PhaseCorrect(duty_cycle, NON_inverting_mode);
/******************************************************************/

		H_LCD_void_clearScreen();
		H_LCD_void_sendString("Enter Prescaler");
		H_LCD_void_gotoXY(2,1);
		H_LCD_void_sendString("1-1024  2-256");
		H_LCD_void_gotoXY(3,1);
		H_LCD_void_sendString("3- 64 	 4-8");


/*************************** scan Prescaler ***************************/
		u8 freq_choice = NO_PRESSED_KEY;

		do
		{
			freq_choice = H_KEYPAD_u8_getPressedKey();

		}while(freq_choice == NO_PRESSED_KEY);
		_delay_ms(200);


		switch(freq_choice)
		{

		case '1':

			H_LED_void_turnON(LED_GRN);
			H_LED_void_turnON(LED_RED);
			H_LED_void_turnON(LED_BLUE);
			H_LED_void_turnON(LED_YELLOW);

			M_Timer0_void_start(prescaler_1024);
			break;

		case '2':

				H_LED_void_turnON(LED_GRN);
				H_LED_void_turnON(LED_RED);
				H_LED_void_turnON(LED_BLUE);
				H_LED_void_turnOFF(LED_YELLOW);

			M_Timer0_void_start(prescaler_256);
			break;

		case '3':

			H_LED_void_turnON(LED_RED);
			H_LED_void_turnON(LED_GRN);
			H_LED_void_turnOFF(LED_BLUE);
			H_LED_void_turnOFF(LED_YELLOW);

			M_Timer0_void_start(prescaler_64);
			break;

		case '4':

			H_LED_void_turnON(LED_RED);
			H_LED_void_turnOFF(LED_GRN);
			H_LED_void_turnOFF(LED_BLUE);
			H_LED_void_turnOFF(LED_YELLOW);

			M_Timer0_void_start(prescaler_8);
			break;

		default:
			H_LCD_void_clearScreen();
			H_LCD_void_sendString("Wrong Choice");
			H_LCD_void_gotoXY(2, 1);
			H_LCD_void_sendString("Please Choose");
			H_LCD_void_gotoXY(3, 1);
			H_LCD_void_sendString("1,2,3 OR 4");
			_delay_ms(1500);
			break;
		}//switch

	}//while



return 0;
}//main

/*
 * UART_prg.c
 *
 *  Created on: Mar 4, 2023
 *      Author: nasser
 */
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu_HW.h"
#include "UART_int.h"


void M_UART_void_int(UART_config *UART_cofig_ptr)
{

	//calculate UBRR_reg
	u16 UBRR;

	UBRR = (FCPU/( 16 * ( UART_cofig_ptr->Baud_rate) )) - 1 ;
	UBRRH_REG=(u8)(UBRR>>8);
	UBRRL_REG=(u8)UBRR;

/*************************************************************/
	//select parity mode

	//APPLY MASK
	UCSRC_REG &= PARITY_MASK;
	//insert mask
	UCSRC_REG |= (1<<URSEL_BIT) | ((UART_cofig_ptr->parity_Mode)<<4);
/*************************************************************/
// select NO of stop bits

	//APPLY MASK
	UCSRC_REG &= STOP_BIT_MASK;
	//insert mask
	UCSRC_REG |= (1<<URSEL_BIT) | ((UART_cofig_ptr->NO_stopBits)<<3);
/*************************************************************/
	//select Word Length

	//APPLY MASK
	UCSRC_REG &= WORD_LENGTH_MASK;
	//insert mask
	UCSRC_REG |= (1<<URSEL_BIT) | ((UART_cofig_ptr->Word_leght)<<1);

	if(UART_cofig_ptr->Word_leght == nine)
	{
		SET_BIT(UCSRB_REG,2);
	}
/*************************************************************/
/* Enable USART Sender & Receiver*/
	SET_BIT(UCSRB_REG,TXEN_BIT);
	SET_BIT(UCSRB_REG,RXEN_BIT);

}

void M_UART_v_SendData(u8 data)
{
	u16 counter=0;
	/*Wait for UDR transmit buffer to be empty*/
	while( (GET_BIT(UCSRA_REG,UDRE_BIT)== 0) && counter < MAXCOUNTER)
	{
		counter++;
	}
	/*Put data to UDR transmit buffer transmit*/
	UDR_REG = data ;
}

u8 M_UART_u8_ReceiveData(void)
{
	u16 counter=0;
		/*Wait for UDR receive buffer to be filled with data*/
	while( (GET_BIT(UCSRA_REG,RXC_BIT)== 0) && counter < MAXCOUNTER)
	{
		counter++;
	}
		/*Receive data from UDR receive buffer*/
		return UDR_REG ;
}

void M_UART_vSendstring( u8 *ptr)
{
	while(*ptr!='\0')
	{
		M_UART_v_SendData(*ptr);
		ptr++;
		_delay_ms(100);
	}
}






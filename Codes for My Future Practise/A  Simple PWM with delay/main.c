 /**
	@author 
 
	@file main.c
	@brief ENTER discription
*/

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
// newly added
#include <util/delay.h>
#include <stdio.h>
#include "lcd.h"
 

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Init the microcontroller
*/
void init(void){
	// Digital I/O init----------------------------------------------------
	DDRB &= ~(1 << DDB0);		// PB0 as Input (key 1)
	PORTB |= ( 1 << PB0);		// Pullup PB0

	DDRB |=  (1 << DDB1);		// PB1 as Output (LED red)
	DDRB |=  (1 << DDB2);		// PB1 as Output (LED yellow)
	DDRB |=  (1 << DDB3);		// PB1 as Output (LED green)

 

}
/******************************************************************************/


/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){
	
	 
	init();

	// Loop forever
	while (1){
		if (~PINB & (1<<PB0)){
		PORTB |= (1<<PB1);
		_delay_ms(20);
		PORTB &= ~(1<<PB1);
		_delay_ms(50);
		}
		else
		{
		PORTB |= (1<<PB1);
		}			
		}
	return 0;
}
/******************************************************************************/

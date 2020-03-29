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
#define F_CPU 8000000UL //CPU clock

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


	// ADC init------------------------------------------------------------
	DDRC &= ~(1 << DDC3);		// PC3 as Input (Poti)
	PORTC &= ~(1 << DDC3);		// Pullup PC3 OFF	
	
	// ADMUX
	ADMUX = 0;
	ADMUX |= (1 << REFS0); // AVCC as reference
	//TODO Use the datasheet
	//ADMUX |= (1 << MUX0)|(1 << MUX1); // Select Channel ADC3
	
	// ADCSRA
	ADCSRA = (1 << ADPS2)|(1 << ADPS1); // Set ADC Prescale to 64

	// Start conversion, Free running, Enalbe ADC
	ADCSRA |= (1 << ADSC)|(1 << ADATE)|(1 << ADEN); 

}
/******************************************************************************/


/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){
	
	 
	uint16_t adc;
	 
	// Init
	init();

	// Loop forever
	while (1){
	
	 // Task 2.2.3 Analogue to Digital Converter
		 
		
		adc = ADCW;
		
		if (adc < 340){
			PORTB |= (1 << PB3);
			PORTB &= ~(1 << PB1);
			PORTB &= ~(1 << PB2);
		}
			
		if (adc >= 340 && adc < 680){
			PORTB |= (1 << PB2);
			PORTB &= ~(1 << PB3);
			PORTB &= ~(1 << PB1);
		}
			
		if (adc >= 680 && adc <=1023){
			PORTB |= (1 << PB1);
			PORTB &= ~(1 << PB2);
			PORTB &= ~(1 << PB3);
		}

		 
	}
	return 0;
}
/******************************************************************************/

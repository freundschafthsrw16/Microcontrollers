/**
	@author
	@This code has changed with masoud, the delay function has removed and instead only a simple delay 
	@version 0.1
	@file main.c
	@brief ENTER discription
*/

/**
	@brief The CPU speed in Hz
*/
#define F_CPU 8000000UL

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Init the microcontroller
*/
void init(void){

	// Init key inputs
	DDRB &=  ~(1 << DDB2);		// PB2 input
	DDRC &=  ~(1 << DDC0);		// PC0 input
	PORTB |= (1 << PB2); // enable Pullup PB2
	PORTC |= (1 << PC0); // enable Pullup PC0


	// Init LED outputs
	//TODO
	DDRB |= (1 << DDB0);	// PB0 output
	DDRB |= (1 << DDB1);	// PB1 output
	
	// pin change interrupt register setting and selecting other pins than D2 and D3 for external interrupt
	PCICR |= (1<<PCIE0)|(1<<PCIE1); 
	PCMSK0 |= (1<<PCINT2);//PB2 selected as external interrupt pin
	PCMSK1 |= (1<<PCINT8);// PC0 selected as external interrupt pin
       
}
/*********************************************************************************/
                                 /*Delay Function*/
/*********************************************************************************/
//delay function
void mydelay(uint8_t time){
	
	while (time > 0){
		_delay_ms(250);
		time--;
	}
	
	return;
}
/******************************************************************************/




/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){
		
	// Init
	init();

	// Global interrupt enable
	sei();

	// Loop forever
	while (1){
		
		/* Task 2.1.b
		** Blink Yellow LED every 0.5 sec
		*/
		PORTB ^= (1 << PB1);
		mydelay(1);
		
				
	}
	
	return 0;
}
/******************************************************************************/

/**
	@brief pin change interrupt(PCINT) and its related ISRs
*/

/******************************************************************************/
ISR(PCINT0_vect){
	PORTB |= (1 << PB0);
	
	}
/******************************************************************************/
ISR(PCINT1_vect){
	
	PORTB &= ~(1 << PB0);
	}
/*******************************************************************************/
/*******************************************************************************/

/**
	@author Masoud & Oussama
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
	DDRD &=  ~(1 << DDD2);		// PD2 input
	DDRD &=  ~(1 << DDD3);		// PD3 input
	PORTD |= (1 << PD2); // enable Pullup PD2
	PORTD |= (1 << PD3); // enable Pullup PD3


	// Init LED outputs
	//TODO
	DDRB |= (1 << DDB0);	// PB0 output
	DDRB |= (1 << DDB1);	// PB1 output
	
	// Enable interrupts
	//TODO for Task 2.2
	EICRA |= (1 << ISC01) | (1 << ISC11);
	EIMSK |= (1 << INT0) | (1 << INT1);  //Enabling external interrupt
			
}

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
		mydelay(2);
				
	}
	
	return 0;
}
/******************************************************************************/

/**
	@brief INT0 interrupt
*/

ISR(INT0_vect){
	// Your code here
	PORTB |= (1 << PB0);
}
/******************************************************************************/

/**
	@brief INT1 interrupt
*/

ISR(INT1_vect){
	// Your code here
	PORTB &= ~(1 << PB0);
	}
/******************************************************************************/


/**
	@author ENTER YOUR NAME
	@version 0.1
	@file main.c
	@brief ENTER discription
*/

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
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

	// Analog input
	DDRC &= ~(1 << DDC0);		// PC0 as Input (ADC0)
	PORTC &= ~( 1 << PC0);		// Pullup PC0 off

	// Init LED outputs
	DDRB |= (1<<PB0);
	DDRB |= (1<<PB1);
	DDRB |= (1<<PB2);	
	// Enable interrupts
	//TODO
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
	//sei();

	// Loop forever
	while (1){
		
		if 
		(~PIND & (1 << PD2)){
		PORTB |= (1<<PB0);
				}
		else 
		
		PORTB &= ~(1<<PB0);
		
		

	}
	
	return 0;
}
/******************************************************************************/

/**
	@brief INT0 interrupt
*/
//ISR(INT0_vect){
	// Your code here
//}
/******************************************************************************/

/**
	@brief INT1 interrupt
*/
//ISR(INT1_vect){
	// Your code here
//}
/******************************************************************************/

/**
	@brief Timer1 overflow interrupt
*/
//ISR(TIMER1_OVF_vect){
	// Your code here
//}
/******************************************************************************/

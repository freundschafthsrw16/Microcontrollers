/**
	@author ENTER YOUR NAME
	@version 0.1
	@file main.c
	@brief ENTER discription
*/

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
//#include <avr/io.h>
#include <avr/interrupt.h>
/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
// newly added
#include <util/delay.h>
#include <stdio.h>
/*************************************************************************/
#define F_CPU 1000000UL //CPU clock

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Init the microcontroller
*/
void init(void){
	
	//VARIABLE DECLARATION
	
	// Init key inputs
	DDRB &=  ~(1 << DDB0);		// PB0 input
	
	//DDRB &=  ~(1 << DDB4);		//PB4 INPUT

	PORTB |= (1 << PB0);           // enable Pullup PB0
	
	//PORTB |= (1 << PB4); // enable Pullup PB4
/******************************************************************************/

	// Init LED outputs
	
	DDRB |= (1<<PB1);
	DDRB |= (1<<PB2);
		
	// Enable interrupts
	//TODO
}
	




/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){
	
	// Init
	
	volatile uint8_t Button1 = 0;
	int i;
	
	init();
	
	// Global interrupt enable
	//sei();

	// Loop forever
	while (1){

           if ( ~PINB & (1 << PB0) ){
	            _delay_us(100);
            while (~PINB & (1 << PB0)){
                                      }
           
                Button1 = !Button1;
		                    }
	    if (Button1==1){
	        for(i=5;i>0;--i){
		PORTB |= ((1<<PB1) | (1<<PB2));
		_delay_ms(500);
		PORTB &= ~((1<<PB1) | (1<<PB2));
		_delay_ms(500);
                                }
		 Button1 =0;
		           }
	    else {
		PORTB &= ~(1<<PB1);
		PORTB &= ~(1<<PB2);
		}
           

	       }

	
	return 0;
 }


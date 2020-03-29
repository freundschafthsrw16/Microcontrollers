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

/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
//#include "lcd.h"
/******************************************************************************/
#define F_CPU 1000000UL //CPU clock-Be careful to change in external clock with different frequency is used

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
	
	// Pullup enable
	PORTB |= (1 << PB0); // enable Pullup PB0
	
/******************************************************************************/

	// Init LED outputs
	
	DDRD |= (1<<PD2);
		
 }

	



/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){
	
	// Init
	
	volatile uint8_t Button1 = 0;
	
	init();
	
	

	// Loop forever
	while (1){
	
           if ( ~PINB & (1 << PB0) ){
                  _delay_us(200);
               while (~PINB & (1 << PB0)){
                                         }
         
                Button1 = !Button1;
		                    }
		if(Button1){
			PORTD |=(1<<PD2);			
			   }
		else{
			PORTD &= ~(1<<PD2);
		    }

	         }

	
	return 0;
}


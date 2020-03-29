/**
    @author J.C. Mariscal and Zhiwen He
    MIT License
*/


/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include "init.h"
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Init the PORTx and DDRx register for the I/O setup
*/
void init(void){

    // input
	DDRC &= ~(1 << PC0); // PC0 to input, pcint8
	DDRB &= ~(1 << PB5); // PB2 to input, pcint5

	// Enable Pullup resistors
        PORTC |= (1 << PC0);
	PORTB |= (1 << PB5);
	
	//DDRC |= (1 << DDC5);	// PC5 output
	// TWI / I2C
	//DDRC &= ~(1 << PC5);
	//DDRC &= ~(1 << PC4);
	//PORTC |= (1 << PC5);
	//PORTC |= (1 << PC4);
	//TWBR = 25;
	//TWSR = (1<<TWPS0);

}
/******************************************************************************/


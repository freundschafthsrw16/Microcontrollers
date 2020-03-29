/**
	@author Masoud & Oussama
	@version 0.1
	@file main.c
	@brief ENTER discription
*/

/**
	@brief The CPU speed in Hz
*/
#define F_CPU 1000000UL  //Using internal clock

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
	DDRB &=  ~(1 << DDB0);		// PD2 input
	DDRB &=  ~(1 << DDB1);		// PD3 input
	PORTB |= (1 << PB0); // enable Pullup PD2
	PORTB |= (1 << PB1); // enable Pullup PD3

	// Analog input
	DDRC &= ~(1 << DDC0);		// PC0 as Input (ADC0)
	PORTC &= ~( 1 << PC0);		// Pullup PC0 off

	// Init LED outputs
	DDRD |= (1 << DDD0);	// PB2 output
	DDRD |= (1 << DDD1);
	DDRD |= (1 << DDD2);
	DDRD |= (1 << DDD3);
	DDRD |= (1 << DDD4);
// ADC init------------------------------------------------------------
	
	
	// ADMUX
	ADMUX = 0;
	ADMUX |= (1 << REFS0); // AVCC as reference
	//TODO Use the datasheet
	//ADMUX |= (1 << MUX0)|(1 << MUX1); // Select Channel ADC3
	//ADMUX |= 0;
	// ADCSRA
	ADCSRA = (1 << ADPS2)|(1 << ADPS1); // Set ADC Prescale to 64

	// Start conversion, Free running, Enalbe ADC
	ADCSRA |= (1 << ADSC)|(1 << ADATE)|(1 << ADEN); 




/******************************************************************************/
	// Enable interrupts
	//TODO for Task 2.2
	
	TCCR1B |= (1 << CS11) ;			// Prescaler 8  selected
	//Output compare register value
	OCR1A=32568;
		
}


/******************************************************************************/




/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){
		
	// Init
	init();
	
	uint16_t adc;
	// Global interrupt enable
	sei();
	
	// Loop forever
	while (1){

		
				
	                  
		
	if ( ~PINB & (1 << PB0) ){
	            _delay_us(100);
            while (~PINB & (1 << PB0)){
                                      }
           
              
		TIMSK1 |= (1 << OCIE1A);
		TIMSK1 |= (1 << TOIE1);
		
		                 }
        
	if ( ~PINB & (1 << PB1) ){
		TIMSK1 &= ~(1 << OCIE1A);
		TIMSK1 &= ~(1 << TOIE1);
		PORTD &= ~(1 << PD0);
	        PORTD &= ~(1 << PD1);
		TCNT1=0;
		                 }
/*ACD PART OF THE CODE: **************************************************************************/
		
		adc = ADCW;
		if (adc <256 ){
			PORTD &= ~(1 << PD2);
			PORTD &= ~(1 << PD3);
			PORTD &= ~(1 << PD4);
                }

		if (adc >=256 && adc < 512 ){
			PORTD |= (1 << PD2);
			PORTD &= ~(1 << PD3);
			PORTD &= ~(1 << PD4);
		}
			
		if (adc >= 512 && adc < 768){
			PORTD |= (1 << PD2);
			PORTD |= (1 << PD3);
			PORTD &= ~(1 << PD4);
		}
			
		if (adc >= 768 && adc <=1023){
			PORTD |= (1 << PD2);
			PORTD |= (1 << PD3);
			PORTD |= (1 << PD4);
		}
			
/***********************************************************************************/
		 }
	
	return 0;
}


/**
	@brief Timer1 overflow interrupt
*/
ISR(TIMER1_OVF_vect){
	
	PORTD &= ~(1 << PD0);
	PORTD |= (1 << PD1);
}
/******************************************************************************/
/**
	@brief Timer1 Output compare
*/
ISR(TIMER1_COMPA_vect){
	
	PORTD |= (1<<PD0);
	PORTD &= ~(1<<PD1);
	
}
/******************************************************************************/

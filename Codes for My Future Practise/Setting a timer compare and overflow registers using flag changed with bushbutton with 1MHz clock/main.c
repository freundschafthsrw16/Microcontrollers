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
	DDRD &=  ~(1 << DDD2);		// PD2 input
	DDRD &=  ~(1 << DDD3);		// PD3 input
	PORTD |= (1 << PD2); // enable Pullup PD2
	PORTD |= (1 << PD3); // enable Pullup PD3

	// Analog input
	DDRC &= ~(1 << DDC0);		// PC0 as Input (ADC0)
	PORTC &= ~( 1 << PC0);		// Pullup PC0 off

	// Init LED outputs
	//TODO
	DDRB |= (1 << DDB0);	// PB0 output
	DDRB |= (1 << DDB1);	// PB1 output
	DDRB |= (1 << DDB2);	// PB2 output
	DDRB |= (1 << DDB3);
	// Enable interrupts
	//TODO for Task 2.2
	//EIMSK |= (1 << INT0) | (1 << INT1);
	//EICRA |= (1 << ISC01) | (1 << ISC11);
	
	// Timer1 for Task 2.3  P*133-134
	//TCCR1B |= (1 << CS10) |  (1 << CS11) ;	// Prescaler 64 selected
	TCCR1B |= (1 << CS11) ;			// Prescaler 8  selected
	//Timer/Counter Interrupt Mask Register-P*135
	
	//TIMSK1 |= (1 << TOIE1);	//Timer/Counter1 Overflow Interrupt Enable */
	//TIMSK1 |= (1 << OCIE1A);//Timer/Counter1 Output Compare Interrupu Enable*/
	
	OCR1A=30068;
		
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
	volatile uint8_t Button1 = 0;
	
	// Global interrupt enable
	sei();
	//int a = TCNT1;	
	// Loop forever
	while (1){

		
				
	                  
		
	if ( ~PIND & (1 << PD2) ){
	            _delay_us(100);
            while (~PIND & (1 << PD2)){
                                      }
           
                Button1 = !Button1;
		                 }
	if (Button1==1){
		//TIMSK1 |= (1 << TOIE1);
		TIMSK1 |= (1 << OCIE1A);
		TIMSK1 |= (1 << TOIE1);
		           }
         else {
		//TIMSK1 &= ~(1 << TOIE1);
		TIMSK1 &= ~(1 << OCIE1A);
		TIMSK1 &= ~(1 << TOIE1);
		PORTB &= ~(1 << PB3);
	        PORTB &= ~(1 << PB2);
		TCNT1=0;
		 }
		 }
	
	return 0;
}
/******************************************************************************/

/**
	@brief INT0 interrupt
*/

/*ISR(INT0_vect){
	// Your code here
	PORTB |= (1 << PB0);
}*/
/******************************************************************************/

/**
	@brief INT1 interrupt
*/

/*ISR(INT1_vect){
	// Your code here
	PORTB &= ~(1 << PB0);
}*/
/******************************************************************************/

/**
	@brief Timer1 overflow interrupt
*/
ISR(TIMER1_OVF_vect){
	// Your code here
	PORTB &= ~(1 << PB3);
	PORTB |= (1 << PB2);
}
/******************************************************************************/
/**
	@brief Timer1 Output compare
*/
ISR(TIMER1_COMPA_vect){
	//Your code here
	//int a= TCNT1;
	//PORTB &=~(1<<PB2);
	//PORTB &=~(1<<PB2);
	PORTB |= (1<<PB3);
	PORTB &= ~(1<<PB2);
	
}
/******************************************************************************/

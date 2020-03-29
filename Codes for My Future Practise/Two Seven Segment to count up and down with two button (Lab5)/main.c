 
/**
	@author Thomas Grunenberg
	@version 0.1
	@file one.c
	@brief Seven segment display
	if both buttons are pressed, counter will become 0
*/

#define F_CPU 8000000UL

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
/**
	@brief Init input and output
*/
void init(void){
	
	// Input
	DDRC &= (1 << DDC2);
	DDRC &= (1 << DDC3);
	PORTC |= (1 << PC2);
	PORTC |= (1 << PC3);

	// Output
	DDRD |= (1 << DDD7);//10,A
	DDRD |= (1 << DDD6);//9,B
	DDRD |= (1 << DDD5);//7,C
	DDRB |= (1 << DDB4);//5,
	DDRB |= (1 << DDB5);//4
	DDRC |= (1 << DDC0);//2
	DDRC |= (1 << DDC1);//1

	DDRD |= (1 << DDD4);//10,A
	DDRD |= (1 << DDD3);//9,B
	DDRD |= (1 << DDD2);//7,C
	DDRB |= (1 << DDB0);//5,
	DDRB |= (1 << DDB1);//4
	DDRB |= (1 << DDB2);//2
	DDRB |= (1 << DDB3);//1
	
	
	//DDRC |= (1<<DDC5);

}
/******************************************************************************/

void sevensegment1(uint8_t x){
	static uint8_t last = 100;
	
	// stop here if no change
	if (x == last)
		return;
	
	last = x;
	

	// Disable all LEDs
	PORTB &= ~(1 << PB4);//5,D
	PORTB &= ~(1 << PB5);//4,E
	PORTC &= ~(1 << PC0);//2,F
	PORTC &= ~(1 << PC1);//1,G
	PORTD &= ~(1 << PD5);//7,C	
	PORTD &= ~(1 << PD6);//9,B
	PORTD &= ~(1 << PD7);//10,A

	// Enable LEDs for value
	switch(x){
	
		case(1):
			PORTD &= ~(1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB &= ~(1 << PB4); // D
			PORTB &= ~(1 << PB5); // E
			PORTC &= ~(1 << PC0); // F
			PORTC &= ~(1 << PC1); // G
			
			break;
			
		case(2):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD &= ~(1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTB |= (1 << PB5); // E
			PORTC &= ~(1 << PC0); // F
			PORTC |= (1 << PC1); // G
			
		break;

		case(3):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTB &= ~(1 << PB5); // E
			PORTC &= ~(1 << PC0); // F
			PORTC |=  (1 << PC1); // G
			
		break;

		case(4):
			PORTD &= ~(1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB &= ~(1 << PB4); // D
			PORTB &= ~(1 << PB5); // E
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
			
		break;

		case(5):
			PORTD |= (1 << PD7); // A
			PORTD &= ~(1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTB &= ~(1 << PB5); // E
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
			
		break;

		case(6):
			PORTD |= (1 << PD7); // A
			PORTD &= ~(1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTB |= (1 << PB5); // E
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
			
		break;

		case(7):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB &= ~(1 << PB4); // D
			PORTB &= ~(1 << PB5); // E
			PORTC &= ~(1 << PC0); // F
			PORTC &= ~(1 << PC1); // G
			
		break;
			
		case(8):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB |= (1 << PB4); // D
			PORTB |= (1 << PB5); // E
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
			
		break;

		case(9):
			PORTD |= (1 << PD7); // A
			PORTD |= (1 << PD6); // B
			PORTD |= (1 << PD5); // C
			PORTB &= ~(1 << PB4); // D
			PORTB &= ~(1 << PB5); // E
			PORTC |= (1 << PC0); // F
			PORTC |= (1 << PC1); // G
			
		break;


		default:
			PORTD |= (1 << PD7); // A   pin 10
			PORTD |= (1 << PD6); // B   pin 9
			PORTD |= (1 << PD5); // C   pin 7
			PORTB |= (1 << PB4); // D   pin 5
			PORTB |= (1 << PB5); // E   pin 4 
			PORTC |= (1 << PC0); // F   pin 2
			PORTC &= ~(1 << PC1); // G    pin 1
			
		break;
	
			
			
	}


}
/******************************************************************************/

void sevensegment10(uint8_t y){
	static uint8_t last = 100;
	
	// stop here if no change
	if (y == last)
		return;
	
	last = y;
	

	// Disable all LEDs
	PORTD &= ~(1 << PD4);//5,D
	PORTD &= ~(1 << PD3);//4,E
	PORTD &= ~(1 << PD2);//2,F
	PORTB &= ~(1 << PB0);//1,G
	PORTB &= ~(1 << PB1);//7,C	
	PORTB &= ~(1 << PB2);//9,B
	PORTB &= ~(1 << PB3);//10,A

	// Enable LEDs for value
	switch(y){
	
		case(1):
			PORTD &= ~(1 << PD4); // A
			PORTD |= (1 << PD3); // B
			PORTD |= (1 << PD2); // C
			PORTB &= ~(1 << PB0); // D
			PORTB &= ~(1 << PB1); // E
			PORTB &= ~(1 << PB2); // F
			PORTB &= ~(1 << PB3); // G
			
			break;
			
		case(2):
			PORTD |= (1 << PD4); // A
			PORTD |= (1 << PD3); // B
			PORTD &= ~(1 << PD2); // C
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB1); // E
			PORTB &= ~(1 << PB2); // F
			PORTB |= (1 << PB3); // G
			
		break;

		case(3):
			PORTD |= (1 << PD4); // A
			PORTD |= (1 << PD3); // B
			PORTD |= (1 << PD2); // C
			PORTB |= (1 << PB0); // D
			PORTB &= ~(1 << PB1); // E
			PORTB &= ~(1 << PB2); // F
			PORTB |=  (1 << PB3); // G
			
		break;

		case(4):
			PORTD &= ~(1 << PD4); // A
			PORTD |= (1 << PD3); // B
			PORTD |= (1 << PD2); // C
			PORTB &= ~(1 << PB0); // D
			PORTB &= ~(1 << PB1); // E
			PORTB |= (1 << PB2); // F
			PORTB |= (1 << PB3); // G
			
		break;

		case(5):
			PORTD |= (1 << PD4); // A
			PORTD &= ~(1 << PD3); // B
			PORTD |= (1 << PD2); // C
			PORTB |= (1 << PB0); // D
			PORTB &= ~(1 << PB1); // E
			PORTB |= (1 << PB2); // F
			PORTB |= (1 << PB3); // G
			
		break;

		case(6):
			PORTD |= (1 << PD4); // A
			PORTD &= ~(1 << PD3); // B
			PORTD |= (1 << PD2); // C
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB1); // E
			PORTB |= (1 << PB2); // F
			PORTB |= (1 << PB3); // G
			
		break;

		case(7):
			PORTD |= (1 << PD4); // A
			PORTD |= (1 << PD3); // B
			PORTD |= (1 << PD2); // C
			PORTB &= ~(1 << PB0); // D
			PORTB &= ~(1 << PB1); // E
			PORTB &= ~(1 << PB2); // F
			PORTB &= ~(1 << PB3); // G
			
		break;
			
		case(8):
			PORTD |= (1 << PD4); // A
			PORTD |= (1 << PD3); // B
			PORTD |= (1 << PD2); // C
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB1); // E
			PORTB |= (1 << PB2); // F
			PORTB |= (1 << PB3); // G
			
		break;

		case(9):
			PORTD |= (1 << PD4); // A
			PORTD |= (1 << PD3); // B
			PORTD |= (1 << PD2); // C
			PORTB &= ~(1 << PB0); // D
			PORTB &= ~(1 << PB1); // E
			PORTB |= (1 << PB2); // F
			PORTB |= (1 << PB3); // G
			
		break;


		default:
			PORTD |= (1 << PD4); // A   pin 10
			PORTD |= (1 << PD3); // B   pin 9
			PORTD |= (1 << PD2); // C   pin 7
			PORTB |= (1 << PB0); // D   pin 5
			PORTB |= (1 << PB1); // E   pin 4 
			PORTB |= (1 << PB2); // F   pin 2
			PORTB &= ~(1 << PB3); // G    pin 1
			
		break;
	
			
			
	}


}
/******************************************************************************/

void sevensegment(uint8_t value){
	uint8_t x,y;

	x=value/10;
	y=value%10;
	sevensegment1(x);
	sevensegment10(y);}
/****************************************************************************/
	/*@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){
	uint8_t value = 0;
	
	
	init(); 	// Function to initialise I/Os
	
	// Loop forever
	while (1){
		sevensegment(value);
_delay_ms(20);
		
		//check if either button is pressed	
		if((~PINC & (1 << PC2))||(~PINC & (1<<PC3))){  
			//wait to see which is pressed	
			_delay_ms(20);

			//if both pressed
			if((~PINC & (1<<PC2))&&(~PINC &(1<<PC3))){
				value = 0;	
				//wait until button is released
				sevensegment(value);

				while((~PINC & (1<<PC2))||(~PINC &(1<<PC3)));
					_delay_ms(20);
			
			}
			
			//if PD2 is pressed
			else if(~PINC & (1<<PC2)){
				
				if(value>= 99){
					value = 0;
				
				}
				else{
					value++;
				}
				
				sevensegment(value);

				//wait until button is released
				while(~PINC & (1<<PC2)&&(!(~PINC &(1<<PC3))));
			}
			 else if(~PINC & (1<<PC3)){
			   
				if(value<= 0){
					value = 99;
				
				}
				else{
					value--;
				}
				 
				sevensegment(value);

				 //wait until button is released
				 while(~PINC & (1<<PC3)&&(!(~PINC &(1<<PC2))));
				 
			 }
		
		}

	}
	

	return 0;
}
/******************************************************************************/

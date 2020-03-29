/**
	@author J.C. Mariscal and Zhiwen He
    	MIT License
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
#include <stdio.h>
#include "init.h"
#include "lcd.h"

/******************************************************************************/

/******************************************************************************/
/* GLOBAL VARIABLES                                                           */
/******************************************************************************/
volatile uint8_t mil = 0;
volatile uint8_t sec = 0;
volatile char str[16];
volatile uint8_t min = 0;
volatile uint8_t hour = 0;
volatile uint8_t firstCount = 0;
volatile uint8_t Button1 = 0;
volatile uint8_t state = 0;
volatile uint8_t currentTime = 0;
volatile uint8_t splitHour = 0;
volatile uint8_t splitMin = 0;
volatile uint8_t splitSec = 0;
volatile uint8_t oldTime = 0;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
/*****************************************************************************/
// starts count to 1
void countOne()
{
    if (firstCount == 0)
    {
        TCNT1 = 65534; //In order to start counting immdietly after pressing
        firstCount = 1;
    }
}
/******************************************************************************/
/* Inputs: button 1 on PB5, button 2 on PC0 */

int main(void)
{
    // init pre-scaler
    TCCR1B |= (1 << CS12) | (1 << CS10); // 1024 pre-scaler

    TIMSK1 |= (1 << TOIE1);
    PCICR |= (1 << PCIE1);   //| (1<<PCIE0);
    PCMSK1 |= (1 << PCINT8); // PC0 selected as external interrupt pin
    sei();

    lcd_init(); // Function to initialise LCD display
    init();     // Function to initialise I/Os
    lcd_clear();
    Button1 = 0;
    lcd_clear();

    for (;;)
    {
        // start/stop button
        if (~PINB & (1 << PB5))
        {
            _delay_us(30);
            while (~PINB & (1 << PB5))
            {
            }

            Button1 = !Button1;
        }
        if (Button1)
        {
            countOne();
        }

        else if (Button1 == 0)
        {
            TCNT1 = 0;
            firstCount = 0;
        }
    }

    return 0;
}
/****************************************************************************/
                        /*Timer1 overflow interrupt*/
/****************************************************************************/
ISR(TIMER1_OVF_vect)
{
    if (mil < 99)
    {
        mil++;
    }
    else
    {
        mil = 0;

    if (sec < 59)
    {
        sec++;
    }
    else
    {
         sec = 0;
    if (min < 59)
    {
	 min++;
    }
    else
    {
    min = 0;
    hour++;
        }
    }}
    
    sprintf(str, "%02i:%02i:%02i:%02i", hour, min, sec, mil); // write to display
    lcd_setcursor(0,2);
    lcd_string(str);

    TCNT1 = 65469;//65469 is the very accurate time:(65535-(8000000/1024)/(100))

    //currentTime = hour * (3600) + min * 60 + sec; // current time secs
}
/********************************************************************************/
                   /*Pin change interrupt on pin pc0*/
/********************************************************************************/

ISR(PCINT1_vect)
{
    	
    sprintf(str, "%02i:%02i:%02i:%02i", hour, min, sec, mil); // write to display
    lcd_setcursor(0,1);
    lcd_string(str);
}


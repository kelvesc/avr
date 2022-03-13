#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>

/* Blink LED
 * This code blinks a led connected to PD7 (arduino digital pin 7)
 * in a Arduino Nano board with an ATMega328
 */
int main(void)
{
        /* SETUP HERE */
        DDRD |= 0B10000000;
        PORTD = 0B00000000;

        while(1){
                /* INFINITE LOOP HERE */
                PORTD ^= ~(0 << DDD7); /* toggle pin */
                _delay_ms(1000);
        } /* end loop */

} /* end main */

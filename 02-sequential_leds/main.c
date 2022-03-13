#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "../libs/bits.h"

/*
 * Blink LEDs PB0, PB1 and PB2 (D8, D9, and D10) sequentialy
 * BOARD: Arduino Nano with an ATMega328
 */
int main(void)
{
        /* setup here */
        DDRB |= 0B00000111;
        /* PB7 and PB6 should always be high for crystal */
        PORTB |= 0B11000000;

        const uint8_t CLEARMASK = 0B00000111;

        const uint16_t interval = 1000;

        while(1){
                CLEARBITMASK(PORTB, CLEARMASK);
                SETBITMASK(PORTB, _BV(DDB0));
                _delay_ms(interval);

                CLEARBITMASK(PORTB, CLEARMASK);
                SETBITMASK(PORTB, _BV(DDB1));
                _delay_ms(interval);

                CLEARBITMASK(PORTB, CLEARMASK);
                SETBITMASK(PORTB, _BV(DDB2));
                _delay_ms(interval);
        } /* end loop */

        return 0;

} /* end main */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "../include/bits.h"

#define CLEARMASK 0x00
#define INTERVAL 500

int main(void)
{
        /* setup here */
        setbit(DDRD, PD2);
        setbit(DDRD, PD3);
        setbit(DDRD, PD4);

        PORTD = 0x00;

        setbit(PORTD, DDD2);
        setbit(PORTD, DDD3);
        setbit(PORTD, DDD4);

        /* single loop here */
        while(1){

                toggle_bit(PORTD, DDD2);
                _delay_ms(INTERVAL);

                toggle_bit(PORTD, DDD3);
                _delay_ms(INTERVAL);

                toggle_bit(PORTD, DDD4);
                _delay_ms(INTERVAL);

                if(check_bit_mask(PORTD, 0x04)){
                        toggle_bit(PORTD, DDD4);
                        _delay_ms(INTERVAL/4);
                        toggle_bit(PORTD, DDD4);
                        _delay_ms(INTERVAL/4);
                        toggle_bit(PORTD, DDD4);
                        _delay_ms(INTERVAL/4);
                        toggle_bit(PORTD, DDD4);
                        _delay_ms(INTERVAL/4);
                }

        } /* end loop */

        return 0;

} /* end main */

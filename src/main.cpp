#include <Arduino.h>

#define bot1 ((PIND >> 4) & 0x01)
#define bot2 ((PIND >> 5) & 0x01)
#define bot3 ((PIND >> 6) & 0x01)
#define bot4 ((PIND >> 7) & 0x01)

#define prender(PORT, PIN) (PORT |= 1 << PIN)
#define apagar(PORT, PIN) (PORT &= 1 << PIN)

int main(void)
{
    DDRD &= ~(1 << PD4);
    DDRD &= ~(1 << PD5);
    DDRD &= ~(1 << PD6);
    DDRD &= ~(1 << PD7);

    DDRB |= (1 << PB0);
    DDRB |= (1 << PB1);
    DDRB |= (1 << PB2);
    DDRB |= (1 << PB3);

    while (1)
    {
        if (bot1 != 1)
        {
            prender(PORTB, 0);
        }
        else
        {
            apagar(PORTB, 0);
        }
        if (bot2 != 1)
        {

            prender(PORTB, 1);
        }
        else
        {
            apagar(PORTB, 1);
        }
        if (bot3 != 1)
        {
            prender(PORTB, 2);
        }
        else{
            apagar(PORTB, 2);
        }
        if (bot4 != 1)
        {
            prender(PORTB, 3); 
        }
        else{
            apagar(PORTB, 3);
        }

    }
}
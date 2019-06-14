#include <avr/io.h>
#include "ports.h"

void configurePortOutput(unsigned char port, unsigned char pin)
{
    switch(port)
    {
        case 'A':
            DDRA |= 1 << (pin & 0x7);
            break;
        case 'B':
            DDRB |= 1 << (pin & 0x7);
            break;
        case 'C':
            DDRC |= 1 << (pin & 0x7);
            break;
        case 'D':
            DDRD |= 1 << (pin & 0x7);
            break;
    }
}

void configurePortInput(unsigned char port, unsigned char pin, char pullUp)
{
    switch(port)
    {
        case 'A':
            DDRA &= ~(1 << (pin & 0x7));
            if(pullUp) PORTA |= 1 << (pin & 0x7);
            else PORTA &= ~(1 << (pin & 0x7));
            break;
        case 'B':
            DDRB &= ~(1 << (pin & 0x7));
            if(pullUp) PORTB |= 1 << (pin & 0x7);
            else PORTB &= ~(1 << (pin & 0x7));
            break;
        case 'C':
            DDRC &= ~(1 << (pin & 0x7));
            if(pullUp) PORTC |= 1 << (pin & 0x7);
            else PORTC &= ~(1 << (pin & 0x7));
            break;
        case 'D':
            DDRD &= ~(1 << (pin & 0x7));
            if(pullUp) PORTD |= 1 << (pin & 0x7);
            else PORTD &= ~(1 << (pin & 0x7));
            break;
    }
}

void setPortValue(unsigned char port, unsigned char pin, char value)
{
    if(value)
    {
        switch(port)
        {
            case 'A':
                PINA |= 1 << (pin & 0x7);
                break;
            case 'B':
                PINB |= 1 << (pin & 0x7);
                break;
            case 'C':
                PINC |= 1 << (pin & 0x7);
                break;
            case 'D':
                PIND |= 1 << (pin & 0x7);
                break;
        }
    }
    else
    {
        switch(port)
        {
            case 'A':
                PINA &= ~(1 << (pin & 0x7));
                break;
            case 'B':
                PINB &= ~(1 << (pin & 0x7));
                break;
            case 'C':
                PINC &= ~(1 << (pin & 0x7));
                break;
            case 'D':
                PIND &= ~(1 << (pin & 0x7));
                break;
        }
    }
    
}
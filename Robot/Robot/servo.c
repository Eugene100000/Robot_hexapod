#include <avr/io.h>
#include <avr/interrupt.h>
#include "ports.h"
#include "servo.h"


signed char createServo(signed char minAngle, signed char maxAngle, char port, char pin)
{
    if(servoNumber >= MAX_SERVO_NUMBER) return -1;
    else
    {
        configurePortOutput(port, pin);
        servos[servoNumber].minAngle = minAngle;
        servos[servoNumber].maxAngle = maxAngle;
        servos[servoNumber].currentAngle = (maxAngle + minAngle) / 2;
        servos[servoNumber].port = port;
        servos[servoNumber].pin = pin;

        servoNumber++;
    }
    return servoNumber - 1;
}

void setAngle(signed char servoId, signed char angle)
{
    if(servos[servoId].maxAngle < angle) servos[servoId].currentAngle = servos[servoId].maxAngle;
    else if(servos[servoId].minAngle > angle) servos[servoId].currentAngle = servos[servoId].minAngle;
    else
        servos[servoId].currentAngle = angle;
}

void startServos()
{
    if(servoNumber > 0)
    {
        if(servoNumber > 1)
            setPortValue(servos[nextServo].port, servos[nextServo].pin, 1);

        OCR2 = 100; // любое число от 1 до 255, желательно ближе к середине

        //Compare Match, Overflow Interrupt Enable
        TIMSK |= (1 << OCIE2) | (1 << TOV2);

        // prescaler 32
        //TCCR2 = 0x03; // normal mode
        TCCR2 = 0x4B; // fastPWM mode
    }
}

ISR(TIMER2_COMP_vect)
{
    setPortValue(servos[currentServo].port, servos[currentServo].pin, 0);
    
    OCR2 = (signed short)250 * (servos[nextServo].currentAngle - servos[nextServo].minAngle) /
                 (servos[nextServo].maxAngle - servos[nextServo].minAngle) + 1;
    
    currentServo = nextServo;
}

ISR(TIMER2_OVF_vect)
{
    nextServo++;
    if(nextServo >= MAX_SERVO_NUMBER)
        nextServo = 0;
    if(nextServo < servoNumber)
    {
        setPortValue(servos[nextServo].port, servos[nextServo].pin, 1);
    }   
}
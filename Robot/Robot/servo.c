#include <avr/io.h>
#include "servo.h"

signed char createServo(signed char minAngle, signed char maxAngle, char reverse, char port, char portBit)
{
    if(servoNumber >= MAX_SERVO_NUMBER) return -1;
    else
    {
        servos[servoNumber].minAngle = minAngle;
        servos[servoNumber].maxAngle = maxAngle;
        servos[servoNumber].reverse = reverse;
        servos[servoNumber].currentAngle = (maxAngle + minAngle) / 2;



        servoNumber++;
    }
    return servoNumber - 1;
}

void setAngle(signed char servoNumber, signed char angle)
{
    if(servos[servoNumber].maxAngle < angle) servos[servoNumber].currentAngle = servos[servoNumber].maxAngle;
    else if(servos[servoNumber].minAngle > angle) servos[servoNumber].currentAngle = servos[servoNumber].minAngle;
    else
        servos[servoNumber].currentAngle = angle;
}
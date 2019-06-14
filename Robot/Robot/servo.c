#include <avr/io.h>
#include "servo.h"

signed char createServo(signed short minAngle, signed short maxAngle, char reverse, char port, char portBit)
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
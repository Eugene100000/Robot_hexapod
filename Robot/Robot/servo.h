#ifndef SERVO_H_
#define SERVO_H_

#define MAX_SERVO_NUMBER 20

typedef struct
{
	signed short maxAngle;
	signed short minAngle;
	signed short currentAngle;
	char reverse;
} Servo;

static char servoNumber = 0;
Servo servos[MAX_SERVO_NUMBER];

signed char createServo(signed short minAngle, signed short maxAngle, char reverse, char port, char portBit);

#endif /* SERVO_H_ */
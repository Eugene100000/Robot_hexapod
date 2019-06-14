#ifndef SERVO_H_
#define SERVO_H_

#define MAX_SERVO_NUMBER 20

typedef struct
{
    signed char maxAngle;
    signed char minAngle;
    signed char currentAngle;
    char reverse;
} Servo;

static char servoNumber = 0;
Servo servos[MAX_SERVO_NUMBER];

signed char createServo(signed char minAngle, signed char maxAngle, char reverse, char port, char portBit);
void setAngle(signed char servoNumber, signed char angle);

#endif /* SERVO_H_ */
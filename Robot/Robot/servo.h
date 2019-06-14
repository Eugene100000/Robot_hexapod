#ifndef SERVO_H_
#define SERVO_H_

#define MAX_SERVO_NUMBER 20

typedef struct
{
    signed char maxAngle;
    signed char minAngle;
    signed char currentAngle;
    char port;
    char pin;

} Servo;

static short servoNumber = 0;
static short currentServo = 0;
static short nextServo = 1;


Servo servos[MAX_SERVO_NUMBER];

signed char createServo(signed char minAngle, signed char maxAngle, char port, char pin);
void setAngle(signed char servoId, signed char angle);

void startServos();

#endif /* SERVO_H_ */
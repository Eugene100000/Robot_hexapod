#ifndef PORTS_H_
#define PORTS_H_

#include <avr/io.h>

#define PORT_INPUT 0
#define PORT_OUTPUT 1

void configurePortOutput(unsigned char port, unsigned char pin);
void configurePortInput(unsigned char port, unsigned char pin, char pullUp);
void setPortValue(unsigned char port, unsigned char pin, char value);

#endif /* PORTS_H_ */
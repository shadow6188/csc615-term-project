#include <wiringPi.h>

#define TRIG 18      //GPIO 18
#define ECHO 24      //GPIO 24


void initECHO();
double distance();
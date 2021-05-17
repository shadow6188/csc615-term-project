//
// Created by gerardo on 5/17/21.
//

#ifndef CSC615_GROUP_TERM_PROJECT_PRAMODKHATRI10_ECHO_SENSORS_H
#define CSC615_GROUP_TERM_PROJECT_PRAMODKHATRI10_ECHO_SENSORS_H

#include <wiringPi.h>

#define TRIG 5 //assigning TRIG to GPIO 5
#define ECHO 6 //assigning Echo to GPIO  6

#define soundVelocity 34000

void init_echo_sensors();
double distance();

#endif //CSC615_GROUP_TERM_PROJECT_PRAMODKHATRI10_ECHO_SENSORS_H
#include "echo_sensor.h"

void init_echo_sensors(){
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
}


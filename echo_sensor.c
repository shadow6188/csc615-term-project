#include "echo_sensor.h"

void init_line_sensors(){
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
}


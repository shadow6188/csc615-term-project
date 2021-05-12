#include "echo_sensor.h"

void init_line_sensors(){
    pinMode(FRONT_ECHO_TRIGGER, OUTPUT);
    pinMode(FRONT_ECHO_SENSOR, INPUT);
}


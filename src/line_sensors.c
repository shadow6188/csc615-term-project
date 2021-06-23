/**************************************************************
* Class: CSC-615-01 Spring 2021
* Name: Team Autonomous
* Github ID: pramodkhatri10
* Project: final project
*
* File: line_sensors.c
*
* Description: functions having to do with line sensor
**************************************************************/

#include "line_sensors.h"

void init_line_sensors(){
    // initializing sensor pins to input mode
    pinMode(RSENSOR, INPUT);
    pinMode(LSENSOR, INPUT);
}
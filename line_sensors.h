/**************************************************************
* Class: CSC-615-01 Spring 2021
* Name: Team Autonomous
* Github ID: pramodkhatri10
* Project: final project
*
* File: line_sensors.c
*
* Description: headers for line sensor functions, and
* define gpio pin number for line sensors
**************************************************************/

#ifndef CSC615_GROUP_TERM_PROJECT_PRAMODKHATRI10_LINE_SENSORS_H
#define CSC615_GROUP_TERM_PROJECT_PRAMODKHATRI10_LINE_SENSORS_H
#include <wiringPi.h>

#define RSENSOR 17  //gpio pin for right line sensor
#define LSENSOR 27  //gpio pin for left line sensor

void init_line_sensors();
#endif //CSC615_GROUP_TERM_PROJECT_PRAMODKHATRI10_LINE_SENSORS_H

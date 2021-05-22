/**************************************************************
* Class: CSC-615-01 Spring 2021
* Name: Team Autonomous
* Github ID: pramodkhatri10
* Project: final project
*
* File: echo_sensor.h
*
* Description: contains headers for echo sensor functions and
* defines gpio pin numbers for the echo sensor trigger and return
* pins
**************************************************************/

#ifndef CSC615_GROUP_TERM_PROJECT_PRAMODKHATRI10_ECHO_SENSORS_H
#define CSC615_GROUP_TERM_PROJECT_PRAMODKHATRI10_ECHO_SENSORS_H
#include <wiringPi.h>

#include <wiringPi.h>

#define TRIG 5 //assigning TRIG to GPIO 5
#define ECHO 6 //assigning Echo to GPIO  6

#define soundVelocity 34000

void init_echo_sensors();
double distance();

#endif //CSC615_GROUP_TERM_PROJECT_PRAMODKHATRI10_ECHO_SENSORS_H

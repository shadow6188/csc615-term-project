/**************************************************************
* Class: CSC-615-01 Spring 2021
* Name: Team Autonomous
* Github ID: pramodkhatri10
* Project: final project
*
* File: line_sensors.c
*
* Description: 
**************************************************************/

#include "line_sensors.h"

void init_line_sensors(){
    pinMode(RSENSOR, INPUT);
    //pinMode(MSENSOR, INPUT);
    pinMode(LSENSOR, INPUT);
}
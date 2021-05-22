/**************************************************************
* Class: CSC-615-01 Spring 2021
* Name: Team Autonomous
* Github ID: pramodkhatri10
* Project: final project
*
* File: echo_sensor.c
*
* Description: contains functions which involve use of echo
*  sensor
**************************************************************/

#include "echo_sensor.h"

void init_echo_sensors() {
    //setting up wiringPi library
    //setting Trig as input/ Echo as output
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
}

double distance()
{
    //Outputing a high-level pulse in Trig pin lasting for least 10uS.
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    //Waiting for echo to start
    while (digitalRead(ECHO) == LOW)
        ;
    double startTime = micros();

    //Waiting for echo to stop
    while (digitalRead(ECHO) == HIGH)
        ;
    double stopTime = micros();

    ////Echo Time = stopTime - startTime
    double echoTime = stopTime - startTime;

    //Changing microseconds to seconds
    echoTime = echoTime / 1000000;

    //Distance = Echo time * sound velocity / 2
    double distance = (echoTime * soundVelocity) / 2;
    return distance;
}
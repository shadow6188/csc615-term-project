/**************************************************************
* Class: CSC-615-01 Spring 2020
* Name: Gerardo Ochoa
* Student ID: 918631875
* Github ID: shadow6188
* Project: Assignment 3 - Motors
*
* File: main.c
*
* Description: main function where button press logic and
* motor running are handled. Modified from main provided in
* waveshare example code
**************************************************************/
#include <stdio.h>      //printf()
#include <stdlib.h>     //exit()
#include <signal.h>
#include "DEV_Config.h"
#include "drivetrain.h"
#include "line_sensors.h"
#include "echo_sensor.h"

volatile int running = 0;
volatile int left = 0;
volatile int mid = 0;
volatile int right = 0;
volatile int echo = 0;
//volatile int trigger = 0;

void run_motor();
double distance();


PI_THREAD(line);
//PI_THREAD(sensor); // this refers to IR sensor 

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:Motor Stop\r\n");
    stop();
    DEV_ModuleExit();
    exit(0);
}


int main(void)
{
    //1.System Initialization
    if(DEV_ModuleInit())
        exit(0);
    
    //2.Motor Initialization
    initialize_motor();
    init_line_sensors();
    //init_echo_sensors();

    piThreadCreate (line);
   // piThreadCreate (sensor);
    // Exception handling:ctrl + c
    signal(SIGINT, Handler);


    // prints distance 
    // printf("Distance: %.2f cm\n", distance());
    // delay(1000);


    while (1){
        // printf("Distance: %.2f cm\n", distance());
        //     delay(1000);
        // if (distance < 100)
        // {
        //     setMotors(0);
        //     printf("echo sensor activated and motor stopped \n");
        // }
        if (left && right) 
            {
            setMotors(60);
            } 
         else if (!left && right)
            {
            turnRight(80);
            //softturnRight(80);
            } 
        else if (!right && left)
            {
            turnLeft(80);
            //softturnLeft(80);
            }  
        else{
            stop();
            }
    }

    //3.System Exit
    DEV_ModuleExit();
    return 0;
}

PI_THREAD(line){
        while (1){
            if (digitalRead(RSENSOR)) {
                right = 0;
                printf("sensor on RIGHT\n");
            } else 

            {
                right = 1;
            }

            if (digitalRead(LSENSOR))
            {
                left = 0;
                printf("sensor on LEFT\n");
            } else {
                left = 1;
            }

            
        }
}

// PI_THREAD(sensor)
// {
//     // while (1)
//     //     {
//     //     echo = distance();
//     //     }

// }

// double distance() {
//         //Outputing a high-level pulse in Trig pin lasting for least 10uS.
//         digitalWrite(TRIG, HIGH);
//         delayMicroseconds(10);
//         digitalWrite(TRIG, LOW);

//         //Waiting for echo to start
//         while(digitalRead(ECHO) == LOW);
//         double startTime = micros();

//         //Waiting for echo to stop
//         while(digitalRead(ECHO) == HIGH);
//         double stopTime = micros();

//         ////Echo Time = stopTime - startTime
//         double echoTime = stopTime - startTime;

//         //Changing microseconds to seconds
//         echoTime = echoTime / 1000000;

//         //Distance = Echo time * sound velocity / 2
//         double distance = ( echoTime * soundVelocity )/2;

//         return distance;
// }
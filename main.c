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
#include <wiringPi.h>
#include "DEV_Config.h"
#include "drivetrain.h"
#include "line_sensors.h"
#include "echo_sensor.h"

volatile int running = 0;
volatile int left = 0;
volatile int mid = 0;
volatile int right = 0;

void run_motor();

PI_THREAD(line);

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
    

    piThreadCreate (line);

    // Exception handling:ctrl + c
    signal(SIGINT, Handler);


    while (1){
        if (left && right) 
            {
            setMotors(30);
            } 
         else if (!left && right)
            {
            turnRight(25);
            //turnLeft(40);
            //softturnRight(80);
            } 
        else if (!right && left)
            {
            turnLeft(25);
            //turnRight(40);
            //softturnLeft(80);
            }  
        else{
            stop();
            }
    }

    while (1) {
        
    }

    //3.System Exit
    DEV_ModuleExit();
    return 0;
}

PI_THREAD(line){
        while (1){
            if (digitalRead(RSENSOR)) {
                right = 0;
                printf("sensor OFF RIGHT\n");
            } else 
            {
                right = 1;
            }
            if (digitalRead(LSENSOR))
            {
                left = 0;
                printf("sensor OFF LEFT\n");
            } else {
                left = 1;
            }
        }
}
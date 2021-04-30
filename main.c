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

volatile int running = 0;
void run_motor();

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

    // Exception handling:ctrl + c
    signal(SIGINT, Handler);

    run_motor();

    stop();

    //3.System Exit
    DEV_ModuleExit();
    return 0;
}
void run_motor(){
    printf("Motor_Run\r\n");
    setMotors(100);
    delay(1000); // 2 second delay
    setRightMotors(100);
    setLeftMotors(-100);
    delay(1000);
    setMotors(-100);
    delay(1000);
}

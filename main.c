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
        forward(100);
        delay(2000); // 2 second delay
        for (int i = 100;i > 15;i -= 5){// slow down 5% at a time until at 15%
            forward(i);
            delay(100);
        }
        stop();
        delay(1000);
        for (int i = 0; i <= 100 ; i += 5) {
            reverse(i);
            delay(100);
        }
        running = 0;
}

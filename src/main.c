/**************************************************************
* Class: CSC-615-01 Spring 2021
* Name: Team Autonomous
* Github ID: pramodkhatri10
* Project: final project
*
* File: main.c
*
* Description: main function where the motor run, lane sensor,
* and echo sensors run
**************************************************************/
#include <stdio.h>      //printf()
#include <stdlib.h>     //exit()
#include <signal.h>
#include <wiringPi.h>
#include "echo_sensor.h"
#include "DEV_Config.h"
#include "drivetrain.h"
#include "line_sensors.h"

volatile int running = 0;
volatile int left = 0;
volatile int mid = 0;
volatile int right = 0;
volatile double obstacle_distance = 0;

void run_motor();

//declares thread functions for lane and echo sensor
PI_THREAD(line);
PI_THREAD(echo);

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:Motor Stop\r\n");
    stop();
    DEV_ModuleExit();
    exit(0);
}

//gives direction and speed control once obsatcle is detected
void obstacle_avoidance () {
        turnRight(70); //speed at 70
        delay(3000); //3 sec
        setMotors(40); //speed at 40
        delay(3000); //3 sec
        turnLeft(70); //speed at 70
        delay(6000); //6 sec
    }
}


int main(void)
{
    //1.System Initialization
    if(DEV_ModuleInit())
        exit(0);
    
    //2.Motor Initialization
    initialize_motor();
    init_line_sensors();
    init_echo_sensors();
    

    piThreadCreate (line);
    piThreadCreate(echo);

    // Exception handling:ctrl + c
    signal(SIGINT, Handler);

    // main loop
    // if obstacle detected stop
    // else if left & right are on then go forward
    // if only right is on then turn left
    // if only left is on then turn right
    // if both are off the stop
    while (1){

        if (obstacle_distance < 15){
            printf("obstacle detected \n");
            stop();
            obstacle_avoidance();
        } else {
            if (left && right) {
                setMotors(30);
            } else if (!left && right) {
                turnLeft(31);
            } else if (!right && left) {
                turnRight(31);
            } else {
                stop();
            }
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
            // read right sensor ond set right depending on the value
            if (digitalRead(RSENSOR)) {
                right = 0;
            } else{
                right = 1;
            }
            // read left sensor ond set left depending on the value
            if (digitalRead(LSENSOR)){
                left = 0;
            } else {
                left = 1;
            }
        }
}

PI_THREAD(echo) {

     printf("Activating Echo  Sensor.....\n");

        //while TRUE
        while (1)
        {
                // reads distance value from echo sensor & sets global variable obstacle_distance
                obstacle_distance = distance();
                //printf("Distance: %.2f cm\n", obstacle_distance);
                delay(1000);
        }
        return 0;
}
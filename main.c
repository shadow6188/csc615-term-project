* Description: main function where the motor run, lane sensor, echo sensors are run
**************************************************************/
#include <stdio.h>      //printf()
#include <stdlib.h>     //exit()
#include <signal.h>
#include <wiringPi.h>
#include "DEV_Config.h"
#include "drivetrain.h"
#include "line_sensors.h"

volatile int running = 0;
volatile int left = 0;
volatile int mid = 0;
volatile int right = 0;
volatile double obstacle_distance = 0;

#define TRUE (1 == 1)
#define soundVelocity 34000

#define TRIG 5 //assigning TRIG to GPIO 5
#define ECHO 6 //assigning Echo to GPIO  6

void run_motor();

PI_THREAD(line);
PI_THREAD(sensor);

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:Motor Stop\r\n");
    stop();
    DEV_ModuleExit();
    exit(0);
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


int main(void)
{
    //1.System Initialization
    if(DEV_ModuleInit())
        exit(0);
    
    //2.Motor Initialization
    initialize_motor();
    init_line_sensors();
    

    piThreadCreate (line);
    piThreadCreate(sensor);

    // Exception handling:ctrl + c
    signal(SIGINT, Handler);


    while (1){
    //    if (obstacle_distance <= 12) {
    //        printf("obstacle detected \n");
    //    }
        if (left && right) 
            {
            setMotors(30);
            } 
         else if (!left && right)
            {
            turnLeft(25);
            //turnLeft(40);
            //softturnRight(80);
            } 
        else if (!right && left)
            {
            turnRight(25);
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
                //printf("sensor OFF RIGHT\n");
            } else 
            {
                right = 1;
            }
            if (digitalRead(LSENSOR))
            {
                left = 0;
               // printf("sensor OFF LEFT\n");
            } else {
                left = 1;
            }
        }
}

PI_THREAD(sensor) {
     printf("Activating Echo  Sensor.....\n");

        //Setting up to start
        wiringPiSetup();

        //while TRUE
        while (1 == 1)
        {
                //prints distance
                printf("Distance: %.2f cm\n", distance());
                delay(1000);
        }
        return 0;
}
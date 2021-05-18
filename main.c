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


    while (1){

        while (obstacle_distance < 30){
            printf("obstacle detected \n");
            turnRight(40);
            setMotors(20);
            if (left && right)
            {
                 turnLeft(30);
                 //sleep(2);

                 turnRight(40);
                 setMotors(20);
                
            }
            //this tries to go back to the lane 
            
        } 
    
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

    //3.System Exit
    DEV_ModuleExit();
    return 0;
}

PI_THREAD(line){
        while (1){
            if (digitalRead(RSENSOR)) {
                right = 0;
            } else{
                right = 1;
            }
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
                //prints distance
                obstacle_distance = distance();
                printf("Distance: %.2f cm\n", obstacle_distance);
                delay(1000);
        }
        return 0;
}
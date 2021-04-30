/**************************************************************
* Class: CSC-615-01 Spring 2020
* Name: Gerardo Ochoa
* Student ID: 918631875
* Github ID: shadow6188
* Project: Assignment 3 - Motors
*
* File: customDriver.c
*
* Description:File with functions to direct motor connected to
* Waveshare HAT
**************************************************************/
#include "drivetrain.h"

uint8_t check_speed(uint8_t speed);

void initialize_motor(){// initialize ic2
    PCA9685_Init(0x40);
    PCA9685_SetPWMFreq(100);
}

void forward(uint8_t speed){ // move
    speed = check_speed(speed);
    PCA9685_SetLevel(AIN1,1); // power sent out through (AN1)
    PCA9685_SetLevel(AIN2,0); // set AIN2 to GND
    PCA9685_SetLevel(BIN1,1); // power sent out through (AN1)
    PCA9685_SetLevel(BIN2,0); // set AIN2 to GND
    PCA9685_SetPwmDutyCycle(PWMB, speed);
    PCA9685_SetPwmDutyCycle(PWMA, speed);
}
void reverse(uint8_t speed){
    speed =check_speed(speed);
    PCA9685_SetLevel(AIN1,1); // set AIN1 to GND
    PCA9685_SetLevel(AIN2,0); // power sent out through
    PCA9685_SetLevel(BIN1,1);
    PCA9685_SetLevel(BIN2,0);
    PCA9685_SetPwmDutyCycle(PWMB, speed);
    PCA9685_SetPwmDutyCycle(PWMA, speed);
}
void stop(){
    PCA9685_SetPwmDutyCycle(PWMA, 0);
    PCA9685_SetPwmDutyCycle(PWMB,0);
}
uint8_t check_speed(uint8_t speed){
    if (speed > 100)
        return 100;
    else
        return speed;
}

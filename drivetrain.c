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

int check_speed(int speed);

void initialize_motor(){// initialize ic2
    PCA9685_Init(0x40);
    PCA9685_SetPWMFreq(100);
}

void setRightMotors(int speed){
    speed = check_speed(speed);

    if (speed > 0){
        PCA9685_SetLevel(AIN1,0);
        PCA9685_SetLevel(AIN2,1);
        PCA9685_SetPwmDutyCycle(PWMA,speed);
    } else {
        PCA9685_SetLevel(AIN1, 1);
        PCA9685_SetLevel(AIN2, 0);
        PCA9685_SetPwmDutyCycle(PWMA,-speed);
    }
}
void setLeftMotors(int speed){
    speed = check_speed(speed);

    if (speed > 0){
        PCA9685_SetLevel(BIN1,1);
        PCA9685_SetLevel(BIN2,0);
        PCA9685_SetPwmDutyCycle(PWMB,speed);
    } else {
        PCA9685_SetLevel(BIN1, 0);
        PCA9685_SetLevel(BIN2, 1);
        PCA9685_SetPwmDutyCycle(PWMB,-speed);
    }
}

void setMotors(int speed){
    setRightMotors(speed);
    setLeftMotors(speed);
}
void softturnLeft(int speed){
    setLeftMotors(speed - 15);
    setRightMotors(speed);
}
void softturnRight(int speed){
    setLeftMotors(speed);
    setRightMotors(speed - 15);
}
void hardturnLeft(int speed){
    setLeftMotors(speed - 30);
    setRightMotors(speed);
}
void hardturnRight(int speed){
    setLeftMotors(speed);
    setRightMotors(speed - 30);
}
void turnLeft(int speed){
    setLeftMotors(0);
    setRightMotors(speed);
}
void turnRight(int speed){
    setLeftMotors(speed);
    setRightMotors(0);
}
void stop(){
    PCA9685_SetPwmDutyCycle(PWMA, 0);
    PCA9685_SetPwmDutyCycle(PWMB,0);
}
int check_speed(int speed){
    if (speed > 100)
        return 100;
    else if (speed < -100)
        return -100;
    else
        return speed;
}

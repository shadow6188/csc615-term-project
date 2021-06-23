/**************************************************************
* Class: CSC-615-01 Spring 2021
* Name: Team Autonomous
* Github ID: pramodkhatri10
* Project: final project
*
* File: drivetrain.c
*
* Description: contains functions which involves the use of motors and their speed control
**************************************************************/
#include "drivetrain.h"

int check_speed(int speed);

void initialize_motor(){// initialize ic2
    PCA9685_Init(0x40);
    PCA9685_SetPWMFreq(100);
}

void setRightMotors(int speed){
    // sets right side motors to speed
    // if speed is negative switches direction of motor
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
    // sets left side motors to speed
    // if speed is negative switches direction of motor
    speed = check_speed(speed);

    if (speed > 0){
        PCA9685_SetLevel(BIN1,0);
        PCA9685_SetLevel(BIN2,1);
        PCA9685_SetPwmDutyCycle(PWMB,speed);
    } else {
        PCA9685_SetLevel(BIN1, 1);
        PCA9685_SetLevel(BIN2, 0);
        PCA9685_SetPwmDutyCycle(PWMB,-speed);
    }
}

void setMotors(int speed){
    //passes speed to left & right motors
    setRightMotors(speed);
    setLeftMotors(speed);
}

void turnLeft(int speed){
    // sets left motor to zero so that car will turn to left
    setLeftMotors(0);
    setRightMotors(speed);
}
void turnRight(int speed){
    // sets right motor to zero so that car will turn to left
    setLeftMotors(speed);
    setRightMotors(0);
}
void stop(){
    // sets both motors pwm value to zero, stopping the car
    PCA9685_SetPwmDutyCycle(PWMA, 0);
    PCA9685_SetPwmDutyCycle(PWMB,0);
}
int check_speed(int speed){
    // checks value if speed is within 100 & -100
    if (speed > 100)
        return 100;
    else if (speed < -100)
        return -100;
    else
        return speed;
}

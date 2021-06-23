/**************************************************************
* Class: CSC-615-01 Spring 2021
* Name: Team Autonomous
* Github ID: pramodkhatri10
* Project: final project
*
* File: drivetrain.h
*
* Description: defines functions for motors and their speed control and contains header files needed for motors
**************************************************************/

#include "PCA9685.h"

// Right side motors
#define PWMA        PCA_CHANNEL_0
#define AIN1        PCA_CHANNEL_1
#define AIN2        PCA_CHANNEL_2
// Left side motors
#define PWMB        PCA_CHANNEL_5
#define BIN1        PCA_CHANNEL_4
#define BIN2        PCA_CHANNEL_3

#define MOTOR       0


void initialize_motor();
void setMotors(int speed);
void setRightMotors(int speed);
void setLeftMotors(int speed);
void turnLeft(int speed);
void turnRight(int speed);
void stop();

/**************************************************************
* Class: CSC-615-01 Spring 2020
* Name: Gerardo Ochoa
* Student ID: 918631875
* Github ID: shadow6188
* Project: Assignment 3 - Motors
*
* File: customDriver.h
*
* Description: header for motor driver
**************************************************************/

#include "PCA9685.h"

// Right side motors
#define PWMA        PCA_CHANNEL_0
#define AIN1        PCA_CHANNEL_1
#define AIN2        PCA_CHANNEL_2
// Left side motors
#define PWMB        PCA_CHANNEL_5
#define BIN1        PCA_CHANNEL_3
#define BIN2        PCA_CHANNEL_4

#define MOTOR       0

void initialize_motor();
void forward(uint8_t speed);
void reverse(uint8_t speed);
void stop();

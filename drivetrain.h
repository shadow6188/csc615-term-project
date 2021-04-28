//
// Created by gerardo on 4/28/21.
//

#ifndef CSC615_GROUP_TERM_PROJECT_PRAMODKHATRI10_DRIVETRAIN_H
#define CSC615_GROUP_TERM_PROJECT_PRAMODKHATRI10_DRIVETRAIN_H
#include <wiringPi.h>


//Motor 1 pins
#define M1PMW 11
#define M1F 15
#define M1R 13
//Motor 2 pins
#define M2PMW 22
#define M2F 16
#define M2R 18
//Motor 3 pins
#define M3PMW 19
#define M3F 21
#define M3R 23
//Motor 4 pins
#define M4PMW 32
#define M4F 24
#define M4R 26

void initMotors();
void motorsForward();
#endif //CSC615_GROUP_TERM_PROJECT_PRAMODKHATRI10_DRIVETRAIN_H

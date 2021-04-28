//
// Created by gerardo on 4/28/21.
//
#include <wiringPi.h>
#include "drivetrain.h"

void init();

int main(){
    init();
    motorsForward();
    return 0;
}

void init(){
    wiringPiSetupGpio();
    initMotors();
}
//
// Created by gerardo on 4/28/21.
//

#include "drivetrain.h"

void initMotors(){
    //sett up all pmw pins
    softPwmCreate(M1PMW, 0, 100);
    softPwmCreate(M2PMW, 0, 100);
    softPwmCreate(M3PMW, 0, 100);
    softPwmCreate(M4PMW, 0, 100);

    pinMode(M1F,OUTPUT);
    pinMode(M2F,OUTPUT);
    pinMode(M3F,OUTPUT);
    pinMode(M4F,OUTPUT);

    pinMode(M1R,OUTPUT);
    pinMode(M2R,OUTPUT);
    pinMode(M3R,OUTPUT);
    pinMode(M4R,OUTPUT);
}
void motorsForward(){
    softPwmWrite(M1PMW,100);
    softPwmWrite(M2PMW,100);
    softPwmWrite(M3PMW,100);
    softPwmWrite(M4PMW,100);
    pinMode(M1F,HIGH);
    pinMode(M2F,HIGH);
    pinMode(M3F,HIGH);
    pinMode(M4F,HIGH);
    pinMode(M1R,LOW);
    pinMode(M2R,LOW);
    pinMode(M3R,LOW);
    pinMode(M4R,LOW);

}
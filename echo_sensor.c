
#include "echo_sensor.h"

void initECHO(){
         pinMode(TRIG, OUTPUT); 	   // sets the TRIG as output
         pinMode(ECHO, INPUT);      // sets the ECHO as input 
}

double distance() {
        // reads a high-level pulse in Trig pin which lasts for least 10uS.
        digitalWrite(TRIG, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIG, LOW);

	//Waits for echo to start
        while(digitalRead(ECHO) == LOW);
        double startTime = micros();


        //Waits for echo to stop
        while(digitalRead(ECHO) == HIGH);
        double stopTime = micros();

        //Echo Time = stopTime - startTime
        double echoTime = stopTime - startTime;

	//Convets microseconds to seconds
        echoTime = echoTime / 1000000;

	//Distance = Echo time * sound velocity / 2
        double distance = ( echoTime * Velocity )/2;

        return distance;
}

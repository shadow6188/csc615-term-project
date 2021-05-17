all: Project

Project: main.c
	gcc -o project main.c echo_sensors.c line_sensors.c drivetrain.c DEV_Config.c PCA9685.c -lm -lwiringPi
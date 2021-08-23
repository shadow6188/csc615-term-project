# Raspberry Pi Autonomous Car

Welcome to Raspberry Pi Autonomous Car our term project for CSC 615 UNIX Programming class.

Our Task was to create a robot car with the capability to autonomously follow a track and maneuver around any obstacles on that track.

The concept behind the car was to have two line sensors, one on each side of the car to detect track and an echo sensor to detect any obstacles on the tracks.

![Overhead-view-car](img/car_overhead.jpg)
## Robot build
_______________________________________
### parts
|1. 2x TCRT5000 IR sensors | 2. 1x Ultrasonic Module HC-SR04|3. 2x motors|4. 2x wheels|5. 1x swivel caster wheel|
|---------------|-----------|-------------|-------------------|------|
|<img alt="lane sensors" height="150" src="img/IR_sensor.jpg" width="100"/>|<img alt="echo sensor" height="150" src="img/echo_sensor.jpg" width="100"/>|<img alt="motor" height="150" src="img/motor.jpg" width="100"/>|<img alt="wheel" height="100" src="img/wheel.jpg" width="100"/>|<img alt="swivel wheel" height="120" src="img/swivel_caster_wheel.png" width="100"/>|

|6. 2x chassis frame|7. 1x power bank|8. 3x 9800mAh Battery Rechargeable|9. 1x Motor Driver Hat
|-------|---------|---------|-----------|
<img alt="frame" height="200" src="img/frame.png" width="100"/>|<img alt="power bank" height="150" src="img/powerbank.png" width="100"/>|<img alt="batteries" height="150" src="img/batteries.png" width="100"/>|<img alt="motorshield" height="120" src="img/motorshield.png" width="150"/>|

_____________________________________
### Hardware Diagrams

![sensors-diagram](img/Hardware_diagram.png)
![motors-diagram](img/Motorshield_diagram.png)
______________________________________

### GPIO pin assignments for sensors
1. HC-SR04 Sensor

|VCC|Trig|Echo|Gnd|
|----|----|----|----|
|5V power|GPIO 5 |GPIO 6 |Ground|
|physical pin 1|physical pin 29|physical pin 31|physical pin 39| 
2. Right TCRT500 Sensor

|VCC|GND|D0 |A0 |
|---|---|---|---|
|3V3 power|Ground|GPIO 27| |
|physical pin 17|physical pin 14|physical pin 13|not used

3.Left TCRT500 Sensor

|VCC|GND|D0|A0|
|---|---|---|---|
|3V3 power|Ground|GPIO 17| |
|physical pin 1|physical pin 9|physical pin 11|not used|

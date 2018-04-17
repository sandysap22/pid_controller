# PID Controller
## Author: Sandeep Patil

#### Objective of this project is to derive steering values by using PID Controller.   

In this project we will fine tune PID parameters to get steering values for track 1 of simulator based on cross track error (CTE) provided by simulator. 

### PID details
We would find tune three parameters P, I and D. P stands for Proportion. I stands for factor for integrated error. D stands for derivative of change in error.  
The steering value is calculated as:   
steering_value = - P  x *CTE* - I x sum of all errors - D x change in error from last step / time elapsed.
 
Following is significance of three parameters.
* P : It is the proportion parameter by which we want to reduce instantaneous error. The high P value results in overshooting and high oscillation.
* I : It helps to overcome problem of constant error due to bias in steering or there are curvature on roads. This works on accumulated error over time. High value of I can lead to more oscillation. Proper value of I would help to reduce residual errors.
* D : The correction due to P always lead to oscillation in positive and negative region of error. We can use derivative or change rate in error to dampen the oscillation and D parameter is used to fine tune it. High value of D results in high fluctuations.

### How do I arrived at final parameter values.
I have used manual fine tuning approach. 
1. I started with P=0.5 and I=D=0 and it resulted in high oscillation.
2. Then I reduce it to P=0.3 though there was still small oscillations but car was leaving track on curvature. 
3. Then I use D=5.0 which helped me to keep car on track however it resulted in high steering movements. 
4. The high speed over 30 was causing issue of high instability at curvature. so I introduced PID for throttle and I followed P and I values from project 3. The error in this case is difference between desired speed and actual speed.   
    P for speed = 0.075 and I for speed = 0.001 and D=0
5. Above step helped me to keep constant velocity of 25 mph.
6. Then I gradually reduced both P for steering to 0.2 and D to 2.0. 
7. Still there was high oscillation at curvatures, so I introduced I=0.0001.
8. After some fine tuning finally following values worked and it provides smooth ride. P=0.21, I=0.0002 and D=1.5


--- 
### Installations and build 

This project involves the Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases) .

This repository includes two files that can be used to set up and install [uWebSocketIO](https://github.com/uWebSockets/uWebSockets) for either Linux or Mac systems. 

For Linux  
`./install-ubuntu.sh`

For Mac  
`./install-mac.sh`


Once the install for uWebSocketIO is complete, the main program can be built and run by doing the following from the project top directory.

### Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`

---

### Communication between main.cpp (server) and simulator
Here is the main protocol that main.cpp uses for uWebSocketIO in communicating with the simulator.

INPUT: values provided by the simulator to the c++ program

["sensor_measurement"] => cross track error (CTE) that is how much car is away from center of road. 

OUTPUT: values provided by the c++ program to the simulator   

["steering_angle"] <= Steering value in radian.  
["throttle"] <= accelration value



---

### Other Important Dependencies

* cmake >= 3.5
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)



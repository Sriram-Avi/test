#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_


//located in tuner.cpp creates a PID tuner and runs the PID tuner: prints to controller screen
void tuneMe();

#include "main.h"
//I'm lazy and made a method to initialize motors
void initMotor(pros::Motor m,int amps);

void magneticSlewControl(void *width);
#endif

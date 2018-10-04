#include "main.h"
using namespace okapi;
void tuneMe(){
  //create motor instances
  okapi::Motor bl (MOTOR_BL);
  okapi::Motor fl (MOTOR_FL);
  okapi::Motor br (MOTOR_BR);
  okapi::Motor fr (MOTOR_FR);
  pros::Controller master(pros::E_CONTROLLER_MASTER);

  //these are basically arraylist<> first ins is inputs(motor encoders) second outs is of outputs(motors)
 std::shared_ptr<ControllerInput<double>> lIns(new IntegratedEncoder(bl));
 std::shared_ptr<ControllerOutput<double>> lOuts(new MotorGroup({1,2}));

 //create an instance of PID tuner for left side of drive
 auto leftTune = PIDTunerFactory::create(
   lIns,lOuts,
   minute,1000,
   0.05,3.00,
   0.00,1.50,
   0.00,1.00,
   5,16,1,2


 );

 //these are basically arraylist<> first ins is inputs(motor encoders) second outs is of outputs(motors)
std::shared_ptr<ControllerInput<double>> rIns(new IntegratedEncoder(br));
std::shared_ptr<ControllerOutput<double>> rOuts(new MotorGroup({3,4}));

//create an instance of PID tuner for right side
auto rightTune = PIDTunerFactory::create(
  rIns,rOuts,
  minute,1000,
  0.05,3.00,
  0.00,1.50,
  0.00,1.00,
  5,16,1,2


);

//create an output class and label it yay to store PID tuner output
 PIDTuner::Output rConstants;
 PIDTuner::Output lConstants;
//run PID tuner and set yay to its output
rConstants = rightTune.autotune();
lConstants = leftTune.autotune();


//print the outputs
const char * kP = std::to_string(rConstants.kP).c_str();
const char * kD = std::to_string(rConstants.kD).c_str();
const char * kI = std::to_string(rConstants.kI).c_str();

master.set_text(0,0,kP);
master.set_text(1,0,kI);
master.set_text(2,0,kD);
}

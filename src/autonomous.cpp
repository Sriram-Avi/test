#include "main.h"


using namespace okapi;


void autonomous() {


  pros::Controller master(pros::E_CONTROLLER_MASTER);

  //create motor instances
  okapi::Motor bl (MOTOR_BL);
  okapi::Motor fl (MOTOR_FL);
  okapi::Motor br (MOTOR_BR);
  okapi::Motor fr (MOTOR_FR);


//tuneMe();
//after performing the above code once there isn't a need to do it again. Just save the printed values somewhere

//*************************You Are big ghey and you sugg pendis Xd gottem***********************************************//

//create a chassis controller with three PIDs
auto testChassis = ChassisControllerFactory::create(
  //start with left two motors then right two motors
  {bl, fl}, {br, fr},
  //first is distance PID, then angle PID, then turn PID
  //tune values of second two manually for now but use results of PIDtuner for first one
  IterativePosPIDController::Gains{0.5, 0, 0},
  IterativePosPIDController::Gains{0.1, 0.05, 0},
  IterativePosPIDController::Gains{0.2, 0, 0},
  //gearset then width of wheel then width of base from center of one  back  wheel to center of the other back wheel
  AbstractMotor::gearset::green,
  {4_in, 15.5_in}
);

//create a motion profiler controller put in maximum velocity, then maximum acceleration, then maximum jerk
auto mProfile = AsyncControllerFactory::motionProfile(1.0, 2.0, 10.0, testChassis);

//now we create a sample path and execute that path
//mProfile.generatePath({Point{0_ft,0_ft,0_deg}, Point{3_ft,2_ft,20_deg},Point{4_ft,5_ft,130_deg}}, "samplePath");

mProfile.setTarget("samplePath");

//if you want you can do a wait here and have a seperate controller running the motor powers of other mechanisms
mProfile.waitUntilSettled();

//****************************You are even bigger gay now you have turbo-ultra-aids************************************//



}

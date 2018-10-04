#include "main.h"


using namespace okapi;
void magneticSlewControl(void * width){
  pros::Controller master (pros::E_CONTROLLER_MASTER);
  Motor liftMotor (LIFT_MOTOR);
  auto liftSlew = AsyncControllerFactory::posIntegrated(LIFT_MOTOR);
  int setGoalHeight;
  int trueGoalHeight;


  while(true){
    //based on button press the lift target changes
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)&&liftMotor.getPosition()<300){
      trueGoalHeight+=1;
    }
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)&&liftMotor.getPosition()>0){
      trueGoalHeight-=1;
    }

    //if near one of the pole's predetermined height set the goal height to that height
    if(trueGoalHeight<=(HI_POLE+(int)width)){
      setGoalHeight = HI_POLE;
    }
    else if(trueGoalHeight>=(HI_POLE-(int)width)){
      setGoalHeight = HI_POLE;
    }

    if(trueGoalHeight<=(LOW_POLE+(int)width)){
      setGoalHeight = LOW_POLE;
    }
    else if(trueGoalHeight>=(LOW_POLE-(int)width)){
      setGoalHeight = LOW_POLE;
    }


    pros::delay(10);
    liftSlew.setTarget(setGoalHeight);
  }
}

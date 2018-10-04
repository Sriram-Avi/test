#include "main.h"

using namespace pros::literals;


 using namespace okapi;
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	auto jimbo = ChassisControllerFactory::create(
  {MOTOR_FL, MOTOR_BL}, {MOTOR_FR, MOTOR_BR},
  AbstractMotor::gearset::green,
  {4_in, 15.5_in}
	);



	while (true) {
		jimbo.arcade(master.get_analog(ANALOG_LEFT_Y),master.get_analog(ANALOG_RIGHT_X));
		pros::delay(20);
	}
}

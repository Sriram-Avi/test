#include "main.h"

using namespace pros;

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
	pros::lcd::register_btn1_cb(on_center_button);

	//if a motor is burning out change the second value to decrease amperage limit, if not enough torque increase limit
	Motor br_pros (MOTOR_BR);
	initMotor(br_pros,1500);
	Motor bl_pros(MOTOR_BL);
	initMotor(bl_pros, 1500);
	Motor fr_pros(MOTOR_FR);
	initMotor(fr_pros,1500);
	Motor fl_pros(MOTOR_FL);
	initMotor(fl_pros,1500);

}


void disabled() {}


void competition_initialize() {}

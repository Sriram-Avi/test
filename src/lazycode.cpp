#include "main.h"

using namespace pros;

//set brake mode to brake and set amperage limit
void initMotor(Motor m,int amps){
  m.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	m.set_current_limit(amps);
}

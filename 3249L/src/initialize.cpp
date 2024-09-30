#include "main.h"
#include "pros/adi.hpp"
#include "pros/motors.hpp"

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

	log_init();
	LOG_ALWAYS("In Initialize");
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);/*
	pros::Motor FLXMotor_initializer (1,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);
	pros::Motor FRXMotor_initializer (2,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);
	pros::Motor BLXMotor_initializer (3,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);//idk why VScode isnt happy
	pros::Motor BRXMotor_initializer (4,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);
  
	pros::Motor LeftMotor_initializer(5,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);//odom
	pros::Motor RightMotor_initializer(6,pros::E_MOTOR_GEARSET_18,true,pros::E_MOTOR_ENCODER_DEGREES);

*/
pros::Motor motor (1, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
	pros::adi::Encoder Xaxis ('B','C',false);
	pros::Motor FLXMotor (1);
	pros::Motor FRXMotor (2);
	pros::Motor BLXMotor (3);
	pros::Motor BRXMotor (4);

	pros::Motor LeftMotor(5);//odom
	pros::Motor RightMotor(6);

    void lv_init();

}
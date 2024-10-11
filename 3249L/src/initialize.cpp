#include "main.h"
#include "pros/adi.hpp"
#include "pros/motors.hpp"


void initialize() {

	pros::Task Odom(Odometry);
	pros::Task ScreenInfo(ShowScreen);

	log_init();
	LOG_ALWAYS("In Initialize");
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	
	pros::Motor FLXMotor_initializer (1,pros::v5::MotorGears::green,pros::v5::MotorUnits::degrees);
	pros::Motor FRXMotor_initializer (2,pros::v5::MotorGears::green,pros::v5::MotorUnits::degrees);
	pros::Motor BLXMotor_initializer (3,pros::v5::MotorGears::green,pros::v5::MotorUnits::degrees);//idk why VScode isnt happy
	pros::Motor BRXMotor_initializer (4,pros::v5::MotorGears::green,pros::v5::MotorUnits::degrees);
  
	pros::Motor LeftMotor_initializer(5,pros::v5::MotorGears::green,pros::v5::MotorUnits::degrees);//odom
	pros::Motor RightMotor_initializer(-6,pros::v5::MotorGears::green,pros::v5::MotorUnits::degrees);

	pros::adi::Encoder Xaxis ('B','C',false);
	
	pros::Motor FLXMotor (1);
	pros::Motor FRXMotor (2);
	pros::Motor BLXMotor (3);
	pros::Motor BRXMotor (4);

	pros::Motor LeftMotor(5);
	pros::Motor RightMotor(6);

    void lv_init();

}
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

	pros::lcd::register_btn1_cb(on_center_button);
	pros::adi::Encoder Xaxis ('B','C',false);
	pros::Motor FLX (1);
	pros::Motor FRX (2);
	pros::Motor BLX (3);
	pros::Motor BRX (4);

	pros::Motor Left(5);//odom
	pros::Motor Right(6);

    void lv_init();

}
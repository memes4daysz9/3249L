#include "main.h"
/*
float cPower;
 float cTurn;
 float left;
 float right;
 float curve;

	cPower = MainController.get_analog(ANALOG_LEFT_Y);
	cTurn = MainController.get_analog(ANALOG_RIGHT_X);
	left = cPower + cTurn;
	right = cPower - cTurn;

 	FrontLeftMotor.move(forward,(100*(((1-curve)*left)/100+(curve*pow(left/100,7)))));
 	FrontRightMotor.move(forward,(100*(((1-curve)*right)/100+(curve*pow(right/100,7)))));
  	BackLeftMotor.move(forward,(100*(((1-curve)*left)/100+(curve*pow(left/100,7)))));
 	BackRightMotor.move(forward,(100*(((1-curve)*right)/100+(curve*pow(right/100,7)))));*/

void opcontrol(){
    bool TDriveOverTemp;// this is for when the 2 motor drive gets over temp;
    bool XDriveOverTemp;// this is for when the x drive over temps

    pros::Motor FLXMotor (1);
	pros::Motor FRXMotor (2);
	pros::Motor BLXMotor (3);
	pros::Motor BRXMotor (4);

	pros::Motor LeftMotor(5);
	pros::Motor RightMotor(6);

    pros::Controller MainController(pros::E_CONTROLLER_MASTER);
    	pros::adi::DigitalIn AutoTuneButton (1);

    if (AutoTuneButton.get_value() >= 1){
        AutoTune();
        pros::screen::print(pros::E_TEXT_SMALL,11,"Button:%3d",AutoTuneButton.get_value());
    }
    while(true){
    const float curve = 0.85;
    float cPower;
    float cTurn;
    float cSide;
    float left;
    float right;
    float fleft;
    float fright;
    float bleft;
    float bright;

	cPower = MainController.get_analog(ANALOG_LEFT_Y);
	cTurn = MainController.get_analog(ANALOG_RIGHT_X);
    cSide = MainController.get_analog(ANALOG_LEFT_X);
    
	left = cPower + cTurn;
	right = cPower - cTurn;

    fleft = left - cSide;
    fright = right + cSide;
    bleft = left*(-1) - cSide;
    bright = right*(-1);

    FLXMotor.move_voltage(120 * (100*(((1-curve)*fleft)/100+(curve*pow(fleft/100,7)))));
    FRXMotor.move_voltage(120 * (100*(((1-curve)*fright)/100+(curve*pow(fright/100,7)))));
    BLXMotor.move_voltage(120 * (100*(((1-curve)*bleft)/100+(curve*pow(bleft/100,7))))); // parentheses galore
    BRXMotor.move_voltage(120 * (100*(((1-curve)*bright)/100+(curve*pow(bright/100,7)))));

    LeftMotor.set_current_limit(25 * left);
    RightMotor.set_current_limit(25 * right);// for helping temps

    LeftMotor.move_voltage(120 * right);
    RightMotor.move_voltage(120 * right);//so jank

    }
    //motor spin <- ->
}
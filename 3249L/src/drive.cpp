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
    const curve = 0.3;
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
    motor.spin();// work in proggress
}
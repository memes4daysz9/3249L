#include "main.h"
	pros::Motor FLXMotor (1);
	pros::Motor FRXMotor (2);
	pros::Motor BLXMotor (3);
	pros::Motor BRXMotor (4);

	pros::Motor LeftMotor(5);
	pros::Motor RightMotor(6);
extern constexpr double diameter = 3.25;
extern constexpr double radius = diameter/2;
extern constexpr double TrackLength = 8;
extern constexpr double Tolerance = 36;
extern double kP = 0;//might change this after AutoPID does its thing
extern double kI = 0;
extern double kD = 0;
extern void MoveAllMotors(float Voltage){//going forward
    FLXMotor.move_voltage(Voltage);
    FRXMotor.move_voltage(Voltage);
    BLXMotor.move_voltage(Voltage*(-1));
    BRXMotor.move_voltage(Voltage*(-1));
    LeftMotor.move_voltage(Voltage);
    RightMotor.move_voltage(Voltage);
}
extern void MoveXMotorsF(float Voltage){//for going forward
    FLXMotor.move_voltage(Voltage);
    FRXMotor.move_voltage(Voltage);
    BLXMotor.move_voltage(Voltage*(-1));
    BRXMotor.move_voltage(Voltage*(-1));
}
extern double InchesToDegrees(float distance){return distance/((M_PI * diameter)/360);}

extern double RotationToDegrees(double degrees){return (((degrees * (M_PI / 180))*(TrackLength/2))/diameter*360)/2;}


extern double DegToRad(double x) {
    return (x * (M_PI/180));
}
extern double RadToDeg(double x) {
    return (x* (180/M_PI));
}

extern int sgn(double x){return (x>0) - (x<0);}

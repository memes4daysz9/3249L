#include "main.h"

int Stepper = 0;

/*void ToggleBrakeMode(){
    pros::Motor FLXMotor(-1);
    pros::Motor FRXMotor(2);
    pros::Motor BLXMotor(3); // testing
    pros::Motor BRXMotor(-7);

    Stepper = ((Stepper + 1)*(Stepper < 2));// No if statement W
    
    if (Stepper < 2){
        Stepper++;
    }else{
        Stepper = 0;
    }
    FLXMotor.set_brake_mode(Stepper);
    FRXMotor.set_brake_mode(Stepper);
    BLXMotor.set_brake_mode(Stepper);
    BRXMotor.set_brake_mode(Stepper);
}*/
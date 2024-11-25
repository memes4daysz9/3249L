#include "main.h"

uint8_t Stepper = 0;

pros::motor_brake_mode_e_t BrakeMode [3] = {MOTOR_BRAKE_COAST,MOTOR_BRAKE_BRAKE,MOTOR_BRAKE_HOLD};// if it works it works

void ToggleBrakeMode(){
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
    FLXMotor.set_brake_mode(BrakeMode[Stepper]);
    FRXMotor.set_brake_mode(BrakeMode[Stepper]);
    BLXMotor.set_brake_mode(BrakeMode[Stepper]);
    BRXMotor.set_brake_mode(BrakeMode[Stepper]);
}

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

void MoterTempCheck(){
    const uint8_t max = 60;

    pros::Motor FLXMotor(-1);
    pros::Motor FRXMotor(2);
    pros::Motor BLXMotor(3); // testing
    pros::Motor BRXMotor(-4);

    float FrontMax = std::max(FLXMotor.get_temperature(),FRXMotor.get_temperature());
    float BackMax = std::max(BLXMotor.get_temperature(), BRXMotor.get_temperature());

    float AllMax = std::max(FrontMax, BackMax);
    if(AllMax > max){
        //bot.ErrorSector = ((FLXMotor.get_temperature() >= max) *1000)+ ((FRXMotor.get_temperature() >= max) * 100) + ((BLXMotor.get_temperature() >= max)*10) + (BRXMotor.get_temperature() >= max);
        //longest statement ever
    }
    /*if(AllMax >= 60){
        if(FrontMax > BackMax){

            if (FLXMotor.get_temperature() > FRXMotor.get_temperature())
            {
             
                bot.ErrorSector = 1;
           
            }else{

                bot.ErrorSector = 2;

            }
            

        }else{

             if (BLXMotor.get_temperature() > BRXMotor.get_temperature())
            {
             
                bot.ErrorSector = 3;
           
            }else{

                bot.ErrorSector = 4;

            }

        }

       
       bot.Interupt = true;

    }*/
    
}
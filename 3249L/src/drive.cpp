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
void Cheese()
{
    pros::Motor FLXMotor(-1);
    pros::Motor FRXMotor(2);
    pros::Motor BLXMotor(3); // testing
    pros::Motor BRXMotor(-7);

    FLXMotor.move_voltage(12000);
    FRXMotor.move_voltage(-12000);
    BLXMotor.move_voltage(12000); // WEEEEEEEEEEE :3
    BRXMotor.move_voltage(-12000);
    pros::delay(10);
    FLXMotor.move_voltage(0);
    FRXMotor.move_voltage(0);
    BLXMotor.move_voltage(0); // un WEE :(
    BRXMotor.move_voltage(0);
}
void HapyJompYIPPEE(){
    pros::Motor FLXMotor(-1);
    pros::Motor FRXMotor(2);
    pros::Motor BLXMotor(3); // testing
    pros::Motor BRXMotor(-7);

    FLXMotor.move_voltage(-12000);
    FRXMotor.move_voltage(-12000);
    BLXMotor.move_voltage(-12000); // Bong :3
    BRXMotor.move_voltage(-12000);
    pros::delay(10);
    FLXMotor.move_voltage(0);
    FRXMotor.move_voltage(0);
    BLXMotor.move_voltage(0); // un WEE :(
    BRXMotor.move_voltage(0);
}
void opcontrol()
{
    const float Limiter = 1; // helps with battery while testing
    bool TDriveOverTemp;     // this is for when the 2 motor drive gets over temp;
    bool XDriveOverTemp;     // this is for when the x drive over temps
    int TempState;           // Average, then Ports
    bool loop;               // stops values from rolling over
    //

    pros::Motor FLXMotor(-1);
    pros::Motor FRXMotor(2);
    pros::Motor BLXMotor(3); // testing
    pros::Motor BRXMotor(-7);

    pros::Motor LeftIn(5);
    pros::Motor RightIn(-6);

    pros::Controller MainController(pros::E_CONTROLLER_MASTER);
    pros::adi::DigitalIn AutoTuneButton(1);

    if (AutoTuneButton.get_value() >= 1)
    {
        AutoTune();
        pros::screen::print(pros::E_TEXT_SMALL, 11, "Button:%3d", AutoTuneButton.get_value());
    }
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

    while (true)
    {

        cPower = MainController.get_analog(ANALOG_LEFT_Y) * Limiter;
        cTurn = MainController.get_analog(ANALOG_RIGHT_X) * Limiter;
        cSide = MainController.get_analog(ANALOG_LEFT_X) * Limiter;

        left = cPower + cTurn;
        right = cPower - cTurn;

        fleft = (left + cSide); // idk why initialized motors dont reverse
        fright = right - cSide;
        bleft = left * (-1) + cSide;
        bright = (right * (-1) - cSide);

        FLXMotor.move_voltage((120 * (100 * (((1 - curve) * fleft) / 100 + (curve * pow(fleft / 100, 7))))) * Limiter);
        FRXMotor.move_voltage((120 * (100 * (((1 - curve) * fright) / 100 + (curve * pow(fright / 100, 7))))) * Limiter);
        BLXMotor.move_voltage((120 * (100 * (((1 - curve) * bleft) / 100 + (curve * pow(bleft / 100, 7))))) * Limiter); // parentheses galore
        BRXMotor.move_voltage((120 * (100 * (((1 - curve) * bright) / 100 + (curve * pow(bright / 100, 7))))) * Limiter);
        /*
        LeftMotor.set_current_limit(25 * left);
        RightMotor.set_current_limit(25 * right); // for helping temps

        LeftMotor.move_voltage(120 * left);   // testing
        RightMotor.move_voltage(120 * right); // so jank
        */

            bot.MaxTemp = (FLXMotor.get_temperature() + FRXMotor.get_temperature() + BLXMotor.get_temperature() + BRXMotor.get_temperature()) / 4;

        /*if (MainController.get_digital(DIGITAL_B))
            //lamba off

        }*/
        if (MainController.get_digital(DIGITAL_R2)){
            LeftIn.move_voltage(12000 * bot.IntakeSpeed);//positive voltage intakes. 
            RightIn.move_voltage(12000 * bot.IntakeSpeed);
        }else if (MainController.get_digital(DIGITAL_R1)){
            LeftIn.move_voltage(-120000 * bot.IntakeSpeed);//Negative Climbs the bot
            RightIn.move_voltage(-120000 * bot.IntakeSpeed);
        }
        if (MainController.get_digital(DIGITAL_UP)){
            Cheese();
        }
        if (MainController.get_digital(DIGITAL_X)){
            HapyJompYIPPEE();
        }
        // motor spin <- ->
    }

}


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
bool EnterNextTier(){
    
}
/*void opcontrol()
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
    pros::Motor BRXMotor(-4);

    pros::Motor LeftIn(5);
    pros::Motor RightIn(-6);

    pros::Controller MainController(pros::E_CONTROLLER_MASTER);
    pros::adi::DigitalIn AutoTuneButton(1);
    pros::adi::DigitalOut MOGOClamp(8);

    pros::Task Odom(Odometry);

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

        fleft = (left + cSide);
        fright = right - cSide;
        bleft = left * (-1) + cSide;
        bright = (right * (-1) - cSide);

        FLXMotor.move_voltage((120 * (100 * (((1 - curve) * fleft) / 100 + (curve * pow(fleft / 100, 7)))))+ 600);
        FRXMotor.move_voltage((120 * (100 * (((1 - curve) * fright) / 100 + (curve * pow(fright / 100, 7)))))+ 600);
        BLXMotor.move_voltage((120 * (100 * (((1 - curve) * bleft) / 100 + (curve * pow(bleft / 100, 7)))))+ 600); // parentheses galore
        BRXMotor.move_voltage((120 * (100 * (((1 - curve) * bright) / 100 + (curve * pow(bright / 100, 7)))))+ 600);
        if (MainController.get_digital(DIGITAL_L2)){
            MOGOClamp.set_value(1);

        }else if (MainController.get_digital(DIGITAL_L1)){
            MOGOClamp.set_value(0);
        }

            bot.MaxTemp = (FLXMotor.get_temperature() + FRXMotor.get_temperature() + BLXMotor.get_temperature() + BRXMotor.get_temperature()) / 4;
       
        if (MainController.get_digital(DIGITAL_B)){
            lambda.Toggle();
        }

        if (MainController.get_digital(DIGITAL_R2)){
            LeftIn.move_voltage(12000);//positive voltage intakes. 
            RightIn.move_voltage(12000);
        }else if (MainController.get_digital(DIGITAL_R1)){
            LeftIn.move_voltage(-120000);//Negative Climbs the bot
            RightIn.move_voltage(-120000);
        }else{
            LeftIn.move_voltage(0);
            RightIn.move_voltage(0);
        }
        
        if (MainController.get_digital(DIGITAL_UP)){
            Cheese();  
        }
        if (MainController.get_digital(DIGITAL_X)){
            HapyJompYIPPEE();
        }
        // motor spin <- ->
    }

}*/
void Vertical(float Voltage){//going forward
	pros::Motor FLXMotor (-1);
	pros::Motor FRXMotor (2);
	pros::Motor BLXMotor (3);
	pros::Motor BRXMotor (-4);


    FLXMotor.move_voltage(Voltage);
    FRXMotor.move_voltage(Voltage);
    BLXMotor.move_voltage(-Voltage);
    BRXMotor.move_voltage(-Voltage);
}
void Rotate(float Voltage){
    pros::Motor FLXMotor (-1);
	pros::Motor FRXMotor (2);
	pros::Motor BLXMotor (3);
	pros::Motor BRXMotor (-4);

    FLXMotor.move_voltage(Voltage);
    FRXMotor.move_voltage(-Voltage);
    BLXMotor.move_voltage(-Voltage);
    BRXMotor.move_voltage(Voltage);
}
void opcontrol(){
    pros::Controller MainController(pros::E_CONTROLLER_MASTER);
    Vertical(-6000);
    pros::delay(400);
    Vertical(0);
    //pnumatic enable MOGO
    pros::delay(100);
    Rotate(-12000);
    pros::delay(200);
    Vertical(0);
    pros::delay(100);
    Vertical(-12000);
    pros::delay(700);
    Vertical(0);
    //Pnumatic disable MOGO
    pros::delay(100);
    Rotate(-3000);
    pros::delay(200);
    Vertical(6000);
    pros::delay(1000);
    Vertical(0);
}

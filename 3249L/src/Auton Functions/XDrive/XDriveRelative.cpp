#include "main.h"

    pros::Motor FLX (1);
	pros::Motor FRX (2);
	pros::Motor BLX (3);
	pros::Motor BRX (4);

void Bot::XDriveRelativeForward(float Distance){

    double Output;
    double I;
    double lastError;
    bot.LTar = InchesToDegrees(Distance) + bot.LDeg;
    bot.error = (bot.LTar - bot.LDeg);

    while(bot.error >= Tolerance && !bot.failed){
        bot.error = (bot.LTar - bot.LDeg);
        I=(I+bot.error) * kI;
        Output = (bot.error * kP) + I + ((bot.error - lastError)*kD);
        lastError = error;
        FLX.move_voltage(Output);
        FRX.move_voltage(-Output);
        BLX.move_voltage(Output);
        BRX.move_voltage(-Output);
        }
}

void Bot::XDriveRelativeRotate(float Deg){

    int RSMul;
    double theta;
    double LastError;
    double output;
    double I;
    if (Deg < 0){
        RSMul = 1;
    }else{
        RSMul = -1;
    }
    bot.RTar = RotationToDegrees(Deg) + bot.RDeg;
    bot.error = bot.RTar - bot.RDeg;
    while (bot.error >= Tolerance && !bot.failed){
        bot.error = bot.RTar - bot.RDeg;
        I = (I + bot.error) * kD;
        output = (error * kP) + I + ((bot.error - LastError)*kD);
        LastError = bot.error;
        //RightMotor.move_voltage(output * RSMul);
        //LeftMotor.move_voltage(output * (RSMul * -1));

    }
}
        







    void Bot::XDriveRelativeHorizontal(float Distance){
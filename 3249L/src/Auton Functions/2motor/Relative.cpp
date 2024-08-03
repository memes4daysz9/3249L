#include "main.h"

void Bot::RelativeForward(float distance){

    double Output;
    double I;
    double lastError;
    bot.LTar = InchesToDegrees(distance) + bot.LDeg;
    bot.RTar = InchesToDegrees(distance) + bot.RDeg;
    bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;

    while(bot.error >= Tolerance && !bot.failed){
        bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;
        I=(I+bot.error) * kI;
        Output = (bot.error * kP) + I + ((bot.error - lastError)*kD);
        lastError = error;
        }
}
void Bot::RelativeRotate(float Deg){
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

void Bot::RelativeForwardHardStop(float distance){ //use this for really precise without overshooting. only really use this for the auton barrier for getting the mobile goal.
//PD controller
    double Output;
    double lastError;
    bot.LTar = InchesToDegrees(distance) + bot.LDeg;
    bot.RTar = InchesToDegrees(distance) + bot.RDeg;
    bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;
    while(bot.error >= Tolerance && !bot.failed){
        bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;
        Output = (bot.error * kP) + ((bot.error - lastError)*kD);
        lastError = error;
        }
}



void Bot::RelativeCurve(int p1[1],int p2[1]){
    const int x0 = 0; // this is where the bot is already at so its already a known variable
    const int y0 = 0;
    int x1 = p1[1];
    int y1= p1[2];
    int x2= p2[1];
    int y2= p2[2];
    double errorX;
    double errorY;
    double t;
    const double g = 0.85; // my own variable,just makes it take the corner faster
    double b0;
    double b1;
    b0 = (((pow(1-t,2) * x0 ) * g + (2*(1-t)*t*x1) * g + (pow(t,2)*x2)) * t);
    b1 = (((pow(1-t,2) * y0 ) * g + (2*(1-t)*t*y1) * g + (pow(t,2)*x2)) * t);
    bot.LTar = InchesToDegrees(b0) + bot.LDis;
    bot.RTar = RotationToDegrees(RadToDeg(atan(bot.RTar/bot.LTar))) + bot.RDeg;

    bot.error = errorX + errorY;

    errorX = bot.LTar - bot.LDeg;
    errorY = (RotationToDegrees(RadToDeg(atan(bot.RTar/bot.LTar)))) - bot.RDeg;
}
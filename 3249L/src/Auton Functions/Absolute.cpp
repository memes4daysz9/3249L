#include "main.h"



void Bot::AbsoluteForward(float x,float y){ // x = unprocessed X = processed
    double X = (x - bot.x);
    double Y = (y - bot.y);
    bool TurnLeft;
    double theta;
    double DistanceToCover = sqrt(pow(X,2)+pow(Y,2));
    double LastError;
    double output;
    double I;
    int RSMul;
    if(x < 0){//this finds the most optimal way to turn
        if(y < 0){
            TurnLeft = false;
            RSMul = -1;
            theta = 90 + atan(Y/X);
            //turn Right

        }else {
            TurnLeft = true;
            RSMul = 1;
            theta = asin(X/DistanceToCover);
            //turn left

        }
    }else if(y<0){
        TurnLeft = false;
        theta = std::abs(atan(Y/X));
        RSMul = -1;
        // turn Right
    }else {
        TurnLeft = true;
        RSMul = 1;
        theta = atan(Y/X);
        //turn Left
    }

    bot.RTar = RotationToDegrees(theta) + bot.RDeg;
    bot.error = bot.RTar - bot.RDeg;

    while (bot.error >= Tolerance && !bot.failed){ // rotation first
        bot.error = bot.RTar - bot.RDeg;
        I = (I + bot.error) * kD;
        output = (error * kP) + I + ((bot.error - LastError)*kD);
        LastError = bot.error;
        //RightMotor.move_voltage(output * RSMul);
        //LeftMotor.move_voltage(output * (RSMul * -1));
    }

    bot.LTar = InchesToDegrees(DistanceToCover) + bot.LDeg;
    bot.error = (bot.LTar - bot.LDeg);

    while(bot.error >= Tolerance && !bot.failed){// going forward
        bot.error = (bot.LTar - bot.LDeg);
        I = (I + bot.error) * kD;
        output = (error * kP) + I + ((bot.error - LastError)*kD);
        LastError = bot.error;
    }
    
}

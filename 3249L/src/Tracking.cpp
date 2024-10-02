#include "globals.h"
#include "main.h"
#include "pros/adi.hpp"

	pros::Motor Left(5);//odom
	pros::Motor Right(6);

const double XwheelDia  = 3.25;//since its a tracking wheel, it may have a different diameter than the drivetrain

const double SL = 1;// "the left-right distance from the tracking center to the left tracking wheel"
const double SR = 1;// "the left-right distance from the tracking center to the right tracking wheel"
const double SS = 1;// "the forward-backward distance from the tracking center to the back tracking wheel"

void Odometry(){

    pros::adi::Encoder Xaxis ('B','C',false);
    double DeltaLeft;
    double DeltaRight;
    double DeltaX;
    double LastL;
    double LastR;
    double LastX;
    double LastHeading;
    double DeltaHeading;
    double LocalOffset[2]; // delta variants of x,y
    while (true){
        bot.RDeg = Right.get_position();//delta R
        bot.LDeg = Left.get_position();//delta L
        bot.XDeg = Xaxis.get_value();// Delta S

        DeltaLeft = (bot.LDeg - LastL);
        DeltaRight = (bot.RDeg - LastR);
        DeltaX = (bot.XDeg - LastX);

        LastL = bot.LDeg;
        LastR = bot.RDeg;
        LastX = bot.XDeg;

        bot.LDis = DegToRad(DeltaLeft) * radius; // Lr
        bot.RDis = DegToRad(DeltaRight) * radius;//Rr               4
        bot.XDis = DegToRad(DeltaX) * XwheelDia;//doesnt get mentioned, but nice to have for now

        bot.Heading = LastHeading + ((bot.LDis-bot.RDis)/(SL+SR));//theta1

        DeltaHeading = bot.Heading - LastHeading;

        bot.Heading = (bot.Heading - LastHeading);

        if (DeltaHeading < 0.1){
            LocalOffset[0] = bot.XDis;
            if (bot.RDis > 1){
                LocalOffset[1] = bot.RDis;
            }else {
                LocalOffset[1] = bot.LDis;
            }//line 193 https://github.com/Aidan360/EyesofVector/blob/main/src/purePursuit.cpp
        }else {
            LocalOffset[0] = (2*sin(bot.Heading/2)*(bot.XDis/DeltaHeading)+SS);

            if (bot.RDis > 1){
                LocalOffset[1] = (2*sin(bot.Heading/2)*(bot.RDis/DeltaHeading)+SR);
            }else {
                LocalOffset[1] = (2*sin(bot.Heading/2)*(bot.LDis/DeltaHeading)+SL);
            }
        }
        bot.x += LocalOffset[0];
        bot.y += LocalOffset[1];
    }

}
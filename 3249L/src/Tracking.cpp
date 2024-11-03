#include "globals.h"
#include "main.h"
#include "pros/adi.hpp"
#include "okapi/api.hpp"

	pros::Motor Left(5);//odom
	pros::Motor Right(6);

const double TrackerRadius  = 3.25;//since its a tracking wheel, it may have a different diameter than the drivetrain

const double SL = 3.5;// "the left-right distance from the tracking center to the left tracking wheel"
const double SR = 3.5;// "the left-right distance from the tracking center to the right tracking wheel"
const double SS = 3.5;// "the forward-backward distance from the tracking center to the back tracking wheel"

void Odometry(){
    pros::adi::Encoder Left ('A','B',false);

    pros::adi::Encoder Xaxis ('C','D',false);
    pros::adi::Encoder Right ('E','F',false);
    //okapi::ADIEncoder Xaxis = {'C','D'};

    double DeltaLeft;
    double DeltaRight;
    double DeltaX;
    double LastL;
    double LastR;
    double LastX;
    double LastHeading;
    double DeltaHeading;
    double LocalOffset[2]; // delta variants of x,y
    int X;
    while (true){
        bot.RDeg = Right.get_value();//delta R
        bot.LDeg = Left.get_value();//delta L
        X = Xaxis.get_value();// Delta S
        bot.XDeg = X;
        pros::screen::print(pros::E_TEXT_SMALL,9,"X: %3d",X);

        DeltaLeft = (bot.LDeg - LastL);
        DeltaRight = (bot.RDeg - LastR);
        DeltaX = (bot.XDeg - LastX);

        LastL = bot.LDeg;
        LastR = bot.RDeg;
        LastX = bot.XDeg;

        bot.LDis = DegToRad(DeltaLeft) * TrackerRadius; // Lr
        bot.RDis = DegToRad(DeltaRight) * TrackerRadius;//Rr               4
        bot.XDis = DegToRad(DeltaX) * TrackerRadius;//doesnt get mentioned, but nice to have for now

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
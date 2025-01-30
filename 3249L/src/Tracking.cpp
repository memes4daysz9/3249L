#include "globals.h"
#include "main.h"
#include "pros/adi.hpp"




    //sine functions are in radians

const double TrackerRadius  = 3.25;//since its a tracking wheel, it may have a different diameter than the drivetrain

const double SL = 11;// "the left-right distance from the tracking center to the left tracking wheel"
const double SR = 11;// "the left-right distance from the tracking center to the right tracking wheel"
const double SS = 11;// "the forward-backward distance from the tracking center to the back tracking wheel"

void Odometry(){
    //pros::adi::Encoder Left ('A','B',false);

    //pros::adi::Encoder Xaxis ('C','D',false);
    //pros::adi::Encoder Right ('E','F',false);
    //okapi::ADIEncoder Xaxis = {'C','D'};

    pros::Motor Left(-1);
    pros::Motor Right(-4);
    pros::Motor Xaxis(3);

    double DeltaLeft;
    double DeltaRight;
    double DeltaX;
    int RDeg;
    int LDeg; 
    int XDeg;
    double RDis;
    double LDis;
    double XDis;
    double Heading = 0;
    double RHeading = 0;
    int LastL = 0;
    int LastR = 0;
    int LastX = 0;
    double LastHeading = 0;
    double DeltaHeading = 0;
    double LocalOffset[2]; // delta variants of x,y
    double AvgHeading;
    double HOffsetX;
    double HOffsetY;
    while (true){
        RDeg = int(Right.get_position());//delta R
        LDeg = int(Left.get_position());//delta L
        XDeg = int(Xaxis.get_position());// Delta X
        pros::screen::print(pros::E_TEXT_SMALL, 2, "LeftDeg:%d, RightDeg:%d, XDeg:%d", LDeg, RDeg, XDeg);
        bot.XDeg = XDeg;
        bot.LDeg = LDeg;//local to global
        bot.RDeg = RDeg;
        

        DeltaLeft = (LDeg - LastL);
        DeltaRight = (RDeg - LastR);
        DeltaX = (XDeg - LastX);

        //pros::screen::print(pros::E_TEXT_SMALL,19,"LL: %3d",LastL);



        LDis = DegToRad(DeltaLeft) * TrackerRadius; // Lr
        RDis = DegToRad(DeltaRight) * TrackerRadius;//Rr               4
        XDis = DegToRad(DeltaX) * TrackerRadius;

        Heading = LastHeading + double(((LDis-RDis)/(SL+SR)));//theta1

        DeltaHeading = Heading - LastHeading;

        bot.Heading = (RadToDeg(Heading - LastHeading)); // apparently thats just a thing.
        RHeading = Heading - LastHeading;// may work

        if (DeltaHeading < 0.1){
            LocalOffset[0] = XDis;
            if (RDis > double(1)){
                LocalOffset[1] = RDis;
            }else {
                LocalOffset[1] = LDis;
            }//line 193 https://github.com/Aidan360/EyesofVector/blob/main/src/purePursuit.cpp
        }else {
            LocalOffset[0] = double(double(2)*sin(RHeading/2)*(XDis/DeltaHeading)+SS);

            if (RDis > double(1)){
                LocalOffset[1] = double(2*sin(RHeading/2)*(RDis/DeltaHeading)+SR);
            }else {
                LocalOffset[1] = double(2*sin(RHeading/2)*(LDis/DeltaHeading)+SL);
            }
        }

        //pros::screen::print(pros::E_TEXT_SMALL, 2, "X:%f, Y:%f", bot.x,bot.y);

        bot.x += LocalOffset[0];
        bot.y += LocalOffset[1];

        LastL = LDeg;
        LastR = RDeg;
        LastX = XDeg;
    }

}







extern void IntakeTracking(){
    pros::Motor Left(5);//odom
    int IntakeDeg;
    int LastI;
    while(true){
        IntakeDeg = Left.get_position();
        conveyor.DistanceMoved = DegToRad(IntakeDeg); // radius of 1, therfore no multiplications
    }//skibidi toilet
}
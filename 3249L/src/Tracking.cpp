#include "main.h"

const double radius;

class Bot(){
    int RDeg;
    int LDeg;
    double LTar;
    double RTar;
    double Dis;
    double LDis;
    double RDis;
    double error;
    double Heading;
    bool PurePursuit;
}
double DegToRad(double x) {
    return (x * (pi/180));
}
double RadToDeg(double x) {
    return (x* (180/pi));
}

void Odometry(){
    double DeltaLeft;
    double DeltaRight;
    double LastL;
    double LastR;

    while (1){
        Bot.RDeg = 1;//replace with Motor degrees
        Bot.LDeg = 1;

        DeltaLeft = (Bot.LDeg - LastL);
        DeltaRight = (Bot.RDeg - LastR);

        Bot.LDis = DegToRad(DeltaLeft) * radius;
        Bot.RDis = DegToRad(DeltaRight) * radius;

        Bot.Dis = (Bot.LDis + Bot.RDis)/2.0;
        Bot.Heading = (Bot.Heading - LastHeading);

        Bot.x = Bot.Dis * cos(Bot.Heading);
        Bot.y = Bot.Dis * sin(Bot.Heading);

        LastL = Bot.LDeg;
        LastR = Bot.RDeg;
    }
}
#include "main.h"



void Odometry(){
    double DeltaLeft;
    double DeltaRight;
    double LastL;
    double LastR;
    double LastHeading;

    while (1){
        bot.RDeg = 1;//replace with Motor degrees
        bot.LDeg = 1;

        DeltaLeft = (bot.LDeg - LastL);
        DeltaRight = (bot.RDeg - LastR);

        bot.LDis = DegToRad(DeltaLeft) * radius;
        bot.RDis = DegToRad(DeltaRight) * radius;

        bot.Dis = (bot.LDis + bot.RDis)/2.0;
        bot.Heading = (bot.Heading - LastHeading);

        bot.x += bot.Dis * cos(bot.Heading);
        bot.y += bot.Dis * sin(bot.Heading);
        bot.Heading += (bot.LDis - bot.RDis)/ TrackLength;

        LastL = bot.LDeg;
        LastR = bot.RDeg;

        LastHeading = bot.Heading;
    }
}
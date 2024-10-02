#include "main.h"
extern constexpr double diameter = 3.25;
extern constexpr double radius = diameter/2;
extern constexpr double TrackLength = 8;
extern constexpr double Tolerance = 36;
extern double kP = 0;//might change this after AutoPID does its thing
extern double kI = 0;
extern double kD = 0;
extern void MoveAllMotors(float Voltage){
    
}
extern double InchesToDegrees(float distance){return distance/((M_PI * diameter)/360);}

extern double RotationToDegrees(double degrees){return (((degrees * (M_PI / 180))*(TrackLength/2))/diameter*360)/2;}


extern double DegToRad(double x) {
    return (x * (M_PI/180));
}
extern double RadToDeg(double x) {
    return (x* (180/M_PI));
}

extern int sgn(double x){return (x>0) - (x<0);}

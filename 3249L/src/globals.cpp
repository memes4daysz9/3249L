#include "main.h"
extern const double diameter = 3.25;
extern const double radius = diameter/2;
extern const double TrackLength = 8;
extern const double Tolerance = 36;
extern double kP = 0;//might change this after AutoPID does its thing
extern double kI = 0;
extern double kD = 0;


extern double InchesToDegrees(float distance){return distance/((M_PI * diameter)/360);}

extern double RotationToDegrees(double degrees){return (((degrees * (M_PI / 180))*(TrackLength/2))/diameter*360)/2;}


extern double DegToRad(double x) {
    return (x * (M_PI/180));
}
extern double RadToDeg(double x) {
    return (x* (180/M_PI));
}

extern int sgn(double x){if (x > 0){return 1;}else if(x < 0){return -1;}else{return 0;}}

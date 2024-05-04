#include "main.h"
extern const double diameter = 3.25;
extern const double radius = diameter/2;
extern const double TrackLength = 8;
extern const double Tolerance = 36;
extern const double kP = 30;
extern const double kI = 0.1;
extern const double kD = 1;
extern double InchesToDegrees(float distance){return distance/((M_PI * diameter)/360);}

extern double RotationToDegrees(double degrees){return (((degrees * (M_PI / 180))*(TrackLength/2))/diameter*360)/2;}


extern double DegToRad(double x) {
    return (x * (M_PI/180));
}
extern double RadToDeg(double x) {
    return (x* (180/M_PI));
}



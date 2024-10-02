#include "main.h"
#pragma once
extern double InchesToDegrees(float distance);
extern double RotationToDegrees(double degrees);
extern double DegToRad(double x);
extern double RadToDeg(double x);
extern int sgn(double x);
extern void MoveAllMotors(float Voltage);
extern void LogPIDValues();
extern void LogALLvalues();
extern void AutoTune();
extern const double diameter;
extern const double TrackLength;
extern const double Tolerance;
extern const double radius;
extern double kP;
extern double kI;
extern double kD;
extern ProgressBar Bars[13];
extern Needle Needles[13];

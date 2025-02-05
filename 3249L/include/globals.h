#include "main.h"
#pragma once

extern double InchesToDegrees(float distance);
extern double RotationToDegrees(double degrees);
extern double DegToRad(double x);
extern double RadToDeg(double x);
extern int sgn(double x);
extern void MoveAllMotors(float Voltage);
extern void MoveXMotorsF(float Voltage);
extern void LogPIDValues();
extern void LogALLvalues();
extern void AutoTune();
extern void Odometry();
extern void ShowScreen();
extern void IntakeTracking();
extern const double diameter;
extern const double TrackLength;
extern const double Tolerance;
extern const double radius;
extern double kP;
extern double kI;
extern double kD;
extern const int PathLimit;
extern int CurrLine;
extern float Paths[][2];
//extern ProgressBar Bars[13];
//extern Needle Needles[13];

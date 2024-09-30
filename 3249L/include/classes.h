#include "main.h"
#pragma once
class Bot{
    public:
    int RDeg;
    int LDeg;
    int XDeg;
    float LTar;
    float RTar;//double 4 byte = 8 byte
    double Dis;
    double LDis;
    double RDis;
    double XDis;
    double error;
    bool PurePursuit;
    double Heading;
    double x;
    double y;
    bool failed;
    //very much needed`
    Bot();
    //by default, movements are using dual motor, however there are functions for using all motors for going forward and rotating
    void XDriveRelativeForward(float Distance);
    void XDriveRelativeHorizontal(float Distance);// negitive left, positive right
    void XDriveRelativeRotate(float Deg);//X Drive exclusive

    void XDriveGoTo(float x,float y);
    void XDriveAbsoluteRotate(float Deg);//X Drive exclusive

    void RelativeForward(float Distance);
    void RelativeRotate(float Deg);
    void RelativeForwardHardStop(float Distance);
    void RelativeCurve(int p1[1],int p2[1]); // dual motor exclusive

    void AbsoluteGoTo(float x,float y);
    void AbsoluteRotate(float Deg);//dual motor exclusive
    void AbsoluteHardStop(int x, int y);
    void AbsoluteCurve(int p1[1] ,int p2[1], int p3[1]);

    void AllMotorRotate(float Deg);//All motors
    void AllMotorForward(float distance);
    void AllMotorHardStop(float x,float y);


};
extern Bot bot;

class Lambda{
    public:
    bool status;
    Lambda();
    void Activate();//Lambda.Activate();
    void Deactivate();//Lambda.DeActivate();
};
extern Lambda lambda;
class Conveyor{
    public:
    bool Climbing;
    bool Intaking;
    Conveyor();
    void Climb();//Conveyor.Climb();
    void Intake();//Conveyor.Intake();
};
extern Conveyor conveyor;
class Logger{
    public:
    bool IsSDconnected;
    bool isInFile;
    std::string FileName;
    Logger();
    void writeToFile(std::string Text);
    void CreateFile(std::string FileName);
};
extern Logger logger;

class ProgressBar{
    public:
    float Data;
    float min;
    float max;
    int X[1];
    int Y[1];
    int ID;
    bool initBar(ProgressBar CurBar);
    void GetBarID(ProgressBar BarToGet);
    bool UpdateBar(int BarID);
    bool UpdateAllBars();
};
extern ProgressBar bar;

class Needle{// little spedometer
    public:
    float Data;
    float min;
    float max;
    float Radius;
    int16_t X[1];
    int16_t Y[1];
    int ID;
    void InitDial(Needle NtoAdd);
    void UpdateDial(int BarID);
};
extern Needle needle;
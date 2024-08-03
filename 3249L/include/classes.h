#include "main.h"
#pragma once
class Bot{
    public:
    int RDeg;
    int LDeg;
    float LTar;
    float RTar;//double 4 byte = 8 byte
    double Dis;
    double LDis;
    double RDis;
    double error;
    bool PurePursuit;
    double Heading;
    double x;
    double y;
    bool failed;
    //very much needed
    Bot();
    void RelativeForward(float Distance);
    void RelativeRotate(float Deg);
    void RelativeForwardHardStop(float Distance);
    void RelativeCurve(int p1[1],int p2[1]);
    void AbsoluteGoTo(float x,float y);
    void AbsoluteRotate(float Deg);
    void AbsoluteHardStop(int x, int y);
    void AbsoluteCurve(int p1[1] ,int p2[1], int p3[1]);

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
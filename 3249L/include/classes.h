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
    float MaxTemp;
    float IntakeSpeed;
    //very much needed`
    Bot();
    bool MoveToPoint(float x,float y);//deprecatted
    bool MoveRelative(float x, float y);
    bool AddppPoint(float x,float y);
    bool MoveVertical(float dis);

};
extern Bot bot;

class Lambda{
    public:
    bool status;
    Lambda();
    void Activate();//Lambda.Activate();
    void Deactivate();//Lambda.DeActivate();
    void Toggle();
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

/*class ProgressBar{
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
*/// i giving up ngl
/*class Vector2{
    public:
    float x;
    float y;
    Init();
};
extern Vector2 vector2;

class Vector3{
    public:
    float x;
    float y;
    float z;//typically will be heading
    Init();
};
extern Vector3 vector3;*/
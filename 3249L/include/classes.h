#include "main.h"

class Bot{
    public:
    int RDeg;
    int LDeg;
    int LTar;
    int RTar;
    double error;
    Bot();
    void RelativeForward(float Distance);
    void RelativeRotate(float Deg);
    void RelativeHardStop(float Distance);
    void AbsoluteForward(int x,int y);
    void AbsoluteRotate(float Deg);
    void AbsoluteHardStop(int x, int y);
};

class Lambda{
    public:
    bool status;
    Lambda();
    void Activate();
    void Deactivate();
};

class Conveyor{
    public:
    bool Climbing;
    Conveyor();
    void Climb();
    void Intake();
};
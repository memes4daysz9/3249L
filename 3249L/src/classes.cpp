
#include "main.h"

Bot bot;
Bot::Bot(){
    int RDeg;
    int LDeg;
    int XDeg;
    double LTar;
    double RTar;
    double Dis;
    double LDis;
    double RDis;
    double XDis;

    float MaxTemp;
    double Heading;
    bool PurePursuit;
    double error;
    float IntakeSpeed;
    bool Interupt = false;

    int ErrorCode;
    int ErrorSector;//stuff like which motor
}

Lambda lambda;
Lambda::Lambda(){
    bool status;
}
int StepperL;
pros::adi::DigitalOut lambdap(7);
void Lambda::Toggle(){
    StepperL = ((StepperL + 1)*(StepperL < 1)); // 0 and 1
    lambdap.set_value(StepperL);
}

Conveyor conveyor;
Conveyor::Conveyor(){
    bool Climbing;
    bool Intaking;
    int ClimbDistance;// Total distance climbed so far, in inches
    float CurrentTier;// a more user friendly version of climb distance
    float DistanceMoved;//Raw movement
}

Logger logger;
Logger::Logger(){

    bool IsSDconnected;
    bool isInFile;
    std::string FileName;
}
/*Vector2 vector2;
Vector2::Init(){
    public:
    float x;
    float y;
};
extern Vector2 vector2;

Vector3::Init(){
    public:
    float x;
    float y;
    float z;//typically will be heading
};
extern Vector3 vector3;
*/
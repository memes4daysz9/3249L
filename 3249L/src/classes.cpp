
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
    double error;
    double Heading;
    bool PurePursuit;
}

Lambda lambda;
Lambda::Lambda(){
    bool status;
}

Conveyor conveyor;
Conveyor::Conveyor(){
    bool Climbing;
    bool Intaking;
}

Logger logger;
Logger::Logger(){

    bool IsSDconnected;
    bool isInFile;
    std::string FileName;
}
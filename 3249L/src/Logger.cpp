#include "globals.h"
#include "main.h"
#include "pal/log.h"

void LogPIDValues(){
    log_segment();
    log_data_dbl("kP",kP);
    log_data_dbl("kI",kI);
    log_data_dbl("kD",kD);
    log_segment();//for the next list of data, the PID data is just for easy viewing
}
void LogALLvalues(){
    
}
/*
X
Y
LDeg
RDeg
Heading
Error
LeftDis
RightDis
Dis
ForwardTar
RotateTar
FPS
TimeBetweenFrames
PID Failed?
PurePursuit
*/
/*          pros::screen::print(pros::E_TEXT_SMALL,1,"X:%3d, Y:%3d",bot.x,bot.y);
          pros::screen::print(pros::E_TEXT_SMALL,2,"LeftDeg:%3d, RightDeg:%3d",bot.LDeg,bot.RDeg);
          pros::screen::print(pros::E_TEXT_SMALL,3,"Heading:%3d",bot.Heading);
          pros::screen::print(pros::E_TEXT_SMALL,4,"Error:%3d",bot.error);
          pros::screen::print(pros::E_TEXT_SMALL,5,"LeftDis:%3d, RightDis:%3d",bot.LDis,bot.RDis);
          pros::screen::print(pros::E_TEXT_SMALL,6,"ForwardTar%3d, RotateTar:%3d",bot.LTar,bot.RTar);
          pros::screen::print(pros::E_TEXT_SMALL,7,"FPS:%3d",1000/((1000/FrameRate)-TimePast));
          pros::screen::print(pros::E_TEXT_SMALL,8,"Time Between Clocks:%3d",TimePast);*/
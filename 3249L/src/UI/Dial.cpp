#include "main.h"

void Needle::InitDial(Needle NtoAdd){
    Needles[NtoAdd.ID] = NtoAdd;
    UpdateDial(NtoAdd.ID);
}

void Needle::UpdateDial(int BarID){
    const int step = 1;
    float limit = Needles[BarID].max/180;
    float Heading = Needles[BarID].Data/limit;
    float L[1];
    L[0] = step*cos(M_PI*2* (-Heading/360))* -Needles[BarID].Radius;
    L[1] = step*sin(M_PI*2* (-Heading/360))* -Needles[BarID].Radius;
    int16_t* X;
    int16_t* Y;
    X = Needles[BarID].X;
    Y = Needles[BarID].Y;
    pros::screen::draw_line(*X, *Y, L[0], L[1]);
}

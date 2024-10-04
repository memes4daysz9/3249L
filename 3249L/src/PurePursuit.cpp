#include "main.h"
//THIS IS HEAVILY A WORK IN PROGRESS and will probably not be used for awhile

/*
steps:
Get the location of the vehicle
find the path point closest to the vehicle in a single look ahead distance
find the good point
transform the goal point to vehicle cordinates
calculate the curvature and request the vehicle to set the steering to that curvature
Update position
*/
//TODO:  2,3,4,

const float LookAheadDist = 10;//this is in inches
void RunPP(){
    bool Colliding;
//Vector3 ClosestPath[1];
//goal point is the position on the line thats the closest to the look ahead distance
    float x[1];
    float y[1];

    float ColXm; // m = -
    float ColXp;
    float ColYm;// Col = Collider
    float ColYp;// p = +
    float Discriminant;
    while (true){
    float Dx = x[1] - x[0];
    float Dy = y[1] - x[0];
    float Dr = sqrt(pow(Dx,2)+pow(Dy,2));
    float D = (x[0]*y[1]) - (x[1]*y[0]);
    

    ColXm = (D * Dy - sgn(Dy)*Dx *sqrt(pow(LookAheadDist,2)* pow(Dr,2)-pow(D,2)))/pow(Dr,2);//what the sigma
    ColXp = (D * Dy + sgn(Dy)*Dx *sqrt(pow(LookAheadDist,2)* pow(Dr,2)-pow(D,2)))/pow(Dr,2);//what the sigma

    ColYm = (-D*Dx-abs(Dy)*sqrt(pow(LookAheadDist,2)*pow(Dr,2)-pow(D,2)))/pow(Dr,2);
    ColYp = (-D*Dx+abs(Dy)*sqrt(pow(LookAheadDist,2)*pow(Dr,2)-pow(D,2)))/pow(Dr,2);

    Discriminant = pow(LookAheadDist,2)*pow(Dr,2) - pow(D,2);
    
    if (Discriminant > 0 || Discriminant == 0){
        Colliding = true;
    }else{
        Colliding = false;
    }
    }
}
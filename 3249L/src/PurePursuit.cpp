#include "main.h"
// THIS IS HEAVILY A WORK IN PROGRESS and will probably not be used for awhile

/*
steps:
Get the location of the vehicle
find the path point closest to the vehicle in a single look ahead distance
find the good point
transform the goal point to vehicle cordinates
calculate the curvature and request the vehicle to set the steering to that curvature
Update position
*/
// TODO:  2,3,4,

float Sol1[1]; // im hella stupid when i intially wrote this, Solution one is both X Solutoins, so thats fun! And screw you future Ben GLHF
float Sol2[1];
const float LookAheadDist = 10; // this is in inches
const int PathLimit = 3;
const float Paths[PathLimit][2] = {
    {0, 0},
    {1, 1},  // OH MY GOD WE ARE PLANNING AN AIR STRIKE
    {2, 7}}; // erm actually these are points in a path and not the paths themselves
float BestPoint[1];
bool Finished = false;


bool CheckForIntersection(float xp[1], float yp[1])
{

    float x[1]; // with offset
    float y[1]; // with offset

    x[0] = xp[0] - bot.x;
    x[1] = xp[1] - bot.x;

    y[0] = yp[0] - bot.y;
    y[1] = yp[1] - bot.y;

    bool Colliding;
    // Vector3 ClosestPath[1];
    // goal point is the position on the line thats the closest to the look ahead distance

    float ColXm; // m = -
    float ColXp;
    float ColYm; // Col = Collider
    float ColYp; // p = +

    float Discriminant;
    float MinPoint[1]; // X then Y
    float MaxPoint[1];
    MinPoint[0] = std::min(x[0], x[1]);
    MinPoint[1] = std::min(y[0], y[1]);

    MaxPoint[0] = std::max(x[0], x[1]);
    MaxPoint[1] = std::max(y[0], y[1]);

    float Dx = x[1] - x[0];
    float Dy = y[1] - x[0];
    float Dr = sqrt(pow(Dx, 2) + pow(Dy, 2));
    float D = (x[0] * y[1]) - (x[1] * y[0]);

    Sol1[0] = (D * Dy - sgn(Dy) * Dx * sqrt(pow(LookAheadDist, 2) * pow(Dr, 2) - pow(D, 2))) / pow(Dr, 2); // what the sigma
    Sol1[1] = (D * Dy + sgn(Dy) * Dx * sqrt(pow(LookAheadDist, 2) * pow(Dr, 2) - pow(D, 2))) / pow(Dr, 2); // what the sigma

    Sol2[0] = (-D * Dx - abs(Dy) * sqrt(pow(LookAheadDist, 2) * pow(Dr, 2) - pow(D, 2))) / pow(Dr, 2);
    Sol2[1] = (-D * Dx + abs(Dy) * sqrt(pow(LookAheadDist, 2) * pow(Dr, 2) - pow(D, 2))) / pow(Dr, 2);

    Discriminant = pow(LookAheadDist, 2) * pow(Dr, 2) - pow(D, 2);

    if (Discriminant > 0 || Discriminant == 0)
    {
        Colliding = true;
    }
    else
    {
        Colliding = false; // this is for objects that dont even need to run the bounds check, as i know full well that the bounds check is expensive
        return false;
    }

    if (Colliding && /*X*/ ((MinPoint[0] <= Sol1[0] <= MaxPoint[0]) || (MinPoint[0] <= Sol1[1] <= MaxPoint[0])) && /*Y*/ ((MinPoint[1] <= Sol2[0] <= MaxPoint[1]) || (MinPoint[1] <= Sol2[1] <= MaxPoint[1])))
    { // check if its within the range of the bounds
        return true;
    }
}

bool GetBestPoint()
{                      // trying to find which of the two points we should go after, otherwise itll send us backwards
    float Distance[1]; // for getting the distance from the end point to the solution point
    float x[1];
    float y[1];
    for (int i = PathLimit; i > 0; i--)
    { // oOoOoo scary inverse for loop. I know i will regret it later but it might be helpful
        // starting with the last points to check so the one thats closest to the end will always run. why diddnt the people inside the doc not think of this. such poopy farts
        x[0] = Paths[i - 1][0];
        x[1] = Paths[i][0];
        y[0] = Paths[i - 1][1]; // feels like this can be optimized, oh well
        y[1] = Paths[i][1];
        if (CheckForIntersection(x, y))
        { // if a valid intercetion happens, then our job here is done
            Distance[0] = x[1] - Sol1[0];
            if (abs(Sol1[0] - x[1]) < abs(Sol1[1] - x[1]) || abs(Sol2[0] - x[1]) < abs(Sol2[1] - x[1]))
            { // if the first solution is smaller, or closer to the goal, then the best distance is the first distance.
                Distance[1] = Sol2[0];
                Distance[0] = Sol1[0];
                BestPoint[0] = Distance[0];
                BestPoint[1] = Distance[1];
                break;
            }
            else
            {
                Distance[1] = Sol2[1];
                Distance[0] = Sol1[1];
                BestPoint[0] = Distance[0];
                BestPoint[1] = Distance[1];
                break;
            }
        }
    }
}

bool MoveToPoint()
{
    pros::Motor FLXMotor(-1);
pros::Motor FRXMotor(2);
pros::Motor BLXMotor(3);
pros::Motor BRXMotor(-7);

pros::Motor LeftMotor(5);
pros::Motor RightMotor(6);
    float T;
    float R; // Temps
    float S;

    float P1 = cos(T + (M_PI / 4)) * (-1);
    float P2 = sin(T + (M_PI / 4));
    float s = (std::max(abs(P1), abs(P2))) / S;
    float MoveBias[4]; // the part that moves the individual X motors, this goes into an error calcualation
    // FL, FR, BL, BR
    // this is going to suck to implement
    // convert X,Y to X,Y with Heading Biases
    float Hypotentuse = sqrt(pow(BestPoint[0], 2) + pow(BestPoint[1], 2));
    float Heading = bot.Heading - sin(BestPoint[1] / Hypotentuse);
    // heading = sin(opposite/hypotinuse)

    float l0 = cos((Heading / 180));
    float l1 = sin(M_PI * 2 * (Heading / 360));
    float Bias[1];
    Bias[0] = BestPoint[0] + l0;
    Bias[1] = BestPoint[1] + l1;
    float Dividend = std::max(Bias[1]+Bias[0],Bias[1]-Bias[0]);
    MoveBias[0] = (Bias[1] + Bias[0])/Dividend;
    MoveBias[1] = (Bias[1] - Bias[0])/Dividend;
    MoveBias[2] = (Bias[1] - Bias[0])/Dividend;//Normalizing them. making them -1 - 1
    MoveBias[3] = (Bias[1] + Bias[0])/Dividend;
    float error = InchesToDegrees((bot.x + bot.y) - (BestPoint[0] + BestPoint[1])); // I would like to mention this calculation is math pulled out me rear, its not at all definite and is 90% wrong
    while (error > Tolerance)
    {
        error = InchesToDegrees((bot.x + bot.y) - (BestPoint[0] + BestPoint[1]));
        FLXMotor.move_voltage(12000 * MoveBias[0]);
        FRXMotor.move_voltage(12000 * MoveBias[1]);
        BLXMotor.move_voltage(12000 * MoveBias[2]);
        BRXMotor.move_voltage(12000 * MoveBias[3]);
    }
}
void RunPP()
{

    while (!Finished)
    {
        GetBestPoint(); // get target
        MoveToPoint();  // move
    }
}
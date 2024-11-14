#include "main.h"

bool Bot::AddppPoint(float x, float y){//add point to the PP array
    if (CurrLine == NULL){
        CurrLine = 0;
    }
    int Cord[2];
    Paths[CurrLine][0] = x;
    Paths[CurrLine][1] = y; // should maybe hopefully work
    CurrLine++;
}


bool Bot::MoveRelative(float x, float y){
    pros::Motor FLXMotor(-1);
    pros::Motor FRXMotor(2);
    pros::Motor BLXMotor(3);
    pros::Motor BRXMotor(-7);

    pros::Motor LeftMotor(5);
    pros::Motor RightMotor(6);

    float T;
    float R; // Temps
    float S; //what?

    float P1 = cos(T + (M_PI / 4)) * (-1);
    float P2 = sin(T + (M_PI / 4));
    float s = (std::max(abs(P1), abs(P2))) / S;
    float MoveBias[4]; // the part that moves the individual X motors, this goes into an error calcualation
    // FL, FR, BL, BR
    // this is going to suck to implement
    // convert X,Y to X,Y with Heading Biases
    float Hypotentuse = sqrt(pow(x, 2) + pow(y, 2));
    float Heading = bot.Heading - sin(y / Hypotentuse);
    // heading = sin(opposite/hypotinuse)

    float l0 = cos((Heading / 180));
    float l1 = sin(M_PI * 2 * (Heading / 360));
    float Bias[1];
    Bias[0] = x + l0;
    Bias[1] = y + l1;
    float Dividend = std::max(Bias[1]+Bias[0],Bias[1]-Bias[0]);
    MoveBias[0] = (Bias[1] + Bias[0])/Dividend;
    MoveBias[1] = (Bias[1] - Bias[0])/Dividend;
    MoveBias[2] = (Bias[1] - Bias[0])/Dividend;//Normalizing them. making them -1 - 1
    MoveBias[3] = (Bias[1] + Bias[0])/Dividend;
    float error = InchesToDegrees((bot.x + bot.y) - (x + y)); // I would like to mention this calculation is math pulled out of thin air, its not at all definite and is 90%, completly wrong
    while (abs(error) > Tolerance)
    {
        error = InchesToDegrees((bot.x + bot.y) - (x + y));
        FLXMotor.move_voltage(12000 * MoveBias[0]);
        FRXMotor.move_voltage(12000 * MoveBias[1]);
        BLXMotor.move_voltage(12000 * MoveBias[2]);
        BRXMotor.move_voltage(12000 * MoveBias[3]);
    }
}
bool MoveVertical(float dis){
    float Combined = bot.x + bot.y;
    
    bot.LTar = (Combined + InchesToDegrees(dis)*(dis>0))+(Combined - InchesToDegrees(dis)*(dis<0));

    if (dis == 0)return false;// slight optimize for litterally no reason

    bot.error = bot.LTar - Combined;

    pros::Motor FLXMotor(-1);
    pros::Motor FRXMotor(2);
    pros::Motor BLXMotor(3);
    pros::Motor BRXMotor(-7);
    
    float i;
    float LastError;

    while (abs(bot.error) > Tolerance){

        i = (i+bot.error) * kI;

        FLXMotor.move_voltage((bot.error * kP)+i+((bot.error - LastError) * kD));
        BLXMotor.move_voltage((bot.error * kP)+i+((bot.error - LastError) * kD));
        FRXMotor.move_voltage((bot.error * kP)+i+((bot.error - LastError) * kD));
        BRXMotor.move_voltage((bot.error * kP)+i+((bot.error - LastError) * kD));   
        
        LastError = bot.error;
    }
}
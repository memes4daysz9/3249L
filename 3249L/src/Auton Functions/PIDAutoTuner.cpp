#include "main.h"

const int Tolerance = 30;//motor degrees
void AutoTune(){//start with P then move to I then D
    double minP = 1;
    bool GotPValue = false;
    double TestingP;
    double LastP;
    double Adder = 10;//how much to add to each variable per their test run
    while (RDeg < Tolerance){
        //P tuning
        //get the lowest value for P possible

        //motor.move_voltage(minP);
        minP += 10;
    }
    TestingP = minP;
    while (!GotPValue){
        if(ForwardPTest(10,TestingP)){
            TestingP = LastP + Adder;
        }else{
            if(Adder < 1){
                GotPValue = true;//exiting loop
                
            }else{
                Adder = Adder/10; //10, 1, 0.1
                TestingP = -(Adder + Adder);//worse case, it makes you do 10 more
            }
        }
        kP = TestingP;
        RollBack(10);
        LastP = TestingP;
    }
    Adder = 0.1;//for I setup
    bool GotIValue = false;
    double TestingI;
    double LastI;
    while (!GotIValue){
        if(ForwardITest(10,TestingI)&&ForwardITest(10,TestingI)){//twice, to ensure reliability as the I multiplier can be hectic
            TestingI = LastI + Adder;
        }else{
            if(Adder < 0.1){
                GotIValue = true;//exiting loop
                
            }else{
                Adder = Adder/10; //0.1, 0.01
                TestingI = -(Adder);
            }
        }
    }
}
bool RollBack(float distance){
    double Output;
    double I;
    double lastError;
    bot.LTar = InchesToDegrees(distance) + bot.LDeg;
    bot.RTar = InchesToDegrees(distance) + bot.RDeg;
    bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;

    while(bot.error >= Tolerance && !bot.failed){
        bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;
        I=(I+bot.error) * 0;
        Output = (bot.error * kP) + I + ((bot.error - lastError)*0);
        lastError = error;
        }
}
bool ForwardITest(float distance,double Imul){

    double Output;
    double I;
    double lastError;
    bot.LTar = InchesToDegrees(distance) + bot.LDeg;
    bot.RTar = InchesToDegrees(distance) + bot.RDeg;
    bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;

    while(bot.error >= Tolerance && !bot.failed){
        bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;
        I=(I+bot.error) * Imul;
        Output = (bot.error * kp) + I + ((bot.error - lastError)*0);
        if (bot.error >= -(Tolerance)){
            bot.failed = true;
        }
        lastError = error;
    }
    if (bot.failed){
        return false; //failed, make the tester roll back twice then go finer
    }else{
        return true;//passed, up the amount
    }
}
bool ForwardPTest(float distance,double P){

    double Output;
    double I;
    double lastError;
    bot.LTar = InchesToDegrees(distance) + bot.LDeg;
    bot.RTar = InchesToDegrees(distance) + bot.RDeg;
    bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;

    while(bot.error >= Tolerance && !bot.failed){
        bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;
        I=(I+bot.error) * 0;
        Output = (bot.error * P) + I + ((bot.error - lastError)*0);
        if (bot.error >= -(Tolerance)){
            bot.failed = true;
        }
        lastError = error;
    }
    if (bot.failed){
        return false; //failed, make the tester roll back twice then go finer
    }else{
        return true;//passed, up the amount
    }

}
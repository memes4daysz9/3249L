#include "main.h"

const int ATtolerance = 6;//motor degrees, may change if friction is much different from last year
const int OverShootAmt = 1;
int MaxWorkingDistance;
int MinWorkingDistance;

    
void MoveAllMotors(float Voltage){//going forward
	pros::Motor FLXMotor (-1);
	pros::Motor FRXMotor (2);
	pros::Motor BLXMotor (3);
	pros::Motor BRXMotor (-4);


    FLXMotor.move_voltage(Voltage);
    FRXMotor.move_voltage(Voltage);
    BLXMotor.move_voltage(Voltage);
    BRXMotor.move_voltage(Voltage);
}
void MoveXMotorsF(float Voltage){//for going forward
	pros::Motor FLXMotor (-1);
	pros::Motor FRXMotor (2);
	pros::Motor BLXMotor (3);
	pros::Motor BRXMotor (-7);

	pros::Motor LeftMotor(5);
	pros::Motor RightMotor(6);
    FLXMotor.move_voltage(Voltage);
    FRXMotor.move_voltage(Voltage);
    BLXMotor.move_voltage(Voltage*(-1));
    BRXMotor.move_voltage(Voltage*(-1));
}
bool RollBack(float distance){//just using that P
    double Output;
    double I;
    double lastError;
    bot.LTar = InchesToDegrees(distance) + bot.LDeg;
    bot.RTar = InchesToDegrees(distance) + bot.RDeg;
    bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;

    while(bot.error >= ATtolerance && !bot.failed){
        bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;
        I=(I+bot.error) * 0;
        Output = (bot.error * kP) + I + ((bot.error - lastError)*0);
        MoveAllMotors(Output);
        lastError = bot.error;
        }
}
bool ForwardPTest(float distance,double P){
    int amtTimesRan = 0;
    double Output;
    double I;
    double lastError;
    bot.LTar = InchesToDegrees(distance) + bot.LDeg;
    bot.RTar = InchesToDegrees(distance) + bot.RDeg;
    bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;

    while(bot.error >= ATtolerance && !bot.failed && amtTimesRan <= 3){
        bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;
        I=(I+bot.error) * 0;
        Output = (bot.error * P) + I + ((bot.error - lastError)*0);
        MoveAllMotors(Output);
        if (bot.error <= -(InchesToDegrees(OverShootAmt)+ATtolerance)){//if it passes over the ATtolerance limit, report that it failed
            bot.failed = true;
        }else if (bot.error >= InchesToDegrees(OverShootAmt)){
            RollBack(distance);
            amtTimesRan++;
        }
        lastError = bot.error;
    }

    if (bot.failed){
        return false; //failed, make the tester roll back then go finer
    }else{
        return true;//passed, up the amount
    }

}
bool ForwardDTest(float distance,double D){
    int amtTimesRan = 0;
    double Output;
    double I;
    double lastError;
    bot.LTar = InchesToDegrees(distance) + bot.LDeg;
    bot.RTar = InchesToDegrees(distance) + bot.RDeg;
    bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;

    while(bot.error >= ATtolerance && !bot.failed && amtTimesRan <= 3){
        bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;
        I=(I+bot.error) * 0;
        Output = (bot.error * kP) + I + ((bot.error - lastError)*D);
        MoveAllMotors(Output);
        if (bot.error <= -ATtolerance/2){//the ATtolerance if +15 - -15 motor deg, hence the /2
            bot.failed = true;
        }else if (bot.error < ATtolerance/2){
            amtTimesRan++;
        }
        lastError = bot.error;
    }

    if (bot.failed){
        return false; //failed, make the tester roll back then go finer
    }else{
        return true;//passed, up the amount
    }
}

bool ForwardITest(float distance,double i){//typically in alot of my code, a lowercase standalone variable is the "un proccesed" version of the variable

    double Output;
    double I;
    double lastError;
    bot.LTar = InchesToDegrees(distance) + bot.LDeg;
    bot.RTar = InchesToDegrees(distance) + bot.RDeg;
    bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;

    while(bot.error >= ATtolerance && !bot.failed){
        bot.error = ((bot.LTar - bot.LDeg) + (bot.RTar - bot.LDeg))/2;
        I=(I+bot.error) * i;
        Output = (bot.error * kP) + I + ((bot.error - lastError)*kD);
        MoveAllMotors(Output);
        if (bot.error >= -(ATtolerance)){
            bot.failed = true;
        }
        lastError = bot.error;
    }
    if (bot.failed){
        return false; //failed, make the tester roll back twice then go finer
    }else{
        return true;//passed, up the amount
    }
}
extern void AutoTune(){//start with P then move to D then I
    double minP = 1;
    bool GotPValue = false;
    double TestingP;
    double LastP;
    double Adder = 10;//how much to add to each variable per their test run
    while (bot.RDeg < InchesToDegrees(5)){
        //P tuning/KickStarter
        //get the lowest value for P possible

        //motor.move_voltage(minP*5);//5 for the lowest number tested, as the error gets higher, so will the output
        MoveAllMotors(minP);
        minP += 1;
    }
    TestingP = minP;
    while (!GotPValue){
        if(ForwardPTest(10,TestingP)&&ForwardPTest(5,TestingP)&&ForwardPTest(15,TestingP)){
            TestingP = LastP + Adder;
        }else{
            if(Adder < 1){
                GotPValue = true;//exiting loop
                
            }else{
                Adder = Adder/10; //10, 1, 0.1
                TestingP = -(Adder);
            }
        }
        kP = TestingP;
        LastP = TestingP;
    }
    kP = LastP;
    Adder = 1;//for D setup

    bool GotDValue = false;
    double TestingD;
    double LastD;
    while (!GotDValue){
        if(ForwardDTest(10,TestingD)&&ForwardDTest(5,TestingD)&&ForwardDTest(15,TestingD)){
            TestingD = LastD + Adder;
        }else{
            if(Adder < 1){
                GotDValue = true;//exiting loop
                
            }else{
                Adder = Adder/10; // 1, 0.1, 0.01
                TestingD = -(Adder);
            }
        }
        kD = TestingD;

        LastD = TestingD;
    }
    kD = LastD;

    Adder = 0.1;// for I
    bool GotIValue = false;
    double TestingI;
    double LastI;
    while (!GotIValue){
        if(ForwardITest(10,TestingI)&&ForwardITest(10,TestingI)){//twice, to ensure reliability as the I multiplier can be hectic
            TestingI = LastI + Adder;
        }else{
            if(Adder < 0.01){
                GotIValue = true;//exiting loop
                
            }else{
                Adder = Adder/10; //0.1, 0.01,0.001
                TestingI = -(Adder);
            }
        }
        kI = TestingI;
        LastI = TestingI;
    }

    if (GotPValue && GotIValue && GotDValue){
        Adder = 20;
        bool Break = false;
        while (Adder < 150 && !Break){//the auton line is around 144 inches, 
            if(ForwardITest(Adder,kI)){ //using I, becuse the P and D are already known when testing for I
                MaxWorkingDistance = Adder;
                Adder += 10;
            }else{
                Break = true;
            }
        }// its generally fine if these break, as at least the MinDistance is. the max is more or less needed for MOGO rush
        MaxWorkingDistance = Adder - 10;
        Adder = 5;
        Break = false;
        while (Adder > 0 && !Break){
            if (ForwardITest(Adder,kI)){
                MinWorkingDistance = Adder;
                Adder = Adder - 0.2;
            }else {
                Break = true;
            }
        }
    }
}
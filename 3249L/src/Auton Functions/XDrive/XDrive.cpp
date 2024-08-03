#include "main.h"

void Bot::XDriveRelativeForward(float Distance){
    double Output;
    double I;
    double lastError;
    bot.LTar = InchesToDegrees(Distance) + bot.LDeg;
    bot.error = (bot.LTar - bot.LDeg);

    while(bot.error >= Tolerance && !bot.failed){
        bot.error = (bot.LTar - bot.LDeg);
        I=(I+bot.error) * kI;
        Output = (bot.error * kP) + I + ((bot.error - lastError)*kD);
        lastError = error;
        
        }
}
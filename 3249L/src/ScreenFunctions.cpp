#include "main.h"
#include "pros/colors.h"
unsigned long long int Timer = 0;
int Customclock(){
  pros::delay(1);
  Timer++;
  return Timer;
}

void ShowScreen(){
  uint8_t WhichStats; //Context based stats
    /*
  0 = basic
  1 = Ben Mode (semi Nerd)
  2 = PID Debuging/Very Nerd
  3 = Pure Pursuit Debugging / all options
  */
  const static uint8_t FrameRate = 59; //59 as i dunno how to enable V-Sync, and these brains have bad tearing
  int TimePast = 0;
  int InitialTime = 0;



    //pros::screen::print(pros::TEXT_MEDIUM, 3, "Seconds Passed: %3d", i++);
      while (pros::competition::is_autonomous()) {
        InitialTime = clock();

            pros::screen::set_pen(0x0);//set pen color
            pros::screen::fill_rect(1,1,480,240); // this is after auton is selected... fills entire screen
            pros::screen::set_pen(0x00FFFFFF);//set pen color

        pros::delay((1000/FrameRate)-TimePast);

        pros::screen::set_pen(0x082c54);//hear me out
        pros::screen::fill_rect(1,1,480,240);
        pros::screen::set_pen(0xffffff);

        if(WhichStats == 0){ // the everyone can read mode
        pros::screen::print(pros::E_TEXT_SMALL,2,"X:%3d, Y:%3d",bot.x,bot.y);
        pros::screen::print(pros::E_TEXT_SMALL,4,"Heading:%3d",bot.Heading);
        pros::screen::print(pros::E_TEXT_SMALL,6,"FPS:%3d",1000/((1000/FrameRate)-TimePast));

        }else if (WhichStats == 1){//nerdy stuff
          pros::screen::print(pros::E_TEXT_SMALL,1,"X:%3d, Y:%3d",bot.x,bot.y);
          pros::screen::print(pros::E_TEXT_SMALL,2,"LeftDeg:%3d, RightDeg:%3d",bot.LDeg,bot.RDeg);
          pros::screen::print(pros::E_TEXT_SMALL,3,"Heading:%3d",bot.Heading);
          pros::screen::print(pros::E_TEXT_SMALL,4,"Error:%3d",bot.error);
          pros::screen::print(pros::E_TEXT_SMALL,5,"LeftDis:%3d, RightDis:%3d",bot.LDis,bot.RDis);
          pros::screen::print(pros::E_TEXT_SMALL,6,"Time Between Clocks:%3d",TimePast);
          pros::screen::print(pros::E_TEXT_SMALL,7,"FPS:%3d",1000/((1000/FrameRate)-TimePast));
          

        }else if (WhichStats == 2){//PID test / really nerdy
          pros::screen::print(pros::E_TEXT_SMALL,1,"X:%3d, Y:%3d",bot.x,bot.y);
          pros::screen::print(pros::E_TEXT_SMALL,2,"LeftDeg:%3d, RightDeg:%3d",bot.LDeg,bot.RDeg);
          pros::screen::print(pros::E_TEXT_SMALL,3,"Heading:%3d",bot.Heading);
          pros::screen::print(pros::E_TEXT_SMALL,4,"Error:%3d",bot.error);
          pros::screen::print(pros::E_TEXT_SMALL,5,"LeftDis:%3d, RightDis:%3d",bot.LDis,bot.RDis);
          pros::screen::print(pros::E_TEXT_SMALL,6,"ForwardTar%3d, RotateTar:%3d",bot.LTar,bot.RTar);
          pros::screen::print(pros::E_TEXT_SMALL,7,"FPS:%3d",1000/((1000/FrameRate)-TimePast));
          pros::screen::print(pros::E_TEXT_SMALL,8,"Time Between Clocks:%3d",TimePast);

        }else{//why have some when you can have ALL of them 
          pros::screen::print(pros::E_TEXT_SMALL,1,"X:%3d, Y:%3d",bot.x,bot.y);
          pros::screen::print(pros::E_TEXT_SMALL,2,"LeftDeg:%3d, RightDeg:%3d",bot.LDeg,bot.RDeg);
          pros::screen::print(pros::E_TEXT_SMALL,3,"Heading:%3d",bot.Heading);
          pros::screen::print(pros::E_TEXT_SMALL,4,"Error:%3d",bot.error);
          pros::screen::print(pros::E_TEXT_SMALL,5,"LeftDis:%3d, RightDis:%3d",bot.LDis,bot.RDis);
          pros::screen::print(pros::E_TEXT_SMALL,6,"ForwardTar%3d, RotateTar:%3d",bot.LTar,bot.RTar);
          pros::screen::print(pros::E_TEXT_SMALL,7,"FPS:%3d",1000/((1000/FrameRate)-TimePast));
          pros::screen::print(pros::E_TEXT_SMALL,8,"Time Between Clocks:%3d",TimePast);

        }
          if(bot.failed){
          pros::screen::print(pros::E_TEXT_SMALL,9,"Did PurePursuit fail?");
          pros::screen::set_pen(0xff0000);
          pros::screen::fill_rect(400,0,480,120);//covers small part, so itll be eaily known if pure pursuit fails
          pros::screen::set_pen(0xffffff);
        }else{
          pros::screen::set_pen(0xffff00);
          pros::screen::fill_rect(400,0,480,120);//we chillin
          pros::screen::set_pen(0xffffff);
        }
        if (bot.PurePursuit){
          pros::screen::print(pros::E_TEXT_SMALL,11,"Is PurePursuit on?");
          pros::screen::set_pen(0xff0000);
          pros::screen::fill_rect(400,121,480,240);//covers small part, so itll be eaily known if pure pursuit fails
          pros::screen::set_pen(0xffffff);
        }else{
          pros::screen::set_pen(0xffff00);
          pros::screen::fill_rect(400,121,480,240);//we chillin
          pros::screen::set_pen(0xffffff);
        }

     TimePast = clock() - InitialTime;// tries to run V-Sync  
  }

}
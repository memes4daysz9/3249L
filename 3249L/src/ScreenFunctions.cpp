#include "main.h"
#include "pros/colors.h"
unsigned long long int Timer = 0;
int Customclock()
{
  pros::delay(1);
  Timer++;
  return Timer;
}
void on_center_button()
{
  static bool pressed = false;
  pressed = !pressed;
  if (pressed)
  {
    pros::lcd::set_text(2, "I was pressed!");
  }
  else
  {
    pros::lcd::clear_line(2);
  }
}
// Needle needle;
void ShowScreen()
{
  uint8_t WhichStats = 3; // Context based stats
  /*
0 = basic, whith cool visualizations
1 = Ben Mode (semi Nerd)
2 = PID Debuging/Very Nerd
3 = Pure Pursuit Debugging / all options
*/

  uint8_t WhichModes; // Context based Screen
  /*
  0 = Initializing
  1 = Auton
  2 = Driver
  3 = Post Game
  */
  pros::Motor Left(5); // odom
  pros::Motor Right(6);

  const static uint_fast8_t FrameRate = 10;
  int TimePast = 0;
  int InitialTime = 0;
  /*Needle Speed;
  Speed.ID = 0;
  Speed.max = 600;
  Speed.Radius = 10;
  int16_t x = 10;
  int16_t y = 10;
  Speed.X[0] = x;// alot of these are place holders
  Speed.Y[0] = y;
  Speed.Data = 0;
  needle.InitDial(Speed);
  //Tempurture dial
  Needle Temp;
  Temp.ID = 1;
  Temp.max = 54;//thats when the temp is about to start throttling the motor
  Temp.Radius = 10;
  Temp.Data = 0;
  Temp.X[0] = x;// alot of these are place holders
  Temp.Y[0] = y;
  needle.InitDial(Temp);
  */
  pros::screen::set_pen(0x001e56); // hear me out
  pros::screen::fill_rect(1, 1, 480, 240);
  pros::screen::set_pen(0xffffff);
  while (true)
  {
    /*if (bot.Interupt){
      pros::screen::set_pen(0x001e56); // hear me out
      pros::screen::fill_rect(1, 1, 480, 240);
      pros::screen::set_pen(0xff0000);
      pros::screen::print(pros::E_TEXT_LARGE, 2, "ERROR! Error code: %3d-%3d",bot.ErrorCode,bot.ErrorSector);
      pros::screen::print(pros::E_TEXT_MEDIUM, 4, "BOT INTERUPTED");
    }*/
    InitialTime = clock();
    pros::lcd::register_btn1_cb(on_center_button);
    /*pros::screen::set_pen(0x0);//set pen color
    pros::screen::fill_rect(1,1,480,240);
    pros::screen::set_pen(0x00FFFFFF);//set pen color
    */

    pros::delay((1000 / FrameRate) - TimePast);
    // pros::delay(500);
    // pros::screen::print(pros::TEXT_MEDIUM, 3, "Seconds Passed: %3d", i++);
    if (WhichModes = 1)
    {

      if (WhichStats == 0)
      { // the everyone can read mode
        // Needles[Speed.ID].Data = (Left.get_actual_velocity() + Right.get_actual_velocity()) / 2;//updates the data for the area

        pros::screen::print(pros::E_TEXT_SMALL, 2, "X:%3d, Y:%3d", bot.x, bot.y);
        pros::screen::print(pros::E_TEXT_SMALL, 4, "Heading:%3d", bot.Heading);
        pros::screen::print(pros::E_TEXT_SMALL, 6, "FPS:%3d", 1000 / ((1000 / FrameRate) - TimePast));
        pros::screen::print(pros::E_TEXT_SMALL, 8, "Frame Time:%3d", (1000 / FrameRate) - TimePast);
        // needle.UpdateDial(Speed.ID);
        // needle.UpdateDial(Temp.ID);
      }
      else if (WhichStats == 1)
      { // nerdy stuff
        pros::screen::print(pros::E_TEXT_SMALL, 1, "X:%3d, Y:%3d", bot.x, bot.y);
        pros::screen::print(pros::E_TEXT_SMALL, 2, "LeftDeg:%3d, RightDeg:%3d", bot.LDeg, bot.RDeg);
        pros::screen::print(pros::E_TEXT_SMALL, 3, "Heading:%3d", bot.Heading);
        pros::screen::print(pros::E_TEXT_SMALL, 4, "Error:%3d", bot.error);
        pros::screen::print(pros::E_TEXT_SMALL, 5, "LeftDis:%3d, RightDis:%3d", bot.LDis, bot.RDis);
        pros::screen::print(pros::E_TEXT_SMALL, 6, "Time Between Clocks:%3d", TimePast * 100);
        pros::screen::print(pros::E_TEXT_SMALL, 7, "FPS:%3d", 1000 / ((1000 / FrameRate) - TimePast));
      }
      else if (WhichStats == 2)
      { // PID test / really nerdy
        pros::screen::print(pros::E_TEXT_SMALL, 1, "X:%3d, Y:%3d", bot.x, bot.y);
        pros::screen::print(pros::E_TEXT_SMALL, 2, "LeftDeg:%3d, RightDeg:%3d", bot.LDeg, bot.RDeg);
        pros::screen::print(pros::E_TEXT_SMALL, 3, "Heading:%3d", bot.Heading);
        pros::screen::print(pros::E_TEXT_SMALL, 4, "Error:%3d", bot.error);
        pros::screen::print(pros::E_TEXT_SMALL, 5, "LeftDis:%3d, RightDis:%3d", bot.LDis, bot.RDis);
        pros::screen::print(pros::E_TEXT_SMALL, 6, "ForwardTar%3d, RotateTar:%3d", bot.LTar, bot.RTar);
        pros::screen::print(pros::E_TEXT_SMALL, 7, "FPS:%3d", 1000 / ((1000 / FrameRate) - TimePast));
        pros::screen::print(pros::E_TEXT_SMALL, 8, "Time Between Clocks:%3d", TimePast);
      }
      else if (WhichStats = 3)
      { // why have some when you can have ALL of them
        pros::screen::print(pros::E_TEXT_SMALL, 1, "X:%f, Y:%f", bot.x, bot.y);
        //pros::screen::print(pros::E_TEXT_SMALL, 2, "LeftDeg:%f, RightDeg:%f, XDeg:%f", bot.LDeg, bot.RDeg, bot.XDeg);
        pros::screen::print(pros::E_TEXT_SMALL, 3, "Heading:%f", bot.Heading);
        pros::screen::print(pros::E_TEXT_SMALL, 4, "Error:%f", bot.error);
        pros::screen::print(pros::E_TEXT_SMALL, 5, "LeftDis:%f, RightDis:%f", bot.LDis, bot.RDis);
        pros::screen::print(pros::E_TEXT_SMALL, 6, "ForwardTar%f, RotateTar:%f", bot.LTar, bot.RTar);
        pros::screen::print(pros::E_TEXT_SMALL, 7, "FPS:%3d", 1000 / ((1000 / FrameRate) - TimePast));
        pros::screen::print(pros::E_TEXT_SMALL, 8, "Time Between Clocks:%3d", TimePast);
        pros::screen::print(pros::E_TEXT_SMALL, 9, "Average Temp: %3d", bot.MaxTemp);
      }
      if (bot.failed)
      {
        pros::screen::print(pros::E_TEXT_SMALL, 9, "Did PurePursuit fail?");
        pros::screen::set_pen(0xff0000);
        pros::screen::fill_rect(400, 0, 480, 120); // covers small part, so itll be eaily known if pure pursuit fails
        pros::screen::set_pen(0xffffff);
      }
      else
      {
        pros::screen::set_pen(0xffff00);
        pros::screen::fill_rect(400, 0, 480, 120); // we chillin
        pros::screen::set_pen(0xffffff);
      }
      if (bot.PurePursuit)
      {
        pros::screen::print(pros::E_TEXT_SMALL, 11, "Is PurePursuit on?");
        pros::screen::set_pen(0xff0000);
        pros::screen::fill_rect(400, 121, 480, 240); // covers small part, so itll be eaily known if pure pursuit fails
        pros::screen::set_pen(0xffffff);
      }
      else
      {
        pros::screen::set_pen(0xffff00);
        pros::screen::fill_rect(400, 121, 480, 240); // we chillin
        pros::screen::set_pen(0xffffff);
      }
    }
    else if (WhichModes = 2)
    { // driver
      // Temp Dial
      // Speed Dial
      // Intake Mode
    }
    TimePast = clock() - InitialTime; // tries to run V-Sync
  }
}
#include "main.h"

void ShowScreen(){
      while (pros::competition::is_autonomous()) {
        pros::screen::set_pen(0x082c54);//hear me out
        pros::screen::fill_rect(1,1,480,240);
        
  }

}

#include "main.h"

bool ProgressBar::initBar(ProgressBar CurBar){
    UpdateBar(CurBar.ID);
    
}
int GetBarID(ProgressBar BarToGet){
    for(int i = 0;i<13;i++){
        if (Bars[i].ID== BarToGet.ID){
            return i;
        }
    }
}
bool UpdateBar(int BarID){
    int X[1];
    int Y[1];
    float Difference;
    float D1;
        if(Bars[BarID].Data > Bars[BarID].min){//helps some optimizting
            X[0] = Bars[BarID].X[0];//knowns
            Y[0] = Bars[BarID].Y[0];
            X[1] = Bars[BarID].X[1];//array supreme
            Y[1] = Bars[BarID].Y[1];
            if (Bars[BarID].Data > Bars[BarID].max){
                pros::screen::fill_rect(X[0],Y[0],X[1],Y[1]);
            }else{
                //clear the area with a backround color
            D1 = Bars[BarID].Data/Bars[BarID].max;
            //get the four positions needed to make a filled rectangle
            
            pros::screen::fill_rect(X[0],Y[0],X[0]+D1*(X[1]-X[0]),Y[1]);
            //fill Rectangle
            }

        }
}
bool UpdateAllBars(){
    int X[3];
    int Y[3];
    int XR[1];
    int YR[1];//Y value Rectangle to use
    float Difference;
    float D1;


    for(int i = 0; i < 13;i++){
        if(Bars[i].Data > Bars[i].min){//helps some optimizting
            X[0] = Bars[i].X[0];//knowns
            Y[0] = Bars[i].Y[0];
            X[1] = Bars[i].X[1];//array supreme
            Y[1] = Bars[i].Y[1];
            if (Bars[i].Data > Bars[i].max){
                pros::screen::fill_rect(X[0],Y[0],X[1],Y[1]);
            }else{
                //clear the area with a backround color
            D1 = Bars[i].Data/Bars[i].max;
            //get the four positions needed to make a filled rectangle
            
            XR[0] = X[0];
            XR[1] = D1 * X[1];
            pros::screen::fill_rect(X[0],Y[0],X[0]+D1*(X[1]-X[0]),Y[1]);
            //fill Rectangle
            }

        }

       }
}
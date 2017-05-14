#include "graphics.hpp"
#include "formWidget.hpp"
#include "iostream"
using namespace std;
using namespace genv;


formWidget::formWidget(Window* w,int px,int py, int sx, int sy):
 _px(px),_py(py),_sx(sx),_sy(sy)
{
    parent = w;
    isActive = false;
    isHovered = false;
}

bool formWidget::isMouseOverWidget(genv::event ev){
    bool active = false;
    if(ev.pos_x >= _px && ev.pos_x <= _px+_sx && ev.pos_y > _py && ev.pos_y <= _py+_sy){
        active = true;
        isHovered = active;
    }else{
        active = false;
    }
    if(ev.button == btn_left){
        isActive = active;
        return isActive;
    }
 /*   if(ev.type == ev_mouse){
        isHovered = active;
    }*/

}

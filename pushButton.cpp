#include "pushButton.hpp"
#include "formWidget.hpp"
#include "window.hpp"
#include "graphics.hpp"
using namespace genv;
pushButton::pushButton(Window *w,int x, int y, int sx, int sy,string buttontext, string ID)
:formWidget(w,x,y,sx,sy){
    parent = w;
   currentValue = buttontext;
   eventID = ID;
}

void pushButton::draw() const
{
    canvas c;
    c.open(_sx, _sy);
    c.load_font("LiberationSans-Regular.ttf", 15);

    c<<move_to(0,0)<<box(_sx,_sy);

    c << move_to(2,2) << color(0,0,0) << box(_sx-4, _sy-4);
    c<<move_to(15,15)<<color(255,255,255)<<text(currentValue);
    gout << stamp(c, _px, _py);
}

void pushButton::handle(genv::event ev){
    if(isActive && ev.button == btn_left){
        buttonClick();
    }
}

bool pushButton::isWidgetMouseOver(genv::event ev){
    if(ev.pos_x >= _px && ev.pos_x <= _px+_sx && ev.pos_y > _py && ev.pos_y <= _py+_sy){
        isActive = true;
        return true;
    }else{
        isActive = false;
        return false;
    }
}
void pushButton::buttonClick()const {
    parent->esemeny(eventID);
}

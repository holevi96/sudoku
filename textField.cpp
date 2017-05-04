#include "formWidget.hpp"
#include "graphics.hpp"
#include "textField.hpp"
using namespace std;
using namespace genv;

textField::textField(Window *w,int x, int y, int sx, int sy,string t):
    formWidget(w,x,y,sx,sy)
{
    currentValue = t;
}

void textField::draw() const
{

    canvas c;
    c.open(_sx, _sy);
    c.load_font("LiberationSans-Regular.ttf", 15);
    if(isActive){
        c<<color(255,0,0);
    }else{
        gout<<color(255,255,255);
    }
    c<<move_to(0,0)<<box(_sx,_sy);
    c << move_to(2,2) << color(0,0,0) << box(_sx-4, _sy-4);
    c<<move_to(15,15)<<color(255,255,255)<<text(currentValue);
    gout << stamp(c, _px, _py);
}
void textField::handle(genv::event ev){

    if(gout.twidth(currentValue) <= _sx-40){
        if(ev.type==ev_key && ev.keycode>31 && ev.keycode<256){
                currentValue+=ev.keycode;
        }
    }
        if(ev.keycode == key_backspace) currentValue = currentValue.substr(0, currentValue.size()-1);

}

bool textField::isWidgetMouseOver(genv::event ev){
    if(ev.pos_x >= _px && ev.pos_x <= _px+_sx && ev.pos_y > _py && ev.pos_y <= _py+_sy){
        isActive = true;
        return true;
    }else{
        isActive = false;
        return false;
    }
}

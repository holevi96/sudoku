#include <sstream>
#include "formWidget.hpp"
#include "numberField.hpp"
#include "window.hpp"
#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;
using namespace genv;
numberField::numberField(Window* w,int px,int py, int sx, int sy, int mn ,int mx, int numberFieldValue):
    formWidget(w, px, py,  sx,  sy),minimum(mn),maximum(mx),numberFieldValue(numberFieldValue)
{

}
void numberField::incrementValue(int n){
    if(numberFieldValue + n <= maximum && numberFieldValue+n >= minimum) numberFieldValue+=n;
}
bool numberField::isUpClicked(int x, int y,int sx,int sy) const {
    return (x<=sx&&x>=sx-30&&y<=sy/2&&y>=0);
}
bool numberField::isDownClicked(int x, int y,int sx,int sy) const {
    return (x<=sx&&x>=sx-30&&y<=sy&&y>=sy/2);
}
void numberField::handle(genv::event ev){
    int mx = ev.pos_x - _px;
    int my = ev.pos_y - _py;
    if(ev.button == btn_left){
        if(isUpClicked(mx,my,_sx,_sy)){
          incrementValue(1);
        }
        if(isDownClicked(mx,my,_sx,_sy)) incrementValue(-1);
    }
    if(ev.keycode == key_up && isActive) incrementValue(1);
    if(ev.keycode == key_down && isActive) incrementValue(-1);
    if(ev.keycode == key_pgdn && isActive) incrementValue(-10);
    if(ev.keycode == key_pgup && isActive) incrementValue(10);
}
void numberField::draw() const{

    canvas c;
    c.open(_sx, _sy);
    c.load_font("LiberationSans-Regular.ttf", 15);
    c<<color(255,255,255);
    c<<move_to(0,0)<<box(_sx,_sy)<<move_to(2,2)<<color(0,0,0)<<box(_sx-4,_sy-4);
    c<<move_to(15,15)<<color(255,255,255)<<text(getNumberFieldValueString());
    c<<move_to(_sx-30,0)<<box(30,_sy/2)<<move_to(_sx-26,18)<<color(0,0,0)<<line(11,-11)<<line(11,11)<<color(255,255,255);
    c<<move_to(_sx-30,_sy/2)<<box(30,_sy/2)<<move_to(_sx-26,_sy/2+(_sy/2-18))<<color(0,0,0)<<line(11,11)<<line(11,-11);
    c<<move_to(_sx-26,_sy/2)<<color(0,0,0)<<line(22,0);
    gout << stamp(c, _px, _py);
}

int numberField::getNumberFieldValue() const{
        return numberFieldValue;
}
string numberField::getNumberFieldValueString()const{
    stringstream ss;
    ss<<numberFieldValue;
    return ss.str();
}

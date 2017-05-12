#include "sudokuNumberField.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;

sudokuNumberField::sudokuNumberField(Window* w,int px,int py, int sx, int sy, int minimum ,int maximum, int numberFieldValue):
    numberField(w,px,py,sx,sy,minimum,maximum,numberFieldValue){

}

void sudokuNumberField::draw() const{
    canvas c;
    c.open(_sx, _sy);
    c.load_font("LiberationSans-Regular.ttf", 20);

    c<<color(255,255,255);
    c<<move_to(0,0)<<box(_sx,_sy)<<move_to(2,2)<<color(0,0,0)<<box(_sx-4,_sy-4);
    c<<move_to(15,15)<<color(255,255,255)<<text(getNumberFieldValueString());
    if(isHovered){
        c<<move_to(_sx-30,0)<<box(30,_sy/2)<<move_to(_sx-26,18)<<color(0,0,0)<<line(11,-11)<<line(11,11)<<color(255,255,255);
        c<<move_to(_sx-30,_sy/2)<<box(30,_sy/2)<<move_to(_sx-26,_sy/2+(_sy/2-18))<<color(0,0,0)<<line(11,11)<<line(11,-11);
        c<<move_to(_sx-26,_sy/2)<<color(0,0,0)<<line(22,0);
    }

    gout << stamp(c, _px, _py);
}

void sudokuNumberField::handle(genv::event ev){
    int mx = ev.pos_x - _px;
    int my = ev.pos_y - _py;
    if(ev.button == btn_left){
        if(isUpClicked(mx,my,_sx,_sy)){
          changeValue(1);
        }
        if(isDownClicked(mx,my,_sx,_sy)) changeValue(-1);
    }
    if(ev.keycode == key_up && isActive) changeValue(1);
    if(ev.keycode == key_down && isActive) changeValue(-1);
    if(ev.keycode == key_pgdn && isActive) changeValue(-10);
    if(ev.keycode == key_pgup && isActive) changeValue(10);
}

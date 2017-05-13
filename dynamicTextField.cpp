#include "formWidget.hpp"
#include "graphics.hpp"
#include "dynamicTextField.hpp"
#include "staticText.hpp"
using namespace std;
using namespace genv;

dynamicTextField::dynamicTextField(Window *w,int x, int y, int sx, int sy,string t):
    StaticText(w,x,y,sx,sy,t)
{
}

void dynamicTextField::draw() const
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
    c<<move_to(15,15)<<color(255,255,255)<<text(textFieldValue);
    gout << stamp(c, _px, _py);
}
void dynamicTextField::handle(genv::event ev){

    if(gout.twidth(textFieldValue) <= _sx-40){
        if(ev.type==ev_key && ev.keycode>31 && ev.keycode<256){
                textFieldValue+=ev.keycode;
        }
    }
        if(ev.keycode == key_backspace){
            if(textFieldValue.length() != 1){
                textFieldValue = textFieldValue.substr(0, textFieldValue.size()-1);
            }else{
                textFieldValue = " ";
            }
        }

}

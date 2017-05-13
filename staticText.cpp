#include "formWidget.hpp"
#include "graphics.hpp"
#include "dynamicTextField.hpp"
using namespace std;
using namespace genv;

StaticText::StaticText(Window *w,int x, int y, int sx, int sy,string t):
    formWidget(w,x,y,sx,sy)
{
    textFieldValue = t;

}

void StaticText::draw() const
{

    canvas c;
    c.open(_sx, _sy);
    c.load_font("LiberationSans-Regular.ttf", 15);

    c<<move_to(0,0)<<box(_sx,_sy);
    c << move_to(2,2) << color(0,0,0) << box(_sx-4, _sy-4);
    c<<move_to(15,15)<<color(255,255,255)<<text(textFieldValue);
    gout << stamp(c, _px, _py);
}
void StaticText::handle(genv::event ev){
}


void StaticText::setText(string t){
    textFieldValue = t;
}
string StaticText::getText(){
    return textFieldValue;
}

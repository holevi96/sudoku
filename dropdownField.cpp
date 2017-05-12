#include <sstream>
#include "formWidget.hpp"
#include "dropdownField.hpp"
#include "graphics.hpp"
#include <vector>
#include <iostream>
using namespace std;
using namespace genv;
dropDownField::dropDownField(Window *w,int px,int py, int sx, int sy, vector<string> op,int maxoptions):
    formWidget(w, px, py,  sx,  sy),activeOptionIndex(0),isOpened(false),scrollTop(0),maxOptions(maxoptions)
{

    /*if(op.size() < maxoptions){
        maxOptions = op.size();
    }*/
    if(op.size() == 0){
        isEmpty = true;
       // currentValue = "No entries.";
    }else{
        //currentValue = op[0];
        for(auto e : op){
            addOption(e);
        }
    }

   // cout<<options.size()<<endl;
}


void dropDownField::addOption(string o){
    options.push_back(o);
    isEmpty = false;
    scrollerSize = (_sy*maxOptions-60)*((double)maxOptions/options.size());
    //currentValue = o;
    activeOptionIndex = options.size()-1;


}
void dropDownField::removeSelected(){
    options.erase(options.begin() + activeOptionIndex);
    if(options.size() != 0){
            activeOptionIndex = 0;
       // currentValue = options[0];
    }else{
        isEmpty = true;
        //currentValue = "No entries.";
    }
}

bool dropDownField::isElementClicked(int x,int y) const{
     return (x>=0&&x<_sx-30&&y<=_sy*(maxOptions+1)&&y>=_sy);
}
bool dropDownField::isOpenerClicked(int x, int y) const {
    return (x<=_sx&&x>=_sx-30&&y<=_sy&&y>=0);
}
bool dropDownField::isScrollBarUpClicked(int x,int y) const{
    return (x>_sx-25&&x<=_sx-5&&y>_sy+5&&y<=_sy+25);
}
bool dropDownField::isScrollBarDownClicked(int x,int y) const{

    return (x>_sx-25&&x<=_sx-5&&y>_sy*maxOptions-25&&y<=_sy*options.size()-5);
}
void dropDownField::scroll(int n){
    if(scrollTop+n <= options.size()-maxOptions && scrollTop+n >=0 && options.size() > maxOptions){
        scrollTop+=n;
    }
}
void dropDownField::handle(genv::event ev){
    int mx = ev.pos_x - _px;
    int my = ev.pos_y - _py;

     if(ev.button == btn_left){

        if(isElementClicked(mx,my)){
            activeOptionIndex = elementIndex(my);
            //currentValue = options[activeOptionIndex];
            isOpened = false;
            isActive = false;
        }
        if(isOpenerClicked(mx,my)){
            isOpened = !isOpened;
        }

        if(isScrollBarDownClicked(mx,my)){
                scroll(1);
        }
        if(isScrollBarUpClicked(mx,my)){
                scroll(-1);
        }

    }
    if(ev.button == btn_wheeldown && isActive) scroll(1);
    if(ev.button == btn_wheelup && isActive) scroll(-1);
}
int dropDownField::elementIndex(int y) const{

    return (int)y/_sy -1 + scrollTop;
}
void dropDownField::draw() const
{
    canvas c;
    c.open(_sx, _sy+maxOptions*_sy);
    c.load_font("LiberationSans-Regular.ttf", 13);
    c.transparent(true);
    //az épp kiválasztott elem kirajzolása

    c<<color(255,255,255);
    c<<move_to(0,0)<<box(_sx,_sy)<<move_to(2,2)<<color(0,0,0)<<box(_sx-4,_sy-4);
    string currentText;
    if(options.size()>0){
        currentText = options[activeOptionIndex];
    }else{
        currentText = "No entries.";
    }
    c<<move_to(15,15)<<color(255,255,255)<<text(currentText);
    //a lenyitó nyilacska kirajzolása
    c<<move_to(_sx-30,0)<<color(255,255,255)<<box(30,_sy);
    c<<move_to(_sx-26,(_sy/2-5))<<color(0,0,0)<<line(11,11)<<line(11,-11);

    // a nyitott panel kirajzolása
    if(isOpened && isActive && !isEmpty)
    {
        c.transparent(false);

        //a scrollbar kirajzolása
        if(options.size() > maxOptions){
            c<<move_to(_sx-20,_sy+30+(scrollerSize*scrollTop/maxOptions))<<color(255,255,255)<<box(5,scrollerSize);
            //scrollbar nyil boxok kirajzolása
            c<<move_to(_sx-25,_sy+5)<<color(255,255,255)<<box(20,20)<<color(0,0,0)<<genv::move(-4,-6)<<line(-7,-7)<<line(-7,7);
            c<<move_to(_sx-25,_sy*(maxOptions+1)-25)<<color(255,255,255)<<box(20,20)<<color(0,0,0)<<genv::move(-4,-12)<<line(-7,7)<<line(-7,-7);;
        }
        int b,col;
        //a menüpontok kirajzolása
        int j = 0;
        int iterNumber;
        if(options.size()<maxOptions){
            iterNumber = options.size();
        }else{
            iterNumber = maxOptions;
        }
        for(int i=scrollTop; i<scrollTop+iterNumber; i++)
        {
            if(i == activeOptionIndex)
            {
                b = 255;
                col = 0;
            }
            else
            {
                b = 0;
                col = 255;
            }
            c<<move_to(0,(j+1)*_sy);
            c<<color(255,255,255)<<box(_sx-30,_sy);
            c<<move_to(2,((j+1)*_sy)+2)<<color(b,b,b)<<box(_sx-4-30,_sy-4);
            c<<move_to(15,((j+1)*_sy)+15)<<color(col,col,col)<<text(options[i]);
            j++;
        }
    }
    gout << stamp(c, _px, _py);
}

bool dropDownField::isMouseOverWidget(genv::event ev){
     bool felt;
if(isOpened){
    felt = ev.pos_x >= _px && ev.pos_x <= _px+_sx && ev.pos_y > _py && ev.pos_y <= _py+_sy*(maxOptions+1);
}else{
    felt = ev.pos_x >= _px && ev.pos_x <= _px+_sx && ev.pos_y > _py && ev.pos_y <= _py+_sy;
}
    if(felt){
        isActive = true;
        return true;
    }else{
        isActive = false;
        isOpened = false;
        return false;
    }
}

string dropDownField::getSelectedOption() const{
    return options[activeOptionIndex];
}

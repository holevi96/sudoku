#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED

#include "formWidget.hpp"
#include "window.hpp"
using namespace std;

class pushButton : public formWidget{

    string eventID;
    public:
    pushButton(Window *w,int x, int y, int sx, int sy,string buttontext, string ID);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual bool isWidgetMouseOver(genv::event ev);
    void buttonClick() const;

};

#endif // PUSHBUTTON_HPP_INCLUDED

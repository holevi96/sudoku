#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED

#include "formWidget.hpp"
#include "window.hpp"
using namespace std;

class pushButton : public formWidget{
protected:
    string eventID,buttonText;
    bool isVisible;
    public:
    pushButton(Window *w,int x, int y, int sx, int sy,string buttontext, string ID);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    void buttonClick() const;
    void toggleEditable();

};

#endif // PUSHBUTTON_HPP_INCLUDED

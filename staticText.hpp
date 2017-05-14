#ifndef EXAMPLETEXTBOX_HPP_INCLUDED
#define EXAMPLETEXTBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "formWidget.hpp"

using namespace std;
class StaticText : public formWidget {
protected:
    string textFieldValue;
    public:
    StaticText(Window *w,int x, int y, int sx, int sy,string t);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    string getText();
     void setText(string t);
};


#endif // EXAMPLETEXTBOX_HPP_INCLUDED

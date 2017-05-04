#ifndef FORMWIDGET_HPP_INCLUDED
#define FORMWIDGET_HPP_INCLUDED
#include "graphics.hpp"
#include "window.hpp"
using namespace std;

class Window; // forward declaration;

class formWidget{
    protected:
        int _px,_py,_sx,_sy;
        string currentValue;
        bool isActive;
        Window* parent;
    public:
        formWidget(Window* w,int px,int py, int sx, int sy);
        virtual void handle(genv::event ev) = 0;
        virtual void draw() const {};
        virtual bool isWidgetMouseOver(genv::event ev)=0;
        string getValue();
};


#endif // FORMWIDGET_HPP_INCLUDED

#ifndef TEXTFIELD_HPP_INCLUDED
#define TEXTFIELD_HPP_INCLUDED
#include "formWidget.hpp"

using namespace std;
using namespace genv;
class textField : public formWidget{
    bool is_typing = false;
    public:
    textField(Window *w,int x, int y, int sx, int sy,string t);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
     virtual bool isWidgetMouseOver(genv::event ev);
};

#endif // TEXTFIELD_HPP_INCLUDED

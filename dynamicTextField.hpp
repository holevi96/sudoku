#ifndef TEXTFIELD_HPP_INCLUDED
#define TEXTFIELD_HPP_INCLUDED
#include "formWidget.hpp"
#include "staticText.hpp"
using namespace std;
using namespace genv;
class dynamicTextField : public StaticText{
    bool is_typing = false;
    public:
    dynamicTextField(Window *w,int x, int y, int sx, int sy,string t);
    virtual void draw() const ;
    virtual void handle(genv::event ev);

};

#endif // TEXTFIELD_HPP_INCLUDED

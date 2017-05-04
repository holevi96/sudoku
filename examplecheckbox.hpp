#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"

#include "formWidget.hpp"
class CheckBox : public formWidget {
protected:
    bool _checked;
public:
    CheckBox(Window* w,int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
      virtual bool isWidgetMouseOver(genv::event ev);
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED

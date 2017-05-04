#ifndef NUMBERFIELD_HPP_INCLUDED
#define NUMBERFIELD_HPP_INCLUDED
#include "formWidget.hpp"
#include "window.hpp"
class numberField : public formWidget{
protected:

    int minimum,maximum;
    public:
    numberField(Window* w,int px,int py, int sx, int sy, int minimum ,int maximum, int value);
    void changeValue(int n);
    virtual void handle(genv::event ev);
    virtual void draw() const;
    bool isUpClicked(int x, int y,int sx,int sy) const;
    bool isDownClicked(int x, int y,int sx,int sy) const;
    virtual bool isWidgetMouseOver(genv::event ev);
};
#endif // NUMBERFIELD_HPP_INCLUDED

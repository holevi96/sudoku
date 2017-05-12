#ifndef NUMBERFIELD_HPP_INCLUDED
#define NUMBERFIELD_HPP_INCLUDED
#include "formWidget.hpp"
#include "window.hpp"
class numberField : public formWidget{
protected:

    int minimum,maximum;
    int numberFieldValue;
    public:
    numberField(Window* w,int px,int py, int sx, int sy, int minimum ,int maximum, int numberFieldValue);
    virtual void changeValue(int n);
    virtual void handle(genv::event ev);
    virtual void draw() const;
    virtual bool isUpClicked(int x, int y,int sx,int sy) const;
    virtual bool isDownClicked(int x, int y,int sx,int sy) const;
    int getNumberFieldValue() const;
    string getNumberFieldValueString()const;
};
#endif // NUMBERFIELD_HPP_INCLUDED

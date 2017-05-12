#ifndef DROPDOWNFIELD_HPP_INCLUDED
#define DROPDOWNFIELD_HPP_INCLUDED
#include "formWidget.hpp"
#include <vector>
using namespace std;
using namespace genv;
class dropDownField : public formWidget{
protected:
    vector<string> options;
    int activeOptionIndex,scrollTop,scrollerSize,maxOptions;
    bool isOpened;
    bool isEmpty;
    public:
    dropDownField(Window* w,int px,int py, int sx, int sy,vector<string> opt,int maxoptions);
    virtual void handle(genv::event ev);
    virtual void draw() const;
    void addOption(string o);
    void removeSelected();
    bool isOpenerClicked(int x, int y) const;
    bool isScrollBarUpClicked(int x, int y) const;
    bool isScrollBarDownClicked(int x, int y) const;
    bool isElementClicked(int x,int y) const;
    virtual bool isMouseOverWidget(genv::event ev);
    int elementIndex(int y) const;
    void scroll(int n);
    string getSelectedOption() const;
};


#endif // DROPDOWNFIELD_HPP_INCLUDED

#ifndef MYWINDOW_HPP_INCLUDED
#define MYWINDOW_HPP_INCLUDED
#include "formWidget.hpp"
#include "window.hpp"
class myWindow : public Window{

    public:
    myWindow(int xx,int yy);
    virtual void esemeny(string azonosito);
};

#endif // MYWINDOW_HPP_INCLUDED

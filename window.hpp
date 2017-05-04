#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED
#include "formWidget.hpp"
#include <vector>

using namespace std;

class formWidget; // forward declaration;

class Window{
    protected:
     int XX, YY;
     vector<formWidget*> widgets;
    public:
    void event_loop();
    virtual void esemeny(string azonosito) = 0;
};

#endif // WINDOW_HPP_INCLUDED

#include "graphics.hpp"
#include "formWidget.hpp"
#include "iostream"
using namespace std;



formWidget::formWidget(Window* w,int px,int py, int sx, int sy):
 _px(px),_py(py),_sx(sx),_sy(sy)
{
    parent = w;
    isActive = false;
}

string formWidget::getValue() {
    return currentValue;
}

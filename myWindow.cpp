#include "myWindow.hpp"
#include "formWidget.hpp"
#include "pushButton.hpp"
#include "numberField.hpp"
#include "dropdownField.hpp"
#include "textField.hpp"
#include "iostream"
#include "vector"
myWindow::myWindow(int xx, int yy){
    XX = xx;
    YY = yy;
    gout.open(XX,YY);

    for(int s=0;s<9;s++){
        for(int o=0;o<9;o++){
            numberField *n = new numberField(this,s*70,o*70,70,70,0,9,0);
            widgets.push_back(n);
        }
    }

    event_loop();
}
 void myWindow::esemeny(string azonosito){
    if(azonosito == "ACTION"){

    }

}

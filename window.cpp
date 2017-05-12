#include "formWidget.hpp"
#include "window.hpp"
#include "graphics.hpp"
#include "fstream"
using namespace genv;

void Window::event_loop(){
      event ev;
    int focus = -1;

    while(gin >> ev ) {

        if (ev.type == ev_mouse) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->isMouseOverWidget(ev)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY);
        //gout<<move_to(450,35)<<color(255,255,255)<<text("Press space to create txt file with values.");
        for (size_t i=0;i<widgets.size();i++) {
            widgets[i]->draw();
        }
        /*if(ev.keycode == key_space){
            ofstream kifile("ertekek.txt");
            for (size_t i=0;i<widgets.size();i++) {
                kifile<<widgets[i]->getValue()<<endl;
            }
        }*/
        gout << refresh;
    }
}

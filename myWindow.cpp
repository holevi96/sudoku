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

    formWidget *n1 = new numberField(this,20,100,150,50,1,10,5);
    formWidget *n2 = new numberField(this,220,100,150,50,10,100,50);
    vector<string> opt = {};
    formWidget *d1 = new dropDownField(this,20,20,150,40,opt,3);
    vector<string> opt2 = {"Elso menupont", "Masodik","Harmadik","Huszonhatodik","Ez is","Meg ez","sadadas"};
    formWidget *d2 = new dropDownField(this,220,20,150,40,opt2,5);

    formWidget *t1 = new textField(this,20,260,150,50,"Lofasz");
    formWidget *b = new pushButton(this,20,310,100,50,"Add element","INPUT_DROPDOWN");
    formWidget *remover = new pushButton(this,200,310,200,50,"Remove selected","REMOVE_SELECTED");

   widgets.push_back(n1);
   widgets.push_back(n2);
   widgets.push_back(d1);
   widgets.push_back(t1);
   widgets.push_back(b);
   widgets.push_back(remover);
   event_loop();
}
 void myWindow::esemeny(string azonosito){
    if(azonosito == "INPUT_DROPDOWN"){
        //ha megnyomtuk a gombot, rakja bele az input mezobol a dropdownba,
        // TODO FLUGI KÉRDÉS: ez így jo??
        dropDownField* dB = static_cast<dropDownField*>(widgets[2]);
        dB->addOption(widgets[3]->getValue());
    }
    if(azonosito == "REMOVE_SELECTED"){
        dropDownField* dB = static_cast<dropDownField*>(widgets[2]);
        dB->removeSelected();

    }
}

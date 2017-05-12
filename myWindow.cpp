#include "myWindow.hpp"
#include "formWidget.hpp"
#include "pushButton.hpp"
#include "numberField.hpp"
#include "sudokuNumberField.hpp"
#include "dropdownField.hpp"
#include "textField.hpp"
#include "iostream"
#include "vector"
#include "fstream"
#include "graphics.hpp"
using namespace std;
using namespace genv;
myWindow::myWindow(int xx, int yy,string filename){
    XX = xx;
    YY = yy;
    gout.open(XX,YY);

    ifstream sfile(filename);
    sudoku.resize(9);
    for(int s=0;s<9;s++){
        sudoku[s].resize(9);
        for(int o=0;o<9;o++){
            sfile>> sudoku[s][o];
            sudokuNumberField *n = new sudokuNumberField(this,s*60+s*10,o*60+o*10,60,60,0,9,s,o,sudoku[s][o]);
            widgets.push_back(n);
        }
    }

    event_loop();
}
void myWindow::esemeny(string azonosito){
    if(azonosito == "ACTION"){

    }
}
void myWindow::changeSudokuValue(int row, int column,int value){
    sudoku[row][column] = value;
    validateSudoku();
}
void myWindow::validateSudoku(){

    for(int s=0;s<9;s++){
        for(int o=0;o<9;o++){
                sudokuNumberField* f = static_cast<sudokuNumberField*>(widgets[9*o+s]);
            if(isValidInColumn(s,o)==false||isValidInRow(s,o)==false || isValidInSub(s,o) == false){
                f->setFieldCorrect();
            }else{
                f->setFieldIncorrect();
            }
        }
    }
}
void myWindow::event_loop(){
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
        gout<<move_to(200,0)<<color(0,0,255)<<box(10,620);
        gout<<move_to(410,0)<<color(0,0,255)<<box(10,620);

        gout<<move_to(0,200)<<color(0,0,255)<<box(620,10);
        gout<<move_to(0,410)<<color(0,0,255)<<box(620,10);

        /*if(ev.keycode == key_space){
            ofstream kifile("ertekek.txt");
            for (size_t i=0;i<widgets.size();i++) {
                kifile<<widgets[i]->getValue()<<endl;
            }
        }*/
        gout << refresh;
    }
}

bool myWindow::isValidInSub(int x, int y) const{
    int bx, by;
    bool valid = true;
    int elem =sudoku[x][y];
    //ez megkeresi hogy az adott elem melyik 3x3as subsudokuhoz tartozik, és végigmegy rajta.
    for (bx = (x/3)*3; bx < (x/3)*3 + 3; bx++) {
        for (by = (y/3)*3; by < (y/3)*3 + 3; by++) {
            if(bx!=x && by!=y && sudoku[bx][by] == elem) valid = false;
        }
    }
    return valid;
}
bool myWindow::isValidInColumn(int x, int y) const{
    int elem = sudoku[x][y];
    bool valid = true;
    for(int i=0;i<9;i++){
        if(i!=y && sudoku[x][i] == elem) valid = false;
    }
    return valid;
}
bool myWindow::isValidInRow(int x,int y) const{
    int elem = sudoku[x][y];
    bool valid = true;
    for(int i=0;i<9;i++){
        if(i!=x && sudoku[i][y] == elem) valid = false;
    }
    return valid;
}

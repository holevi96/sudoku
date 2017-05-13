#include "myWindow.hpp"
#include "formWidget.hpp"
#include "pushButton.hpp"
#include "numberField.hpp"
#include "checkbox.hpp"
#include "sudokuNumberField.hpp"
#include "staticText.hpp"
#include "iostream"
#include "vector"
#include "fstream"
#include "graphics.hpp"
using namespace std;
using namespace genv;
myWindow::myWindow(int xx, int yy,vector<string> f) {
    XX = xx;
    YY = yy;
    filenames = f;
    gout.open(XX,YY);
    currentSudokuID = 0;
    sudoku.resize(9);
    for(int i=0;i<9;i++)
        sudoku[i].resize(9);


    for(int s=0;s<9;s++){
        for(int o=0;o<9;o++){
            sudokuNumberField *n = new sudokuNumberField(this,o*60+o*10,s*60+s*10,60,60,0,9,s,o,0);
            widgets.push_back(n);
        }
    }
    p = new pushButton(this,650,100,150,50,"Next sudoku","NEXTSUDOKU");
    widgets.push_back(p);
    initSudoku(0);
    event_loop();

}
void myWindow::initSudoku(int ID){

    ifstream sfile(filenames[ID]);
    for(int s=0;s<9;s++){
        for(int o=0;o<9;o++){
            sfile>>sudoku[s][o];
           sudokuNumberField* f = static_cast<sudokuNumberField*>(widgets[o+9*s]);
           f->setValue(sudoku[s][o]);
           widgets[o+9*s] = f;
        }
    }
    sfile.close();
    validateSudoku();


}
void myWindow::esemeny(string azonosito){
    if(azonosito == "NEXTSUDOKU"){

       currentSudokuID++;
        if(currentSudokuID <= filenames.size()-1){
            initSudoku(currentSudokuID);

        }else{
            gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY)<<move_to(30,10)<<text("There is no sudokus left...");
        }

    }
}
void myWindow::changeSudokuValue(int row, int column,int value){
    sudoku[row][column] = value;
    validateSudoku();
}
bool myWindow::validateSudoku(){
    bool valid = true;
    for(int s=0;s<9;s++){
        for(int o=0;o<9;o++){
            if(sudoku[s][o]==0) valid == false;
            sudokuNumberField* f = static_cast<sudokuNumberField*>(widgets[o+9*s]);
            if(isValidInColumn(s,o)==false || isValidInRow(s,o)==false || isValidInSub(s,o)==false){
                f->setFieldIncorrect();
                valid = false;
                }else{
                    f->setFieldCorrect();
                }
        }
    }
    return valid;
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
    if(elem!=0){
    //ez megkeresi hogy az adott elem melyik 3x3as subsudokuhoz tartozik, és végigmegy rajta.
    for (bx = (x/3)*3; bx < (x/3)*3 + 3; bx++) {
        for (by = (y/3)*3; by < (y/3)*3 + 3; by++) {
            if(bx!=x && by!=y && sudoku[bx][by] == elem) valid = false;
        }
    }
    }

    return valid;
}
bool myWindow::isValidInColumn(int x, int y) const{
    int elem = sudoku[x][y];
    //cout<<elem<<" ";
    bool valid = true;
     if(elem!=0){
    for(int i=0;i<9;i++){
     //   cout<<sudoku[x][i];
        if(i!=y && sudoku[x][i] == elem) valid = false;
    }
     }
    return valid;
}
bool myWindow::isValidInRow(int x,int y) const{
    int elem = sudoku[x][y];
    bool valid = true;
     if(elem!=0){
    for(int i=0;i<9;i++){
        if(i!=x && sudoku[i][y] == elem) valid = false;
    }
     }
    return valid;
}

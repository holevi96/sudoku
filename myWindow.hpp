#ifndef MYWINDOW_HPP_INCLUDED
#define MYWINDOW_HPP_INCLUDED
#include "formWidget.hpp"
#include "window.hpp"
using namespace std;
class myWindow : public Window{
protected:
    vector<string> filenames;
    int currentSudokuID;
    vector< vector<int> > sudoku;
    public:

    myWindow(int xx,int yy,vector<string> f);
    virtual void event_loop();
    virtual void esemeny(string azonosito);
    bool isValidInSub(int x, int y) const;
    bool isValidInRow(int x, int y) const;
    bool isValidInColumn(int x, int y) const;
    void changeSudokuValue(int row, int column, int value);
    bool validateSudoku();
    void initSudoku(int ID);
    pushButton *p;

};

#endif // MYWINDOW_HPP_INCLUDED

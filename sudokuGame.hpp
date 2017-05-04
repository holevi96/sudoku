#ifndef SUDOKUGAME_HPP_INCLUDED
#define SUDOKUGAME_HPP_INCLUDED
#include "vector"
using namespace std;

class sudokuGame{
    protected:
    vector< vector<int> > sudoku;
    public:
    sudokuGame();
    bool isValidInSub(int x, int y) const;
    bool isValidInRow(int x, int y) const;
    bool isValidInColumn(int x, int y) const;
    void onChange(int x, int y);
    void drawTable();
};

#endif // SUDOKUGAME_HPP_INCLUDED

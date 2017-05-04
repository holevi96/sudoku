#ifndef SUDOKUGAME_HPP_INCLUDED
#define SUDOKUGAME_HPP_INCLUDED
#include "vector"
using namespace std;

class sudokuGame{
    protected:

    public:
        vector< vector<int> > sudoku;
    sudokuGame();
    bool isValidInSub(int x, int y) const;
    bool isValidInRow(int x, int y) const;
    bool isValidInColumn(int x, int y) const;
    bool onChange(int x, int y);
    void drawTable();
};

#endif // SUDOKUGAME_HPP_INCLUDED

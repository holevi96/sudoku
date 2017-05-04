#include "sudokuGame.hpp"
#include "fstream"
#include  "iostream"
sudokuGame::sudokuGame(){
    ifstream sfile("sudoku1.txt");
    sudoku.resize(9);
    for(int s=0;s<9;s++){
        sudoku[s].resize(9);
        for(int o=0;o<9;o++){
            sfile>> sudoku[s][o];
        }
    }
}
bool sudokuGame::isValidInSub(int x, int y) const{
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
bool sudokuGame::isValidInColumn(int x, int y) const{
    int elem = sudoku[x][y];
    bool valid = true;
    for(int i=0;i<9;i++){
        if(i!=y && sudoku[x][i] == elem) valid = false;
    }
    return valid;
}
bool sudokuGame::isValidInRow(int x,int y) const{
    int elem = sudoku[x][y];
    bool valid = true;
    for(int i=0;i<9;i++){
        if(i!=x && sudoku[i][y] == elem) valid = false;
    }
    return valid;
}
bool sudokuGame::onChange(int x, int y){
    int elem = sudoku[x][y];
    if(elem != 0){
        if(isValidInColumn(x,y)&&isValidInRow(x,y)&&isValidInSub(x,y)){
            cout<<"Valid";
            return true;
        }else{
            cout<<"Invalid";
            return false;
        }
    }else{
        return true;
    }

}

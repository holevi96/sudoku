#include "graphics.hpp"
#include "vector"
#include "iostream"
#include "fstream"
#include "sudokuGame.hpp"
#include "myWindow.hpp"
using namespace genv;
using namespace std;

int main()
{

   myWindow App(1000,1000,"sudoku1.txt");

    sudokuGame S;
    S.sudoku[0][8] = 5;
    S.onChange(0,8);


    return 0;
}

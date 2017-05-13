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
    vector<string> filenames{"sudoku1.txt","sudoku2.txt"};
   myWindow App(1000,1000,filenames);

    return 0;
}

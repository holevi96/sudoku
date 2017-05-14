#include "graphics.hpp"
#include "vector"
#include "iostream"
#include "fstream"
#include "mySudokuGameMaster.hpp"
using namespace genv;
using namespace std;

int main()
{
    vector<string> filenames{"sudoku1.txt","sudoku2.txt"};
   mySudokuGameMaster App(1000,1000,filenames);

    return 0;
}

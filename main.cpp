#include "graphics.hpp"
#include "vector"
#include "iostream"
#include "fstream"
#include "sudokuGame.hpp"
using namespace genv;
using namespace std;

int main()
{

    const int WIDTH = 400;
    const int HEIGHT = 400;
    gout.open(WIDTH,HEIGHT); // pixelben adja meg h mekkora.
    event ev;
    sudokuGame S;

    while(gin >> ev) {

    }

    return 0;
}

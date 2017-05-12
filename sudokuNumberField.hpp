#ifndef SUDOKUNUMBERFIELD_HPP_INCLUDED
#define SUDOKUNUMBERFIELD_HPP_INCLUDED
#include "numberField.hpp"
class sudokuNumberField : public numberField{
protected:
    bool isIncorrect = false;
    int row,column;
    public:
    sudokuNumberField(Window* w,int px,int py, int sx, int sy, int minimum ,int maximum,int row,int column, int numberFieldValue);
    void handle(genv::event ev);
    virtual void changeValue(int n);
    void draw() const;
};

#endif // SUDOKUNUMBERFIELD_HPP_INCLUDED

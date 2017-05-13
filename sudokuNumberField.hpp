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
    void incrementValue(int n);
    void draw() const;
    void setFieldCorrect();
    void setFieldIncorrect();
    void setValue(int v);
};

#endif // SUDOKUNUMBERFIELD_HPP_INCLUDED

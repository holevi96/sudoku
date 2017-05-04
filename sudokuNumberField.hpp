#ifndef SUDOKUNUMBERFIELD_HPP_INCLUDED
#define SUDOKUNUMBERFIELD_HPP_INCLUDED
#include "numberField.hpp"
class sudokuNumberField : public numberField{
protected:


    public:
    sudokuNumberField(Window* w,int px,int py, int sx, int sy, int minimum ,int maximum, int value);
    void changeValue(int n);
    void draw() const;
};

#endif // SUDOKUNUMBERFIELD_HPP_INCLUDED

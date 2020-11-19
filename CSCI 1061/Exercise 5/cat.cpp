#include "cat.h"

Cat::Cat()
{
    this->_colour = "";
}

Cat::Cat(string colour)
{
    this->_colour = colour;
}

Cat::~Cat() {}

void speak()
{
    cout << "meow" << endl;
}
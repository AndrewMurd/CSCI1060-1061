#include "dog.h"

Dog::Dog()
{
    this->_bread = "";
}

Dog::Dog(string bread)
{
    this->_bread = bread;
}

Dog::~Dog() {}

void speak()
{
    cout << "woof" << endl;
}
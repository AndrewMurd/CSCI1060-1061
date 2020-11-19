#ifndef __cat_h__
#define __cat_h__

#include <iostream>
#include <vector>
#include "pet.h"

using namespace std;

class Cat : public Pet 
{
  protected:
    string _colour;

  public:
    Cat();
    Cat(string colour);
    virtual ~Cat();

    friend ostream &operator<<(ostream &os, const Cat &c);

    void speak();
};

#endif
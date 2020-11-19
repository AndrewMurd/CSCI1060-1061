#ifndef __dog_h__
#define __dog_h__

#include <iostream>
#include <vector>
#include "pet.h"

using namespace std;

class Dog : public Pet
{
  protected:
    string _bread;

  public:
    Dog();
    Dog(string bread);
    virtual ~Dog();

    friend ostream &operator<<(ostream &os, const Dog &d);

    void speak();
};

#endif
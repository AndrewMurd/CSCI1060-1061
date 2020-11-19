#ifndef __pet_h__
#define __pet_h__

#include <iostream>
#include <vector>

using namespace std;

class Pet
{
  protected:
    string _name;
    int _age;
    int _weight;
    string _owner;

  public:
    Pet();
    Pet(string name, int age, int weight, string owner);
    virtual ~Pet();

    void setName();
    void setWeight();
    void setAge();
    void readName();
    void readWeight();
    void readAge();

    friend ostream &operator<<(ostream &os, const Pet &p);

    virtual void speak();
};

#endif
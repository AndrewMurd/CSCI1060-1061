#include "pet.h"
#include <string>

Pet::Pet()
{
    this->_name = "";
    this->_age = 0;
    this->_weight = 0;
    this->_owner = "";
}

Pet::Pet(string name, int age, int weight, string owner)
{
    this->_name = name;
    this->_age = age;
    this->_weight = weight;
    this->_owner = owner;
}

Pet::~Pet() {}

void setName(string name)
{

}
void setWeight()
{

}
void setAge()
{

}
void readName()
{

}
void readWeight()
{

}
void readAge()
{

}

ostream &operator<<(ostream &os, const Pet &p)
{
    os << "Name: " << p._name << endl;
    os << "Name: " << p._age << endl;
    os << "Name: " << p._weight << endl;
    os << "Name: " << p._owner << endl;
    
    return os;
}

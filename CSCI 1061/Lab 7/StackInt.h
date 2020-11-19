#ifndef __StackInt_h__
#define __StackInt_h__

#include "Stack.h"
#include <vector>

class StackInt : public Stack
{
  protected:
    size_t stride; // We need this to number of bytes needed to store an int
    int *a;

  public:
    StackInt();
    void push(int val);
    int pop();

    int read(istream &is);
    int write(ostream &os) const;

    friend ostream &operator<<(ostream &os, const StackInt &s);
};

#endif
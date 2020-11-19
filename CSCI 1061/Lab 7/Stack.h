#ifndef __Stack_h__
#define __Stack_h__

#include "Buffer.h"

class Stack : public Buffer
{
  protected:
    int i;

  public:
    Stack();
    void push(char a);
    char pop();

    int read(istream &is);
    int write(ostream &os) const;

    friend ostream &operator<<(ostream &os, const Stack &s);
};

#endif
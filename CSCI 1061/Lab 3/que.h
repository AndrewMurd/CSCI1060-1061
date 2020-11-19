// que.h

#ifndef __que_h__
#define __que_h__

#include <iostream>
#include <string.h>
#include <math.h>
#include "str.h"

using namespace std;

struct Node
{
  string element;
  Node* next;
};

class que
{
protected:
  str _storage;
  string* del = new string[_sz];
  Node* front;
  Node* back; 
  int _sz;                             

public:
  que();  // Default constructor.  Creates an empty queue.
  ~que(); // Destructor.
  
  int size();
  int compress();
  char pop();
  void push(char c);
};

#endif
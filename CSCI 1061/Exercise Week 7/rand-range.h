#ifndef __rand_range_h__
#define __rand_range_h__

#include <iostream>
#include <vector>
#include "rand-int.h"

using namespace std;

class RandRange : public RandInt
{
  protected:
    int _low;
    int _high;

  public:
    RandRange();
    RandRange(int low, int high);
    RandRange(int seed, int low, int high);
    virtual ~RandRange();

    void gen(int n);
};

#endif
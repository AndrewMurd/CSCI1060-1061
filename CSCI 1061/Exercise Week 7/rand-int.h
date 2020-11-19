#ifndef __rand_int_h__
#define __rand_int_h__

#include <iostream>
#include <vector>

using namespace std;

class RandInt
{
  protected:
    vector<double> _numbers;
    int _seed;

  public:
    RandInt();
    RandInt(int seed);
    virtual ~RandInt();

    void gen(int n);

    inline int size() const { return _numbers.size(); }
    inline const vector<double> &get() const { return _numbers; }

    friend ostream &operator<<(ostream &os, const RandInt &r);
};

#endif
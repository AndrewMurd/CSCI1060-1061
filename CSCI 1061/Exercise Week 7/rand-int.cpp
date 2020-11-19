#include "rand-int.h"

RandInt::RandInt()
{
    _seed = 0;
}

RandInt::RandInt(int seed)
    : _seed(seed)
{
}

RandInt::~RandInt()
{
}

void RandInt::gen(int n)
{
    srand(_seed);
    for (int i = 0; i < n; ++i)
    {
        _numbers.push_back((double)rand());
    }
}

ostream &operator<<(ostream &os, const RandInt &r)
{
    for (int i = 0; i < r._numbers.size(); ++i)
    {
        os << r._numbers[i] << " ";
    }
    return os;
}
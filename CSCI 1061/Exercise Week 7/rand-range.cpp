#include "rand-range.h"

RandRange::RandRange()
{
    _seed = 0;
}

RandRange::RandRange(int low, int high)
{
    _seed = 0;
    _low = low;
    _high = high;
}

RandRange::RandRange(int seed, int low, int high)
{
    _seed = seed;
    _low = low;
    _high = high;
}

RandRange::~RandRange()
{

}

void RandRange::gen(int n)
{
    srand(_seed);
    int range = _high  - _low;
    for (int i = 0; i < n; i++)
    {
        int num = rand() % range + _low;
        _numbers.push_back(num);
    }
}
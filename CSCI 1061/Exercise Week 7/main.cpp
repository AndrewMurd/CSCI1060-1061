#include <iostream>
#include "rand-int.h"
#include "rand-range.h"

using namespace std;

int main()
{
    RandInt r;
    r.gen(5);
    cout << r << endl;

    const vector<double> &numbers = r.get();
    cout << numbers[0] << endl;

    RandRange r1(10, 12); // RandRange instance using low and high values
    r1.gen(4);
    cout << r1 << endl;

    return 0;
}
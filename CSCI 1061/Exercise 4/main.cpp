#include <iostream>
#include "mat3.h"

using namespace std;

int main()
{
    Mat3 m1;
    cout << m1 << endl;

    double a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Mat3 m2(a);
    cout << m2 << endl;

    Mat3 m3(m2);
    cout << m3 << endl;

    m1 = m2;
    cout << m1 << endl;

    //Mat3 m4 = m1 * m2;
    //cout << m4 << endl;

    //Mat3 a;
    // Mat3 b;
    // Mat3 c;
    //c = a * b;

    return 0;
}
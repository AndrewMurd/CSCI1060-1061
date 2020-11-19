#include <iostream>
#include <string.h>
#include "mat3.h"

using namespace std;

Mat3::Mat3()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            _data[i][j] = 0.0;
        }
    }
}

Mat3::Mat3(double a[])
{
    memcpy(_data, a, 9 * sizeof(double));
}

Mat3::Mat3(const Mat3& m)
{
    memcpy(_data, m._data, 9 * sizeof(double));
}

const Mat3 Mat3::operator=(const Mat3& m)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            _data[i][j] = m._data[i][j];
        }
    }
    
    return *this;
}

ostream& operator<<(ostream& os, const Mat3& m)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            os << m._data[i][j] << " ";
        }
        cout << endl;
    }
    return os;
}

const Mat3 operator*(Mat3 & a, Mat3& b)
{
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         return b._data[i][j] * a._data[i][j];
    //     }
    // }
}

// Mat3::Mat3(int x, int y)
// {
//     this->_data[x][y] = 
// }

Mat3::~Mat3()
{
}

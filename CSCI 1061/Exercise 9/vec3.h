#ifndef __vec3_h__
#define __vec3_h__

#include <iostream>
using namespace std;

template <typename T>
class vec3
{
  protected:
    T data[3];

  public:
    vec3() {}

    vec3(T x, T y, T z)
    {
        data[0] = x;
        data[1] = y;
        data[2] = z;
    }

    vec3(const vec3 &v)
    {
        for (int i = 0; i < 3; ++i)
        {
            data[i] = v[i];
        }
    }

    const vec3 &operator=(const vec3 &v)
    {
        for (int i = 0; i < 3; ++i)
        {
            data[i] = v[i];
        }
        return *this;
    }

    T &operator[](int i) { return data[i]; }
    const T &operator[](int i) const { return data[i]; }

    void print();

    template <typename U>
    friend U find_max(const vec3<U> &v);
};

template <typename T>
void vec3<T>::print()
{
    cout << "(" << data[0] << "," << data[1] << "," << data[2] << ")" << endl;
}

template <typename T>
T find_max(const vec3<T> &v)
{
    T m = v[0];
    if (m < v[1])
        m = v[1];
    if (m < v[2])
        m = v[2];
    return m;
}

#endif
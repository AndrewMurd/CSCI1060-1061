#ifndef mat3_h
#define mat3_h

#include <iostream>

using namespace std;

class Mat3
{
    protected:
        double _data[3][3];

    public:
        //Constructors
        Mat3();
        Mat3(double a[]);
        Mat3(const Mat3& m);
        Mat3(int x, int y);

        const Mat3 operator=(const Mat3&);
        friend const Mat3 operator*(Mat3&);
        friend ostream& operator<<(ostream &os, const Mat3 &m);
        //Destructor
        ~Mat3();
        
        // friend std::istream &operator>>(std::istream &stream, Mat3 &o);
        // bool operator==(const Mat3& o) const;
        // friend bool operator==(const Mat3 &o1, const Mat3 &o2);

        // const double &operator[](int i) const;
        // double &operator[](int i);

        // const double &operator()(int i) const;
        // double &operator()(int i);

        // operator int() const;
};

#endif 
#include "StackInt.h"

StackInt::StackInt()
{
    i = 0;
    //a = new int[sz];
}

void StackInt::push(int val)
{
    int length = std::to_string(val).length();
    cout << length << endl;
    vector<int> digits;

    if (0 == val)
    {
        digits.push_back(0);
    }
    else
    {
        while (val != 0)
        {
            int last = val % 10;
            digits.push_back(last);
            val = (val - last) / 10;
        }
    }

    for (int j = 0; j < length; j++)
    {
        char a = '0' + digits[j];
        m[i + j] = a;
    }
    i++;
}

int StackInt::pop()
{
    int k = m[i - 1];
    m[i - 1] = 0;
    i--;
    return k;
}

int StackInt::read(istream &is)
{
    int n;
    is.read((char *)&n, sizeof(int));
    resize(n);
    is.read(m, n);

    return is.gcount();
}

int StackInt::write(ostream &os) const
{
    int c = (i < sz) ? i : sz;
    os.write((char *)&c, sizeof(int));
    os.write(m, c);
    return c;
}

ostream &operator<<(ostream &os, const StackInt &s)
{
    cout << "StackInt: " << s.i << " [";
    for (int i = 0; i < s.i; i++)
    {
        cout << s.m[i] << ",";
    }
    if (s.i > 0)
    {
        cout << '\b';
    }
    cout << "]";
    return os;
}
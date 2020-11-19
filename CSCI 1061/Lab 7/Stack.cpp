#include "Stack.h"

Stack::Stack() 
{
    i = 0;
}

void Stack::push(char a)
{
    m[i] = a;
    i++;
}

char Stack::pop()
{
    char k = m[i - 1];
    m[i - 1] = 0;
    i--;
    return k;
}

int Stack::read(istream& is)
{
    int n;
    is.read((char *)&n, sizeof(int));
    resize(n);
    is.read(m, n);

    return is.gcount();
}

int Stack::write(ostream& os) const
{
    int c = (i < sz) ? i : sz;
    os.write((char *)&c, sizeof(int));
    os.write(m, c);
    return c;
}
  
ostream& operator<< (ostream& os, const Stack& s)
{
    cout << "Stack: " << s.i << " [";
    for (int i = 0; i < s.i; i++)
    {
        cout << s.m[i];
    }
    cout << "]";
    return os;
}
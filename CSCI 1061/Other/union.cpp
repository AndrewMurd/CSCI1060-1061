#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<int> union1(vector<int> &a, vector<int> &b)
{
    vector<int> c;
    int f;
    
    for (int i = 0; i < a.size(); i++)
    {
        f = 0;
        for (int j = 0; j < c.size(); j++)
        {
            if (a[i] == c[j])
            {
                f = 1;
            }
        }
        if (f == 0)
        {
            c.push_back(a[i]);
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        int f = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if (b[i] == a[j])
            {
                f = 1;
            }
        }
        if (f == 0)
        {
            c.push_back(b[i]);
        }
    }
    return c;
}

int main()
{
    vector<int> a;
    a.push_back(3);
    a.push_back(1);
    a.push_back(4);
    a.push_back(2);

    vector<int> b;
    b.push_back(5);
    b.push_back(1);

    vector<int> c = union1(a, b);

    cout << "a: ";
    print(a);
    cout << "b: ";
    print(b);
    cout << "c: ";
    print(c);

    return 0;
}
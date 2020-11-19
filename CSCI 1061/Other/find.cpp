#include <iostream>
#include <cstring>

using namespace std;

int find(char s[], int lens, char q[], int lenq)
{
    int test = 0;

    char comp = q[0];

    for (int i = 0; i < lens; i++)
    {
        if (s[i] == comp)
        {
            for (int y = 0; y < lenq; y++)
            {
                if (s[i + y] == q[y])
                {
                    test++;
                }
                else
                {
                    break;
                }
            }
            if (test == lenq)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    char s[] = "Its a beautiful world.";
    char q1[] = "world";
    char q2[] = "exam";

    cout << "Str:      " << s << endl;
    cout << "Query:    " << q1 << endl;
    cout << "Found at: " << find(s, strlen(s), q1, strlen(q1)) << endl;

    cout << "Str:      " << s << endl;
    cout << "Query:    " << q2 << endl;
    cout << "Found at: " << find(s, strlen(s), q2, strlen(q2)) << endl;
}
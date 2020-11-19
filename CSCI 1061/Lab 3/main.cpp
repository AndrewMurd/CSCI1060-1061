// main.cpp

#include "str.h"
#include "que.h"

char random_char()
{
    char ch = char((rand() % 26) + 65);
    return ch;
}

int main()
{
    /*str s1;
    cout << s1 << endl;

    str s2 = "Hello";
    cout << s2 << endl;

    str s3 = "World";

    /*str s4 = s2 + " " + s3;
    cout << s4 << endl;

    str s5, s6;
    cin >> s5 >> s6;
    cout << s5 << ' ' << s6;*/

    /*que q;
    q.push('h');
    q.push('d');
    cout << q.pop() << endl;
    cout << q.pop() << endl;*/

    que q;

    for (int i = 0; i < 10; ++i)
    {
        q.push(random_char());
        cout << "size = " << q.size() << endl;
    }

    for (int i = 0; i < 4; ++i)
    {
        cout << q.pop() << endl;
        cout << "size = " << q.size() << endl;
    }

    q.compress();
    cout << "size = " << q.size() << endl;

    return 0;
}
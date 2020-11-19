//Andrew Murdoch
//CSCI 1060U
//2018-11-30

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

typedef int *IntPtr;

using namespace std;

int main()
{
    int SIZE = 3;
    char **array = new char *[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = new char[SIZE];
    }

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            //Fills array will all X's (the character X)
            array[x][y] = 'X';
        }
    }

    cout << "<Start>" << endl;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cout << array[x][y] << endl;
        }
    }
    cout << "<End>" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        delete [] array[i];
    }

    delete [] array;
    return 0;
}
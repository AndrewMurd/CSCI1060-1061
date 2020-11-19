//Andrew Murdoch
//CSCI 1060U
//2018-12-11

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
    int size = 4;

    srand(time(NULL));
    int randomNum;

    char **array2d = new char*[size];
    for (int i = 0; i < size; i++)
    {
        array2d[i] = new char[size];
    }

    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            randomNum = rand() % 2;
            if (randomNum % 5 == 0)
            {
                array2d[x][y] = 'O';
            }
            else
            {
                array2d[x][y] = 'X';
            }
        }
    }

    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            cout << array2d[x][y] << endl;
        }
    }

    for (int i = 0; i < size; i++)
    {
        delete [] array2d[i];
    }

    delete [] array2d;
    return 0;
}
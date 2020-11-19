#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int get_max(int height[], int sz)
{
    int m = height[0];

    for (int i = 1; i < sz; ++i)
    {
        if (height[i] > m)
        {
            m = height[i];
        }
    }
    return m;
}

void print_height(int height[], int sz)
{
    for (int i = 0; i < sz; ++i)
    {
        cout << height[i] << " ";
    }
    cout << endl;
}

void pprint_height(int height[], int sz)
{
    int m = get_max(height, sz);

    for (int row = m; row >= 0; --row)
    {
        for (int i = 0; i < sz; ++i)
        {
            if (height[i] >= row)
                cout << 'x';
            else
                cout << ' ';
        }
        cout << endl;
    }
}

int main()
{
    srand(time(NULL));

    int height[16]; // 1D array to store the heights at
                    // different locations
    int num, firstNum;

    // TO DO -- assign heights here
    firstNum = rand() % 64;
    //cout << "First Num: " << firstNum << endl;

    for (int i = 0; i < 16; i++)
    {
        while (true)
        {
            num = rand() % 64;
            if ((firstNum <= (num + 10)) && (firstNum >= (num - 10)))
            {
                //cout << "num " << num << endl;
                height[i] = num;
                break;
            }  
        }
    }

    // Display 1D terrain
    cout << "Generated terrain:" << endl;
    pprint_height(height, 16);
}
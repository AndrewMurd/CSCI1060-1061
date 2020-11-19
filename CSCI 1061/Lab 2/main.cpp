//Andrew Murdoch
//CSCI 1061U
//main.cpp
//2018-01-29

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "count.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <count>" << endl;
        cerr << "\t<count> is an integer between 10 and 10000\n";
        cerr << "\tExiting." << endl;
        return -1;
    }

    int n = atoi(argv[1]);

    if (n < 10 || n > 10000)
    {
        cerr << "Usage: " << argv[0] << " <count>" << endl;
        cerr << "\t<count> is an integer between 10 and 10000\n";
        cerr << "\tExiting." << endl;
        return -2;
    }

    srand(time(NULL));

    char *arr = new char[n];

    for (int i = 0; i < n; i++)
    {
        //Loop through array and add capital letters between A - Z
        arr[i] = 'A' + rand() % 26;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    count(arr, n);

    delete[] arr;

    return 0;
}
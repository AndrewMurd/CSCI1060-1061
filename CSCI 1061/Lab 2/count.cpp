#include <iostream>
#include "count.h"

using namespace std;

void count(char *arr, int n)
{
    int *seen = new int[n];

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (seen[i] == 0)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                //loop through entire array for each value
                if (arr[i] == arr[j])
                {
                    //Count the number of times it's reapeated
                    count += 1;
                    seen[j] = 1;
                }
            }
            //Output collected data of reapeated value
            cout << arr[i] << " occurs " << count << " time" << endl;
        }
    }

    delete[] seen;
}
//Andrew Murdoch
//CSCI 1060U
//csci1060U_Lab8_a1.cpp
//2018-11-15

#include <iostream>
#include <string>

using namespace std;

typedef int *IntPtr;

int main()
{
    //Declaration of Size of array and integer values
    int SIZE;
    int inputedInt;

    cout << "Input Size of Array: ";
    cin >> SIZE;
    //Declaration of dynamic arrays
    IntPtr integerArray;
    IntPtr seen;
    integerArray = new int[SIZE]; 
    seen = new int[SIZE];
    //Input integer values
    cout << "Input Integer Values for Array: " << endl;
    for (int i = 0; i < SIZE;i++)
    {
        cin >> inputedInt;
        integerArray[i] = inputedInt;
    }
    //Counting reapeated values in array
    for (int i = 0; i < SIZE; i++)
    {
        if (seen[i] == 0)
        {
            int count = 0;
            for (int j = 0; j < SIZE; j++)
            {
                //loop through entire array for each value
                if (integerArray[j] == integerArray[i])
                {
                    //Count the number of times it's reapeated
                    count += 1;
                    seen[j] = 1;
                }
            }
            //Output collected data of reapeated value
            cout << integerArray[i] << " occurs " << count << " times" << endl;
        }
    }
    //Delete array to remove garbage values
    delete[] integerArray; 
    delete[] seen;

    return 0;
}
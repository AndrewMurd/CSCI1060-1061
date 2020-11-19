//Andrew Murdoch
//CSCI 1060U
//2018-12-11

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

typedef int *IntPtr;

using namespace std;

int main()
{
    int size = 1;
    string outfile = "courses";
    string *names = new string[size];
    string input = " ";
    string output;
    int x = 0, i = 0;

    ofstream myOutput(outfile);

    cout << "Enter names of courses(type -1 to stop): " << endl;
    while (true)
    {
        cin >> input;
        if (input == "-1")
        {
            break;
        }
        names[x] = input;
        x++;
        if (x == size)
        {
            size += 1;
            string *temp = new string[size];
            for (int i = 0; i < (size - 1); i++)
            {
                temp[i] = names[i];
            }
            names = temp;
        } 
    }

    for (int y = 0; y < size; y++)
    {
        myOutput << names[y] << endl;
    }

    myOutput.close();

    ifstream myInput(outfile);

    string *data = new string[size];

    while (!myInput.eof())
    {
        myInput >> data[i];
        i++;
    }

    for (int y = 0; y < size; y++)
    {
        cout << data[y] << endl;
    }

    myInput.close();

    delete [] names;
    delete [] data;
    return 0;
}   
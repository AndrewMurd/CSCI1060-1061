//Andrew Murdoch
//CSCI 1061U
//sr.cpp
//2019-03-23

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    //Line is the current line from getline
    //x is counter for number of equal characters
    //times is the number of times substr is in file 
    string filename = argv[1], line, substr = argv[2];
    int x = 0, times = 0;

    cout << "Reading " << argv[1] << endl; 

    ifstream input(filename);
    //if file dosen't open let user know and close program
    if (!input) 
    {
        cout << "Unable to open file";
        exit(1); //terminate with error
    }
    //loop until end of file
    while (!input.eof()) 
    {
        getline(input, line);
        //loop through line
        for (int i = 0; i < line.length(); i++)
        {
            //reset counter to zero
            x = 0;
            if (substr[0] == line[i])//check if the current character in line is equal to the first letter of the substr
            {
                for (int j = 0; j < substr.length(); j++) //loop through to see if substr is found
                {
                    if (line[i + j] == substr[j])
                    {
                        x++;
                    }
                    else
                    {
                        break;
                    }
                }
                //checking if substr was found 
                if (x == substr.length())
                {
                    times++;
                }
            }
        }
    }
    
    input.close();

    //outputting result after looping through entire file
    cout << substr << " was found " << times << " times." << endl;
       
    return 0;
}
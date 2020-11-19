//Andrew Murdoch
//CSCI 1061U
//part2.cpp
//2018-01-21

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string encrypt(string text, int s);
string decrypt(string text, int s);

const char WHITE_SPACE(32);

int main(int argc, char** argv)
{
    int shiftVal;
    string line, temp, encryptedLine, decryptedLine, inF, outF;

    //Assigning input entered to temp
    //Determining if it's encryption or decryption the user wants when running program
    temp = argv[1];

    if (temp == "-e")
    {
        string s = argv[2]; //Declaring shift value
        stringstream geek(s); //Converting string to int 
        geek >> shiftVal;
        inF = argv[3]; //Declaring input - Output files
        outF = argv[4];

        ifstream myInput(inF);  //Opening input - Output streams
        ofstream myOutput(outF); 

        if (myInput.is_open()) //checking if file is open
        {
            while (getline(myInput, line)) //get first line from input text file
            {
                encryptedLine = encrypt(line, shiftVal); //encrypt the inputted line
                myOutput << encryptedLine << endl; //output line to output text file
            }
            myInput.close();
            myOutput.close();
        }
    }
    if (temp == "-d")
    {
        string s = argv[2];
        stringstream geek(s);
        geek >> shiftVal;
        inF = argv[3];
        outF = argv[4];

        ifstream myInput(inF);
        ofstream myOutput(outF);

        if (myInput.is_open())
        {
            while (getline(myInput, line))
            {
                decryptedLine = decrypt(line, shiftVal);
                myOutput << decryptedLine << endl;
            }
            myInput.close();
            myOutput.close();
        }
    }
    return 0;
}

string encrypt(string text, int s)
{
    string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
        {
            result += char(int(text[i] + s - 65) % 26 + 65);
        }
        else if (islower(text[i]))
        {
            result += char(int(text[i] + s - 97) % 26 + 97);
        }
        //Checking if character is number or space so it isn't accidentally encrypted
        else if (text[i] == '0' || text[i] == '1' || text[i] == '2' || text[i] == '3' || text[i] == '4' || text[i] == '5' || text[i] == '6' || text[i] == '7' || text[i] == '8' || text[i] == '9' || text[i] == WHITE_SPACE)
        {
            if (text[i] == WHITE_SPACE)
            {
                result += WHITE_SPACE; //adding appropriate white space
            }
            else
            {
                result += text[i]; //adding numbers
            }
        }
    }
    return result;
}

string decrypt(string text, int s)
{
    s = 26 - s;

    string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
        {
            result += char(int(text[i] + s - 65) % 26 + 65);
        }
        else if (islower(text[i]))
        {
            result += char(int(text[i] + s - 97) % 26 + 97);
        }
        else if (text[i] == '0' || text[i] == '1' || text[i] == '2' || text[i] == '3' || text[i] == '4' || text[i] == '5' || text[i] == '6' || text[i] == '7' || text[i] == '8' || text[i] == '9' || text[i] == WHITE_SPACE)
        {
            if (text[i] == WHITE_SPACE)
            {
                result += WHITE_SPACE;
            }
            else
            {
                result += text[i];
            }
        }
    }
    return result;
}
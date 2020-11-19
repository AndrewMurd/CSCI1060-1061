//Andrew Murdoch
//CSCI 1061U
//part3.cpp
//2018-01-21

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string encrypt(string text, int s);
string decrypt(string text, int s);

const char WHITE_SPACE(32);

int main(int argc, char **argv)
{
    int shiftVal, x = 0, y = 0;
    string temp;
    string plainText, encryptedLine, decryptedLine, inF, outF, text = "", numbers = "";
    string line;

    temp = argv[1];

    if (temp == "-e")
    {
        string s = argv[2];
        stringstream geek(s);
        geek >> shiftVal;

        while (getline(cin, line)) //get line from input file from input stream 
        {
            encryptedLine = encrypt(line, shiftVal);
            cout << encryptedLine << endl; //output encrypted line to output file through output stream
        }
    }
    if (temp == "-d")
    {
        string s = argv[2];
        stringstream geek(s);
        geek >> shiftVal;

        while (getline(cin, line))
        {
            decryptedLine = decrypt(line, shiftVal);
            cout << decryptedLine << endl;
        }
    }    
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
//Andrew Murdoch
//CSCI 1061U
//part1.cpp
//2018-01-21

#include <iostream>
#include <string>

using namespace std;

//Encryption and Decryption Ceasar Cipher Functions
string encrypt(string text, int s);
string decrypt(string text, int s);

int main()
{
    int shiftVal;
    string plainText, encryptedText, decryptedText;

    cout << "Enter shift (+/- 26): " << endl;
    cin >> shiftVal;
    
    cout << "Enter plaintext message (A-Z only, no spaces):" << endl;
    cin >> plainText;

    //Encrypting text entered with shift value entered
    encryptedText = encrypt(plainText, shiftVal);

    cout << "ciphertext: " << encryptedText << endl;

    //Decrypting text entered with shift value entered
    decryptedText = decrypt(encryptedText, shiftVal);

    cout << "plaintext: " << decryptedText << endl;

    return 0;
}

string encrypt(string text, int s)
{
    string result = "";

    //Loop through the string entered 
    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i])) //Checking for upper case letter
        {
            result += char(int(text[i] + s - 65) % 26 + 65); //add shifted value to result string
        }
        else
        {
            result += char(int(text[i] + s - 97) % 26 + 97);
        }
    }
    return result;
}

string decrypt(string text, int s)
{
    //Altering shift value to it decrypts correctly
    s = 26 - s;

    string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
        {
            result += char(int(text[i] + s - 65) % 26 + 65);
        }
        else
        {
            result += char(int(text[i] + s - 97) % 26 + 97);
        }
    }
    return result;
}
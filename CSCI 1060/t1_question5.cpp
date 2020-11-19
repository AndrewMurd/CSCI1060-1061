#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void writeString(string input);

int main(){
    
    int x = 0;
    string input, input2;
    string filename = "user.txt";

    cout << "Enter a string:";
    cin >> input;

    ofstream myOutput(filename);
    writeString(input);

    cout << "Enter strings:";


    for (int x = 0; x< 10000;x++){
        ofstream myOutput(filename);
        cin >> input2;
        if (input2 == "QUIT"){
                exit(1);
        }
    } 
}

void writeString(string input){

    string filename = "user.txt";
    cout << input << endl;

    ifstream myInput(filename);
    if (!myInput.eof() == true){
        cout << "true" << endl;
    }

    if (!myInput.eof() == false){
        cout << "false" << endl;
    }
}
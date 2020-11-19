#include "Buffer.h"
#include "Stack.h"
#include "StackInt.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    Buffer buf1("Hello");
    cout << buf1 << endl;

    cout << "##########################################" << endl;
    cout << "Saving buffer to out.txt" << endl;

    ofstream outfile;
    outfile.open("out.txt", ios::binary);
    cout << "Written = " << buf1.write(outfile) << endl;
    outfile.close();

    cout << "##########################################" << endl;
    cout << "Create a new buffer and read buffer from out.txt" << endl;

    Buffer buf2(1);

    // Reading from a file
    ifstream infile;
    infile.open("out.txt", ios::binary);
    cout << "Read = " << buf2.read(infile) << endl;
    infile.close();
    cout << buf2 << endl;

    cout << "##########################################" << endl;
    cout << "Increasing buffer size to 10" << endl;

    // Increasing is size
    buf2.resize(10);
    cout << buf2 << endl;

    cout << "##########################################" << endl;
    cout << "Decreasing buffer to 2" << endl;

    // Decreasing its size
    buf2.resize(2);
    cout << buf2 << endl;

    cout << "##########################################" << endl;
    cout << "Character stack" << endl;

    //The stack class
    Stack s;
    s.push('1');
    s.push('2');
    s.push('3');
    s.push('4');

    cout << "##########################################" << endl;
    cout << "After pushing 1, 2, 3, 4" << endl;

    cout << s << endl;

    cout << "##########################################" << endl;
    cout << "Pop should return a 4" << endl;

    cout << s.pop() << endl;
    cout << s << endl;

    cout << "##########################################" << endl;
    cout << "Saving character stack to out-stack.txt" << endl;

    outfile.open("out-stack.txt", ios::binary);
    cout << "Written = " << s.write(outfile) << endl;
    outfile.close();

    cout << "##########################################" << endl;
    cout << "Creating another character stack and loading it in from out-stack.txt" << endl;

    Stack s2;
    infile.open("out-stack.txt", ios::binary);
    cout << "Read = " << s2.read(infile) << endl;
    infile.close();
    cout << s2 << endl;

    cout << "##########################################" << endl;
    cout << "Pushed 5 into character stack" << endl;

    s2.push('5');
    cout << s2 << endl;

    cout << "##########################################" << endl;
    cout << "Integer stack" << endl;

    StackInt s3;
    cout << s3 << endl;

    cout << "##########################################" << endl;
    cout << "After pushing 122,234,3453" << endl;
    s3.push(122);
    s3.push(234);
    s3.push(3453);
    cout << s3 << endl;

    cout << "##########################################" << endl;
    cout << "Pop should return 3453" << endl;
    cout << s3.pop() << endl;
    cout << s3 << endl;

    cout << "##########################################" << endl;
    cout << "Saving integer stack to out-stackint.txt" << endl;
    outfile.open("out-stackint.txt", ios::binary);
    cout << "Written = " << s3.write(outfile) << endl;
    outfile.close();

    cout << "##########################################" << endl;
    cout << "Creating a new integer stack and loading it in from out-stackint.txt" << endl;
    StackInt s4;
    infile.open("out-stackint.txt", ios::binary);
    cout << "Read = " << s4.read(infile) << endl;
    infile.close();
    cout << s4;
    cout << endl;

    cout << "##########################################" << endl;
    cout << "Push 45,-65,-5665" << endl;
    s4.push(45);
    s4.push(-65);
    s4.push(-5665);
    cout << s4;
    cout << endl;

    return 0;
}
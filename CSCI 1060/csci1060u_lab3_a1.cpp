//Andrew Murdoch
//CSCI 1060U
//lab02_a1.cpp
//2018-09-27

#include <iostream>
#include <string>

using namespace std;
//Declaring functions
int ascending(int list[], int size);
void swapper(int& a, int& b);


int main(){
    //Array size
    const int SIZE = 5;
    //Declaring array
    int list[SIZE];
    
    cout << "Enter 5 integers: " << endl;
    //5 inputs
    for (int i = 0; i < SIZE; i++){
        cin >> list[i];
    }
    //Calling sort function
    ascending(list, SIZE);

    cout << endl << "The array of integers sorted in ascending order is: " << endl;
    //Outputing sorted list
    for (int j = 0; j < SIZE; j++)
    {
        cout << list[j] << " ";
    }
    cout << endl;
}
//Sort function
int ascending(int list[], int size){
    //Loop for to compare each varible 
    for(int i = 0; i < size;i++){
        for (int j = 0; j < size; j++){
            //Check if one is bigger then other
            if (list[j] > list[j + 1]){
                swapper(list[j], list[j+1]);
            }
        }
    }
}
//Swap numbers
void swapper(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}

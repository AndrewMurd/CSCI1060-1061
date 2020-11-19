//Andrew Murdoch
//CSCI 1060U
//lab02_a1.cpp
//2018-09-27

/*Time for 1000 numbers:
real    0m0.058s
user    0m0.000s
sys     0m0.016s
*/

/*Time for 10000 numbers:
real    0m1.000s
user    0m0.953s
sys     0m0.000s*/

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;
//Declaring functions
int ascending(int list[], int size);
void swapper(int& a, int& b);


int main(){

    srand(time(NULL));
    //Declaring array and variables
    const int x = 1000;
    int list[x], randomNum;
    
    //Creating arrays
        for (int i = 0; i < x; i++){
            randomNum = rand()%100;
            list[i] = randomNum;
        }

    //Calling sort function
    ascending(list, x);

    cout << endl << "The array of integers sorted in ascending order is: " << endl;
    //Outputing sorted list
    for (int j = 0; j < x; j++)
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

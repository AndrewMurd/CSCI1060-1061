//Andrew Murdoch
//CSCI 1060U
//lab05.cpp
//2018-10-25
//Version 2

/*This program takes users input on how many units are
produced in each factory and outputs a gaph accordingly*/

#include <iostream>
#include <cmath>

using namespace std;

//Declaring Constant (Number of Factories)
const int kFACTORIES = 3;

//Declaring Functions
void LoopFactories(int production[], int NUM);
void Convert(int production[], int NUM);
void DisplayGraphs(const int production[], int NUM);
void AddingUnits(int &sum);
int SmallestValue(double decimal);
void CreatingGraph(int n);

int main(){
    int production[kFACTORIES];

    cout << "This program displays a graph showing\n"
         << "production for each factory in the company.\n";

    LoopFactories(production, kFACTORIES);
    Convert(production, kFACTORIES);
    DisplayGraphs(production, kFACTORIES);

    return 0;
}

void LoopFactories(int production[], int NUM){
    //Looping through each factory in the array
    for (int x = 1; x <= NUM; x++){
        cout << endl
             << "Enter production data for plant number " << x << endl;
        //Returns the sum of the units into the array
        AddingUnits(production[x - 1]);
    }
}

void AddingUnits(int &sum){
    cout << "Enter number of units produced by each department.\n"
         << "Append a negative number to the end of the list.\n";
    sum = 0;
    int num_units;
    cin >> num_units;
    /*While the value of the unit is greater or equal to zero 
    add it's value to the total (sum)*/
    while (num_units >= 0){
        sum = sum + num_units;
        cin >> num_units;
    }
    //Output the total value (sum)
    cout << "Total = " << sum << endl;
}

void Convert(int production[], int NUM){
    //Converting value entered to units of 1000
    for (int index = 0; index < NUM; index++){
        production[index] = SmallestValue(production[index] / 1000.0);
    }    
}

int SmallestValue(double decimal){
    //Converting the double value to integer and returning the smallest value (floor)
    return static_cast<int>(floor(decimal + 0.5));
}

void DisplayGraphs(const int production[], int NUM){
    cout << "\nUnits produced in thousands of units:\n";
    //Displaying Graph for each Factory
    for (int index = 1; index <= NUM; index++){
        cout << "Factory #" << index << " ";
        CreatingGraph(production[index - 1]);
        cout << endl;
    }
}

void CreatingGraph(int n){
    //Creates bar graph
    for (int count = 1; count <= n; count++){
        cout << "*";
    }    
}
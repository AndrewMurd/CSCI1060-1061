//Andrew Murdoch
//CSCI 1060U 
//lab01_a1.cpp
//2018-09-20

#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Declraring Variables
    string names;
    string surname;
    int birth_year, age;
    double hourly_wage;

    //Asking for input
    cout << "Enter your're name: ";
    getline(cin, names);
    cout << "Input you're Birth Year: ";
    cin >> birth_year;
    cout << "Enter your're hourly wage: "; 
    cin >> hourly_wage;

    //Output
    cout << "Name: " << names << endl;
    cout << "Birth Year: " << birth_year << endl; 
    cout << "Hourly wage($): " << hourly_wage << endl;

    //Calculating age
    age = 2018 - birth_year;

    //Outputing sentence
    cout << names << " is " << age << " and requests an hourly wage of $" << 
    hourly_wage << "." << endl;
}
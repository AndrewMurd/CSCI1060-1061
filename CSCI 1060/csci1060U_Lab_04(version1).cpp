//Andrew Murdoch
//CSCI 1060U
//lab02_a1.cpp
//2018-09-27

#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

int printMonth(string month, int year,int t[], int daysMonths[], int days[], string dayName);
int printYear(int year, string dayName, string monthName[], int t[], int daysMonths[], int days[]);

int main(){

    const int SIZE = 12;
    int days[31] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
                     21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
    int daysMonths[SIZE] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int t[SIZE] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    string dayName = "Sun Mon Tue Wed Thu Fri Sat";
    string monthName [SIZE] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", 
                               "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    string inputType, inputMonth;
    int inputYear;
 
    cout << "Which type of calender would you prefer"
         << "(Y for year calendar/M for month calendar):";

    cin >> inputType;
    if (inputType == "Y"){
        cout << "What year would you like:";
        cin >> inputYear;
        printYear(inputYear, dayName, monthName, t, daysMonths, days);
    }
    if (inputType == "M")
    {
        cout << "What year would you like:";
        cin >> inputYear;
        cout << "What month would you like:";
        cin >> inputMonth;
        printMonth(inputMonth, inputYear, t, daysMonths, days, dayName);
    }
}

int printMonth(string month, int year,int t[], int daysMonths[], int days[], string dayName)
{
    string name;
    int i = 0;
    if (month == "january" || month == "January")
    {
        name = "JANUARY";
        i = 0;
    }
    if (month == "February" || month == "february")
    {
        name = "FEBRUARY";
        i = 1;
    }
    if (month == "March" || month == "march")
    {
        name = "MARCH";
        i = 2;
    }
    if (month == "April" || month == "april")
    {
        name = "APRIL";
        i = 3;
    }
    if (month == "May" || month == "may")
    {
        name = "MAY";
        i = 4;
    }
    if (month == "June" || month == "june")
    {
        name = "JUNE";
        i = 5;
    }
    if (month == "July" || month == "july")
    {
        name = "JULY";
        i = 6;
    }
    if (month == "August" || month == "august")
    {
        name = "AUGUST";
        i = 7;
    }
    if (month == "September" || month == "september")
    {
        name = "SEPTEMBER";
        i = 8;
    }
    if (month == "October" || month == "october")
    {
        name = "OCTOBER";
        i = 9;
    }
    if (month == "November" || month == "november")
    {
        name = "NOVEMBER";
        i = 10;
    }
    if (month == "December" || month == "december")
    {
        name = "DECEMBER";
        i = 11;
    }

    bool A_Leap_Year = ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
    if (A_Leap_Year)
    {
        daysMonths[1] = 29;
    }

    cout << endl << name << " " << year << endl 
         << dayName << endl;
    int y = year - (daysMonths[i] < 2);
    y = (y + y / 4 - y / 100 + y / 400 + t[i] + 1) % 7;
    for (int a = 0; a < y; a++){
            cout << " ";
    }
    int iterations = daysMonths[i];
    for (int i = 0; i < iterations; i++){
        cout << days[i] << " ";
        if ((i % 7) == 0 && (i != 0)){
            cout << endl;
        }
    }
    cout << endl;
}

int printYear(int year, string dayName, string monthName[], int t[], int daysMonths[], int days[]){

    bool A_Leap_Year = ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
    if (A_Leap_Year){
        daysMonths[1] = 29;
    }

    for (int i = 0; i < 12;i++){
        cout << endl << endl << monthName[i] << " " << year << endl 
             << dayName << endl;
        int y = year - (daysMonths[i] < 2);
        y = (y + y / 4 - y / 100 + y / 400 + t[i] + 1) % 7;
        /*for (int a = 0; a < y; a++){
            cout << " ";
        }*/
        cout << setw((y * 2));
        int iterations = daysMonths[i];
        for (int i = 0; i < iterations;i++){
            cout << days[i] << setw(4);
            if ((i % 7) == 0 && (i != 0)){
                cout << endl;
            }
        } 
    }
    cout << endl;
}



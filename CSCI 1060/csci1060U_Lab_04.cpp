//Andrew Murdoch
//CSCI 1060U
//lab02_a1.cpp
//2018-10-14

#include<bits/stdc++.h> 
using namespace std; 
  
//Function that returns index of day
int dayNumber(int day, int month, int year) 
{ 
  
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 
                       4, 6, 2, 4 }; 
    year -= month < 3; 
    return ( year + year/4 - year/100 + 
             year/400 + t[month-1] + day) % 7; 
} 
  
//Month Names for output
string getMonthName(int monthNumber) 
{ 
    string months[] = {"January", "February", "March", 
                       "April", "May", "June", 
                       "July", "August", "September", 
                       "October", "November", "December"
                      }; 
  
    return (months[monthNumber]); 
} 
  
//Determine amount of days in each month
int numberOfDays (int monthNumber, int year) 
{ 
    //January 
    if (monthNumber == 0) 
        return (31); 
  
    //February 
    if (monthNumber == 1) 
    { 
        //If the year is leap then February has 
        //29 days 
        if (year % 400 == 0 || 
                (year % 4 == 0 && year % 100 != 0)) 
            return (29); 
        else
            return (28); 
    } 
  
    //March 
    if (monthNumber == 2) 
        return (31); 
  
    //April 
    if (monthNumber == 3) 
        return (30); 
  
    //May 
    if (monthNumber == 4) 
        return (31); 
  
    //June 
    if (monthNumber == 5) 
        return (30); 
  
    //July 
    if (monthNumber == 6) 
        return (31); 
  
    //August 
    if (monthNumber == 7) 
        return (31); 
  
    //September 
    if (monthNumber == 8) 
        return (30); 
  
    //October 
    if (monthNumber == 9) 
        return (31); 
  
    //November 
    if (monthNumber == 10) 
        return (30); 
  
    //December 
    if (monthNumber == 11) 
        return (31); 
}
//Function for a single month
void printMonth(int year, string month)
{
    //Determine what month the user inputted
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
    //Display title
    printf("\n         Calendar - %d\n", year);
    int days;

    int current = dayNumber(1, i, year);

        days = numberOfDays(i, year);

        // Print the current month name
        printf("\n  ------------%s-------------\n",
               getMonthName(i).c_str());

        // Print the columns
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print appropriate spaces
        int k;
        for (k = 0; k < current; k++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++k > 6)
            {
                k = 0;
                printf("\n");
            }
        }

        if (k)
            printf("\n");

        current = k;

    return;
}

// Function to print the calendar of the given year
void printYear(int year) 
{ 
    printf ("\n         Calendar - %d\n\n", year); 
    int days; 
  
    int current = dayNumber (1, 1, year); 
  
    for (int i = 0; i < 12; i++) 
    { 
        days = numberOfDays (i, year); 
  
        printf("\n  ------------%s-------------\n", 
               getMonthName (i).c_str()); 
 
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n"); 
  
        int k; 
        for (k = 0; k < current; k++) 
            printf("     "); 
  
        for (int j = 1; j <= days; j++) 
        { 
            printf("%5d", j); 
  
            if (++k > 6) 
            { 
                k = 0; 
                printf("\n"); 
            } 
        } 
  
        if (k) 
            printf("\n"); 
  
        current = k; 
    } 
  
    return; 
} 
  
//Main Function getting user input
int main() 
{
    string inputType, inputMonth;
    int inputYear;

    cout << "Which type of calender would you prefer"
         << "(Y for year calendar/M for month calendar):";

    cin >> inputType;
    if (inputType == "Y")
    {
        cout << "What year would you like:";
        cin >> inputYear;
        printYear(inputYear);
    }
    if (inputType == "M")
    {
        cout << "What year would you like:";
        cin >> inputYear;
        cout << "What month would you like:";
        cin >> inputMonth;
        printMonth(inputYear, inputMonth);
    }

    return (0);
} 
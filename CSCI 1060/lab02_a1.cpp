//Andrew Murdoch
//CSCI 1060U
//lab02_a1.cpp
//2018-09-27

//Including Required Libraries
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

//Main Function
int main()
{
    //Declaration of variables
    int randomNum, guess;
    //Counter for guesses
    int i = 0;
    //Variable for remainder
    int x = 5;

    //Title of Game
    cout<< "-------------------------------" << endl;
    cout<< "WELCOME TO GUESS THAT NUMBER!!!"<< endl;
    cout << "-------------------------------" << endl;

    //Looping Code for Multiple Rounds
    for(int y = 1;y<1000000;y++){
        //Space Rounds
        cout << endl;
        //Using Time to create random number
        srand (time(NULL));
        randomNum = rand() % x;

        //Test Code for program
        //cout << randomNum << endl;

        //Output what round it is
        cout<< "Round "<< y << " Fight!" << endl;
        
        //do while loop for inputed guesses
        do{
            //Count up for each guess
            i++;
            //Output what you are suppose to guess
            cout << "Guess a number less than "<< x << ":";
            //Inputed Guess
            cin >> guess;
            //Check if we need to break loop
            if(randomNum == guess){
                break;
            }
            //Outputing amountt of tries left
            cout << "Incorrect! try again (" << (5-i) << " tries remaining)" << endl;
          /*Check if the player still hasen't guessed 
          the number and still has tries left*/
        } while(randomNum != guess && i<5);

        //Output Winner screen and increase remainder value by doubling
        if (randomNum == guess)
        {
            cout << "Congrats! The Number was "<< randomNum << endl;
            i = 0;
            x = x*2;
        }
        //Output loser screen closing program
        else{
            cout << "Game Over! You are out of guesses" << endl;
            exit(0);
        }
    }
}
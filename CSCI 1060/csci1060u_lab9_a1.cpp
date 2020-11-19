//Andrew Murdoch
//CSCI 1060U
//csci1060u_lab6_a1.cpp
//2018-11-01

//TIC-TAC-TOE [game]

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 3;
bool start = false;

void displayBoard(string **b);
bool userFirst();
bool currentPlayerWon(string **b, string symbol);
int generateComputerMove(string **board, int &row, int &col);

int main()
{
    //construct board
    //Declraring 2d Dynamic Array
    string** board = new string*[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        //Create array in each position in first pointed to array
        board[i] = new string[SIZE];
    }

    int position_id = 1;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = to_string(position_id);
            /*  stringstream ss;
        ss << position_id;
        board[i][j] = ss.str();
        */
            position_id++;
        }
    }

    //Initial game output
    cout << "Welcome to Tic-Tac-Toe" << endl;

    bool userTurn = userFirst();
    if (userTurn == true)
    {
        cout << "Player goes first!" << endl;
    }
    else
    {
        cout << "Computer goes first!" << endl;
    }

    //Loop for turn taking in game
    int positionsRemaining = SIZE * SIZE;
    bool userWon = false;
    bool computerWon = false;

    while ((positionsRemaining > 0) && (!userWon) && (!computerWon))
    {
        displayBoard(board);

        //User's turn
        if (userTurn)
        {
            bool validMove = false;
            while (!validMove)
            {
                int position_id;
                cout << "Enter a position: ";
                cin >> position_id;
                if ((position_id <= (SIZE * SIZE)) && (position_id > 0))
                {
                    int row = (position_id - 1) / SIZE;
                    int col = (position_id - 1) % SIZE;
                    //cout << "row = " << row << " col = " << col << endl;
                    if ((board[row][col] != "X") && (board[row][col] != "O"))
                    {
                        board[row][col] = "X";
                        validMove = true;
                    }
                    else
                    {
                        cout << "Position already used. Try again." << endl;
                    }
                }
                else
                {
                    cout << "Position invalid. Try again." << endl;
                }
            }
            positionsRemaining--;
            userWon = currentPlayerWon(board, "X");
            userTurn = false;
            start = true;
        }
        //First turn for Computer if it goes first
        else if (start == false)
        {
            board[1][1] = "O";
            positionsRemaining--;
            computerWon = currentPlayerWon(board, "O");
            userTurn = true;
            start = true;
        }

        //Computer's turn
        else
        {
            //The row and col are both passed as
            //call-by-reference
            int row, col;
            generateComputerMove(board, row, col);
            board[row][col] = "O";

            positionsRemaining--;
            computerWon = currentPlayerWon(board, "O");

            userTurn = true;
        }
    }

    //Display game result
    displayBoard(board);
    if (userWon)
    {
        cout << "Congratulations! You have won!" << endl;
    }
    else if (computerWon)
    {
        cout << "The computer has won. Try again." << endl;
    }
    else
    {
        cout << "Out of moves. Try again." << endl;
    }
    return 0;
}

int generateComputerMove(string **board, int &row, int &col)
{
    //Declaring counters and arrays
    bool validMove = false, end = false;
    int num_Col0 = 0, num_Col1 = 0, num_Col2 = 0, num_Row0 = 0, num_Row1 = 0, num_Row2 = 0, x, y;
    //Attack Move
    //Vertical Case
    for (int j = 0; j < SIZE; j++)
    {
        //Count how many O are in that case
        if (board[j][0] == "O")
        {
            num_Col0++;
        }
    }

    for (int j = 0; j < SIZE; j++)
    {
        if (board[j][1] == "O")
        {
            num_Col1++;
        }
    }

    for (int j = 0; j < SIZE; j++)
    {
        if (board[j][2] == "O")
        {
            num_Col2++;
        }
    }
    //If it counted 2 
    if (num_Col0 >= 2)
    {
        x = 0;
        //Find where to place it
        for (int j = 0; j < SIZE; j++)
        {
            //Make sure its free
            if ((board[j][x] != "O") && (board[j][x] != "X"))
            {
                //Return Values of move
                row = j;
                return col = x;
            }
        }
    }
    if (num_Col1 >= 2)
    {
        x = 1;
        for (int j = 0; j < SIZE; j++)
        {
            if ((board[j][x] != "O") && (board[j][x] != "X"))
            {
                row = j;
                return col = x;
            }
        }
    }
    if (num_Col2 >= 2)
    {    
        x = 2;
        for (int j = 0; j < SIZE; j++)
        {
            if ((board[j][x] != "O") && (board[j][x] != "X"))
            {
                row = j;
                return col = x;
            }
        }
    }
    //Reset Variables
    num_Col0 = 0; 
    num_Col1 = 0; 
    num_Col2 = 0;
    //Horizontal case
    for (int j = 0; j < SIZE; j++)
    {
        if (board[0][j] == "O")
        {
            num_Row0++;
        }
    }

    for (int j = 0; j < SIZE; j++)
    {
        if (board[1][j] == "O")
        {
            num_Row1++;
        }
    }

    for (int j = 0; j < SIZE; j++)
    {
        if (board[2][j] == "O")
        {
            num_Row2++;
        }
    }

    if (num_Row0 >= 2)
    {
        y = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if ((board[y][j] != "O") && (board[y][j] != "X"))
            {
                row = y;
                return col = j;
            }
        }
    }
    if (num_Row1 >= 2)
    {
        y = 1;
        for (int j = 0; j < SIZE; j++)
        {
            if ((board[y][j] != "O") && (board[y][j] != "X"))
            {
                row = y;
                return col = j;
            }
        }
    }
    if (num_Row2 >= 2)
    {
        y = 2;
        for (int j = 0; j < SIZE; j++)
        {
            if ((board[y][j] != "O") && (board[y][j] != "X"))
            {
                row = y;
                return col = j;
            }
        }
    }
    num_Row0 = 0;
    num_Row1 = 0;
    num_Row2 = 0;
    //Diagonal1
    //Check each case individualy and return move
    if (board[0][0] == "O" && board[1][1] == "O")
    {
        if (board[2][2] != "X")
        {
            //return correct board position for computer
            row = 2;
            return col = 2;
        }
    }
    if (board[0][0] == "O" && board[2][2] == "O")
    {
        if (board[1][1] != "X")
        {
            row = 1;
            return col = 1;
        }
    }
    if (board[2][2] == "O" && board[1][1] == "O")
    {
        if (board[0][0] != "X")
        {
            row = 0;
            return col = 0;
        }
    }
    //Diagonal2
    if (board[2][0] == "O" && board[1][1] == "O")
    {
        if (board[0][2] != "X")
        {
            row = 0;
            return col = 2;
        }
    }
    if (board[0][2] == "O" && board[2][0] == "O")
    {
        if (board[1][1] != "X")
        {
            row = 1;
            return col = 1;
        }
    }
    if (board[0][2] == "O" && board[1][1] == "O")
    {
        if (board[2][0] != "X")
        {
            row = 2;
            return col = 0;
        }
    }
    //Defense Move
    //Vertical Case
    for (int j = 0; j < SIZE; j++)
    {
        if (board[j][0] == "X")
        {
            num_Col0++;
            //cout << "num_Col0:" << num_Col0 << endl;
        }
    }

    for (int j = 0; j < SIZE; j++)
    {
        if (board[j][1] == "X")
        {
            num_Col1++;
            //cout << "num_Col1:" << num_Col1 << endl;
        }
    }

    for (int j = 0; j < SIZE; j++)
    {
        if (board[j][2] == "X")
        {
            num_Col2++;
            //cout << "num_Col2:" << num_Col2 << endl;
        }
    }

    if (num_Col0 >= 2)
    {
        x = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if ((board[j][x] != "X") && (board[j][x] != "O"))
            {
                row = j;
                return col = x;
            }
        }
    }
    if (num_Col1 >= 2)
    {
        x = 1;
        for (int j = 0; j < SIZE; j++)
        {
            if ((board[j][x] != "X") && (board[j][x] != "O"))
            {
                row = j;
                return col = x;
            }
        }
    }
    if (num_Col2 >= 2)
    {
        x = 2;
        for (int j = 0; j < SIZE; j++)
        {
            if ((board[j][x] != "X") && (board[j][x] != "O"))
            {
                row = j;
                return col = x;
            }
        }
    }
    //Horizontal case
    //Loop through each row
    for (int j = 0; j < SIZE; j++)
    {
        if (board[0][j] == "X")
        { 
            num_Row0++;
        }
    }

    for (int j = 0; j < SIZE; j++)
    {
        if (board[1][j] == "X")
        {
            num_Row1++;
        }
    }

    for (int j = 0; j < SIZE; j++)
    {
        if (board[2][j] == "X")
        {
            num_Row2++;
        }
    }

    if (num_Row0 >= 2)
    {
        y = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if ((board[y][j] != "O") && (board[y][j] != "X"))
            {
                row = y;
                return col = j;
            }
        }
    }
    if (num_Row1 >= 2)
    {
        y = 1;
        for (int j = 0; j < SIZE; j++)
        {
            if ((board[y][j] != "O") && (board[y][j] != "X"))
            {
                row = y;
                return col = j;
            }
        }
    }
    if (num_Row2 >= 2)
    {
        y = 2;
        for (int j = 0; j < SIZE; j++)
        {
            if ((board[y][j] != "O") && (board[y][j] != "X"))
            {
                row = y;
                return col = j;
            }
        }
    }
    //Diagonal1
    if (board[0][0] == "X" && board[1][1] == "X")
    {
        if (board[2][2] != "O")
        {
            row = 2;
            return col = 2;
        }
    }
    if (board[0][0] == "X" && board[2][2] == "X")
    {
        if (board[1][1] != "O")
        {
            row = 1;
            return col = 1;
        }
    }
    if (board[2][2] == "X" && board[1][1] == "X")
    {
        if (board[0][0] != "O")
        {
            row = 0;
            return col = 0;
        }
    }
    //Diagonal2
    if (board[2][0] == "X" && board[1][1] == "X")
    {
        if (board[0][2] != "O")
        {
            row = 0;
            return col = 2;
        }
    }
    if (board[0][2] == "X" && board[2][0] == "X")
    {
        if (board[1][1] != "O")
        {
            row = 1;
            return col = 1;
        }
    }
    if (board[0][2] == "X" && board[1][1] == "X")
    {
        if (board[2][0] != "O")
        {
            row = 2;
            return col = 0;
        }
    }
    //If all cases are not detected create valid random move 
    while (!validMove)
    {
        int a = rand() % SIZE;
        int b = rand() % SIZE;
        if ((board[a][b] != "X") && (board[a][b] != "O"))
        {
            row = a;
            return col = b;
        }
    }      
}

void displayBoard(string **b)
{
    cout << "Tic-tac-toe board:" << endl
         << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

bool userFirst()
{
    //set seed for random number generation
    srand(time(NULL));

    //generate a random number
    //0 for computer
    //1 for user
    int num = rand() % 2;
    if (num == 0)
    {
        return false;
    }
    return true;
}

//Return true if player/computer with symbol (X or O) has won
bool currentPlayerWon(string **b, string symbol)
{
    //Horizontal case
    //Loop through each row
    for (int i = 0; i < SIZE; i++)
    {
        bool rowWinDetected = true;
        //Check all positions in row and see if they are the same symbol
        for (int j = 0; j < SIZE; j++)
        {
            if (b[i][j] != symbol)
            {
                rowWinDetected = false;
            }
        }
        if (rowWinDetected)
        {
            return true;
        }
    }

    //Vertical case
    //Loop through each column
    for (int i = 0; i < SIZE; i++)
    {
        bool colWinDetected = true;
        //Check all positions in column and see if they are the same symbol
        for (int j = 0; j < SIZE; j++)
        {
            if (b[j][i] != symbol)
            {
                colWinDetected = false;
            }
        }
        if (colWinDetected)
        {
            return true;
        }
    }

    //Diagonal case #1
    bool diagonal1WinDetected = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (b[i][i] != symbol)
        {
            diagonal1WinDetected = false;
        }
    }
    if (diagonal1WinDetected)
    {
        return true;
    }

    //Diagonal case #2
    bool diagonal2WinDetected = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (b[(SIZE - 1) - i][i] != symbol)
        {
            diagonal2WinDetected = false;
        }
    }
    if (diagonal2WinDetected)
    {
        return true;
    }

    //otherwise win not diagonal2WinDetected
    return false;
}
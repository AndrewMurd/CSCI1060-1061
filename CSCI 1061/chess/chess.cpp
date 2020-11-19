#include <cstdlib>
#include "chess.h"

Board::Board()
{
    board[0][0] = 'R';
    board[1][0] = 'N';
    board[2][0] = 'B';
    board[3][0] = 'Q';
    board[4][0] = 'K';
    board[5][0] = 'B';
    board[6][0] = 'N';
    board[7][0] = 'R';

    for (int i = 0; i < 7; ++i)
    {
        board[i][1] = 'P';
        board[i][6] = 'P';
    }

    board[0][7] = 'R';
    board[1][7] = 'N';
    board[2][7] = 'B';
    board[3][7] = 'Q';
    board[4][7] = 'K';
    board[5][7] = 'B';
    board[6][7] = 'N';
    board[7][7] = 'R';
}

const char &Board::get_square(const string &loc) const
{
    char s[2];
    s[0] = loc.at(1);
    s[1] = '\0';

    int i = loc.at(0) - 'a';
    int j = atoi(s) - 1;
    return board[i][j];
}

char &Board::get_square(const string &loc)
{
    char s[2];
    s[0] = loc.at(1);
    s[1] = '\0';

    int i = loc.at(0) - 'a';
    int j = atoi(s) - 1;
    return board[i][j];
}

void Chess::add_player(const string &std)
{
    cout << "Not implemented." << endl;
}

void Chess::set_board()
{
    
}

void Chess::prn_board()
{
    cout << "Not implemented." << endl;
}

Chess::Chess()
{

}
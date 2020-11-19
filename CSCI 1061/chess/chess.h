#ifndef __chess_h__
#define __chess_h__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Board
{
    protected:
        char board[8][8];

    public:
        Board();
        const char &get_square(const string& loc) const;
        char &get_square(const string &loc);
};

class Piece
{
    protected:
        string location;

    public:
        virtual void move(const string& mv);
};

class Pawn : public Piece
{
    protected:
        string symbol; 

    public: 
        
}; 

class Chess
{
    protected:
        vector <string> _players;
  
    public:
        Chess();
        void add_player(const string &std);
        void set_board();
        void prn_board();
};

#endif
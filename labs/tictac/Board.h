#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.
class Board {
    private:
        char brd[9];
        char movecount = 0;
        bool gameover;
        char lastplayed;
        int movenumber;
    public:
        Board();
        char checkWin();
        void add_move(int movenum, char player, int row, int column);
        std::string getstatus();

};

#endif

#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main()
{
    Board board;

    std::string line;
    while (getline(std::cin, line))
    {
        board.checkWin();
        Move move(line);
        if (board.getgame() == false)
        {
            
            board.add_move(move.getmovenum(), move.getplayer(), move.getrow(), move.getcolumn());
        }
        else
        {
            board.getstatus();
        }
    }
}
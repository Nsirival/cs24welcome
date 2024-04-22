#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>
#include <fstream>



int main()
{
    Board board;
    std::string line;
    while(getline(std::cin, line)){
        Move move(line);
        board.add_move(move.getmovenum(), move.getplayer(), move.getrow(), move.getcolumn());

    }
    board.getstatus();


}

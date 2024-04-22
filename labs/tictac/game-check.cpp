#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    

    Board board;
    
    std::string line;
    while (getline(std::cin, line))
    {
        board.checkWin();
        
            try{
            Move move (line);    
            board.add_move(move.number, (char)move.player, move.row, move.column);   
            } catch (const ParseError & w){
                std::cout << "Parse error.\n";
                exit(1);
            } catch (const InvalidMove & f){
                std::cout << "Invalid move.\n";
                exit(2);
            }
        
    }
    
    board.getstatus();
    exit(0);
}
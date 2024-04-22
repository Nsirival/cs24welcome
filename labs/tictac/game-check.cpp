#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    bool verbose = false;

    if (argc == 2 && std::string(argv[1]) == "-v")
    {
        verbose = true;
    }

    if (verbose)
    {
        std::cout << "> ";
    }

    Board board;
    
    std::string line;
    while (getline(std::cin, line))
    {
        board.checkWin();
        Move move (line);
            try{
            board.add_move(move.number, move.player, move.row, move.column);   
            } catch (const ParseError & w){
                if(verbose) {
                    std::cout << "Parse error: " << w.what() << '\n';
                }
                else {
                    std::cout << "Parse error.\n";
                }
                exit(1);
            } catch (const InvalidMove & f){
                if(verbose) {
                    std::cout << "Invalid Move." << f.what() << '\n';
                }
                else {
                    std::cout << "Invalid Move.\n";
                }
                exit(2);
            }
        
    }
    
    board.getstatus();
        exit(0);
}
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
        Move move(line);
        if (board.getgame() == false)
        {
            try
            {
                board.add_move(move.getmovenum(), move.getplayer(), move.getrow(), move.getcolumn());
            }
            catch (const InvalidMove &e)
            {
                if (verbose)
                {
                    std::cout << "Invalid move." << e.what() << '\n';
                }
                else
                {
                    std::cout << "Invalid move.\n";
                }
            }
        }
        else
        {
            board.getstatus();
        }
    }
}
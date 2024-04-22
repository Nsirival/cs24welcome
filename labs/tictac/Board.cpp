#include "Errors.h"
#include "Board.h"
#include <iostream>
// Space for implementing Board functions.
Board::Board()
{
    for (int i = 0; i < 9; i++)
    {
        brd[i] = '0';
    }
    movecount = 0;
    gameover = false;
    lastplayed = '0';
}

char Board::checkWin()
{
    if (((brd[0] == brd[1]) && (brd[1] == brd[2])) && brd[1] != '0')
    {
        gameover = true;
        return (char)brd[1];
    }
    if (((brd[3] == brd[4]) && (brd[4] == brd[5])) && brd[4] != '0')
    {
        gameover = true;
        return (char)brd[4];
    }
    if (((brd[6] == brd[7]) && (brd[7] == brd[8])) && brd[7] != '0')
    {
        gameover = true;
        return (char)brd[7];
    }
    if (((brd[0] == brd[3]) && (brd[3] == brd[6])) && brd[3] != '0')
    {
        gameover = true;
        return (char)brd[3];
    }
    if (((brd[1] == brd[4]) && (brd[4] == brd[7])) && brd[4] != '0')
    {
        gameover = true;
        return (char)brd[4];
    }
    if (((brd[2] == brd[5]) && (brd[5] == brd[8])) && brd[5] != '0')
    {
        gameover = true;
        return (char)brd[5];
    }
    if (((brd[0] == brd[4]) && (brd[4] == brd[8])) && brd[4] != '0')
    {
        gameover = true;
        return (char)brd[4];
    }
    if (((brd[2] == brd[4]) && (brd[4] == brd[6])) && brd[4] != '0')
    {
        gameover = true;
        return (char)brd[4];
    }
    return '0';
}

void Board::add_move(int movenum, char player, int row, int column)
{  
    
    Board::checkWin();
    movecount++;
    if (movenum != movecount || lastplayed == player || gameover == true)
    {
        InvalidMove hi("Invalid move.");
        throw hi;
        exit(2);
    }
    int index = column - 1 + (row-1) * 3;
    if (brd[index] == 'X' || brd[index] == 'O')
    {
        InvalidMove hi("Invalid move.");
        throw hi;
        exit(2);
    }

    brd[index] = (char)player;
    
    lastplayed = player;
    
}

std::string Board::getstatus()
{
    char h = static_cast<char>(Board::checkWin());
    if (h == 'X')
    {
        std::cout << "Game over: X wins." << std::endl;
        exit(2);
    }
    if (h == 'O')
    {
        std::cout << "Game over: O wins." << std::endl;exit(2);
    }
    if ((h == '0') && movecount == 9)
    {
        std::cout << "Game over: Draw." << std::endl;exit(0);
    }
    if (movecount == 0)
    {
        std::cout <<"Game in progress: New game." << std::endl;exit(0);
    }
    
    
    if (lastplayed == 'O')
    {
       std::cout <<"Game in progress: X's turn." << std::endl;exit(0);
    }
    else
    {
        std::cout << "Game in progress: O's turn." << std::endl;exit(0);
    }
}


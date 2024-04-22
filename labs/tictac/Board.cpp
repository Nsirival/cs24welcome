#include "Errors.h"
#include "Board.h"

// Space for implementing Board functions.
Board::Board(){
    for(int i = 0; i < sizeof(brd)/(int)sizeof(brd[0]); i++){
        brd[i] = '0';
    }
}

char Board::checkWin(){
    if((brd[0] == brd[1]) & (brd [1] == brd[2])){
        return (char)brd[1];
    }
    if((brd[3] == brd[4]) & (brd [4] == brd[5])){
        return (char)brd[4];
    }
    if((brd[6] == brd[7]) & (brd [7] == brd[8])){
        return (char)brd[7];
    }
    if((brd[0] == brd[3]) & (brd [3] == brd[6])){
        return (char)brd[3];
    }
    if((brd[1] == brd[4]) & (brd [4] == brd[7])){
        return (char)brd[4];
    }
    if((brd[2] == brd[5]) & (brd [5] == brd[8])){
        return (char)brd[5];
    }
    if((brd[0] == brd[4]) & (brd [4] == brd[8])){
        return (char)brd[4];
    }
    if((brd[2] == brd[4]) & (brd [4] == brd[6])){
        return (char)brd[4];
    }
    return '0';
}

void Board::add_move(char player, int row, int column){
    if(brd[column-1+(row-1)*3] != 'X' && brd[column-1+(row-1)*3] != 'O'){
        if(row == 1){
            brd[column-1] = player;
        } else if(row == 2){
            brd[column-1 + 3] = player;
        } else if(row == 3){
            brd[column-1 + 6] = player;
        }
    }
    movecount ++;
}

std::string Board::getstatus(){
    if(movecount == 0){
        return "Game in progress: New game.";
    } 
    if(movecount == 9){
        return "someone won";
    }
    if(movecount %2 == 1){
        
        return "Game in progress: X's turn.";
    } else {
        return "Game in progress: O's turn.";
    }
    return "you fucked up";
}


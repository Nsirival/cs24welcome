#include "Errors.h"
#include "Move.h"
#include <iostream>
// 1 X B3
// 2 O A1
// 3 X C3
// 4 O A3
// 5 X A2
// 6 O C1
// 7 X B2
// 8 O B1
//   int  number;
//   char player;
//   int  row;
//   int  column;
//1 X B2
// Space for implementing Move functions.
Move::Move(const std::string& input){
    std::string ipt= Move::to_string();
    if(input.length() >= 6){
        
        if(isdigit(input[0]) && isspace(input[1])){
            number = (int)input[0];
        } else {
            std::cout << "Parse error." << std::endl;
            exit(1);
        } 
        if((input[2] == 'X' || input[2] == 'O')&& isspace(input[3])){
            player = (int)input[2];
        } else {
            std::cout << "Parse error." << std::endl;
            exit(1);
        }
        if(input[4] == 'A'){row = 1;}
        if(input[4] == 'B'){row = 2;}
        if(input[4] == 'C'){row = 3;}

        column = (int)input[5];

    }else {
        exit(1);
    }

    
    
};


std::string Move::to_string() const{
    // std::string str = "";
    // str += (std::string)number;
    // str += " ";
    // str += (std::string)player;
    // str += " ";
    // if (row == 1){str += "A";}
    // if (row == 2){str += "B";}
    // if (row == 3){str += "C";}
    // str += (std::string)column;
     return "h";
}
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
    int i = 1;
    if(input.length() >= 6){
        
        if(isdigit(input[0]) && isspace(input[1])){
            if(((int)input[0] -48<= 9) &&((int)input[0] -48>= 1)){
                number = (int)input[0] -48;
            } else {
            std::cout << "Parse error." << std::endl;
            exit(1);
            } 
        } else {
            std::cout << "Parse error." << std::endl;
            exit(1);
        } 
        while((isspace(input[i])) && (i < (int)input.length()-1)){
            i++;
        }
        if((input[i] == 'X' || input[i] == 'O') || (input[i] == 'x' || input[i] == 'o')){
            player = (int)input[i];
        } else {
            std::cout << "Parse error." << std::endl;
            exit(1);
        } 
        if(i < (int)input.length()){
            i++;
        } else {
            std::cout << "Parse error." << std::endl;
            exit(1);
        }
        while((isspace(input[i])) && (i < (int)input.length()-1)){
            i++;
        }

        if(input[i] == 'A' || input[i] == 'a'){
            row = 1;
        } else if(input[i] == 'B' || input[i] == 'b'){
            row = 2;
        } else if(input[i] == 'C' || input[i] == 'c'){
            row = 3;
        } else {
            std::cout << "Parse error." << std::endl;
            exit(1);
        }
        if(i < (int)input.length()){
            i++;
        } else {
            std::cout << "Parse error." << std::endl;
            exit(1);
        }
        if((input[i] == '1') || (input[i] == '2') || (input[i] == '3')){
            column = (int)input[i]-48;
        }else {
            std::cout << "Parse error." << std::endl;
            exit(1);
        }

    }else {
        exit(1);
        std::cout << "Parse error." << std::endl;
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
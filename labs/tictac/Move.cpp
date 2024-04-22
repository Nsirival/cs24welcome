#include "Errors.h"
#include "Move.h"
#include <iostream>

// Space for implementing Move functions.
Move::Move(const std::string &input)
{
    column = 0;
    row = 0;
    int num = 0;
    for (int i = 0; i < (int)input.length(); i++)
    {
        if (!isspace(input[i]))
        {
            if (num == 0)
            {
                if ((int)input[i] - 48 > 0 && (int)input[i] - 48 < 10 && i == 0)
                {
                    number = (int)input[i] - 48;
                }
                else
                {
                    ParseError hi("Parse error.");
                    throw hi;
                    exit(1);
                }
            }
            if (num == 1)
            {
                if ((input[i] == 'X' || input[i] == 'x') && isspace(input[i - 1]))
                {
                    player = 'X';
                }
                else if ((input[i] == 'O' || input[i] == 'o') && isspace(input[i - 1]))
                {
                    player = 'O';
                }
                else
                {
                    ParseError hi("Parse error.");
                    throw hi;
                    exit(1);
                }
            }
            if (num == 2)
            {
                if ((input[i] == 'A' || input[i] == 'a') && isspace(input[i - 1]))
                {
                    row = 1;
                }
                else if ((input[i] == 'B' || input[i] == 'b') && isspace(input[i - 1]))
                {
                    row = 2;
                }
                else if ((input[i] == 'C' || input[i] == 'c') && isspace(input[i - 1]))
                {
                    row = 3;
                }
                else
                {
                    ParseError hi("Parse error.");
                    throw hi;
                    exit(1);
                }
            }
            if (num == 3)
            {
                if (((input[i] == '1') || (input[i] == '2') || (input[i] == '3')) && isalnum(input[i - 1]))
                {

                    column = (int)input[i] - 48;
                }
                else
                {
                    ParseError hi("Parse error.");
                    throw hi;
                    exit(1);
                }
            }
            if (num == 4)
            {
                if (!(input[i] == '#') || !(isspace(input[i - 1])))
                {
                    ParseError hi("Parse error.");
                    throw hi;
                    exit(1);
                }
            }

            num++;
        }
    }
    if (num < 4)
    {
        ParseError hi("Parse error.");
        throw hi;
        exit(1);
    }

};

std::string Move::to_string() const
{
    std::string d;
    if (row == 1)
    {
        d = "A";
    }
    else if (row == 2)
    {
        d = "B";
    }
    else if (row == 3)
    {
        d = "C";
    }
    
    return std::to_string(number) + " " + (char)player + " " + d + std::to_string(column);
}
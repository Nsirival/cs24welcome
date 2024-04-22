#include "Errors.h"
#include "Move.h"
#include <iostream>

// Space for implementing Move functions.
Move::Move(const std::string &input)
{
    int count = 0;
    for (int i = 0; i < (int)input.length(); i++)
    {
        if (isalnum(input[i]))
        {
            count++;
        }
    }
    if (count < 4)
    {
        std::cout << "Parse error." << std::endl;
        exit(1);
    }

    int i = 1;

    if (!isdigit(input[0]) && !isspace(input[1]))
    {
        std::cout << "Parse error." << std::endl;
        exit(1);
    }
    if (((int)input[0] - 48 > 9) || ((int)input[0] - 48 < 1))
    {
        std::cout << "Parse error." << std::endl;
        exit(1);
    }
    number = (int)input[0] - 48;

    while (isspace(input[i]) && i < (int)input.length() - 1)
    {
        i++;
    }

    if ((input[i] == 'X' || input[i] == 'x') && isspace(input[i + 1]))
    {
        i++;
        player = 'X';
    }
    else if ((input[i] == 'O' || input[i] == 'o') && isspace(input[i + 1]))
    {
        i++;
        player = 'O';
    }
    else
    {
        std::cout << "Parse error." << std::endl;
        exit(1);
    }
    while ((isspace(input[i])) && (i < (int)input.length() - 1))
    {
        i++;
    }

    if (input[i] == 'A' || input[i] == 'a')
    {
        i++;
        row = 1;
    }
    else if (input[i] == 'B' || input[i] == 'b')
    {
        i++;
        row = 2;
    }
    else if (input[i] == 'C' || input[i] == 'c')
    {
        i++;
        row = 3;
    }
    else
    {
        std::cout << "Parse error." << std::endl;
        exit(1);
    }
    if ((input[i] == '1') || (input[i] == '2') || (input[i] == '3'))
    {
        
        column = (int)input[i] - 48;
        i++;
    }
    else
    {
        std::cout << "Parse error." << std::endl;
        exit(1);
    }
    if (i < (int)input.length() - 1)
    {
        if (!isspace(input[i]))
        {
            std::cout << "Parse error." << std::endl;
            exit(1);
        }
        else
        {
            while ((isspace(input[i])) && (i < (int)input.length() - 1))
            {
                i++;
            }
            if (input[i] != '#')
            {
                std::cout << "Parse error." << std::endl;
                exit(1);
            }
        }
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
    return std::to_string(number) + " " + std::to_string(player) + " " + d + std::to_string(column);
}
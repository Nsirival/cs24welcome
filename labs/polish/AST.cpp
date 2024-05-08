#include "AST.h"
#include "Nodes.h"
#include "Stack.h"
#include <sstream>
#include <iostream>
#include <stdexcept>

AST *AST::parse(const std::string &expression)
{
    std::string token;
    std::istringstream stream(expression);
    Stack stack;

    try
    {
        while (stream >> token)
        {
            if (token == "~")
            {
                if (stack.root == nullptr)
                {
                    throw std::runtime_error("Not enough operands.");
                }
                AST *right = stack.pop();
                stack.push(new neg(right));
            }
            else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
            {
                if (stack.root == nullptr)
                {
                    throw std::runtime_error("Not enough operands.");
                }
                AST *right = stack.pop();
                if (stack.root == nullptr)
                {
                    delete right;
                    throw std::runtime_error("Not enough operands.");
                }
                AST *left = stack.pop();
                if (token == "+")
                {
                    stack.push(new add(left, right));
                }
                else if (token == "-")
                {
                    stack.push(new sub(left, right));
                }
                else if (token == "*")
                {
                    stack.push(new mult(left, right));
                }
                else if (token == "/")
                {
                    stack.push(new divd(left, right));
                }
                else if (token == "%")
                {
                    stack.push(new mod(left, right));
                }
            }
            else if (isdigit(token[0]) || token[0] == '-' || token[0] == '+')
            {
                char *end;
                double result = strtod(token.c_str(), &end);
                if (*end != '\0')
                {
                    throw std::runtime_error("Invalid token: " + token);
                }
                stack.push(new nodes(result));
            }
            else
            {
                throw std::runtime_error("Invalid token: " + token);
            }
        }

        if (stack.root == nullptr)
        {
            throw std::runtime_error("No input.");
        }
        AST *root = stack.pop();

        if (stack.root != nullptr)
        {
            delete root;
            throw std::runtime_error("Too many operands.");
        }

        return root;
    }
    catch (const std::runtime_error &e)
    {
        // Clean up all remaining nodes in the stack.
        while (stack.root != nullptr)
        {
            delete stack.pop();
        }
        throw; // Rethrow the exception after cleanup.
    }
}
#include "AST.h"
#include "Nodes.h"
#include "Stack.h"
#include <sstream>


AST *AST::parse(const std::string &expression)
{
    std::string token;
    std::istringstream stream(expression);
    Stack stack;

    while (stream >> token)
    {
        if (isdigit(token[0]) || token[0] == '-' || token[0] == '+')
        {
            char *end;
            double result = strtod(token.c_str(), &end);
            if (end == token.c_str() || *end != '\0')
            {
                stack.push(new nodes(result));
            }
        }
        else if (token == "+")
        {
            if (stack.root == nullptr)
            {
                throw std::runtime_error("Not enough operands");
            }
            AST *right = stack.pop();
            if (stack.root == nullptr)
            {
                throw std::runtime_error("Not enough operands");
            }
            AST *left = stack.pop();
            stack.push(new add(left, right));
        }
        else if (token == "-")
        {
            if (stack.root == nullptr)
            {
                throw std::runtime_error("Not enough operands");
            }
            AST *right = stack.pop();
            if (stack.root == nullptr)
            {
                throw std::runtime_error("Not enough operands");
            }
            AST *left = stack.pop();
            stack.push(new sub(left, right));
        }
        else if (token == "*")
        {
            if (stack.root == nullptr)
            {
                throw std::runtime_error("Not enough operands");
            }
            AST *right = stack.pop();
            if (stack.root == nullptr)
            {
                throw std::runtime_error("Not enough operands");
            }
            AST *left = stack.pop();
            stack.push(new mult(left, right));
        }
        else if (token == "/")
        {
            if (stack.root == nullptr)
            {
                throw std::runtime_error("Not enough operands");
            }
            AST *right = stack.pop();
            if (stack.root == nullptr)
            {
                throw std::runtime_error("Not enough operands");
            }
            AST *left = stack.pop();
            stack.push(new divd(left, right));
        }
        else if (token == "%")
        {
            if (stack.root == nullptr)
            {
                throw std::runtime_error("Not enough operands");
            }
            AST *right = stack.pop();
            if (stack.root == nullptr)
            {
                throw std::runtime_error("Not enough operands");
            }
            AST *left = stack.pop();
            stack.push(new mod(left, right));
        }
        else if (token == "~")
        {
            if (stack.root == nullptr)
            {
                throw std::runtime_error("Not enough operands");
            }
            AST *right = stack.pop();
            stack.push(new neg(right));
        }
    }

    

    AST *root = stack.pop();
    return root;
    
}

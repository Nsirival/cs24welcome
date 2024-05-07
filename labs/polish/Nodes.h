#ifndef NODES_H
#define NODES_H

#include "AST.h"

// Declare your AST subclasses here.
// Implement their member functions in Nodes.cpp.

struct nodes : public AST
{
    double data;
    nodes(double data);
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};
struct neg : public AST
{
    AST *one;
    neg(AST *single);
    ~neg();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};
struct add : public AST
{
    AST *leftt;
    AST *rightt;

    add(AST *left, AST *right);
    ~add();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};
struct sub : public AST
{

    AST *leftt;
    AST *rightt;
    sub(AST *left, AST *right);
    ~sub();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};
struct mult : public AST
{

    AST *leftt;
    AST *rightt;
    mult(AST *left, AST *right);
    ~mult();

    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};
struct divd : public AST
{

    AST *leftt;
    AST *rightt;
    divd(AST *left, AST *right);
    ~divd();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};
struct mod : public AST
{

    AST *leftt;
    AST *rightt;
    mod(AST *left, AST *right);
    ~mod();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

#endif

#include "Nodes.h"
#include <cmath>
#include <sstream>
#include <string>

// This creates the number format the autograder expects:
std::string format(double number)
{
  std::ostringstream stream;
  stream << number;
  return stream.str();
}

// Implement your AST subclasses' member functions here.
nodes::nodes(double info)
{
  data = info;
}
std::string nodes::prefix() const
{
  return format(value());
}
std::string nodes::postfix() const
{
  return format(value());
}
double nodes::value() const
{
  return data;
}

neg::neg(AST *single) { one = single; }
neg::~neg(){
  delete one;
}
std::string neg::prefix() const
{
  return "- " + one->prefix();
}
std::string neg::postfix() const
{
  return one->prefix() + " -";
}
double neg::value() const
{
  return -one->value();
}

add::add(AST *left, AST *right)
{
  leftt = left;
  rightt = right;
}
add::~add()
{
  delete leftt;
  delete rightt;
}
std::string add::prefix() const
{
  return "+ " + leftt->prefix() + " " + rightt->prefix();
}
std::string add::postfix() const
{return leftt->postfix() + " " + rightt->postfix() + " +";
}
double add::value() const
{
  return leftt->value() + rightt->value();
}

sub::sub(AST *left, AST *right)
{
  leftt = left;
  rightt = right;
}
sub::~sub()
{
  delete leftt;
  delete rightt;
}
std::string sub::prefix() const
{return "- " + leftt->prefix() + " " + rightt->prefix();
}
std::string sub::postfix() const
{return leftt->postfix() + " " + rightt->postfix() + " -";
}
double sub::value() const
{
  return leftt->value() - rightt->value();
}
mult::mult(AST *left, AST *right)
{
  leftt = left;
  rightt = right;
}
mult::~mult()
{
  delete leftt;
  delete rightt;
}
std::string mult::prefix() const
{return "* " + leftt->prefix() + " " + rightt->prefix();
}
std::string mult::postfix() const
{return leftt->postfix() + " " + rightt->postfix() + " *";
}
double mult::value() const
{return leftt->value() * rightt->value();
}
divd::divd(AST *left, AST *right)
{
  leftt = left;
  rightt = right;
}
divd::~divd()
{
  delete leftt;
  delete rightt;
}
std::string divd::prefix() const
{return "/ " + leftt->prefix() + " " + rightt->prefix();
}
std::string divd::postfix() const
{return leftt->postfix() + " " + rightt->postfix() + " /";
}
double divd::value() const
{
  if (rightt->value() == 0){
    throw std::runtime_error("Division by zero.");
  }
  return leftt->value() / rightt->value();
}
mod::mod(AST *left, AST *right)
{
  leftt = left;
  rightt = right;
}
mod::~mod()
{
  delete leftt;
  delete rightt;
}
std::string mod::prefix() const
{return "% " + leftt->prefix() + " " + rightt->prefix();
}
std::string mod::postfix() const
{return leftt->postfix() + " " + rightt->postfix() + " %";
}
double mod::value() const
{
  if(rightt->value() == 0){
    throw std::runtime_error("Division by zero.");
  }
  return fmod(leftt->value(), rightt->value());
}

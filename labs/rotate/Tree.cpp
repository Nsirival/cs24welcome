#include "Tree.h"
#include "stdexcept"

// size_t Tree::recursivecount(Node *start)
// {
//     if (start == nullptr)
//     {
//         return 0;
//     }
//     // if (start->downleft == nullptr && start->downright == nullptr)
//     // {
//     //     return 1;
//     // }
//     // else if (start->downleft == nullptr)
//     // {
//     //     return 1 + recursivecount(start->downright);
//     // }
//     // else if (start->downright == nullptr)
//     // {
//     //     return 1 + recursivecount(start->downleft);
//     // }

//     return (size_t)(1 + recursivecount(start->downleft) + recursivecount(start->downright));
// }

void Tree::recursiveclear(Node *start)
{
    if (start != nullptr)
    {
        recursiveclear(start->downright);
        recursiveclear(start->downleft);
        delete start;
        start = nullptr;
    }
}

size_t Tree::recursivefind(Node *start, std::string value)
{
    if (start != nullptr)
    {
        if (start->data == value)
        {
            randomnum = start->index;
            int s = randomnum;
            randomnum = -1;
            return s;
        }
        else
        {
            recursivefind(start->downleft, value);
            recursivefind(start->downright, value);
        }
    }
    return randomnum;
}

Tree::Tree()
{
    hi = nullptr;
}

Tree::~Tree()
{
    delete hi;
}

void Tree::clear()
{
    recursiveclear(hi);
}

size_t Tree::count() const
{
    return nodecount;
}

bool Tree::contains(const std::string &s)
{
    if ((int)Tree::recursivefind(hi, s) == -1)
    {
        return false;
    }
    return true;
}

size_t Tree::find(const std::string &s)
{
    if (Tree::contains(s) == true)
    {
        return Tree::recursivefind(hi, s);
    }
    return (size_t)1;
}

std::string Tree::lookup(size_t index)
{
    if (index > nodecount)
    {
        throw std::out_of_range("Index out of range");
    }
    return "hi";
}

void Tree::print() const
{
    //((a b c) d (- e f))
}

void Tree::remove(size_t index)
{
}

void Tree::insert(const std::string &s)
{
}
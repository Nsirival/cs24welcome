#include "Tree.h"
#include "Node.h"
#include "iostream"

void Tree::recursivedelete(Node *rooot)
{
    if (rooot != nullptr)
    {
        recursivedelete(rooot->downleft);
        recursivedelete(rooot->downright);
        delete rooot;
    }
}
size_t Tree::recursivecount(Node *rooot) const
{
    if (rooot != nullptr)
    {
        return 1 + recursivecount(rooot->downleft) + recursivecount(rooot->downright);
    }
    return 0;
}

size_t Tree::recursivefind(Node *rooot, std::string s) const
{
    if (rooot == nullptr)
    {
        return -1;
    }
    if (s == rooot->data)
    {
        return rooot->index;
    }
    if (s < rooot->data)
    {
        return recursivefind(rooot->downleft, s);
    }
    else
    {
        return recursivefind(rooot->downright, s);
    }
}
void Tree::recursiveprint(Node *rooot) const
{

    if (rooot->downleft != nullptr || rooot->downright != nullptr)
    {
        std::cout << "(";
    }
    if (rooot->downleft == nullptr && rooot->downright == nullptr)
    {
        std::cout << rooot->data;
    }
    else if (rooot->downleft == nullptr && rooot->downright != nullptr)
    {
        std::cout << "- " << rooot->data << " ";
        recursiveprint(rooot->downright);
    }
    else if (rooot->downleft != nullptr && rooot->downright == nullptr)
    {
        recursiveprint(rooot->downleft);

        std::cout << " " << rooot->data << " -";
    }
    else if (rooot->downleft != nullptr && rooot->downright != nullptr)
    {
        recursiveprint(rooot->downleft);
        std::cout << " " << rooot->data << " ";
        recursiveprint(rooot->downright);
    }
    if (rooot->downleft != nullptr || rooot->downright != nullptr)
    {
        std::cout << ")";
    }
}
void Tree::recursiveinsert(Node *rooot, Node *newnode)
{
    if (newnode->data <= rooot->data && rooot->downleft != nullptr)
    {
        rooot->index += 1;
        incrementing(rooot->downright);
        recursiveinsert(rooot->downleft, newnode);
    }
    else if (newnode->data > rooot->data && rooot->downright != nullptr)
    {
        recursiveinsert(rooot->downright, newnode);
    }
    else if (newnode->data <= rooot->data && rooot->downleft == nullptr)
    {
        int temp = rooot->index;
        rooot->index += 1;
        incrementing(rooot->downright);
        newnode->index = temp;
        newnode->up = rooot;
        rooot->downleft = newnode;
    }
    else if (newnode->data > rooot->data && rooot->downright == nullptr)
    {
        newnode->up = rooot;
        rooot->downright = newnode;
    }
}

std::string Tree::recursivelookup(Node *rooot, size_t x) const
{
    if (rooot == nullptr)
    {
        throw std::out_of_range("Out of range");
    }
    if (x < rooot->index)
    {
        return recursivelookup(rooot->downleft, x);
    }
    else if (x > rooot->index)
    {
        return recursivelookup(rooot->downright, x);
    }
    else
    {
        return rooot->data;
    }
}
void Tree::incrementing(Node *rooot)
{
    if (rooot != nullptr)
    {
        rooot->index += 1;
        if (rooot->downleft != nullptr)
        {
            incrementing(rooot->downleft);
        }
        if (rooot->downright != nullptr)
        {
            incrementing(rooot->downright);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

Tree::Tree()
{
    root = nullptr;
}
Tree::~Tree()
{
    Tree::clear();
}
void Tree::clear()
{
    recursivedelete(root);
    root = nullptr;
};
size_t Tree::count() const
{
    return recursivecount(root);
};
bool Tree::contains(const std::string &s) const
{
    if (root == nullptr)
    {
        return false;
    }
    if (recursivefind(root, s) != (size_t)(-1))
    {
        return true;
    }
    return false;
};
size_t Tree::find(const std::string &s) const
{
    if (recursivefind(root, s) == (size_t)(-1))
    {
        return -1;
    }
    return recursivefind(root, s);
};
void Tree::insert(const std::string &s)
{
    num += 1;
    Node *hi = new Node(s);
    if (root == nullptr)
    {
        root = hi;
        root->index = 1;
    }
    else if (root != nullptr)
    {
        recursiveinsert(root, hi);
    }
};
std::string Tree::lookup(size_t index) const
{
    if (index > num)
    {
        throw std::out_of_range("Out of range.");
    }
    return recursivelookup(root, index);
};
void Tree::print() const
{
    if (root == nullptr)
    {
        std::cout << "-";
    }
    else
    {
        recursiveprint(root);
        std::cout << std::endl;
    }
};
void Tree::remove(size_t index){

};

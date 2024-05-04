
#include "Tree.h"
#include "Node.h"
#include "iostream"
#include "cmath"

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
    int index = 0;
    int x = 0;
    while(x == 0){
        if (recursivelookup(rooot, index) == s){
            x += 1;
        }
    }
    return index;
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

std::string Tree::recursivelookup(Node *rooot, size_t x) const
{
    if (rooot == nullptr)
    {
        throw std::out_of_range("Out of range");
    }
    if (x == rooot->index)
    {
        return rooot->data;
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
        throw std::out_of_range("Out of range");
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

Node *Tree::finder(Node *rooot, size_t index)
{
    if (rooot == nullptr)
    {
        return rooot;
    }
    if (index == rooot->index)
    { // find index
        return rooot;
    }
    if (index < rooot->index)
    {
        if (rooot->downleft != nullptr)
        {
            return finder(rooot->downleft, index);
        }
        else
        {
            throw std::out_of_range("Out of range");
        }
    }
    else
    {
        if (rooot->downright != nullptr)
        {
            return finder(rooot->downright, index);
        }
        else
        {
            throw std::out_of_range("Out of range");
        }
    }
}
void Tree::recursiveinsert(Node *rooot, Node *newnode)
{
    if (newnode->data <= rooot->data && rooot->downleft != nullptr)
    {
        rooot->index += 1;
        incrementing(rooot->downright);
        recursiveinsert(rooot->downleft, newnode);
        // rotate(rooot, 1);
    }
    else if (newnode->data > rooot->data && rooot->downright != nullptr)
    {
        recursiveinsert(rooot->downright, newnode);
        // rotate(rooot, 0);
    }
    else if (newnode->data <= rooot->data && rooot->downleft == nullptr)
    {
        int temp = rooot->index;
        rooot->index += 1;
        incrementing(rooot->downright);
        newnode->index = temp;
        newnode->up = rooot;
        rooot->downleft = newnode;
        // rotate(rooot, 1);
    }
    else if (newnode->data > rooot->data && rooot->downright == nullptr)
    {
        size_t temp = rooot->index;
        newnode->index = temp + 1;
        newnode->up = rooot;
        rooot->downright = newnode;
        // rotate(rooot, 0);
    }
}

size_t Tree::imbalance(Node *rooot)
{
    if (rooot->downleft != nullptr && rooot->downright != nullptr)
    {
        return 2 + imbalance(rooot->downleft) + imbalance(rooot->downright);
    }
    else if (rooot->downleft == nullptr && rooot->downright != nullptr)
    {
        return 1 + imbalance(rooot->downright);
    }
    else if (rooot->downleft != nullptr && rooot->downright == nullptr)
    {
        return 1 + imbalance(rooot->downleft);
    }
    else
    {
        return 0;
    }
}

size_t Tree::getbalance(Node *rooot)
{
    return abs(imbalance(rooot->downleft) - imbalance(rooot->downright));
}

Node *Tree::balance(Node *rooot, int rotation)
{

    if (rooot != nullptr)
    {
        size_t diff = getbalance(rooot);
        if (rooot->downleft != nullptr && rotation == 1)
        {
            rotate(rooot, 1);
            if (getbalance(rooot->downleft) >= diff) // not sure if >= or <
            {
                rotate(rooot->downleft, 0);
            }
            else
            {
                diff = getbalance(rooot->downleft);
            }
        }
        if (rooot->downright != nullptr && rotation == 0)
        {
            rotate(rooot, 0);
            if (getbalance(rooot->downright) >= diff)
            {
                rotate(rooot->downright, 1);
            }
        }
    }
    return rooot;
}

void Tree::rotate(Node *rooot, int LR)
{
    if (LR == 1)
    {
        // rotate right
        if (rooot != nullptr)
        {
            if (rooot->downleft != nullptr)
            {
                if (rooot->downleft->downright != nullptr)
                {
                    rooot->downleft->downright->up = rooot;
                }

                rooot->downleft = rooot->downleft->downright;
                rooot->downleft->downright = rooot;
                if (rooot == root)
                {
                    rooot->downleft->up = nullptr;
                    rooot->up = rooot->downleft;
                    root = rooot->downleft;
                }
                else
                {
                    if (rooot->up->downleft == rooot)
                    {
                        rooot->up->downleft = rooot->downleft;
                    }
                    if (rooot->up->downright == rooot)
                    {
                        rooot->up->downright = rooot->downleft;
                    }
                    rooot->downleft->up = rooot->up;
                    rooot->up = rooot->downleft;
                }
            }
        }
    }
    else if (LR == 0)
    {
        // rotate left
        if (rooot != nullptr)
        {
            if (rooot->downright != nullptr)
            {
                if (rooot->downright->downleft != nullptr)
                {
                    rooot->downright->downleft->up = rooot;
                }
                rooot->downright = rooot->downright->downleft;
                rooot->downright->downleft = rooot;
                if (rooot == root)
                {
                    rooot->downright->up = nullptr;
                    rooot->up = rooot->downright;
                    root = rooot->downright;
                }
                else
                {
                    if (rooot->up->downleft == rooot)
                    {
                        rooot->up->downleft = rooot->downright;
                    }
                    if (rooot->up->downright == rooot)
                    {
                        rooot->up->downright = rooot->downright;
                    }
                    rooot->downright->up = rooot->up;
                    rooot->up = rooot->downright;
                }
            }
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
    if (recursivefind(root, s) == (size_t)(-1))
    {
        return false;
    }
    return true;
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
    Node *hi = new Node(s);
    if (root == nullptr)
    {
        root = hi;
        root->index = 0;
    }
    else if (root != nullptr)
    {
        recursiveinsert(root, hi);
    }
};
std::string Tree::lookup(size_t index) const
{
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
    }
    std::cout << std::endl;
};
void Tree::remove(size_t index)
{
    Node *hi = finder(root, index);
    if (hi == nullptr)
    {
        return;
    }
    if (hi->downright == nullptr && hi->downleft == nullptr)
    {
        if (hi == root)
        {
            delete root;
            root = nullptr;
        }
        else
        {
            if (hi->up->downleft == hi)
            {
                hi->up->downleft = nullptr;
            }
            else
            {
                hi->up->downright = nullptr;
            }
            delete hi;
        }
    }
    else if (hi->downleft == nullptr && hi->downright != nullptr)
    {
        if (hi == root)
        {
            root = hi->downright;
            hi->downright->up = nullptr;
        }
        else
        {
            hi->downright->up = hi->up;
            if (hi->up->downleft == hi)
            {
                hi->up->downleft = hi->downright;
            }
            else
            {
                hi->up->downright = hi->downright;
            }
        }
        delete hi;
    }
    else if (hi->downleft != nullptr && hi->downright == nullptr)
    {
        if (hi == root)
        {
            root = hi->downleft;
            hi->downleft->up = nullptr;
        }
        else
        {
            hi->downleft->up = hi->up;
            if (hi->up->downleft == hi)
            {
                hi->up->downleft = hi->downleft;
            }
            else
            {
                hi->up->downright = hi->downleft;
            }
        }
        delete hi;
    }
    else
    {
    }
};
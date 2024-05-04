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
    if (s == rooot->data)
    { // find index
        if (rooot->downleft != nullptr)
        {
            if (rooot->downleft->data == s)
            {
                return recursivefind(rooot->downleft, s);
            }
            else
            {
                return rooot->index;
            }
        }
        else
        {
            return rooot->index;
        }
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
        rooot->weight += 1;
        incrementing(rooot->downright);
        recursiveinsert(rooot->downleft, newnode);
    }
    else if (newnode->data > rooot->data && rooot->downright != nullptr)
    {
        rooot->weight += 1;
        recursiveinsert(rooot->downright, newnode);
    }
    else if (newnode->data <= rooot->data && rooot->downleft == nullptr)
    {
        int temp = rooot->index;
        rooot->weight += 1;
        rooot->index += 1;
        incrementing(rooot->downright);
        newnode->index = temp;
        newnode->up = rooot;
        rooot->downleft = newnode;
    }
    else if (newnode->data > rooot->data && rooot->downright == nullptr)
    {
        rooot->weight += 1;
        size_t temp = rooot->index;
        newnode->index = temp + 1;
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
void Tree::put(Node *rooot, size_t index)
{
    if (rooot != nullptr)
    {

        if (rooot->downleft != nullptr)
        {
            put(rooot->downleft, index);
        }
        if (rooot->downright != nullptr)
        {
            put(rooot->downright, index);
        }
        if (rooot->index > index)
        {
            rooot->index -= 1;
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
Node* Tree::balance(size_t index)
{
    size_t lefth = -1;
    size_t righth = -1;
    size_t current = -1;
    size_t otherside = 0;
    
    if(root != nullptr){
        if(root->downright != nullptr && root->downleft != nullptr){
            current = abs(root->downright->weight - root->downleft->weight);
        } else if(root->downright == nullptr && root->downleft != nullptr){
            current = root->downleft->weight;
        } else if(root->downright != nullptr && root->downleft == nullptr){
            current = root->downright->weight;
        } 

        if(index > root->index){
            if(root->downright != nullptr){
                if(root->downright->downright != nullptr){
                    otherside = root->downright->downright->weight;
                }
                if(root->downright->downleft != nullptr){
                    righth = abs((root->weight - root->downright->weight + root->downright->downleft->weight) - otherside);
                } else {
                    righth = abs((root->weight - root->downright->weight) - otherside);
                }
            } else {
                righth= abs(otherside);
            }
            if(root->downright != nullptr && righth < current){
                return root->downright;
            }
        } else if(index < root->index){
            if(root->downleft != nullptr){
                if(root->downleft->downleft != nullptr){
                    otherside = root->downleft->downleft->weight;
                }
                if(root->downleft->downright != nullptr){
                    lefth = abs((root->weight - root->downleft->weight + root->downleft->downright->weight) - otherside);
                } else {
                    lefth = abs((root->weight - root->downleft->weight) - otherside);
                }
            } else {
                lefth = abs(otherside);
            }
            if(root->downleft != nullptr && lefth < current){
                return root->downleft;
            }
        }   
    }
    return root;
}


void Tree::rotate(Node*child)
{
    if (child != root)
    {
        if (root->downleft != nullptr)
        {
            if (root->downleft == child)
            {
                root->downleft = root->downleft->downright;
                root->up = child;

                child->up = nullptr;
                child->downright = root;
                root = child;
            }
        }
        else if (root->downright != nullptr)
        {
            if (root->downright == child)
            {
                root->downright = root->downright->downleft;
                root->up = child;

                child->up = nullptr;
                child->downleft = root;
                root = child;
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
    num++;
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
    rotate(balance(hi->index));
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
void Tree::remove(size_t index){
    // Node *hi = finder(root, index);
    // if (hi == nullptr)
    // {
    //     return;
    // }
    // if (hi->downright == nullptr && hi->downleft == nullptr)
    // {
    //     if (hi == root)
    //     {
    //         delete root;
    //         root = nullptr;
    //     }
    //     else
    //     {
    //         if (hi->up->downleft == hi)
    //         {
    //             hi->up->downleft = nullptr;
    //         }
    //         else
    //         {
    //             hi->up->downright = nullptr;
    //         }
    //         delete hi;
    //     }
    //     put(root, index);
    //     findmin(root, 0);
    //     findmin(root, 1);
    //     rotate();
    // }
    // else if (hi->downleft == nullptr && hi->downright != nullptr)
    // {
    //     if (hi == root)
    //     {
    //         root = hi->downright;
    //         hi->downright->up = nullptr;
    //     }
    //     else
    //     {
    //         hi->downright->up = hi->up;
    //         if (hi->up->downleft == hi)
    //         {
    //             hi->up->downleft = hi->downright;
    //         }
    //         else
    //         {
    //             hi->up->downright = hi->downright;
    //         }
    //     }

    //     delete hi;
    //     put(root, index);
    //     findmin(root, 0);
    //     findmin(root, 1);
    //     rotate();
    // }
    // else if (hi->downleft != nullptr && hi->downright == nullptr)
    // {
    //     if (hi == root)
    //     {
    //         root = hi->downleft;
    //         hi->downleft->up = nullptr;
    //     }
    //     else
    //     {
    //         hi->downleft->up = hi->up;
    //         if (hi->up->downleft == hi)
    //         {
    //             hi->up->downleft = hi->downleft;
    //         }
    //         else
    //         {
    //             hi->up->downright = hi->downleft;
    //         }
    //     }

    //     delete hi;
    //     put(root, index);
    //     findmin(root, 0);
    //     findmin(root, 1);
    //     rotate();
    // }
    // else
    // {
    //     Node *n = finder(root, index + 1);

    //     if (n->downright != nullptr)
    //     {
    //         n->downright->up = n->up;
    //         n->up->downleft = n->downright;
    //     }

    //     n->downright = hi->downright;
    //     n->up = hi->up;
    //     n->downleft = hi->downleft;
    //     delete hi;
    //     put(root, index);
    //     findmin(root, 0);
    //     findmin(root, 1);
    //     rotate();
    // }
};

#include "Tree.h"
#include "Node.h"
#include "iostream"

void Tree::recursivedelete(Node *rooot)
{
    if (rooot != nullptr)
    {
        recursivedelete(rooot->downleft);
        recursivedelete(rooot->downright);
    }
    delete rooot;
}

size_t Tree::recursivecount(Node *rooot) const
{
    if (rooot != nullptr)
    {
        return 1 + recursivecount(rooot->downleft) + recursivecount(rooot->downright);
    }
    return 0;
}

size_t recursivefind(Node *rooot, const std::string &s) 
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
        recursivefind(rooot->downleft, s);
    }
    if (s > rooot->data)
    {
        recursivefind(rooot->downright, s);
    }
    return -1;
}

void Tree::recursiveinsert(Node *rooot, Node *newnode)
{
    if (newnode->data <= rooot->data && rooot->downleft != nullptr)
    {
        recursiveinsert(rooot->downleft, newnode);
    }
    else if (newnode->data > rooot->data && rooot->downright != nullptr)
    {
        recursiveinsert(rooot->downright, newnode);
    }
    else if (newnode->data <= rooot->data && rooot->downleft == nullptr)
    {
        newnode->up = rooot;
        rooot->downleft = newnode;
    }
    else if (newnode->data > rooot->data && rooot->downright == nullptr)
    {
        newnode->up = rooot;
        rooot->downright = newnode;
    }
}

// std::string Tree::recursiveindex(Node*rooot, int idx){
//     if (rooot!= nullptr){
//         index += 1;
//         recursiveindex(rooot->downleft, idx);
//         recursiveindex(rooot->downright, idx);

//     }
// }

// Node *Tree::promotion(Node *rooot)
// {
//     if (rooot != nullptr)
//     {
//         leftweight = nodecount(rooot->downleft);
//         leftweight = nodecount(rooot->downright);
//     }
// }

// int Tree::nodecount(Node *rooot)
// {
// }

void Tree::recursiveprint(Node *rooot)const
{

    if (rooot->downleft != nullptr || rooot->downright != nullptr)
    {
        std::cout << "(";
    }
    if (root->downleft == nullptr && root->downright == nullptr)
    {
        std::cout << root->data;
    }
    else if (root->downleft == nullptr && root->downright != nullptr)
    {
        std::cout << "- " << root->data << " ";
        recursiveprint(rooot->downright);
    }
    else if (root->downleft != nullptr && root->downright == nullptr)
    {
        recursiveprint(rooot->downleft);

        std::cout << " " << root->data << " -";
    }
    else
    {
        recursiveprint(rooot->downleft);
        std::cout << " " << root->data << " ";
        recursiveprint(rooot->downright);
    }

    if (rooot->downleft != nullptr || rooot->downright != nullptr)
    {
        std::cout << ")";
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
size_t Tree::count()const
{
    return recursivecount(root);
};
bool Tree::contains(const std::string &s)
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
size_t Tree::find(const std::string &s)const
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
    recursiveinsert(root, hi);
};
// std::string Tree::lookup(size_t index)const{

// };
void Tree::print()const
{
    if (root != nullptr)
    {
        recursiveprint(root);
    }

    std::cout << std::endl;
};
void Tree::remove(size_t index){

};

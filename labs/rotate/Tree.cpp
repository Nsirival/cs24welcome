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
    { // find index
        return 0;
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



// Node *Tree::promotion(Node *rooot)
// {
//     if (rooot != nullptr)
//     {
//         leftweight = nodecount(rooot->downleft);
//         leftweight = nodecount(rooot->downright);
//     }
// }

// std::string Tree::recursiveindex(Node*rooot, int idx){
//     if (rooot!= nullptr){
//         index += 1;
//         recursiveindex(rooot->downleft, idx);
//         recursiveindex(rooot->downright, idx);

//     }
// }

void Tree::indexassign(Node*rooot){
    
    if(rooot->downleft != nullptr){
        num += 1;
        rooot->downleft->index = num;
    } 
    if(rooot->downright != nullptr){
        num += 1;
        rooot->downright->index = num;
    }
    indexassign(rooot->downleft);
}

std::string Tree::recursivelookup(Node*rooot, size_t index) const{
    if(rooot == nullptr){
        throw std::out_of_range("Out of range");
    }
    std::string result = recursivelookup(rooot->downleft, index);
    if(!result.empty()){
        return result;
    }
    if (index == 0){
        return rooot->data;
    }
    index -=1;
    return recursivelookup(rooot->downright, index);    
}

// int Tree::nodecount(Node *rooot)
// {
// }



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
        root->index = 0;
    }
    else if(root != nullptr)
    {
        recursiveinsert(root, hi);

    }
};
std::string Tree::lookup(size_t index) const
{
    if (index > num){
        throw std::out_of_range("Out of range.");
    }
    return recursivelookup(root, index);
};
void Tree::print() const
{
    if (root != nullptr)
    {
        std::cout << std::endl;
        recursiveprint(root);
    }

    std::cout << std::endl;
};
void Tree::remove(size_t index){

};

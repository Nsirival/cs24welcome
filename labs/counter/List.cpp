#include "List.h"

Node::Node(const std::string &k, int d)
{
    key = k;
    data = d;
    prev = nullptr;
    next = nullptr;
}
// List Member Functions

List::List()
{
    head = nullptr;
    tail = nullptr;
}

List::~List()
{
    Node *x = head;
    while (x != nullptr)
    {
        Node *y = x->next;
        delete x;
        x = y;
    }
}

void List::insert(const std::string &k, int d)
{

    Node *y = new Node(k, d);
    if (tail == nullptr)
    {
        tail = y;
        head = y;
    }
    tail->next = y;
    y->prev = tail;
    tail = y;
}

Node *List::find(const std::string &k) const
{
    Node *y = head;
    while (y != nullptr)
    {
        if (y->key == k)
        {
            return y;
        }
        y = y->next;
    }
    return nullptr;
}
void List::remove(Node *n)
{
    if (n == nullptr)
    {
        return;
    }
    if (n->prev)
    {
        n->prev->next = n->next;
    }
    else
    {
        head = n->next;
    }

    if (n->next)
    {
        n->next->prev = n->prev;
    }
    else
    {
        tail = n->prev;
    }
    delete n;
}
bool List::empty() const
{
    return head == nullptr;
}

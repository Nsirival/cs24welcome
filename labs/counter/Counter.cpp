#include "Counter.h"

Counter::Iterator::Iterator(Node *n) : curr(n) {}

void Counter::Iterator::operator++()
{
    curr = curr->next;
}

bool Counter::Iterator::operator==(const Iterator &z) const
{
    return curr == z.curr;
}

bool Counter::Iterator::operator!=(const Iterator &z) const
{
    return curr != z.curr;
}

// Counter implementation
Counter::Counter() {}

Counter::~Counter() {}

size_t Counter::count() const
{
    return list.getcnt();
}

int Counter::total() const
{
    return list.gettot();
}

void Counter::inc(const std::string &k, int h)
{
    Node *n = list.find(k);
    if (n == nullptr)
    {

        list.insert(k, h);
    }
    else
    {
        list.updatevalue(n, h);
    }
}

void Counter::dec(const std::string &k, int h)
{
    Node *n = list.find(k);
    if (n != nullptr)
    {
        list.updatevalue(n, h);
        if (n->data <= 0)
        {
            list.remove(n);
        }
    }
}

void Counter::del(const std::string &k)
{
    Node *n = list.find(k);
    if (n != nullptr)
    {
        list.remove(n);
    }
}

int Counter::get(const std::string &k) const
{
    Node *n = list.find(k);
    if (n != nullptr)
    {
        return n->data;
    }
    else
    {
        return 0;
    }
}

void Counter::set(const std::string &k, int count)
{
    Node *n = list.find(k);
    if (n == nullptr)
    {
        list.insert(k, count);
    }
    else
    {
        n->data = count;
        if (n->data == 0)
        {
            list.remove(n);
        }
    }
}

Counter::Iterator Counter::begin() const
{
    return Iterator(list.getHead());
}

Counter::Iterator Counter::end() const
{
    return Iterator(nullptr);
}
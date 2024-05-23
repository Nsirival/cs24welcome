#include "Counter.h"
#include <functional> // For std::hash
#include "Index.h"
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
    return index.getcouunt();
}

int Counter::total() const
{
    return index.gettottal();
}

void Counter::inc(const std::string &k, int h)
{
    Node *n = index.find(k);
    if (n == nullptr)
        index.add(k, list.insert(k, h));
}

void Counter::dec(const std::string &k, int h)
{
    Node *n = index.find(k);
    if (n == nullptr)
        index.add(k, list.insert(k, h));
}

void Counter::del(const std::string &k)
{
    Node *n = index.find(k);
    if (n != nullptr)
    {
        index.rem(k);
    }
}

int Counter::get(const std::string &k) const
{
    Node *n = index.find(k);
    return n->data;
}

void Counter::set(const std::string &k, int count)
{
    Node *n = list.find(k);
    n->data = count;
}

Counter::Iterator Counter::begin() const
{
    return Iterator(list.getHead());
}

Counter::Iterator Counter::end() const
{
    return Iterator(nullptr);
}
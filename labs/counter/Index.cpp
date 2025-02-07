#include "Index.h"

Index::Index(size_t size) : cap(size)
{
    tab = new Listitem[cap];
    for (size_t i = 0; i < cap; ++i)
    {
        tab[i].clear();
    }
    couunt = 0;
    tottal = 0;
}

Index::~Index()
{
    delete[] tab;
}

size_t Index::hash(const std::string &k) const
{
    std::hash<std::string> hasher;
    return hasher(k) & (cap - 1);
}

void Index::add(const std::string &k, Node *n)
{
    size_t x = hash(k);
    size_t a = 0;
    while (tab[x].occupied && tab[x].isActive)
    {
        a++;
        x = (x + a * a) & (cap - 1);
    }
    tab[x].key = k;
    tab[x].node = n;
    tab[x].occupied = true;
    tab[x].isActive = true;
    couunt++;
    tottal += n->data;
}

Node *Index::find(const std::string &k) const
{
    size_t x = hash(k);
    size_t start = x;
    size_t a = 0;
    while (tab[x].occupied)
    {
        if (tab[x].isActive && tab[x].key == k)
        {
            return tab[x].node;
        }
        a++;
        x = (x + a * a) & (cap - 1);
        if (x == start)
            return nullptr;
    }
    return nullptr;
}

void Index::rem(const std::string &key)
{
    size_t x = hash(key);
    size_t a = 0;
    while (tab[x].occupied)
    {
        if (tab[x].isActive && tab[x].key == key)
        {
            couunt--;
            tottal -= tab[x].node->data;
            tab[x].isActive = false;
            tab[x].node = nullptr;
            return;
        }
        a++;
        x = (x + a * a) & (cap - 1);
    }
}

void Index::Listitem::clear()
{
    key.clear();
    node = nullptr;
    occupied = false;
    isActive = false;
}
#include "Index.h"
#include <cstring> // For memset

Index::Index(size_t size) : cap(size), cnt(0)
{
    tab = new Listitem[cap];
    for (size_t i = 0; i < cap; ++i)
    {
        tab[i].clear();
    }
}

Index::~Index()
{
    delete[] tab;
}

size_t Index::hash(const std::string &k) const
{
    std::hash<std::string> hasher;
    return hasher(k) % cap;
}

void Index::add(const std::string &k, Node *n)
{
    size_t x = hash(k);
    while (tab[x].occupied && tab[x].isActive)
    {
        x = (x + 1) % cap;
    }
    tab[x].key = k;
    tab[x].node = n;
    tab[x].occupied = true;
    tab[x].isActive = true;
    cnt++;

    if (cnt >= cap / 2)
    {
        grow();
    }
}

Node *Index::find(const std::string &k) const
{
    size_t x = hash(k);
    size_t start = x;

    while (tab[x].occupied)
    {
        if (tab[x].isActive && tab[x].key == k)
        {
            return tab[x].node;
        }
        x = (x + 1) % cap;
        if (x == start)
            return nullptr;
    }
    return nullptr;
}

void Index::rem(const std::string &key)
{
    size_t x = hash(key);
    while (tab[x].occupied)
    {
        if (tab[x].isActive && tab[x].key == key)
        {
            tab[x].isActive = false;
            cnt--;
            return;
        }
        x = (x + 1) % cap;
    }
}

void Index::rehash()
{
    size_t oldcap = cap;
    Listitem *oldtab = tab;

    cap *= 2;
    tab = new Listitem[cap];
    for (size_t i = 0; i < cap; ++i)
    {
        tab[i].clear();
    }
    cnt = 0;

    for (size_t i = 0; i < oldcap; i++)
    {
        if (oldtab[i].occupied && oldtab[i].isActive)
        {
            add(oldtab[i].key, oldtab[i].node);
        }
    }

    delete[] oldtab;
}

void Index::grow()
{
    rehash();
}

void Index::Listitem::clear()
{
    key.clear();
    node = nullptr;
    occupied = false;
    isActive = false;
}
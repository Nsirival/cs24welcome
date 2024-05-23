#include "Index.h"
static const size_t FNV_OFFSET_BASIS = 2166136261u;
static const size_t FNV_PRIME = 16777619u;


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
    size_t hash = FNV_OFFSET_BASIS;
    for (unsigned char c : k) {
        hash ^= c;
        hash *= FNV_PRIME;
    }
    return hash % cap;
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
    cnt++;
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
            tab[x].isActive = false;
            cnt--;
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
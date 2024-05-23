
#ifndef INDEX_H
#define INDEX_H

#include "List.h"
#include <string>
#include <functional> // For std::hash

class Index
{
private:
    struct Listitem
    {
        std::string key;
        Node *node = nullptr;
        bool occupied = false;
        bool isActive = true;

        Listitem() = default;
        void clear();
    };

    Listitem *tab;
    size_t cap;
    

    size_t hash(const std::string &k) const;

public:
    size_t couunt;
    int tottal;
    Index(size_t size = 262144);
    ~Index();

    Node *find(const std::string &k) const;

    void add(const std::string &k, Node *n);

    void rem(const std::string &k);
    size_t getcouunt() const { return couunt; }
    int gettottal() const { return tottal; }
};

#endif
#ifndef INDEX_H
#define INDEX_H

#include "List.h"
#include <string>

struct listitem {
    std::string key;
    Node* node;
    listitem* next;
    bool occupied;

    listitem(const std::string& k, Node* n, listitem* nxt)
        : key(k), node(n), next(nxt), occupied(false){}

};

class Index {
private:
    listitem** table;
    size_t capacity;
    size_t fnvHash(const std::string &k) const;
    size_t probe(size_t hash, size_t i) const; 
public:
    Index(size_t cap = 101);
    ~Index();

    void add(const std::string &k, Node *n);
    void rem(const std::string &k);
    Node *find(const std::string &k) const;
};

#endif
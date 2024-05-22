#include "Index.h"
#include <functional>

static const size_t FNV_PRIME = 16777619u;
static const size_t OFFSET_BASIS = 2166136261u;

Index::Index(size_t cap) : capacity(cap) {
    table = new listitem*[capacity]();
}

Index::~Index() {
    for (size_t i = 0; i < capacity; i++) {
        listitem *curr = table[i];
        while (curr != nullptr) {
            listitem *next = curr->next;
            delete curr;
            curr = next;
        }
    }
    delete[] table;
}

size_t Index::fnvHash(const std::string &k) const {
    size_t hash = OFFSET_BASIS;
    for (char c : k) {
        hash ^= (unsigned char)c;
        hash *= FNV_PRIME;
    }
    return hash % capacity;
}

void Index::add(const std::string &k, Node *n) {
    size_t x= fnvHash(k);
    table[x] = new listitem(k, n, table[x]);
}

void Index::rem(const std::string &k) {
    size_t x = fnvHash(k);
    listitem *curr = table[x], *prev = nullptr;
    while (curr != nullptr) {
        if (curr->key == k) {
            if (prev) prev->next = curr->next;
            else table[x] = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

Node* Index::find(const std::string &k) const {
    size_t x= fnvHash(k);
    for (listitem *curr = table[x]; curr != nullptr; curr = curr->next) {
        if (curr->key == k) return curr->node;
    }
    return nullptr;
}

#ifndef INDEX_H
#define INDEX_H

#include "List.h" 

#include <string>

class Index {
    private:
        
        struct listitem {
            std::string key;
            Node* node;
            listitem* next;

            listitem(const std::string& k, Node* n, listitem* next): key(k), node(n), next(n) {};

        };

        listitem**table;
        size_t capacity;

        size_t hash(const std::string&k) const;

    public:
        Index(size_t cap = 20);
        ~Index();


        void add(const std::string& k, Node* n);
        void rem(const std::string& k);

        Node* find(const std::string &k);
};

#endif

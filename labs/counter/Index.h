#ifndef INDEX_H
#define INDEX_H

#include "List.h" 

#include <string>
struct listitem {
            std::string key;
            Node* node;
            listitem* next;

            listitem(const std::string& k, Node* n, listitem* nxt): key(k), node(n), next(nxt) {};

        };


class Index {
    private:
        
        

        listitem**table;
        size_t capacity;

        size_t hash(const std::string&k) const;

    public:
        Index(size_t cap = 40);
        ~Index();


        void add(const std::string& k, Node* n);
        void rem(const std::string& k);

        Node* find(const std::string &k);
};

#endif

#ifndef INDEX_H
#define INDEX_H

#include "List.h" 
#include <unordered_map>
#include <string>

class Index {
    private:
        
        struct listitem {
            std::string k;
            Node* node;
            listitem* next;

            listitem(const std::string& k, Node* n, listitem* next);
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

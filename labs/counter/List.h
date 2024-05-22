#ifndef LIST_H
#define LIST_H
#include <string>

struct Node {
    std::string key;
    int data;
    Node* prev;
    Node * next;

    Node(const std::string& k, int d);
};

class List {
    private:
        Node* head;
        Node* tail;
    public:
        List();
        ~List();
        void insert(const std::string& k, int d);
        Node* find (const std::string& k);
        void remove (Node* n);
        bool empty() const;

};

#endif
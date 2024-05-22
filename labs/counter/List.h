
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
        size_t nodeCount;
        int tot;
    public:
        List();
        ~List();
        void insert(const std::string& k, int d);
        Node* find (const std::string& k) const;
        void remove (Node* n);
        bool empty() const;
        size_t size() const { return nodeCount; }
        Node* getHead() const { return head; } 
        int gettot()const {return tot;}
        void updatevalue(Node* n, int d);
};

#endif
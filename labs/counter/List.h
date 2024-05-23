
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
        size_t nodeCount = 0;
        int tot = 0;
    public:
        List();
        ~List();
        Node* insert(const std::string& k, int d);
        Node* find (const std::string& k) const;
        void remove (Node* n);
        size_t size() const { return nodeCount; }
        Node* getHead() const { return head; } 
        int gettot()const {return tot;}
        void updatevalue(Node* n, int d);
        void setvalue(Node* n, int d);
};

#endif
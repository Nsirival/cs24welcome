#ifndef HEAP_H
#define HEAP_H

#include <stdexcept>
#include <vector>

class Heap {
public:
    struct Entry {
        std::string word;
        double score;
    };

private:
    std::vector<Entry> data;
    int cap;
    void percUp(int x);
    void percDown(int x);

public:
    Heap(int capacity);

    int count() const;

    int capacity() const;

    void push(const Entry& entry);
    Entry pop();
    Entry& top();
};

#endif // HEAP_H

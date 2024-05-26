#include "Heap.h"

Heap::Heap (int capacity){
    cap = capacity;
    data.reserve(capacity);
}

int Heap::count() const{
    return data.size();
}

int Heap::capacity() const{
    return cap;
}

void Heap::push(const Entry& entry) {
    if (data.size() >= cap) {
        throw std::overflow_error("Heap capacity exceeded");
    }
    data.push_back(entry);
    // Up(data.size() - 1);
}

Heap::Entry Heap::pop() {
    if (data.empty()) {
        throw std::underflow_error("Heap is empty");
    }
    Entry min = data.front();
    data[0] = data.back();
    data.pop_back();
    // Down(0);
    return min;
}

Heap::Entry& Heap::top() {
    if (data.empty()) {
        throw std::underflow_error("Heap is empty");
    }
    return data.at(0);
}

void Heap::percUp(int x) {
    while (x > 0 && data[(x - 1) / 2].score > data[x].score) {
        Entry temp = data[(x - 1) / 2];
        data[(x - 1) / 2] = data[x];
        data[x] = temp;


        x = (x - 1) / 2;
    }
}

void Heap::percDown(int x) {
    int n = data.size();
    while (true) {
        int leftchild = 2 * x + 1;
        int rightchild = 2 * x + 2;
        int min = x;
        if(leftchild < n){
        if (data[leftchild].score < data[min].score) {
            min = leftchild;
        }}
        if (rightchild < n){
        if (data[rightchild].score < data[min].score) {
            min = rightchild;
        }}
        if (min == x) break;
        Entry temp = data[min];
        data[min] = data[x];
        data[x] = temp;
        x = min;
    }
}
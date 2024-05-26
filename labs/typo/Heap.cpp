#include "Heap.h"
#include <stdexcept>

Heap::Heap(size_t capacity)
{
    mData = new Entry[capacity];
}

Heap::Heap(const Heap &other)
{
    mCapacity = other.mCapacity;
    mCount = other.mCount;

    mData = new Entry[mCapacity];
    std::copy(other.mData, other.mData + other.mCount, mData);
}

Heap::~Heap() { delete[] mData; }
size_t Heap::count() const { return mCount; }
size_t Heap::capacity() const { return mCapacity; }

const Heap::Entry &Heap::lookup(size_t index) const
{
    if (index >= mCount)
    {
        throw std::out_of_range("Index out of range");
    }
    return mData[index];
}

void Heap::push(const std::string &value, float score)
{
    if (mCount >= mCapacity)
    {
        throw std::overflow_error("Heap capacity exceeded");
    }
    mCount++;
    mData[mCount] = {value, score};
    size_t x = mCount;

    // percup mcount
    while (x > 0)
    {
        size_t parent = (x - 1) / 2;
        if (mData[parent].score > mData[x].score)
        {
            Heap::Entry temp = mData[x];
            mData[x] = mData[parent];
            mData[parent] = temp;
            x = parent;
        }
        else
        {
            break;
        }
    }

    mCount++;
}
Heap::Entry Heap::pop()
{
    if (mCount == 0)
    {
        throw std::underflow_error("Heap is empty");
    }

    mCount--;
    Entry i = mData[0];
    mData[0] = mData[mCount];

    size_t x = 0;
    size_t child = 2 * x + 1;


    while (child < mCount)
    {
        if (child + 1 < mCount && mData[child + 1].score < mData[child].score)
        {
            child++;

        }
        if (mData[x].score > mData[child].score)
        {
            Heap::Entry temp = mData[x];
            mData[x] = mData[child];
            mData[child] = mData[x];
            x = child;
            child = 2 * x + 1;
        }
        else
        {
            break;
        }
    }

    return i;
}
Heap::Entry Heap::pushpop(const std::string &value, float score)
{
    Entry i = {value, score};

    if (mCount == 0 || score > mData[0].score)
    {
        if (mCount < mCapacity)
        {
            push(value, score);
            return i;
        }
        else
        {
            Entry minItem = mData[0];
            mData[0] = i;
            // percdown
            return minItem;
        }
    }
    return i;
}

const Heap::Entry &Heap::top() const
{
    if (mCount == 0)
    {
        throw std::underflow_error("Heap is empty");
    }
    return mData[0];
}

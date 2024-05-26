#include "Heap.h"
#include <stdexcept>

Heap::Heap(size_t capacity)
{
    mCapacity = capacity;
    mCount = 0;
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

    mData[mCount] = {value, score};
    size_t x = mCount;
    mCount++;
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
}

Heap::Entry Heap::pop()
{
    if (mCount == 0)
    {
        throw std::underflow_error("Heap is empty");
    }

    Entry i = mData[0];
    mCount--;
    mData[0] = mData[mCount];
    

    size_t p = 0;
    while (true)
    {
        size_t lchild = 2 * p + 1;
        size_t rchild = 2 * p + 2;

        size_t x = p;
        if (lchild < mCount && mData[lchild].score < mData[x].score)
        {
            x = lchild;
        }
        if (rchild < mCount && mData[rchild].score < mData[x].score)
        {
            x = rchild;
        }
        if (x != p)
        {
            std::swap(mData[p], mData[x]);
            p = x;
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
    if (mCount == 0)
    {
        push(value, score);
        return i;
    }

    else if (score > mData[0].score)
    {
        Entry hi = mData[0];
        mData[0] = i;

        size_t p = 0;
        while (true)
        {
            size_t lchild = 2 * p + 1;
            size_t rchild = 2 * p + 2;

            size_t x = p;

            if (lchild < mCount && mData[lchild].score < mData[x].score)
            {
                x = lchild;
            }
            if (rchild < mCount && mData[rchild].score < mData[x].score)
            {
                x = rchild;
            }

            if (x != p)
            {
                Heap::Entry temp = mData[p];
                mData[p] = mData[x];
                mData[x] = temp;

                p = x;
            }
            else
            {
                break;
            }
        }
        return hi;
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

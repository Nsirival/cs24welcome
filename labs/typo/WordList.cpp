#include "WordList.h"
#include "Point.h"
#include "Heap.h"
#include <fstream>
#include <cmath>

double distance(Point point1, Point point2)
{
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

WordList::WordList(std::istream &input)
{
    std::string word;

    while (std::getline(input, word))
    {
        bool alllower = true;
        for (int i = 0; i < word.length(); i++)
        {
            if (!islower(word[i]))
            {
                alllower = false;
            }
        }
        if (alllower)
        {
            words.push_back(word);
        }
    }
}

Heap WordList::correct(const std::vector<Point> &points, size_t maxcount, float cutoff) const
{
    Heap heap(maxcount);
    std::vector<Heap::Entry> result;

    for (auto word : words)
    {
        if (word.length() != points.size())
        {
            continue;
        }
        bool valid = true;
        double total;
        double finalscore = 0;
        for (size_t i = 0; i < word.length(); ++i)
        {
            Point k = QWERTY[word[i] - 'a'];
            double len = distance(k, points[i]);

            finalscore = 1.0 / (10 * pow(len, 2) + 1);
            if (finalscore < cutoff)
            {
                valid = false;
                break;
            }
            total += finalscore;



        }

        if (valid)
        {
            double avg = total / word.length();
            if (heap.count() < maxcount && avg > heap.top().score)
            {
                if(heap.count() == maxcount){
                heap.pop();
            }
            heap.push({word, avg});
            }
            
        }
    }
    return heap;
}

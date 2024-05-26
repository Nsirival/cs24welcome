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
        for (char ch : word)
        {
            if (!islower(ch))
            {
                alllower = false;
                break;
            }
        }
        if (alllower)
        {
            mWords.push_back(word);
        }
    }
}

Heap WordList::correct(const std::vector<Point> &points, size_t maxcount, float cutoff) const
{
    Heap heap(maxcount);

    for (const auto &word : mWords)
    {
        if (word.length() != points.size())
        {
            continue;
        }

        bool valid = true;
        double total = 0;

        for (size_t i = 0; i < word.length(); i++)
        {
            Point k = QWERTY[word[i] - 'a'];
            double len = distance(k, points[i]);

            double finalscore = 1.0 / (10 * pow(len, 2) + 1);
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
            if (heap.count() < maxcount)
            {
                heap.push(word, avg);
            }
            else if (avg > heap.top().score)
            {
                heap.pop();
                heap.push(word, avg);
            }
        }
    }

    return heap;
}

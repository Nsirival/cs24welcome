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

    for (auto word : mWords)
    {
        if (word.length() == points.size())
        {
            double s = 0.0;

            for (size_t i = 0; i < word.length(); i++)
            {
                Point k = QWERTY[word[i] - 97];
                double len = distance(k, points[i]);

                s += 1.0 / (10 * pow(len, 2) + 1);
            }
            s = s / word.length();
            if (s > cutoff)
            {
                heap.push(word, s);
            }
        }
    }
    return heap;
}

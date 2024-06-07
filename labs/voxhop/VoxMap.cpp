#include "VoxMap.h"
#include "Errors.h"
#include "Route.h" 
#include "Point.h" 
#include <queue>
#include <unordered_set>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

bool VoxMap::canstand(Point pt)
{
  int x = pt.x;
  int y = pt.y;
  int z = pt.z;
  if (voxmap[z][y][x])
  {
    return true;
  }
  return false;
}

bool VoxMap::valid(const Point &pt)
{
  if (pt.x < 0 || pt.x >= l || pt.y < 0 || pt.y >= w || pt.z < 0 || pt.z >= h)
  {
    return false;
  }
  return canstand(pt);
}

std::size_t pointHash(const Point &p) {
    return std::hash<int>()(p.x) ^ std::hash<int>()(p.y) ^ std::hash<int>()(p.z);
}

bool pointEqual(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

double h(const Point &a, const Point &b)
{
  return std::abs(a.x - b.x) + std::abs(a.y - b.y) + std::abs(a.z - b.z);
}

struct Comparator
{
  Point dst;

  Comparator(Point destination) : dst(destination) {}

  bool operator()(const std::pair<Point, Route> &a, const std::pair<Point, Route> &b) const
  {
    return h(a.first, dst) > h(b.first, dst);
  }
};

VoxMap::VoxMap(std::istream &stream)
{
  stream >> l;
  stream >> w;
  stream >> h;
  voxmap.resize(h, std::vector<std::vector<bool>>(w, std::vector<bool>(l)));

  for (int z = 0; z < h; z++)
  {
    std::string line;
    std::getline(stream, line); 
    for (int y = 0; y < w; y++)
    {
      std::getline(stream, line);
      for (int x = 0; x < l / 4; ++x)
      {
        char hexChar = line[x];
        int value = std::stoi(std::string(1, hexChar), nullptr, 16);
        for (int bit = 0; bit < 4; ++bit)
        {
          voxmap[z][y][x * 4 + (3 - bit)] = (value & (1 << bit)) != 0;
        }
      }
    }
  }
}

Route VoxMap::route(Point src, Point dst)
{
  if (!valid(src))
    throw InvalidPoint(src);
  if (!valid(dst))
    throw InvalidPoint(dst);

  using QueueElement = std::pair<Point, Route>;

  auto comparator = Comparator(dst);
  std::priority_queue<QueueElement, std::vector<QueueElement>, Comparator> q(comparator);
  std::unordered_set<Point, size_t, bool> visited;
  std::unordered_map<Point, Point, size_t, bool> came_from;

  q.push({src, Route()});
  visited.insert(src);

  while (!q.empty())
  {
    QueueElement currentElement = q.top();
    q.pop();

    Point curpoint = currentElement.first;
    Route currentRoute = currentElement.second;


    //FIND THE PATH
    if (curpoint.x == dst.x && curpoint.y == dst.y && curpoint.z == dst.z)
    {
      Route route;
      Point tracer = curpoint;
      while (tracer != src)
      {
        Point prev = came_from[tracer];
        if (tracer.x > prev.x)
        {
          route.push_back(Move::EAST);
        }
        else if (tracer.x < prev.x)
        {
          route.push_back(Move::WEST);
        }
        else if (tracer.y > prev.y)
        {
          route.push_back(Move::SOUTH);
        }
        else if (tracer.y < prev.y)
        {
          route.push_back(Move::NORTH);
        }
        tracer = prev;
      }
      std::reverse(route.begin(), route.end());
      return route;
    }

    int posmoves[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};



    //FIND THE SURROUNDING TILES
    for (int i = 0; i < 4; i++)
    {
      Point test = curpoint;
      test.x += posmoves[i][0];
      test.y += posmoves[i][1];

      if (valid(test) && visited.find(test) == visited.end())
      {
        Route newRoute = currentRoute;
        if (test.y == curpoint.y - 1)
        {
          newRoute.push_back(Move::NORTH);
        }
        else if (test.y == curpoint.y + 1)
        {
          newRoute.push_back(Move::SOUTH);
        }
        else if (test.x == curpoint.x + 1)
        {
          newRoute.push_back(Move::EAST);
        }
        else if (test.x == curpoint.x - 1)
        {
          newRoute.push_back(Move::WEST);
        }
        q.push({test, newRoute});
        visited.insert(test);
        came_from[test] = curpoint;
      }
    }
  }

  throw NoRoute(src, dst);
}

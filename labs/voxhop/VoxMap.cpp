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
#include <sstream>
#include <cctype>

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

std::size_t pointHash(const Point &p)
{
  return std::hash<int>()(p.x) ^ std::hash<int>()(p.y) ^ std::hash<int>()(p.z);
}

bool pointEqual(const Point &a, const Point &b)
{
  return a.x == b.x && a.y == b.y && a.z == b.z;
}

double h(const Point &a, const Point &b)
{
  return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

struct Comparator
{
  Point dst;

  Comparator(Point destination)
  {
    dst = destination;
  }

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
  std::string line;

  for (int z = 0; z < h; ++z)
  {
    std::getline(stream, line);
    std::vector<std::vector<bool>> yv;

    for (int y = 0; y < w; ++y)
    {
      if (line.length() != 0)
      {
        std::vector<bool> xv;
        std::getline(stream, line);
        for (int x = 0; x < l / 4; ++x)
        {
          char hexChar = line.at(x);
          int value;
          if (std::isdigit(hexChar))
          {
            value = hexChar - '0';
          }
          else
          {
            value = hexChar - 'a' + 10;
          }
          const int bitMasks[4] = {1, 2, 4, 8};

          for (int bit = 0; bit < 4; ++bit)
          {
            xv.push_back((value & bitMasks[bit]) != 0);
          }
        }
        yv.push_back(xv);
      }
      voxmap.push_back(yv);
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
  std::unordered_set<Point, decltype(&pointHash), decltype(&pointEqual)> visited(0, pointHash, pointEqual);
  std::unordered_map<Point, Point, decltype(&pointHash), decltype(&pointEqual)> came_from(0, pointHash, pointEqual);

  q.push({src, Route()});
  visited.insert(src);

  while (!q.empty())
  {
    QueueElement currentElement = q.top();
    q.pop();

    Point curpoint = currentElement.first;
    Route currentRoute = currentElement.second;

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

// bool Voxhop::validmove(Point &a, Point &b)
// {
//   // 2block high no
//   // headbang no
//   // falling
//   if (b.z + 1 >= 0 || b.z + 1 < h)
//   {
//     if (b.z + 2 >= 0 || b.z + 2 < h)
//     {
//       if (voxmap[z + 1][y][x] && voxmap[z + 2][][])
//       {
//         return true;
//       }
//     } else {
//       int zed = b.z;
//       int i = 0;
//       while (i < 1 || z > -1) {
//         z--
//       }
//     }
//   }
// }
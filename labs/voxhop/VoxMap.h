#ifndef VOXMAP_H
#define VOXMAP_H

#include <istream>
#include <vector>

#include "Point.h"
#include "Route.h"

class VoxMap
{
private:
  int l = 0;
  int w = 0;
  int h = 0;
  std::vector<std::vector<std::vector<bool>>> voxmap;

  bool canstand(Point pt);

public:
  VoxMap(std::istream &stream);

  Route route(Point src, Point dst);
  bool valid(const Point &pt);
};

#endif

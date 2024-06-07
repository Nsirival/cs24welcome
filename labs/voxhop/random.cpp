Route VoxMap::route(const Point& src, const Point& dst) {
  if (!isValid(src)) {
    throw InvalidPoint(src);
  }
  if (!isValid(dst)) {
    throw InvalidPoint(dst);
  }

  // Implementing a basic breadth-first search (BFS) for pathfinding
  std::queue<Point> q;
  std::unordered_map<Point, Point> came_from;
  std::unordered_set<Point> visited;
  q.push(src);
  visited.insert(src);

  while (!q.empty()) {
    Point current = q.front();
    q.pop();

    if (current.x == dst.x && current.y == dst.y && current.z == dst.z) {
      // Reconstruct the route
      Route route;
      Point trace = current;
      while (trace != src) {
        Point prev = came_from[trace];
        if (trace.x > prev.x) route.addMove(Move::EAST);
        else if (trace.x < prev.x) route.addMove(Move::WEST);
        else if (trace.y > prev.y) route.addMove(Move::SOUTH);
        else if (trace.y < prev.y) route.addMove(Move::NORTH);
        trace = prev;
      }
      std::reverse(route.moves.begin(), route.moves.end());
      return route;
    }

    // Explore neighbors (N, E, S, W)
    std::vector<Point> neighbors = {
      {current.x, current.y + 1, current.z},
      {current.x + 1, current.y, current.z},
      {current.x, current.y - 1, current.z},
      {current.x - 1, current.y, current.z}
    };

    for (const Point& neighbor : neighbors) {
      if (isValid(neighbor) && visited.find(neighbor) == visited.end()) {
        q.push(neighbor);
        visited.insert(neighbor);
        came_from[neighbor] = current;
      }
    }
  }

  throw NoRoute(src, dst);
}
#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "BFS.h"

using namespace cs225;

BFS::BFS(const PNG & png, const Point & start, double tolerance) { 
   pngOne = png;
   startPoint = start;
   toleranceOne = tolerance;
   daqueue.push(start);
}

ImageTraversal::Iterator BFS::begin() {
  return ImageTraversal::Iterator(this, startPoint, pngOne, toleranceOne);
}

ImageTraversal::Iterator BFS::end() {
  return ImageTraversal::Iterator();
}

void BFS::add(const Point & point) {
  daqueue.push(point);
}

Point BFS::pop() {
  Point temporary = daqueue.front();
  daqueue.pop();
  return temporary;
}

Point BFS::peek() const {
  return daqueue.front();
} 

bool BFS::empty() const {
  return daqueue.empty();
}
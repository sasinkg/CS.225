#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"

//using namespace cs225;


DFS::DFS(const PNG & png, const Point & start, double tolerance) {  
}

ImageTraversal::Iterator DFS::begin() {
  return ImageTraversal::Iterator(this, startPoint, pngOne, toleranceOne);
}

ImageTraversal::Iterator DFS::end() {
  return ImageTraversal::Iterator();
}

void DFS::add(const Point & point) {
  stack.push(point);
}

Point DFS::pop() {
  Point temporary = stack.top();
  stack.pop();
  return temporary;
}

Point DFS::peek() const {
  return stack.top();
}

bool DFS::empty() const {
  return stack.empty();
}

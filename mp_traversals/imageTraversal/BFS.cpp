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

/**
 * Initializes a breadth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * @param png The image this BFS is going to traverse
 * @param start The start point of this BFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this BFS
 */
BFS::BFS(const PNG & png, const Point & start, double tolerance) {  
  /** @todo [Part 1] */ 
  pic = png; 
  startPoint = start;  
  queue.push(startPoint); 
  delta = tolerance;
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator BFS::begin() {
  /** @todo [Part 1] */ 
    //this might be an error 
  
  return ImageTraversal::Iterator(this, startPoint);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator BFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const Point & point) { 
  /** @todo [Part 1] */   

queue.push(point);

/*
 Point right(point.x+1,point.y); 
 if(bounds(right)){queue.push(right);}    

 Point down(point.x,point.y+1); 
 if(bounds(down)){queue.push(down);} 
 

 Point up(point.x-1,point.y); 
 if(bounds(up)){queue.push(up);} 
 

 Point left(point.x,point.y-1); 
 if(bounds(left)){queue.push(left);} 
*/ 

}
bool BFS::bounds(const Point & point){ 
if(point.x < pic.width() && point.y < pic.height()){return true;} 
else{return false;}
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point BFS::pop() {
  /** @todo [Part 1] */ 
  Point temp = queue.front(); 
  queue.pop();
  return temp;
}

/**
 * Returns the current Point in the traversal.
 */
Point BFS::peek() const {
  /** @todo [Part 1] */
  return queue.front();
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  /** @todo [Part 1] */
  return queue.empty();
}

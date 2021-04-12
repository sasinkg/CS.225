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


/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * 
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {  
  /** @todo [Part 1] */ 
  pic = png; 
  startPoint = start;  
  stack.push(startPoint); 
  delta = tolerance;
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(this, startPoint);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) { 
  /** @todo [Part 1] */  

stack.push(point);
/*
 Point right(point.x+1,point.y); 
 if(bounds(right)){stack.push(right);}    

 Point down(point.x,point.y+1); 
 if(bounds(down)){stack.push(down);} 
 

 Point up(point.x-1,point.y); 
 if(bounds(up)){stack.push(up);} 
 

 Point left(point.x,point.y-1); 
 if(bounds(left)){stack.push(left);}  
*/

}
bool DFS::bounds(const Point & point){ 
if(point.x < pic.width() && point.y < pic.height()){return true;} 
else{return false;}
}
/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */ 
  Point ret = stack.top(); 
  stack.pop();
  return ret;
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  return stack.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */ 
return stack.empty();
}

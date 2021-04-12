#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h" 

using namespace std;

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() : traversal(NULL){
  /** @todo [Part 1] */ 

}
ImageTraversal::Iterator::Iterator(ImageTraversal* t, Point p) {
  /** @todo [Part 1] */ 
  traversal = t;  
  point = p; 

  matrix.resize(t->pic.width()); 

  for(unsigned int i = 0;  i < t->pic.width(); ++i){ 
   
   matrix[i] = vector<bool>(t->pic.height());  

  }
}
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */ 
  Point current = this->traversal->pop();

   if(!visited(current)){  
   Point right(point.x+1,point.y); 
   if(bounds(right)){this->traversal->add(right);}    

   Point down(point.x,point.y+1); 
   if(bounds(down)){this->traversal->add(down);} 
 

   Point up(point.x-1,point.y); 
   if(bounds(up)){this->traversal->add(up);} 
 

   Point left(point.x,point.y-1); 
   if(bounds(left)){this->traversal->add(left);}  

    matrix[current.x][current.y] = true;

  }  
  
  if(this->traversal->empty()) {   
    this->traversal = NULL;
    return *this; 
  }

  Point next = this->traversal->peek();


  while(visited(next) || !tolCheck(next) ) 
  {  

    next = this->traversal->pop(); 

  //empty check 
    if(this->traversal->empty()) {  
     this->traversal = NULL;
     return *this; 
    }

   next = this->traversal->peek(); 

  }
  
  this->point = next;
  return *this;

} 
/*returns true if a point has been visited*/ 
bool ImageTraversal::Iterator::visited(Point point){  

if(matrix[point.x][point.y]){return true;} 
return false;
/*
for(auto it = matrix.begin(); it < matrix.end(); ++it){ 

if(*it == point){return true;} 

}  
*/


}
 
bool ImageTraversal::Iterator::bounds(const Point point){ 
if(point.x < this->traversal->pic.width() && point.y < this->traversal->pic.height()){return true;} 
else{return false;}
}

bool ImageTraversal::Iterator::tolCheck(Point next){ 

double tol = calculateDelta(this->traversal->pic.getPixel(this->traversal->startPoint.x, this->traversal->startPoint.y), this->traversal->pic.getPixel(next.x, next.y)); 

if(tol < this->traversal->delta) {return true;} 
 
return false;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return this->point;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */ 
     bool thisEmpty = false; 
     bool otherEmpty = false;
     if (traversal == NULL) { thisEmpty = true; }
     if (other.traversal == NULL) { otherEmpty = true; }

    if (!thisEmpty)  { thisEmpty = traversal->empty(); }
    if (!otherEmpty) { otherEmpty = other.traversal->empty(); }

    if (thisEmpty && otherEmpty) return false; // both empty then the traversals are equal, return true
    else if ((!thisEmpty)&&(!otherEmpty)) return (traversal != other.traversal); //both not empty then compare the traversals
    else return true; // one is empty while the other is not, return true
}


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
ImageTraversal::Iterator::Iterator() : trav(NULL) {
  /** @todo [Part 1] */
  //trav = NULL;
  /* unsigned int w = 0;
  unsigned int h = 0;
  unsigned int  */
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator::Iterator(ImageTraversal * newTrav, Point p){
  /** @todo [Part 1] */
  //return *this;
  trav = newTrav;
  curr = p;

  queue.resize(newTrav -> newPNG.width());

  for(unsigned i = 0; i < newTrav -> newPNG.width(); i++) {
    queue[i] = vector<bool> (trav -> newPNG.height());   
  }

}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  Point newCurr = this -> trav -> pop();

  if(!checkParameter(newCurr)) {
    Point right(curr.x + 1, curr.y);
    if (right.x < (this -> trav -> newPNG.width()) && right.y < this -> trav -> newPNG.height()) {
      this -> trav -> add(right);
    }
    
    Point down(curr.x, curr.y + 1);
    if (down.x < (this -> trav -> newPNG.width()) && down.y < this -> trav -> newPNG.height()) {
      this -> trav -> add(down);
    } 

    Point up(curr.x - 1, curr.y);
    if (up.x < (this -> trav -> newPNG.width()) && up.y < this -> trav -> newPNG.height()) {
      this -> trav -> add(up);
    }

    
    Point left(curr.x, curr.y - 1);
    if (left.x < (this -> trav -> newPNG.width()) && left.y < this -> trav -> newPNG.height()) {
      this -> trav -> add(left);
    }

    queue[newCurr.x][newCurr.y] = true;   
  }

  if (this -> trav -> empty()) {
    this -> trav = NULL;
    return *this;
  } 
  Point next = this -> trav -> peek();

  while(checkParameter(next) || !checkTolerance(next)) {
    next = this -> trav -> pop();
    if ( this -> trav -> empty()) {
      this -> trav = NULL;
      return *this;
    }
    next = this -> trav -> peek();
  }
  this -> curr = next;
  return *this;
} 

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return this -> curr;
}

bool ImageTraversal::Iterator::checkTolerance(Point next) {
  double a = calculateDelta(this -> trav -> newPNG.getPixel(this -> trav -> newStart.x, this -> trav -> newStart.y), this -> trav -> newPNG.getPixel(next.x, next.y));
  if (a > this -> trav -> newTolerance) {
    return false;
  } else {
    return true;
  }
}
bool ImageTraversal::Iterator::checkParameter(Point boys) {
  if(queue[boys.x][boys.y]) {
    return true;
  } else {
    return false;
  }
}
/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */

	  bool thisEmpty, otherEmpty;
	  if (trav == NULL){
			thisEmpty = true;
	  }else{
			thisEmpty = trav -> empty();
	  }
	  if (other.trav == NULL){
			otherEmpty = true;
	  }else{
			otherEmpty = other.trav -> empty();
	  }
	  return !(thisEmpty && otherEmpty);

}
/* bool ImageTraversal::Iterator::checkValid (Point curr, Point p) {
	if (p.x >= newPNG.width()){
		return false;
	}
	if (p.y >= newPNG.height()){
		return false;
	}
	if (newTolerance <= calculateDelta(newPNG.getPixel(curr.x, curr.y) , newPNG.getPixel(p.x, p.y)) ) {
		return false;
	}
	if (queue.at(p.x + p.y * newPNG.width()) == 1){
		return false;
	}
	return true;
} */





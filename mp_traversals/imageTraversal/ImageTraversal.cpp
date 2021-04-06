#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

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
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  IT = NULL;
  /* unsigned int w = 0;
  unsigned int h = 0;
  unsigned int  */
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator::Iterator(ImageTraversal * itrav, Point spo, PNG png1, double tol){
  /** @todo [Part 1] */
  //return *this;

  IT = itrav;
  sp = spo;
  pngg = png1;
  toleranceg = tol;
  curr = IT -> peek();

  for(unsigned i = 0; i < pngg.height() * pngg.width(); i++) {
    visit.push_back(false); 
  }

}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  Point p (0, 0);
  if (!IT -> empty()) {
    curr = IT -> pop();
    p.x = curr.x;
    p.y = curr.y;

    visit.at(p.x + p.y*pngg.width()) = 1;
    
    p.x = curr.x + 1;
    p.y = curr.y;
    if(checkValid (sp,p)) {
      IT -> add(p);
    }
    
    p.x = curr.x;
    p.y = curr.y + 1;
    if(checkValid (sp,p)) {
      IT -> add(p);
    }
    p.x = curr.x;
    p.y = curr.y - 1;
    if(checkValid (sp,p)) {
      IT -> add(p);
    }
    p.x = curr.x - 1;
    p.y = curr.y;
    if(checkValid (sp,p)) {
      IT -> add(p);
    }
    while (!IT -> empty()) {
      curr = IT -> peek();
      if(visit.at(curr.x + curr.y * pngg.width())) {
        IT -> pop();
      } else {
        break;
      } if (IT -> empty()) {
        curr = sp;
        break;
      }
      curr = IT -> peek();
    }
  }
  return *this;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return curr;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */

	  bool thisEmpty, otherEmpty;
	  if (IT == NULL){
			thisEmpty = true;
	  }else{
			thisEmpty = IT -> empty();
	  }
	  if (other.IT == NULL){
			otherEmpty = true;
	  }else{
			otherEmpty = other.IT -> empty();
	  }
	  return !(thisEmpty && otherEmpty);

}

bool ImageTraversal::Iterator::checkValid (Point sp, Point p) {
	if (p.x >= pngg.width()){
		return false;
	}
	if (p.y >= pngg.height()){
		return false;
	}
	if (toleranceg <= calculateDelta(pngg.getPixel(sp.x, sp.y) , pngg.getPixel(p.x, p.y)) ) {
		return false;
	}
	if (visit.at(p.x + p.y * pngg.width()) == 1){
		return false;
	}
	return true;
}





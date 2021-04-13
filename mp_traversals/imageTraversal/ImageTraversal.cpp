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
  trav = NULL;
 // Point sp (0,0);
  // cp = sp;
}


ImageTraversal::Iterator::Iterator(ImageTraversal * trav2, PNG png2, Point start2, double tolerance2) {
  /** @todo [Part 1] */
 // traversal = NULL;
    /* Point points (0,0);
    if (trav -> empty() == false) {
        curr = trav -> pop();
        points.x = curr.x;
        points.y = curr.y;

    }*/ 

    trav = trav2;
    start1 = start2;
    png1 = png2;
    tolerance1 = tolerance2;
    double area = png1.width() * png1.height();
    curr = trav -> peek();
    for (unsigned i = 0; i < area; i++) {
        //pass[png1.width()][png1.height()] = (false);
        pass.push_back(false);
    }

   
}
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
Point s(0,0);
if(trav -> empty() == false) {
    curr = trav -> pop();
    s.x = curr.x;
    s.y = curr.y;

    pass.at(s.x + s.y * png1.width()) = 1; 
    
    s.x = curr.x + 1;
    s.y = curr.y;
    PreValidity(p,s);
    
    s.x = curr.x;
    s.y = curr.y + 1;
    PreValidity(p,s);

    s.x = curr.x - 1;
    s.y = curr.y;
    PreValidity(p,s);

    s.x = curr.x;
    s.y = curr.y - 1;
    PreValidity(p,s);
    
}
  while (trav -> empty() == false) {
      curr = trav -> peek();
      int dab = curr.x + curr.y * png1.width();
      if (pass.at(dab)) {
          trav -> pop();
      } else {
          break;
      } 
      if (trav -> empty() == true) {
          curr = p;
          break;
      }
    curr = trav -> peek();
  }
  return *this;
}
void ImageTraversal::Iterator::PreValidity(Point p, Point s) {
  if (Validity(p, s)) {
        trav -> add(s);
    } 
}
bool ImageTraversal::Iterator::Validity(Point p, Point s) {
    if(s.x >= png1.width() || s.y >= png1.height()) {
        return false;
    }
    if (pass.at(s.x + s.y * png1.width()) == 1) {
        return false;
    }
    if (tolerance1 <= calculateDelta(png1.getPixel(p.x, p.y), png1.getPixel(s.x,s.y))) {
        return false;
    } 
    return true;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return cp;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  //return false;
    bool thisEmpty, otherEmpty;
    if(trav == NULL) {
        thisEmpty = true;
    } else {
        thisEmpty = trav -> empty();
    } 

    if (other.trav == NULL) {
        otherEmpty = true;
    } else { otherEmpty = other.trav -> empty();}
    return !(thisEmpty && otherEmpty);
}

/* bool ImageTraversal::Iterator::Visitation(Point currPoint) {
    if (currPoint.x < png1.width()) {
        if (currPoint.y < png1.height()) {
            if (calculateDelta(png1.getPixel(start1.x, start1.y), png1.getPixel(currPoint.x, currPoint.y)) < tolerance1) {
                if (pass[currPoint.x][currPoint.y] == false) {
                    return true;
                }
            }
        }
    }
    return false;
} */
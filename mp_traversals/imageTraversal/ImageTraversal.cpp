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
  Point sp (0,0);
  cp = sp;
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
    for (unsigned i = 0; i < area; i++) {
        pass[png1.width()][png1.height()] = (false);
    }

   
}
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
    //psuedo
    Point right = Point(cp.x + 1, cp.y);
    Point down = Point(cp.x, cp.y + 1);
    Point left = Point(cp.x - 1, cp.y);
    Point up = Point(cp.x, cp.y - 1);

    if (Visitation(right)) {
        trav -> add(right);
    }
    if (Visitation(down)) {
        trav -> add(down);
    }
    if (Visitation(left)) {
        trav -> add(left);
    }
    if (Visitation(up)) {
        trav -> add(up);
    }

    while (trav -> empty() == false) {
        curr2 = trav -> peek();
        if(Visitation(curr2) == false) {
          trav -> pop();
          if (trav -> empty()) {
            return *this;
           }
        } else {
          break;
        }
        curr2 = trav -> peek();
    }
  //r//eturn *this;
  cp = curr2;
  return *this;
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

bool ImageTraversal::Iterator::Visitation(Point currPoint) {
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
}
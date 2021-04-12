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
ImageTraversal::Iterator::Iterator(ImageTraversal * newTrav, Point p, PNG pngOne, double tol){
  /** @todo [Part 1] */
  //return *this;
  trav = newTrav;
  newStart = p;
  newPNG = pngOne;
  newTolerance = tol;

  //queue.resize(newTrav -> newPNG.width());

  // for(unsigned i = 0; i < newTrav -> newPNG.width(); i++) {
  //   queue[i] = vector<bool> (trav -> newPNG.height());   
  // }
  temp = trav -> peek();
  double area = newPNG.height() * newPNG.width();
  for (unsigned i = 0;  i < area; i++) {
    queue.push_back(false);
  }
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  Point origin (0,0);
  if(!trav -> empty()) {
    temp = trav -> pop();
    origin.x = temp.x;
    origin.y = temp.y;
    int newWidth = origin.y * newPNG.width();
    queue.at(origin.x + newWidth) = 1;

    //Point originOne (0,0);

    origin.x = temp.x + 1;
    origin.y = temp.y;
    testValid(newStart, origin);

    origin.x = temp.x;
    origin.y = temp.y + 1;
    testValid(newStart, origin);

    origin.x = temp.x - 1;
    origin.y = temp.y;
    testValid(newStart, origin);

    origin.x = temp.x;
    origin.y = temp.y - 1;
    testValid(newStart, origin);

    while(!trav -> empty()) {
      temp = trav -> peek();
      int total = temp.x + temp.y * newPNG.width();
      if (queue.at(total)) {
        trav -> pop();
      } else {
        break;
      }
      if (trav -> empty()) {
        temp = newStart;
        break;
      }
      temp = trav -> peek();
    }
  }
  return *this;
}
Point ImageTraversal::Iterator::operator*() {
  return curr;
}
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator & other) {
  bool thisEmpty = false;
  bool otherEmpty = false;

  if (trav == NULL) {
    thisEmpty = true;
  } else {
    thisEmpty = trav -> empty();
  }

  if(other.trav == NULL) {
    otherEmpty = true;
  } else {
    otherEmpty = other.trav -> empty();
  }
  return !(thisEmpty && otherEmpty);
}
void ImageTraversal::Iterator::testValid(Point newStart, Point origin) {
    if (checkValidity(newStart, origin)) {
      trav -> add(origin);
    }
}

bool ImageTraversal::Iterator::checkValidity(Point newStart, Point origin) {
  if (origin.x >= newPNG.width() && origin.y >= newPNG.height()) {
    return false;
  }
  if (newTolerance <= calculateDelta(newPNG.getPixel(newStart.x, newStart.y), newPNG.getPixel(origin.x, origin.y))) {
    return false;
  } 
  if (queue.at(origin.x + origin.y * newPNG.width()) == 1) {
    return false;
  }
  return true;
}


#include <cmath>
#include <iterator>
#include <iostream>
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"
#include "ImageTraversal.h"

using namespace std;

double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}


ImageTraversal::Iterator::Iterator() { goCubs = NULL;}

ImageTraversal::Iterator::Iterator(ImageTraversal * goBears, Point pointTwo, PNG pngg, double tol){
  goCubs = goBears;
  nextPoint = pointTwo;
  pngOne = pngg;
  toleranceOne = tol;
  curr = goCubs -> peek();

  for (unsigned i = 0; i < pngOne.height() * pngOne.width(); i++) {
    pass.push_back(false);
  }
}
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  Point points (0,0);
  if (!goCubs -> empty()) {
    curr = goCubs -> pop();
    points.x = curr.x;
    points.y = curr.y;
    pass.at(points.x + points.y * pngOne.width()) = 1;

    points.x = curr.x + 1;
    points.y = curr.y;
    if (checkValidity(nextPoint, points)) {
      goCubs -> add(points);
    }
     points.x = curr.x;
    points.y = curr.y + 1;
    if (checkValidity(nextPoint,points)) {
      goCubs -> add(points);
    }
     points.x = curr.x - 1;
    points.y = curr.y;
    if (checkValidity(nextPoint,points)) {
      goCubs -> add(points);
    }
    points.x = curr.x;
    points.y = curr.y - 1;
    if (checkValidity(nextPoint,points)) {
      goCubs -> add(points);
    }
    while(!goCubs -> empty()) {
      curr = goCubs -> peek();
      if(pass.at(curr.x + curr.y * pngOne.width())) {
        goCubs -> pop();
      } else {
        break;
      } 
      if (goCubs -> empty()) {
        curr = nextPoint;
        break;
      }
      curr = goCubs -> peek();
    }
    
   // return *this;
  }

  return *this;
}

Point ImageTraversal::Iterator::operator*() {
  return curr;
}
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator & other) {
  bool thisEmpty, otherEmpty;
  if(goCubs ==NULL) {
    thisEmpty = true;
  } else {
    thisEmpty = goCubs -> empty();
  } 
  if (other.goCubs == NULL) {
    otherEmpty = true;
  } else {
    otherEmpty = other.goCubs -> empty();
  } 
  return !(thisEmpty && otherEmpty);
}

bool ImageTraversal::Iterator::checkValidity(Point nextPoint, Point points) {
  if (points.x >= pngOne.width()) {
    return false;
  } 
  if (points.y >= pngOne.height()) {
    return false;
  } 
  if (toleranceOne <= calculateDelta(pngOne.getPixel(nextPoint.x, nextPoint.y), pngOne.getPixel(points.x, points.y))) {
    return false;
  } 
  if (pass.at(points.x + points.y * pngOne.width()) == 1) {
    return false;
  }
  return true;
}
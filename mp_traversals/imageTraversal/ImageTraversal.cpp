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

  if (h>180) { h = 360 - h};
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l));
}
ImageTraversal::Iterator::Iterator() {
  trav = NULL;
  tolerance_ = 0;
  startpoint_ = Point(0,0);
  currentpoint_ = startpoint_;
}
ImageTraversal::Iterator::Iterator(startpoint2, tolerance2, image2, ImageTraversal * trav2) {
  trav = trav2;
  startpoint_ = startpoint2;
  image_ = image2;
  tolerance_ = tolerance2;

  curr = trav -> peek();

  for (unsigned i = 0; i < image_.height() * image2.width(); i++) {
    pass.push_back(false);
  }
}
 // return ImageTraversal::Iterator();
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  Point right = Point(currentpoint_.x + 1, currentpoint_.y);
  if(Visit(right) == true) {
    trav -> add(right);
  }
  Point left = Point(currentpoint_.x - 1, currentpoint_.y);
  if(Visit(left) == true) {
    trav -> add(left);
  }
  Point up = Point(currentpoint_.x, currentpoint_.y - 1);
  if(Visit(up) == true) {
    trav -> add(up);
  }
  Point down = Point(currentpoint_.x, currentpoint_.y + 1);
  if(Visit(down) == true) {
    trav -> add(down);
  }

  pass[currentpoint_.x][currentpoint_.y] = true;
  see = trav -> peek();

  while(!trav-> empty()) {
    if(Visit(see) == false) {
      trav -> pop();
      if(trav ->empty()) {
        return *this;
      }
    } else {
      break;
    }
    see = trav-> peek;
    return *this;
  }
}
Point ImageTraversal::Iterator::operator*() {
  return;
}
 bool ImageTraversal::Iterator::Visit(Point sp) {
  if(sp.x < image_.width()) {
    if (sp.y < image.height()) {
      if (calculateDelta(image_.getPixel(startpoint_.x, startpoint_.y), image_.getPixel(sp.x, sp.y)) < tolerance_ && pass[sp.x][sp.y] == false) {
        return true;
      }
    }
  }
  return false;
}
/**
 * @file ImageTraversal.h
 */
#pragma once

#include <iterator>
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"
#include <vector>

using namespace cs225;
using namespace std;

/**
 * A base class for traversal algorithms on images.
 *
 * BFS and DFS will inherit from this class
 * 
 * Each derived class must maintain an ordering of points on an image,
 * through calls to the virtual member functions `add` and `pop`.
 * 
 * A derived class provides a traversal by returning instances of
 * ImageTraversal::Iterator.
 */
class ImageTraversal {
public:
  /**
   * A forward iterator through an ImageTraversal.
   */
  class Iterator : std::iterator<std::forward_iterator_tag, Point> {
  public:
    Iterator();
    Iterator(ImageTraversal * trav2, PNG png2, Point start2, double tolerance1);
    Iterator & operator++();
    Point operator*();
    bool operator!=(const Iterator &other);
    void PreValidity(Point p, Point s);
    bool Validity(Point p, Point s);

    /** @todo [Part 1] */
    /** add member functions if neccesary*/

  private:
    /** @todo [Part 1] */
    /** add private members here if neccesary*/
    ImageTraversal * trav;
    double tolerance1;
    Point start1;
    Point curr;
    Point cp;
        PNG png1;

    Point p;
    Point s;
    Point curr2;
    std::vector <int> pass;
  };

  /**
   * The begining of an iterator
   * Virtual function. Derived class need to implement this
   */
  virtual Iterator begin() = 0;

  /**
   * The end of an iterator
   * Virtual function. Derived class need to implement this
   */
  virtual Iterator end() = 0;

  /**
   * Add new point to the traversal
   * Virtual function. Derived class need to implement this
   */
  virtual void add(const Point & t) = 0;
  /**
   * Remove and return the next point of the traversal
   * Virtual function. Derived class need to implement this
   */
  virtual Point pop() = 0;
  /**
   * Return but not remove the next point of the traversal
   * Virtual function. Derived class need to implement this
   */
  virtual Point peek() const = 0;
  /**
   * To see if the traversal has no points left
   * Virtual function. Derived class need to implement this
   */
  virtual bool empty() const = 0;

private:
  static double calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2);  
};
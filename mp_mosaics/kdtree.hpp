/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */

    if (first[curDim] < second[curDim] || first < second) {
      return true;
    } else if (first[curDim] > second[curDim]) {
      return false;
    } else {
      return false;
    }

    //return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */

    if(distance(target, currentBest) == distance(potential, target)) {
      return potential < currentBest;
    } else {
      return distance(target,potential) < distance(target, currentBest);
    }

    //return false;
}

template <int Dim>
double KDTree<Dim>::distance(const Point<Dim> pointOne, const Point<Dim> pointTwo) const{

  double dist = 0;
  for(int i = 0; i < Dim; i++) {
    dist += pow(pointOne[i] - pointTwo[i], 2);
  }
  return dist;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */

  size = 0;
  for (unsigned int i = 0; i < newPoints.size(); i++) {
    points.push_back(newPoints[i]);
  }
  root = buildTree (0, 0, points.size() - 1); 
}

template <int Dim>
KDTree<Dim>::buildTree(int dimension, int left, int right, KDTreeNode*& currRoot) {
  if(left <= right) {
    int average = (left + right) / 2;
    int newDim = (dimension + 1) %Dim;
    currRoot = new KDTreeNode(quickSelect(left, right, average, dimension);
  }

  buildTree(newDim, left, average - 1, currRoot -> left);
  buildTree(next_dim, med + 1, right, currRoot->right);
}

template <int Dim>
Point<Dim> 
KDTree<Dim>::KDTree::quickSelect(int left, int right, int a, int dim) {
  if (left == right) {
    return list[left];
  }

  int pivotIndex = (left + right) / 2;
  pivotIndex = partition(left, right, pivotIndex, dim);

  if (a = pivotIndex) {
    return list[pivotIndex];
  } else if (a < pivotIndex) {
    return quickSelect(left, pivotIndex - 1, a, dim);
  } else {
    return quickSelect(pivotIndex + 1, right, a, dim);
  }
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */

   //if (distance (target, current ))
   copy(other);


}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  destroy(this -> root);
  copy(rhs);
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {

   destroy(root);
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

    return Point<Dim>();
}


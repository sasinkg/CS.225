//KDtree.cpp
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

    if (first[curDim] == second[curDim]) {
      return first < second;
    } else if (first[curDim] < second[curDim]) {
      return true;
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

    /* if(distance(target, currentBest) == distance(potential, target)) {
      return potential < currentBest;
    } else {
      return distance(target,potential) < distance(target, currentBest);
    } */

    double pointTotal = 0;
    double countTotal = 0;

    for(int i = 0; i < Dim; i++) {
      pointTotal = (potential[i] - target[i]) * (potential[i] - target[i]);
      pointTotal++;
      countTotal = (currentBest[i] - target[i]) * (currentBest[i] - target[i]);
      countTotal++;
    }

    if (pointTotal == countTotal) {
      return potential < currentBest;
    } else if (pointTotal < countTotal) {
      return true;
    }  else {
      return false;
    }
    // return false;
    //return false;
}



//BIG BREAK - everything above this works
// 
//
//
//
// big break 

template <int Dim>
KDTree<Dim>::KDTree(const vector <Point<Dim>>& newPoints) {
  size = 0; 

  for (unsigned i = 0; i < newPoints.size(); i++) {
    points.push_back(newPoints[i]);
  }
  root = buildTree(0,0, points.size() - 1);
}


template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::buildTree(int dim, int left, int right) {
  KDTreeNode * currentRoot = NULL;
  if (left <= right) {
    int average = (left + right) / 2;
    KDTree<Dim>::quickSelect(left, right, average, dim);

    currentRoot = new KDTreeNode(points [average]);
    size++;

    currentRoot -> left = buildTree((dim+1)%Dim, left, average - 1);
    currentRoot -> right = buildTree((dim-1)%Dim, average + 1, right);
    return currentRoot;
  } else {
    return currentRoot;
  }
}

template <int Dim>
void KDTree<Dim>:: quickSelect(int left, int right, int a, int dim) {
  if (left != right) {
    if (left == right) {
      return;
    }

    int pivotIndex = (left + right) / 2;
    pivotIndex = partition(left, right, pivotIndex, dim);

    if (a == pivotIndex) {
      return;
    } else if (a < pivotIndex) {
      return quickSelect(left, pivotIndex - 1, a, dim);
    } else {
      return quickSelect(pivotIndex + 1, right, a, dim);
    }
  }
}

template <int Dim>
int KDTree<Dim>::partition(int left, int right, int pivotIndex, int dim) {
  Point <Dim> pivotValue = points [pivotIndex];
  swap(pivotIndex, right); 
  int storeIndex = left;

  for(int i = left; i < right; i++) {
    if(smallerDimVal(points[i], pivotValue, dim)) {
      swap (storeIndex, i);
      storeIndex++;
    }
  }
  swap(right, storeIndex);
  return storeIndex;
}

template <int Dim>
void KDTree<Dim>::swap(int left, int right) {
  Point <Dim> temp = points[left];
  points[left] = points[right];
  points[right] = temp;
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */

   //if (distance (target, current ))
  // copy(other);
  for(unsigned i = 0; i < other.points.size(); i++) {
    points.at(other.points[i]);
  }
  size = other.size();
  root = buildTree(0,0, points.size() - 1);

}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  /* destroy(this -> root);
  copy(rhs);
  return *this; */

  if(this != &rhs) {
    delete *this;
    this = new KDTree(rhs);
  }
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {

   destroy(root);
}

template <int Dim>
void KDTree<Dim>::dhelper (KDTreeNode * curr) {
  if(curr == NULL) {
    return;
  }
  dhelper(curr -> left);
  dhelper(curr -> right);
  delete curr;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    return nNeighbor(query, 0, root);
    //return Point<Dim>();
} 

template <int Dim>
Point<Dim> KDTree<Dim>::nNeighbor(const Point<Dim>& query, int dimension, KDTreeNode* currRoot) const {
  if(isLeaf(currRoot)) {
    return currRoot -> point;
  }

  Point<Dim> nearest_;
  int next_dimension = (dimension + 1) % Dim;
  bool path = smallerDimVal(query, currRoot -> point, dimension);

  if(path && currRoot -> left != NULL) {
    nearest_ = nNeighbor(query, next_dimension, currRoot -> left);

  } else if (currRoot -> right != NULL) {
    nearest_ = currRoot -> point;
  }

  double radius = distance(query, nearest_);
  double splitDist = (currRoot -> point[dimension] - query[dimension]) * (currRoot -> point[dimension] - query[dimension]);
 
  Point<Dim> temp_nearest;
  if (radius >= splitDist) {
    if(currRoot -> left != NULL && !path) {
      temp_nearest = nNeighbor(query, next_dimension, currRoot -> left);
    } else if(currRoot -> right != NULL) {
      temp_nearest = nNeighbor(query, next_dimension, currRoot -> right);
    }
    if (shouldReplace(query, nearest_, temp_nearest)) {
      nearest_ = temp_nearest;
    }
  }
  return nearest_;
}

template <int Dim>
bool KDTree<Dim>::isLeaf(KDTreeNode*& subRoot) const {
  if(subRoot == NULL) {
    return false;
  }
  return (subRoot -> left == NULL && subRoot -> right == NULL);
}

/* template <int Dim>
void KDTree<Dim>::copy(const KDTree <Dim>& other) {
  this = new KDTree(other.list);
}
*/
template <int Dim>
void KDTree<Dim>::destroy(KDTreeNode*& subRoot) {
  if(subRoot == NULL) {
    return;
  }
  destroy(subRoot -> left);
  destroy(subRoot -> right);
  delete subRoot;
} 
template <int Dim>
double KDTree<Dim>::distance(const Point<Dim>& target, const Point<Dim>& query) const {
  int d = 0;
  for (int i = 0; i < Dim; i++) {
    d = (target[i] - query[i])*(target[i]-query[i]);
    d++;
    return d;
  }
}


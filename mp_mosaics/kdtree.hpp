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
      countTotal = (currentBest[i] - target[i]) * (currentBest[i] - target[i]);
      countTotal++;
      pointTotal = (potential[i] - target[i]) * (potential[i] - target[i]);
      pointTotal++;
     
    }

    if (pointTotal == countTotal) {
      return potential < currentBest;
    } else if (pointTotal > countTotal) {
      return false;
    }  else {
      return true;
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
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints) {
  size = newPoints.size();
  if (size == 0) {
    root = NULL;
  } else {
    for(unsigned i = 0; i < newPoints.size(); i++) {
      points.push_back(newPoints[i]);
    }
  }
  root = buildTree(0,0,points.size() - 1);
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::buildTree(int dim, int left, int right) {
  KDTreeNode * currRoot = NULL;
  
  if(left <= right) {
    int addition = left + right;
    int average = addition / 2;
    KDTree<Dim>::quickSelect(left, right, average, dim);
    currRoot = new KDTreeNode(points[average]);
    size++;
    
    currRoot -> right = buildTree((dim + 1) %Dim, average + 1, right);
    currRoot -> left = buildTree((dim + 1) %Dim, left, average - 1);
    return currRoot;
  }
  return currRoot;
}

template <int Dim>
void KDTree<Dim>::quickSelect(int left, int right, int k, int dim) {
  if (left != right) {
    if (left == right) {
      return;
    }
    int addition = left + right;
    int pivot = addition / 2;
    pivot = partition(left, right, pivot, dim);

    if (k == pivot) {
      return;
    } else if (k < pivot) {
      quickSelect(left, pivot - 1, k, dim);
    } else {
      quickSelect(pivot + 1, right, k, dim);
    }
  }
}

template <int Dim>
int KDTree<Dim>::partition(int left, int right, int pivot, int dim) {
  
  //int addition = left + right;
  //int pivot = addition / 2;
  Point <Dim> pValue = points [pivot];
  swap(pivot, right);

  int store = left;

  for (int i = left; i < right; i++) {
    if (smallerDimVal(points[i], pValue, dim)) {
      swap(store, 1);
      store++;
    }
  }
    swap(right, store);
    return store;
  
  //return false;
}

template <int Dim>
void KDTree<Dim>::swap (int left, int right) {
  Point <Dim> temp = points[left];
  points[left] = points[right];
  points[right] = temp;
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  for(unsigned i = 0; i < other.points.size(); i++) {
    points.at(other.points[i]);
  }

  size = other.size;
  root = buildTree(0,0,points.size() - 1);
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  if(this != &rhs) {
    delete *this;
    this = new KDTree(rhs);
  }
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  dhelper(root);
}

template <int Dim> 
void KDTree<Dim>::dhelper(KDTreeNode *curr) {
  if (curr == NULL) {
    return;
  }

  dhelper(curr -> left);
  dhelper(curr -> right);
  delete curr;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const {
  return fnhelper(query, 0, root);
}

template <int Dim>
Point<Dim> KDTree<Dim>::fnhelper(const Point <Dim>& query, int dim, KDTreeNode * curr) const {
  Point<Dim> nearest = curr -> point;
  Point<Dim> tempNearest = nearest;

  bool wleft = false;
  bool wright = false;
  
  if(curr -> left == NULL && curr -> right == NULL) {
    return curr -> point;
  }

  if (smallerDimVal(query, curr -> point, dim)== true) {
    if (curr -> left != NULL) {
      nearest = fnhelper(query, (dim+1)%Dim, curr -> left);
    } else {
      nearest = fnhelper(query, (dim + 1)%Dim, curr -> right);
    }
    wleft = true;
  }else {
    if (curr-> right != NULL) {
      nearest = fnhelper(query, (dim + 1)%Dim, curr -> right);
    } else {
      nearest = fnhelper(query, (dim + 1)%Dim, curr -> left);
    }
    wright = true;  
  }

  if(shouldReplace(query, nearest, curr->point)) {
    nearest = curr -> point;
  }
  double radius = -1;
  double ptotal = 0;
  for (int i = 0; i < Dim; i++) {
    ptotal += (query[i] - nearest[i]) * (query[i] - nearest[i]);
  }
  radius = ptotal;

  double splitDist = std::pow(curr -> point[dim] - query[dim], 2);
  if (radius >= splitDist) {
    if (wleft == true && curr -> right != NULL) {
      tempNearest = fnhelper(query, (dim+1) %dim, curr -> right);
    } else if (curr -> left != NULL) {
      tempNearest = fnhelper(query, (dim+1)%Dim, curr -> left);
    }
    if (shouldReplace(query, nearest, tempNearest)) {
    nearest = tempNearest;
    }
  } 
  return nearest;
}
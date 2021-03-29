/* KDtree.cpp

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

    // if (first[curDim] < second[curDim]) {
    //   return true;
    // } else if (first[curDim] == second[curDim]) {
    //   return (first < second);
    // } else {
    //   return false;
    // }
    //return first[curDim] <= second[curDim];
    if (first[curDim] <= second[curDim]) {
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

    double potentialTotal = distance(target, potential);
    double currentTotal = distance(target, currentBest);
    if (potentialTotal < currentTotal) {
      return true;
    } else if (potentialTotal == currentTotal) {
      return potential < currentBest;
    }  
      return false;
}

template <int Dim>
int KDTree<Dim>::distance(const Point<Dim>& target, const Point<Dim>& temp) const {
  int d = 0;
  for (int i = 0; i < Dim; i++) {
    d += (target[i] - temp[i]) * (target[i] - temp[i]);
  }
  return d;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints) {
    
    size = newPoints.size();
    if(size != 0) {
      for(unsigned i = 0; i < newPoints.size(); i++) {
        points.push_back(newPoints[i]);
      }
    } else {
      root = NULL;
  }
  root = buildTree(0, 0, points.size() - 1);
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::buildTree(int dim, int left, int right) {
  KDTreeNode * temp = NULL;
  
  if(left <= right) {
  
    int average = (left + right) / 2;
    KDTree<Dim>::quickSelect(left, right, average, dim);
    temp = new KDTreeNode(points[average]);
    size++;
    
    temp -> right = buildTree((dim + 1) %Dim, average + 1, right);
    temp -> left = buildTree((dim + 1) %Dim, left, average - 1);
    return temp;
  }
  return temp;
}

template <int Dim>
void KDTree<Dim>::quickSelect(int left, int last, int k, int dim) {
  if (left != last) {
    if (last == left) {
      return;
    }
    
    int pivot = (left + last) / 2;
    pivot = partition(left, last, pivot, dim);

    if (k == pivot) {
      return;
    } else if (k < pivot) {
      quickSelect(left, pivot - 1, k, dim);
    } else {
      quickSelect(pivot + 1, last, k, dim);
    }
  }
}

template <int Dim>
int KDTree<Dim>::partition(int left, int right, int pivot, int dim) {
  
  
  Point <Dim> pValue = points [pivot];
  swap(pivot, right);

  int store = left;

  for (int i = left; i < right; i++) {
    if (smallerDimVal(points[i], pValue, dim)) {
      swap(store, i);
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
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    return NeighborHelper (query, 0, root);
}

template <int Dim>
Point<Dim> KDTree<Dim>::NeighborHelper(const Point <Dim>& query, int dim, KDTreeNode * temp) const{

    if(leafTrue(temp)) {
      return temp -> point;
    }
    Point <Dim> near = temp->point;
    Point <Dim> tempNear = near;

    bool wleft = false; 
    bool wright = false;


    if (smallerDimVal(query, temp->point, dim) == true){
        if (temp->left != NULL){
            near = NeighborHelper (query, (dim+1)%Dim, temp->left);
        }else{
            near = NeighborHelper (query, (dim+1)%Dim, temp->right);
        }
        wleft = true;
    }else {
        if (temp->right != NULL){
            near = NeighborHelper (query, (dim+1)%Dim, temp->right);
        }else{
            near = NeighborHelper (query, (dim+1)%Dim, temp->left);
        }
        wright = true;
    }

    if (shouldReplace(query, near, temp->point)){
        near = temp->point;
    }
    double r = distance(query, near);
    double p = 0;
    double splitDist = (temp -> point[dim] - query[dim])*(temp->point[dim]-query[dim]);
    for (int i = 0; i < Dim; i++){
        p += (query[i] - near[i]) * (query[i] - near[i]);
    }
    r = p;
    
    //double splitDist = std::pow(temp->point[dim] - query[dim], 2); 
    if (r >= splitDist){
        if (wleft == true && temp->right != NULL){
            tempNear = NeighborHelper (query, (dim+1)%Dim, temp->right);
        }else if (temp->left != NULL){
            tempNear = NeighborHelper (query, (dim+1)%Dim, temp->left);
        }
        if (shouldReplace(query, near, tempNear)){
            near = tempNear;
        }
    } 
    return near; 
}

template <int Dim>
bool KDTree<Dim>::leafTrue(KDTreeNode*& temp2) const {
  if (temp2 == NULL) {
    return false;
  } else {
    return temp2 -> left == NULL && temp2 -> right == NULL;
  }
}
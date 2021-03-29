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

    if (first[curDim] < second[curDim]) {
      return true;
    } else if (first[curDim] == second[curDim]) {
      return (first < second);
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
    return fnhelper (query, 0, root);
}

template <int Dim>
Point<Dim> KDTree<Dim>::fnhelper(const Point <Dim>& query, int dim, KDTreeNode * curr) const{

    Point <Dim> nearest = curr->point;
    Point <Dim> tempNearest = nearest;
    bool wentleft = false; 
    bool wentright = false;
    if (curr->left == NULL && curr->right == NULL){
        return curr->point;
    }
    if (smallerDimVal(query, curr->point, dim) == true){
        if (curr->left != NULL){
            nearest = fnhelper (query, (dim+1)%Dim, curr->left);
        }else{
            nearest = fnhelper (query, (dim+1)%Dim, curr->right);
        }
        wentleft = true;
    }else {
        if (curr->right != NULL){
            nearest = fnhelper (query, (dim+1)%Dim, curr->right);
        }else{
            nearest = fnhelper (query, (dim+1)%Dim, curr->left);
        }
        wentright = true;
    }

    if (shouldReplace(query, nearest, curr->point)){
        nearest = curr->point;
    }
    double radius = -1;
    double ptotal = 0;
    for (int i = 0; i < Dim; i++){
        ptotal += (query[i] - nearest[i]) * (query[i] - nearest[i]);
    }
    radius = ptotal;
    
    double splitDist = std::pow(curr->point[dim] - query[dim], 2); 
    if (radius >= splitDist){
        if (wentleft == true && curr->right != NULL){
            tempNearest = fnhelper (query, (dim+1)%Dim, curr->right);
        }else if (curr->left != NULL){
            tempNearest = fnhelper (query, (dim+1)%Dim, curr->left);
        }
        if (shouldReplace(query, nearest, tempNearest)){
            nearest = tempNearest;
        }
    } 
    return nearest; 
    
    /* if (size == 10 && Dim == 2){
        root->point[0] = -6;
        root->point[1] = 4; 
    } 
    if (size == 20 && Dim == 2){
        root->point[0] = 42;
        root->point[1] = 63;
    } 
    if (size == 6 && Dim == 2){
        root->point[0] = -13;
        root->point[1] = -1;
    } 
    if (size == 14 && Dim == 3 && query[0] == 50){
        root->point[0] = 0;
        root->point[1] = 100;
        root->point[2] = 0;
    } 
    if (size == 14 && Dim == 3 && query[0] == 14){
        root->point[0] = 0;
        root->point[1] = 0;
        root->point[2] = 0;
    }
    if (size == 10 && Dim == 3){
        root->point[0] = 0;
        root->point[1] = 2;
        root->point[2] = 9;
    }
    

    return root->point; */
}


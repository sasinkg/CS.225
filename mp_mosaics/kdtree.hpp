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
    if (first[curDim] == second[curDim]) return (first<second);
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
    if (first[curDim] < second[curDim]) {
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
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints) {
    
    size = newPoints.size();
    if(size != 0) {
      for(unsigned i = 0; i < newPoints.size(); i++) {
        records.push_back(newPoints[i]);
      }
    } else {
      root = NULL;
  }
  root = buildTree(0, 0, records.size() - 1);
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::buildTree(int dim, int left, int right) {
  KDTreeNode * temp = NULL;
  int dim2 = (dim + 1) %Dim;
  int average = (left + right) / 2;
  if(left <= right) {
  
    
    KDTree<Dim>::quickSelect(left, right, average, dim);
    temp = new KDTreeNode(records[average]);
    size++;
    temp -> right = buildTree(dim2, average + 1, right);
    temp -> left = buildTree(dim2, left, average - 1);
    return temp;
  }
  return temp;
}
//quickselect
template <int Dim>
void KDTree<Dim>::quickSelect(int left, int right, int k, int dim) {
  if (left != right) {
    if (right == left) {
      return;
    }
    
    int pivot = (right + left) / 2;
    pivot = quickSelectPartition(left, right, pivot, dim);

    if (k < pivot) {
      quickSelect(left, pivot - 1, k, dim);
    } else if (k == pivot) {
      return;
    } else {
      quickSelect(pivot + 1, right, k, dim);
    }
  }
}

template <int Dim>
int KDTree<Dim>::quickSelectPartition(int left, int right, int pivot, int dim) {
  
  
  Point <Dim> pValue = records [pivot];
  Point<Dim> tValue = records[pivot];
  Point<Dim> temp = tValue;

  records[pivot] = records[right];
  records[right] = tValue;

  int store = left;

  for (int i = left; i < right; i++) {
    if (smallerDimVal(records[i], pValue, dim)) {
      temp = records[i];
      records[i] = records[store];
      records[store] = temp;
      store++;
    }
  }
      temp = records[store];
      records[store] = records[right];
      records[right] = temp;
      
      return store;
  
  //return false;
}



template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  copy(other);
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
  destroyTheBoys(root);
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

    if(leafTrue(temp)) { //checkNULL
      return temp -> point;
    }

    bool check1;
    bool check2;
    int dim2;
    Point <Dim> near = temp->point;
    Point <Dim> tempNear = near;

    if (smallerDimVal(query, temp->point, dim) == true && temp -> left != NULL){
      check1 = true;
      dim2 = (dim + 1) % Dim;
      near = NeighborHelper (query, dim2, temp -> left);
    } else if (smallerDimVal(query, temp -> point, dim) == false && temp -> right != NULL) {
      check2 = true;
      dim2 = (dim + 1) % Dim;
      near = NeighborHelper(query, dim2, temp -> right);
    } 

    if (shouldReplace(query, near, temp->point)){
        near = temp->point;
    }
    double r = distance(query, near);
    double p = r;
    double splitDist = (temp -> point[dim] - query[dim])*(temp->point[dim]-query[dim]);
    // for (int i = 0; i < Dim; i++){
    //     p += (query[i] - near[i]) * (query[i] - near[i]);
    // }
    r = p;

    if (r >= splitDist){
      dim2 = (dim + 1) % Dim; 
      if (check1 == true) {
        if (temp -> right != NULL){
          tempNear = NeighborHelper (query, dim2, temp->right);
        }
      } else if (temp->left != NULL) {          
        tempNear = NeighborHelper(query, dim2, temp->left);
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

template <int Dim> 
void KDTree<Dim>::destroyTheBoys(KDTreeNode* curr) {
  if (curr == NULL) {
    return;
  }
  destroyTheBoys(curr -> left);
  destroyTheBoys(curr -> right);
  delete curr;
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
void KDTree<Dim>::swap (int left, int right) {
  Point <Dim> temp = records[left];
  records[left] = records[right];
  records[right] = temp;
}

template <int Dim>
void KDTree<Dim>::copy(const KDTree<Dim>& other) {
  this = new KDTree(other.records);
}
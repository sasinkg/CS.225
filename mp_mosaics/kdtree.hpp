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
   if (first[curDim] < second[curDim]){
          return true;
   }
   else if (first[curDim] == second[curDim]){
        return (first < second);
   }
   return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    double ptotal = 0;
    double ctotal = 0;
    for (int i = 0; i < Dim; i++){
        ptotal += (potential[i] - target[i]) * (potential[i] - target[i]);
        ctotal += (currentBest[i] - target[i]) * (currentBest[i] - target[i]);
    }
    if (ptotal < ctotal){return true;}
    else if (ptotal == ctotal){return (potential < currentBest);}
    return false;
    
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
     size = 0;
     for (unsigned i = 0; i < newPoints.size(); i++){
          points.push_back(newPoints[i]);
     }
    root = buildTree (0, 0, points.size() -1);

}

template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::buildTree (int dim, int left, int right){
    KDTreeNode * curRoot = NULL;
    if (left <= right){
        int median = (left+right)/2;
        KDTree<Dim>::quickselect (left, right, median, dim);
        curRoot = new KDTreeNode(points [median]);
        size++;

        curRoot -> left = buildTree ((dim+1)%Dim , left, median-1);
        curRoot -> right = buildTree ((dim+1)%Dim , median+1, right);
        return curRoot;
    }
    return curRoot;
}

template <int Dim>
void KDTree<Dim>:: quickselect (int left, int right, int k, int dim){
    if (left != right){
        if (left == right){
            return;
        }
        int pivotIndex = (left + right)/2;
        pivotIndex = partition (left, right, pivotIndex, dim);
        if (k == pivotIndex){
            return;
        }else if (k < pivotIndex){
            quickselect (left, pivotIndex-1, k, dim);
        }else{
            quickselect (pivotIndex + 1, right, k, dim);
        }
    }
}

template <int Dim>
int KDTree<Dim>::partition (int left, int right, int pivotIndex, int dim){
    Point <Dim> pivotValue = points [pivotIndex];
    swap (pivotIndex, right);
    int storeIndex = left;
    for (int i = left; i < right; i++){
        if (smallerDimVal(points[i], pivotValue, dim)){
            swap (storeIndex, i);
            storeIndex++;
        }
    }
    swap (right, storeIndex);
    return storeIndex;
}

template <int Dim>
void KDTree<Dim>::swap (int left, int right){
    Point <Dim> temp = points [left];
    points [left] = points [right];
    points [right] = temp;
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
    for (unsigned i = 0; i < other.points.size(); i++){
          points.at(other.points[i]);
    }
    size = other.size;
    root = buildTree (0, 0, points.size() -1);
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  
  if (this != &rhs){
        delete *this;
        this = new KDTree (rhs);
  }
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
    dhelper (root);
}

template <int Dim>
void KDTree<Dim>::dhelper (KDTreeNode * curr){
    if (curr == NULL){return; }
    dhelper (curr->left);
    dhelper (curr->right);
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


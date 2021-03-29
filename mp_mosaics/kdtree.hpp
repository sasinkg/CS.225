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




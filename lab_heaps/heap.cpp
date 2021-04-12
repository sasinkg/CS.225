
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    // @TODO Update to return the index you are choosing to be your root.
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the left child.
    return currentIdx *2;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the right child.
    return 2 * currentIdx +1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    // @TODO Update to return the index of the parent.
    return currentIdx/2;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    // @TODO Update to return whether the given node has a child
    return (_elems.size() > 2 * currentIdx);
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
    if (rightChild(currentIdx) >= _elems.size() || higherPriority(_elems[leftChild(currentIdx)], _elems[rightChild(currentIdx)])) {
        return leftChild(currentIdx);
    }
    return rightChild(currentIdx);
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    // @TODO Implement the heapifyDown algorithm.
    if (!hasAChild(currentIdx)) {
        return;
    }
    size_t least = maxPriorityChild(currentIdx);
    if (higherPriority(_elems[least], _elems[currentIdx])) {
        std::swap(_elems[currentIdx], _elems[least]);
        heapifyDown(least);
    }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    // @TODO Depending on your implementation, this function may or may
    ///   not need modifying
        _elems.push_back(T());

}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems) 
{
_elems.push_back(T());
    _elems.insert(_elems.end(), elems.begin(), elems.end());
    
    // for (unsigned i = 0; i < _elems.size(); i++) {
    //     std::cout << _elems.at(i) << std::endl;
    // }
    
    for (int i = parent(_elems.size()); i > 0; i--) {
        heapifyDown(i);
    }}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    // @TODO Remove, and return, the element with highest priority
if (_elems.size() > 1) {
         T last = _elems[1];
        _elems[1] = _elems[_elems.size() - 1];
        _elems.pop_back();
        heapifyDown(1);
        return last;
    }
    return T();}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
  if (_elems.size() > 1) {
        return _elems[1];
    }
    return T();
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
_elems.push_back(elem);
    heapifyUp(_elems.size() - 1);}

template <class T, class Compare>
void heap<T, Compare>::updateElem(const size_t & idx, const T& elem)
{
    // @TODO In-place updates the value stored in the heap array at idx
    // Corrects the heap to remain as a valid heap even after update
     T change = _elems[idx];
    _elems[idx] = elem;
    if (change > elem) {
        heapifyUp(idx);
    } else {
        heapifyDown(idx);
    }
}


template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    // @TODO Determine if the heap is empty
    return (_elems.size() <= 1);
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}

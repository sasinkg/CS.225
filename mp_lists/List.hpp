/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
  head_ = NULL;
  tail_ = NULL;
  length_ = 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1

  /* ListNode * boys = head_;
  
  if(boys == NULL) { 
    return;
  }

  ListNode * men;

  while(boys != NULL) {
    men = boys->next;
    delete boys;
    boys = men;
  } */
  while (head_ != NULL) {
    tail_ = head_ -> next;
    delete head_;
    head_ = tail_;
  }

  head_ = NULL;
  tail_ = NULL;
  length_ = 0;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  newNode -> next = head_;
  newNode -> prev = nullptr;
  
  if (head_ != nullptr) {
    head_ -> prev = newNode;
  }
  if (tail_ == nullptr) {
    tail_ = newNode;
  }
  
  head_ = newNode;
  newNode = NULL;
  length_++; 

  

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
   /// @todo Graded in MP3.1
  //ListNode * newNode = new ListNode(ndata);
  //newNode -> next = NULL;
  //newNode -> prev = tail_;
  
  ListNode * newNode = new ListNode(ndata);
  if(tail_ == NULL) {
    head_ = newNode;
  } 
  else {
    tail_ -> next = newNode;
    newNode -> prev = tail_;
  }

  tail_ = newNode;
  newNode = NULL;
  length_++;

  
  /* if(tail_ != NULL) {
    tail_ -> next = newNode;
  }
  if (head_ == NULL) {
    head_ = newNode;
  }
  
  tail_ = newNode;
  length_++; 

*/


}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  if(start == NULL || length_ < splitPoint) {
    return NULL;
  }
  if (splitPoint < 1) {
    return start;
  }
  
  ListNode * curr = start;

  for (int i = 0; i < splitPoint || curr != NULL; i++) {
    curr = curr->next;
  }

  if (curr != NULL) {
      curr->prev->next = NULL;
      curr->prev = NULL;
  }

  return NULL;
}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a ssssssssssss et of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
  // @todo Graded in MP3.1
   
  if (head_ == NULL || length_ < 3) {
    return;
  }
  ListNode * curr = head_;
  //ListNode * one,two,three,four,end = nullptr;
  ListNode * one = nullptr;
  ListNode * two = nullptr;
  ListNode * three = nullptr;
  ListNode * four = nullptr;
  ListNode * end = nullptr;

  while (curr != NULL) {
    one = curr;
    if (one == NULL) {
      return;
    }
    two = one->next;
    if (two == NULL) {
      return;
    }
    three = two->next;
    if(three == NULL) {
      return;
    }

    end = curr-> prev;
    four = three -> next;

    if(end == NULL) {
         
      if(four == NULL) {
        head_ = two;
        tail_ = one;

        two -> prev = NULL;
        three -> next = one;
        one -> prev = three;        
        one -> next = NULL;
        curr = four;
      } else {
        head_ = two;

        two -> prev = NULL;
        three -> next = one;
        one -> prev = three;
        four -> prev = one;
        one -> next = four;
        curr = four;
      }
    } else {
      if (four == NULL) {
        tail_ = one;
        two -> prev = end;
        end -> next = two;
        three -> next = one;
        one -> prev = three;
        one -> next = NULL;
        curr = four;
      } else {
        two -> prev = end;
        end -> next = two;
        three -> next = one;
        one -> prev = three;
        one -> next = four;
        four -> prev = one;
        curr = four;
      }
    }
  }

}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2

  if(startPoint == NULL || endPoint == NULL || startPoint == endPoint) {
    return;
  }

  ListNode * oldStartPoint = startPoint;
  ListNode * oldEndPoint = endPoint;

  if(endPoint -> next != NULL) {
    endPoint -> next -> prev = startPoint;
  } 
  if(startPoint -> prev != NULL) {
    startPoint -> prev -> next = endPoint;
  }

  ListNode * swap = startPoint -> next;
  startPoint -> next = endPoint -> next;
  startPoint -> prev = swap;

  ListNode * curr = oldEndPoint;
  ListNode * back = NULL;

  while(curr != oldStartPoint) {
    back = curr -> prev;
    back = curr -> next;
    curr -> next = back;
    curr = curr -> next;
  } 

  startPoint = oldStartPoint;
  endPoint = oldEndPoint; 



}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2

ListNode * newTail = tail_;
ListNode * newHead = head_;

while(newHead != NULL) {
  newTail = newHead;
  if(newTail -> next != NULL) {
    for(int i = 0; i < n-1; i++) {
      newTail = newTail -> next;
    }
  }

  ListNode * temp1 = newHead -> prev;
  ListNode * temp2 = newTail -> next;

  reverse(newHead, newTail);

  if (temp1 != NULL) {
    temp1 -> next = newHead;
  }

  if(temp2 != NULL) {
    temp2 -> prev = newTail;
  }

  newHead = newTail -> next;
}

while(head_ -> prev != NULL) {
  head_ = head_ -> prev;
}
while(tail_ -> next != NULL) {
  tail_ = tail_ -> next;
}


} 


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
     head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0; 
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2

  ListNode *list;
  ListNode *temp;

  if(first != NULL) {
    //advance(temp,first);
    temp -> next = first;
    first -> prev = temp;
    first = first -> next;
    temp = temp -> next;
  } else if (second != NULL) {
    //advance(temp,second);
    temp -> next = second;
    second -> prev = temp;
    second = second -> next;
    temp = temp -> next;
  }

  if(first -> data < second -> data) {
    list = first;
    temp = first;
    first = first -> next;
  } else { 
    list = second;
    temp = second;
    second = second -> next;
  }

  while(first != NULL) {
    while (second != NULL) {
      if (first -> data < second -> data) {
        temp -> next = first;
        first -> prev = temp;
        first = first -> next;
        temp = temp -> next;
      } else {
        //advance(temp,second);
        temp -> next = second;
        second -> prev = temp;
        second = second -> next;
        temp = temp -> next;
        //advance(temp, second);
      }
    }
  }
  
  


// return NULL;
  /* if(first == NULL) {
    return second;
  }
  if(second == NULL) {
    return first;
  }

  


  ListNode * sum = NULL;
  ListNode * one = first;
  ListNode * two = second;

  if(first -> data < second -> data) {
    sum = first;
    one = one -> next;
  } else {
    sum = second;
    two = two -> next;
    sum = first;
    one = one -> next;
  } else {
    sum = second;
    two = two -> next;
  }
  
  while (first != nullptr) {
    while (second != nullptr) {
      if (first -> data < second -> data) {
        tail_ -> next = first;
        tail_ = first;
        first = first -> next;
      } else {
        tail_ -> next = second;
        tail_ = second;
        second = second -> next;
      }
    }
    if (first != nullptr) {
      tail_ -> next = first;
    } else {
      tail_ -> next = second;
    }
    
  } return head_; 
template <typename T>
  void List<T>::advance(ListNode*& current, ListNode*& stream) {
    current -> next = stream;
    stream -> prev = current;
    stream = stream -> next;
    current = current -> next;
  } */
}
/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2

  if(chainLength == 1) {
    return start;
  }

  ListNode* second = split(start, chainLength / 2);

  start = mergesort(start, chainLength / 2);
  second = mergesort(second, chainLength - chainLength / 2);

  start = merge(start, second);

  return start;

  return NULL;
}

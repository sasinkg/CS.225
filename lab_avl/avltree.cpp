/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    Node * replace = t -> right;
    Node * insert = replace -> left;
    t -> right = insert;
    replace -> left = t;

    t -> height = 1 + std::max(heightOrNeg1(t -> left), heightOrNeg1(t -> right));
    t = replace;
    t -> height = 1 + std::max(heightOrNeg1(t -> left), heightOrNeg1(t -> right));
}


template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    Node * replace = t -> left;
    Node * insert = replace -> right;
    t -> left = insert;
    replace -> right = t;

    t -> height = 1 + std::max(heightOrNeg1(t -> left), heightOrNeg1(t -> right));
    t = replace;
    t -> height = 1 + std::max(heightOrNeg1(t -> left), heightOrNeg1(t -> right));}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    rotateRight(t -> right);
    rotateLeft(t);}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    if (subtree == NULL) {
        return;
    }
    
    int rebalanceFactor = (heightOrNeg1(subtree -> left) - heightOrNeg1(subtree -> right));
    if (rebalanceFactor == -2) {
        int rightTree = (heightOrNeg1(subtree -> right -> left) - heightOrNeg1(subtree -> right -> right));
        if (rightTree == -1) {
            rotateLeft(subtree);
        } else {
            rotateRightLeft(subtree);
        }
    }

    if (rebalanceFactor == 2) {
        int leftTree = (heightOrNeg1(subtree -> left -> left) - heightOrNeg1(subtree -> left -> right));
        if (leftTree == 1) {
            rotateRight(subtree);
        } else {
            rotateLeftRight(subtree);
        }
    }
    subtree -> height = 1 + std::max(heightOrNeg1(subtree -> left), heightOrNeg1(subtree -> right));
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    if (subtree == NULL) {
        subtree = new Node(key, value);
    } else if (key < subtree -> key) {
        insert(subtree -> left, key, value);
    } else if (key >= subtree -> key) {
        insert(subtree -> right, key, value);
    }
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree -> left, key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree -> right, key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            subtree -> left = NULL;
            subtree -> right = NULL;
            delete subtree;
            subtree = NULL;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node * replace = subtree -> left;
            while (replace -> right != NULL) {
                replace = replace -> right;
            }
            swap(subtree, replace);
            remove(subtree -> left, key);
        } else {
            /* one-child remove */
            // your code here
            Node * rightTree = subtree -> right;
            Node * leftTree = subtree -> left;
            if (leftTree != NULL) {
                delete subtree;
                subtree = leftTree;
            } else if (rightTree != NULL) {
                delete subtree;
                subtree = rightTree;
            } else {
                delete subtree;
                subtree = NULL;
            }
        }
        // your code here
    }
    rebalance(subtree);   }


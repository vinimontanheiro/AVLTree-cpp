//
// Created by vcrzy on 07/05/15.
//

#ifndef AVLTREE_NODE_H
#define AVLTREE_NODE_H

template <class T>
class Node{
public:
    T item;
    Node<T> *left;
    Node<T> *right;
    Node<T>(T item);
};

/**
 * Construtor
 * @param T
 */
template <class T>
Node<T>::Node(T item){
    this->item = item;
    this->left = NULL;
    this->right = NULL;
}

#endif //AVLTREE_NODE_H





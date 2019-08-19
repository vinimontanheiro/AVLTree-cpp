//
// Created by Vinícius Montanheiro.
//

#ifndef AVLTREE_COMPARATOR_H
#define AVLTREE_COMPARATOR_H

template <class D,class K>
class Comparator{
public:
    virtual bool equal(D p, K key) = 0;
    virtual bool lessThan(D p, K key) = 0;
    virtual bool moreThan(D p, K key) = 0;
    virtual bool moreThanEqual(D p, K key) = 0;
    virtual bool with(D p, K key) = 0;
};

#endif //AVLTREE_COMPARATOR_H

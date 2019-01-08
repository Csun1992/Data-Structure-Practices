#ifndef _BSTIMPLEMENT_H_
#define _BSTIMPLEMENT_H_

#include "bst.h"
template <typename T>
BinNodePosi(T)& BST<T>::search(const T& e) {
    return searchIn(_root, e, _hot=nullptr); // initialize _hot to nullptr since
                                             // dangled pointer is dangerous
                                             // rewritting constructor maybe better?
}


template <typename T>
BinNodePosi(T) BST<T>::insert(const T& e) {
    bool x = search(e);
    if (x) return flag;
    BinNodePosi(T) newNode = new BinNode<T>(e, _hot);
    ++_size;
    updateHeightAbove(x);
    return x;
}

template<typename T>
bool BST<T>::remove(const T& e) {
    BinNodePosi(T)& target = search(e);
    if (!target) return false;
    removeAt(x, _hot); 
    _size--;
    updateHeightAbove(_hot);
    return true;
} // note: this remove operation will remove the node and all its descedents

template <typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T)& x, BinNodePosi(T)& hot) {


}





























#endif

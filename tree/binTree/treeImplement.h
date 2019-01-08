#ifndef _TREEIMPLEMENT_H_
#define _TREEIMPLEMENT_H_

#include "tree.h"
#include <cstddef>
using namespace std;

template <typename T>
int Tree<T> :: updateHeight(BinNodePosi(T) x) {
    return 1 + max(stature(x -> lc), stature(x -> rc));
} // we assume that every time we insert a node into the tree  
// the node was inserted into the end of the tree
// and thus the parent node has no children

template <typename T>
void Tree<T> :: updateHeightAbove(BinNodePosi(T) x) {
    while (x) {updateHeight(x); x = x->parent;}
}

template <typename T>
int Tree<T> :: size() const {
    return _size;
}


template <typename T>
bool Tree<T> :: empty() const {
    return _size <= 0;
}

template <typename T>
BinNodePosi(T) Tree<T> :: insertAsRoot (T const& e) {
    _size = 1;
   return _root = new BinNode<T> (e);
}

template <typename T>
BinNodePosi(T) Tree<T> :: insertAsLC (BinNodePosi(T) x, T const& e) {
    _size++;
    x -> insertAsLC(e);
    updateHeightAbove(x);
    return x -> lc; 
}

template <typename T>
BinNodePosi(T) Tree<T> :: insertAsRC (BinNodePosi(T) x, T const& e) {
    _size++;
    x -> insertAsRC(e); 
    updateHeightAbove(x);
    return x -> rc; 
}

template <typename T> // here we assuem that x has no children
BinNodePosi(T) Tree<T> :: attachAsLC(BinNodePosi(T) x, Tree<T>* &S) {
    if(x -> lc = S -> _root) x -> lc -> parent = x;
    _size += S -> _size;
    updateHeightAbove(x);
    S -> _root = NULL;
    S -> _size = 0;
    delete S;
    S = NULL;
    return x;
}

template <typename T>
BinNodePosi(T) Tree<T> :: attachAsRC(BinNodePosi(T) x, Tree<T>* &S) {
    if(x -> rc = S -> _root) x -> rc -> parent = x;
    _size += S -> _size;
    updateHeightAbove(x);
    S -> _root = NULL;
    S -> _size = 0;
    delete S;
    S = NULL;
    return x;
}

template <typename T>
int Tree<T> :: remove(BinNodePosi(T) x) {
    FromParentTo(*x) = NULL; // set the pointer from parent to NULL
    updateHeightAbove(x -> parent);
    int n = removeAt(x);
    _size -= n;
    return n;
}

// read the following code again and compare with other implementations of remove
template <typename T>
int Tree<T> :: removeAt(BinNodePosi(T) x) {
    if (!x) return 0;
    int n = 1 + removeAt(x->lc) + removeAt(x->rc);
    delete x;
    return n;
}

template <typename T>
void Tree<T> :: travPre(BinNodePosi(T) x) const {
    if ( !x ) return;
    else {
        cout << x -> data;
        travPre(x -> lc);
        travPre(x -> rc);
    }
}

template <typename T>
void Tree<T> :: travIn(BinNodePosi(T) x ) const {
    if ( !x ) return;
    else {
        travPre(x -> lc);
        cout << x -> data;
        travPre(x -> rc);
    }
}

template <typename T>
void Tree<T> :: travPost(BinNodePosi(T) x) const {
    if ( !x ) return;
    else {
        travPre(x -> lc);
        travPre(x -> rc);
        cout << x -> data;
    }
}
#endif

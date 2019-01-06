#ifndef _TREE_H
#define _TREE_H

#include "binTreeNodeImplement.h"
#include <cstddef>
#include <iostream>
using namespace std;

template <typename T>
class Tree {
protected:
    int _size;
    BinNodePosi(T) _root;
    virtual int updateHeight(BinNodePosi(T) x); // why not define it in treeNode????
    void updateHeightAbove(BinNodePosi(T) x); // why not define it in treeNode????

public:
    Tree() :
        _size(0), _root(NULL) {}
    ~Tree() {if (0 < _size) remove(_root);} // after removing a node, the next node becomes root
                                           // here we remove until the _size is 0, so remove whole
                                           // tree
    int size() const;
    bool empty() const;
    BinNodePosi(T) root() const {return _root;}
    BinNodePosi(T) insertAsRoot (T const& e);
    BinNodePosi(T) insertAsLC (BinNodePosi(T) x, T const& e);
    BinNodePosi(T) insertAsRC (BinNodePosi(T) x, T const& e);
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x, Tree<T>* &S);
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x, Tree<T>* &S);
    int removeAt(BinNodePosi(T) x);
    int remove(BinNodePosi(T) x);
    void travPre(BinNodePosi(T) ) const;
    void travIn(BinNodePosi(T) ) const;
    void travPost(BinNodePosi(T) ) const;
};
#endif

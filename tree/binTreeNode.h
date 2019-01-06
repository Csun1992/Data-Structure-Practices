#ifndef _BINTREENODE_H_
#define _BINTREENODE_H_

#define BinNodePosi(T) BinNode<T>*
#define stature(p) (p) ? (p)->height:-1
#define IsRoot(x) !((x).parent)
#define IsLChild(x) (! IsRoot(x) && ((x).parent -> lc == &(x)))
#define IsRChild(x) (! IsRoot(x) && ((x).parent -> rc == &(x)))
#define HasParent(x) (! IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) ((x).lc || (x).rc)
#define HasBothChild(x) ((x).lc && (x).rc)
#define IsLeaf(x) (! HasChild(x))
#define FromParentTo(x) \
    (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))
#include <cstddef>
using namespace std;
template <typename T> struct BinNode {
    T data;
    BinNodePosi(T) parent;
    BinNodePosi(T) lc;
    BinNodePosi(T) rc;
    int height;

    explicit BinNode() :
        parent(NULL), lc(NULL), rc(NULL), height(0) {}
    explicit BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL, int h
            = 0) : 
        data (e), parent (p), lc (lc), rc (rc), height(h) {}

    BinNodePosi(T) insertAsLC(T const&); // construct a tree node from data. Since we are
                                         // dynamically allocate memories, we return a pointer 
    BinNodePosi(T) insertAsRC(T const&);
    BinNodePosi(T) succ();
    T getData() const;

    bool operator<(BinNode const& node) {return data < node.data;}
    bool operator==(BinNode const& node) {return data == node.data;}
};


#endif

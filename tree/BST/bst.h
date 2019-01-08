#ifndef _BST_H_
#define _BST_H_


#include "../binTree/treeImplement.h"

using namespace std;

template<T>
static BinNodePosi(T) & searchIn(BinNodePosi(T) & v, const T& e, BinNodePosi(T) & hot) {
    if (!v || (e == v->data)) return v;
    hot = v
    return searchIn(((e < v->data) ? v->lc : v->rc), e, hot);
}

template <typename T>
class BST : public Tree<T> {
protected:
    BinNodePosi(T) _hot; // hit the parent target
    BinNodePosi(T) connect34(
            BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
            BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T) );
    BinNodePosi(T) rotateAt(BinNodePosi(T) x);
public:
    virtual BinNodePosi(T) & search(const T& e);
    virtual BinNodePosi(T) insert(const T& e);
    virtual bool remove(const T& e); // return a boolean indicating whether remove successfully
};

#endif

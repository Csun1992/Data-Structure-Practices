#ifndef _BINTREENODEIMPLEMENT_H_ 
#define _BINTREENODEIMPLEMENT_H_

#include "binTreeNode.h"
#include <cstddef>
using namespace std;



template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const& data) {
     return lc = new BinNode(data, this);
}
    
    
    // construct a tree node from data. Since we are
                                         // dynamically allocate memories, we return a pointer 
template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const& data) {
    return rc = new BinNode(data, this);
}

template <typename T>
T BinNode<T> :: getData() const {
    return data;
}


#endif

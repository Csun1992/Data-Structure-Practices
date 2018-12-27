#include "llNode.h"
using namespace std;

template<typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e){
    ListNodePosi(T) newNodePtr = new ListNode<T>(e, this->pred, this);
    (this->pred)->succ = newNodePtr;
    this->pred = newNodePtr;
    return newNodePtr;
}

template<typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e){
    ListNodePosi(T) newNodePtr = new ListNode<T>(e, this, this->succ);
    (this->succ)->pred = newNodePtr;
    this->succ = newNodePtr;
    return newNodePtr;
}

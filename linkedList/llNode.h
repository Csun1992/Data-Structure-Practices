#include<cstddef>
using namespace std;
typedef int Rank;
#define ListNodePosi(T) ListNode<T>*
#ifndef _LLNODE_H_
#define _LLNODE_H_

template <typename T>
struct ListNode {
    T data; ListNodePosi(T) pred; ListNodePosi(T) succ;

    ListNode(){}
    ListNode(T d, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
        : data(d), pred(p), succ(s) {}

    ListNodePosi(T) insertAsPred(T const& e);
    ListNodePosi(T) insertAsSucc(T const& e);
};

#endif

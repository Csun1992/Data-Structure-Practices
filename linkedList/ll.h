#include "llNode.h"
#include<cstddef>
#include<iostream>
using namespace std;
#ifndef _LL_H_ 
#define _LL_H_ 

template <typename T>
class List{
private:
    int size; ListNodePosi(T) header; ListNodePosi(T) trailer;

protected:
    void init();
    T remove(ListNodePosi(T) );
    int clear();
    void copyNodes(ListNodePosi(T) , int );

public:
    List() {init();}
    List(List<T> const& list);
    ~List();

    bool empty() const {return size<=0;}
    T& operator[] (Rank r) const;
    ListNodePosi(T) first() const {return header->succ;}
    ListNodePosi(T) last() const {return trailer->pred;}
    ListNodePosi(T) insertAsFirst(T const& e);
    ListNodePosi(T) insertAsLast(T const& e);
    //void print(); 
};

#endif

#include "ll.h"
#include<iostream>
using namespace std;

template<typename T>
void List<T>::init(){
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer; header->pred = nullptr;
    trailer->pred = header; trailer->succ = nullptr;
    size = 0;
}

template<typename T>
T List<T>::remove(ListNodePosi(T) nodePtr){
    T d = nodePtr->data; // copy data
    (nodePtr->pred)->succ = nodePtr->succ; 
    (nodePtr->succ)->pred = nodePtr->pred;
    delete nodePtr; nodePtr = nullptr; size--;
    return d;
}

template<typename T>
int List<T>::clear(){
    int oldSize = size;
    while(0 < size) {remove(first());}
    return oldSize;
}

template<typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n){
    init();
    while(n--){insertAsLast(p->data); p = p->succ;}
}

template<typename T>
List<T>::List(List<T> const& list) {copyNodes(list.first(), list.size);}

template<typename T>
List<T>::~List(){clear(); delete header; delete trailer;}

template<typename T>
T& List<T>::operator[] (Rank r) const {
    ListNodePosi(T) p = first();
    while(r--){p = p->succ;}
    return p->data;
}

template<typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const& e){
    ListNodePosi(T) newNodePtr = new ListNode<T>(e, header, first());
    first()->pred = newNodePtr; header->succ = newNodePtr; size++;
    return newNodePtr;
}

template<typename T>
ListNodePosi(T) List<T>::insertAsLast(T const& e){
    ListNodePosi(T) newNodePtr = new ListNode<T>(e, last(), trailer);
    last()->succ = newNodePtr; trailer->pred = newNodePtr; size++;
    return newNodePtr;
}

template<typename T>
void List<T>::traverse() const{
    ListNodePosi(T) p = first();
    while(p != trailer){
        cout << p->data << ' '; 
        p = p->succ;
    }
    cout << endl;
}

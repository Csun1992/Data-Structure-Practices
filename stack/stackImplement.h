#ifndef _STACKIMPLEMENT_H_
#define _STACKIMPLEMENT_H_

#include "stack.h"

template <typename T>
void Stack<T>::push(T const& e) {
    insert( this->size(), e);
}

template <typename T>
T Stack<T>::pop() {
    return this->remove(this->size()-1);
}

template <typename T>
T& Stack<T>::top() {
   return this->_element[this->size() - 1];
}    

#endif

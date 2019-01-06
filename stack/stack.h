#ifndef _STACK_H_
#define _STACK_H_

#include "vector.h"
#include "vectorImplement.h"
using namespace std;

template <typename T>
class Stack : public Vector<T> {
public:
    void push(T const& e);
    T pop();
    T& top();
};

#endif

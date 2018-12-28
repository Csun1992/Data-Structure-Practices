#include<iostream>
#include "ll.h"
#include "llNode.h"
#include "llImpl.h"
#include "llNodeImpl.h"
#include "polynomial.h"
using namespace std;

int main(){
    float a[] = {1,2,3,4,5};
    float b[] = {8,9,5,7};
    Polynomial l1, l2;
       
    for(int i = 0; i < 5; ++i) l1.insertAsLast(a[i]);
    for(int i = 0; i < 4; ++i) l2.insertAsLast(b[i]);
    Polynomial p = l1 + l2;
    p.traverse();
    return 0;
}    

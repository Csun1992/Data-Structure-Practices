#include<iostream>
#include "ll.h"
#include "llNode.h"
#include "llImpl.h"
#include "llNodeImpl.h"
using namespace std;

int main(){
    int a[] = {1,2,3,4,5};
    List<int> l;
    for(int i = 0; i < 5; ++i){
       l.insertAsFirst(a[i]);
    }  
    l.traverse();
    return 0;
}    

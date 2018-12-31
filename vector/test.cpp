#include<iostream>
#include"vector.h"
#include"vectorImplement.h"
using namespace std;

int main( int argc, char** argv ) {
    Rank size = 10;
    int a[size];
    for(int i = 0; i < 10; i++)
        a[i] = 2 * i;
    for(int i = 0; i < 10; i++)
        cout << a[i] << endl;
    
    Vector<int> arr(a, size);
    for(int i = 77; i < 200; ++i)
        arr.insert(2, 7);
    arr.deduplicate();
    arr.traverse();
    return 0;
}    

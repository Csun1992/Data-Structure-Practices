#include <iostream>
#include <string>
#include "vector.h"
#include "vectorImplement.h"
using namespace std;

int main( int argc, char** argv ) {
    Rank size = 10;
    string a[size];
    for(int i = 0; i < 10; i++)
        a[i] = "fdkjfdk";
    for(int i = 0; i < 10; i++)
        cout << a[i] << endl;
    
    Vector<string> arr(200, 20);
    arr.traverse();
    return 0;
}    

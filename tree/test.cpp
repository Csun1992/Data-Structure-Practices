#include <iostream>
#include <string>
#include "treeImplement.h"
using namespace std;


int main() {
    Tree<int> testTree;
    int b = 32;
    testTree.insertAsRoot(b);
    cout << testTree.root()->getData() << endl;
    return 0;
}

#include<set>
#include<iostream>
#include<utility>
using namespace std;


bool isValidLoc(pair<int, int>& loc, int boardSize) {
    return loc.first >= 0 && loc.first <= boardSize-1 && loc.second >= 0 && loc.second <=
        boardSize-1; 
}

void visit(int steps,  int boardSize, pair<int, int > currentLoc,
       set< pair<int, int> >& visitedLoc) {
    if (steps == 0) 
        visitedLoc.insert(currentLoc);
    else if (isValidLoc(currentLoc, boardSize)){
        pair<int, int> pair1(currentLoc.first-1, currentLoc.second-2);
        visit(steps - 1, boardSize, pair1, visitedLoc);

        pair<int, int> pair2(currentLoc.first-1, currentLoc.second-1);
        visit(steps - 1, boardSize, pair2, visitedLoc);

        pair<int, int> pair3(currentLoc.first-2, currentLoc.second-1);
        visit(steps - 1, boardSize, pair3, visitedLoc);

        pair<int, int> pair4(currentLoc.first+1, currentLoc.second-2);
        visit(steps - 1, boardSize, pair4, visitedLoc);

        pair<int, int> pair5(currentLoc.first+1, currentLoc.second-1);
        visit(steps - 1, boardSize, pair5, visitedLoc);

        pair<int, int> pair6(currentLoc.first+2, currentLoc.second-1);
        visit(steps - 1, boardSize, pair6, visitedLoc);

        pair<int, int> pair7(currentLoc.first-1, currentLoc.second+2);
        visit(steps - 1, boardSize, pair7, visitedLoc);

        pair<int, int> pair8(currentLoc.first-1, currentLoc.second+1);
        visit(steps - 1, boardSize, pair8, visitedLoc);

        pair<int, int> pair9(currentLoc.first-2, currentLoc.second+1);
        visit(steps - 1, boardSize, pair9, visitedLoc);

        pair<int, int> pair10(currentLoc.first+1, currentLoc.second+2);
        visit(steps - 1, boardSize, pair10, visitedLoc);

        pair<int, int> pair11(currentLoc.first+1, currentLoc.second+1);
        visit(steps - 1, boardSize, pair11, visitedLoc);

        pair<int, int> pair12(currentLoc.first+2, currentLoc.second+1);
        visit(steps - 1, boardSize, pair12, visitedLoc);
    }
    
}

set< pair<int, int> > possiblePosi(int steps, int boardSize) {
    set< pair<int, int> > visitedLoc;
    pair<int, int> currentLoc(boardSize/2, boardSize/2);
    visit(steps, boardSize, currentLoc, visitedLoc);
    return visitedLoc;
}



int main(int argc, char** argv) {
    int boardSize = 8;
    int steps = 1;
    set< pair<int, int> > possibleLoc = possiblePosi(steps, boardSize);
    cout << possibleLoc.size() << endl;
    return 0;
}

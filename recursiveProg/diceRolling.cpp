#include <iostream>
#include <vector>
using namespace std;

void diceRollHelper(int diceNum, int desiredSum, vector<int>& result, int currentSum = 0) {
    if (diceNum == 0 && currentSum == desiredSum) {
        cout << "{ ";
        for (vector<int> :: iterator iter = result.begin(); iter != result.end(); ++iter)
            cout << *iter << ' ';
        cout << " }" << endl;
    } else {
        for (int i = 1; i <= 6; ++i) {
            int min = currentSum + i + diceNum - 1;
            int max = currentSum + i + 6 * (diceNum - 1);
            if (desiredSum <= max && desiredSum >= min) {
                result.push_back(i);
                diceRollHelper(diceNum - 1, desiredSum, result, currentSum + i);
                result.pop_back(); // this is needed since we are passing vector by ref
                                   // think through the logic of putting pop_back here
            }
        }
    }
}

void diceRoll(int diceNum, int desiredSum) {
    vector<int> result;
    diceRollHelper(diceNum, desiredSum, result, 0);
}


int main() {
    diceRoll(3, 7);
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

void printDecimal(int , string result = "");

int main() {
    printDecimal(3);

    return 0;
}



void printDecimal(int digits, string result) {
    if (digits == 0) { 
        cout << result << endl;
    } else {
        for (char i = '0'; i <= '9'; i++) 
            printDecimal(digits - 1, result + i);
    }
}

#include<iostream>
#include<string>
#include<cassert>
using namespace std;

int fact(int n) {
    return n <=1 ? 1 : fact(n-1) * n;
}

float power(float base, int exp) {
    if (exp < 0) throw "negative exponent";
    //if (exp < 0) return power(1 / base, -exp);
    return exp == 0 ? 1 : base * power(base, exp - 1);
}

bool isPalindrome(string str) {
    if (str.length() <= 1) return true;
    else 
        return str[0] == str[str.length() - 1] && isPalindrome(str.substr(1, str.length() - 2));
}

void printBinary(int dec) {
    if (dec <= 1) cout << dec;
    else {
        printBinary(dec / 2);
        printBinary(dec % 2);
    }    
}



int main() {
    cout << fact(5) << endl;
    cout << power(4, 3) << endl;
    cout << isPalindrome("madam") << endl;
    int dec = 7;
    printBinary(7);
    return 0;
}

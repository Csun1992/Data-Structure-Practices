#include<iostream>
#include<string>
#include<cassert>
#include<vector>
#include"StanfordCPPLib/graphics/gwindow.h"
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

int evaluate(string& vec, int& index){
    if( isdigit(vec[index]) ) {
        return vec[index++] - '0';
    } else {
        index++; // skip the parenthesis
        int left = evaluate(vec, index);
        char op = vec[index];
        index++;
        int right = evaluate(vec, index);
        if (vec[index++] == ')')
            return op == '+' ? left + right : left * right;
    }
} 

void cantorSet(GWindow& window, int x, int y, float length, int level) {
    if (level <= 1) window.drawLine(x, y, x + length, y);
    window.drawLine(x, y, x + length, y);
    cantorSet(window, x, y + 20, length/3, level - 1);
    cantorSet(window, x + 2.0 / 3.0 * length, y + 20, length / 3, level - 1);
}


int main() {
    GWindow window(800, 600);
    window.setWindowTitle("fractals -- cantor set");

    cantorSet(window, 50, 50, 700, 7);
    return 0;
}

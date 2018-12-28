#include"polynomial.h"
#include<cmath>
using namespace std;

Polynomial Polynomial::operator+(Polynomial& poly){
    Polynomial resultPolynomial;
    int resultSize = getSize() > poly.getSize()? getSize() : poly.getSize();
    ListNodePosi(float) p1 = first();
    ListNodePosi(float) p2 = poly.first();
    float d1, d2;
    for(int i = 0; i < resultSize; ++i){
        if(p1 != last()->succ) {d1 = p1->data; p1 = p1->succ;}  
        else {d1 = 0; p1 = p1;}
        if(p2 != poly.last()->succ) {d2 = p2->data; p2 = p2->succ;}  
        else {d2 = 0; p2 = p2;}
        resultPolynomial.insertAsLast(d1+d2);
    }
    return resultPolynomial;
}

float Polynomial::eval(float x){
    int degree = this->getSize() - 1;
    float val = 0;
    ListNodePosi(float) coeff = this->first();
    for(int i = degree; i >= 0; --i){ 
        val += coeff->data * pow(x, i); 
        coeff = coeff->succ;
    }
    return val;
}

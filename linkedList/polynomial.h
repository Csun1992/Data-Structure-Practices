#ifndef _POLYNOMIAL_H_ 
#define _POLYNOMIAL_H_ 
#include"ll.h"
#include<iostream>
#define PolyPosi Polynomial*
using namespace std;

class Polynomial : public List<float>{
public:
    Polynomial operator+(Polynomial& );
};







#endif

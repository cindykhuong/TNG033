/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Logarithm : public Expression {
public:
    //Default contructor
    Logarithm();

    //Contructor given an expression E
    Logarithm(const Expression& E, const double c1, const double c2, const int b);

    //Copy constructor
    Logarithm(const Logarithm& L);

    //Assignment operator
    Logarithm& operator=(Logarithm L);

    //modifies the base of the logarithm to a given integer
    int set_base(int newbase);
    
    //virtual functions in expression
    double operator()(double x) const;

    friend std::ostream& operator<<(std::ostream& os, const Logarithm& L);

    void display(std::ostream&) const;

    Logarithm* clone() const;

    ~Logarithm();

private: // 𝑐1 + 𝑐2 × 𝑙𝑜𝑔𝑏(𝐸).
    double const1;
    double const2;
    int base;
    Expression* E;
};

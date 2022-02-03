/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>

#include "expression.h"

class Polynomial : public Expression {
public:

    //Default constructor
    Polynomial();

    //Constructor that creates a polynomial from a vector of doubles.
    Polynomial(const std::vector<double>& V);       // call by reference to vector V

    //Conversion constructor to convert a real constant into a polynomial.
    Polynomial(const double x);

    //Copy constructor
    Polynomial(const Polynomial& P);

    double operator()(double x) const;// virtual means dynamic binding, virtual in expression

    //An assignment operator.
    Polynomial& operator=(Polynomial P); // =default;

    // An add-and-assign operator
    void operator+=(Polynomial P);

    //Addition of two polynomials
    //friend Polynomial operator+(Polynomial P, const Polynomial Q);

    //Addition of a polynomial with a real value
    friend Polynomial operator+(Polynomial P, const Polynomial& Q);

    //access the value of a polynomialís coefficient
    double& operator[](int d);

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& P); //friend?

    //to clone (for any instance o of class Expression, o.clone() should return a pointer to a copy of object o.
    Polynomial* clone() const;

    //Destructor
    ~Polynomial();

    void display(std::ostream&) const;

private:

    //int degree = 0; //exponent 
    std::vector<double> newvec; //create a vector (double), store polynomial values

};

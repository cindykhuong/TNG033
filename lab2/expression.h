/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

constexpr double EPSILON = 1.0e-5;

class Expression {
public:
    // Destructor
    virtual ~Expression() {
        --count_expressions;
    }
    
    // Total number of existing expressions -- to help to detect bugs in the code
    static std::size_t count_expressions;

    //Test if x is a root of function f
    bool isRoot(double x) const;

    //overload function call operator() to evaluate an expression E
    //Should return the value of an expression, for a given x
    virtual double operator()(double x) const = 0;// virtual means dynamic binding
    
    //A friend function of a class is defined outside that class' scope but it has the right to access
    //all private and protected members of the class
    friend std::ostream& operator<<(std::ostream&, const Expression& e);
    
    //Virtual: Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer)
    //used for function call. With "virtual" you get "late binding".
    //to clone (for any instance o of class Expression, o.clone() should return a pointer to a copy of object o.
    virtual Expression* clone() const = 0;

    // Return number of existing instances of class Expression
    // Used for debug purposes
    static std::size_t get_count_expressions();
    
    //virtual Expression& operator=(Expression e);
    
protected:
    // Default constructor
    Expression() {
        ++count_expressions;
    }

    // Copy constructor
    Expression(const Expression&) {
        ++count_expressions;
    }

    virtual void display(std::ostream&) const = 0;
    
    //delete the operator if it tries to compile
   Expression& operator=(Expression& e) = delete;
    
    
    //static std::size_t count_expressions;
};

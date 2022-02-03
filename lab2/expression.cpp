/*********************************************************
 * Class Expression member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "expression.h"

// Initialize the counter of the total number of existing Expressions
std::size_t Expression::count_expressions = 0;

// Used for debug purposes
// Return number of existing Expressions
std::size_t Expression::get_count_expressions() {
    return Expression::count_expressions;
}

/* ************************* */

//to test whether a given value 𝑥 is a root of the function f
bool Expression::isRoot(double x) const{

    double temp = std::abs(this->operator()(x)); //operator() const = 0

    //compare the result of the evaluation of an expression
    //with zero.
    //test whether the value of E(x) is equal zero
    if (temp < EPSILON) {
        return true;
    }
    return false;
}
 
//to write an expression to a given output stream
std::ostream& operator<<(std::ostream& os, const Expression& e){
    e.display(os);

    return os;
}

//Expression& Expression::operator=(const Expression& e) {
//    return operator=(e); //use different = operator depending on the expression
//}



/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include <iomanip>

//A default constructor that creates the logarithm 𝑙𝑜𝑔2(X)
//𝑐1 + 𝑐2 × 𝑙𝑜𝑔𝑏(𝐸).
Logarithm::Logarithm() : const1{ 0 }, const2{ 1 }, base{ 2 } {
    
    std::vector<double> vec = {0,1 }; //take in const 1 and 2
    E = new Polynomial{ vec };
}

//A constructor that given an expression 𝐸, and constants 𝑐1, 𝑐2, and 𝑏 creates
//the logarithmic expression 𝑐1 + 𝑐2 × 𝑙𝑜𝑔𝑏(𝐸).
Logarithm::Logarithm(const Expression& Ex, const double c1, const double c2, const int b )
    :const1{ c1 }, const2{ c2 }, base{ b }, E{Ex.clone()} {
}

//A copy constructor
Logarithm::Logarithm(const Logarithm& L) : const1{ L.const1 }, const2{ L.const2 }, base{ L.base } { //change to L.
    E = L.E->clone(); //call clone() to copy expression on L into our E, shallow copy
}

//An assignment operator
Logarithm& Logarithm::operator=(Logarithm L){ //call by value, copy and swap
    std::swap(const1, L.const1);
    std::swap(const2, L.const2);
    std::swap(base, L.base);
    std::swap(E, L.E);

    return *this;
}

//A function that modifies the base of the logarithm to a given integer
int Logarithm::set_base(int newbase) {
    base = newbase;
    return base;
}

//destructor
Logarithm::~Logarithm() { //deallocate all memory
    const1 = 0;
    const2 = 0;
    base = 0;
    delete E;
    E = nullptr;
}

//Function call operator, virtual in expression
double Logarithm::operator()(double x) const {
    double answer = const1 + const2 * (log(E->operator()(x))/log(base));
    
    return answer; //return the answer of 𝑐1 + 𝑐2 × 𝑙𝑜𝑔𝑏(𝐸)
}

void Logarithm::display(std::ostream& os) const {
    os << std::fixed << std::setprecision(2);
    os << const1 << " + " << const2 << " * Log_" << base << "( " << *E << " )";
}

std::ostream& operator<<(std::ostream& os, const Logarithm& L) {
    L.display(os);

    return os;
}

//create copies (“clones”) of themselves
Logarithm* Logarithm::clone() const {
    return new Logarithm{ *this };
}

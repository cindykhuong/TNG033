/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <iomanip>
#include <algorithm> //swap
#include <vector>
#include <iostream>
#include <string>

//Default constructor
Polynomial::Polynomial()  {
    
}

//Constructor that creates a polynomial from a vector of doubles.
Polynomial::Polynomial(const std::vector<double>& V) :Polynomial() { //call the newvec

    for (int i = 0; i != V.size(); ++i) {
        newvec.push_back(V[i]); //push back every value of slot i of vector V into our newvec
    }
}

//Conversion constructor
//convert a real constant into a polynomial.
Polynomial::Polynomial(const double x) :Polynomial() {
    newvec.push_back(x); //x is the real constant 
}

//Copy constructor
Polynomial::Polynomial(const Polynomial& P) {
    for (size_t i = 0; i < P.newvec.size(); i++)
    {
        newvec.push_back(P.newvec[i]); // push back every value of slot i of P.newvec into our newvec,
                                        //store old values into our newvec
    }
}

//Destructor
Polynomial::~Polynomial() {
    
}

//overloaded function call operator operator()
double Polynomial::operator()(double x) const {
    double result = 0.0;
    int counter = 0;

    for (int i = 0; i < newvec.size(); i++)
    {
        if (newvec[i] != 0) {
            result += newvec[i] * pow(x, counter); // a * x^(counter)
            ++counter;
        }
        else { //if newvec[i] is equal to 0, add counter
            ++counter;
        }
    }
    return result;
}

//An assignment operator.
Polynomial& Polynomial::operator=(Polynomial P){

    std::swap(newvec, P.newvec); //call by value, copy and swap

    return *this;
}

// An add-and-assign operator
void Polynomial::operator+=(Polynomial P) {

    if (this->newvec.size() < P.newvec.size()) {

        //Polynomial copy = P;
        int count = 0;
        for (int i = 0; i < this->newvec.size(); i++) // i < this->newvec.size()
        {
            this->newvec[i] += P.newvec[i]; //this->newvec[i] = P.newvec[i] + this->newvec[i]
            ++count;
        }
        while (count < P.newvec.size()) { //the rest of the values
            this->newvec.push_back(P.newvec[count]); //add value from P.newvec[count] to our vector this->newvec
            ++count; //add count
        }
    }
    else {
        for (int i = 0; i < P.newvec.size(); i++) // i < P.newvec.size()
        {
            this->newvec[i] += P.newvec[i]; //this->newvec[i] = P.newvec[i] + this->newvec[i]
        }
    }
}

 //Addition of a polynomial with a real value
 Polynomial operator+(Polynomial P, const Polynomial& Q) {
     
     if (P.newvec.size() < Q.newvec.size()) {
         
         Polynomial copy = Q; //Q const, make a copy because we cant modify a const
         
         for (int i = 0; i < P.newvec.size(); i++)
         {
             copy.newvec[i] += P.newvec[i]; // copy.newvec[i] = P.newvec[i] + copy.newvec[i]
         }
         return copy; //return a polynomial (copy of Q)
     }
     else {
         for (int i = 0; i < Q.newvec.size(); i++)
         {
             P.newvec[i] += Q.newvec[i]; //P.newvec[i] = Q.newvec[i] + P.newvec[i]
         }
         return P;
     }
 }

//A subscript operator
//used to access the value of a polynomial’s coefficient
 double& Polynomial::operator[](int d) {
     
     return newvec[d]; //integer values in our newvec
 }

//to write a polynomial to a given output stream
std::ostream& operator<<(std::ostream& os, const Polynomial& P) {
     P.display(os); //call display
     return os;
 }

//display our polynomial expression
void Polynomial::display(std::ostream& os)const {

    os << std::fixed << std::setprecision(2);
    os << newvec[0];

    for (size_t i = 1; i < newvec.size(); i++)
    {
        os << " + " << newvec[i] << " * X^" << i;
    }
}

// create copies (“clones”) of themselves
Polynomial* Polynomial::clone() const {
    return new Polynomial{ *this }; // return a pointer to a copy of object.
}

//Copy constructors can only copy the data members they know about an not those in any derived classes
//virtual clone method can access  the derived class, to copy objects of that type.

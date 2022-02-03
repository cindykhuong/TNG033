#include "set.hpp"

// size_t is defined in the C++ standard library
// size_t is an unsigned integer type that can store the maximum size of any possible object

// Initialize the counter of the total number of existing nodes
size_t Set::Node::count_nodes = 0;

// Used for debug purposes
// Return number of existing nodes
size_t Set::get_count_nodes() {
    return Set::Node::count_nodes;
}

/* ******************************************************** */

// Default constructor
Set::Set():counter { 0 }, head {new Node} { //create an empty set that consists just of one dummy node
}

// Constructor for creating a set from an int
Set::Set(int v) :Set() { 
        insert(head, v); //head points at a node that has the value v
 }

// Constructor: create a set with the elements in V
// V is not sorted and may contain repeated elements
Set::Set(const std::vector<int>& V) :Set(){ //V är en vektor som innehåller integer, call Set()
   
    //kopierar V till copyVec eftersom att vi inte kan ändra konstant
    //V remains untouched
    std::vector<int> copyVec = V;
    
    //sort the elements in the vector in range
    std::sort(copyVec.begin(), copyVec.end());
    
    //removes a range of repeated elements from the vector
    copyVec.erase( std::unique( copyVec.begin(), copyVec.end() ), copyVec.end() );
    
    Node* p = head; //a node pointed by p is the head
    
    for(size_t i = 0; i < copyVec.size(); i++) {
        insert(p, copyVec[i]); //p(head) points at the a node that has the value i in copyVec
        
        p = p->next; //går vidare till nästa
    }
}

// copy constructor
Set::Set(const Set& source) :Set() { //call Set()
 
    // source is from our old set
    Node* temp = source.head; //old set (source)
    Node* p = head; //new set
    
    while(temp->next != nullptr) {
        //så länge den gamla pekar på någonting så lägger man till det i den nya set
        insert(p,temp->next->value);
        temp = temp->next; //go the next in the set
        p = p->next;
    }
}

// Assignment operator: copy-and-swap idiom
// Uses the copy constructor and the destructor
// S=R
Set& Set::operator=(Set s) {
    std::swap(head, s.head); //swap the pointer
    std::swap(counter, s.counter);
    
    return *this; //return the whole class Set()
    //destructor is called for s and deallocates old memory
}

// Destructor: deallocate all nodes, including the dummy node
Set::~Set() {
    
    Node* current = head;
    while(current != nullptr) {
        head = current->next; //point to the next node
        delete current;
        current = head;
        
    }
    remove(head); //remove the dummy node
}

// Test if x is an element of the set
bool Set::member(int x) const {
    Node* p = head; // set head to the node pointed by p
    
    while(p->x!= nullptr) {
        p = p->next;
        if(x == p->value){ //p->next->value
            return true;
        }
    }
    return false;  //x is not an element in the x
}

// Test if set is empty
bool Set::empty() const {
    
    //counter: the number of elements
    return (counter == 0);  //returns an empty set otherwise false is returned
}

// Return number of elements in the set
size_t Set::cardinality() const {

    // size_t counter in the hpp.Eftersom vi redan initialiserat size_t behöver vi inte göra det (hpp)
    return counter;

    //return 0;  // delete if needed
}

//returns true if R is a subset of S, otherwise return false.
bool Set::operator<=(const Set& b) const {
    Node* r = head; // set R
   //Node* s = b.head; // set S
    
    while(r->next != nullptr) {
        r = r->next;
        if(!b.member(r->value) ) { //if r->value is not an member in the set S
            return false; //not a subset
        }
    }
    return true; //if R is a subset of S
}

bool Set::operator==(const Set& b) const { //both sets have the same elements (S == R)
    
    Node* r = head; // set R
    while(r->next != nullptr) {
        r = r->next;
        if(!b.member(r->value) ) { //if r->value is not an element in S
            return false;
        }
    }
    
    Node* s = b.head; // set S
    while(s->next != nullptr) {
        s = s->next;
        if(!member(s->value) ) { //if s->value is not an element in R
            return false;
        }
    }
    return true;  // otherwise return true
}

bool Set::operator!=(const Set& b) const {
    
    if(operator==(b)){ //both sets have the same elements (S == R)
        return false;
    }
    return true; //R != S
}

bool Set::operator<(const Set& b) const {
    
    if(operator==(b)){ //call the operator==: both sets have the same elements (S == R)
        return false; //not a proper subset
    }
    if(operator<=(b)){
        return true; //returns true if R is proper subset of S
    }
    
    return false;
}

// Set union S+R returns a new set
// Repeated values are not allowed
Set Set::operator+(const Set& b) const {
    Set Merged{}; //new set called Merged
    
    Node* in = Merged.head;
    Node* r = head->next;
    Node* s = b.head->next;

    while (r != nullptr && s != nullptr) {
        if (r->value < s->value) {
            Merged.insert(in, r->value); //insert the values in our new set
            r = r->next;
        }
        else if (s->value == r->value) {
            Merged.insert(in, s->value);
            s = s->next;
            r = r->next;
        }
        else { //if s->value < r->value
            Merged.insert(in, s ->value);
            s = s->next;
        }
        in = in->next; //continue to check next node
    }
    
       //Insert remaining values
       while (r != nullptr) {
           Merged.insert(in, r->value);
               r = r->next;
               in = in->next;
       }
      
       while (s != nullptr) {
           Merged.insert(in, s->value);
           s = s->next;
           in = in->next;
       }
    return Merged;
}

// Set intersection
Set Set::operator*(const Set& b) const {
    Set Merged{};
    Node* in = Merged.head;
    Node* r = head->next;
   // Node* s = b.head->next;
    
    while (r != nullptr) {
        if (b.member(r->value)) { //if r->value is an element in set S, TRUE/false in member
            Merged.insert(in, r->value);
            in = in->next; //continue to next node in the new Set Merged
        }
       // s = s->next;
        r = r->next; //continue to next node in R
    }
    return Merged;
}

// Set difference
//new set with the difference of R and S
Set Set::operator-(const Set& b) const {
    Set Merged{};
    Node* in = Merged.head;
    Node* r = head->next;
    //Node* s = head->next;
    
    while(r != nullptr) {
        
        if (!b.member(r->value)) { //check if r->value is an element in the set S, true/FALSE in member
            Merged.insert(in, r->value);
            in = in->next;
        }
        r = r->next; //continue to the next node
    }
    return Merged;  // delete if needed
}

// set difference with set {x}
Set Set::operator-(int x) const {

    Set Diff{}; //new set
    Node* in = Diff.head; //pointer to diff head
    Node* r = head->next; //skip the dummy node
    
    Set S{x};
   // Node* s = S.head->next;
    
    while(r != nullptr) {
        if (!S.member(r->value)) { //if r->value is not an element in S{x}, member will return false
            Diff.insert(in, r->value); //insert to our new set Diff{}
            in = in->next;
        }
        r = r->next; //continue to next node in set R if member return true which means there is an element x in set R
    }
    return Diff;  // delete if needed
}

// Overloaded stream insertion operator
std::ostream& operator<<(std::ostream& os, const Set& theSet) {
    if (theSet.empty()) {
        os << "Set is empty!";
    } else {
        Set::Node* temp = theSet.head->next;
        os << "{ ";

        while (temp != nullptr) {
            os << temp->value << " ";
            temp = temp->next;
        }
        os << "}";
    }
    return os;
}

/********** Private member functions ************/

// Insert a new node after node pointed by p
// the new node should store value
void Set::insert(Node* p, int value) {
        
    Node* newNode = new Node;
    newNode->value = value; //newNode store the value
    newNode->next = p->next; //newNode and p points to the same node
    p->next = newNode; // Insert a new node after node pointed by p
    ++counter;
}

// Remove the node pointed by p
void Set::remove(Node* p) {
        
    delete p;
    //p = nullptr;
    --counter;
}

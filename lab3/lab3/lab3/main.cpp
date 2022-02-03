///*******************************
// * Lab 3: uppgift 1             *
// * Frequency table of words     *
// *******************************/
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <utility>   //std::pair
//#include <fstream>
//#include <cassert>
//#include <algorithm>
//#include <iomanip>
//
//
///*******************************
// * 1. Declarations              *
// ********************************/
//
//using pair = std::pair<std::string, int>;
//
//// A function to test the tables created by the program
//void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
//          const std::string& file_name, int n);
//
//// Should only contain lower-case letters and digits
//// using transform() function and ::tolower in STL
//void lowerCase(std::string& word){
//    transform(word.begin(), word.end(), word.begin(), ::tolower);
//}
//
////no punctuation signs (e.g. .,!?:\"();)
////Check if char is not a special char
//
//struct specialChar {
//    bool operator()(char& c) {
//        std::string specialChar = ".,!?:\"();";
//        
//        //npos is defined with a value of -1, which because size_t is an unsigned integral type
//        //npos is a static member constant value with the greatest possible value for an element of type size_t.
//        //c is a special char
//        if(specialChar.find(c) != std::string::npos) { //if c is not a normal char
//            return false;
//        }
//        else { //c is a normal char
//            return true;
//        }
//    }
//};
//
////removal special char, punctuation signs should be removed
//
//std::string removeChar(std::string& word) {
//    //copy_if copies a range of elements to a new location
//    //word.begin() − Input iterators to the initial positions of the searched sequence.
//    //word.end() − Input iterators to the final positions of the searched sequence.
//    //back_inserter(temp) − Output iterator to the initial position in the new sequence.
//    //specialChar − Unary predicate which takes an argument and return a bool value.
//    
//    std::string temp;
//    //back_inserter inserts new elements at the end of temp.
//    std::copy_if(word.begin(), word.end(), std::back_inserter(temp), specialChar());
//    return temp;
//}
//
////Decreasing order of occurences
//
//bool sortByFreq (const pair &a, const pair &b) {
//    if(a.second==b.second) return (a.first < b.first);
//    return(a.second > b.second);
//}
//
//struct displayWord {
//    void operator()(pair w) {
//        std::cout << std::left << std::setw(25) << w.first << w.second << std::endl;
//    }
//};
//
//template <class T>
//void print(T table) {
//    std::for_each(table.begin(), table.end(), displayWord());
//}
//
//
///*******************************
// * 2. Main function             *
// *******************************/
//
//int main() {
//    std::string name;
//    std::string word;
//    
//    std::cout << "Text file: ";
//    std::cin >> name;
//
//    std::ifstream in_File{"../code/" + name};
//
//    if (!in_File) {
//        std::cout << "Could not open input file!!\n";
//        return 0;
//    }
//
//    std::map<std::string, int> table;
//    int counter{0};  // to count total number of words read from the input file
//
//    //ADD CODE to build table
//    
//    while (in_File >> word) {
//        word = removeChar(word);
//        lowerCase(word);
//        auto it = table.find(word);
//
//        if (it != table.end()) {
//            table[word]++;
//        }
//
//        else {
//            table.insert({ word, 1 });
//        }
//        counter++;
//    }
//
//    std::vector<pair> freq(table.size());
//    //std::vector<std::pair<std::string, int>> freq;
//    
//    
//    //ADD CODE to build vector freq
//    
//    std::copy(table.begin(), table.end(), freq.begin());
//    std::sort(freq.begin(), freq.end(), sortByFreq);
//
//    
//    /* ************** Testing **************** */
//
//    test(table, freq, name, counter);
//
//}
///*******************************
// * 2. Test implementation      *
// * Do not modify               *
// *******************************/
//
//void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
//          const std::string& file_name, int n) {
//
//    std::ifstream file{"../code/out_" + file_name};
//
//    // Test if stream is in good state
//    assert(bool(file) == true);
//
//    std::map<std::string, int> result1;
//    std::string word;
//    int counter{0};
//    int total{0};
//
//    // load expected frequency table sorted alphabetically
//    while (file >> word >> counter && counter > 0) {
//        result1[word] = counter;
//        total += counter;
//    }
//
//    assert(total == n);  // test if total number of words is correct
//    assert(t == result1);
//
//    std::vector<std::pair<std::string, int>> result2;
//
//    // load expected frequency table sorted by frequence
//    while (file >> word >> counter) {
//        result2.push_back(std::pair{word, counter});
//    }
//
//    assert(v == result2);
//
//    std::cout << "\nPassed all tests successfully!!\n";
//}

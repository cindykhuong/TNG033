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
////dont have to write std::pair
//using pair = std::pair<std::string, int>;
//
//// A function to test the tables created by the program
//void test(const std::map<std::string, int>& theMap, const std::vector<std::pair<std::string, int>>& vecFreq,
//          const std::string& file_name, int counter);
//
//// Should only contain lower-case letters and digits
//// using transform()function and ::tolower in Standard template library
//void lowerCase(std::string& word){
//    transform(word.begin(), word.end(), word.begin(), ::tolower); //::tolower convert uppercase letter to lowercase
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
////sorting the freq (vector)
//bool sortByFreq (const pair &a, const pair &b) {
//    if(a.second==b.second){
//        return (a.first < b.first); //sorting it
//    }
//    return(a.second > b.second);
//}
//
///*******************************
// * 2. Main function             *
// *******************************/
//
//int main() {
//    std::string name;
//    std::string word;
//
//    //User enters filename
//    std::cout << "Text file: ";
//    std::cin >> name;
//
//    std::ifstream in_File{"/Users/cindykhuong/Documents/TNG033/lab3/" + name};
//
//    if (!in_File) {
//        std::cout << "Could not open input file!!\n";
//        return 0;
//    }
//
//    std::map<std::string, int> table; //create a map called table which takes in an int & string
//    int counter{0};  // to count total number of words read from the input file
//
//    //ADD CODE to build table
//
//    while (in_File >> word) {            //read word for file
//        word = removeChar(word);         //remove special char (e.g. .,!?:\"();)
//        lowerCase(word);                 //change all words in the input file to lower-case letters
//        auto it = table.find(word);      //find the word in the map called table
//
//        if (it != table.end()) {         //if it is not at the end of the table
//            table[word]++;               //increment to the next position
//        }
//
//        else {
//            table.insert({ word, 1 });   //if it is at the end of the table add the word and number 1
//        }
//        counter++;                       //increment (the total of words in the file)
//    }
//
//    //ADD CODE to build vector freq
//
//    std::vector<pair> freq(table.size());   //create a vector of pairs called freq
//
//    //Copy all pairings of word and frequency from the map created in the point above into a
//    //std::vector (name the vector variable as freq)
//    std::copy(table.begin(), table.end(), freq.begin());
//
//    // sort the vector decreasingly by the words’ frequency.
//    std::sort(freq.begin(), freq.end(), sortByFreq);
//
//
//    /* ************** Testing **************** */
//
//    test(table, freq, name, counter); //call the test function
//
//}
///*******************************
// * 2. Test implementation      *
// * Do not modify               *
// *******************************/
//
//void test(const std::map<std::string, int>& theMap, const std::vector<std::pair<std::string, int>>& vecFreq,
//          const std::string& file_name, int number) {
//
//    std::ifstream file{"/Users/cindykhuong/Documents/TNG033/lab3/out_" + file_name};
//
//    // Test if stream is in good state
//    assert(bool(file) == true);
//
//    std::map<std::string, int> result1; //create new map
//    std::string word;
//
//    int counter{0};
//    int total{0};
//
//    // load expected frequency table sorted alphabetically
//    while (file >> word >> counter && counter > 0) {
//        result1[word] = counter;
//        total += counter; //total = total + counter
//    }
//
//    assert(total == number);  // test if total number of words is correct
//    assert(theMap == result1);
//
//    std::vector<std::pair<std::string, int>> result2;
//
//     //load expected frequency table sorted by frequence
//    while (file >> word >> counter) {
//        result2.push_back(pair{word, counter});
//    }
//
//    assert(vecFreq == result2);
//
//    std::cout << "\nPassed all tests successfully!!\n";
//}

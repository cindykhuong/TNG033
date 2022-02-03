#include <iostream>
#include <map>          //std::map
#include <string>       //std::string
#include <fstream>      //std::ifstream
#include <algorithm>    //std::for_each, std::transform, std::copy
#include <utility>      //std::setw()
#include <vector>       //std::vector
#include <iterator>
#include <set>
#include <iomanip>
#include <cassert>

//dont have to write std::pair
using pair_ = std::pair<std::string, std::set<std::string>>;
using map_ = std::map<std::string, std::set<std::string>>;

//A function to test the tables created by the program
void test(const std::map<std::string, std::set<std::string>>& testmap, const std::string& file_name);

int main() {

    std::string name;

    //user enter the text file
    std::cout << "Text file: ";
    std::cin >> name;

    std::ifstream in_File{"/Users/cindykhuong/Documents/TNG033/lab3/" + name};

    if (!in_File) { //if in_File is not found
        std::cout << "Could not open input file!!\n";
        return 0;
    }

    //auto keyword is simply asking the compiler to deduce the type of the variable from the initialization.
    //An iterator is any object that, pointing to some element in a range of elements (such as an array or a container), has the ability to iterate through the elements
    auto input = std::istream_iterator<std::string>(in_File);
    auto inputEnd = std::istream_iterator<std::string>();

    //Store the list of anagrams for every subject. input med ursprungliga ordet, inputEnd the different anagrams for each subject
    auto all_words = std::vector<std::string>(input, inputEnd);

    in_File.close(); //Close the file

    //Create an empty container called myMap
    auto myMap = map_();

    //STL algorithm that takes a collection of elements (in the form of a begin and end iterator) and a function (or function object), and applies the function on each element of the collection.
    std::for_each(all_words.begin(), all_words.end(), [&myMap](const std::string& word) { //myMap a function

        std::string copy = word;                //because it is a const
        std::sort(copy.begin(), copy.end());    //sort copy alphabetically
        myMap[copy].insert(word);               //myMap store in copy and insert the word into our myMap
    });

    //Display
    //each subject should then be written to an output stream
    std::for_each(myMap.begin(), myMap.end(), [] (const pair_& myPair) { //function myPair, kinda a loop

        //if-stat?
        if(myPair.second.size() > 1) { //if the word contains more than 1 anagram

            std::cout << std::setw(10) << myPair.first << std::setw(10) << " - "; //display the alphabetically sorted word (subject)

            std::for_each(myPair.second.begin(), myPair.second.end(), [](const std::string& anagram) { //function anagram
                std::cout << anagram << " "; //display the anagram
            });
    }

        //cases of subjects with two or more anagram words should be written to the output stream
        if (myPair.second.size() > 1) { //display the arrows, if its more than 1 word
            std::cout << std::setw(5) << " --> " << std::setw(2) << myPair.second.size() << " words." << std::endl;
        }
     /*   else {
            std::cout << std::endl;
        }*/
    });

    std::cout << "\nTotal number of words in the file: " << all_words.size() << "\n\n";
    test(myMap, name); //call the function test
}

/******************************
// * 2. Test implementation   *
//
// ****************************/

void test(const std::map<std::string, std::set<std::string>>& testmap,
    const std::string& file_name){

    std::ifstream outfile{"/Users/cindykhuong/Documents/TNG033/lab3/out_" + file_name};

    // Test if stream is in good state
    assert(bool(outfile) == true);
    std::cout << "The file is in good state.\n";
    std::cout << "Testing the maps...\n";

    //Create an empty container called myMapnew
    auto myMapnew = map_();

    //auto keyword is simply asking the compiler to deduce the type of the variable from the initialization.
    //An iterator is any object that, pointing to some element in a range of elements (such as an array or a container), has the ability to iterate through the elements
    auto output = std::istream_iterator<std::string>(outfile);
    auto outputEnd = std::istream_iterator<std::string>();

    //Store the list of anagrams for every subject. input med ursprungliga ordet, inputEnd the different anagrams for each subject
    auto all_words_new = std::vector<std::string>(output, outputEnd);

    outfile.close(); //Close the file

    //store it in myMapnew
    std::for_each(all_words_new.begin(), all_words_new.end(), [&myMapnew](const std::string& word) {

        std::string copy = word; //beacuse it is a const
        std::sort(copy.begin(), copy.end()); //sort the word in alphabetically, cindy, cdiny

        myMapnew[copy].insert(word); //cdiny, cindy

    });

    // check whether the testmap created in a) has the correct contents as the one we created called myMapnew
    assert(myMapnew == testmap);

    std::cout << "\nPassed all tests successfully!!\n";
}







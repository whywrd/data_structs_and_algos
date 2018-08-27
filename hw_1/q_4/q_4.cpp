/*
CS 110c 
Homework 1
Question 4

Using the standard library and STL, write functions to print the unique
letters in a string and determine if a string is a pangram. A pangram is
a sentence that uses every letter in an alphabet (english in this case)
*/

#include <iostream>
#include <cstring>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

// prototypes
bool isPangram(const char string[]);
void printUniqueLetters(const char string[]);
set<char> stringToAlphaSet(const char string[]);
set<char> alphabetSet();


int main() {
    
    // print unique letters
    cout << "the unique letters in \"aaaaaaaAAA\" are: ";
    printUniqueLetters("aaaaaaaAAA");
    cout << endl << endl;

    // testing for pangrams
    char notPangram[] = "this is obviously not a pangram!";
    char pangram[] = "Jived fox nymph grabs quick waltz.";
    cout << "testing pangrams: " << endl;
    cout << "should be 0: " << isPangram(notPangram) << endl;
    cout << "should be 1: " << isPangram(pangram) << endl;
    return 0;
}






/*
stringToAlphaSet
Given a cString return a  char set containing the lowercased alphabet characters
in of the cString.
*/

set<char> stringToAlphaSet(const char string[]) {
    set<char> charSet;
    for(int i = 0; i < strlen(string); i++){
        if(isalpha(string[i])) {
            charSet.insert(tolower(string[i]));
        }
    }
    return charSet;
}







/*
printUniqueLetters
Given a cString print the unique characters in it. First convert it to a set
and then print the elements of the set.
*/

void printUniqueLetters(const char string[]) {
    set<char> charSet = stringToAlphaSet(string);
    for(set<char>::const_iterator iter = charSet.begin(), end = charSet.end(); 
        iter != end; iter++) {
            cout << (*iter);
    }
}






/*
isPangram
return whether or not the elements in a given string contains every letter in
the english alphabet.
*/

bool isPangram(const char string[]) {
    static set<char> alphabet = alphabetSet();
    set<char> stringSet = stringToAlphaSet(string);
    set<char> result;
    set_difference(alphabet.begin(), alphabet.end(), stringSet.begin(), 
                   stringSet.end(), inserter(result, result.end()));
    return result.empty();
}






/*
alphabetSet
return a set containing all the letters in the alphabet
*/

set<char> alphabetSet() {
    set<char> alphabet;
    for(char letter = 'a'; letter <= 'z'; letter++) {
        alphabet.insert(letter);
    }
    return alphabet;
}






/*
output:

the unique letters in "aaaaaaaAAA" are: a

testing pangrams: 
should be 0: 0
should be 1: 1
*/
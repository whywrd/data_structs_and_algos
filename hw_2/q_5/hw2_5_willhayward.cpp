/*
CS110C Homework 2 Question 5
Will Hayward
October 1, 2017

Write recursive function named 'isPalindrome' that takes a string as
input and returns true if the string is a palindrome and false if it is not
a palindrome. 

Examples: isPalindrome("madam") -> true
*/

#include <cstring>
#include <iostream>


bool isPalindrome(const char* const);


int main() {
    std::cout << "testing palindromes" << std::endl;
    std::cout << "madam: " << isPalindrome("madam") << std::endl;
    std::cout << "firefighter: " << isPalindrome("firefighter") << std::endl;
    std::cout << "racecar: " << isPalindrome("racecar") << std::endl;
}






/*
isPalindrome
return true or false depending on whether or not the cString is a palindrome. 
This function operates recursively. Test whether two characters (lowercased)
symmetrically oriented around the midpoint of the cString are the same. Base
case is that the cString is less than 2 characters long

if you want it to work irrespective of punctuation and capitalization, clean
the cString before analyzing.
*/

bool isPalindrome(const char* const string) {
    bool result = true;
    int size = strlen(string); // number of chars excluding null term
    if(size > 2) {
        char substr[size-1]; // remove 2 chars but want null term => -1
        strncpy(substr, &string[1], size-2);
        substr[size-2] = '\0'; // strcpy does not null terminate
        result = isPalindrome(substr);
    }
    return result & (string[0] == string[size-1]);
}

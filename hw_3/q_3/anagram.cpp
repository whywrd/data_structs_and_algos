#include <string>
#include <iostream>

bool isAnagram(const std::string&, std::string);


int main() {
    std::cout << isAnagram("bad credit", "debit card") << std::endl;
    std::cout << isAnagram("test failure", "returns false") << std::endl;
}






/*
isAnagram
return wether or not the two strings are an anagram pair. Assume that all characters
have to be represented in each string the same number of times. No care is taken for
character case and non alpha numeric characters.

Go through each character in string1 and search for it in string2. If there is a match
null out the character in string2 so that it cannot be matched against again. If all of
the characters in string1 are found in string 2 without replacement and the two strings
are the same length then they are anagrams. Otherwise, they are not.
*/

bool isAnagram(const std::string &string1, std::string string2) {
    
    if(string1.length() != string2.length()) {
        return false;
    }

    for(int i = 0; i < string1.length(); i++) {
        
        bool found = false;
        for(int j = 0; !found && j < string1.length(); j++) {
            if(tolower(string1[i]) == tolower(string2[j])) {
                found = true;
                string2[j] = NULL;
            }
        }

        if(!found) {
            return false;
        }
    }

    return true;
}







/*
OUTPUT

1
0
*/
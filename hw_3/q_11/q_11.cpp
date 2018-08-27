/*
1. The best, average and worst case scenarios for two words with different sizes are
all the same. This is because the two words are first checked to make sure they are the
same length. If they are not the algorithm returns false without any further computation.

2. The best, average and worst case scenarios all have a run time of O(1) because string
stores the length as a field.

3. If the words are the same size then the process of checking the two words begins. 

Best case: the first character of string1 is not in string2. In this case the outerloop 
will terminate after 1 iteration.

Worst case: the two strings are anagrams. In this case the outerloop will execute n times.

Ave case: assume characters are uniformly distributed. the probability that a char
is in a word of length n is (1-(25/26)^n)

4.
Best case: O(n) because the inner loop still iterates over all n characters
Worst case: O(n^2) becaues the outerloop iterates over all n characters and the inner
loop iterates over n/2 characters on average
Ave case: expect n/2 * (1-a^n) where a = 25/26. there O(n(1-a^n))

5. without considering the time complexity of creating the maps:
best case: the two strings have different lengths.
worst case: the two strings are the same.

6.
best case: O(1)
worst case: operator[] is log(n) therefore O(nlog(n))
*/

#include <map>
#include <string>
#include <iostream>

using namespace std;


bool isAnagram(const string&, const string&);
map<char, int> charMap(const string&);



int main() {
    std::cout << isAnagram("bad credit", "debit card") << std::endl;
    std::cout << isAnagram("test failure", "returns false") << std::endl;
    return 0;
}





/*
isAnagram
return wether or not the two words are anagrams
*/

bool isAnagram(const string &str1, const string &str2) {
    map<char, int> cMap1, cMap2;

    if(str1.size() != str2.size()) {
        return false;
    }

    cMap1 = charMap(str1); 
    cMap2 = charMap(str2);
    
    for(std::map<char,int>::iterator it=cMap1.begin(); it!=cMap1.end(); it++) {
        if(it->second != cMap2[it->first]) {
            return false;
        }
    }

    return true;
}





/*
charMap
given a string return a map where the keys are the characters and the
values are the counts of the character in the strin
*/

map<char, int> charMap(const string &str) {
    map<char, int> cMap;
    for(int i=0; i < str.length(); i++) {
        cMap[str[i]]++;
    }
    return cMap;
}






/*
OUTPUT

1
0
*/
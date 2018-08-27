/*
CS110C Homework 2 Question 8
Will Hayward
October 1, 2017

Write a C++ recursive function to check whether a given integer is prime or not. 
*/

#include <iostream>

bool isPrime(int);
bool isPrime(int, int);


int main() {
    std::cout << "testing prime numbers" << std::endl;
    int toTest[7] = {2, 13, 113, 117, 200, 2221, 93};
    for(int i=0; i<7; i++) {
        std::cout << toTest[i] << ": " << isPrime(toTest[i]) << std::endl;
    }
}






/*
isPrime
Given a positive integer return whether or not it is prime

This function kicks off a recursive call to isPrime(int, int) using x/2 as the 
starting point.
*/

bool isPrime(int x) {
    return isPrime(x, x/2);
}






/*
isPrime
Recursive prime function. Given the prime number to check and a second number
see if any number less than the second number evenly divides the suspect prime
number. 

First base case, the second number divides the subject number; therefore, the
subject number is not prime. Second base case, the second number reaches 1;
therefore, the subject number is prime.
*/

bool isPrime(int x, int divisor) {
    if(divisor == 1) {
        return true;
    } else if(x % divisor == 0) {
        return false;
    } else {
        return isPrime(x, divisor - 1);
    }
}






/*
output:

testing prime numbers
2: 1
13: 1
113: 1
117: 0
200: 0
2221: 1
93: 0
*/
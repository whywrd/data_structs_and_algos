/*
CS110C Homework 2 Question 7
Will Hayward
October 1, 2017

Write a recursive C++ method, powOfn() to calculate the n th power of a 
given number, m. n is an integer and m is a double value. 
*/

#include <iostream>
#include <cstdlib> // abs()

double powOfn(double, int);


int main() {
    std::cout << "testing powOfn" << std::endl;
    std::cout << "powOfn(3.0, 3): " << powOfn(3.0, 3) << std::endl;
    std::cout << "powOfn(2.0, 4): " << powOfn(2.0, 4) << std::endl;
    std::cout << "powOfn(72.0, 0): " << powOfn(72.0, 0) << std::endl;
}






/*
powOfn
recursive function to determine the nth power of m, where n is a positive 
integer and m is a double.

Base Case: n == 0 return 1
Simplifying Case: return m * powOfn(m, n-1).
*/

double powOfn(double m, int n) {
    if(n == 0) {
        return 1;
    } else {
        return m * powOfn(m, n - 1);
    }
}
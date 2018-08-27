/*
CS110C Homework 2 Question 6
Will Hayward
October 1, 2017

Write a recursive algorithm for determining the lowest common divisor of
two integers
*/

#include <iostream>


int GCD(int, int);

int main() {
    std::cout << (GCD(18, 24) == 6) << std::endl;
    std::cout << (GCD(42, 35) == 7) << std::endl;
}






/*
GCD
given two integers return their greatest common divisor ie the largest
number that divides them with remainder 0.

by euclids algorithm:
GCD(A,0) = A
GCD(0,B) = B
If A = B⋅Q + R and B≠0 then GCD(A,B) = GCD(B,R)

Therefore the base case is B == 0 and in the other cases, the problem
can be simplified as GCD(A, A%B). Note if B > A, then GCD(B, A % B) == GCD(B, A)
therefore, you can garauntee x is greater than y after the first recursion.
*/

int GCD(int x, int y) {
    if(y == 0) {
        return x;
    } else {
        return GCD(y, x % y);
    }
}
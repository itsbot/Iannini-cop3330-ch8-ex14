/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Patrick Iannini
 */

/*
Can we declare a non-reference function argument const (e.g., void f(const int);)? 
What might that mean? Why might we want to do that? Why don’t people do that often? 
Try it; write a couple of small programs to see what works.
*/

/* Answer:
Yes it can be done, we can do this to use an unmodifiable object in a function.
This isn't done often because there are other methods to get the same results such as pointers.
If we want to modify then we just point to the original value and use it in our function.
If we want it to be unmodifiable then we can just use the address of the origional.  
*/

#include <iostream>

int f1(int a, int b) {
    return a+b;
}
int f2(const int a, const int b, const int c) {
    return a+c/b;
}
int f3(int a, const int b) {
    a = a+1;
    // b = b+1; doesnt work
    return a+b;
}
int f4(const int *a, const int &b) {
    a = a+1;
    // b = b*b; doesnt work
    return *a+b;
}

int main() {
    int a = 1;
    int b = 2;
    int c = 3;

    std::cout << "\na+b = " << f1(a ,b);
    std::cout << "\na+c/b = " << f2(a, b, c);
    std::cout << "\na+b = " << f3(a ,b);
    std::cout << "\n*a+b = " << f4(&a ,b);

    return 0;
}
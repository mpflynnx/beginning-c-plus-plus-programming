// Section 11
// Recursion - Factorial

#include <iostream>

unsigned long long factorial(unsigned long long);

unsigned long long factorial(unsigned long long n) {
    if (n == 0)
        return 1;	             // base case, must exist to stop infinite recursion
    return n * factorial(n - 1); // recursive case
}

int main() {
    //std::cout << factorial(3) << std::endl;       // 6
    //    std::cout << factorial(8) << std::endl;     // 40320
    //    std::cout << factorial(12) << std::endl;   // 479001600
    std::cout << factorial(20) << std::endl;   // 2432902008176640000
    return 0;
}
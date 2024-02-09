// Section 11
// Recursion - Fibonacci

#include <iostream>

unsigned long long fibonacci(unsigned long long n);

unsigned long long fibonacci(unsigned long long n) {
    if (n <= 1)
        return n;	             // base case must exit to terminate recursion
    return fibonacci(n - 1) + fibonacci(n - 2); // recursion
}

int main() {
    std::cout << fibonacci(5) << std::endl;   // 5
    //std::cout << fibonacci(30) << std::endl;	// 832040 
    //std::cout << fibonacci(40) << std::endl; // 102334155
    return 0;
}
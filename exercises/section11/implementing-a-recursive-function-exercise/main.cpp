#include <iostream>
#include <cmath>

int sum_of_digits(int n);
int sum_of_digitsR(int n);
int sum_of_digitsI(int n);

int main()
{

    // non recursive function calls
    //std::cout << sum_of_digits(1234); // 10
    //std::cout << sum_of_digits(5678); // 26
    //std::cout << sum_of_digits(9999); // 36
    //std::cout << sum_of_digits(1000); // 1

    // my recursive function calls test cases
    // works one at a time but not all together, die to static int variable in function, not resetting
    //std::cout << sum_of_digitsR(1234) << '\n'; // 10
    //std::cout << sum_of_digitsR(5678) << '\n'; // 26
    //std::cout << sum_of_digitsR(9999) << '\n'; // 36
    //std::cout << sum_of_digitsR(1000) << '\n'; // 1
    //std::cout << sum_of_digitsR(5555) << '\n'; // 20
    //std::cout << sum_of_digitsR(1234567890) << '\n'; // 45
    //std::cout << sum_of_digitsR(1111111111) << '\n'; // 10

    // instructors version recursive function calls
    std::cout << sum_of_digitsI(1234) << '\n'; // 10
    //std::cout << sum_of_digitsI(5678) << '\n'; // 26
    //std::cout << sum_of_digitsI(9999) << '\n'; // 36
    //std::cout << sum_of_digitsI(1000) << '\n'; // 1
    //std::cout << sum_of_digitsI(5555) << '\n'; // 20
    //std::cout << sum_of_digitsI(1234567890) << '\n'; // 45
    //std::cout << sum_of_digitsI(1111111111) << '\n'; // 10

    return 0;
 }

int sum_of_digits(int n) {

    int sum{0};

     while (n > 0) {
         int digit{ n % 10 }; // Extract the rightmost digit
        sum += digit;
        n /= 10; // Remove the rightmost digit
    }
    return sum;
}

// My recursive version, static int sum is never cleared after the function exits
 int sum_of_digitsR(int n) {

    
    static int sum{ 0 }; // static to save value for recusive function call

    if (n == 0) {    // base case to halt recursion
        return sum;
    }

    int digit{ n % 10 }; // Extract the rightmost digit
    sum += digit;
    n /= 10; // Remove the rightmost digit

    return sum_of_digitsR(n);
}

// Instructors version works in udemy.com ide my version doesn't?
int sum_of_digitsI(int n) {
    if (n == 0)
        return 0;
    return (n % 10 + sum_of_digitsI(n / 10));
}
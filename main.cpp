#include <iostream>

int main()
{
    int number {0};
    std::cout << "Enter an integer less than 100: ";
    std::cin >> number;

    while (number >= 100){
        std::cout << "Enter an integer less than 100: ";
        std::cin >> number;
    }

    std::cout << "Thanks, " << number << " is a good number.";
    
    return 0;
}

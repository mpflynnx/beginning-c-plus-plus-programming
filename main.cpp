#include <iostream>

int main()
{

    int x {};
    std::cout << "Size of integer storage: " << sizeof x << '\n' << '\n'; // 4bytes

    int scores[] {100, 95, 89};
    std::cout << "Value of array name: " << scores << '\n'; // array name value is memory address

    int* score_ptr{scores}; // no need for & address-of operator as scores decays to address
    std::cout << "Value of pointer: " << score_ptr << '\n';

    std::cout << "\nArray offset notation -----------------\n";
    std::cout << "First element address: " << scores << '\n';
    std::cout << "First element of array: " << *scores << '\n'; // equivalent to scores + 0
    std::cout << "Second element address: " << scores + 1  << '\n'; // equivalent to scores + 4bytes(size of int) + 4bytes(size of int)
    std::cout << "Second element of array: " << *(scores + 1) << '\n'; // equivalent to scores + 4bytes(size of int)
    std::cout << "Third element address: " << scores + 2 << '\n'; // equivalent to scores + 4bytes(size of int) + 4bytes(size of int)
    std::cout << "Third element of array: " << *(scores + 2) << '\n'; // equivalent to scores + 4bytes(size of int) + 4bytes(size of int)

    std::cout << "\nPointer offset notation -----------------\n";
    std::cout << "First element address: " << score_ptr << '\n';
    std::cout << "First element of array: " << *score_ptr << '\n'; // equivalent to score_ptr + 0
    std::cout << "Second element address: " << (score_ptr + 1) << '\n'; // equivalent to score_ptr + 4bytes(size of int) + 4bytes(size of int)
    std::cout << "Second element of array: " << *(score_ptr + 1) << '\n'; // equivalent to score_ptr + 4bytes(size of int)
    std::cout << "Third element address: " << (score_ptr + 2) << '\n'; // equivalent to score_ptr + 4bytes(size of int) + 4bytes(size of int)
    std::cout << "Third element of array: " << *(score_ptr + 2) << '\n'; // equivalent to score_ptr + 4bytes(size of int) + 4bytes(size of int)
    
    return 0;
}
#include <iostream>


int main() {
    const size_t array1_size{ 5 };
    const size_t array2_size{ 3 };

    int array1[]{ 1,2,3,4,5 };
    int array2[]{ 10,20,30 };

    std::cout << "Array 1: ";
    print(array1, array1_size);

    std::cout << "Array 2: ";
    print(array2, array2_size);

    int* results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size{ array1_size * array2_size };

    std::cout << "Result: ";
    print(results, results_size);

    std::cout << std::endl;

    return 0;
}
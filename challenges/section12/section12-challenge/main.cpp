#include <iostream>

int* apply_all(int* arr1, size_t arr1_size, int* arr2, size_t arr2_size);
void print(const int* arr, size_t size);


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

int* apply_all(int* arr1, size_t arr1_size, int* arr2, size_t arr2_size) {

    std::cout << "\n// apply_all function debugging\n";
    size_t size{ arr1_size * arr2_size };

    int* new_storage{ nullptr };
    new_storage = new int[size];

    std::cout << "new_storage created @ " << new_storage << '\n';

    int i{0};

    // see garbage at new_storage memory location
    std::cout << "mem: " << (new_storage + i) << " | " << *(new_storage + i) << '\n';

    std::cout << "Start writing to new storage\n";
    while (i < size) {

        for (size_t j{ 0 }; j < arr2_size; ++j) {
            for (size_t k{ 0 }; k < arr1_size; ++k) {
                *(new_storage + i) = arr2[j] * arr1[k];
                std::cout << "mem: " << (new_storage + i) << " | " << *(new_storage + i) << '\n';
                i++;
            }

        }
    }
    std::cout << "// Stopped writing to new storage\n\n";

    return new_storage;
}

void print(const int* arr, const size_t size) {
    std::cout << "[";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << ' ' << arr[i];
    }
    std::cout << " ] \n";
}
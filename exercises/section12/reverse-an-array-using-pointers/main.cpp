#include <iostream>

void display(const int* const array, size_t size);

void reverse_array(int* arr, int size);

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    reverse_array(arr, size);

    // After the function call, the array should be reversed:
    // arr[] = {5, 4, 3, 2, 1}

    display(arr, size);

    return 0;
  }

/*
Best practice:
A function parameter expecting a C-style array type should use the array syntax (e.g. int arr[]) 
rather than pointer syntax (e.g. int *arr).
https://www.learncpp.com/cpp-tutorial/c-style-array-decay/

C-style arrays should be avoided in most cases
https://www.learncpp.com/cpp-tutorial/c-style-array-decay/

*/
void reverse_array(int* arr, int size) {

    int temp{};

    for (int i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1]; // left hand side
        arr[size - i - 1] = temp; // right hand side
    }

}

void display(const int* const array, size_t size) {
    for (size_t i{ 0 }; i < size; ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';
}


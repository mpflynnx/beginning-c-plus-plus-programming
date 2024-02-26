#include <iostream>
#include <climits> // for INT_MIN

int findMaxElement(int* arr, int size);

int main()
{
    int arr[] = { -5, -12, -3, -8, -1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxElement = findMaxElement(arr, size);

    std::cout << maxElement << '\n';
    // maxElement should be 67

    return 0;
}

int findMaxElement(int* arr, int size) {
    int max{ INT_MIN }; // minimum integer possible
    for (size_t i{ 0 }; i < size; ++i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
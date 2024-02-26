## Solution

```c
int find_max_element(int* arr, int size) {
    int maxElement = *arr;  // Initialize maxElement with the first element

    for (int i = 1; i < size; i++) {
        if (*(arr + i) > maxElement) {
            maxElement = *(arr + i);  // Update maxElement if a larger element is found
        }
    }

    return maxElement;
}
```
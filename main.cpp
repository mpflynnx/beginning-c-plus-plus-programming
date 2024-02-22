#include <iostream>
#include <vector>
#include <string>

int* largest_int(int* int_ptr1, int* int_ptr2);

int main() {

    int int1 {99};
    int int2 {345};

    std::cout << "Largest int value: " << *(largest_int(&int1, &int2));

}

int* largest_int(int* int_ptr1, int* int_ptr2){
    if (*int_ptr1 > *int_ptr2)
        return int_ptr1;
    else
        return int_ptr2;
}
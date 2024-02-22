#include <iostream>

int* create_array(size_t size, int init_value = 0);

int main() {

    int* my_array; // int pointer to array first element
    my_array = create_array(10,99); // function returns address to pointer

    // use the array

    delete[] my_array; // free storage when done with array
}

int* create_array(size_t size, int init_value) {
   int* new_storage {nullptr};
   new_storage = new int[size];   
   for (size_t i{0}; i < size; ++i)
      *(new_storage + i) = init_value;
   return new_storage;
}
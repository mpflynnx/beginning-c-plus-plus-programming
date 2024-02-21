#include <iostream>

int main()
{
    int x {123};
    int y {123};
    int z {789};

    int* x_ptr { &x };
    int* y_ptr { &y };
    int* z_ptr { &z }; 

    std::cout << z_ptr << '\n';

    std::cout << (*x_ptr == *y_ptr) << '\n'; // true both 123
    std::cout << (x_ptr == y_ptr) << '\n'; // false different addresses
    std::cout << (*x_ptr != *z_ptr) << '\n'; // true as z = 789

    std::cout << (z_ptr++) << '\n';
    std::cout << (*z_ptr) << '\n';
    return 0;
}
#include <iostream>

int main()
{

    int highest {180};
    int lowest {1};

    const int *const score_ptr { &highest };

    *score_ptr = 86; // Error
    score_ptr = &lowest; // Error 

    return 0;
}
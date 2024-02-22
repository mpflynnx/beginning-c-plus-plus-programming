#include <iostream>

void swapPointers(int* ptr1, int* ptr2);
void swapPointersNoTemp(int* ptr1, int* ptr2);

int main()
{
    int a{ 5 };
    int b{ 10 };

    int* ptrA{ &a };
    int* ptrB{ &b };

    /*
    * select only one function below
    */
    //swapPointers(ptrA, ptrB);
    swapPointersNoTemp(ptrA, ptrB);

    std::cout << "\n------ After function call ------\n";
    std::cout << "a: " << *ptrA << '\n';
    std::cout << "b: " << *ptrB << '\n';

    return 0;
}

/*
* swaps pointers using a temp variable
*/
void swapPointers(int* ptr1, int* ptr2) {

    int temp{};

    std::cout << "------- starting values ---------\n";
    std::cout << "ptr1 @ " << ptr1 << " = " << *ptr1 << '\n';
    std::cout << "ptr2 @ " << ptr2 << " = " << *ptr2 << '\n';
    std::cout << "temp @ " << &temp << " = " << temp << '\n';

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

}

/*
* swaps pointers using no temp variable
*/
void swapPointersNoTemp(int* ptr1, int* ptr2) {

    std::cout << "------- starting values ---------\n";
    std::cout << "ptr1 @ " << ptr1 << " = " << *ptr1 << '\n';
    std::cout << "ptr2 @ " << ptr2 << " = " << *ptr2 << '\n';

    std::cout << "\n------- *ptr1 = *ptr1 + *ptr2 ---------\n";
    *ptr1 = *ptr1 + *ptr2; // 5 + 10 = 15
    std::cout << "ptr1 @ " << ptr1 << " = " << *ptr1 << '\n';

    std::cout << "\n------- *ptr2 = *ptr1 - *ptr2 ---------\n";
    *ptr2 = *ptr1 - *ptr2; // 15 - 10 = 5
    std::cout << "ptr2 @ " << ptr2 << " = " << *ptr2 << '\n';
    
    std::cout << "\n------- *ptr1 = *ptr1 - *ptr2 ---------\n";
    *ptr1 = *ptr1 - *ptr2; // 15 - 5 = 10
    std::cout << "ptr1 @ " << ptr1 << " = " << *ptr1 << '\n';

}

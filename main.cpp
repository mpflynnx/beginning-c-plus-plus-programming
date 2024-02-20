#include <iostream>
#include <vector>

int main()
{

    std::vector <int> test_scores {100, 98, 89, 85, 93};
    std::vector <int> *pVec{&test_scores};

    std::cout << "Value of pVec is: "<< pVec << '\n';
    std::cout << "Address of test_scores is: " << &test_scores << '\n';
    std::cout << "Address of pVec is: " << &pVec << '\n';
    std::cout << "size of test_scores (bytes) is: " << sizeof test_scores << '\n';

    return 0;
}
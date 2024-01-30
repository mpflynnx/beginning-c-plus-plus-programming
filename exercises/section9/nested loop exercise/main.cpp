#include <iostream>
#include <vector>

int main()
{

    // Test cases
    //std::vector<int> vec{ 1,2,3 };
    //std::vector<int> vec{ 2,4,6,8 };
    //std::vector<int> vec{ 1 };
    //std::vector<int> vec{};
    std::vector<int> vec{ 2, 2, 3, 2 };

    size_t vec_size{ vec.size() };
    int result{};

    if (vec_size >= 2) { // Vector must be equal or greater than 2
        for (unsigned i{ 0 }; i < vec_size; ++i) {

            for (unsigned j{ 0 }; j < vec_size; ++j) {

                if (i == j || j <= i) {
                    std::cout << "continued" << '\n';
                    continue;
                }

                int product{};
                product = vec[i] * vec[j];
                std::cout << "product: " << vec[i] << " * " << vec[j] << " = " << product << '\n';

                result += product;
            }
        }
    } else {
        result = 0;
    }

    std::cout << "result: " << result << '\n';

    return 0;
}


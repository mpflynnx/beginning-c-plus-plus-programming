#include <iostream>
#include <vector>

int main()
{

    // Test cases
    std::vector<int> vec{ 1,2,3 };
    //std::vector<int> vec{ 2,4,6 };
    //std::vector<int> vec{ 1 };
    //std::vector<int> vec{};

    int result{};
    size_t index{ 0 };

    if (vec.size() >= 2) {
        //0 * 1 or 1 * 2
        //0 * 2 or 1 * 3
        //0 * 3 or 2 * 3
        for (auto val: vec) {
            for (int i{ 0 }; i<=vec.size(); ++i) {
                for (int j{ 0 }; j <= vec.size(); ++i) {
            }
        }

    }
    else {
        result = 0;
    }

    return 0;
}


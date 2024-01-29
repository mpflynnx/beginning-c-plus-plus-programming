#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec{ 1,2,3,-99,4,5,6 };

    int count{ 0 };
    size_t index{ 0 };

    while (index < vec.size() && vec.at(index) != -99) {
        ++count;
        ++index;
    }

    std::cout << count << " elements in the vector before -99.";

    return 0;
}

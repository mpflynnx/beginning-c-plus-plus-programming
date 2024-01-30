#include <iostream>
#include <vector>

int main()
{

    // Test conditions
    std::vector <char> vec{'f', 'r', 'a', 'n', 'k'};
    //std::vector <char> vec{'F', 'R', 'A', 'N', 'K'};
    //std::vector <char> vec{'h', 'e', 'l', 'l', 'o'};
    //std::vector <char> vec{};
    //std::vector <char> vec{'x', 'y', 'z', 'o'};

    int count{ 0 };
    size_t index{ 0 };

    if (vec.size() != 0) { // Check vector isn't empty first

        do {

            switch (vec.at(index))
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                std::cout << "Vowel found: " << vec.at(index);
                ++count; // Set condition for not outputting the "No vowel was found message"
                index = vec.size(); // Force loop termination
                break;
            default:
                break;
            }

            ++index; // Move on to next vector index

        } while (index < vec.size());

        if (!count)
            std::cout << "No vowel was found";

    }
    else { // Condition if vector is empty.

        std::cout << "No vowel was found";
    }

    return 0;
}


#include <iostream>
#include <vector>

void print_numbers(const std::vector<int>& arr) {


    if (arr.size() == 0)
        std::cout << "\n[] - the list is empty\n";
    else {
        std::cout << "\n[";
        for (auto num : arr)
            std::cout << ' ' << num << ' ';
        std::cout << "]\n";
    }

}

void add_number(std::vector<int>& arr) {

    std::cout << "\nEnter an integer to add: ";
    int num{};
    std::cin >> num;
    arr.push_back(num);
    std::cout << '\n' << num << " added\n";

}

void display_mean(const std::vector<int>& arr) {

    double result{};

    if (arr.size() < 2)
        std::cout << "\nUnable to calculate the mean - no data\n";
    else {
        for (auto num : arr)
            result += num;
        std::cout << '\n' << result / arr.size() << '\n';
            
    }

}

void display_smallest(const std::vector<int>& arr) {

    if (arr.size() == 0)
        std::cout << "\nUnable to determine the smallest number - list is empty\n";
    else {
        std::cout << "\n[";
        for (auto num : arr)
            std::cout << ' ' << num << ' ';
        std::cout << "]\n";
    }


}

void display_largest(const std::vector<int>& arr) {

    if (arr.size() == 0)
        std::cout << "\nUnable to determine the largest number - list is empty\n";
    else {
        std::cout << "\n[";
        for (auto num : arr)
            std::cout << ' ' << num << ' ';
        std::cout << "]\n";
    }

}

void display_quitting() {
    std::cout << "\nGoodbye\n";
}

void display_illegal() {
    std::cout << "\nUnknown selection, please try again\n";
}

int main()
{

    std::vector<int> vec{};

    //std::vector<int> vec{1,2,3,4};

    char selection{};

    do {
        std::cout << '\n';
        std::cout << "P - Print numbers" << '\n';
        std::cout << "A - Add a number" << '\n';
        std::cout << "M - Display mean of the numbers" << '\n';
        std::cout << "S - Display the smallest number" << '\n';
        std::cout << "L - Display the largest number" << '\n';
        std::cout << "Q - Quit" << '\n';
        std::cout << "\nEnter your choice: ";
        std::cin >> selection;

        switch (selection) {
        case 'p':
            print_numbers(vec);
            break;
        case 'P':
            print_numbers(vec);
            break;
        case 'a':
            add_number(vec);
            break;
        case 'A':
            add_number(vec);
            break;
        case 'm':
            display_mean(vec);
            break;
        case 'M':
            display_mean(vec);
            break;
        case 's':
            display_smallest(vec);
            break;
        case 'S':
            display_smallest(vec);
            break;
        case 'l':
            display_largest(vec);
            break;
        case 'L':
            display_largest(vec);
            break;
        case 'q':
            display_quitting();
            break;
        case 'Q':
            display_quitting();
            break;
        default:
            display_illegal();
        }

    } while (selection != 'q' && selection != 'Q');

    return 0;
}


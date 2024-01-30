#include <iostream>
#include <vector>
#include <climits>

void print_numbers(const std::vector<int>& arr);
void clear_numbers(std::vector<int>& arr);
void add_number(std::vector<int>& arr);
void display_mean(const std::vector<int>& arr);
void display_smallest(const std::vector<int>& arr);
void display_largest(const std::vector<int>& arr);
void display_sum_of_product_pairs(const std::vector<int>& arr);
void display_quitting();
void display_illegal();

int main()
{

    std::vector<int> vec{};

    //std::vector<int> vec{1,2,3,4};

    char selection{};

    do {
        std::cout << '\n';
        std::cout << " D - Display numbers" << '\n';
        std::cout << " C - Clear numbers" << '\n';
        std::cout << " A - Add a number" << '\n';
        std::cout << " M - Display mean of the numbers" << '\n';
        std::cout << " S - Display the smallest number" << '\n';
        std::cout << " L - Display the largest number" << '\n';
        std::cout << " P - Display the sum of the product of all pairs" << '\n';
        std::cout << " Q - Quit" << '\n';
        std::cout << "\n Enter your choice: ";
        std::cin >> selection;

        switch (selection) {
        case 'd':
            print_numbers(vec);
            break;
        case 'D':
            print_numbers(vec);
            break;
        case 'c':
            clear_numbers(vec);
            break;
        case 'C':
            clear_numbers(vec);
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
        case 'p':
            display_sum_of_product_pairs(vec);
            break;
        case 'P':
            display_sum_of_product_pairs(vec);
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

void print_numbers(const std::vector<int>& arr) {


    if (arr.size() == 0)
        std::cout << "\n [] - the list is empty\n";
    else {
        std::cout << "\n [";
        for (auto num : arr)
            std::cout << ' ' << num << ' ';
        std::cout << "]\n";
    }

}

void clear_numbers(std::vector<int>& arr) {
    if (arr.size() == 0)
        std::cout << "\n [] - the list is empty\n";
    else {
        arr.clear();
        std::cout << "\n [";
        for (auto num : arr)
            std::cout << ' ' << num << ' ';
        std::cout << "]\n";
    }
}

void add_number(std::vector<int>& arr) {

    std::cout << "\n Enter an integer to add: ";
    long long num{}; // Will accept long long here!
    std::cin >> num;
    if (num > INT_MAX || num < INT_MIN) { // Flag error if num not in int range
        std::cout << "\n Invalid number!\n";
        std::cout << " Must be in range: " << INT_MIN << " to " << INT_MAX << '\n';
    }
    else {
        arr.push_back(static_cast<int>(num)); // cast long long num to int
        std::cout << '\n' << num << " added\n";
    }

}

void display_mean(const std::vector<int>& arr) {

    double result{};

    if (arr.size() < 2)
        std::cout << "\n Unable to calculate the mean - no data\n";
    else {
        for (auto num : arr)
            result += num;
        std::cout << '\n' << " mean of the numbers: " << result / arr.size() << '\n';
            
    }

}

void display_smallest(const std::vector<int>& arr) {

    if (arr.size() == 0)
        std::cout << "\n Unable to determine the smallest number - list is empty\n";
    else {
        int smallest{ INT_MAX }; // Set largest integer possible using <CLIMITS>
        for (auto num : arr)
            if (num  <= smallest) {
                smallest = num;
            }

        std::cout << '\n' << " The smallest number is " << smallest << '\n';
    }
}

void display_largest(const std::vector<int>& arr) {

    if (arr.size() == 0)
        std::cout << "\n Unable to determine the largest number - list is empty\n";
    else {
        int largest{ INT_MIN }; // Set smallest integer possible using <CLIMITS>
        for (auto num : arr)
            if (num >= largest) {
                largest = num;
            }

        std::cout << '\n' << " The largest number is " << largest << '\n';
    }
}

void display_sum_of_product_pairs(const std::vector<int>& vec) {
    size_t vec_size{ vec.size() };
    int result{};

    if (vec_size >= 2) { // Vector must be equal or greater than 2

        for (unsigned i{ 0 }; i < vec_size; ++i) {

            for (unsigned j{ 0 }; j < vec_size; ++j) {

                if (i == j || j <= i) {
                    //std::cout << "continued" << '\n';
                    continue;
                }

                int product{};
                product = vec[i] * vec[j];
                std::cout << "\n Product of pair: " << vec[i] << " * " << vec[j] << " = " << product << '\n';

                result += product;
            }
        }
    }
    else {
        result = 0;
        std::cout << "\n Unable to calculate sum of the product of all pairs, not enough data\n";
    }

    std::cout << "\n Sum of all pairs is " << result << '\n';
}

void display_quitting() {
    std::cout << "\n Goodbye\n";
}

void display_illegal() {
    std::cout << "\n Unknown selection, please try again\n";
}

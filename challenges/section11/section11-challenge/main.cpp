#include <iostream>
#include <vector>
#include <climits>
#include <cctype>


// Prototypes for displaying the menu and getting the user selection
void print_menu();
char get_selection();

// Prototype for function doing the actions required by user
void do_actions(std::vector<int>& arr);

// These prototypes are called from do_actions()
void print_numbers(const std::vector<int>& arr);
void clear_numbers(std::vector<int>& arr);
void add_number(std::vector<int>& arr);
void display_mean(const std::vector<int>& arr);
void display_smallest(const std::vector<int>& arr);
void display_largest(const std::vector<int>& arr);
void display_sum_of_product_pairs(const std::vector<int>& arr);
void find_num(const std::vector<int>& arr);
void display_quitting();
void display_illegal();

int main()
{

    std::vector<int> vec{};
    do_actions(vec);

    return 0;
}
/***************************************************************
This function displays the menu to the console.
***************************************************************/
void print_menu() {
    std::cout << '\n';
    std::cout << " D - Display numbers" << '\n';
    std::cout << " C - Clear numbers" << '\n';
    std::cout << " A - Add a number" << '\n';
    std::cout << " M - Display mean of the numbers" << '\n';
    std::cout << " S - Display the smallest number" << '\n';
    std::cout << " L - Display the largest number" << '\n';
    std::cout << " P - Display the sum of the product of all pairs" << '\n';
    std::cout << " F - Display the index of a number" << '\n';
    std::cout << " Q - Quit" << '\n';
}

/***************************************************************
This function gets the selection from the user.
***************************************************************/
char get_selection() {
    char selection{};
    std::cout << "\n Enter your choice: ";
    std::cin >> selection;
    // https://www.programiz.com/cpp-programming/library-function/cctype/toupper
    return (char) toupper(selection);
}

/***************************************************************
This function executes the actions required by the user.
***************************************************************/
void do_actions(std::vector<int>& arr) {

    char selection{};
    do {
       print_menu();
       selection = get_selection();

       switch (selection) {
       case 'D':
           print_numbers(arr);
           break;
       case 'C':
           clear_numbers(arr);
           break;
       case 'A':
           add_number(arr);
           break;
       case 'M':
           display_mean(arr);
           break;
       case 'S':
           display_smallest(arr);
           break;
       case 'L':
           display_largest(arr);
           break;
       case 'P':
           display_sum_of_product_pairs(arr);
           break;
       case 'F':
           find_num(arr);
           break;
       case 'Q':
           display_quitting();
           break;
       default:
           display_illegal();
       }

    } while (selection != 'Q');

}

/***************************************************************
This function displays the numbers in the vector.
***************************************************************/
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

/***************************************************************
This function clears the vector.
***************************************************************/
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

/***************************************************************
This function appends an integer to the vector.
***************************************************************/
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

/***************************************************************
This function calculates and displays the mean of the numbers in 
the vector.
***************************************************************/
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

/***************************************************************
This function displays the smallest number in the vector.
***************************************************************/
void display_smallest(const std::vector<int>& arr) {

    if (arr.size() == 0)
        std::cout << "\n Unable to determine the smallest number - list is empty\n";
    else {
        int smallest{ INT_MAX }; // Set largest integer possible using <CLIMITS>
        for (auto num : arr)
            if (num <= smallest) {
                smallest = num;
            }

        std::cout << '\n' << " The smallest number is " << smallest << '\n';
    }
}

/***************************************************************
This function displays the largest number in the vector.
***************************************************************/
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

/***************************************************************
This function displays the sum of the pairs in the vector.
***************************************************************/
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

/***************************************************************
This function prompts the user for a integer to tr to find in the 
vector, and displays the index(es) of the found number.
***************************************************************/
void find_num(const std::vector<int>& arr) {

    bool found{ false };

    std::cout << "\n Enter an integer to find: ";
    long long num{}; // Will accept long long here!
    std::cin >> num;
    if (num > INT_MAX || num < INT_MIN) { // Flag error if num not in int range
        std::cout << "\n Invalid number!\n";
        std::cout << " Must be in range: " << INT_MIN << " to " << INT_MAX << '\n';
    }
    else {
        for (unsigned i{ 0 }; i < arr.size(); ++i)
            if (arr[i] == num) {
                found = true;
                std::cout << "\n Found " << num << " at index " << i;
            }
        std::cout << '\n';
        if (!found)
            std::cout << " Unable to find " << num << ".\n";
            
    }

}

/***************************************************************
This function displays the quit message.
***************************************************************/
void display_quitting() {
    std::cout << "\n Goodbye\n";
}

/***************************************************************
This function displays the illegal input message.
***************************************************************/
void display_illegal() {
    std::cout << "\n Unknown selection, please try again\n";
}

#include <iostream>
#include <cmath>

int main()
{

    double bill_total{ 102.78 };
    int number_of_guests{ 5 };

    //DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----

    double individual_bill{ bill_total / number_of_guests};

    // https://en.cppreference.com/w/cpp/numeric/math/floor
    double individual_bill_1{floor(individual_bill)};

    // https://en.cppreference.com/w/cpp/numeric/math/round
    double individual_bill_2{round(individual_bill)};

    // https://en.cppreference.com/w/cpp/numeric/math/ceil
    double individual_bill_3{ceil(individual_bill*100)/ 100};



    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    std::cout << "The individual bill at location 1 will be $" 
         << individual_bill_1 << "\n" 
         << "The individual bill at location 2 will be $" 
         << individual_bill_2 << "\n" 
         << "The individual bill at location 3 will be $" 
         << individual_bill_3;

    return 0;
}

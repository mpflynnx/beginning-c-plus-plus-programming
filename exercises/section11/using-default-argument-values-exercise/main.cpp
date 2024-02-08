#include <iostream>

void print_grocery_list(int apples = 3, int oranges = 7, int mangos=13);
//----WRITE YOUR FUNCTION PROTOTYPE BELOW THIS LINE----

void modify_grocery_list();

int main()
{
    modify_grocery_list();
    return 0;
}

void print_grocery_list(int apples, int oranges, int mangos) { //----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    std::cout << apples << " apples" << "\n" 
              << oranges << " oranges" << "\n" 
              << mangos << " mangos" << "\n";
}

void modify_grocery_list() {

    print_grocery_list(); // first week
    print_grocery_list(5); // The next week, you decide that you would like 5 apples instead of 3.
    print_grocery_list(7,11); // For the final week, 7 apples, 11 oranges, and the default number of mangos

}
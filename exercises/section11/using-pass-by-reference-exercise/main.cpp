#include <iostream>
#include <string>
#include <typeinfo>
#include <string_view>

// Best practice:
// source: https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/
// Prefer passing strings using std::string_view (by value) instead of const std::string&, 
// unless your function calls other functions that require C-style strings or std::string parameters.
void print_guest_listSV(std::string_view, std::string_view, std::string_view);

// Exercise reguired the below function
// Not best practice to pass std::string& but ok if std::string argument passed in
std::string print_guest_list(const std::string& guest_1, const std::string& guest_2, const std::string& guest_3);

void clear_guest_list(std::string& guest_1, std::string& guest_2, std::string& guest_3);
void event_guest_list();

int main()
{
    event_guest_list();
    return 0;
}

void event_guest_list() {

    std::string guest_1{ "Larry" };
    std::string guest_2{ "Moe" };
    std::string guest_3{ "Curly" };

    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE THE FUNCTION CALLS BELOW THIS LINE----

    //print_guest_list(guest_1, guest_2, guest_3);
    //clear_guest_list(guest_1, guest_2, guest_3);
    //print_guest_list(guest_1, guest_2, guest_3);

    print_guest_listSV(guest_1, guest_2, guest_3);
    clear_guest_list(guest_1, guest_2, guest_3);
    print_guest_listSV(guest_1, guest_2, guest_3);

}

//----WRITE THE FUNCTION DEFINITIONS BELOW THIS LINE----
std::string print_guest_list(const std::string& guest_1, const std::string& guest_2, const std::string& guest_3) {

    //----WRITE THE FUNCTION BODY BELOW THIS LINE----

    std::cout << guest_1 << '\n';
    std::cout << guest_2 << '\n';
    std::cout << guest_3 << '\n';

    //----WRITE THE FUNCTION BODY ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    std::string test_1 = typeid(guest_1).name(), test_2 = typeid(guest_2).name(), test_3 = typeid(guest_3).name();
    return test_1 + test_2 + test_3;
}

void clear_guest_list(std::string& guest_1, std::string& guest_2, std::string& guest_3) {

    //----WRITE THE FUNCTION BODY BELOW THIS LINE----
    guest_1 = ' ';
    guest_2 = ' ';
    guest_3 = ' ';

}

void print_guest_listSV(std::string_view guest_1, std::string_view guest_2, std::string_view guest_3) {
    //----WRITE THE FUNCTION BODY BELOW THIS LINE----

    std::cout << guest_1 << '\n';
    std::cout << guest_2 << '\n';
    std::cout << guest_3 << '\n';

}
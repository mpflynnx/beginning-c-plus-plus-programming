#include <iostream>
#include <string>

void event_guest_list();
std::string print_guest_list(const std::string guest_list[], size_t size);
void clear_guest_list(std::string guest_list[], size_t size);

int main()
{
    event_guest_list();
    return 0;
}

void event_guest_list() {

    std::string guest_list[]{ "Larry", "Moe", "Curly" };
    size_t guest_list_size{ 3 };

    print_guest_list(guest_list, guest_list_size);
    clear_guest_list(guest_list, guest_list_size);
    print_guest_list(guest_list, guest_list_size);

}

std::string print_guest_list(const std::string guest_list[], size_t size) {
    
    for (int i = 0; i < size; i++) {
        std::cout << guest_list[i] << '\n';
    }
           
    return typeid(guest_list).name();
}

void clear_guest_list(std::string guest_list[], size_t size) {
    for (int i = 0; i < size; i++) {
        guest_list[i] = ' ';
    }
}

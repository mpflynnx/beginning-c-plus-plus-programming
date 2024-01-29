#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{

    cout << "Welcome to the carpet cleaning service" << endl;

    cout << "\nHow many small rooms to clean? ";
    int small_rooms_to_clean {0};
    cin >> small_rooms_to_clean;

    cout << "How many large rooms to clean? ";
    int large_rooms_to_clean {0};
    cin >> large_rooms_to_clean;

    const double price_per_small_room {25};
    const double price_per_large_room {35};
    const double sales_tax {0.06};
    const int estimate_expiry {30};

    cout << "\nEstimate for carpet cleaning service"
         << endl;
    cout << "Number of small rooms: " 
         << small_rooms_to_clean  
         << endl;
    cout << "Number of large rooms: "
         << large_rooms_to_clean 
         << endl;
    cout << "Price per small room: £"
         << price_per_small_room << endl;    
    cout << "Price per large room: £"
         << price_per_large_room << endl;

    double total_for_small_rooms {price_per_small_room * small_rooms_to_clean};
    double total_for_large_rooms {price_per_large_room * large_rooms_to_clean};
    double total_for_all_rooms {total_for_small_rooms + total_for_large_rooms};
    cout << "Total cost for rooms: £" 
         << total_for_all_rooms 
         << endl;
    double tax_to_pay {total_for_all_rooms * sales_tax};
    cout << "Tax: £" 
         << tax_to_pay 
         << endl;
    cout << "=========================================" << endl;
    cout << "Total estimate: £" 
         << total_for_all_rooms + tax_to_pay 
         << endl;

    cout << "The estimate is valid for " 
         << estimate_expiry 
         << " days." 
         << endl;

    return 0;
}
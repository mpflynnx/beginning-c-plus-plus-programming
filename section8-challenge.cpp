#include <iostream>

int main()
{
    const int dollar {100};
	const int quarter {25};
	const int dime {10};
	const int nickel {5};
    const int penny {1};

    std::cout << "Enter an amount in cents : ";
    int amount {};
    std::cin >> amount;

    std::cout << "\nYou can provide this change as follows:\n";

    int remainder {0}; 
    int num_of_dollars {0};
    if (amount >= dollar)
    {
        num_of_dollars = amount / dollar;
        // std::cout << "amount remainder: " << remainder << '\n'; 
    }

    std::cout << "dollars    : "  << num_of_dollars << '\n';
    remainder = amount %= dollar;

    int num_of_quarters {0};
    if (amount >= quarter)
    {
        num_of_quarters = amount / quarter;
        // std::cout << "amount remainder: " << remainder << '\n'; 
    }
    std::cout << "quarters : " << num_of_quarters << '\n';
    remainder = amount %= quarter;

    int num_of_dimes {0};
    if (amount >= dime)
    {
        num_of_dimes = amount / dime;

        // std::cout << "amount remainder: " << remainder << '\n'; 
    }
    std::cout << "dimes     : " << num_of_dimes << '\n';
    remainder = amount %= dime;

    int num_of_nickels {0};
    if (amount >= nickel)
    {
        num_of_nickels = amount / nickel;

        // std::cout << "amount remainder: " << remainder << '\n'; 
    }
    std::cout << "nickels   : " << num_of_nickels << '\n';
    remainder = amount %= nickel;

    int num_of_pennies {0};
    if (amount >= penny)
    {
        num_of_pennies = amount / penny;

        // std::cout << "amount remainder: " << remainder << '\n'; 
    }

    std::cout << "pennies  : " << num_of_pennies << '\n';
    remainder = amount %= penny;

    // std::cout << "\nYou can provide this change as follows:\n";
    // std::cout << "dollars    : " << num_of_dollars << '\n';
    // std::cout << "quarters : " << num_of_quarters << '\n';
    // std::cout << "dimes     : " << num_of_dimes << '\n';
    // std::cout << "nickels   : " << num_of_nickels << '\n';
    // std::cout << "pennies  : " << num_of_pennies << '\n';

	return 0;
}

// is amount >= 100
// what is the remainder of amount % 100
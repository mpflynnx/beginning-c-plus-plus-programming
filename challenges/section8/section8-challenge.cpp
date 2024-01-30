#include <iostream>

int func(int amount, int type)
{
    if (amount >= type)
    {
        int num_of_type {amount / type};
        return num_of_type;
    }

    return 0;
}

int main()
{
    const int dollar {100};
	const int quarter {25};
	const int dime {10};
	const int nickel {5};

    std::cout << "Enter an amount in cents : ";
    int amount {};
    std::cin >> amount;

    std::cout << "\nYou can provide this change as follows:\n";

    std::cout << "dollars    : "  << func(amount, dollar) << '\n';
    amount %= dollar;

    std::cout << "quarters : " << func(amount, quarter) << '\n';
    amount %= quarter;

    std::cout << "dimes     : " << func(amount, dime) << '\n';
    amount %= dime;

    std::cout << "nickels   : " << func(amount, nickel) << '\n';
    amount %= nickel;

    std::cout << "pennies  : " << amount << '\n';

	return 0;
}

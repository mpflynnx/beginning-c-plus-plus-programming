#include <iostream>
#include <iomanip>

int function_activation_count{ 0 };

void amount_accumulated();

double a_penny_doubled_everyday(int n, double money=0.01);

int main()
{
    amount_accumulated();
    return 0;
}

void amount_accumulated() {

    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE THE FUNCTION CALL BELOW THIS LINE----

    double total_amount{};
    total_amount = a_penny_doubled_everyday(25);


    //----WRITE THE FUNCTION CALL ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    std::cout << "If I start with a penny and doubled it every day for 25 days, I will have $" 
              << std::setprecision(10) << total_amount;
}


double a_penny_doubled_everyday(int n, double money) {

    double total_amount{};

    if (n == 1)
        return money;

    total_amount = money + money; // double money
    n--; // count down the days
    return (a_penny_doubled_everyday(n, total_amount));

}

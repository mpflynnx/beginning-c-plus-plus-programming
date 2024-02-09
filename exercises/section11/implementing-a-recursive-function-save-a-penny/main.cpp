#include <iostream>

int function_activation_count{ 0 };

double a_penny_doubled_everyday(int n, double money=0.01);

int main()
{
    std::cout << a_penny_doubled_everyday(18);
    return 0;
}

// wip
double a_penny_doubled_everyday(int n, double money) {
    //if (n == 0)
    //    return 0.01;
    //return (n + a_penny_doubled_everyday(n * money));
    return 0.01;
}

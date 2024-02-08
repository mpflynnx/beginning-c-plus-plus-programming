#include <iostream>

void area_calc();

int find_area(int side_length); // overload for integers
double find_area(double, double); // overload for doubles

int main()
{
    area_calc();
    return 0;
}

// overload for integers
int find_area(int side_length) {
    return side_length * side_length;
}

// overload for doubles
double find_area(double length, double width) {
    return length * width;
}

void area_calc() {

    int square_area{ find_area(2) };
    double rectangle_area{ find_area(4.5,2.3) };

    std::cout << "The area of the square is " << square_area << "\n" 
         << "The area of the rectangle is " << rectangle_area;
}
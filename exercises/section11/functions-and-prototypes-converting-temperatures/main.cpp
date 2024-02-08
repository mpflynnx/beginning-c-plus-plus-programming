#include <iostream>
#include <cmath>

//----WRITE YOUR FUNCTION PROTOTYPES BELOW THIS LINE----
double fahrenheit_to_celsius(double temperature);
double fahrenheit_to_kelvin(double temperature);
void temperature_conversion(double fahrenheit_temperature);
//----WRITE YOUR FUNCTION PROTOTYPES ABOVE THIS LINE----

int main()
{
    double fahrenheit_temperature{ 60.5 };
    temperature_conversion(fahrenheit_temperature);
    return 0;
}

//----WRITE YOUR FUNCTION DEFINITIONS BELOW THIS LINE----

double fahrenheit_to_celsius(double temperature) {
    return round((5.0 / 9.0) * (temperature - 32));
}

double fahrenheit_to_kelvin(double temperature) {
    return round((5.0 / 9.0) * (temperature - 32) + 273);
}

void temperature_conversion(double fahrenheit_temperature) {

    double celsius_temperature{fahrenheit_to_celsius(fahrenheit_temperature)};
    double kelvin_temperature{fahrenheit_to_kelvin(fahrenheit_temperature)};

    std::cout << "The fahrenheit temperature "
        << fahrenheit_temperature
        << " degrees is equivalent to "
        << celsius_temperature
        << " degrees celsius and "
        << kelvin_temperature << " degrees kelvin.";
}
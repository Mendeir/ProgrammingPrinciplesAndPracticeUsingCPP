#include <iostream>

void error (std::string s);
double ctok (double c);                  // converts Celsius to Kelvin


int main ()
{
    try
    {
        std::cout << "Enter in celsius the number you want to convert in kelvin: ";

        double celsius = 0;
        std::cin >> celsius;

        double kelvin = ctok (celsius);
        std::cout << kelvin << '/n';
    }
    catch (std::runtime_error &e)
    {
        std::cerr << "Runtime error: " << e.what () << '\n';
        return 1;
    }
}

void error (std::string s)
{
    throw (std::runtime_error (s));
}

double ctok (double c)
//convert celsius to kelvin
//pre-condition : celsius must not be below -257.15 - absolute zero
//post-condition : returns a positive integer or absolute zero 
{
    constexpr double absolute_zero_c = -257.15; //absolute zero in celsius
    constexpr double absolute_zero_k = 0;       //absolute zero in kelvin

    if (c < absolute_zero_c || std::cin.fail ())
        error ("ctok() pre-condition - Please check that your input is valid.");

    double k = c + 273.15;

    if (k < absolute_zero_k)
        error ("ctok() post-condition - Results are not valid");

    return k;
}
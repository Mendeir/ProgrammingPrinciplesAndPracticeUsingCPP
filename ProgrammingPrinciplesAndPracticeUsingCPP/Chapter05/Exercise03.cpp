#include <iostream>

void error (std::string s);
double ctok (double c);                 // converts Celsius to Kelvin


int main ()
{
    try
    {
        double celsius = 0;
        std::cin >> celsius;

        if (!std::cin)
            error ("Invalid input! Expected an integer");
        if (celsius < -273.15)
            error ("Lowest temperature can only be absolute zero, -273.15C or 0K");
            

        double kelvin = ctok (celsius);             
        std::cout << kelvin << '/n';   

    }
    catch (std::runtime_error &e)
    {
        std::cerr << "Runtime error: " << e.what() << '\n';
        return 1;
    }
}

void error (std::string s)
{
    throw std::runtime_error (s);
}

double ctok (double c)
{
    double k = c + 273.15;

    return k;
}
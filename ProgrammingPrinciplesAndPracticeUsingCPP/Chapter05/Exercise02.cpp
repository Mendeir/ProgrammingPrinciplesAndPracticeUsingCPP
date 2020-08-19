#include <iostream>

using namespace std;

/*
    Errors found: 
    1. Variable being inputted is undefined/uninitialized
        Correction : Changed the variable 'd' to 'c' as c is commented as input variable.
    2. The argument in the function is invalid as it expects a double data type but the argument being passed is a string.
        Correction : Removed the double quotation marks since the 'c' variable has a double data type
    3. Cout is not recognized by the compiler, might be a typo
        Correction : Made the letter 'c' in the Cout lowercase.
    4. The function expects to receive a double integer but instead receives an int data type, missing a semicolon in return type
        Correction : Changed the return value to the variable found inside the function and added semicolon.
    5. The data type that the function expects is double and the data type being used in the computation with floating point number is an int,
    it might lead to a narrow conversion/data loss.
        Correction : Changed the data type from int to double


*/

double ctok (double c)                  // converts Celsius to Kelvin
{
    double k = c + 273.15;
    return k;
}
int main ()
{
    double c = 0;                       // declare input variable
    cin >> c;                           // retrieve temperature to input variable
    double k = ctok (c);                // convert temperature
    cout << k << '/n';                  // print out temperature
}
/*

Run this program with a variety of inputs. Try small values 
(e.g., 2 and 3); try large values (larger than 127, larger 
than 1000); try negative values; try 56; try 89; try 128; 
try non-integer values (e.g., 56.9 and 56.2). In addition 
to showing how conversions from double to int and conversions
from int to char are done on your machine, this program shows
you what character (if any) your machine will print for a given 
integer value.

*/

#include "std_lib_facilities.h"

int main ()
{
    double d = 0;
    while (cin >> d) {                      // repeat the statements below
                                            // as long as we type in numbers
        int i = d;                          // try to squeeze a double into an int
        char c = i;                         // try to squeeze an int into a char
        int i2 = c;                         // get the integer value of the character
        cout << "d==" << d                  // the original double
            << " i==" << i                  // converted to int
            << " i2==" << i2                // int value of char
            << " char(" << c << ")\n";      // the char
    }
}
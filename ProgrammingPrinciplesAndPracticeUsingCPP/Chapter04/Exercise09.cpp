// For an int it will only take 31 squares and for a double it takes many iterations

#include "std_lib_facilities.h"

int main ()
{
    int rice { 0 };
    int square_rice { 1 };
    double drice { 0 };
    double dsquare_rice { 1 };

    for (int square = 1; square <= 1500; ++square) {

        rice += square_rice;
        drice += dsquare_rice;
        square_rice *= 2;
        dsquare_rice *= 2;

        cout << "Square " << square << ": int rice (" << rice << "), double rice ("
            << drice << ")\n";
    }

    return 0;
}
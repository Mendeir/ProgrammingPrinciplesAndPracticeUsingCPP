#include "std_lib_facilities.h"

// compute mean and median temperatures
int main ()
{
    vector<double> temps;                  // temperatures
    for (double temp; cin >> temp; )    // read into temp
        temps.push_back (temp);     // put temp into vector

// compute mean temperature:
    double sum = 0;
    for (double x : temps) sum += x;
    cout << "Average temperature: " << sum / temps.size () << '\n';

    // compute median temperature:
    sort (temps);                                     // sort temperatures
    const int middle_element = temps.size () / 2;
    if (temps.size () % 2 != 0)
        cout << "Median temperature: " << temps [middle_element] << '\n';
    else
        cout << "Median temperature: " << (temps [middle_element] + temps [middle_element - 1]) / 2 << '\n'; //formula for median if elements are even
    
}
/*

Get the “name and age” example to run. Then, modify it to write out the age 
in months: read the input in years and multiply (using the * operator) by 12. 
Read the age into a double to allow for children who can be very proud of
being five and a half years old rather than just five.

*/

#include "std_lib_facilities.h"

int main ()
{

	cout << "Please enter your first name and age\n";
	
	string firstName = "???";
	double age = 0.0;

	cin >> firstName >> age;

	cout << "Hello, " << firstName << "(age " << age*12 << " months)\n";

	return 0;
}
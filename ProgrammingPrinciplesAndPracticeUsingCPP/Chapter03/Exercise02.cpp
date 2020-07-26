#include "std_lib_facilities.h"


int main ()
{
	double miles_input { 0.0 };
	constexpr double kilometer { 1.60934 };

	cout << "MILES TO KILOMETER CONVERTER";

	cout << "\nEnter the number of miles to convert: ";
	cin >> miles_input;

	cout << miles_input << " miles is equivalent to " << miles_input * kilometer << " kilometers.\n";



	return 0;
}

#include "std_lib_facilities.h"

int main ()
{
	vector <string> numbers { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector <string> digits { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	string input { "" };

	cout << "Enter a digit or its word:\n";

	while (cin >> input)
	{
		
		for (size_t counter { 0 }; counter < numbers.size (); ++counter)
		{
			if (input == numbers [counter])
				cout << digits [counter] << '\n';
		}

		for (size_t counter { 0 }; counter < digits.size (); ++counter)
		{
			if (input == digits [counter])
				cout << numbers [counter] << '\n';
		}

	}


	return 0;
}
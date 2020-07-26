#include "std_lib_facilities.h"

int main ()
{
	string input { "???" };

	cout << "Enter a string of a number: ";
	cin >> input;

	if (!cin)
		error ("Something wrong happened with the input");

	if (input == "zero")
		cout << "0\n";
	else if (input == "one")
		cout << "1\n";
	else if (input == "two")
		cout << "2\n";
	else if (input == "three")
		cout << "3\n";
	else if (input == "four")
		cout << "4\n";
	else
		cout << "Not a number i know\n";

	return 0;
}
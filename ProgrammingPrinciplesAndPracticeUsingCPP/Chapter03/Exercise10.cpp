#include "std_lib_facilities.h"

int main ()
{

	string operation { "???" };
	double val1 { 0 }, val2 { 0 };

	cout << "Enter an operation followed by two integer values separated by space: ";
	cin >> operation >> val1 >> val2;

	if (!cin)
		error ("Something wrong happened with the input.");

	if (operation == "+")
		cout << "The sum of " << val1 << " and " << val2 << " is: " << val1 + val2 << '\n';
	else if (operation == "-")
		cout << "The difference of " << val1 << " and " << val2 << " is: " << val1 - val2 << '\n';
	else if (operation == "*")
		cout << "The product of " << val1 << " and " << val2 << " is: " << val1 * val2 << '\n';
	else if (operation == "/")
	{
		if (val2 == 0)
			cout << "Oops! You cannot divide a number by zero\n";
		else
			cout << "The quotient of " << val1 << " and " << val2 << " is: " << val1 / val2 << '\n';
	}
	else
		cout << "Sorry - I can't recognize the operation you entered.";

	return 0;
}
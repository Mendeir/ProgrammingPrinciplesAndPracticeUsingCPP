#include "std_lib_facilities.h"

int main ()
{
	double val1 { 0 }, val2 { 0 };

	cout << "Enter two values: ";
	cin >> val1 >> val2;

	if (!cin)
		error ("Something went wrong with the input.");

	cout << '\n';

	//determine small and large
	if (val1 == val2)
		cout << val1 << " and " << val2 << " are equal.\n";
	if (val1 > val2)
		cout << val1 << " is larger than " << val2 << ".\n";
	if (val1 < val2)
		cout << val2 << " is larger than " << val2 << ".\n";

	//give sum, difference, and product
	cout << "The sum of " << val1 << " and " << val2 << " is: " << val1 + val2 << '\n';
	cout << "The difference of " << val1 << " and " << val2 << " is: " << val1 - val2 << '\n';
	cout << "The product of " << val1 << " and " << val2 << " is: " << val1 * val2 << '\n';

	if (val2 == 0)
		cout << "You cannot divide " << val1 << " by 0\n";
	else
		cout << "The ratio of " << val1 << " and " << val2 << " is: " << val1 / val2 << '\n';

	return 0;
}
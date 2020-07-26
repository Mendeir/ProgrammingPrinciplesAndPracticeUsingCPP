#include "std_lib_facilities.h"

int main ()
{
	int val1 { 0 };

	cout << "CHECK IF INTEGER IS ODD OR EVEN\n";
	cout << "Enter an integer you want to check: ";
	cin >> val1;

	if (val1 % 2 == 0)
		cout << "\nThe number " << val1 << " is an even number\n";
	else
		cout << "\nThe number " << val1 << " is an odd number\n";

	return 0;
}
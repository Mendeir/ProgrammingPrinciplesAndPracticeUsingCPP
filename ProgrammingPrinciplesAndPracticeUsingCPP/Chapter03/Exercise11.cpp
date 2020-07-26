#include "std_lib_facilities.h"

int main ()
{

	double number_of_pennies { 0 }, number_of_nickels { 0 }, number_of_dimes { 0 },
		number_of_quarters { 0 }, number_of_half_dollars { 0 }, dollar_value { 0.0 };

	cout << "How many pennies do you have? ";
	cin >> number_of_pennies;

	cout << "How many nickels do you have? ";
	cin >> number_of_nickels;

	cout << "How many dimes do you have? ";
	cin >> number_of_dimes;

	cout << "How many quarters do you have? ";
	cin >> number_of_quarters;

	cout << "How many half dollars do you have? ";
	cin >> number_of_half_dollars;

	if (number_of_pennies == 1)
		cout << "\nYou have " << number_of_pennies << " penny.\n";
	else
		cout << "\nYou have " << number_of_pennies << " pennies.\n";
	
	if (number_of_nickels == 1)
		cout << "You have " << number_of_nickels << " nickel.\n";
	else 
		cout << "You have " << number_of_nickels << " nickels.\n";

	if (number_of_dimes == 1)
		cout << "You have " << number_of_dimes << " dime.\n";
	else
		cout << "You have " << number_of_dimes << " dimes.\n";

	if (number_of_quarters == 1)
		cout << "You have " << number_of_quarters << " quarter.\n";
	else
		cout << "You have " << number_of_quarters << " quarters.\n";

	if (number_of_half_dollars == 1)
		cout << "You have " << number_of_half_dollars << " half dollar.\n";
	else
		cout << "You have " << number_of_half_dollars << " half dollars.\n";
	


	dollar_value = number_of_pennies + (number_of_nickels * 5) + (number_of_dimes * 10) 
				   + (number_of_quarters * 25) + (number_of_half_dollars * 50);

	cout << "The value of all your coins is $" << dollar_value / 100 << '\n';
	

	return 0;
}
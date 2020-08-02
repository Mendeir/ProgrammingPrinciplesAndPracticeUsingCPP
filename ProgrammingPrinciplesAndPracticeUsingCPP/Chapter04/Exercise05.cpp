#include "std_lib_facilities.h"

int main ()
{
	int user_input1 { 0 }, user_input2 { 0 };
	char operation { ' ' };

	cout << "SIMPLE CALCULATOR\n";
	cout << "\nEnter two numbers separated by space followed by an operation(+, -, *, /): \n";

	while (cin >> user_input1 >> user_input2 >> operation)
	{
		switch (operation)
		{
			case '+':
				cout << "The sum of " << user_input1 << " and " << user_input2 << " is " << user_input1 + user_input2 << '\n';
				break;

			case '-':
				cout << "The difference of " << user_input1 << " and " << user_input2 << " is " << user_input1 - user_input2 << '\n';
				break;

			case '*':
				cout << "The product of " << user_input1 << " and " << user_input2 << " is " << user_input1 * user_input2 << '\n';
				break;

			case '/':
				cout << "The quotient of " << user_input1 << " and " << user_input2 << " is " << user_input1 + user_input2 << '\n';
				break;

			default:
				cout << "Sorry can't understand your input. Please try again.\n";
		}
	}
	return 0;
}
#include "std_lib_facilities.h"

int get_number ();
vector<string> numbers { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", " nine", "ten" };

int main ()
{
	

	cout << "CALCULATOR 2.0\n";

	cout << "Enter a digit or its word separated by an operator (+,-,*,/,%):\n";

	while (true)
	{
		string output_operator {" "};
		int result { 0 };
		char exit { ' ' };
		int user_input1 = get_number ();
		
		char op { ' ' };
		cin >> op;
		
		int user_input2 = get_number ();

		switch (op)
		{
			case '+':
				output_operator = "The sum of ";
				result = user_input1 + user_input2;
				break;

			case '-':
				output_operator = "The difference of ";
				result = user_input1 - user_input2;
				break;

			case '*':
				output_operator = "The product of ";
				result = user_input1 * user_input2;
				break;

			case '/':
				if (user_input2 == 0)
				{
					output_operator = "The quotient of ";
					cout << "Error: Division of zero not allowed. Result assigned to 0" << '\n';
					result = 0;
					break;
				}
				output_operator = "The quotient of ";
				result = user_input1 / user_input2;
				break;

			case '%':
				if (user_input2 == 0)
				{
					output_operator = "The modulo of ";
					cout << "Error: Division of zero not allowed. Result assigned to 0" << '\n';
					result = 0;
					break;
				}
				output_operator = "The modulo of ";
				result = user_input1 % user_input2;
				break;

			default:
				cout << "Error: Invalid operator input." << '\n';
		}

		cout << output_operator << user_input1 << " and " << user_input2 << " is: " << result << '\n';

	}

	return 0;
}

int get_number ()
{
	string string_input { " " };
	int int_input { 0 };

	if (cin >> int_input)
		return int_input;
	else
	{
		cin.clear();
		cin >> string_input;

		for (size_t counter = 0; counter < numbers.size(); ++counter)
		{
			if (string_input == numbers [counter])
				return counter;
		}

		cout << "Error: Input unknown number, will be initialized to 0\n";
		return 0;
	}

}
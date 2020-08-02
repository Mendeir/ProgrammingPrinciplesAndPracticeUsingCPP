#include "std_lib_facilities.h"

int main ()
{
	char user_input { 0 };
	int first_number { 1 }, last_number { 100 };
	int tries { 0 };
	int guess { 0 };

	cout << "GUESSING GAME\n";

	cout << "\nThink of a number between " << first_number << " - " << last_number << " and the computer will guess it.\n"
		 << "Answer honestly for accurate results\n"
		 << "Input 'y' for yes and 'n' for no\n";
	
	while (first_number != last_number)
	{
		//initialize guess
		guess = (first_number + last_number) / 2;

		//to avoid loss of info
		if ((last_number - first_number) == 1) 
			guess = last_number;    						
		else 
			guess = (first_number + last_number) / 2;

		//Alternately ask less than and greater than
		if (tries % 2 == 0)
		{
			cout << "\nIs the number you're thinking less than " << guess << "? ";
			cin >> user_input;

			if (user_input == 'y')
			{
				last_number = guess - 1;
				++tries;
			}
			else if (user_input == 'n')
			{
				first_number = guess;
				++tries;
			}
			else
				cout << "Sorry can't understand your input. Please try again.\n";
		}
		else
		{
			cout << "\nIs the number you're thinking greater than " << guess << "? ";
			cin >> user_input;

			if (user_input == 'y')
			{
				first_number = guess + 1;	
				++tries;
			}
			else if (user_input == 'n')
			{
				last_number = guess;
				++tries;
			}
			else
				cout << "Sorry can't understand your input. Please try again.\n";
		
			
		}

	}
		

	cout << "The number you are thinking is: " << first_number << endl;
	cout << "It took me " << tries << " tries to guess it." << endl;

	return 0;
}
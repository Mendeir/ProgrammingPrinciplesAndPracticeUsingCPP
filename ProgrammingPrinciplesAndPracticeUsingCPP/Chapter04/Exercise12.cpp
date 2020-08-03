#include "std_lib_facilities.h"

bool check_if_prime (int check_number);
int get_max_input ();

int main ()
{
	vector<int> all_prime_numbers;
	int count { 0 }, max { 0 };

	max = get_max_input ();

	for (int counter = 1; counter <= max; ++counter)
	{
		if (check_if_prime (counter))
			all_prime_numbers.push_back (counter);
	}

	cout << "\nAll the prime numbers from 1 to " << max << ":\n";
	for (int counter : all_prime_numbers)
	{
		cout << counter << " ";
		if (count == 10)
		{
			cout << '\n';
			count = 0;
		}
		++count;
	}


	return 0;
}

int get_max_input ()
{
	int max { 0 };
	while (true)
	{
		cout << "Enter the max range that you want the prime number to be found: ";
		cin >> max;

		if (cin.fail ())
		{
			cin.clear ();
			cin.ignore ();
			cout << "Invalid input! Please try again.\n";
		}
		else
			return max;

		cout << '\n';

	}
}

bool check_if_prime (int check_number)
{
	vector<int> primes { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

	for (int counter : primes)
	{
		if (check_number % counter == 0 && check_number != counter || check_number == 1)
			return false;
	}

	return true;

}
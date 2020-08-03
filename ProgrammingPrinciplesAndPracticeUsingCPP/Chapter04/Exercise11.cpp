#include "std_lib_facilities.h"

bool check_if_prime (int check_number);

int main ()
{
	vector<int> all_prime_numbers;
	int count { 0 };

	for (int counter = 1; counter <= 100; ++counter)
	{
		if (check_if_prime(counter))
			all_prime_numbers.push_back (counter);	
	}

	cout << "All the prime numbers from 1 to 100:\n";
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

bool check_if_prime (int check_number)
{
	vector<int> primes { 2, 3, 5, 7 };

	for (int counter : primes)
	{
		if (check_number % counter == 0 && check_number != counter)
			return false;
	}

	return true;

}
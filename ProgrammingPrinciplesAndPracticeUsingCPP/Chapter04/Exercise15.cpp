#include "std_lib_facilities.h"

void find_prime_numbers (vector<int> &given_vector, int max_range);
void display_prime_numbers_vector (const vector<int> display_vector);

int main ()
{

	cout << "FIRST N PRIMES\n";

	cout << "How many primes you want to find? ";
	int first_primes { 0 };
	cin >> first_primes;

	constexpr int first_prime_number { 2 };
	vector<int> primes { first_prime_number };

	find_prime_numbers (primes, first_primes);
	display_prime_numbers_vector (primes);

	return 0;
}

void find_prime_numbers (vector<int> &given_vector, int max_range)
{
	//We start evaluating 3 since 2 is already prime
	
	int evaluate_number { 3 };
	constexpr int lower_boundary {0};

	while (given_vector.size() != max_range)
	{
		bool flag { false };
		for (size_t counter = lower_boundary; counter < given_vector.size (); ++counter)
		{
			if (evaluate_number % given_vector [counter] == 0)
				flag = true;
		}

		if (!flag)
			given_vector.push_back (evaluate_number);
		
	

		++evaluate_number;
	}
}

void display_prime_numbers_vector (const vector<int> display_vector)
{
	int newline_counter { 0 };

	for (int counter : display_vector)
	{
		cout << counter << '\t';
		++newline_counter;

		if (newline_counter == 10)
		{
			cout << '\n';
			newline_counter = 0;
		}
	}
}
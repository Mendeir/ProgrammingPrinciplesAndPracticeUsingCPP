#include "std_lib_facilities.h"

void sieve_of_erasthones (vector<int> &given_vector, int higher_boundary);
void display_prime_vector (const vector<int> display_vector, int max);

int main ()
{

	cout << "PRIME FACTORS FROM 1 TO N\n";

	cout << "You look to find out prime numbers from 1 to? ";
	int max { 0 };
	cin >> max;

	//We add 1 due to the index always starts with 0 which means numbers from 1 to n - 1 will only be displayed
	vector<int> markings (max + 1);
	
	sieve_of_erasthones (markings, max);
	display_prime_vector (markings, max);



	
	return 0;
}

void sieve_of_erasthones (vector<int> &given_vector, int higher_boundary)
{
	//Mark 0 and 1 since its not a prime
	given_vector [0] = 1;
	given_vector [1] = 1;

	constexpr int first_prime = 2;

	for (int counter = first_prime; counter <= sqrt(higher_boundary); ++counter)
	{
		if (given_vector [counter] == 0)
		{
			for (int counter2 = counter + counter; counter2 <= higher_boundary; counter2 += counter)
				given_vector [counter2] = 1;
		}
	}
}

void display_prime_vector (const vector<int> display_vector, int max)
{
	constexpr int lower_boundary { 0 };
	const int higher_boundary { max };
	int newline_counter { 0 };


	for (int counter = lower_boundary; counter <= higher_boundary; ++counter)
	{
		if (display_vector [counter] == 0)
		{
			cout << counter << '\t';
			++newline_counter;
		}

		if (newline_counter == 10)
		{
			cout << '\n';
			newline_counter = 0;
		}

	}

}
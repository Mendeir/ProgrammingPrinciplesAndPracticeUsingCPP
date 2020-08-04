#include "std_lib_facilities.h"

void display_vector (const vector<int> display, int max);
void sieve_of_erasthones (vector<int> &numbers, int lower_boundary, int max);

int main ()
{
	constexpr int lower_boundary { 2 }, max { 100 };
	vector<int> numbers(max);
	
	sieve_of_erasthones (numbers, lower_boundary, max);
	display_vector (numbers, max);

	return 0;
}

void display_vector (const vector<int> display, int max)
{
	int newline_counter { 0 };

	for (int counter = 0; counter <= max - 1; ++counter)
	{
		if (display [counter] == 0)
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

void sieve_of_erasthones (vector<int> &numbers, int lower_boundary, int max)
{
	numbers [0] = 1;
	numbers [1] = 1;

	for (size_t counter = lower_boundary; counter <= sqrt (max); ++counter)
	{
		if (numbers [counter] == 0)
		{
			for (int counter2 = counter * counter; counter2 <= max - 1; counter2 += counter)
				numbers [counter2] = 1;
		}
	}

}

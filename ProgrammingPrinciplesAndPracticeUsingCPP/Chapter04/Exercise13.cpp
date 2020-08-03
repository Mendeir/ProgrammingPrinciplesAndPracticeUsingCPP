#include "std_lib_facilities.h"

void fill_vector (vector<int> &numbers, int max_range);
void display_vector (const vector<int> display);
void sieve_of_erasthones (vector<int> &numbers, vector<int> &unmarked, int lower_boundary, int max);

int main ()
{
	vector<int> numbers, unmarked;
	constexpr int lower_boundary { 2 }, max { 100 };
	numbers [1] = 0;
	
	display_vector (numbers);
	

	return 0;
}

void display_vector (const vector<int> display)
{
	int newline_counter { 0 };

	for (const bool counter : display)
	{
		cout << counter << "\t";
		if (newline_counter == 10)
		{
			cout << '\n';
			newline_counter = 0;
		}
		++newline_counter;
	}

	cout << '\n';
		
}

void fill_vector (vector<int> &numbers, int max_range)
{
	constexpr int lower_boundary { 2 };

	for (int counter = lower_boundary; counter <= max_range; ++counter)
		numbers.push_back (counter);
}

void sieve_of_erasthones (vector<int> &numbers, vector<int> &unmarked, int lower_boundary, int max)
{
	for (size_t counter = lower_boundary; counter <= sqrt (max); ++counter)
	{
		for (size_t counter2 = 0; counter2 < numbers.size (); ++counter2)
		{
			if (numbers [counter2] % counter != 0 || numbers [counter2] == counter)
				unmarked.push_back (numbers [counter2]);
		}

		numbers = unmarked;
		unmarked.clear ();
	}
}
#include "std_lib_facilities.h"

void calculate_smallest_largest_string (string given_input, string &smallest, string &largest);
void calculate_string_mode (vector<string> given_vector, string &mode, int &occurence);

int main ()
{
	vector<string> user_string_input;
	string smallest { " " }, largest { " " }, mode { " " };
	int occurence { 0 };

	cout << "Enter a string input:\n";

	for (string user_input; cin >> user_input;)
	{
		user_string_input.push_back (user_input);
		calculate_smallest_largest_string (user_input, smallest, largest);
	}

	calculate_string_mode (user_string_input, mode, occurence);

	cout << "The first smallest occuring string is: " << smallest << '\n';
	cout << "The first largest occuring string is: " << largest << '\n';
	cout << "The first most occuring string is: " << mode << " which occured " << occurence << " times." << '\n';
	

	return 0;
}

void calculate_smallest_largest_string (string given_input, string &smallest, string &largest)
{
	if (smallest == " " && largest == " ")
	{
		smallest = given_input;
		largest = given_input;
	}

	if (smallest.size () > given_input.size ())
		smallest = given_input;

	if (largest.size () < given_input.size ())
		largest = given_input;
}

void calculate_string_mode (vector<string> given_vector, string &mode, int &occurence)
{
	size_t mode_counter { 0 }, count { 0 }, mode_index { 0 };
	constexpr size_t lower_boundary { 0 };

	sort (given_vector);

	for (size_t counter = lower_boundary; counter < given_vector.size () - 1; ++counter)
	{
		if (given_vector [counter] == given_vector [counter + 1])
			++count;
		else
			count = 0;

		if (mode_counter < count)
		{
			mode_counter = count;
			occurence = count + 1;
			mode_index = counter;
		}
	}

	mode = given_vector [mode_index];
}
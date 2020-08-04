#include "std_lib_facilities.h"

void get_and_display_mode (vector<int> given_vector, vector<int> frequency_collection);

int main ()
{
	vector<int> positive_integers;
	vector<int> frequency_collection;

	int input { 0 };

	cout << "Enter a positive integer:\n";
	while (cin >> input)
		positive_integers.push_back (input);

	cout << "The mode for the set of positive integers is: ";
	get_and_display_mode (positive_integers, frequency_collection);

	return 0;
}

void get_and_display_mode (vector<int> given_vector, vector<int> frequency_collection)
{
	size_t mode_counter { 0 }, count { 0 }, mode { 0 };
	constexpr size_t lower_boundary { 0 };

	sort (given_vector);

	//get mode
	//We only loop -1 of the vector size since we evaluate ahead of the elements
	for (size_t counter = lower_boundary; counter < given_vector.size () - 1; ++counter)
	{
		if (given_vector [counter] == given_vector [counter + 1])
			++count;

		if (mode_counter < count)
			mode_counter = count;

		//We evaluate if it detects a new number or the loop will end
		if (given_vector [counter] != given_vector [counter + 1] || counter == given_vector.size() - 2) 
		{
			frequency_collection.push_back (count);
			frequency_collection.push_back (given_vector [counter]);

			count = 0;
		}
		
		

	}

	//display mode
	for (size_t counter = lower_boundary; counter < frequency_collection.size (); counter += 2)
	{
		if (frequency_collection [counter] == mode_counter)
			cout << frequency_collection [counter + 1] << " ";
	}


}
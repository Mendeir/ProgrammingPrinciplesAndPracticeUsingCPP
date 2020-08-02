#include "std_lib_facilities.h"

void display_data (vector<double> inputs, double sum);

int main ()
{
	double input1 { 0 }, sum_of_cities { 0 };
	vector<double> distances_input;

	cout << "Enter a number separated by whitespace. Assume the numbers are distances: \n";

	while (cin >> input1)
	{
		if (input1 <= 0)
		{
			if (distances_input.size () == 0)
				error ("No distance found");

			display_data (distances_input, sum_of_cities);
		}

		sum_of_cities += input1;
		distances_input.push_back (input1);
	}

	if (distances_input.size () == 0)
		error ("No distance found");
	display_data (distances_input, sum_of_cities);

	return 0;
}

void display_data (vector<double> inputs, double sum)
{
	sort (inputs);
	cout << "Total distance: " << sum << endl;
	cout << "Smallest distance between neighboring cities: " << inputs [0] << endl;
	cout << "Largest distance between neighboring cities: " << inputs [inputs.size () - 1] << endl;
	cout << "Mean distance between between two neighboring cities: " << sum / inputs.size () << endl;
	keep_window_open ("`");
}
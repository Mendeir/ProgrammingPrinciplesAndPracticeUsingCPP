#include "std_lib_facilities.h"

int main ()
{
	vector <int> milestones { 1'000, 1'000'000, 1'000'000'000 };
	int current_square { 0 }, number_of_current_grains { 1 }, grains_on_previous_squares { 0 };
	int milestone_tracker { 0 };
	size_t number_of_milestones { milestones.size () };
	cout << '\n';

	while (milestone_tracker != number_of_milestones)
	{
		++current_square;

		cout << "Current square: " << " Square " << current_square << '\n';
		cout << "Number of grains on the current square: " << number_of_current_grains << '\n';
		cout << "Grains on all previous squares: " << grains_on_previous_squares << '\n';

		grains_on_previous_squares += number_of_current_grains;
		

		if (grains_on_previous_squares >= milestones [milestone_tracker])
		{
			cout << "\nMILESTONE: To give the inventor " << milestones[milestone_tracker] 
				 << " grains, the inventor must have " << current_square << " squares\n";
			++milestone_tracker;
		}

		number_of_current_grains *= 2;

		cout << '\n';
	}
	

	return 0;
}
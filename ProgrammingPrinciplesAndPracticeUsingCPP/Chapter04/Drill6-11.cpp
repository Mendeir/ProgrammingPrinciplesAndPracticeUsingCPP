#include "std_lib_facilities.h"

void calculate_smallest_largest (double a, double &smallest, double &largest);
void output_data (double small, double large, double total_values, double sum_values);
double convert_unit_to_meters (double a, string unit);
bool check_unit (string unit);

int main ()
{

	double input { 0 };
	double smallest { 0 }, largest { 0 };
	double sum_of_values { 0 }, number_of_values { 0 };
	string unit { "" };
	vector<double> input_values;

	cout << "Enter an integer followed by a unit (cm, in, ft, m): \n";

	while (cin >> input >> unit)
	{
		//check if unit is correct
		if (check_unit(unit))
		{
			input = convert_unit_to_meters (input, unit);
			cout << input << " meters";
			calculate_smallest_largest (input, smallest, largest);
			sum_of_values += input;									
			++number_of_values;			
			input_values.push_back (input);

			cout << endl;
		}
		else
			cout << "Something is wrong with the unit input, please try again.\n";
	}

	output_data (smallest, largest, number_of_values, sum_of_values);
	
	//sort and display input_values vector elements
	sort (input_values);
	cout << "\tValues entered(meters): ";
	for (double counter : input_values)
		cout << counter << " ";

	cout << endl;

	keep_window_open ();

	return 0;
}

void calculate_smallest_largest (double a, double &smallest, double &largest)
{
	if (smallest == 0 && largest == 0)
	{
		cout << " the smallest and the largest so far";
		smallest = a;
		largest = a;
	}

	if (a < smallest)
	{
		cout << " the smallest so far";
		smallest = a;
	}

	if (a > largest)
	{
		cout << " the largest so far";
		largest = a;
	}

}

void output_data (double small, double large, double total_values, double sum_values)
{
	//display smallest, largest, sum, and total of all the inputs
	cout << "\nData from all the inputs:";
	cout << "\n\tSmallest number: " << small << " meters";
	cout << "\n\tLargest number: " << large << " meters";
	cout << "\n\tNumber of values: " << total_values;
	cout << "\n\tSum of values(meters): " << sum_values << " meters\n";
}

double convert_unit_to_meters (double a, string unit)
{
	constexpr double in_to_cm_ratio { 2.54 };
	constexpr double ft_to_in_ratio { 12 };
	constexpr double char_to_m_ratio { 0.01 };
	constexpr double in_to_m_ratio { in_to_cm_ratio * char_to_m_ratio };
	constexpr double ft_to_m_ratio { ft_to_in_ratio * in_to_m_ratio };

	if (unit == "cm")
		return char_to_m_ratio * a;

	if (unit == "m")
		return a;

	if (unit == "in")
		return in_to_m_ratio * a;

	if (unit == "ft")
		return ft_to_m_ratio * a;

	return a;

}

bool check_unit (string unit)
{
	if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft")
		return true;
	else
		return false;
}


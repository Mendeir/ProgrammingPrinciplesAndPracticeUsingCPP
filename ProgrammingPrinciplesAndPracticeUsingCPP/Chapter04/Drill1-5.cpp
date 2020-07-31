#include "std_lib_facilities.h"

double get_min (double a, double b);
double get_max (double a, double b);
bool almost_equal (double a, double b);

int main ()
{
	double value1 { 0 }, value2 { 0 };

	while (cin >> value1 >> value2)
	{
		if (value1 == value2)
			cout << "The numbers are equal" << endl;
		else
		{
			cout << "The smaller value is: " << get_min (value1, value2) << endl;
			cout << "The larger value is: " << get_max (value1, value2) << endl;
			if (almost_equal(value1, value2))
				cout << "The numbers are almost equal" << endl;
		}
	}

	return 0;
}


double get_min (double a, double b)
{
	return a < b ? a : b;
}

double get_max (double a, double b)
{
	return a > b ? a : b;
}

bool almost_equal (double a, double b)
{
	constexpr double almost_equal_value { 1.0 / 100 };

	return abs(a - b) < almost_equal_value ? true : false;
}
#include "std_lib_facilities.h"

double calculate_positive_x (double a, double b, double c);
double calculate_negative_x (double a, double b, double c);
int main ()
{
	

	cout << "BASIC QUADRATIC EQUATION SOLVER\n";
	
	cout << "\nPlease enter a, b and c separated by space: ";
	double a { 0 }, b { 0 }, c { 0 };
	cin >> a >> b >> c;

	double x1 { calculate_positive_x (a, b, c) };
	double x2 { calculate_negative_x (a, b, c) };
	cout << "\nThe answer for " << a << "x^2 + " << b << "x + " << c << " = 0 is:\n";
	cout << "x = " << x1 << " and " << x2 << '\n';


	return 0;
}

double calculate_positive_x (double a, double b, double c)
{
	return ((-b + sqrt ((b * b) - (4 * a * c))) / (2 * a));
}

double calculate_negative_x (double a, double b, double c)
{
	return ((-b - sqrt ((b * b) - (4 * a * c))) / (2 * a));
}
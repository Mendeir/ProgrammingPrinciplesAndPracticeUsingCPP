/*
Comments:
	The results will be determined plausible based on the discriminant
	if discrimant is less than 0 atleast it must have no real roots
	if discriminant is exactly equal to 0 it must have atleast one real root
	if discriminant is above 0 then it must have 2 real roots	


*/

#include <iostream>
#include <cmath>
#include <limits>

void getUserInput (double &a, double &b, double &c);
void badUserInput (std::string s);
void error (std::string s);
void solveQuadEquation (double &a, double &b, double &c);
int tryAgain ();

int main ()
{
	try
	{
		int choice = 1;
		while (choice)
		{
			std::cout << "Simple quadratic equation calculator\n";

			double a = 0, b = 0, c = 0;
			getUserInput (a, b, c);
			solveQuadEquation (a, b, c);
			choice = tryAgain ();
			std::cout << '\n';
			
		}

		return 0;
	}
	catch (std::runtime_error &e)
	{
		std::cerr << "Runtime error: " << e.what() << '\n';
	}
}

void getUserInput (double &a, double &b, double &c)
//Gets the quadratic equation and checks if the equation is right
//Pre-condition variable must be a double
//Post-condition input must be a valid quadratic equation
{

	double input1 = 0, input2 = 0, input3 = 0;

	while (true)
	{
		std::cout << "\nPlease enter a, b, and c separated by a whitespace: ";
		std::cin >> input1 >> input2 >> input3;

		if (std::cin.fail () || input1 == 0)
		{
			std::cin.clear ();
			std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
			badUserInput ("Not a quadratic equation!");
		}
		else
		{
			char choice = ' ';
			std::cout << "\nIs the equation " << input1 << "x^2 + " << input2 << "x + " << input3 << " = 0 correct?(Y/N): ";
			std::cin >> choice;

			if ((choice != 'Y' && choice != 'N') || std::cin.fail ())
			{
				std::cin.clear ();
				std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
				badUserInput ("Input not found in choices!");
			}
			else
			{
				if (choice == 'Y')
				{
					a = input1;
					b = input2;
					c = input3;
					return;
				}
			}
		}
	}
}

void solveQuadEquation (double &a, double &b, double &c)
//Solves the quadratic equation using the quadratic formula
//Pre-condition: Already checked at user input
//Post-condition: Must return atleast one real root
{
	double discriminant = b * b - 4 * a * c;
	
	if (discriminant < 0)
	{
		std::cout << "No real roots\n";
		return;
	}
	
	if (discriminant == 0)
	{
		std::cout << "Single root: x = " << (-b) / (2 * a) << '\n';
		return;
	}

	if (discriminant > 0)
	{
		std::cout << "Two real roots\n";
		std::cout << "x1 = " << ((-b) + sqrt (discriminant)) / (2 * a) << '\n';
		std::cout << "x2 = " << ((-b) - sqrt (discriminant)) / (2 * a) << '\n';
		return;
	}	

	error ("solveQuadEquation() - post condition");
	
}


void badUserInput (std::string s)
{
	std::cerr << "Error bad input: " << s << " Please try again!\n";
}

void error (std::string s)
{
	throw(std::runtime_error (s));
}

int tryAgain ()
{
	char choice = ' ';
	while (true)
	{
		std::cout << "\nDo you want to continue?(Y/N): ";
		std::cin >> choice;

		if ((choice != 'Y' && choice != 'N') || std::cin.fail ())
		{
			std::cin.clear ();
			std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
			badUserInput ("Input not found in choices!");
		}

		if (choice == 'Y')
			return 1;

		if (choice == 'N')
			return 0;
	}
}
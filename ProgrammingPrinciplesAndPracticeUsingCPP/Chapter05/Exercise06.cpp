#include <iostream>

int userChoice ();
double temperatureInput (std::string s, std::string temp);
void ctof (double temp);
void ftoc (double temp);
void badInputError ();
void error (std::string s);

int main ()
{
	try
	{
		std::cout << "Temperature Converter : Kelvin and Celsius\n"
				  << "\t1. Convert from Celsius to Kelvin\n"
				  << "\t2. Convert from Kelvin to Celsius\n";
				  
		switch (userChoice ())
		{
			case 1:
					ctof(temperatureInput ("Celsius to Farenheit", "Celsius"));

				break;
			case 2:
					ftoc(temperatureInput ("Farenheit to Celsius", "Farenheit"));
				break;
			default:
				error ("Something went wrong!");
		}
	}
	catch (std::runtime_error(s))
	{
		std::cerr << "Runtime error: " << s.what () << '\n';
	}
}

void error (std::string s)
{
	throw(std::runtime_error (s));
}

void badInputError ()
{
	std::cerr << "Error: Input invalid, please try again.\n";
}

int userChoice ()
//Gets user choice from the menu
//Pre-condition: input must be only from the menu
//Post-condition: N/A
{
	constexpr int menuLowerLimit = 1;
	constexpr int menuUpperLimit = 2;
	int choice = 0;

	while (true)
	{
		std::cout << "\nEnter the number of your choice: ";
		std::cin >> choice;

		if (choice < menuLowerLimit || choice > menuUpperLimit)
		{
			std::cin.clear ();
			std::cin.ignore ();
			badInputError ();
		}
		else
			return choice;
		
	}
}

double temperatureInput (std::string s, std::string temp)
//Gets user temperature input with given arguement to what temperature will it be converted to
//Pre-condition: input must be a valid temperature, not below absolute zero;
//Post-condition: N/A
{
	double absoluteZero = -1;

	if (temp == "Celsius")
		absoluteZero = -273.15;
	if (temp == "Farenheit")
		absoluteZero = -459.67;

	if (absoluteZero == -1)
		error ("Invalid function argument std::string temp");

	double tempInput;

	while (true)
	{
		std::cout << "\nEnter the temperature that you want to convert from " << s << ": ";
		std::cin >> tempInput;

		if (tempInput < absoluteZero)
		{
			std::cin.clear ();
			std::cin.ignore ();
			badInputError ();
		}
		else
			return tempInput;
	}
}

void ctof (double temp)
//Converts Celsius to Farenheit
//Pre-condition: temperature must not be below absolute zero
//Post-condition temperature must not be below absolute zero
{
	constexpr double absoluteZeroC = -273.15;
	constexpr double absoluteZeroF = -459.67;

	if (temp < absoluteZeroC)
		error ("Pre-condition ctof ()");

	double f = (temp * 9/5) + 32;

	if (f < absoluteZeroF)
		error ("Post-condition ctof ()");

	std::cout << "The temperature from " << temp << "C is " << f << "F\n";
}

void ftoc (double temp)
//Converts Farenheit to Celsius
//Pre-condition: temperature must not be below absolute zero
//Post-condition temperature must not be below absolute zero
{
	constexpr double absoluteZeroC = -273.15;
	constexpr double absoluteZeroF = -459.67;

	if (temp < absoluteZeroF)
		error ("Pre-condition ftoc ()");

	double c = (temp - 32) * 5/9;

	if (c < absoluteZeroC)
		error ("Post-condition ftoc ()");

	std::cout << "The temperature from " << temp << "F is " << c << "C\n";
}
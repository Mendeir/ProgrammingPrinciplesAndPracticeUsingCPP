#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <limits>

void inputValues (std::string givenDay, const int givenValue, std::vector<int> &givenValues, const std::vector<std::string> givenDays);
bool checkStringGetPos (std::string givenDay, const std::vector<std::string> givenDays, int &givenPosition);
void getInputs (const std::vector <std::string> givenDays, std::vector<int> &givenValues);
void displayInputs (const std::vector<int> givenValues, std::vector<std::string> givenDays);
void error (const std::string s);

int main ()
{
	std::vector<int> values(7);
	std::vector<std::string> days { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
	std::cout << "Enter values from a day of the week separated by a whitespace"
		  	  << "\ncan be abbrevated by 3 letters or lowercase (tuesday 10, Thu -20, Monday 30):"
			  << "\nInput Done -1 to exit\n";

	getInputs (days, values);
	displayInputs (values, days);

	return 0;
}

void getInputs (const std::vector <std::string> givenDays, std::vector<int> &givenValues)
//Get unlimited input from the user, terminate when Done -1 is inputted
//Pre-condition: cin must not fail
{
	std::string dayInput;
	int valueInput = 0;
	

	while (true)
	{
		try
		{
			std::cin >> dayInput >> valueInput;

			if (dayInput == "Done" && valueInput == -1)
				break;

			if (std::cin.fail ())
			{
				std::cin.clear ();
				std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
				error ("Invalid input!");
			}

			inputValues (dayInput, valueInput, givenValues, givenDays);
		}
		catch (std::runtime_error &e)
		{
			std::cerr << "Runtime error: " << e.what () << '\n';
		}
	}
}

void displayInputs (const std::vector<int> givenValues, std::vector<std::string> givenDays)
//Displays all the value position according to its day position, capitalizes the first letter in givenDays vector 
{
	std::cout << "\nValues from all seven days: \n";
	for (int counter = 0; counter < givenDays.size (); ++counter)
	{
		std::string day = givenDays [counter];
		day [0] = toupper (day [0]);
		std::cout << day << ": " << givenValues [counter] << '\n';
	}
}

bool checkStringGetPos (std::string givenDay, const std::vector<std::string> givenDays, int &givenPosition)
//Makes the string lowercase and checks if the string is right based on the condition and gets the vector position of the string if it matches
//Pre-condition: The given string must not have a number
//Post-condition: The given string must match from the givendays
{
	for (auto counter : givenDay)
	{
		if (counter <= '9' && counter >= '0')
			return true;
	}

	std::transform (givenDay.begin (), givenDay.end (), givenDay.begin (),
					[] (unsigned char c) {return std::tolower (c); });

	for (size_t counter = 0; counter < givenDays.size(); ++counter)
	{
		if (givenDay.substr (0, 3) == givenDays [counter].substr (0, 3))
		{
			givenPosition = counter;
			return false;
		}
	}
	
	return true;
}

void inputValues (std::string givenDay, const int givenValue, std::vector<int> &givenValues, const std::vector<std::string> givenDays)
//Inputs the givenValue to its matching day position which is obtained while checking givenDay variable
//Pre-condition: givenDay must match with the givenDays
{
	int position = 0;
	while (true)
	{
		try
		{
			if (checkStringGetPos (givenDay, givenDays, position))
				error ("Invalid string input!");

			givenValues [position] += givenValue;
			return;
		}
		catch(std::runtime_error &e)
		{
			std::cerr << "Runtime error: " << e.what () << '\n';
			return;
		}
	}
}

void error (const std::string s)
{
	throw(std::runtime_error (s));
}